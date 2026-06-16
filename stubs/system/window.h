#ifndef _STUB_SYSTEM_WINDOW_H
#define _STUB_SYSTEM_WINDOW_H

#include <stdint.h>
#include <cutils/native_handle.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ANativeWindowBuffer {
    int width;
    int height;
    int stride;
    int format;
    int usage;
    uint32_t layerCount;
    native_handle_t* handle;
    uint64_t usage_producer;
    uint64_t usage_consumer;
} ANativeWindowBuffer_t;

#ifdef __cplusplus
}
#endif

#endif // _STUB_SYSTEM_WINDOW_H
