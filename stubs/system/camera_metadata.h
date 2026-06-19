#ifndef _STUB_SYSTEM_CAMERA_METADATA_H
#define _STUB_SYSTEM_CAMERA_METADATA_H

#include <stdint.h>
#include <sys/types.h>
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration
typedef struct camera_metadata camera_metadata_t;

// Internal types (match Android's camera_metadata.h and camera_metadata_hidden.h)
typedef uint32_t metadata_uptrdiff_t;
typedef uint32_t metadata_size_t;

#define METADATA_ALIGNMENT  ((size_t)4)
#define ENTRY_ALIGNMENT     ((size_t)4)
#define DATA_ALIGNMENT      ((size_t)8)

#define METADATA_PACKET_ALIGNMENT \
    ((METADATA_ALIGNMENT > DATA_ALIGNMENT ? METADATA_ALIGNMENT : DATA_ALIGNMENT) > ENTRY_ALIGNMENT ? \
     (METADATA_ALIGNMENT > DATA_ALIGNMENT ? METADATA_ALIGNMENT : DATA_ALIGNMENT) : ENTRY_ALIGNMENT)

// Real camera_metadata layout (matches Android's libcamera_metadata)
struct camera_metadata {
    metadata_size_t          size;
    uint32_t                 version;
    uint32_t                 flags;
    metadata_size_t          entry_count;
    metadata_size_t          entry_capacity;
    metadata_uptrdiff_t      entries_start;     // offset from start of camera_metadata
    metadata_size_t          data_count;
    metadata_size_t          data_capacity;
    metadata_uptrdiff_t      data_start;        // offset from start of camera_metadata
    uint8_t                  reserved[];
};

// Vendor tag ops
#include "camera_vendor_tags.h"

// camera_metadata_rational_t
typedef struct {
    int32_t numerator;
    int32_t denominator;
} camera_metadata_rational_t;

// Minimal metadata type enum
enum {
    TYPE_BYTE   = 0,
    TYPE_INT32  = 1,
    TYPE_FLOAT  = 2,
    TYPE_INT64  = 3,
    TYPE_DOUBLE = 4,
    TYPE_RATIONAL = 5,
    NUM_TYPES
};

static const size_t camera_metadata_type_size[NUM_TYPES] = {
    sizeof(uint8_t),
    sizeof(int32_t),
    sizeof(float),
    sizeof(int64_t),
    sizeof(double),
    sizeof(camera_metadata_rational_t)
};

// Camera metadata section IDs
#define ANDROID_COLOR_CORRECTION           0
#define ANDROID_CONTROL                    1
#define ANDROID_DEMOSAIC                   2
#define ANDROID_EDGE                       3
#define ANDROID_FLASH                      4
#define ANDROID_FLASH_INFO                 5
#define ANDROID_HOT_PIXEL                  6
#define ANDROID_JPEG                       7
#define ANDROID_LENS                       8
#define ANDROID_LENS_INFO                  9
#define ANDROID_NOISE_REDUCTION           10
#define ANDROID_QUIRKS                    11
#define ANDROID_REQUEST                   12
#define ANDROID_SCALER                    13
#define ANDROID_SENSOR                    14
#define ANDROID_SENSOR_INFO               15
#define ANDROID_SHADING                   16
#define ANDROID_STATISTICS                17
#define ANDROID_STATISTICS_INFO           18
#define ANDROID_TONEMAP                   19
#define ANDROID_LED                       20
#define ANDROID_INFO                      21
#define ANDROID_BLACK_LEVEL               22
#define ANDROID_SYNC                      23
#define ANDROID_REPROCESS                 24
#define ANDROID_DEPTH                     25
#define ANDROID_LOGICAL_MULTI_CAMERA      26
#define ANDROID_DISTORTION_CORRECTION     27
#define ANDROID_HEIC                      28

#define ANDROID_SECTION_COUNT             29

// Vendor section ID
#define VENDOR_SECTION                    0x8000

// Tag type macros
#define CAMERA_METADATA_ENUM_VAL(bit) ((0xFFFF0000) | ((bit) << 16))
#define CAMERA_METADATA_ENUM_VAL_START 0x80000000

// Android sensor info tags
#define ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SENSOR_INFO) | 0x00
#define ANDROID_SENSOR_INFO_PIXEL_ARRAY_SIZE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SENSOR_INFO) | 0x01
#define ANDROID_SENSOR_ORIENTATION \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SENSOR) | 0x00

// Color correction tags
#define ANDROID_COLOR_CORRECTION_TRANSFORM \
    CAMERA_METADATA_ENUM_VAL(ANDROID_COLOR_CORRECTION) | 0x00

// Android control tags
#define ANDROID_CONTROL_AE_TARGET_FPS_RANGE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x00
#define ANDROID_CONTROL_AE_STATE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x02
#define ANDROID_CONTROL_AF_STATE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x03
#define ANDROID_CONTROL_AWB_STATE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x04
#define ANDROID_CONTROL_VIDEO_STABILIZATION_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x05
#define ANDROID_CONTROL_SCENE_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x06
#define ANDROID_CONTROL_EFFECT_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x07
#define ANDROID_CONTROL_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x08
#define ANDROID_CONTROL_ENABLE_ZSL \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x09
#define ANDROID_CONTROL_AE_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_CONTROL) | 0x0A
#define ANDROID_FLASH_STATE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_FLASH) | 0x00

// Android sensor tags
#define ANDROID_SENSOR_EXPOSURE_TIME \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SENSOR) | 0x01
#define ANDROID_SENSOR_TIMESTAMP \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SENSOR) | 0x02

// Android statistics
#define ANDROID_STATISTICS_FACE_DETECT_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_STATISTICS) | 0x00

// Android scaler available stream configs
#define ANDROID_SCALER_AVAILABLE_STREAM_CONFIGURATIONS \
    CAMERA_METADATA_ENUM_VAL(ANDROID_SCALER) | 0x10

// Hot pixel mode
#define ANDROID_HOT_PIXEL_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_HOT_PIXEL) | 0x00

// Noise reduction mode
#define ANDROID_NOISE_REDUCTION_MODE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_NOISE_REDUCTION) | 0x00

// JPEG tags
#define ANDROID_JPEG_GPS_COORDINATES \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x00
#define ANDROID_JPEG_GPS_PROCESSING_METHOD \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x01
#define ANDROID_JPEG_GPS_TIMESTAMP \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x02
#define ANDROID_JPEG_ORIENTATION \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x03
#define ANDROID_JPEG_QUALITY \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x04
#define ANDROID_JPEG_THUMBNAIL_QUALITY \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x05
#define ANDROID_JPEG_THUMBNAIL_SIZE \
    CAMERA_METADATA_ENUM_VAL(ANDROID_JPEG) | 0x06

// Android request
#define ANDROID_REQUEST_AVAILABLE_CAPABILITIES \
    CAMERA_METADATA_ENUM_VAL(ANDROID_REQUEST) | 0x00

#define ANDROID_REQUEST_MAX_NUM_OUTPUT_STREAMS \
    CAMERA_METADATA_ENUM_VAL(ANDROID_REQUEST) | 0x04

// camera_metadata_tag_t
typedef uint32_t camera_metadata_tag_t;
typedef camera_metadata_tag_t camera_metadata_tag;

// camera_metadata_entry_t - with typed data access like Android's internal definition
typedef struct camera_metadata_entry {
    size_t   index;
    uint32_t tag;
    uint8_t  type;
    uint32_t count;
    union {
        uint32_t offset;
        uint8_t  value[4];
        uint8_t*  u8;
        int32_t*  i32;
        float*    f;
        int64_t*  i64;
        double*   d;
        camera_metadata_rational_t* r;
    } data;
} camera_metadata_entry_t;

typedef struct camera_metadata_ro_entry {
    size_t   index;
    uint32_t tag;
    uint8_t  type;
    uint32_t count;
    union {
        uint32_t offset;
        uint8_t  value[4];
        const uint8_t*  u8;
        const int32_t*  i32;
        const float*    f;
        const int64_t*  i64;
        const double*   d;
        const camera_metadata_rational_t* r;
    } data;
} camera_metadata_ro_entry_t;

// Metadata API function stubs

// Internal metadata buffer entry (matches Android's libcamera_metadata layout)
typedef struct camera_metadata_buffer_entry {
    uint32_t tag;
    uint32_t count;
    union {
        uint32_t offset;
        uint8_t  value[4];
    } data;
    uint8_t  type;
    uint8_t  reserved[3];
} camera_metadata_buffer_entry_t;

// Current metadata version
#define CURRENT_METADATA_VERSION 1

// Flags
#define FLAG_SORTED 0x00000001

#define ALIGN_TO(val, alignment) \
    (((uintptr_t)(val) + ((alignment) - 1)) & ~((alignment) - 1))

// --- C API function declarations (implementations in camera_metadata_port.cpp) ---

// Not inline — real implementations
int find_camera_metadata_entry(camera_metadata_t* src, uint32_t tag, camera_metadata_entry_t* entry);
int add_camera_metadata_entry(camera_metadata_t* dst, uint32_t tag, const void* data, size_t data_count);
int add_camera_metadata_entry_raw(camera_metadata_t* dst, uint32_t tag, uint8_t type, const void* data, size_t data_count);
camera_metadata_t* allocate_camera_metadata(size_t entry_cap, size_t data_cap);
camera_metadata_t* place_camera_metadata(void* dst, size_t dst_size, size_t entry_cap, size_t data_cap);
void free_camera_metadata(camera_metadata_t* metadata);
camera_metadata_t* clone_camera_metadata(const camera_metadata_t* src);
size_t get_camera_metadata_entry_count(const camera_metadata_t* src);
size_t get_camera_metadata_entry_capacity(const camera_metadata_t* src);
size_t get_camera_metadata_data_count(const camera_metadata_t* src);
size_t get_camera_metadata_data_capacity(const camera_metadata_t* src);
size_t get_camera_metadata_size(const camera_metadata_t* src);
size_t calculate_camera_metadata_size(size_t entry_count, size_t data_count);
size_t calculate_camera_metadata_entry_data_size(uint8_t type, size_t data_count);
int get_camera_metadata_tag_type(uint32_t tag);
int get_camera_metadata_entry(camera_metadata_t* src, size_t index, camera_metadata_entry_t* entry);
int get_camera_metadata_ro_entry(const camera_metadata_t* src, size_t index, camera_metadata_ro_entry_t* entry);
int append_camera_metadata(camera_metadata_t* dst, const camera_metadata_t* src);
int update_camera_metadata_entry(camera_metadata_t* dst, size_t index, const void* data, size_t data_count, camera_metadata_entry_t* updated_entry);
int validate_camera_metadata_structure(const camera_metadata_t* metadata, const size_t* expected_size);
int set_camera_metadata_vendor_ops(const vendor_tag_ops_t* ops);
void dump_camera_metadata(const camera_metadata_t* metadata, int fd, int verbosity);
int delete_camera_metadata_entry(camera_metadata_t* dst, size_t index);
camera_metadata_t* allocate_copy_camera_metadata_checked(const camera_metadata_t* src, size_t data_alignment);

// Tag info tables (defined in camera_metadata_tag_info.cpp)
extern const uint32_t camera_metadata_section_bounds[ANDROID_SECTION_COUNT][2];
extern const uint8_t* tag_info[ANDROID_SECTION_COUNT];

// Android control scene mode enum stub
typedef enum {
    ANDROID_CONTROL_SCENE_MODE_DISABLED             = 0,
    ANDROID_CONTROL_SCENE_MODE_FACE_PRIORITY        = 1,
    ANDROID_CONTROL_SCENE_MODE_ACTION               = 2,
    ANDROID_CONTROL_SCENE_MODE_PORTRAIT             = 3,
    ANDROID_CONTROL_SCENE_MODE_LANDSCAPE            = 4,
    ANDROID_CONTROL_SCENE_MODE_NIGHT                = 5,
    ANDROID_CONTROL_SCENE_MODE_NIGHT_PORTRAIT       = 6,
    ANDROID_CONTROL_SCENE_MODE_THEATRE              = 7,
    ANDROID_CONTROL_SCENE_MODE_BEACH                = 8,
    ANDROID_CONTROL_SCENE_MODE_SNOW                 = 9,
    ANDROID_CONTROL_SCENE_MODE_SUNSET               = 10,
    ANDROID_CONTROL_SCENE_MODE_STEADYPHOTO          = 11,
    ANDROID_CONTROL_SCENE_MODE_FIREWORKS            = 12,
    ANDROID_CONTROL_SCENE_MODE_SPORTS               = 13,
    ANDROID_CONTROL_SCENE_MODE_PARTY                = 14,
    ANDROID_CONTROL_SCENE_MODE_CANDLELIGHT          = 15,
    ANDROID_CONTROL_SCENE_MODE_BARCODE              = 16,
    ANDROID_CONTROL_SCENE_MODE_HIGH_SPEED_VIDEO     = 17,
    ANDROID_CONTROL_SCENE_MODE_HDR                  = 18,
    ANDROID_CONTROL_SCENE_MODE_FACE_PRIORITY_LOW_LIGHT = 19,
} camera_metadata_enum_android_control_scene_mode_t;

typedef enum {
    ANDROID_CONTROL_EFFECT_MODE_OFF          = 0,
    ANDROID_CONTROL_EFFECT_MODE_MONO         = 1,
    ANDROID_CONTROL_EFFECT_MODE_NEGATIVE     = 2,
    ANDROID_CONTROL_EFFECT_MODE_SOLARIZE     = 3,
    ANDROID_CONTROL_EFFECT_MODE_SEPIA        = 4,
    ANDROID_CONTROL_EFFECT_MODE_POSTERIZE    = 5,
    ANDROID_CONTROL_EFFECT_MODE_WHITEBOARD   = 6,
    ANDROID_CONTROL_EFFECT_MODE_BLACKBOARD   = 7,
    ANDROID_CONTROL_EFFECT_MODE_AQUA         = 8,
} camera_metadata_enum_android_control_effect_mode_t;

// Android control state enums
typedef enum {
    ANDROID_CONTROL_AE_STATE_INACTIVE = 0,
    ANDROID_CONTROL_AE_STATE_SEARCHING = 1,
    ANDROID_CONTROL_AE_STATE_CONVERGED = 2,
    ANDROID_CONTROL_AE_STATE_LOCKED = 3,
    ANDROID_CONTROL_AE_STATE_FLASH_REQUIRED = 4,
    ANDROID_CONTROL_AE_STATE_PRECAPTURE = 5,
} camera_metadata_enum_android_control_ae_state_t;

typedef enum {
    ANDROID_CONTROL_AF_STATE_INACTIVE = 0,
    ANDROID_CONTROL_AF_STATE_PASSIVE_SCAN = 1,
    ANDROID_CONTROL_AF_STATE_PASSIVE_FOCUSED = 2,
    ANDROID_CONTROL_AF_STATE_ACTIVE_SCAN = 3,
    ANDROID_CONTROL_AF_STATE_FOCUSED_LOCKED = 4,
    ANDROID_CONTROL_AF_STATE_NOT_FOCUSED_LOCKED = 5,
    ANDROID_CONTROL_AF_STATE_PASSIVE_UNFOCUSED = 6,
} camera_metadata_enum_android_control_af_state_t;

typedef enum {
    ANDROID_CONTROL_AWB_STATE_INACTIVE = 0,
    ANDROID_CONTROL_AWB_STATE_SEARCHING = 1,
    ANDROID_CONTROL_AWB_STATE_CONVERGED = 2,
    ANDROID_CONTROL_AWB_STATE_LOCKED = 3,
} camera_metadata_enum_android_control_awb_state_t;

#define ANDROID_CONTROL_VIDEO_STABILIZATION_MODE_OFF 0
#define ANDROID_CONTROL_VIDEO_STABILIZATION_MODE_ON  1

#define ANDROID_CONTROL_MODE_OFF                  0
#define ANDROID_CONTROL_MODE_AUTO                 1
#define ANDROID_CONTROL_MODE_USE_SCENE_MODE       2

#define ANDROID_CONTROL_AE_MODE_OFF               0
#define ANDROID_CONTROL_AE_MODE_ON                1
#define ANDROID_CONTROL_AE_MODE_ON_AUTO_FLASH     2
#define ANDROID_CONTROL_AE_MODE_ON_ALWAYS_FLASH   3
#define ANDROID_CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE 4

#define ANDROID_CONTROL_ENABLE_ZSL_FALSE          0
#define ANDROID_CONTROL_ENABLE_ZSL_TRUE           1

#define ANDROID_FLASH_STATE_UNAVAILABLE           0
#define ANDROID_FLASH_STATE_CHARGING              1
#define ANDROID_FLASH_STATE_READY                 2
#define ANDROID_FLASH_STATE_FIRED                 3
#define ANDROID_FLASH_STATE_PARTIAL               4

#define ANDROID_STATISTICS_FACE_DETECT_MODE_OFF    0
#define ANDROID_STATISTICS_FACE_DETECT_MODE_SIMPLE 1
#define ANDROID_STATISTICS_FACE_DETECT_MODE_FULL   2

#ifdef __cplusplus
}
#endif

#endif // _STUB_SYSTEM_CAMERA_METADATA_H
