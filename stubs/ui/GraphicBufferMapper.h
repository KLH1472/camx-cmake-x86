#ifndef _STUB_UI_GRAPHICBUFFERMAPPER_H
#define _STUB_UI_GRAPHICBUFFERMAPPER_H

#include <stdint.h>

namespace android {

class GraphicBufferMapper {
public:
    enum class Version {
        GRALLOC_2,
        GRALLOC_3,
        GRALLOC_4,
    };

    static GraphicBufferMapper& get() {
        static GraphicBufferMapper instance;
        return instance;
    }

    int lock(void* handle, uint32_t usage, const void* rect, void** vaddr) {
        *vaddr = nullptr;
        return 0;
    }

    int unlock(void* handle) {
        return 0;
    }

    void getTransportSize(void* handle, uint32_t* outNumFds, uint32_t* outNumInts) {
        *outNumFds = 0;
        *outNumInts = 0;
    }

    int lockAsync(void* handle, uint32_t usage, const void* rect, void** vaddr, int fenceFd) {
        *vaddr = nullptr;
        return 0;
    }

    int unlockAsync(void* handle, int* fenceFd) {
        *fenceFd = -1;
        return 0;
    }
};

} // namespace android

#endif // _STUB_UI_GRAPHICBUFFERMAPPER_H
