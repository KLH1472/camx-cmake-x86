/*
 * Copyright (C) 2005 The Android Open Source Project
 *
 * Ported from AOSP system/core/libutils/include/utils/RefBase.h
 *
 * Reference-counted base class with weak-reference support.
 *
 * Usage:
 *   class MyClass : public RefBase { ... };
 *   sp<MyClass> ptr = new MyClass();       // strong reference
 *   wp<MyClass> wptr = ptr;               // weak reference
 *   sp<MyClass> promoted = wptr.promote(); // promote weak -> strong (may be null)
 *
 * Concepts:
 *   - Each RefBase object has a weakref_impl that tracks:
 *       mStrong: number of strong references (sp<>)
 *       mWeak:   number of total references (strong + weak, each sp<> counts for both)
 *   - Object lifetime:
 *       OBJECT_LIFETIME_STRONG (default): object deleted when mStrong reaches 0
 *       OBJECT_LIFETIME_WEAK: object survives until mWeak reaches 0
 *   - Each sp<> holds: strong ref + weak ref
 *   - Each wp<> holds: weak ref only
 */

#ifndef ANDROID_UTILS_REF_BASE_H
#define ANDROID_UTILS_REF_BASE_H

#include <atomic>
#include <stdint.h>
#include <sys/types.h>

// ALOG* macros for this port: redirect to fprintf or remove
#ifndef ALOG_ASSERT
#  ifdef NDEBUG
#    define ALOG_ASSERT(cond, ...) ((void)0)
#  else
#    include <assert.h>
#    define ALOG_ASSERT(cond, ...) assert(cond)
#  endif
#endif

#ifndef LIBUTILS_NATIVE
#  ifndef ALOGD
#    include <stdio.h>
#    define ALOGD(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#  endif
#endif

namespace android {

// ---------------------------------------------------------------------------

template <class T> class sp;
template <class T> class wp;

// ---------------------------------------------------------------------------

class RefBase
{
public:
            void            incStrong(const void* id) const;
            void            decStrong(const void* id) const;

            void            forceIncStrong(const void* id) const;

            //! DEBUGGING ONLY: Get current strong ref count.
            int32_t         getStrongCount() const;

    class weakref_type
    {
    public:
        RefBase*            refBase() const;

        void                incWeak(const void* id);
        void                decWeak(const void* id);

        // acquires a strong reference if there is already one.
        bool                attemptIncStrong(const void* id);

        // acquires a weak reference if there is already one.
        // This is NOT the same as incWeak() - it doesn't guarantee
        // success, because the object may have been deleted.
        bool                attemptIncWeak(const void* id);

        //! DEBUGGING ONLY: Get current weak ref count.
        int32_t             getWeakCount() const;

        //! DEBUGGING ONLY: Print references held on object.
        void                printRefs() const;

        //! DEBUGGING ONLY: Enable tracking for this object.
        //! enable -- enable/disable tracking
        //! retain -- when tracking is disabled, if true, then we keep a
        //!           weak reference to this object so that it's not collected
        void                trackMe(bool enable, bool retain);

    protected:
                            weakref_type();
        virtual             ~weakref_type();
    };

    // Create/get weak reference tracking object
            weakref_type*   createWeak(const void* id) const;
            weakref_type*   getWeakRefs() const;

    // Object lifetime mode constants
    enum {
        OBJECT_LIFETIME_STRONG  = 0x0000,
        OBJECT_LIFETIME_WEAK    = 0x0001,
        OBJECT_LIFETIME_MASK    = 0x0001
    };

protected:
                            RefBase();
    virtual                 ~RefBase();

    //! Flags for extendObjectLifetime()
    enum {
        FIRST_INC_STRONG = 0x0001
    };

public:
    void                    extendObjectLifetime(int32_t mode);

    //! Flags for onIncStrongAttempted()
    enum {
        START_INC_STRONG = 0x0001,
        END_INC_STRONG   = 0x0010
    };

    virtual void            onFirstRef();           // called on first strong ref
    virtual void            onLastStrongRef(const void* id); // called on last strong ref going away
    virtual bool            onIncStrongAttempted(uint32_t flags, const void* id);
    virtual void            onLastWeakRef(const void* id);  // called on last weak ref going away

private:
    friend class weakref_type;
    class weakref_impl;

    RefBase(const RefBase& o);              // not copyable
    RefBase& operator=(const RefBase& o);   // not assignable

    // Weakref_impl is const after construction; safe to access without lock
    weakref_impl* const mRefs;
};

// ---------------------------------------------------------------------------

/*
 * LightRefBase: similar to RefBase but only supports strong references.
 * No weak-reference tracking, no onFirstRef/onLastStrongRef callbacks.
 * Suitable for simple cases (e.g., Fence uses LightRefBase).
 */
template <class T>
class LightRefBase
{
public:
    inline LightRefBase() : mCount(0) { }
    inline void incStrong(__attribute__((unused)) const void* id) const {
        mCount.fetch_add(1, std::memory_order_relaxed);
    }
    inline void decStrong(__attribute__((unused)) const void* id) const {
        if (mCount.fetch_sub(1, std::memory_order_release) == 1) {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<const T*>(this);
        }
    }
    //! DEBUGGING ONLY: Get current strong ref count.
    inline int32_t getStrongCount() const {
        return mCount.load(std::memory_order_relaxed);
    }

    typedef LightRefBase<T> basetype;

protected:
    inline ~LightRefBase() { }

private:
    friend class sp<T>;

    mutable std::atomic<int32_t> mCount;
};

// ---------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_UTILS_REF_BASE_H
