#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <mutex>

// CAMX types
#include "camxcdktypes.h"
#include "chi.h"

// Android system headers (stubs needed for HMI / camera_module_t)
#include <hardware/camera_common.h>
#include <system/camera_vendor_tags.h>

// CamX adapter (C-linkage wrappers in camx_runtime_stubs.cpp)
extern "C" void* CamXAdapter_InitContext();
extern "C" void  CamXAdapter_DestroyContext();
extern "C" void* CamXAdapter_CreateSession(unsigned int numPipelines, void* pPipelineInfo,
    void* pCallbacks, void* pPrivateCallbackData, void* pFlags);
extern "C" int   CamXAdapter_ActivatePipeline(void* pSession, void* hPipelineDescriptor);
extern "C" int   CamXAdapter_SubmitRequest(void* pSession, void* pRequest);
extern "C" void* CamXAdapter_CreatePipelineDescriptor(const char* pPipelineName, void* pDescriptor,
    unsigned int numOutputs, void* pOutputBufferDescriptors,
    unsigned int numInputs, void* pInputBufferOptions);
extern "C" void  CamXAdapter_DestroySession(void* pSession);

// =======================================================================
// Internal state structures
// =======================================================================

static bool g_usingRealCamX = false;

// Our internal context handle
struct StubContext {
    bool initialized = false;
    CHITAGSOPS tagOps;
    CHIFENCEOPS fenceOps;
    CHIMETADATAOPS metadataOps;
    CHIBUFFERMANAGEROPS bufferManagerOps;
};

// A session handle
struct StubSession {
    CHICALLBACKS callbacks;
    void* pPrivateCallbackData;
    bool active = false;
};

// A pipeline descriptor handle
struct StubPipelineDescriptor {
    int cameraId;
    bool isRealTime;
};

// A pipeline handle
struct StubPipeline {
    StubPipelineDescriptor* pDescriptor;
    bool activated = false;
};

// Image buffer handle
struct StubImageBuffer {
    size_t size;
    void* data;
    int refCount;
};

// Buffer manager handle
struct StubBufferManager {
    CHIBufferManagerCreateData createData;
    std::vector<StubImageBuffer*> buffers;
    bool active = false;
};

// Metadata handle - simple tag map
struct StubMetadata {
    std::map<uint32_t, std::pair<std::vector<uint8_t>, uint32_t>> tags; // tag -> (data, count)
    CHIMETAPRIVATEDATA pPrivateData = nullptr;
    int refCount = 1;
};

// Fence handle
struct StubFence {
    CDKResult status = CDKResultEInvalidState;
};

// Global state
static StubContext g_context;
static std::vector<StubSession*> g_sessions;
static std::vector<StubPipelineDescriptor*> g_pipelineDescriptors;
static std::vector<StubPipeline*> g_pipelines;
static std::vector<StubBufferManager*> g_bufferManagers;
static std::vector<StubMetadata*> g_metadatas;
static std::vector<StubFence*> g_fences;
static std::mutex g_mutex;

// =======================================================================
// Hardcoded fake camera data
// =======================================================================

static const int FAKE_NUM_CAMERAS = 1;
static const int FAKE_NUM_SENSOR_MODES = 3;

static StubMetadata* g_cameraMeta[1] = { nullptr };

// =======================================================================
// Helper: get stub context / session
// =======================================================================
static StubContext* GetCtx(CHIHANDLE h) {
    (void)h;
    return &g_context;
}

static StubSession* GetSession(CHIHANDLE h) {
    if (!h) return nullptr;
    return reinterpret_cast<StubSession*>(h);
}

// =======================================================================
// Helper: create fake camera info
// =======================================================================
// =======================================================================
// Helper: create fake camera info
// =======================================================================

// Pre-built static metadata buffer for camera 0
static uint8_t* g_pStaticMetaBuf = nullptr;
static bool g_staticMetaReady = false;

static void BuildStaticMetadata() {
    if (g_staticMetaReady) return;
    g_staticMetaReady = true;

    size_t buffer_size = calculate_camera_metadata_size(16, 256);
    g_pStaticMetaBuf = new uint8_t[buffer_size]();

    camera_metadata_t* meta = place_camera_metadata(g_pStaticMetaBuf, buffer_size, 16, 256);
    if (!meta) return;

    int32_t pixel_array[2] = {5344, 4016};
    add_camera_metadata_entry_raw(meta, ANDROID_SENSOR_INFO_PIXEL_ARRAY_SIZE, TYPE_INT32, pixel_array, 2);

    int32_t active_array[4] = {0, 0, 5344, 4016};
    add_camera_metadata_entry_raw(meta, ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE, TYPE_INT32, active_array, 4);

    int32_t orientation = 0;
    add_camera_metadata_entry_raw(meta, ANDROID_SENSOR_ORIENTATION, TYPE_INT32, &orientation, 1);
}

static void FillFakeCameraInfo(CHICAMERAINFO* pInfo) {
    VOID* pLegacy = pInfo->pLegacy;  // preserve pLegacy set by caller
    memset(pInfo, 0, sizeof(CHICAMERAINFO));
    pInfo->pLegacy = pLegacy;
    pInfo->size = sizeof(CHICAMERAINFO);
    pInfo->numSensorModes = FAKE_NUM_SENSOR_MODES;
    pInfo->sensorCaps.size = sizeof(CHISENSORCAPS);
    pInfo->sensorCaps.facing = FacingBack;
    pInfo->sensorCaps.positionType = REAR;
    pInfo->sensorCaps.activeArray.left = 0;
    pInfo->sensorCaps.activeArray.top = 0;
    pInfo->sensorCaps.activeArray.width = 5344;
    pInfo->sensorCaps.activeArray.height = 4016;
    pInfo->sensorCaps.pixelSize = 1.0f;
    pInfo->lensCaps.size = sizeof(CHILENSCAPS);
    pInfo->lensCaps.focalLength = 4.5f;
    pInfo->lensCaps.isFixedFocus = false;
    pInfo->lensCaps.horViewAngle = 70.0f;

    // Set up static metadata on the pLegacy camera_info
    if (pLegacy) {
        BuildStaticMetadata();
        camera_info* info = (camera_info*)pLegacy;
        info->facing = CAMERA_FACING_BACK;
        info->orientation = 0;
        info->static_camera_characteristics = (camera_metadata_t*)g_pStaticMetaBuf;
    }
}

static void FillFakeSensorMode(CHISENSORMODEINFO* pMode, int index) {
    memset(pMode, 0, sizeof(CHISENSORMODEINFO));
    pMode->size = sizeof(CHISENSORMODEINFO);
    pMode->modeIndex = index;
    pMode->bpp = 10;
    pMode->frameRate = 30;
    pMode->sensorModeCaps.u.Normal = 1;
    pMode->sensorModeCaps.u.PDAF = (index == 0) ? 1 : 0;
    pMode->streamtype = StreamImage;
    pMode->horizontalBinning = 1;
    pMode->verticalBinning = 1;

    switch (index) {
    case 0:
        pMode->frameDimension.width = 5344;
        pMode->frameDimension.height = 4016;
        pMode->aspectRatio.numerator = 4;
        pMode->aspectRatio.denominator = 3;
        pMode->cropInfo.width = 5344;
        pMode->cropInfo.height = 4016;
        break;
    case 1:
        pMode->frameDimension.width = 4608;
        pMode->frameDimension.height = 2592;
        pMode->aspectRatio.numerator = 16;
        pMode->aspectRatio.denominator = 9;
        pMode->cropInfo.width = 4608;
        pMode->cropInfo.height = 2592;
        break;
    case 2:
        pMode->frameDimension.width = 1920;
        pMode->frameDimension.height = 1080;
        pMode->aspectRatio.numerator = 16;
        pMode->aspectRatio.denominator = 9;
        pMode->cropInfo.width = 1920;
        pMode->cropInfo.height = 1080;
        break;
    }
}

// =======================================================================
// ChiOps Implementation: Context operations
// =======================================================================
static CHIHANDLE ChiOpenContext() {
    g_context.initialized = true;
    CamXAdapter_InitContext();
    return &g_context;
}

static VOID ChiCloseContext(CHIHANDLE hChiContext) {
    (void)hChiContext;
    g_context.initialized = false;
}

// =======================================================================
// ChiOps Implementation: Camera enumeration
// =======================================================================
static UINT ChiGetNumCameras(CHIHANDLE hChiContext) {
    (void)hChiContext;
    return FAKE_NUM_CAMERAS;
}

static CDKResult ChiGetCameraInfo(CHIHANDLE hChiContext, UINT32 cameraId, CHICAMERAINFO* pCameraInfo) {
    (void)hChiContext;
    if (cameraId >= FAKE_NUM_CAMERAS) return CDKResultEOutOfBounds;
    FillFakeCameraInfo(pCameraInfo);
    return CDKResultSuccess;
}

static CDKResult ChiEnumerateSensorModes(CHIHANDLE hChiContext, UINT32 cameraId,
                                          UINT32 numSensorModes, CHISENSORMODEINFO* pSensorModeInfo) {
    (void)hChiContext;
    if (cameraId >= FAKE_NUM_CAMERAS) return CDKResultEOutOfBounds;
    for (UINT32 i = 0; i < numSensorModes && i < FAKE_NUM_SENSOR_MODES; i++) {
        FillFakeSensorMode(&pSensorModeInfo[i], i);
    }
    return CDKResultSuccess;
}

// =======================================================================
// ChiOps Implementation: Pipeline descriptor
// =======================================================================
static CHIPIPELINEDESCRIPTOR ChiCreatePipelineDescriptor(
    CHIHANDLE hChiContext, const CHAR* pPipelineName,
    const CHIPIPELINECREATEDESCRIPTOR* pDescriptor,
    UINT32 numOutputs, CHIPORTBUFFERDESCRIPTOR* pOutputBufferDescriptors,
    UINT32 numInputs, CHIPIPELINEINPUTOPTIONS* pInputBufferOptions)
{
    (void)hChiContext;

    void* ctx = CamXAdapter_InitContext();
    if (ctx != NULL) {
        void* realDesc = CamXAdapter_CreatePipelineDescriptor(
            pPipelineName, (void*)pDescriptor,
            0, NULL,
            0, NULL);
        if (realDesc != NULL) {
            return reinterpret_cast<CHIPIPELINEDESCRIPTOR>(realDesc);
        }
        fprintf(stderr, "[chi_stub] Real CamX pipeline descriptor failed, falling back to stub\n");
    }

    StubPipelineDescriptor* desc = new StubPipelineDescriptor();
    desc->cameraId = pDescriptor ? pDescriptor->cameraId : 0;
    desc->isRealTime = pDescriptor ? pDescriptor->isRealTime : true;

    std::lock_guard<std::mutex> lock(g_mutex);
    g_pipelineDescriptors.push_back(desc);
    return reinterpret_cast<CHIPIPELINEDESCRIPTOR>(desc);
}

static VOID ChiDestroyPipelineDescriptor(CHIHANDLE hChiContext, CHIPIPELINEDESCRIPTOR hDesc) {
    (void)hChiContext;
    if (!hDesc) return;
    StubPipelineDescriptor* desc = reinterpret_cast<StubPipelineDescriptor*>(hDesc);
    std::lock_guard<std::mutex> lock(g_mutex);
    for (auto it = g_pipelineDescriptors.begin(); it != g_pipelineDescriptors.end(); ++it) {
        if (*it == desc) {
            g_pipelineDescriptors.erase(it);
            break;
        }
    }
    delete desc;
}

// =======================================================================
// ChiOps Implementation: Session operations
// =======================================================================
static CHIHANDLE ChiCreateSession(CHIHANDLE hChiContext, UINT numPipelines,
                                   CHIPIPELINEINFO* pPipelineInfo,
                                   CHICALLBACKS* pCallbacks,
                                   VOID* pPrivateCallbackData,
                                   CHISESSIONFLAGS flags) {
    (void)hChiContext;

    void* ctx = CamXAdapter_InitContext();
    if (ctx != NULL) {
        void* realSession = CamXAdapter_CreateSession(
            numPipelines, pPipelineInfo, pCallbacks, pPrivateCallbackData, &flags);
        if (realSession != NULL) {
            for (UINT i = 0; i < numPipelines; i++) {
                if (pPipelineInfo[i].hPipelineDescriptor != NULL) {
                    CamXAdapter_ActivatePipeline(realSession, pPipelineInfo[i].hPipelineDescriptor);
                }
            }
            g_usingRealCamX = true;
            return reinterpret_cast<CHIHANDLE>(realSession);
        }
        fprintf(stderr, "[chi_stub] Real CamX session failed, falling back to stub\n");
    }

    StubSession* session = new StubSession();
    if (pCallbacks) {
        session->callbacks = *pCallbacks;
    }
    session->pPrivateCallbackData = pPrivateCallbackData;

    std::lock_guard<std::mutex> lock(g_mutex);
    g_sessions.push_back(session);
    return reinterpret_cast<CHIHANDLE>(session);
}

static VOID ChiDestroySession(CHIHANDLE hChiContext, CHIHANDLE hSession, BOOL isForced) {
    (void)hChiContext; (void)isForced;
    if (!hSession) return;

    if (g_usingRealCamX) {
        CamXAdapter_DestroySession(hSession);
        return;
    }

    StubSession* session = reinterpret_cast<StubSession*>(hSession);
    std::lock_guard<std::mutex> lock(g_mutex);
    for (auto it = g_sessions.begin(); it != g_sessions.end(); ++it) {
        if (*it == session) {
            g_sessions.erase(it);
            break;
        }
    }
    delete session;
}

// =======================================================================
// ChiOps Implementation: Pipeline activate/deactivate
// =======================================================================
static CDKResult ChiActivatePipeline(CHIHANDLE hChiContext, CHIHANDLE hSession,
                                      CHIHANDLE hPipeline, CHISENSORMODEINFO* pSensorModeInfo) {
    (void)hChiContext; (void)hSession; (void)pSensorModeInfo;
    if (!hPipeline) return CDKResultEInvalidPointer;
    StubPipeline* pipeline = reinterpret_cast<StubPipeline*>(hPipeline);
    pipeline->activated = true;
    StubSession* session = reinterpret_cast<StubSession*>(hSession);
    if (session) session->active = true;
    return CDKResultSuccess;
}

static CDKResult ChiDeactivatePipeline(CHIHANDLE hChiContext, CHIHANDLE hSession,
                                        CHIHANDLE hPipeline, CHIDEACTIVATEPIPELINEMODE mode) {
    (void)hChiContext; (void)hSession; (void)mode;
    if (!hPipeline) return CDKResultEInvalidPointer;
    StubPipeline* pipeline = reinterpret_cast<StubPipeline*>(hPipeline);
    pipeline->activated = false;
    return CDKResultSuccess;
}

// =======================================================================
// ChiOps Implementation: Query pipeline metadata info
// =======================================================================
static CDKResult ChiQueryPipelineMetadataInfo(CHIHANDLE hChiContext, CHIHANDLE hSession,
                                               CHIPIPELINEDESCRIPTOR hDesc,
                                               CHIPIPELINEMETADATAINFO* pInfo) {
    (void)hChiContext; (void)hSession; (void)hDesc;
    if (!pInfo) return CDKResultEInvalidPointer;
    pInfo->maxNumMetaBuffers = 2;
    pInfo->publishTagCount = 0;
    pInfo->publishPartialTagCount = 0;
    return CDKResultSuccess;
}

// =======================================================================
// ChiOps Implementation: Flush session
// =======================================================================
static CDKResult ChiFlushSession(CHIHANDLE hChiContext, CHISESSIONFLUSHINFO hFlushInfo) {
    (void)hChiContext; (void)hFlushInfo;
    return CDKResultSuccess;
}

// =======================================================================
// ChiOps Implementation: Submit pipeline request (with callback)
// =======================================================================
static CDKResult ChiSubmitPipelineRequest(CHIHANDLE hChiContext, CHIPIPELINEREQUEST* pRequest) {
    (void)hChiContext;
    if (!pRequest) return CDKResultEInvalidPointer;

    if (g_usingRealCamX) {
        CHIHANDLE hSession = pRequest->pSessionHandle;
        return static_cast<CDKResult>(CamXAdapter_SubmitRequest(hSession, pRequest));
    }

    CHIHANDLE hSession = pRequest->pSessionHandle;
    StubSession* session = reinterpret_cast<StubSession*>(hSession);
    if (!session) return CDKResultEInvalidState;

    for (UINT32 reqIdx = 0; reqIdx < pRequest->numRequests; reqIdx++) {
        const CHICAPTUREREQUEST* pCapReq = &pRequest->pCaptureRequests[reqIdx];

        // Build output buffers
        CHISTREAMBUFFER* pOutputBufs = nullptr;
        if (pCapReq->numOutputs > 0) {
            pOutputBufs = new CHISTREAMBUFFER[pCapReq->numOutputs]();
            for (UINT32 i = 0; i < pCapReq->numOutputs; i++) {
                pOutputBufs[i] = pCapReq->pOutputBuffers[i];
                pOutputBufs[i].bufferStatus = 0; // OK
                pOutputBufs[i].acquireFence.valid = false;
                pOutputBufs[i].releaseFence.valid = false;
            }
        }

        // Build input buffer (return same buffer with OK status)
        CHISTREAMBUFFER* pInputBuf = nullptr;
        CHISTREAMBUFFER tmpInputBuf;
        if (pCapReq->numInputs > 0 && pCapReq->pInputBuffers) {
            tmpInputBuf = pCapReq->pInputBuffers[0];
            tmpInputBuf.bufferStatus = 0;
            tmpInputBuf.acquireFence.valid = false;
            tmpInputBuf.releaseFence.valid = false;
            pInputBuf = &tmpInputBuf;
        }

        CHICAPTURERESULT result;
        memset(&result, 0, sizeof(result));
        result.frameworkFrameNum = pCapReq->frameNumber & 0xFFFFFFFF;
        result.numOutputBuffers = pCapReq->numOutputs;
        result.pOutputBuffers = pOutputBufs;
        result.pInputBuffer = pInputBuf;
        result.pPrivData = pCapReq->pPrivData;
        result.pInputMetadata = pCapReq->pInputMetadata;
        result.pOutputMetadata = pCapReq->pOutputMetadata;
        result.pResultMetadata = nullptr;

        // Call back with the result
        if (session->callbacks.ChiProcessCaptureResult) {
            session->callbacks.ChiProcessCaptureResult(&result, session->pPrivateCallbackData);
        }

        // Call back with shutter message
        CHIMESSAGEDESCRIPTOR msg;
        memset(&msg, 0, sizeof(msg));
        msg.messageType = ChiMessageTypeShutter;
        msg.message.shutterMessage.frameworkFrameNum = pCapReq->frameNumber & 0xFFFFFFFF;
        msg.message.shutterMessage.timestamp = 0;
        msg.pPrivData = pCapReq->pPrivData;

        if (session->callbacks.ChiNotify) {
            session->callbacks.ChiNotify(&msg, session->pPrivateCallbackData);
        }

        if (pOutputBufs) delete[] pOutputBufs;
    }

    return CDKResultSuccess;
}

// =======================================================================
// Tag operations stub
// =======================================================================
static CDKResult StubQueryVendorTagLocation(const CHAR* pSectionName, const CHAR* pTagName,
                                             UINT32* pTagLocation) {
    (void)pSectionName; (void)pTagName;
    *pTagLocation = 0x80000000; // Return a vendor tag ID
    return CDKResultSuccess;
}

static CDKResult StubSetMetaData(CHIHANDLE metaHandle, UINT32 tag, VOID* pData, SIZE_T count) {
    (void)metaHandle; (void)tag; (void)pData; (void)count;
    return CDKResultSuccess;
}

static CDKResult StubGetMetaData(CHIHANDLE metaHandle, UINT32 tag, VOID* pData, SIZE_T count) {
    (void)metaHandle; (void)tag; (void)pData; (void)count;
    return CDKResultSuccess;
}

static VOID ChiGetTagOps(CHITAGSOPS* pOps) {
    memset(pOps, 0, sizeof(CHITAGSOPS));
    pOps->pQueryVendorTagLocation = StubQueryVendorTagLocation;
    pOps->pSetMetaData = StubSetMetaData;
    pOps->pGetMetaData = StubGetMetaData;
}

// =======================================================================
// Fence operations stub
// =======================================================================
static CDKResult StubCreateFence(CHIHANDLE hChiContext, CHIFENCECREATEPARAMS* pInfo,
                                  CHIFENCEHANDLE* phChiFence) {
    (void)hChiContext; (void)pInfo;
    StubFence* f = new StubFence();
    std::lock_guard<std::mutex> lock(g_mutex);
    g_fences.push_back(f);
    *phChiFence = reinterpret_cast<CHIFENCEHANDLE>(f);
    return CDKResultSuccess;
}

static CDKResult StubReleaseFence(CHIHANDLE hChiContext, CHIFENCEHANDLE hChiFence) {
    (void)hChiContext;
    std::lock_guard<std::mutex> lock(g_mutex);
    StubFence* f = reinterpret_cast<StubFence*>(hChiFence);
    for (auto it = g_fences.begin(); it != g_fences.end(); ++it) {
        if (*it == f) { g_fences.erase(it); break; }
    }
    delete f;
    return CDKResultSuccess;
}

static CDKResult StubSignalFence(CHIHANDLE hChiContext, CHIFENCEHANDLE hChiFence, CDKResult status) {
    (void)hChiContext;
    StubFence* f = reinterpret_cast<StubFence*>(hChiFence);
    if (f) f->status = status;
    return CDKResultSuccess;
}

static CDKResult StubGetFenceStatus(CHIHANDLE hChiContext, CHIFENCEHANDLE hChiFence, CDKResult* pResult) {
    (void)hChiContext;
    StubFence* f = reinterpret_cast<StubFence*>(hChiFence);
    *pResult = f ? f->status : CDKResultEInvalidState;
    return CDKResultSuccess;
}

static CDKResult StubWaitFenceAsync(CHIHANDLE hChiContext, PFNCHIFENCECALLBACK pCallbackFn,
                                     CHIFENCEHANDLE hChiFence, VOID* pData) {
    (void)hChiContext; (void)pCallbackFn; (void)hChiFence; (void)pData;
    return CDKResultSuccess;
}

static VOID ChiGetFenceOps(CHIFENCEOPS* pOps) {
    memset(pOps, 0, sizeof(CHIFENCEOPS));
    pOps->pCreateFence = StubCreateFence;
    pOps->pReleaseFence = StubReleaseFence;
    pOps->pSignalFence = StubSignalFence;
    pOps->pGetFenceStatus = StubGetFenceStatus;
    pOps->pWaitFenceAsync = StubWaitFenceAsync;
}

// =======================================================================
// Metadata operations stub
// =======================================================================
static CDKResult StubMetaCreate(CHIMETAHANDLE* pMetaHandle, CHIMETAPRIVATEDATA pPrivateData) {
    StubMetadata* m = new StubMetadata();
    m->pPrivateData = pPrivateData;
    std::lock_guard<std::mutex> lock(g_mutex);
    g_metadatas.push_back(m);
    *pMetaHandle = reinterpret_cast<CHIMETAHANDLE>(m);
    return CDKResultSuccess;
}

static CDKResult StubMetaDestroy(CHIMETAHANDLE hMetaHandle, BOOL force) {
    (void)force;
    std::lock_guard<std::mutex> lock(g_mutex);
    StubMetadata* m = reinterpret_cast<StubMetadata*>(hMetaHandle);
    for (auto it = g_metadatas.begin(); it != g_metadatas.end(); ++it) {
        if (*it == m) { g_metadatas.erase(it); break; }
    }
    delete m;
    return CDKResultSuccess;
}

static CDKResult StubMetaClone(CHIMETAHANDLE hSrc, CHIMETAHANDLE* phDst) {
    (void)hSrc; (void)phDst;
    return CDKResultEFailed;
}

static CDKResult StubMetaGetTag(CHIMETAHANDLE hMetaHandle, UINT32 tagID, VOID** ppData) {
    (void)hMetaHandle; (void)tagID; (void)ppData;
    return CDKResultENoSuch;
}

static CDKResult StubMetaGetTagEntry(CHIMETAHANDLE hMetaHandle, UINT32 tagID, CHIMETADATAENTRY* pEntry) {
    (void)hMetaHandle; (void)tagID; (void)pEntry;
    return CDKResultENoSuch;
}

static CDKResult StubMetaGetVendorTag(CHIMETAHANDLE hMetaHandle, const CHAR* pSection, const CHAR* pName, VOID** ppData) {
    (void)hMetaHandle; (void)pSection; (void)pName; (void)ppData;
    return CDKResultENoSuch;
}

static CDKResult StubMetaGetVendorTagEntry(CHIMETAHANDLE hMetaHandle, const CHAR* pSection, const CHAR* pName, CHIMETADATAENTRY* pEntry) {
    (void)hMetaHandle; (void)pSection; (void)pName; (void)pEntry;
    return CDKResultENoSuch;
}

static CDKResult StubMetaSetTag(CHIMETAHANDLE hMetaHandle, UINT32 tagID, const VOID* pData, UINT32 count) {
    (void)hMetaHandle; (void)tagID; (void)pData; (void)count;
    return CDKResultSuccess;
}

static CDKResult StubMetaSetVendorTag(CHIMETAHANDLE hMetaHandle, const CHAR* pSection, const CHAR* pName,
                                       const VOID* pData, UINT32 count) {
    (void)hMetaHandle; (void)pSection; (void)pName; (void)pData; (void)count;
    return CDKResultSuccess;
}

static CDKResult StubMetaSetAndroidMetadata(CHIMETAHANDLE hMetaHandle, const VOID* pAndroidMeta) {
    (void)hMetaHandle; (void)pAndroidMeta;
    return CDKResultSuccess;
}

static CDKResult StubMetaDeleteTag(CHIMETAHANDLE hMetaHandle, UINT32 tagID) {
    (void)hMetaHandle; (void)tagID;
    return CDKResultSuccess;
}

static CDKResult StubMetaInvalidate(CHIMETAHANDLE hMetaHandle) {
    (void)hMetaHandle;
    return CDKResultSuccess;
}

static CDKResult StubMetaMerge(CHIMETAHANDLE hDst, CHIMETAHANDLE hSrc, BOOL disjoint) {
    (void)hDst; (void)hSrc; (void)disjoint;
    return CDKResultSuccess;
}

static CDKResult StubMetaCopy(CHIMETAHANDLE hDst, CHIMETAHANDLE hSrc, BOOL disjoint) {
    (void)hDst; (void)hSrc; (void)disjoint;
    return CDKResultSuccess;
}

static CDKResult StubMetaCapacity(CHIMETAHANDLE hMetaHandle, UINT32* pCapacity) {
    (void)hMetaHandle;
    *pCapacity = 1024;
    return CDKResultSuccess;
}

static CDKResult StubMetaTagCount(CHIMETAHANDLE hMetaHandle, UINT32* pCount) {
    (void)hMetaHandle;
    *pCount = 0;
    return CDKResultSuccess;
}

static CDKResult StubMetaPrint(CHIMETAHANDLE hMetaHandle) {
    (void)hMetaHandle;
    return CDKResultSuccess;
}

static CDKResult StubMetaDump(CHIMETAHANDLE hMetaHandle, const CHAR* pFilename) {
    (void)hMetaHandle; (void)pFilename;
    return CDKResultSuccess;
}

static CDKResult StubMetaBinaryDump(CHIMETAHANDLE hMetaHandle, const CHAR* pFilename) {
    (void)hMetaHandle; (void)pFilename;
    return CDKResultSuccess;
}

static CDKResult StubMetaAddReference(CHIMETAHANDLE hMetaHandle, CHIMETADATACLIENTID clientID, UINT32* pRefCount) {
    (void)hMetaHandle; (void)clientID;
    *pRefCount = 1;
    return CDKResultSuccess;
}

static CDKResult StubMetaReleaseReference(CHIMETAHANDLE hMetaHandle, CHIMETADATACLIENTID clientID, UINT32* pRefCount) {
    (void)hMetaHandle; (void)clientID;
    *pRefCount = 0;
    return CDKResultSuccess;
}

static CDKResult StubMetaReleaseAllReferences(CHIMETAHANDLE hMetaHandle, BOOL bCHIAndCAMX) {
    (void)hMetaHandle; (void)bCHIAndCAMX;
    return CDKResultSuccess;
}

static CDKResult StubMetaReferenceCount(CHIMETAHANDLE hMetaHandle, UINT32* pRefCount) {
    (void)hMetaHandle;
    *pRefCount = 1;
    return CDKResultSuccess;
}

static CDKResult StubMetaGetMetadataTable(CHIMETADATAENTRY* pTable) {
    (void)pTable;
    return CDKResultSuccess;
}

static CDKResult StubMetaGetMetadataEntryCount(UINT32* pCount) {
    *pCount = 0;
    return CDKResultSuccess;
}

static CDKResult StubMetaIteratorCreate(CHIMETAHANDLE hMetaHandle, CHIMETADATAITERATOR* pIterator) {
    (void)hMetaHandle;
    *pIterator = reinterpret_cast<CHIMETADATAITERATOR>(new int(0));
    return CDKResultSuccess;
}

static CDKResult StubMetaIteratorDestroy(CHIMETADATAITERATOR hIterator) {
    delete reinterpret_cast<int*>(hIterator);
    return CDKResultSuccess;
}

static CDKResult StubMetaIteratorBegin(CHIMETADATAITERATOR hIterator) {
    (void)hIterator;
    return CDKResultENoMore; // empty
}

static CDKResult StubMetaIteratorNext(CHIMETADATAITERATOR hIterator) {
    (void)hIterator;
    return CDKResultENoMore;
}

static CDKResult StubMetaIteratorGetEntry(CHIMETADATAITERATOR hIterator, CHIMETADATAENTRY* pEntry) {
    (void)hIterator; (void)pEntry;
    return CDKResultEInvalidState;
}

static CDKResult StubMetaGetDefaultAndroidMeta(UINT32 cameraId, const VOID** ppAndroidMeta) {
    (void)cameraId; (void)ppAndroidMeta;
    return CDKResultENotImplemented;
}

static CDKResult StubMetaGetDefaultMetadata(UINT32 cameraId, CHIMETAHANDLE* phMetaBuffer) {
    return StubMetaCreate(phMetaBuffer, nullptr);
}

static CDKResult StubMetaFilter(CHIMETAHANDLE hMetaHandle, VOID* pAndroidMeta, BOOL frameworkTagsOnly,
                                 BOOL filterProperties, UINT32 filterTagCount, UINT32* pFilterTagArray) {
    (void)hMetaHandle; (void)pAndroidMeta; (void)frameworkTagsOnly;
    (void)filterProperties; (void)filterTagCount; (void)pFilterTagArray;
    return CDKResultSuccess;
}

static CDKResult StubMetaGetPrivateData(CHIMETAHANDLE hMetaHandle, CHIMETAPRIVATEDATA* ppPrivateData) {
    StubMetadata* m = reinterpret_cast<StubMetadata*>(hMetaHandle);
    *ppPrivateData = m ? m->pPrivateData : nullptr;
    return CDKResultSuccess;
}

static CDKResult StubMetaMergeMultiCameraMeta(CHIMETAHANDLE hDst, UINT32 count, CHIMETAHANDLE* phSrcs,
                                               UINT32* pCameraIds, UINT32 primaryCameraId) {
    (void)hDst; (void)count; (void)phSrcs; (void)pCameraIds; (void)primaryCameraId;
    return CDKResultSuccess;
}

static CDKResult StubMetaGetTagByCameraId(CHIMETAHANDLE hMetaHandle, UINT32 tagID, UINT32 cameraId, VOID** ppData) {
    (void)hMetaHandle; (void)tagID; (void)cameraId;
    *ppData = nullptr;
    return CDKResultENoSuch;
}

static CDKResult StubMetaCreateWithTagArray(const UINT32* pTagList, UINT32 tagListCount,
                                             CHIMETAHANDLE* pMetaHandle, CHIMETAPRIVATEDATA pPrivateData) {
    (void)pTagList; (void)tagListCount;
    return StubMetaCreate(pMetaHandle, pPrivateData);
}

static CDKResult StubMetaCreateWithAndroidMetadata(const VOID* pAndroidMeta,
                                                    CHIMETAHANDLE* pMetaHandle, CHIMETAPRIVATEDATA pPrivateData) {
    (void)pAndroidMeta;
    return StubMetaCreate(pMetaHandle, pPrivateData);
}

static VOID ChiGetMetadataOps(CHIMETADATAOPS* pOps) {
    memset(pOps, 0, sizeof(CHIMETADATAOPS));
    pOps->pCreate = StubMetaCreate;
    pOps->pCreateWithTagArray = StubMetaCreateWithTagArray;
    pOps->pCreateWithAndroidMetadata = StubMetaCreateWithAndroidMetadata;
    pOps->pDestroy = StubMetaDestroy;
    pOps->pClone = StubMetaClone;
    pOps->pGetTag = StubMetaGetTag;
    pOps->pGetTagEntry = StubMetaGetTagEntry;
    pOps->pGetVendorTag = StubMetaGetVendorTag;
    pOps->pGetVendorTagEntry = StubMetaGetVendorTagEntry;
    pOps->pSetTag = StubMetaSetTag;
    pOps->pSetVendorTag = StubMetaSetVendorTag;
    pOps->pSetAndroidMetadata = StubMetaSetAndroidMetadata;
    pOps->pDeleteTag = StubMetaDeleteTag;
    pOps->pInvalidate = StubMetaInvalidate;
    pOps->pMerge = StubMetaMerge;
    pOps->pCopy = StubMetaCopy;
    pOps->pCapacity = StubMetaCapacity;
    pOps->pCount = StubMetaTagCount;
    pOps->pPrint = StubMetaPrint;
    pOps->pDump = StubMetaDump;
    pOps->pBinaryDump = StubMetaBinaryDump;
    pOps->pAddReference = StubMetaAddReference;
    pOps->pReleaseReference = StubMetaReleaseReference;
    pOps->pReleaseAllReferences = StubMetaReleaseAllReferences;
    pOps->pReferenceCount = StubMetaReferenceCount;
    pOps->pGetMetadataTable = StubMetaGetMetadataTable;
    pOps->pGetMetadataEntryCount = StubMetaGetMetadataEntryCount;
    pOps->pIteratorCreate = StubMetaIteratorCreate;
    pOps->pIteratorDestroy = StubMetaIteratorDestroy;
    pOps->pIteratorBegin = StubMetaIteratorBegin;
    pOps->pIteratorNext = StubMetaIteratorNext;
    pOps->pIteratorGetEntry = StubMetaIteratorGetEntry;
    pOps->pGetDefaultAndroidMeta = StubMetaGetDefaultAndroidMeta;
    pOps->pGetDefaultMetadata = StubMetaGetDefaultMetadata;
    pOps->pFilter = StubMetaFilter;
    pOps->pGetPrivateData = StubMetaGetPrivateData;
    pOps->pMergeMultiCameraMeta = StubMetaMergeMultiCameraMeta;
    pOps->pGetTagByCameraId = StubMetaGetTagByCameraId;
}

// =======================================================================
// Buffer manager operations stub
// =======================================================================
static CHIBUFFERMANAGERHANDLE StubBufferManagerCreate(const CHAR* pName, CHIBufferManagerCreateData* pCreateData) {
    (void)pName;
    StubBufferManager* bm = new StubBufferManager();
    if (pCreateData) bm->createData = *pCreateData;
    std::lock_guard<std::mutex> lock(g_mutex);
    g_bufferManagers.push_back(bm);
    return reinterpret_cast<CHIBUFFERMANAGERHANDLE>(bm);
}

static VOID StubBufferManagerDestroy(CHIBUFFERMANAGERHANDLE hBM) {
    std::lock_guard<std::mutex> lock(g_mutex);
    StubBufferManager* bm = reinterpret_cast<StubBufferManager*>(hBM);
    for (auto& buf : bm->buffers) {
        if (buf->data) free(buf->data);
        delete buf;
    }
    for (auto it = g_bufferManagers.begin(); it != g_bufferManagers.end(); ++it) {
        if (*it == bm) { g_bufferManagers.erase(it); break; }
    }
    delete bm;
}

static CHIBUFFERHANDLE StubBufferManagerGetImageBuffer(CHIBUFFERMANAGERHANDLE hBM) {
    StubBufferManager* bm = reinterpret_cast<StubBufferManager*>(hBM);
    StubImageBuffer* buf = new StubImageBuffer();
    // Allocate a dummy buffer
    size_t size = bm->createData.width * bm->createData.height * 2; // assume NV12
    buf->size = size;
    buf->data = calloc(1, size);
    buf->refCount = 1;
    bm->buffers.push_back(buf);
    return reinterpret_cast<CHIBUFFERHANDLE>(buf);
}

static CDKResult StubBufferManagerAddReference(CHIBUFFERMANAGERHANDLE hBM, CHIBUFFERHANDLE hBuf) {
    (void)hBM;
    StubImageBuffer* buf = reinterpret_cast<StubImageBuffer*>(hBuf);
    buf->refCount++;
    return CDKResultSuccess;
}

static CDKResult StubBufferManagerReleaseReference(CHIBUFFERMANAGERHANDLE hBM, CHIBUFFERHANDLE hBuf) {
    (void)hBM;
    StubImageBuffer* buf = reinterpret_cast<StubImageBuffer*>(hBuf);
    buf->refCount--;
    return CDKResultSuccess;
}

static UINT StubBufferManagerGetReference(CHIBUFFERHANDLE hBuf) {
    StubImageBuffer* buf = reinterpret_cast<StubImageBuffer*>(hBuf);
    return buf->refCount;
}

static CDKResult StubBufferManagerActivate(CHIBUFFERMANAGERHANDLE hBM) {
    StubBufferManager* bm = reinterpret_cast<StubBufferManager*>(hBM);
    bm->active = true;
    return CDKResultSuccess;
}

static CDKResult StubBufferManagerDeactivate(CHIBUFFERMANAGERHANDLE hBM, BOOL partial) {
    (void)partial;
    StubBufferManager* bm = reinterpret_cast<StubBufferManager*>(hBM);
    bm->active = false;
    return CDKResultSuccess;
}

static CDKResult StubBufferManagerBindBuffer(CHIBUFFERHANDLE hBuf) {
    (void)hBuf;
    return CDKResultSuccess;
}

static const VOID* StubBufferManagerGetCPUAddress(CHIBUFFERHANDLE hBuf) {
    StubImageBuffer* buf = reinterpret_cast<StubImageBuffer*>(hBuf);
    return buf->data;
}

static INT StubBufferManagerGetFileDescriptor(CHIBUFFERHANDLE hBuf) {
    (void)hBuf;
    return -1;
}

static VOID* StubBufferManagerGetGrallocHandle(CHIBUFFERHANDLE hBuf) {
    (void)hBuf;
    return nullptr;
}

static CDKResult StubBufferManagerCacheOps(CHIBUFFERHANDLE hBuf, BOOL invalidate, BOOL clean) {
    (void)hBuf; (void)invalidate; (void)clean;
    return CDKResultSuccess;
}

static VOID ChiGetBufferManagerOps(CHIBUFFERMANAGEROPS* pOps) {
    memset(pOps, 0, sizeof(CHIBUFFERMANAGEROPS));
    pOps->pCreate = StubBufferManagerCreate;
    pOps->pDestroy = StubBufferManagerDestroy;
    pOps->pGetImageBuffer = StubBufferManagerGetImageBuffer;
    pOps->pAddReference = StubBufferManagerAddReference;
    pOps->pReleaseReference = StubBufferManagerReleaseReference;
    pOps->pGetReference = StubBufferManagerGetReference;
    pOps->pActivate = StubBufferManagerActivate;
    pOps->pDeactivate = StubBufferManagerDeactivate;
    pOps->pBindBuffer = StubBufferManagerBindBuffer;
    pOps->pGetCPUAddress = StubBufferManagerGetCPUAddress;
    pOps->pGetFileDescriptor = StubBufferManagerGetFileDescriptor;
    pOps->pGetGrallocHandle = StubBufferManagerGetGrallocHandle;
    pOps->pCacheOps = StubBufferManagerCacheOps;
}

// =======================================================================
// GetSettings stub
// =======================================================================
static VOID ChiGetSettings(CHIEXTENDSETTINGS** ppExtend, CHIMODIFYSETTINGS** ppModify) {
    *ppExtend = nullptr;
    *ppModify = nullptr;
}

// =======================================================================
// CHI Entry Point
// =======================================================================
extern "C" {

CDK_VISIBILITY_PUBLIC VOID ChiEntry(CHICONTEXTOPS* pContextOps) {
    if (!pContextOps) return;
    memset(pContextOps, 0, sizeof(CHICONTEXTOPS));
    pContextOps->size = sizeof(CHICONTEXTOPS);
    pContextOps->majorVersion = 1;
    pContextOps->minorVersion = 0;
    pContextOps->subVersion = 0;
    pContextOps->pOpenContext = ChiOpenContext;
    pContextOps->pCloseContext = ChiCloseContext;
    pContextOps->pGetNumCameras = ChiGetNumCameras;
    pContextOps->pGetCameraInfo = ChiGetCameraInfo;
    pContextOps->pEnumerateSensorModes = ChiEnumerateSensorModes;
    pContextOps->pCreatePipelineDescriptor = ChiCreatePipelineDescriptor;
    pContextOps->pDestroyPipelineDescriptor = ChiDestroyPipelineDescriptor;
    pContextOps->pCreateSession = ChiCreateSession;
    pContextOps->pDestroySession = ChiDestroySession;
    pContextOps->pActivatePipeline = ChiActivatePipeline;
    pContextOps->pDeactivatePipeline = ChiDeactivatePipeline;
    pContextOps->pSubmitPipelineRequest = ChiSubmitPipelineRequest;
    pContextOps->pTagOps = ChiGetTagOps;
    pContextOps->pFlushSession = ChiFlushSession;
    pContextOps->pQueryPipelineMetadataInfo = ChiQueryPipelineMetadataInfo;
    pContextOps->pGetFenceOps = ChiGetFenceOps;
    pContextOps->pMetadataOps = ChiGetMetadataOps;
    pContextOps->pGetBufferManagerOps = ChiGetBufferManagerOps;
    pContextOps->pGetSettings = ChiGetSettings;
}

// HMI stub - camera_module_t for vendor tag ops
static int StubGetNumberOfCameras() { return FAKE_NUM_CAMERAS; }
static int StubGetCameraInfo(int camera_id, camera_info* info) {
    memset(info, 0, sizeof(camera_info));
    info->facing = CAMERA_FACING_BACK;
    info->orientation = 0;
    return 0;
}
static void StubGetVendorTagOps(vendor_tag_ops_t* ops) {
    memset(ops, 0, sizeof(vendor_tag_ops_t));
}

static camera_module_t g_cameraModule = {
    0, // common_version
    0, // hal_api_version
    nullptr,
    {nullptr, nullptr, nullptr, nullptr, nullptr},
    StubGetNumberOfCameras,
    StubGetCameraInfo,
    nullptr,
    StubGetVendorTagOps,
    nullptr,
    nullptr,
    nullptr,
    {nullptr, nullptr, nullptr, nullptr, nullptr},
};

CDK_VISIBILITY_PUBLIC camera_module_t HMI = {
    0, // common_version (will be set below)
    0, // hal_api_version
    nullptr,
    {nullptr, nullptr, nullptr, nullptr, nullptr},
    StubGetNumberOfCameras,
    StubGetCameraInfo,
    nullptr,
    StubGetVendorTagOps,
    nullptr,
    nullptr,
    nullptr,
    {nullptr, nullptr, nullptr, nullptr, nullptr},
};

} // extern "C"

// =======================================================================
// Buffer memory functions (exported for dlsym by BufferManager)
// =======================================================================

// Types matching camxpresilmem.h
struct _CamxMemHandle { void* pData; };
typedef _CamxMemHandle* CamxMemHandle;

extern "C" {

CDK_VISIBILITY_PUBLIC uint32_t CamxMemGetImageSize(uint32_t width, uint32_t height, uint32_t format, uint32_t usage) {
    (void)format; (void)usage;
    // Rough estimate: NV12 = 1.5 bytes per pixel
    return (width * height * 3) / 2;
}

CDK_VISIBILITY_PUBLIC int CamxMemAlloc(CamxMemHandle* pphMem, uint32_t width, uint32_t height, uint32_t format, uint32_t usageFlags) {
    (void)format; (void)usageFlags;
    uint32_t size = (width * height * 3) / 2;
    if (size == 0) size = 4096;
    CamxMemHandle handle = new _CamxMemHandle();
    handle->pData = calloc(1, size);
    if (!handle->pData) { delete handle; *pphMem = nullptr; return -1; }
    *pphMem = handle;
    return 0;
}

CDK_VISIBILITY_PUBLIC void CamxMemRelease(CamxMemHandle pphMem) {
    if (pphMem) {
        if (pphMem->pData) free(pphMem->pData);
        delete pphMem;
    }
}

} // extern "C"
