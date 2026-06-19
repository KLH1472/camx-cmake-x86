/*
 * Copyright (C) 2005 The Android Open Source Project
 *
 * Ported from AOSP system/core/libutils/RefBase.cpp
 *
 * Implementation of RefBase reference counting with weak-reference support.
 */

#include <utils/RefBase.h>

#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include <sys/types.h>
#include <unistd.h>

// Sentinel value for mStrong before the first strong reference is taken.
// Must be a value that cannot be reached by real counting (both positive
// and large enough to detect the "first reference" condition).
#define INITIAL_STRONG_VALUE (1<<28)

// ---------------------------------------------------------------------------

namespace android {

// ---------------------------------------------------------------------------

class RefBase::weakref_impl : public RefBase::weakref_type
{
public:
    std::atomic<int32_t>    mStrong;
    std::atomic<int32_t>    mWeak;
    RefBase* const          mBase;
    std::atomic<int32_t>    mFlags;

#if !DEBUG_REFS
    explicit weakref_impl(RefBase* base)
        : mStrong(INITIAL_STRONG_VALUE)
        , mWeak(0)
        , mBase(base)
        , mFlags(0)
    {
    }

    void addStrongRef(const void* /*id*/) { }
    void removeStrongRef(const void* /*id*/) { }
    void renameStrongRefId(const void* /*old_id*/, const void* /*new_id*/) { }
    void addWeakRef(const void* /*id*/) { }
    void removeWeakRef(const void* /*id*/) { }
    void renameWeakRefId(const void* /*old_id*/, const void* /*new_id*/) { }
    void printRefs() const { }
    void trackMe(bool, bool) { }

#else
    // Debug implementation: track each reference with caller address.
    // Useful for finding leaks in the full Android build.
    // We skip this in the port for simplicity.

    struct ref_entry {
        const void* id;
        int32_t     count;
    };

    static constexpr size_t MAX_REFS = 16;
    ref_entry mStrongRefs[MAX_REFS];
    ref_entry mWeakRefs[MAX_REFS];
    size_t mStrongRefCount;
    size_t mWeakRefCount;
    bool mTrackEnabled;

    explicit weakref_impl(RefBase* base)
        : mStrong(INITIAL_STRONG_VALUE)
        , mWeak(0)
        , mBase(base)
        , mFlags(0)
        , mStrongRefCount(0)
        , mWeakRefCount(0)
        , mTrackEnabled(!!DEBUG_REFS_ENABLED_BY_DEFAULT)
    {
        memset(mStrongRefs, 0, sizeof(mStrongRefs));
        memset(mWeakRefs, 0, sizeof(mWeakRefs));
    }

    void addStrongRef(const void* id);
    void removeStrongRef(const void* id);
    void renameStrongRefId(const void* old_id, const void* new_id);
    void addWeakRef(const void* id);
    void removeWeakRef(const void* id);
    void renameWeakRefId(const void* old_id, const void* new_id);
    void printRefs() const;
    void trackMe(bool enable, bool retain);
#endif
};

// ---------------------------------------------------------------------------
// Public RefBase interface
// ---------------------------------------------------------------------------

RefBase::RefBase()
    : mRefs(new weakref_impl(this))
{
}

RefBase::~RefBase()
{
    int32_t flags = mRefs->mFlags.load(std::memory_order_relaxed);

    if ((flags & OBJECT_LIFETIME_MASK) == OBJECT_LIFETIME_WEAK) {
        // The object is being deleted from decWeak (last weak ref gone).
        // decWeak has already decremented mWeak to 0 and will
        // handle deletion of mRefs. Don't touch it here.
        return;
    }

    // OBJECT_LIFETIME_STRONG:
    // The object is being deleted from decStrong (last strong ref gone).
    // mRefs may still have outstanding weak references (wp<>).
    if (mRefs->mWeak.load(std::memory_order_relaxed) == 0) {
        // No references at all - clean up
        delete mRefs;
    }
    // Otherwise, mRefs is kept alive by wp<> references.
    // The last wp<> will trigger decWeak which deletes mRefs.
}

void RefBase::extendObjectLifetime(int32_t mode)
{
    mRefs->mFlags.fetch_or(mode, std::memory_order_relaxed);
}

void RefBase::incStrong(const void* id) const
{
    weakref_impl* const refs = mRefs;
    refs->incWeak(id);
    refs->addStrongRef(id);

    const int32_t c = refs->mStrong.fetch_add(1, std::memory_order_relaxed);

    ALOG_ASSERT(c > 0, "incStrong() called on %p after last strong ref", refs);

    if (c != INITIAL_STRONG_VALUE) {
        return;
    }

    // First strong reference. Adjust from the sentinel value.
    int32_t old __attribute__((unused)) =
        refs->mStrong.fetch_sub(INITIAL_STRONG_VALUE, std::memory_order_relaxed);
    // old should equal INITIAL_STRONG_VALUE at this point (atomicity guarantee)
    ALOG_ASSERT(old > INITIAL_STRONG_VALUE, "incStrong: mStrong wrapped");

    refs->mBase->onFirstRef();
}

void RefBase::decStrong(const void* id) const
{
    weakref_impl* const refs = mRefs;
    refs->removeStrongRef(id);

    const int32_t c = refs->mStrong.fetch_sub(1, std::memory_order_release);

    ALOG_ASSERT(c >= 1, "decStrong() called on %p too many times", refs);

    if (c == 1) {
        std::atomic_thread_fence(std::memory_order_acquire);
        refs->mBase->onLastStrongRef(id);

        int32_t flags = refs->mFlags.load(std::memory_order_relaxed);
        if ((flags & OBJECT_LIFETIME_MASK) == OBJECT_LIFETIME_STRONG) {
            delete this;
            // The destructor ran. refs is still valid because incStrong()
            // also called incWeak(), so mWeak > 0.
            // The subsequent decWeak() below will handle cleaning up refs.
        }
    }
    // Decrement the weak count that was paired with this strong reference.
    // This must happen AFTER potential delete this, since the object
    // might have been deleted but mRefs is still alive (held by mWeak > 0).
    refs->decWeak(id);
}

int32_t RefBase::getStrongCount() const
{
    int32_t c = mRefs->mStrong.load(std::memory_order_relaxed);
    if (c == INITIAL_STRONG_VALUE) {
        return 0;
    }
    return c;
}

void RefBase::forceIncStrong(const void* id) const
{
    // Used by Binder's ProcessState to force a strong reference
    // without going through the normal incStrong path.
    // In the port, this just calls incStrong.
    incStrong(id);
}

// ---------------------------------------------------------------------------
// Weak reference interface
// ---------------------------------------------------------------------------

RefBase::weakref_type* RefBase::createWeak(const void* id) const
{
    mRefs->incWeak(id);
    return mRefs;
}

RefBase::weakref_type* RefBase::getWeakRefs() const
{
    return mRefs;
}

// ---------------------------------------------------------------------------
// Virtual overrides (default no-op implementations)
// ---------------------------------------------------------------------------

void RefBase::onFirstRef()
{
}

void RefBase::onLastStrongRef(const void* /*id*/)
{
}

bool RefBase::onIncStrongAttempted(uint32_t flags, const void* /*id*/)
{
    // Default: allow the promotion attempt to proceed.
    return (flags & FIRST_INC_STRONG) ? true : true;
}

void RefBase::onLastWeakRef(const void* /*id*/)
{
}

// ---------------------------------------------------------------------------
// weakref_type implementation
// ---------------------------------------------------------------------------

RefBase::weakref_type::weakref_type()
{
}

RefBase::weakref_type::~weakref_type()
{
}

RefBase* RefBase::weakref_type::refBase() const
{
    return static_cast<const weakref_impl*>(this)->mBase;
}

void RefBase::weakref_type::incWeak(const void* id)
{
    weakref_impl* const impl = static_cast<weakref_impl*>(this);
    impl->addWeakRef(id);
    const int32_t c __attribute__((unused)) = impl->mWeak.fetch_add(1, std::memory_order_relaxed);
    ALOG_ASSERT(c >= 0, "incWeak called on %p after last weak ref", this);
}

void RefBase::weakref_type::decWeak(const void* id)
{
    weakref_impl* const impl = static_cast<weakref_impl*>(this);
    impl->removeWeakRef(id);
    const int32_t c = impl->mWeak.fetch_sub(1, std::memory_order_release);

    ALOG_ASSERT(c >= 1, "decWeak called on %p too many times", this);

    if (c != 1) return;

    // Last weak reference going away.
    std::atomic_thread_fence(std::memory_order_acquire);

    int32_t flags = impl->mFlags.load(std::memory_order_relaxed);

    if ((flags & OBJECT_LIFETIME_MASK) == OBJECT_LIFETIME_WEAK) {
        // The object survives strong reference count reaching 0.
        // We must now delete the object itself since all references
        // (strong and weak) are gone.
        if (impl->mStrong.load(std::memory_order_relaxed) == INITIAL_STRONG_VALUE) {
            // The object never had a strong reference. Delete it directly.
            delete impl->mBase;
        } else {
            // The object had strong references at some point, but they're
            // all gone. Since OBJECT_LIFETIME_WEAK, it hasn't been deleted yet.
            // onLastWeakRef is called, then we delete it.
            impl->mBase->onLastWeakRef(id);
            delete impl->mBase;
        }
    } else {
        // OBJECT_LIFETIME_STRONG: the object was already deleted by decStrong.
        // We just need to clean up the weakref_impl.
    }
    // Delete the weakref_impl itself (this is safe because 'this' is
    // the weakref_impl and we're in the last reference to it)
    delete impl;
}

bool RefBase::weakref_type::attemptIncStrong(const void* id)
{
    incWeak(id);

    weakref_impl* const impl = static_cast<weakref_impl*>(this);
    int32_t curCount = impl->mStrong.load(std::memory_order_relaxed);

    ALOG_ASSERT(curCount >= 0, "attemptIncStrong called on %p after underflow", this);

    // Attempt to CAS-increment mStrong.
    // We loop because multiple threads may be trying simultaneously.
    while (curCount > 0 && curCount != INITIAL_STRONG_VALUE) {
        // We're in the normal range: there are existing strong refs.
        // Just try to add one more.
        if (impl->mStrong.compare_exchange_weak(curCount, curCount + 1,
                std::memory_order_relaxed)) {
            break; // Successfully incremented.
        }
        // CAS failed, curCount was reloaded. Retry.
    }

    if (curCount <= 0) {
        // The object's strong count has dropped to zero (or below).
        // Under OBJECT_LIFETIME_STRONG, the object has been deleted.
        // Under OBJECT_LIFETIME_WEAK, it may still be alive.
        int32_t flags = impl->mFlags.load(std::memory_order_relaxed);
        if ((flags & OBJECT_LIFETIME_MASK) == OBJECT_LIFETIME_STRONG) {
            // Object was deleted by decStrong. Can't resurrect it.
            decWeak(id);
            return false;
        }

        // OBJECT_LIFETIME_WEAK: attempt resurrection
        bool allow = impl->mBase->onIncStrongAttempted(FIRST_INC_STRONG, id);
        if (!allow) {
            decWeak(id);
            return false;
        }

        // The subclass said it's OK to resurrect. Attempt to CAS from
        // curCount (which is 0 or negative) to curCount + 1.
        curCount = impl->mStrong.fetch_add(1, std::memory_order_relaxed);

        // If curCount was 0 and we succeeded, we now have a valid strong ref.
        // If it was negative, something went very wrong.
        if (curCount > 0) {
            // Someone else got there first (already resurrected).
            // Our fetch_add still succeeded, so we have a valid ref.
        }
    } else if (curCount == INITIAL_STRONG_VALUE) {
        // The object has never had a strong reference.
        // We must ask the base class if it's OK to become the first.
        bool allow = impl->mBase->onIncStrongAttempted(FIRST_INC_STRONG, id);
        if (!allow) {
            decWeak(id);
            return false;
        }

        // Try to take the first strong reference.
        curCount = impl->mStrong.fetch_add(1, std::memory_order_relaxed);

        if (curCount == INITIAL_STRONG_VALUE) {
            // We successfully took the first strong ref.
            // Adjust from the sentinel value.
            impl->mStrong.fetch_sub(INITIAL_STRONG_VALUE, std::memory_order_relaxed);
            // Call onFirstRef outside the loop to avoid re-entry.
            // (In AOSP, onFirstRef is called here too, but the incStrong()
            // path also calls it. We handle it consistently.)
            impl->mBase->onFirstRef();
        } else {
            // Someone else got here first and already took the first
            // strong ref and adjusted the sentinel. Our fetch_add still
            // gave us a valid ref. onFirstRef was already called by the
            // winner. We just keep our ref.
            // curCount was INITIAL_STRONG_VALUE + 1, so we need to subtract
            // the sentinel. But the winner already subtracted it, so we
            // currently have an extra INITIAL_STRONG_VALUE in the count.
            // Actually, no: the winner did: fetch_add(1) then fetch_sub(INITIAL_STRONG_VALUE).
            // The net is: INITIAL_STRONG_VALUE + 1 - INITIAL_STRONG_VALUE = 1.
            // Our fetch_add(1) gives: 2.
            // This is correct: we have 2 strong refs (winner + us).
        }
    }

    return true;
}

bool RefBase::weakref_type::attemptIncWeak(const void* /*id*/)
{
    weakref_impl* const impl = static_cast<weakref_impl*>(this);
    int32_t curCount = impl->mWeak.load(std::memory_order_relaxed);

    // If mWeak is 0, the object is being destroyed and we can't take a ref.
    // If mWeak > 0, we can try to increment.
    while (curCount > 0) {
        if (impl->mWeak.compare_exchange_weak(curCount, curCount + 1,
                std::memory_order_relaxed)) {
            return true;
        }
    }
    return false;
}

int32_t RefBase::weakref_type::getWeakCount() const
{
    return static_cast<const weakref_impl*>(this)->mWeak.load(std::memory_order_relaxed);
}

void RefBase::weakref_type::printRefs() const
{
    static_cast<const weakref_impl*>(this)->printRefs();
}

void RefBase::weakref_type::trackMe(bool enable, bool retain)
{
    static_cast<weakref_impl*>(this)->trackMe(enable, retain);
}

// ---------------------------------------------------------------------------

}; // namespace android
