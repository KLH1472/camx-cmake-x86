// CHI Framework stubs — implementations for chifeature2test Linux build
#include "chiframework_types.h"
#include "chxextensionmodule.h"
#include "chxpipeline.h"
#include "chxsession.h"
#include "chxusecase.h"
#include "chxusecaseutils.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <pthread.h>

#include "chxfeature.h"
#include "camxchiofflinelogger.h"
#include "chifeature2types.h"
#include "chimodule.h"

using namespace std;

CHIBUFFERMANAGEROPS g_chiBufferManagerOps = {};
CHIFENCEOPS         g_chiFenceOps         = {};
CHIMETADATAOPS      g_chiMetadataOps      = {};

static void InitializeGlobalOps() {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;

    ChiModule* pModule = ChiModule::GetInstance();
    if (!pModule) return;
    const CHICONTEXTOPS* ops = pModule->GetChiOps();
    if (!ops) return;
    if (ops->pGetBufferManagerOps) ops->pGetBufferManagerOps(&g_chiBufferManagerOps);
    if (ops->pGetFenceOps)         ops->pGetFenceOps(&g_chiFenceOps);
    if (ops->pMetadataOps)         ops->pMetadataOps(&g_chiMetadataOps);
}

// ══════════════════════════════════════════════════════════════════════════
// ChxUtils / Mutex / Condition / Semaphore — real implementations from
// chxutils.cpp (compiled via nativechitest/chiutils/chxutils.cpp)
// ══════════════════════════════════════════════════════════════════════════

// ══════════════════════════════════════════════════════════════════════════
// ExtensionModule
// ══════════════════════════════════════════════════════════════════════════

ExtensionModule* ExtensionModule::GetInstance() {
    static ExtensionModule instance;
    static bool opsInitialized = false;
    if (!opsInitialized) {
        opsInitialized = true;
        InitializeGlobalOps();
    }
    return &instance;
}

CDKResult ExtensionModule::CreateChiFence(CHIFENCECREATEPARAMS* pInfo, CHIFENCEHANDLE* phChiFence) {
    (void)pInfo;
    *phChiFence = nullptr;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::ReleaseChiFence(CHIFENCEHANDLE hChiFence) {
    (void)hChiFence;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::SignalChiFence(CHIFENCEHANDLE hChiFence, CDKResult statusResult) {
    (void)hChiFence; (void)statusResult;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::GetChiFenceStatus(CHIFENCEHANDLE hChiFence, CDKResult* pFenceResult) {
    (void)hChiFence;
    *pFenceResult = CDKResultSuccess;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::ActivatePipeline(CHIHANDLE sessionHandle, CHIPIPELINEDESCRIPTOR pipelineHandle) {
    (void)sessionHandle; (void)pipelineHandle;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::DeactivatePipeline(CHIHANDLE sessionHandle, CHIPIPELINEDESCRIPTOR pipelineHandle, CHIDEACTIVATEPIPELINEMODE mode) {
    (void)sessionHandle; (void)pipelineHandle; (void)mode;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::Flush(CHIHANDLE sessionHandle) {
    (void)sessionHandle;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::SubmitRequest(CHIPIPELINEREQUEST* pSubmitRequestData) {
    ChiModule* pModule = ChiModule::GetInstance();
    if (pModule && pModule->GetChiOps() && pModule->GetChiOps()->pSubmitPipelineRequest) {
        return pModule->GetChiOps()->pSubmitPipelineRequest(pModule->GetContext(), pSubmitRequestData);
    }
    return CDKResultSuccess;
}

CDKResult ExtensionModule::GetCameraInfo(uint32_t logicalCameraId, camera_info* cameraInfo) {
    (void)logicalCameraId; (void)cameraInfo;
    return CDKResultSuccess;
}

VOID ExtensionModule::GetNumCameras(UINT32* pNumFwCameras, UINT32* pNumLogicalCameras) {
    *pNumFwCameras = 1;
    *pNumLogicalCameras = 1;
}

VOID ExtensionModule::GetVendorTagOps(CHITAGSOPS* pVendorTagOps) {
    (void)pVendorTagOps;
}

VOID ExtensionModule::GetMetadataOps(CHIMETADATAOPS* pMetadataOps) {
    if (pMetadataOps) {
        *pMetadataOps = g_chiMetadataOps;
    }
}

CDKResult ExtensionModule::GetAvailableRequestKeys(UINT32 cameraId, UINT32* pTagList, UINT32 maxTagListSize, UINT32* pActualCount) {
    (void)cameraId; (void)pTagList; (void)maxTagListSize;
    if (pActualCount) *pActualCount = 0;
    return CDKResultSuccess;
}

const LogicalCameraInfo* ExtensionModule::GetPhysicalCameraInfo(UINT32 physicalCameraId) const {
    (void)physicalCameraId;
    static DeviceInfo s_deviceInfo = {};
    static DeviceInfo* s_ppDeviceInfo[1] = { &s_deviceInfo };
    static LogicalCameraInfo s_info = {};
    static bool s_initialized = false;
    if (!s_initialized) {
        s_initialized = true;
        s_info.cameraId = 0;
        s_info.m_cameraCaps.size = sizeof(CHICAMERAINFO);
        s_info.m_cameraCaps.numSensorModes = 3;
        s_info.m_cameraCaps.sensorCaps.size = sizeof(CHISENSORCAPS);
        s_info.m_cameraCaps.sensorCaps.activeArray = { 0, 0, 5344, 4016 };
        s_info.numPhysicalCameras = 1;
        s_info.ppDeviceInfo = s_ppDeviceInfo;
        s_info.primaryCameraId = 0;
        s_info.publicVisiblity = TRUE;
    }
    return &s_info;
}

CDKResult ExtensionModule::GetPhysicalCameraSensorModes(UINT32 physicalCameraId, UINT32* pNumSensorModes, CHISENSORMODEINFO** ppAllSensorModes) {
    (void)physicalCameraId;
    *pNumSensorModes = 0;
    *ppAllSensorModes = nullptr;
    return CDKResultSuccess;
}

CDKResult ExtensionModule::ExtendOpen(uint32_t logicalCameraId, VOID* pPriv) {
    (void)logicalCameraId; (void)pPriv;
    return CDKResultSuccess;
}

VOID ExtensionModule::ModifySettings(VOID* pPriv) {
    (void)pPriv;
}

EnableDumpDebugDataType ExtensionModule::EnableDumpDebugData() { return DumpDebugDataNone; }

// ── Inline accessors that need out-of-line definitions for vtable ──

BOOL ExtensionModule::EnableCHILateBinding() { return FALSE; }
BOOL ExtensionModule::EnableFeature2Dump() { return FALSE; }
BOOL ExtensionModule::EnableMFSRChiFence() { return FALSE; }
BOOL ExtensionModule::EnableTBMChiFence() { return FALSE; }
BOOL ExtensionModule::UseGPURotationUsecase() { return FALSE; }
BOOL ExtensionModule::EnableUnifiedBufferManager() { return TRUE; }
UINT ExtensionModule::GetUsecaseMaxFPS() { return 30; }
UINT32 ExtensionModule::GetMaxHalRequests() { return 4; }
BOOL ExtensionModule::Enable3ADebugData() { return FALSE; }
BOOL ExtensionModule::EnableTuningMetadata() { return FALSE; }

// ══════════════════════════════════════════════════════════════════════════
// ChiMetadataManager — real implementation from chxmetadata.cpp (not stubbed)
// ══════════════════════════════════════════════════════════════════════════

// ══════════════════════════════════════════════════════════════════════════
// ChiMetadata — real implementation from chxmetadata.cpp (not stubbed)
// ══════════════════════════════════════════════════════════════════════════

// ══════════════════════════════════════════════════════════════════════════
// Pipeline
// ══════════════════════════════════════════════════════════════════════════

Pipeline* Pipeline::Create(UINT32 cameraId, PipelineType type, const CHAR* pName) {
    (void)cameraId; (void)type; (void)pName;
    return new Pipeline();
}

VOID Pipeline::Destroy() {
    delete this;
}

CDKResult Pipeline::CreateDescriptor() {
    ChiModule* pModule = ChiModule::GetInstance();
    if (pModule && pModule->GetChiOps() && pModule->GetChiOps()->pCreatePipelineDescriptor && m_pCreateDesc) {
        m_hDescriptor = pModule->GetChiOps()->pCreatePipelineDescriptor(
            pModule->GetContext(), m_pName, m_pCreateDesc,
            m_numOutputs, m_pOutputs, m_numInputs, m_pInputOptions);
        if (m_hDescriptor != NULL) {
            fprintf(stderr, "[Pipeline] CreateDescriptor OK: %p (nodes=%u links=%u)\n",
                    m_hDescriptor, m_pCreateDesc->numNodes, m_pCreateDesc->numLinks);
        }
    }
    return CDKResultSuccess;
}

const CHIPIPELINEINFO Pipeline::GetPipelineInfo() const {
    CHIPIPELINEINFO info = {};
    return info;
}

VOID Pipeline::SetOutputBuffers(UINT numOutputs, CHIPORTBUFFERDESCRIPTOR* pOutputs) {
    m_numOutputs = numOutputs;
    memcpy(&m_pOutputs[0], pOutputs, sizeof(CHIPORTBUFFERDESCRIPTOR) * numOutputs);
}

VOID Pipeline::SetInputBuffers(UINT numInputs, CHIPORTBUFFERDESCRIPTOR* pInputs) {
    (void)numInputs; (void)pInputs;
}

// Inline methods that need out-of-line definitions:
ChiMetadata* Pipeline::GetDescriptorMetadata() {
    static ChiMetadata* s_pMeta = nullptr;
    if (!s_pMeta) s_pMeta = ChiMetadata::Create(nullptr, 0, false, nullptr);
    return s_pMeta;
}
CHIPIPELINEDESCRIPTOR Pipeline::GetPipelineHandle() const {
    return m_hDescriptor ? m_hDescriptor : (CHIPIPELINEDESCRIPTOR)this;
}
UINT Pipeline::GetMetadataClientId() const { return 1; }
const CHAR* Pipeline::GetPipelineName() const { return "stub"; }
UINT32* Pipeline::GetTagList() { return nullptr; }
UINT32 Pipeline::GetTagCount() { return 0; }
UINT32 Pipeline::GetPartialTagCount() { return 0; }
static CHISENSORMODEINFO* GetStubSensorModeInfo() {
    static CHISENSORMODEINFO s_sensorMode = {};
    static bool init = false;
    if (!init) {
        init = true;
        s_sensorMode.size = sizeof(CHISENSORMODEINFO);
        s_sensorMode.modeIndex = 0;
        s_sensorMode.frameDimension = { 5344, 4016 };
        s_sensorMode.cropInfo = { 5344, 4016 };
        s_sensorMode.bpp = 10;
        s_sensorMode.frameRate = 30;
        s_sensorMode.horizontalBinning = 1;
        s_sensorMode.verticalBinning = 1;
    }
    return &s_sensorMode;
}

CHISENSORMODEINFO* Pipeline::GetSensorModeInfo() { return GetStubSensorModeInfo(); }
BOOL Pipeline::IsRealTime() const { return FALSE; }
VOID Pipeline::SetPipelineActivateFlag() {}
VOID Pipeline::SetMetadataClientId(UINT clientId) { (void)clientId; }
VOID Pipeline::SetDeferFinalizeFlag(BOOL isDeferFinalizeNeeded) { (void)isDeferFinalizeNeeded; }
VOID Pipeline::SetPipelineNodePorts(const CHIPIPELINECREATEDESCRIPTOR* pCreateDesc) {
    m_pCreateDesc = pCreateDesc;
}
VOID Pipeline::SetPipelineName(const CHAR* const pPipelineName) { m_pName = pPipelineName; }
VOID Pipeline::SetSensorModePickHint(const CHISENSORMODEPICKHINT* pSensorModePickHint) { (void)pSensorModePickHint; }

// ══════════════════════════════════════════════════════════════════════════
// Session
// ══════════════════════════════════════════════════════════════════════════

Session* Session::Create(Pipeline** ppPipelines, UINT32 numPipelines, CHICALLBACKS* pCallbacks, VOID* pPrivateData) {
    Session* pSession = new Session();
    pSession->m_numPipelines = numPipelines;
    for (UINT32 i = 0; i < numPipelines && i < 16; i++) {
        if (ppPipelines && ppPipelines[i]) {
            pSession->m_pipelineHandles[i] = ppPipelines[i]->GetPipelineHandle();
        }
    }
    ChiModule* pModule = ChiModule::GetInstance();
    if (pModule && pModule->GetChiOps() && pModule->GetChiOps()->pCreateSession) {
        CHIPIPELINEINFO pipelineInfo[16] = {};
        for (UINT32 i = 0; i < numPipelines && i < 16; i++) {
            pipelineInfo[i].hPipelineDescriptor = pSession->m_pipelineHandles[i];
        }
        CHISESSIONFLAGS flags = {};
        pSession->m_hSession = pModule->GetChiOps()->pCreateSession(
            pModule->GetContext(), numPipelines, pipelineInfo,
            pCallbacks, pPrivateData, flags);
    }
    return pSession;
}

VOID Session::Destroy(BOOL isForced) {
    (void)isForced;
    if (m_hSession) {
        ChiModule* pModule = ChiModule::GetInstance();
        if (pModule && pModule->GetChiOps() && pModule->GetChiOps()->pDestroySession) {
            pModule->GetChiOps()->pDestroySession(pModule->GetContext(), m_hSession, isForced);
        }
        m_hSession = nullptr;
    }
    delete this;
}

CHIPIPELINEDESCRIPTOR Session::GetPipelineHandle(UINT index) const {
    return (index < m_numPipelines) ? m_pipelineHandles[index] : nullptr;
}
CHISENSORMODEINFO* Session::GetSensorModeInfo(UINT index) const {
    (void)index;
    return GetStubSensorModeInfo();
}
CHIHANDLE Session::GetSessionHandle() const { return m_hSession; }
BOOL Session::IsPipelineActive(UINT index) const { (void)index; return FALSE; }

// ══════════════════════════════════════════════════════════════════════════
// Usecase
// ══════════════════════════════════════════════════════════════════════════

camera3_capture_result_t* Usecase::GetCaptureResult(UINT resultId) {
    (void)resultId;
    return nullptr;
}

CDKResult Usecase::SubmitRequest(CHIPIPELINEREQUEST* pSubmitRequestData) {
    (void)pSubmitRequestData;
    return CDKResultSuccess;
}

VOID Usecase::ReturnFrameworkMessage(const camera3_notify_msg_t* pMessage, UINT32 cameraID) {
    (void)pMessage; (void)cameraID;
}

VOID Usecase::ProcessErrorMessage(const CHIMESSAGEDESCRIPTOR* pMessageDescriptor) {
    (void)pMessageDescriptor;
}

CDKResult Usecase::UpdateAppResultMetadata(ChiMetadata* pChiMetadata, UINT resultId, UINT32 clientId) {
    (void)pChiMetadata; (void)resultId; (void)clientId;
    return CDKResultSuccess;
}

UINT32 Usecase::GetGenericMetadataClientId() {
    return 0;
}

// ══════════════════════════════════════════════════════════════════════════
// Feature — vtable anchor via Flush (first non-pure, non-default virtual)
// ══════════════════════════════════════════════════════════════════════════

VOID Feature::Flush() {}

VOID Feature::SetFeatureStatus(FeatureStatus currentstate) {
    (void)currentstate;
}

// ══════════════════════════════════════════════════════════════════════════
// CamX::OfflineLogger
// ══════════════════════════════════════════════════════════════════════════

CAMX_NAMESPACE_BEGIN

OfflineLogger::OfflineLogger(OfflineLoggerType type) { (void)type; }
CamxResult OfflineLogger::AddLog(const CHAR* pLog, UINT logSize) { (void)pLog; (void)logSize; return CamxResultSuccess; }

// Static members defined in camxchiofflinelogger.h need out-of-line definition
BOOL OfflineLogger::s_isInitValid = FALSE;
BOOL OfflineLogger::s_isInit = FALSE;
std::mutex OfflineLogger::s_initMutex;
std::vector<OfflineLogger*> OfflineLogger::s_pOfflineLoggerInstancePool;

CAMX_NAMESPACE_END

// ══════════════════════════════════════════════════════════════════════════
// Feature2 descriptors (extern references from OEM features)
// Must use extern to override internal linkage of 'const' in C++
// ══════════════════════════════════════════════════════════════════════════

// Bayer2YuvFeatureDescriptor is now compiled from the real chifeature2bayer2yuvdescriptor.cpp
extern const ChiFeature2Descriptor IPEFeatureDescriptor = {};
extern const ChiFeature2Descriptor JPEGFeatureDescriptor = {};
extern const ChiFeature2Descriptor RealTimeFeatureDescriptor = {};
extern const ChiFeature2Descriptor BPSFeatureDescriptor = {};
extern const ChiFeature2Descriptor MFSRFeatureDescriptor = {};

// ══════════════════════════════════════════════════════════════════════════
// Port descriptors for OEM features (referenced as extern)
// ══════════════════════════════════════════════════════════════════════════

CHAR RealTimeOutputPortDescriptors = 0;
CHAR ZSLInputPortDescriptors = 0;
CHAR MfsrPrefilterOutPutPortDescriptors = 0;
CHAR MfsrBlendOutPutPortDescriptors = 0;
CHAR MfsrBlendInputPortDescriptors = 0;
CHAR MfsrPostFilterOutPutPortDescriptors = 0;

// ══════════════════════════════════════════════════════════════════════════
// Global usecase descriptor stub
// ══════════════════════════════════════════════════════════════════════════

ChiUsecaseTag g_DefaultUsecase = {};
