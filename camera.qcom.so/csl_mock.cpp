#include "camxcsl.h"
#include "camxcsljumptable.h"
#include "camxincs.h"

#include <atomic>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <vector>
#include <sys/mman.h>

static std::atomic<INT32> g_nextSession{1};
static std::atomic<INT32> g_nextDevice{100};
static std::atomic<INT32> g_nextLink{200};
static std::atomic<INT32> g_nextMem{300};
static std::atomic<INT32> g_nextFence{1};

struct MockBuffer
{
    VOID*   pVirtualAddr;
    SIZE_T  size;
    INT     fd;
    UINT32  flags;
};

struct MockFence
{
    std::mutex              mtx;
    std::condition_variable cv;
    CSLFenceResult          result;
    bool                    signaled;
    struct AsyncWaiter { CSLFenceHandler handler; VOID* pUserData; };
    std::vector<AsyncWaiter> asyncWaiters;
};

static std::mutex g_bufferMtx;
static std::unordered_map<INT32, MockBuffer> g_buffers;

static std::mutex g_fenceMtx;
static std::unordered_map<INT32, MockFence*> g_fences;

// ── Session ──

static CamxResult MockCSLInitialize(void)
{
    return CamxResultSuccess;
}

static CamxResult MockCSLUninitialize(void)
{
    return CamxResultSuccess;
}

static CamxResult MockCSLOpen(CSLHandle* phCSL)
{
    if (phCSL == NULL) return CamxResultEInvalidArg;
    *phCSL = g_nextSession.fetch_add(1);
    return CamxResultSuccess;
}

static CamxResult MockCSLClose(CSLHandle hCSL)
{
    CAMX_UNREFERENCED_PARAM(hCSL);
    return CamxResultSuccess;
}

static CamxResult MockCSLAddReference(CSLHandle hCSL)
{
    CAMX_UNREFERENCED_PARAM(hCSL);
    return CamxResultSuccess;
}

// ── Platform ──

static CamxResult MockCSLQueryCameraPlatform(CSLCameraPlatform* pPlatform)
{
    if (pPlatform == NULL) return CamxResultEInvalidArg;
    memset(pPlatform, 0, sizeof(*pPlatform));
    pPlatform->family                    = CSLCameraFamilyTitan;
    pPlatform->platformVersion.majorVersion = 1;
    pPlatform->platformVersion.minorVersion = 7;
    pPlatform->platformVersion.revVersion   = 0;
    pPlatform->CPASVersion.majorVersion     = 1;
    pPlatform->CPASVersion.minorVersion     = 0;
    pPlatform->socId                     = CSLCameraTitanSocSM7150;
    return CamxResultSuccess;
}

// ── Device ──

static CamxResult MockCSLImageSensorProbe(CSLMemHandle hPacket, SIZE_T offset, CSLImageSensorProbeResult* pResult)
{
    CAMX_UNREFERENCED_PARAM(hPacket);
    CAMX_UNREFERENCED_PARAM(offset);
    if (pResult == NULL) return CamxResultEInvalidArg;
    pResult->detected    = FALSE;
    pResult->deviceIndex = -1;
    return CamxResultSuccess;
}

static CamxResult MockCSLSetDebugBuffer(CSLHandle h, CSLDebugBufferType t, CSLMemHandle hb, SIZE_T o, SIZE_T l, CSLDebugBufferResult* r)
{
    CAMX_UNREFERENCED_PARAM(h); CAMX_UNREFERENCED_PARAM(t); CAMX_UNREFERENCED_PARAM(hb);
    CAMX_UNREFERENCED_PARAM(o); CAMX_UNREFERENCED_PARAM(l);
    if (r != NULL) memset(r, 0, sizeof(*r));
    return CamxResultSuccess;
}

static CamxResult MockCSLEnumerateDevices(CSLDeviceDescriptor* pDesc)
{
    CAMX_UNREFERENCED_PARAM(pDesc);
    return CamxResultENoMore;
}

static CamxResult MockCSLQueryDeviceCapabilities(INT32 deviceIndex, VOID* pData, SIZE_T dataSize)
{
    CAMX_UNREFERENCED_PARAM(deviceIndex);
    if (pData != NULL) memset(pData, 0, dataSize);
    return CamxResultSuccess;
}

static CamxResult MockCSLAcquireDevice(CSLHandle hCSL, CSLDeviceHandle* phDevice, INT32 deviceIndex,
    CSLDeviceResource* pRes, SIZE_T numRes, CSLDeviceAttribute* pAttr, SIZE_T numAttr, const CHAR* pName)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(deviceIndex);
    CAMX_UNREFERENCED_PARAM(pRes); CAMX_UNREFERENCED_PARAM(numRes);
    CAMX_UNREFERENCED_PARAM(pAttr); CAMX_UNREFERENCED_PARAM(numAttr);
    CAMX_UNREFERENCED_PARAM(pName);
    if (phDevice == NULL) return CamxResultEInvalidArg;
    *phDevice = g_nextDevice.fetch_add(1);
    return CamxResultSuccess;
}

static CamxResult MockCSLReleaseDevice(CSLHandle hCSL, CSLDeviceHandle hDevice)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hDevice);
    return CamxResultSuccess;
}

// ── Link / Stream ──

static CamxResult MockCSLLink(CSLHandle hCSL, CSLDeviceHandle* phDevices, UINT count, CSLLinkHandle* phLink)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(phDevices); CAMX_UNREFERENCED_PARAM(count);
    if (phLink == NULL) return CamxResultEInvalidArg;
    *phLink = g_nextLink.fetch_add(1);
    return CamxResultSuccess;
}

static CamxResult MockCSLUnlink(CSLHandle hCSL, CSLLinkHandle* phLink)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(phLink);
    return CamxResultSuccess;
}

static CamxResult MockCSLSyncLinks(CSLHandle hCSL, CSLLinkHandle* phLink, UINT count, CSLLinkHandle hMaster, CSLSyncLinkMode mode)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(phLink); CAMX_UNREFERENCED_PARAM(count);
    CAMX_UNREFERENCED_PARAM(hMaster); CAMX_UNREFERENCED_PARAM(mode);
    return CamxResultSuccess;
}

static CamxResult MockCSLOpenRequest(CSLHandle hCSL, CSLLinkHandle hLink, UINT64 requestId, BOOL bubble, CSLSyncLinkMode syncMode, UINT32 exposureMs)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hLink); CAMX_UNREFERENCED_PARAM(requestId);
    CAMX_UNREFERENCED_PARAM(bubble); CAMX_UNREFERENCED_PARAM(syncMode); CAMX_UNREFERENCED_PARAM(exposureMs);
    return CamxResultSuccess;
}

static CamxResult MockCSLCancelRequest(CSLHandle hCSL, const CSLFlushInfo& info)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(info);
    return CamxResultSuccess;
}

static CamxResult MockCSLStreamOn(CSLHandle hCSL, CSLLinkHandle* phLink, CSLDeviceHandle* phDevices)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(phLink); CAMX_UNREFERENCED_PARAM(phDevices);
    return CamxResultSuccess;
}

static CamxResult MockCSLStreamOff(CSLHandle hCSL, CSLLinkHandle* phLink, CSLDeviceHandle* phDevices, CSLDeactivateMode mode)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(phLink); CAMX_UNREFERENCED_PARAM(phDevices);
    CAMX_UNREFERENCED_PARAM(mode);
    return CamxResultSuccess;
}

static CamxResult MockCSLSingleDeviceStreamOn(CSLHandle hCSL, INT32 deviceIndex, CSLDeviceHandle* phDevice)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(deviceIndex); CAMX_UNREFERENCED_PARAM(phDevice);
    return CamxResultSuccess;
}

static CamxResult MockCSLSingleDeviceStreamOff(CSLHandle hCSL, INT32 deviceIndex, CSLDeviceHandle* phDevice)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(deviceIndex); CAMX_UNREFERENCED_PARAM(phDevice);
    return CamxResultSuccess;
}

// ── Submit ──

static CamxResult MockCSLSubmit(CSLHandle hCSL, CSLDeviceHandle hDevice, CSLMemHandle hPacket, SIZE_T offset)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hDevice);
    CAMX_UNREFERENCED_PARAM(hPacket); CAMX_UNREFERENCED_PARAM(offset);
    return CamxResultSuccess;
}

static CamxResult MockCSLFlushLock(CSLHandle hCSL, const CSLFlushInfo& info)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(info);
    return CamxResultSuccess;
}

static CamxResult MockCSLFlushUnlock(CSLHandle hCSL)
{
    CAMX_UNREFERENCED_PARAM(hCSL);
    return CamxResultSuccess;
}

// ── Message Handler ──

static CamxResult MockCSLRegisterMessageHandler(CSLHandle hCSL, CSLLinkHandle hLink, CSLMessageHandler handler, VOID* pUserData)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hLink);
    CAMX_UNREFERENCED_PARAM(handler); CAMX_UNREFERENCED_PARAM(pUserData);
    return CamxResultSuccess;
}

// ── Buffer Management ──

static CamxResult MockCSLAlloc(const CHAR* pStr, CSLBufferInfo* pInfo, SIZE_T size, SIZE_T alignment,
    UINT32 flags, const INT32* pDeviceIndices, UINT deviceCount)
{
    CAMX_UNREFERENCED_PARAM(pStr); CAMX_UNREFERENCED_PARAM(alignment);
    CAMX_UNREFERENCED_PARAM(flags); CAMX_UNREFERENCED_PARAM(pDeviceIndices);
    CAMX_UNREFERENCED_PARAM(deviceCount);
    if (pInfo == NULL || size == 0) return CamxResultEInvalidArg;

    VOID* pAddr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (pAddr == MAP_FAILED) return CamxResultENoMemory;

    INT32 handle = g_nextMem.fetch_add(1);
    memset(pInfo, 0, sizeof(*pInfo));
    pInfo->hHandle      = handle;
    pInfo->pVirtualAddr  = pAddr;
    pInfo->fd            = -1;
    pInfo->size          = size;
    pInfo->flags         = flags;

    std::lock_guard<std::mutex> lock(g_bufferMtx);
    g_buffers[handle] = {pAddr, size, -1, flags};
    return CamxResultSuccess;
}

static CamxResult MockCSLMapBuffer(CSLBufferInfo* pInfo, INT bufferFD, SIZE_T offset, SIZE_T length,
    UINT32 flags, const INT32* pDeviceIndices, UINT deviceCount)
{
    CAMX_UNREFERENCED_PARAM(bufferFD); CAMX_UNREFERENCED_PARAM(offset);
    CAMX_UNREFERENCED_PARAM(flags); CAMX_UNREFERENCED_PARAM(pDeviceIndices);
    CAMX_UNREFERENCED_PARAM(deviceCount);
    if (pInfo == NULL) return CamxResultEInvalidArg;

    VOID* pAddr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (pAddr == MAP_FAILED) return CamxResultENoMemory;

    INT32 handle = g_nextMem.fetch_add(1);
    memset(pInfo, 0, sizeof(*pInfo));
    pInfo->hHandle      = handle;
    pInfo->pVirtualAddr  = pAddr;
    pInfo->fd            = bufferFD;
    pInfo->offset        = offset;
    pInfo->size          = length;
    pInfo->flags         = flags;

    std::lock_guard<std::mutex> lock(g_bufferMtx);
    g_buffers[handle] = {pAddr, length, bufferFD, flags};
    return CamxResultSuccess;
}

static CamxResult MockCSLMapNativeBuffer(CSLBufferInfo* pInfo, const CSLNativeHandle* phNative,
    SIZE_T offset, SIZE_T length, UINT32 flags, const INT32* pDeviceIndices, UINT deviceCount)
{
    CAMX_UNREFERENCED_PARAM(phNative);
    return MockCSLMapBuffer(pInfo, -1, offset, length, flags, pDeviceIndices, deviceCount);
}

static CamxResult MockCSLGetBufferInfo(CSLMemHandle hBuffer, CSLBufferInfo* pInfo)
{
    if (pInfo == NULL) return CamxResultEInvalidArg;
    std::lock_guard<std::mutex> lock(g_bufferMtx);
    auto it = g_buffers.find(hBuffer);
    if (it == g_buffers.end()) return CamxResultEInvalidArg;
    memset(pInfo, 0, sizeof(*pInfo));
    pInfo->hHandle      = hBuffer;
    pInfo->pVirtualAddr  = it->second.pVirtualAddr;
    pInfo->size          = it->second.size;
    pInfo->fd            = it->second.fd;
    pInfo->flags         = it->second.flags;
    return CamxResultSuccess;
}

static CamxResult MockCSLBufferCacheOp(CSLMemHandle hBuffer, BOOL invalidate, BOOL clean)
{
    CAMX_UNREFERENCED_PARAM(hBuffer); CAMX_UNREFERENCED_PARAM(invalidate); CAMX_UNREFERENCED_PARAM(clean);
    return CamxResultSuccess;
}

static CamxResult MockCSLReleaseBuffer(CSLMemHandle hBuffer)
{
    std::lock_guard<std::mutex> lock(g_bufferMtx);
    auto it = g_buffers.find(hBuffer);
    if (it == g_buffers.end()) return CamxResultSuccess;
    if (it->second.pVirtualAddr != NULL)
        munmap(it->second.pVirtualAddr, it->second.size);
    g_buffers.erase(it);
    return CamxResultSuccess;
}

static CamxResult MockCSLReleaseBufferForced(CSLMemHandle hBuffer)
{
    return MockCSLReleaseBuffer(hBuffer);
}

// ── Fence Management ──

static CamxResult MockCSLCreatePrivateFence(const CHAR* pName, CSLFence* pFenceOut)
{
    CAMX_UNREFERENCED_PARAM(pName);
    if (pFenceOut == NULL) return CamxResultEInvalidArg;

    MockFence* pFence = new MockFence();
    pFence->signaled = false;
    pFence->result   = CSLFenceResultSuccess;

    INT32 fenceId = g_nextFence.fetch_add(1);
    {
        std::lock_guard<std::mutex> lock(g_fenceMtx);
        g_fences[fenceId] = pFence;
    }
    *pFenceOut = fenceId;
    return CamxResultSuccess;
}

static CamxResult MockCSLCreateNativeFence(CSLNativeFenceCreateDataPtr pData, CSLFence* pFenceOut)
{
    CAMX_UNREFERENCED_PARAM(pData);
    return MockCSLCreatePrivateFence("native", pFenceOut);
}

static CamxResult MockCSLMergeFences(CSLFence* phFences, SIZE_T count, CSLFence* pFenceOut)
{
    CAMX_UNREFERENCED_PARAM(phFences); CAMX_UNREFERENCED_PARAM(count);
    return MockCSLCreatePrivateFence("merged", pFenceOut);
}

static CamxResult MockCSLGetFenceAttrib(CSLFence hFence, UINT32 attrib, VOID* pVal, UINT32 valSize)
{
    CAMX_UNREFERENCED_PARAM(hFence); CAMX_UNREFERENCED_PARAM(attrib);
    if (pVal != NULL) memset(pVal, 0, valSize);
    return CamxResultSuccess;
}

static CamxResult MockCSLFenceWait(CSLFence hFence, UINT64 timeout)
{
    MockFence* pFence = NULL;
    {
        std::lock_guard<std::mutex> lock(g_fenceMtx);
        auto it = g_fences.find(hFence);
        if (it == g_fences.end()) return CamxResultEInvalidArg;
        pFence = it->second;
    }

    std::unique_lock<std::mutex> lock(pFence->mtx);
    if (pFence->signaled) return CamxResultSuccess;

    if (timeout == 0)
        return CamxResultETimeout;

    auto timeoutMs = std::chrono::milliseconds(timeout);
    if (pFence->cv.wait_for(lock, timeoutMs, [&]{ return pFence->signaled; }))
        return CamxResultSuccess;

    return CamxResultETimeout;
}

static CamxResult MockCSLFenceWaitMultiple(CSLFence* phFences, BOOL* pSignaled, SIZE_T count, UINT64 timeout)
{
    for (SIZE_T i = 0; i < count; i++)
    {
        CamxResult result = MockCSLFenceWait(phFences[i], timeout);
        if (pSignaled != NULL)
            pSignaled[i] = (result == CamxResultSuccess);
    }
    return CamxResultSuccess;
}

static CamxResult MockCSLFenceAsyncWait(CSLFence hFence, CSLFenceHandler handler, VOID* pUserData)
{
    MockFence* pFence = NULL;
    {
        std::lock_guard<std::mutex> lock(g_fenceMtx);
        auto it = g_fences.find(hFence);
        if (it == g_fences.end()) return CamxResultEInvalidArg;
        pFence = it->second;
    }

    std::lock_guard<std::mutex> lock(pFence->mtx);
    if (pFence->signaled)
    {
        handler(pUserData, hFence, pFence->result);
        return CamxResultSuccess;
    }
    pFence->asyncWaiters.push_back({handler, pUserData});
    return CamxResultSuccess;
}

static CamxResult MockCSLFenceAsyncCancel(CSLFence hFence, CSLFenceHandler handler, VOID* pUserData)
{
    MockFence* pFence = NULL;
    {
        std::lock_guard<std::mutex> lock(g_fenceMtx);
        auto it = g_fences.find(hFence);
        if (it == g_fences.end()) return CamxResultSuccess;
        pFence = it->second;
    }

    std::lock_guard<std::mutex> lock(pFence->mtx);
    auto& waiters = pFence->asyncWaiters;
    waiters.erase(
        std::remove_if(waiters.begin(), waiters.end(),
            [&](const MockFence::AsyncWaiter& w) { return w.handler == handler && w.pUserData == pUserData; }),
        waiters.end());
    return CamxResultSuccess;
}

static CamxResult MockCSLFenceSignal(CSLFence hFence, CSLFenceResult status)
{
    MockFence* pFence = NULL;
    {
        std::lock_guard<std::mutex> lock(g_fenceMtx);
        auto it = g_fences.find(hFence);
        if (it == g_fences.end()) return CamxResultEInvalidArg;
        pFence = it->second;
    }

    std::vector<MockFence::AsyncWaiter> waitersToCall;
    {
        std::lock_guard<std::mutex> lock(pFence->mtx);
        pFence->signaled = true;
        pFence->result   = status;
        waitersToCall.swap(pFence->asyncWaiters);
    }
    pFence->cv.notify_all();

    for (auto& w : waitersToCall)
        w.handler(w.pUserData, hFence, status);

    return CamxResultSuccess;
}

static CamxResult MockCSLReleaseFence(CSLFence hFence)
{
    std::lock_guard<std::mutex> lock(g_fenceMtx);
    auto it = g_fences.find(hFence);
    if (it == g_fences.end()) return CamxResultSuccess;
    delete it->second;
    g_fences.erase(it);
    return CamxResultSuccess;
}

// ── Hardware ──

static CamxResult MockCSLAcquireHardware(CSLHandle hCSL, CSLDeviceHandle hDevice, CSLDeviceResource* pRes, UINT32 version)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hDevice);
    CAMX_UNREFERENCED_PARAM(pRes); CAMX_UNREFERENCED_PARAM(version);
    return CamxResultSuccess;
}

static CamxResult MockCSLReleaseHardware(CSLHandle hCSL, CSLDeviceHandle hDevice)
{
    CAMX_UNREFERENCED_PARAM(hCSL); CAMX_UNREFERENCED_PARAM(hDevice);
    return CamxResultSuccess;
}

// ── Jump Table Population ──

static CSLJumpTable g_mockCSLJumpTable = {};

static void EnsureMockJumpTable()
{
    static bool initialized = false;
    if (initialized) return;
    initialized = true;

    g_mockCSLJumpTable.CSLInitialize            = MockCSLInitialize;
    g_mockCSLJumpTable.CSLUninitialize          = MockCSLUninitialize;
    g_mockCSLJumpTable.CSLOpen                  = MockCSLOpen;
    g_mockCSLJumpTable.CSLClose                 = MockCSLClose;
    g_mockCSLJumpTable.CSLAddReference          = MockCSLAddReference;
    g_mockCSLJumpTable.CSLQueryCameraPlatform   = MockCSLQueryCameraPlatform;
    g_mockCSLJumpTable.CSLImageSensorProbe      = MockCSLImageSensorProbe;
    g_mockCSLJumpTable.CSLSetDebugBuffer        = MockCSLSetDebugBuffer;
    g_mockCSLJumpTable.CSLEnumerateDevices      = MockCSLEnumerateDevices;
    g_mockCSLJumpTable.CSLQueryDeviceCapabilities = MockCSLQueryDeviceCapabilities;
    g_mockCSLJumpTable.CSLAcquireDevice         = MockCSLAcquireDevice;
    g_mockCSLJumpTable.CSLReleaseDevice         = MockCSLReleaseDevice;
    g_mockCSLJumpTable.CSLLink                  = MockCSLLink;
    g_mockCSLJumpTable.CSLUnlink                = MockCSLUnlink;
    g_mockCSLJumpTable.CSLSyncLinks             = MockCSLSyncLinks;
    g_mockCSLJumpTable.CSLOpenRequest           = MockCSLOpenRequest;
    g_mockCSLJumpTable.CSLCancelRequest         = MockCSLCancelRequest;
    g_mockCSLJumpTable.CSLStreamOn              = MockCSLStreamOn;
    g_mockCSLJumpTable.CSLStreamOff             = MockCSLStreamOff;
    g_mockCSLJumpTable.CSLSingleDeviceStreamOn  = MockCSLSingleDeviceStreamOn;
    g_mockCSLJumpTable.CSLSingleDeviceStreamOff = MockCSLSingleDeviceStreamOff;
    g_mockCSLJumpTable.CSLSubmit                = MockCSLSubmit;
    g_mockCSLJumpTable.CSLFlushLock             = MockCSLFlushLock;
    g_mockCSLJumpTable.CSLFlushUnlock           = MockCSLFlushUnlock;
    g_mockCSLJumpTable.CSLRegisterMessageHandler = MockCSLRegisterMessageHandler;
    g_mockCSLJumpTable.CSLAlloc                 = MockCSLAlloc;
    g_mockCSLJumpTable.CSLMapBuffer             = MockCSLMapBuffer;
    g_mockCSLJumpTable.CSLMapNativeBuffer        = MockCSLMapNativeBuffer;
    g_mockCSLJumpTable.CSLGetBufferInfo          = MockCSLGetBufferInfo;
    g_mockCSLJumpTable.CSLBufferCacheOp          = MockCSLBufferCacheOp;
    g_mockCSLJumpTable.CSLReleaseBuffer          = MockCSLReleaseBuffer;
    g_mockCSLJumpTable.CSLReleaseBufferForced    = MockCSLReleaseBufferForced;
    g_mockCSLJumpTable.CSLCreatePrivateFence     = MockCSLCreatePrivateFence;
    g_mockCSLJumpTable.CSLCreateNativeFence      = MockCSLCreateNativeFence;
    g_mockCSLJumpTable.CSLMergeFences            = MockCSLMergeFences;
    g_mockCSLJumpTable.CSLGetFenceAttrib         = MockCSLGetFenceAttrib;
    g_mockCSLJumpTable.CSLFenceWait              = MockCSLFenceWait;
    g_mockCSLJumpTable.CSLFenceWaitMultiple      = MockCSLFenceWaitMultiple;
    g_mockCSLJumpTable.CSLFenceAsyncWait         = MockCSLFenceAsyncWait;
    g_mockCSLJumpTable.CSLFenceAsyncCancel       = MockCSLFenceAsyncCancel;
    g_mockCSLJumpTable.CSLFenceSignal            = MockCSLFenceSignal;
    g_mockCSLJumpTable.CSLReleaseFence           = MockCSLReleaseFence;
    g_mockCSLJumpTable.CSLAcquireHardware        = MockCSLAcquireHardware;
    g_mockCSLJumpTable.CSLReleaseHardware        = MockCSLReleaseHardware;
}

CSLJumpTable* GetCSLJumpTableHw(void)
{
    EnsureMockJumpTable();
    return &g_mockCSLJumpTable;
}

CSLJumpTable* GetCSLJumpTableIFH(void)
{
    EnsureMockJumpTable();
    return &g_mockCSLJumpTable;
}
