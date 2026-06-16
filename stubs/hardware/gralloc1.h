#ifndef _STUB_HARDWARE_GRALLOC1_H
#define _STUB_HARDWARE_GRALLOC1_H

#include <stdint.h>
#include <cutils/native_handle.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef const native_handle_t* buffer_handle_t;

// gralloc1 error codes
#define GRALLOC1_ERROR_NONE         0
#define GRALLOC1_ERROR_BAD_HANDLE   1
#define GRALLOC1_ERROR_BAD_VALUE    2
#define GRALLOC1_ERROR_UNDEFINED    3
#define GRALLOC1_ERROR_UNSUPPORTED  4
#define GRALLOC1_ERROR_NO_RESOURCES 5

typedef int32_t gralloc1_error_t;

// gralloc1 usage flags
#define GRALLOC1_CONSUMER_USAGE_CPU_READ           (1ULL << 0)
#define GRALLOC1_CONSUMER_USAGE_CPU_READ_OFTEN     (1ULL << 1)
#define GRALLOC1_CONSUMER_USAGE_CPU_WRITE          (1ULL << 2)
#define GRALLOC1_CONSUMER_USAGE_CPU_WRITE_OFTEN    (1ULL << 3)
#define GRALLOC1_CONSUMER_USAGE_GPU_TEXTURE        (1ULL << 8)

#define GRALLOC1_PRODUCER_USAGE_CPU_READ           (1ULL << 0)
#define GRALLOC1_PRODUCER_USAGE_CPU_WRITE          (1ULL << 2)
#define GRALLOC1_PRODUCER_USAGE_GPU_RENDER_TARGET  (1ULL << 9)
#define GRALLOC1_PRODUCER_USAGE_CAMERA             (1ULL << 16)
#define GRALLOC1_PRODUCER_USAGE_VIDEO_DECODER      (1ULL << 22)

// gralloc1 function/perform codes
#define GRALLOC1_FUNCTION_LOCK             0x00000001
#define GRALLOC1_FUNCTION_UNLOCK           0x00000002
#define GRALLOC1_FUNCTION_ALLOCATE         0x00000003
#define GRALLOC1_FUNCTION_RETAIN           0x00000004
#define GRALLOC1_FUNCTION_RELEASE          0x00000005
#define GRALLOC1_FUNCTION_GET_STRIDE       0x00000006
#define GRALLOC1_FUNCTION_SET_CONSUMER_USAGE 0x00000007
#define GRALLOC1_FUNCTION_SET_PRODUCER_USAGE 0x00000008

// gralloc1 buffer descriptor
typedef struct gralloc1_buffer_descriptor_t {
    uint32_t width;
    uint32_t height;
    int32_t  format;
    uint32_t producerUsage;
    uint32_t consumerUsage;
    uint32_t numFlexPlanes;
} gralloc1_buffer_descriptor_t;

// gralloc1 rect
typedef struct gralloc1_rect {
    int32_t left;
    int32_t top;
    int32_t width;
    int32_t height;
} gralloc1_rect_t;

// gralloc1 device (opaque stub)
typedef struct gralloc1_device {
    void* common;
} gralloc1_device_t;

#ifdef __cplusplus
}
#endif

#endif // _STUB_HARDWARE_GRALLOC1_H
