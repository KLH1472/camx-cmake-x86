#ifndef _STUB_UI_GRAPHICBUFFER_H
#define _STUB_UI_GRAPHICBUFFER_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <utils/StrongPointer.h>
#include <system/window.h>
#include <ui/GraphicBufferMapper.h>

namespace android {

class GraphicBuffer {
public:
    static constexpr uint32_t USAGE_SW_READ_NEVER     = 0x00000000;
    static constexpr uint32_t USAGE_SW_READ_RARELY    = 0x00000002;
    static constexpr uint32_t USAGE_SW_READ_OFTEN     = 0x00000003;
    static constexpr uint32_t USAGE_SW_WRITE_NEVER    = 0x00000000;
    static constexpr uint32_t USAGE_SW_WRITE_RARELY   = 0x00000020;
    static constexpr uint32_t USAGE_SW_WRITE_OFTEN    = 0x00000030;
    static constexpr uint32_t USAGE_HW_TEXTURE        = 0x00000100;
    static constexpr uint32_t USAGE_HW_RENDER         = 0x00000200;
    static constexpr uint32_t USAGE_HW_2D             = 0x00000400;
    static constexpr uint32_t USAGE_HW_COMPOSER       = 0x00000800;
    static constexpr uint32_t USAGE_HW_VIDEO_ENCODER  = 0x00010000;
    static constexpr uint32_t USAGE_HW_CAMERA_WRITE   = 0x00020000;
    static constexpr uint32_t USAGE_HW_CAMERA_READ    = 0x00040000;
    static constexpr uint32_t USAGE_HW_MASK           = 0x00071F00;

    GraphicBuffer() : mBuffer(nullptr), mBufSize(0) {}
    GraphicBuffer(uint32_t w, uint32_t h, int32_t fmt, uint32_t u)
        : width(w), height(h), format(fmt), usage(u), stride(w), mBuffer(nullptr), mBufSize(0) {
        mBufSize = w * h * 4; // RGBA max
        mBuffer = malloc(mBufSize);
        memset(mBuffer, 0, mBufSize);
    }
    ~GraphicBuffer() { free(mBuffer); }

    uint32_t getWidth() const { return width; }
    uint32_t getHeight() const { return height; }
    uint32_t getStride() const { return stride; }
    uint32_t getUsage() const { return usage; }
    int getPixelFormat() const { return format; }
    ANativeWindowBuffer_t* getNativeBuffer() const { return &anwb; }
    int initCheck() const { return 0; }
    int lock(uint32_t, void** vaddr) { *vaddr = mBuffer; return 0; }
    int lock(uint32_t, const void*, void** vaddr) { *vaddr = mBuffer; return 0; }
    int unlock() { return 0; }

    GraphicBufferMapper::Version getBufferMapperVersion() const {
        return GraphicBufferMapper::Version::GRALLOC_3;
    }

    int getFd() const { return -1; }
    size_t getAllocationSize() const { return mBufSize; }
    int reallocate(uint32_t w, uint32_t h, int32_t fmt, uint32_t u) {
        free(mBuffer);
        width = w; height = h; format = fmt; usage = u; stride = w;
        mBufSize = w * h * 4;
        mBuffer = malloc(mBufSize);
        memset(mBuffer, 0, mBufSize);
        return 0;
    }

private:
    mutable ANativeWindowBuffer_t anwb;
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t stride = 0;
    uint32_t usage = 0;
    int32_t format = 0;
    void* mBuffer;
    size_t mBufSize;
};

} // namespace android

#endif // _STUB_UI_GRAPHICBUFFER_H
