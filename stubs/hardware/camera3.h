#ifndef _STUB_HARDWARE_CAMERA3_H
#define _STUB_HARDWARE_CAMERA3_H

#include <stdint.h>
#include <stdbool.h>
#include <system/camera_metadata.h>
#include "camera_common.h"

#ifdef __cplusplus
extern "C" {
#endif

// Camera device version
#define CAMERA_DEVICE_API_VERSION_3_0  0x300

// camera3_stream_type_t
typedef int camera3_stream_type_t;

// Stream types
#define CAMERA3_STREAM_OUTPUT  0
#define CAMERA3_STREAM_INPUT   1
#define CAMERA3_STREAM_BIDIRECTIONAL 2

// Rotation
#define CAMERA3_STREAM_ROTATION_0     0
#define CAMERA3_STREAM_ROTATION_90    1
#define CAMERA3_STREAM_ROTATION_180   2
#define CAMERA3_STREAM_ROTATION_270   3

// Stream configuration mode
#define CAMERA3_STREAM_CONFIGURATION_NORMAL_MODE 0
#define CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE 1

// Template types
#define CAMERA3_TEMPLATE_PREVIEW              1
#define CAMERA3_TEMPLATE_STILL_CAPTURE        2
#define CAMERA3_TEMPLATE_VIDEO_RECORD         3
#define CAMERA3_TEMPLATE_VIDEO_SNAPSHOT       4
#define CAMERA3_TEMPLATE_ZERO_SHUTTER_LAG     5
#define CAMERA3_TEMPLATE_MANUAL               6

// Buffer status
#define CAMERA3_BUFFER_STATUS_OK              0
#define CAMERA3_BUFFER_STATUS_ERROR           1

// Message types
#define CAMERA3_MSG_ERROR                     1
#define CAMERA3_MSG_SHUTTER                   2

// Error codes
#define CAMERA3_MSG_ERROR_DEVICE              1
#define CAMERA3_MSG_ERROR_REQUEST             2
#define CAMERA3_MSG_ERROR_RESULT              3
#define CAMERA3_MSG_ERROR_BUFFER              4

// Request template
#define CAMERA3_REQUEST_TEMPLATE_PREVIEW       1
#define CAMERA3_REQUEST_TEMPLATE_STILL_CAPTURE 2
#define CAMERA3_REQUEST_TEMPLATE_VIDEO_RECORD  3
#define CAMERA3_REQUEST_TEMPLATE_VIDEO_SNAPSHOT 4
#define CAMERA3_REQUEST_TEMPLATE_ZERO_SHUTTER_LAG 5
#define CAMERA3_REQUEST_TEMPLATE_MANUAL        6

// Vendor stream config mode
#define CAMERA3_VENDOR_STREAM_CONFIGURATION_MODE 0x8000

// Forward declarations
typedef struct camera3_device camera3_device_t;
typedef struct camera3_stream camera3_stream_t;
typedef struct camera3_stream_configuration camera3_stream_configuration_t;
typedef struct camera3_stream_buffer camera3_stream_buffer_t;
typedef struct camera_info camera_info_t;
typedef struct camera_metadata camera_metadata_t;

// Stream buffer
typedef struct camera3_stream_buffer {
    camera3_stream_t* stream;
    void*             buffer;
    int               status;
    int               acquire_fence;
    int               release_fence;
} camera3_stream_buffer_t;

// Stream
typedef struct camera3_stream {
    int             stream_type;
    uint32_t        width;
    uint32_t        height;
    int             format;
    uint32_t        usage;
    uint32_t        max_buffers;
    void*           priv;
    int             data_space;
    int             rotation;
    const char*     physical_camera_id;
    void*           reserved[6];
} camera3_stream_t;

// Stream configuration
typedef struct camera3_stream_configuration {
    uint32_t                num_streams;
    camera3_stream_t**      streams;
    uint32_t                operation_mode;
    const camera_metadata_t* session_parameters;
} camera3_stream_configuration_t;

// Capture request
typedef struct camera3_capture_request {
    uint32_t                    frame_number;
    const camera_metadata_t*    settings;
    const camera3_stream_buffer_t* input_buffer;
    uint32_t                    num_output_buffers;
    const camera3_stream_buffer_t* output_buffers;
    void*                       priv;
} camera3_capture_request_t;

// Capture result
typedef struct camera3_capture_result {
    uint32_t                    frame_number;
    const camera_metadata_t*    result;
    uint32_t                    num_output_buffers;
    const camera3_stream_buffer_t* output_buffers;
    const camera3_stream_buffer_t* input_buffer;
    uint32_t                    partial_result;
    uint32_t                    num_physcam_metadata;
    const char**                physcam_ids;
    const camera_metadata_t**   physcam_metadata;
} camera3_capture_result_t;

// Notify message
typedef struct camera3_notify_msg {
    int     type;
    union {
        struct {
            uint32_t frame_number;
            void*    stream;
            int      error_code;
        } error;
        struct {
            uint32_t frame_number;
            uint64_t timestamp;
        } shutter;
    } message;
} camera3_notify_msg_t;

// Camera3 callback ops (HAL -> framework)
typedef struct camera3_callback_ops {
    void (*process_capture_result)(const struct camera3_callback_ops*, const camera3_capture_result_t*);
    void (*notify)(const struct camera3_callback_ops*, const camera3_notify_msg_t*);
    camera3_stream_buffer_t* (*request_stream_buffers)(const struct camera3_callback_ops*, uint32_t, uint32_t, uint32_t*, camera3_stream_buffer_t*);
    void (*return_stream_buffers)(const struct camera3_callback_ops*, uint32_t, const camera3_stream_buffer_t*);
} camera3_callback_ops_t;

// Camera3 device ops (minimal stub)
typedef struct camera3_device_ops {
    int (*initialize)(const camera3_device_t*, const camera3_callback_ops_t*);
    int (*configure_streams)(const camera3_device_t*, camera3_stream_configuration_t*);
    const camera_metadata_t* (*construct_default_request_settings)(const camera3_device_t*, int type);
    int (*process_capture_request)(const camera3_device_t*, camera3_capture_request_t*);
    void (*get_metadata_vendor_tag_ops)(const camera3_device_t*, vendor_tag_ops_t*);
    void (*dump)(const camera3_device_t*, int fd);
    int (*flush)(const camera3_device_t*);
    void* reserved[8];
} camera3_device_ops_t;

// Camera3 device
typedef struct camera3_device {
    void*                   common;
    camera3_device_ops_t*   ops;
    void*                   priv;
} camera3_device_t;

#ifdef __cplusplus
}
#endif

#endif // _STUB_HARDWARE_CAMERA3_H
