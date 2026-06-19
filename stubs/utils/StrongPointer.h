/*
 * Copyright (C) 2005 The Android Open Source Project
 *
 * Ported from AOSP system/core/libutils/include/utils/StrongPointer.h
 *
 * Smart pointer templates: sp<T> (strong pointer) and wp<T> (weak pointer).
 *
 * sp<T> is analogous to std::shared_ptr<T>: it holds a strong reference.
 *   When the last sp<> is destroyed, the object is deleted (OBJECT_LIFETIME_STRONG).
 *
 * wp<T> is analogous to std::weak_ptr<T>: it holds a weak reference.
 *   Call promote() to attempt to get an sp<>.
 */

#ifndef ANDROID_UTILS_STRONG_POINTER_H
#define ANDROID_UTILS_STRONG_POINTER_H

#include <utils/RefBase.h>

#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>

namespace android {

// ---------------------------------------------------------------------------

template <typename T> class sp;

template <typename T>
class sp
{
public:
    inline sp() : m_ptr(nullptr) { }

    // The pattern sp<T> p = new T() is handled by the constructor from T*
    // Taking a strong reference is implicit in construction.
    sp(T* other);

    sp(const sp<T>& other);
    sp(sp<T>&& other) noexcept;

    template<typename U> sp(U* other);
    template<typename U> sp(const sp<U>& other);
    template<typename U> sp(sp<U>&& other) noexcept;

    ~sp();

    // Assignment
    sp& operator=(T* other);
    sp& operator=(const sp<T>& other);
    sp& operator=(sp<T>&& other) noexcept;

    template<typename U> sp& operator=(const sp<U>& other);
    template<typename U> sp& operator=(U* other);
    template<typename U> sp& operator=(sp<U>&& other) noexcept;

    //! Special optimization for use with ProcessState (no ref counting)
    void force_set(T* other);

    // Reset
    void clear();

    // Accessors
    inline T&       operator* () const     { return *m_ptr; }
    inline T*       operator-> () const    { return m_ptr;  }
    inline T*       get() const            { return m_ptr; }

    // Operators

    // This allows referencing sp<> as a condition
    explicit inline operator bool() const {
        return m_ptr != nullptr;
    }

private:
    template<typename Y> friend class sp;
    template<typename Y> friend class wp;
    void set_pointer(T* ptr);
    T* m_ptr;
};

// ---------------------------------------------------------------------------

template <typename T>
class wp
{
public:
    typedef typename RefBase::weakref_type weakref_type;

    inline wp() : m_ptr(nullptr), m_refs(nullptr) { }

    // if nullptr, not initialized
    wp(T* other);
    wp(const wp<T>& other);
    wp(const sp<T>& other);

    template<typename U> wp(U* other);
    template<typename U> wp(const sp<U>& other);
    template<typename U> wp(const wp<U>& other);

    ~wp();

    // Assignment
    wp& operator = (T* other);
    wp& operator = (const wp<T>& other);
    wp& operator = (const sp<T>& other);

    template<typename U> wp& operator = (U* other);
    template<typename U> wp& operator = (const wp<U>& other);
    template<typename U> wp& operator = (const sp<U>& other);

    void set_object_and_refs(T* other, weakref_type* refs);

    // promotion to sp
    sp<T> promote() const;

    // Reset
    void clear();

    // Accessors
    inline  weakref_type* get_refs() const { return m_refs; }

    inline T* unsafe_get() const { return m_ptr; }

    // Operators
    inline bool operator == (const wp<T>& o) const {
        return (m_ptr == o.m_ptr) && (m_refs == o.m_refs);
    }
    template<typename U>
    inline bool operator == (const wp<U>& o) const {
        return m_ptr == o.m_ptr;
    }

    inline bool operator > (const wp<T>& o) const {
        return (m_ptr == o.m_ptr) ? (m_refs > o.m_refs) : (m_ptr > o.m_ptr);
    }
    template<typename U>
    inline bool operator > (const wp<U>& o) const {
        return (m_ptr == o.m_ptr) ? (m_refs > o.m_refs) : (m_ptr > o.m_ptr);
    }

    inline bool operator < (const wp<T>& o) const {
        return (m_ptr == o.m_ptr) ? (m_refs < o.m_refs) : (m_ptr < o.m_ptr);
    }
    template<typename U>
    inline bool operator < (const wp<U>& o) const {
        return (m_ptr == o.m_ptr) ? (m_refs < o.m_refs) : (m_ptr < o.m_ptr);
    }
                         inline bool operator != (const wp<T>& o) const { return m_refs != o.m_refs; }
    template<typename U> inline bool operator != (const wp<U>& o) const { return !operator == (o); }
                         inline bool operator <= (const wp<T>& o) const { return !operator > (o); }
    template<typename U> inline bool operator <= (const wp<U>& o) const { return !operator > (o); }
                         inline bool operator >= (const wp<T>& o) const { return !operator < (o); }
    template<typename U> inline bool operator >= (const wp<U>& o) const { return !operator < (o); }

private:
    template<typename Y> friend class sp;
    template<typename Y> friend class wp;

    T*              m_ptr;
    weakref_type*   m_refs;
};

// ---------------------------------------------------------------------------
// sp<T> implementation
// ---------------------------------------------------------------------------

template <typename T>
sp<T>::sp(T* other)
        : m_ptr(other) {
    if (other) {
        other->incStrong(this);
    }
}

template <typename T>
sp<T>::sp(const sp<T>& other)
        : m_ptr(other.m_ptr) {
    if (m_ptr) {
        m_ptr->incStrong(this);
    }
}

template <typename T>
sp<T>::sp(sp<T>&& other) noexcept
        : m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
}

template <typename T> template <typename U>
sp<T>::sp(U* other)
        : m_ptr(other) {
    if (other) {
        other->incStrong(this);
    }
}

template <typename T> template <typename U>
sp<T>::sp(const sp<U>& other)
        : m_ptr(other.m_ptr) {
    if (m_ptr) {
        m_ptr->incStrong(this);
    }
}

template <typename T> template <typename U>
sp<T>::sp(sp<U>&& other) noexcept
        : m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
}

template <typename T>
sp<T>::~sp() {
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
}

template <typename T>
sp<T>& sp<T>::operator=(T* other) {
    if (other) {
        other->incStrong(this);
    }
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = other;
    return *this;
}

template <typename T>
sp<T>& sp<T>::operator=(const sp<T>& other) {
    T* otherPtr(other.m_ptr);
    if (otherPtr) {
        otherPtr->incStrong(this);
    }
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = otherPtr;
    return *this;
}

template <typename T>
sp<T>& sp<T>::operator=(sp<T>&& other) noexcept {
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
}

template <typename T> template <typename U>
sp<T>& sp<T>::operator=(const sp<U>& other) {
    T* otherPtr(other.m_ptr);
    if (otherPtr) {
        otherPtr->incStrong(this);
    }
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = otherPtr;
    return *this;
}

template <typename T> template <typename U>
sp<T>& sp<T>::operator=(U* other) {
    if (other) {
        static_cast<T*>(other)->incStrong(this);
    }
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = other;
    return *this;
}

template <typename T> template <typename U>
sp<T>& sp<T>::operator=(sp<U>&& other) noexcept {
    if (m_ptr) {
        m_ptr->decStrong(this);
    }
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
}

template <typename T>
void sp<T>::force_set(T* other) {
    if (other) {
        other->forceIncStrong(this);
    }
    m_ptr = other;
}

template <typename T>
void sp<T>::clear() {
    if (m_ptr) {
        m_ptr->decStrong(this);
        m_ptr = nullptr;
    }
}

template <typename T>
void sp<T>::set_pointer(T* ptr) {
    m_ptr = ptr;
}

// ---------------------------------------------------------------------------
// wp<T> implementation
// ---------------------------------------------------------------------------

template <typename T>
wp<T>::wp(T* other)
    : m_ptr(other)
{
    if (other) {
        m_refs = other->createWeak(this);
    } else {
        m_refs = nullptr;
    }
}

template <typename T>
wp<T>::wp(const wp<T>& other)
    : m_ptr(other.m_ptr), m_refs(other.m_refs)
{
    if (m_ptr) {
        m_refs->incWeak(this);
    }
}

template <typename T>
wp<T>::wp(const sp<T>& other)
    : m_ptr(other.m_ptr), m_refs(nullptr)
{
    if (m_ptr) {
        m_refs = m_ptr->createWeak(this);
    }
}

template <typename T> template <typename U>
wp<T>::wp(U* other)
    : m_ptr(other)
{
    if (other) {
        m_refs = other->createWeak(this);
    }
}

template <typename T> template <typename U>
wp<T>::wp(const sp<U>& other)
    : m_ptr(other.m_ptr), m_refs(nullptr)
{
    if (m_ptr) {
        m_refs = m_ptr->createWeak(this);
    }
}

template <typename T> template <typename U>
wp<T>::wp(const wp<U>& other)
    : m_ptr(other.m_ptr), m_refs(other.m_refs)
{
    if (m_ptr) {
        m_refs->incWeak(this);
    }
}

template <typename T>
wp<T>::~wp() {
    if (m_ptr) {
        m_refs->decWeak(this);
    }
}

template <typename T>
wp<T>& wp<T>::operator=(T* other) {
    weakref_type* newRefs = other ? other->createWeak(this) : nullptr;
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = other;
    m_refs = newRefs;
    return *this;
}

template <typename T>
wp<T>& wp<T>::operator=(const wp<T>& other) {
    weakref_type* newRefs = other.m_refs;
    T* newPtr = other.m_ptr;
    if (newPtr) {
        newRefs->incWeak(this);
    }
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = newPtr;
    m_refs = newRefs;
    return *this;
}

template <typename T>
wp<T>& wp<T>::operator=(const sp<T>& other) {
    T* newPtr = other.get();
    weakref_type* newRefs = newPtr ? newPtr->createWeak(this) : nullptr;
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = newPtr;
    m_refs = newRefs;
    return *this;
}

template <typename T> template <typename U>
wp<T>& wp<T>::operator=(U* other) {
    weakref_type* newRefs = other ? other->createWeak(this) : nullptr;
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = other;
    m_refs = newRefs;
    return *this;
}

template <typename T> template <typename U>
wp<T>& wp<T>::operator=(const wp<U>& other) {
    weakref_type* newRefs = other.m_refs;
    U* newPtr = other.m_ptr;
    if (newPtr) {
        newRefs->incWeak(this);
    }
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = newPtr;
    m_refs = newRefs;
    return *this;
}

template <typename T> template <typename U>
wp<T>& wp<T>::operator=(const sp<U>& other) {
    U* newPtr = other.get();
    weakref_type* newRefs = newPtr ? newPtr->createWeak(this) : nullptr;
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = newPtr;
    m_refs = newRefs;
    return *this;
}

template <typename T>
void wp<T>::set_object_and_refs(T* other, weakref_type* refs) {
    if (refs) {
        refs->incWeak(this);
    }
    if (m_ptr) {
        m_refs->decWeak(this);
    }
    m_ptr = other;
    m_refs = refs;
}

template <typename T>
sp<T> wp<T>::promote() const {
    sp<T> result;
    if (m_ptr && m_refs->attemptIncStrong(&result)) {
        result.set_pointer(m_ptr);
    }
    return result;
}

template <typename T>
void wp<T>::clear() {
    if (m_ptr) {
        m_refs->decWeak(this);
        m_ptr = nullptr;
        m_refs = nullptr;
    }
}

// ---------------------------------------------------------------------------

// Comparison operators for sp<>

template <typename T, typename U>
inline bool operator==(const sp<T>& lhs, const sp<U>& rhs) {
    return lhs.get() == rhs.get();
}

template <typename T, typename U>
inline bool operator==(const sp<T>& lhs, U* rhs) {
    return lhs.get() == rhs;
}

template <typename T, typename U>
inline bool operator==(T* lhs, const sp<U>& rhs) {
    return lhs == rhs.get();
}

template <typename T, typename U>
inline bool operator!=(const sp<T>& lhs, const sp<U>& rhs) {
    return lhs.get() != rhs.get();
}

template <typename T, typename U>
inline bool operator!=(const sp<T>& lhs, U* rhs) {
    return lhs.get() != rhs;
}

template <typename T, typename U>
inline bool operator!=(T* lhs, const sp<U>& rhs) {
    return lhs != rhs.get();
}

template <typename T>
inline bool operator==(const sp<T>& lhs, std::nullptr_t) {
    return lhs.get() == nullptr;
}

template <typename T>
inline bool operator==(std::nullptr_t, const sp<T>& rhs) {
    return rhs.get() == nullptr;
}

template <typename T>
inline bool operator!=(const sp<T>& lhs, std::nullptr_t) {
    return lhs.get() != nullptr;
}

template <typename T>
inline bool operator!=(std::nullptr_t, const sp<T>& rhs) {
    return rhs.get() != nullptr;
}

// ---------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_UTILS_STRONG_POINTER_H
