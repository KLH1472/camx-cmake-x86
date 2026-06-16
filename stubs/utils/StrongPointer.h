#ifndef _STUB_UTILS_STRONGPOINTER_H
#define _STUB_UTILS_STRONGPOINTER_H

#include <memory>

namespace android {

template <typename T>
class sp {
public:
    sp() : mPtr(nullptr) {}
    sp(T* ptr) : mPtr(ptr) {}
    sp(const sp<T>& other) : mPtr(other.mPtr) {}
    sp(std::nullptr_t) : mPtr(nullptr) {}

    sp& operator=(T* ptr) { mPtr = ptr; return *this; }
    sp& operator=(const sp<T>& other) { mPtr = other.mPtr; return *this; }
    sp& operator=(std::nullptr_t) { mPtr = nullptr; return *this; }

    T* get() const { return mPtr; }
    void clear() { mPtr = nullptr; }
    T* operator->() const { return mPtr; }
    T& operator*() const { return *mPtr; }
    operator bool() const { return mPtr != nullptr; }

    bool operator==(const sp<T>& other) const { return mPtr == other.mPtr; }
    bool operator!=(const sp<T>& other) const { return mPtr != other.mPtr; }
    bool operator==(std::nullptr_t) const { return mPtr == nullptr; }
    bool operator!=(std::nullptr_t) const { return mPtr != nullptr; }

private:
    T* mPtr;
};

template <typename T>
class wp {
public:
    wp() : mPtr(nullptr) {}
    wp(T* ptr) : mPtr(ptr) {}
    sp<T> promote() const { return sp<T>(mPtr); }
private:
    T* mPtr;
};

} // namespace android

#endif // _STUB_UTILS_STRONGPOINTER_H
