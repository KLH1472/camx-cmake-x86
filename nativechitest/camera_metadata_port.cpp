// Systematic port of Android's libcamera_metadata core functions for Linux.
// Adapted from camera3metadata.cpp (originally from AOSP camera_metadata.c).

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <system/camera_metadata.h>
#include <system/camera_vendor_tags.h>

static const vendor_tag_ops_t* vendor_tag_ops = nullptr;

static camera_metadata_buffer_entry_t* get_entries(const camera_metadata_t* metadata) {
    return (camera_metadata_buffer_entry_t*)((uint8_t*)metadata + metadata->entries_start);
}

static uint8_t* get_data(const camera_metadata_t* metadata) {
    return (uint8_t*)metadata + metadata->data_start;
}

// --- Allocation / placement ---

size_t calculate_camera_metadata_size(size_t entry_count, size_t data_count) {
    size_t memory_needed = sizeof(camera_metadata_t);
    memory_needed = ALIGN_TO(memory_needed, ENTRY_ALIGNMENT);
    memory_needed += sizeof(camera_metadata_buffer_entry_t) * entry_count;
    memory_needed = ALIGN_TO(memory_needed, DATA_ALIGNMENT);
    memory_needed += sizeof(uint8_t) * data_count;
    return memory_needed;
}

camera_metadata_t* place_camera_metadata(void* dst, size_t dst_size, size_t entry_capacity, size_t data_capacity) {
    if (dst == nullptr) return nullptr;

    size_t memory_needed = calculate_camera_metadata_size(entry_capacity, data_capacity);
    if (memory_needed > dst_size) return nullptr;

    camera_metadata_t* metadata = (camera_metadata_t*)dst;
    metadata->version = CURRENT_METADATA_VERSION;
    metadata->flags = 0;
    metadata->entry_count = 0;
    metadata->entry_capacity = entry_capacity;
    metadata->entries_start = ALIGN_TO(sizeof(camera_metadata_t), ENTRY_ALIGNMENT);
    metadata->data_count = 0;
    metadata->data_capacity = data_capacity;
    metadata->size = memory_needed;

    size_t data_unaligned = (uint8_t*)(get_entries(metadata) + metadata->entry_capacity) - (uint8_t*)metadata;
    metadata->data_start = ALIGN_TO(data_unaligned, DATA_ALIGNMENT);

    return metadata;
}

camera_metadata_t* allocate_camera_metadata(size_t entry_capacity, size_t data_capacity) {
    size_t memory_needed = calculate_camera_metadata_size(entry_capacity, data_capacity);
    void* buffer = calloc(1, memory_needed);
    if (!buffer) return nullptr;
    return place_camera_metadata(buffer, memory_needed, entry_capacity, data_capacity);
}

void free_camera_metadata(camera_metadata_t* metadata) {
    free(metadata);
}

// --- Size queries ---

size_t get_camera_metadata_entry_count(const camera_metadata_t* metadata) {
    return metadata ? metadata->entry_count : 0;
}

size_t get_camera_metadata_entry_capacity(const camera_metadata_t* metadata) {
    return metadata ? metadata->entry_capacity : 0;
}

size_t get_camera_metadata_data_count(const camera_metadata_t* metadata) {
    return metadata ? metadata->data_count : 0;
}

size_t get_camera_metadata_data_capacity(const camera_metadata_t* metadata) {
    return metadata ? metadata->data_capacity : 0;
}

size_t get_camera_metadata_size(const camera_metadata_t* metadata) {
    return metadata ? metadata->size : 0;
}

size_t calculate_camera_metadata_entry_data_size(uint8_t type, size_t data_count) {
    if (type >= NUM_TYPES) return 0;
    size_t data_bytes = data_count * camera_metadata_type_size[type];
    return data_bytes <= 4 ? 0 : ALIGN_TO(data_bytes, DATA_ALIGNMENT);
}

// --- Tag type lookup ---

int get_camera_metadata_tag_type(uint32_t tag) {
    uint32_t tag_section = tag >> 16;
    if (tag_section >= VENDOR_SECTION && vendor_tag_ops != nullptr) {
        return vendor_tag_ops->get_tag_type(vendor_tag_ops, tag);
    }
    if (tag_section >= ANDROID_SECTION_COUNT) return -1;
    if (tag_info[tag_section] == nullptr) return -1;

    uint32_t tag_index = tag & 0xFFFF;
    // bounds check via section_bounds
    if (tag_index >= camera_metadata_section_bounds[tag_section][1]) return -1;

    return tag_info[tag_section][tag_index];
}

// --- Entry access ---

int get_camera_metadata_entry(camera_metadata_t* src, size_t index, camera_metadata_entry_t* entry) {
    if (src == nullptr || entry == nullptr) return -1;
    if (index >= src->entry_count) return -1;

    camera_metadata_buffer_entry_t* buffer_entry = get_entries(src) + index;
    memset(entry, 0, sizeof(*entry));
    entry->index = index;
    entry->tag = buffer_entry->tag;
    entry->type = buffer_entry->type;
    entry->count = buffer_entry->count;

    if (buffer_entry->count * camera_metadata_type_size[buffer_entry->type] > 4) {
        entry->data.u8 = get_data(src) + buffer_entry->data.offset;
    } else if (buffer_entry->count > 0) {
        entry->data.u8 = buffer_entry->data.value;
    }
    return 0;
}

// --- Add entry ---

int add_camera_metadata_entry_raw(camera_metadata_t* dst, uint32_t tag, uint8_t type, const void* data, size_t data_count) {
    if (dst == nullptr) return -1;
    if (dst->entry_count == dst->entry_capacity) return -1;
    if (data_count && data == nullptr) return -1;

    size_t data_bytes = calculate_camera_metadata_entry_data_size(type, data_count);
    if (data_bytes + dst->data_count > dst->data_capacity) return -1;

    size_t data_payload_bytes = data_count * camera_metadata_type_size[type];
    camera_metadata_buffer_entry_t* entry = get_entries(dst) + dst->entry_count;
    memset(entry, 0, sizeof(*entry));
    entry->tag = tag;
    entry->type = type;
    entry->count = data_count;

    if (data_bytes == 0) {
        if (data_payload_bytes > 0) memcpy(entry->data.value, data, data_payload_bytes);
    } else {
        entry->data.offset = dst->data_count;
        memcpy(get_data(dst) + entry->data.offset, data, data_payload_bytes);
        dst->data_count += data_bytes;
    }
    dst->entry_count++;
    dst->flags &= ~FLAG_SORTED;
    return 0;
}

int add_camera_metadata_entry(camera_metadata_t* dst, uint32_t tag, const void* data, size_t data_count) {
    int type = get_camera_metadata_tag_type(tag);
    if (type == -1) return -1;
    return add_camera_metadata_entry_raw(dst, tag, (uint8_t)type, data, data_count);
}

// --- Find entry ---

static int compare_entry_tags(const void* p1, const void* p2) {
    uint32_t tag1 = ((camera_metadata_buffer_entry_t*)p1)->tag;
    uint32_t tag2 = ((camera_metadata_buffer_entry_t*)p2)->tag;
    return tag1 < tag2 ? -1 : tag1 == tag2 ? 0 : 1;
}

int find_camera_metadata_entry(camera_metadata_t* src, uint32_t tag, camera_metadata_entry_t* entry) {
    if (src == nullptr || entry == nullptr) return -1;

    int index = -1;
    if (src->flags & FLAG_SORTED) {
        camera_metadata_buffer_entry_t key;
        key.tag = tag;
        camera_metadata_buffer_entry_t* found = (camera_metadata_buffer_entry_t*)
            bsearch(&key, get_entries(src), src->entry_count, sizeof(camera_metadata_buffer_entry_t), compare_entry_tags);
        if (found == nullptr) return -1;
        index = found - get_entries(src);
    } else {
        camera_metadata_buffer_entry_t* search_entry = get_entries(src);
        for (size_t i = 0; i < src->entry_count; i++, search_entry++) {
            if (search_entry->tag == tag) { index = (int)i; break; }
        }
        if (index == -1) return -1;
    }
    return get_camera_metadata_entry(src, index, entry);
}

// --- Clone / append ---

int append_camera_metadata(camera_metadata_t* dst, const camera_metadata_t* src) {
    if (dst == nullptr || src == nullptr) return -1;
    if (src->entry_count + dst->entry_count < src->entry_count) return -1;
    if (src->data_count + dst->data_count < src->data_count) return -1;
    if (dst->entry_capacity < src->entry_count + dst->entry_count) return -1;
    if (dst->data_capacity < src->data_count + dst->data_count) return -1;

    memcpy(get_entries(dst) + dst->entry_count, get_entries(src),
           sizeof(camera_metadata_buffer_entry_t) * src->entry_count);
    memcpy(get_data(dst) + dst->data_count, get_data(src), sizeof(uint8_t) * src->data_count);

    if (dst->data_count != 0) {
        camera_metadata_buffer_entry_t* entry = get_entries(dst) + dst->entry_count;
        for (size_t i = 0; i < src->entry_count; i++, entry++) {
            if (calculate_camera_metadata_entry_data_size(entry->type, entry->count) > 0) {
                entry->data.offset += dst->data_count;
            }
        }
    }
    if (dst->entry_count == 0) {
        dst->flags |= src->flags & FLAG_SORTED;
    } else if (src->entry_count != 0) {
        dst->flags &= ~FLAG_SORTED;
    }
    dst->entry_count += src->entry_count;
    dst->data_count += src->data_count;
    return 0;
}

camera_metadata_t* clone_camera_metadata(const camera_metadata_t* src) {
    if (src == nullptr) return nullptr;
    camera_metadata_t* clone = allocate_camera_metadata(
        get_camera_metadata_entry_count(src), get_camera_metadata_data_count(src));
    if (clone != nullptr) {
        if (append_camera_metadata(clone, src) != 0) {
            free_camera_metadata(clone);
            clone = nullptr;
        }
    }
    return clone;
}

// --- Vendor tag ops ---

int set_camera_metadata_vendor_ops(const vendor_tag_ops_t* ops) {
    vendor_tag_ops = ops;
    return 0;
}

void dump_camera_metadata(const camera_metadata_t* metadata, int fd, int verbosity) {
    (void)metadata; (void)fd; (void)verbosity;
}

int delete_camera_metadata_entry(camera_metadata_t* dst, size_t index) {
    (void)dst; (void)index;
    return 0;
}

camera_metadata_t* allocate_copy_camera_metadata_checked(const camera_metadata_t* src, size_t data_alignment) {
    (void)data_alignment;
    return clone_camera_metadata(src);
}

// --- Minimal validation ---

int validate_camera_metadata_structure(const camera_metadata_t* metadata, const size_t* expected_size) {
    if (metadata == nullptr) return -1;
    if (metadata->entry_count > metadata->entry_capacity) return -1;
    if (metadata->data_count > metadata->data_capacity) return -1;
    return 0;
}

int update_camera_metadata_entry(camera_metadata_t* dst, size_t index, const void* data, size_t data_count, camera_metadata_entry_t* updated_entry) {
    if (dst == nullptr || index >= dst->entry_count) return -1;

    camera_metadata_buffer_entry_t* entry = get_entries(dst) + index;
    size_t data_payload_bytes = data_count * camera_metadata_type_size[entry->type];
    size_t data_bytes = calculate_camera_metadata_entry_data_size(entry->type, data_count);
    size_t entry_bytes = calculate_camera_metadata_entry_data_size(entry->type, entry->count);

    if (data_bytes != entry_bytes) return -1;  // simplified: don't support size change

    if (data_bytes == 0) {
        if (data_payload_bytes > 0) memcpy(entry->data.value, data, data_payload_bytes);
    } else {
        memcpy(get_data(dst) + entry->data.offset, data, data_payload_bytes);
    }
    entry->count = data_count;
    if (updated_entry != nullptr) {
        get_camera_metadata_entry(dst, index, updated_entry);
    }
    return 0;
}
