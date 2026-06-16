#ifndef CHXEXTENSIONMODULE_H
#define CHXEXTENSIONMODULE_H

#include "chiframework_types.h"

// Forward declarations
class ExtensionModule;
struct PipelineCreateData;
struct SessionCreateData;

// ── ExtensionModule base class ──
class ExtensionModule
{
public:
    static ExtensionModule* GetInstance();

    // Key methods
    const LogicalCameraInfo* GetCameraInfo(uint32_t logicalCameraId) const;
    INT32 GetPlatformID();
    UINT32 GetCameraIdIndex(UINT32 logicalCameraId) const;
    UINT32 GetPrimaryCameraIndex(const LogicalCameraInfo* pLogicalCameraInfo);
    const LogicalCameraInfo* GetPhysicalCameraInfo(UINT32 physicalCameraId) const;
    CDKResult GetActiveArray(UINT32 cameraId, CHIRECT* pChiRect);
    CDKResult BuildLogicalCameraInfo(UINT32* sensorIdMap, BOOL isMultiCameraEnabled, BOOL isForExposed);

    CHIPIPELINEDESCRIPTOR CreatePipelineDescriptor(PipelineCreateData* pPipelineCreateData);
    VOID DestroyPipelineDescriptor(CHIPIPELINEDESCRIPTOR pipelineHandle);
    CHIHANDLE CreateSession(SessionCreateData* pSessionCreateData);
    VOID DestroySession(CHIHANDLE sessionHandle, BOOL isForced);
    CDKResult Flush(CHIHANDLE sessionHandle);
    CDKResult Flush(CHISESSIONFLUSHINFO hSessionFlushinfo);
    CDKResult SubmitRequest(CHIPIPELINEREQUEST* pSubmitRequestData);
    CDKResult ActivatePipeline(CHIHANDLE sessionHandle, CHIPIPELINEDESCRIPTOR pipelineHandle);
    CDKResult DeactivatePipeline(CHIHANDLE sessionHandle, CHIPIPELINEDESCRIPTOR pipelineHandle, CHIDEACTIVATEPIPELINEMODE mode);

    CDKResult CreateChiFence(CHIFENCECREATEPARAMS* pInfo, CHIFENCEHANDLE* phChiFence);
    CDKResult ReleaseChiFence(CHIFENCEHANDLE hChiFence);
    CDKResult WaitChiFenceAsync(PFNCHIFENCECALLBACK pCallbackFn, CHIFENCEHANDLE hChiFence, VOID* pData);
    CDKResult SignalChiFence(CHIFENCEHANDLE hChiFence, CDKResult statusResult);
    CDKResult GetChiFenceStatus(CHIFENCEHANDLE hChiFence, CDKResult* pFenceResult);
    CDKResult QueryPipelineMetadataInfo(CHIHANDLE sessionHandle, CHIPIPELINEDESCRIPTOR pipelineHandle, CHIPIPELINEMETADATAINFO* pPipelineMetadataInfo);

    UINT32 RemapCameraId(UINT32 frameworkCameraId, CameraIdRemapMode mode);

    VOID GetNumCameras(UINT32* pNumFwCameras, UINT32* pNumLogicalCameras);
    CDKResult GetCameraInfo(uint32_t logicalCameraId, camera_info* cameraInfo);
    CDKResult ExtendOpen(uint32_t logicalCameraId, VOID* pPriv);
    VOID ExtendClose(uint32_t logicalCameraId, VOID* pPriv);
    VOID ModifySettings(VOID* pPriv);

    VOID SetHALOps(const chi_hal_ops_t* pHalOps);
    const chi_hal_ops_t* GetHalOps() const;
    VOID SetCHIContextOps();

    CDKResult OverrideFlush(const camera3_device_t* camera3_device);
    CDKResult OverrideDump(const camera3_device_t* camera3_device, int fd);

    VOID ReturnFrameworkResult(const camera3_capture_result_t* pResult, UINT32 cameraID);
    VOID ReturnFrameworkMessage(const camera3_notify_msg_t* msg, UINT32 cameraID);

    UINT32 GetNumMetadataResults();
    UINT32 GetCameraIdfromDevice(const camera3_device_t* pCamera3Device);
    VOID DumpDebugData(UINT32 cameraID);

    // Dump debug data
    BOOL DumpDebugDataPerSnapshot;
    EnableDumpDebugDataType EnableDumpDebugData();
    BOOL Enable3ADebugData();
    BOOL EnableTuningMetadata();

    VOID GetVendorTagOps(CHITAGSOPS* pVendorTagOps);
    VOID GetMetadataOps(CHIMETADATAOPS* pMetadataOps);

    // Config settings
    BOOL DisableZSL();
    BOOL OverrideUseCase();
    BOOL UseGPURotationUsecase();
    BOOL UseGPUDownscaleUsecase();
    BOOL EnableMFNRUsecase();
    BOOL EnableMFSRUsecase();
    BOOL EnableHFRNo3AUsecas();
    BOOL EnableUnifiedBufferManager();
    BOOL EnableCHILateBinding();
    BOOL EnableFDStreamSupport();
    BOOL EnableRawHDRSnapshot();
    BOOL EnableMultiCameraJPEG();
    BOOL EnableFeature2Dump();
    BOOL EnableEISV2Usecase();
    BOOL EnableEISV3Usecase();
    BOOL UseFeatureForQuadCFA();
    UINT32 GetAdvanceFeatureMask();
    BOOL EnableBLMClient();
    BOOL IsSWMFEnabled();
    BOOL DisableASDProcessing();
    BOOL EnableFOVCUseCase();
    BOOL EnableCHIPartialData();
    BOOL EnableOfflineNoiseReprocessing();
    BOOL EnableTBMChiFence();
    BOOL EnableMFSRChiFence();

    UINT GetUsecaseMaxFPS();
    UINT GetPreviewFPS();
    UINT GetVideoFPS();
    UINT32 GetForceSensorMode();
    UINT32 GetDCVRMode();
    UINT32 GetStatsSkipPattern();
    UINT32 GetMaxHalRequests();
    UINT32 GetOutputFormat();

    SELECTINSENSORHDRU3EXPSECASE GetSelectInSensorHDR3ExpUsecase();

    VOID SearchNumBatchedFrames(uint32_t cameraId, camera3_stream_configuration_t* pStreamConfigs,
        UINT* pBatchSize, BOOL* pHALOutputBufferCombined, UINT* pFPSValue, UINT maxSessionFps);

    UINT GetNumBatchedFrames();
    BOOL GetHALOutputBufferCombined();
    UINT32 GetOpMode(UINT32 cameraId);
    BOOL IsSystemLogEnabled();

    UINT GetNumberOfLogicalConfig() const;
    const LogicalCameraInfo* GetAllLogicalCameraInfo() const;

    // Physical camera sensor modes
    CDKResult EnumerateSensorModes(UINT32 physCameraId, UINT32 numSensorModes, CHISENSORMODEINFO* pSensorModeInfo);
    CDKResult GetPhysicalCameraSensorModes(UINT32 physicalCameraId, UINT32* pNumSensorModes, CHISENSORMODEINFO** ppAllSensorModes);

    // Static callbacks
    static VOID* RecoveryThread(VOID* pThreadData);
    static VOID* OfflineLoggerASCIIThread(VOID* pThreadData);
    static VOID* OfflineLoggerBinaryThread(VOID* pThreadData);

protected:
    ExtensionModule() {}
    virtual ~ExtensionModule() {}
};

// ── PipelineCreateData ──
struct PipelineCreateData
{
    const CHAR*                     pPipelineName;
    const CHIPIPELINECREATEDESCRIPTOR* pPipelineCreateDescriptor;
    UINT32                          numOutputs;
    CHIPORTBUFFERDESCRIPTOR*        pOutputDescriptors;
    UINT32                          numInputs;
    CHIPIPELINEINPUTOPTIONS*        pInputOptions;
};

// ── SessionCreateData ──
struct SessionCreateData
{
    UINT32              numPipelines;
    CHIPIPELINEINFO*    pPipelineInfo;
    CHICALLBACKS*       pCallbacks;
    VOID*               pPrivateCallbackData;
    CHISESSIONFLAGS     flags;
};

#endif // CHXEXTENSIONMODULE_H
