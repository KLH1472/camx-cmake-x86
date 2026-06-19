#ifndef _STUB_HARDWARE_CAMERA_COMMON_H
#define _STUB_HARDWARE_CAMERA_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <system/camera_vendor_tags.h>
#include <system/camera_metadata.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CAMERA_MODULE_API_VERSION_2_0    0x0200
#define CAMERA_MODULE_API_VERSION_2_3    0x0203
#define CAMERA_MODULE_API_VERSION_3_0    0x0300
#define HARDWARE_MODULE_API_VERSION(major, minor) (((major) << 16) | ((minor) & 0xFFFF))

// Camera facing
#define CAMERA_FACING_BACK      0
#define CAMERA_FACING_FRONT     1
#define CAMERA_FACING_EXTERNAL  2

#define CAMERA_HARDWARE_MODULE_ID "camera"

typedef struct camera_info {
    int facing;
    int orientation;
    uint32_t device_version;
    const camera_metadata_t* static_camera_characteristics;
    void* resource_cost;
    char  conflicting_devices_length;
    char* conflicting_devices;
    int   sorted_children_length;
    int*  sorted_children;
} camera_info;

typedef struct camera_module_callbacks {
    void (*camera_device_status_change)(const struct camera_module_callbacks*, int camera_id, int new_status);
    void (*torch_mode_status_change)(const struct camera_module_callbacks*, const char* camera_id, int new_status);
} camera_module_callbacks_t;

typedef struct camera_module {
    uint32_t common_version;
    uint32_t common_hal_api_version;
    void*    dso;
    void*    reserved[5];
    // v2
    int (*get_number_of_cameras)(void);
    int (*get_camera_info)(int camera_id, camera_info* info);
    // v3
    int (*set_callbacks)(const void* callbacks);
    void (*get_vendor_tag_ops)(vendor_tag_ops_t* ops);
    int (*open_legacy)(const struct hw_module_t* module, const char* id,
                        uint32_t halVersion, struct hw_device_t** device);
    // v4
    int (*set_torch_mode)(const char* camera_id, bool enabled);
    int (*init)();
    void* reserved2[5];
} camera_module_t;

#ifdef __cplusplus
}
#endif

#endif // _STUB_HARDWARE_CAMERA_COMMON_H
