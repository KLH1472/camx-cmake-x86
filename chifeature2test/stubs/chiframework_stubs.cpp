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

// Bring in real Feature class for vtable (from source tree)
#include "chxfeature.h"
#include "camxchiofflinelogger.h"
#include "chifeature2types.h"

using namespace std;

// ══════════════════════════════════════════════════════════════════════════
// ChxUtils static methods
// ══════════════════════════════════════════════════════════════════════════

VOID* ChxUtils::Calloc(SIZE_T numBytes) {
    return calloc(1, numBytes);
}

VOID ChxUtils::Free(VOID* pMem) {
    free(pMem);
}

VOID* ChxUtils::Memcpy(VOID* pDst, const VOID* pSrc, SIZE_T numBytes) {
    return memcpy(pDst, pSrc, numBytes);
}

VOID* ChxUtils::Memset(VOID* pDst, INT value, SIZE_T numBytes) {
    return memset(pDst, value, numBytes);
}

BOOL ChxUtils::FEqualCoarse(FLOAT value1, FLOAT value2) {
    (void)value1; (void)value2; return FALSE;
}

BOOL ChxUtils::IsBitSet(UINT32 number, UINT32 bit) {
    return (number & bit) != 0;
}

UINT32 ChxUtils::AtomicLoadU32(volatile UINT32* pVar) {
    return __atomic_load_n(pVar, __ATOMIC_ACQUIRE);
}

VOID ChxUtils::AtomicStoreU32(volatile UINT32* pVar, UINT32 val) {
    __atomic_store_n(pVar, val, __ATOMIC_RELEASE);
}

CDKResult ChxUtils::ThreadCreate(OSThreadFunc threadEntryFunction, VOID* pThreadData, OSThreadHandle* phThread) {
    (void)threadEntryFunction; (void)pThreadData; (void)phThread;
    return CDKResultSuccess;
}

VOID ChxUtils::ThreadTerminate(OSThreadHandle hThread) {
    (void)hThread;
}

OSLIBRARYHANDLE ChxUtils::LibMap(const CHAR* pLibraryName) {
    const char* path = pLibraryName;
    if (pLibraryName &&
        (strstr(pLibraryName, "camera.qcom") || strstr(pLibraryName, "camera_qcom")))
    {
        path = "./lib/libcamera_qcom.so";
    }
    void* handle = dlopen(path, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "ChxUtils::LibMap: dlopen(%s) failed: %s\n", path, dlerror());
    }
    return handle;
}

VOID* ChxUtils::LibGetAddr(OSLIBRARYHANDLE hLibrary, const CHAR* pProcName) {
    if (!hLibrary || !pProcName) return nullptr;
    return dlsym(hLibrary, pProcName);
}

VOID* ChxUtils::MemMap(INT fd, SIZE_T length, SIZE_T offset) {
    (void)fd; (void)length; (void)offset;
    return nullptr;
}

INT ChxUtils::MemUnmap(VOID* pAddr, SIZE_T length) {
    (void)pAddr; (void)length;
    return 0;
}

const CHAR* ChxUtils::GetFileName(const CHAR* pFilePath) {
    return pFilePath;
}

UINT32 ChxUtils::AlignGeneric32(UINT32 operand, UINT alignment) {
    return (operand + alignment - 1) & ~(alignment - 1);
}

UINT32 ChxUtils::EvenCeilingUINT32(UINT32 input) {
    return (input + 1) & ~1U;
}

VOID ChxUtils::FillDefaultTuningMetadata(ChiMetadata* pMetaData, ChiModeUsecaseSubModeType usecaseMode, UINT32 modeIndex) {
    (void)pMetaData; (void)usecaseMode; (void)modeIndex;
}

// FillTuningModeData (ChiModeUsecaseSubModeType overload, not inline in chxutils.h)
VOID ChxUtils::FillTuningModeData(ChiMetadata* pMetaData, ChiModeUsecaseSubModeType usecaseMode, UINT32 sensorModeIndex,
    UINT32* pEffectModeValue, UINT32* pSceneModeValue, UINT32* pFeature1Value, UINT32* pFeature2Value) {
    (void)pMetaData; (void)usecaseMode; (void)sensorModeIndex;
    if (pEffectModeValue) *pEffectModeValue = 0;
    if (pSceneModeValue) *pSceneModeValue = 0;
    if (pFeature1Value) *pFeature1Value = 0;
    if (pFeature2Value) *pFeature2Value = 0;
}

ChiModeUsecaseSubModeType ChxUtils::GetUsecaseMode(camera3_capture_request_t* pRequest) {
    (void)pRequest;
    return ChiModeUsecaseSubModeType::Preview;
}

UINT32 ChxUtils::GetCameraIdFromStream(ChiStream* pStream) {
    (void)pStream;
    return 0;
}

VOID ChxUtils::UpdateTimeStamp(ChiMetadata* pMetadata, UINT64 timestamp, UINT32 frameNum) {
    (void)pMetadata; (void)timestamp; (void)frameNum;
}

CDKResult ChxUtils::SetVendorTagValue(ChiMetadata* pMetadata, VendorTag tag, UINT dataCount, VOID* ppData) {
    (void)pMetadata; (void)tag; (void)dataCount; (void)ppData;
    return CDKResultSuccess;
}

VOID ChxUtils::GetVendorTagValue(ChiMetadata* pMetadata, VendorTag tag, VOID** ppData) {
    (void)pMetadata; (void)tag;
    *ppData = nullptr;
}

BOOL ChxUtils::IsVendorTagPresent(ChiMetadata* pMetadata, VendorTag tag) {
    (void)pMetadata; (void)tag;
    return FALSE;
}

VOID ChxUtils::PopulateHALToChiStreamBuffer(const camera3_stream_buffer_t* pCamera3StreamBuffer, CHISTREAMBUFFER* pChiStreamBuffer) {
    (void)pCamera3StreamBuffer; (void)pChiStreamBuffer;
}

VOID ChxUtils::PopulateChiToHALStreamBuffer(const CHISTREAMBUFFER* pChiStreamBuffer, camera3_stream_buffer_t* pCamera3StreamBuffer) {
    (void)pChiStreamBuffer; (void)pCamera3StreamBuffer;
}

VOID ChxUtils::SkipFrame(camera3_stream_buffer_t* pBuffer) {
    (void)pBuffer;
}

CDKResult ChxUtils::DebugDataAllocBuffer(DebugData* pDebugData) {
    (void)pDebugData;
    return CDKResultSuccess;
}

VOID ChxUtils::DeepCopyCamera3CaptureRequest(const camera3_capture_request_t* pSrcReq, camera3_capture_request_t* pDestReq) {
    (void)pSrcReq; (void)pDestReq;
}

CDKResult ChxUtils::UpdateMetadataWithInputSettings(ChiMetadata& rInputMetadata, ChiMetadata& rOutputMetadata) {
    (void)rInputMetadata; (void)rOutputMetadata;
    return CDKResultSuccess;
}

CDKResult ChxUtils::UpdateMetadataWithSnapshotSettings(ChiMetadata& rMetadata) {
    (void)rMetadata;
    return CDKResultSuccess;
}

// ── ChxUtils::AndroidMetadata ──

BOOL ChxUtils::AndroidMetadata::IsVendorTagPresent(const VOID* pMetadata, VendorTag tag) {
    (void)pMetadata; (void)tag;
    return FALSE;
}

VOID ChxUtils::AndroidMetadata::GetVendorTagValue(const VOID* pMetadata, VendorTag tag, VOID** ppData) {
    (void)pMetadata; (void)tag;
    *ppData = nullptr;
}

CDKResult ChxUtils::AndroidMetadata::SetVendorTagValue(VOID* pMetadata, VendorTag tag, UINT dataCount, VOID* ppData) {
    (void)pMetadata; (void)tag; (void)dataCount; (void)ppData;
    return CDKResultSuccess;
}

// ══════════════════════════════════════════════════════════════════════════
// ExtensionModule
// ══════════════════════════════════════════════════════════════════════════

ExtensionModule* ExtensionModule::GetInstance() {
    static ExtensionModule instance;
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
    (void)pSubmitRequestData;
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

const LogicalCameraInfo* ExtensionModule::GetPhysicalCameraInfo(UINT32 physicalCameraId) const {
    (void)physicalCameraId;
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
UINT ExtensionModule::GetUsecaseMaxFPS() { return 30; }
UINT32 ExtensionModule::GetMaxHalRequests() { return 4; }
BOOL ExtensionModule::Enable3ADebugData() { return FALSE; }
BOOL ExtensionModule::EnableTuningMetadata() { return FALSE; }

// ══════════════════════════════════════════════════════════════════════════
// ChiMetadataManager
// ══════════════════════════════════════════════════════════════════════════

ChiMetadataManager* ChiMetadataManager::Create(UINT32 inputFps) {
    (void)inputFps;
    return nullptr;
}

ChiMetadataManager::~ChiMetadataManager() {}

VOID ChiMetadataManager::Destroy() {
    delete this;
}

ChiMetadata* ChiMetadataManager::Get(UINT32 clientId, UINT32 frameNumber) {
    (void)clientId; (void)frameNumber;
    return nullptr;
}

ChiMetadata* ChiMetadataManager::GetInput(const camera_metadata_t* pFrameworkInput, UINT32 frameNumber, bool bUseSticky, bool bReuseBuffers) {
    (void)pFrameworkInput; (void)frameNumber; (void)bUseSticky; (void)bReuseBuffers;
    return nullptr;
}

CDKResult ChiMetadataManager::Release(ChiMetadata* pMetadata) {
    (void)pMetadata;
    return CDKResultSuccess;
}

UINT32 ChiMetadataManager::RegisterClient(BOOL isExclusive, UINT32* pTagList, UINT32 tagCount, UINT32 partialTagCount, UINT32 bufferCount, ChiMetadataUsage usage) {
    (void)isExclusive; (void)pTagList; (void)tagCount; (void)partialTagCount; (void)bufferCount; (void)usage;
    return 1;
}

CDKResult ChiMetadataManager::UnregisterClient(UINT32 clientId) {
    (void)clientId;
    return CDKResultSuccess;
}

ChiMetadata* ChiMetadataManager::GetMetadataFromHandle(CHIMETADATAHANDLE hMetaHandle) {
    (void)hMetaHandle;
    return nullptr;
}

CDKResult ChiMetadataManager::InitializeFrameworkInputClient(UINT32 bufferCount, bool bSupportMultipleInputs) {
    (void)bufferCount; (void)bSupportMultipleInputs;
    return CDKResultSuccess;
}

// Nested class destructors
ChiMetadataManager::AndroidMetadataHolder::AndroidMetadataHolder() {}
ChiMetadataManager::AndroidMetadataHolder::~AndroidMetadataHolder() {}
ChiMetadataManager::MetaClient::~MetaClient() {}

// ══════════════════════════════════════════════════════════════════════════
// ChiMetadata
// ══════════════════════════════════════════════════════════════════════════

ChiMetadata* ChiMetadata::Create(const UINT32* pTagList, UINT32 tagCount, bool useDefaultFrameworkKeys, ChiMetadataManager* pManager) {
    (void)pTagList; (void)tagCount; (void)useDefaultFrameworkKeys; (void)pManager;
    return new ChiMetadata();
}

ChiMetadata* ChiMetadata::Create(const CHAR* pMetadataFileName) {
    (void)pMetadataFileName;
    return new ChiMetadata();
}

CDKResult ChiMetadata::Destroy(bool force) {
    (void)force;
    delete this;
    return CDKResultSuccess;
}

CDKResult ChiMetadata::SetTag(UINT32 tagID, const VOID* pData, UINT32 count) {
    (void)tagID; (void)pData; (void)count;
    return CDKResultSuccess;
}

CDKResult ChiMetadata::SetTag(const CHAR* pTagSectionName, const CHAR* pTagName, const VOID* pData, UINT32 count) {
    (void)pTagSectionName; (void)pTagName; (void)pData; (void)count;
    return CDKResultSuccess;
}

VOID* ChiMetadata::GetTag(UINT32 tagID) {
    (void)tagID;
    return nullptr;
}

VOID* ChiMetadata::GetTag(const CHAR* pTagSectionName, const CHAR* pTagName) {
    (void)pTagSectionName; (void)pTagName;
    return nullptr;
}

CDKResult ChiMetadata::Copy(ChiMetadata& srcMetadata, bool disjoint) {
    (void)srcMetadata; (void)disjoint;
    return CDKResultSuccess;
}

CDKResult ChiMetadata::Merge(ChiMetadata& srcMetadata, bool disjoint) {
    (void)srcMetadata; (void)disjoint;
    return CDKResultSuccess;
}

CDKResult ChiMetadata::FindTag(uint32_t tag, camera_metadata_entry_t* pEntry) {
    (void)tag; (void)pEntry;
    return CDKResultENoSuch;
}

CDKResult ChiMetadata::SetAndroidMetadata(const camera_metadata_t* pCameraMetadata) {
    (void)pCameraMetadata;
    return CDKResultSuccess;
}

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
    return CDKResultSuccess;
}

const CHIPIPELINEINFO Pipeline::GetPipelineInfo() const {
    CHIPIPELINEINFO info = {};
    return info;
}

VOID Pipeline::SetOutputBuffers(UINT numOutputs, CHIPORTBUFFERDESCRIPTOR* pOutputs) {
    (void)numOutputs; (void)pOutputs;
}

VOID Pipeline::SetInputBuffers(UINT numInputs, CHIPORTBUFFERDESCRIPTOR* pInputs) {
    (void)numInputs; (void)pInputs;
}

// Inline methods that need out-of-line definitions:
ChiMetadata* Pipeline::GetDescriptorMetadata() { return nullptr; }
CHIPIPELINEDESCRIPTOR Pipeline::GetPipelineHandle() const { return (CHIPIPELINEDESCRIPTOR)this; }
UINT Pipeline::GetMetadataClientId() const { return 0; }
const CHAR* Pipeline::GetPipelineName() const { return "stub"; }
UINT32* Pipeline::GetTagList() { return nullptr; }
UINT32 Pipeline::GetTagCount() { return 0; }
UINT32 Pipeline::GetPartialTagCount() { return 0; }
CHISENSORMODEINFO* Pipeline::GetSensorModeInfo() { return nullptr; }
BOOL Pipeline::IsRealTime() const { return FALSE; }
VOID Pipeline::SetPipelineActivateFlag() {}
VOID Pipeline::SetMetadataClientId(UINT clientId) { (void)clientId; }
VOID Pipeline::SetDeferFinalizeFlag(BOOL isDeferFinalizeNeeded) { (void)isDeferFinalizeNeeded; }
VOID Pipeline::SetPipelineNodePorts(const CHIPIPELINECREATEDESCRIPTOR* pCreateDesc) { (void)pCreateDesc; }
VOID Pipeline::SetPipelineName(const CHAR* const pPipelineName) { (void)pPipelineName; }
VOID Pipeline::SetSensorModePickHint(const CHISENSORMODEPICKHINT* pSensorModePickHint) { (void)pSensorModePickHint; }

// ══════════════════════════════════════════════════════════════════════════
// Session
// ══════════════════════════════════════════════════════════════════════════

Session* Session::Create(Pipeline** ppPipelines, UINT32 numPipelines, CHICALLBACKS* pCallbacks, VOID* pPrivateData) {
    (void)ppPipelines; (void)numPipelines; (void)pCallbacks; (void)pPrivateData;
    return new Session();
}

VOID Session::Destroy(BOOL isForced) {
    (void)isForced;
    delete this;
}

CHIPIPELINEDESCRIPTOR Session::GetPipelineHandle(UINT index) const { (void)index; return nullptr; }
CHISENSORMODEINFO* Session::GetSensorModeInfo(UINT index) const { (void)index; return nullptr; }
CHIHANDLE Session::GetSessionHandle() const { return nullptr; }
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
// Mutex
// ══════════════════════════════════════════════════════════════════════════

Mutex* Mutex::Create() {
    Mutex* m = new Mutex();
    return m;
}

VOID Mutex::Destroy() { delete this; }
VOID Mutex::Lock() {}
VOID Mutex::Unlock() {}
OSMutexHandle* Mutex::GetNativeHandle() { return nullptr; }

// ══════════════════════════════════════════════════════════════════════════
// Condition
// ══════════════════════════════════════════════════════════════════════════

Condition* Condition::Create() {
    Condition* c = new Condition();
    return c;
}

VOID Condition::Destroy() { delete this; }
CDKResult Condition::Wait(OSMutexHandle* phMutex) { (void)phMutex; return CDKResultSuccess; }
CDKResult Condition::TimedWait(OSMutexHandle* phMutex, UINT timeoutMilliseconds) {
    (void)phMutex; (void)timeoutMilliseconds;
    return CDKResultSuccess;
}
VOID Condition::Signal() {}

// ══════════════════════════════════════════════════════════════════════════
// Semaphore
// ══════════════════════════════════════════════════════════════════════════

Semaphore* Semaphore::Create(INT count) {
    (void)count;
    Semaphore* s = new Semaphore();
    return s;
}

VOID Semaphore::Destroy() { delete this; }
VOID Semaphore::NotifyAllThreads() {}
VOID Semaphore::Reset() {}
VOID Semaphore::WaitForSemaphore() {}

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

extern const ChiFeature2Descriptor Bayer2YuvFeatureDescriptor = {};
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
