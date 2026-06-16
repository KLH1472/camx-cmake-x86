#ifndef CHXUSECASE_H
#define CHXUSECASE_H

#include "chiframework_types.h"

// Forward declarations
class Session;
class Pipeline;
struct ChiUsecase;

// ── UsecaseRequestFlags ──
// Already defined in chiframework_types.h
enum FlushStatus { NotFlushing, IsFlushing, HasFlushed };

class Usecase
{
public:
    CDKResult ProcessCaptureRequest(camera3_capture_request_t* request);
    virtual VOID ResetMetadataStatus(camera3_capture_request_t*);
    VOID FlushRequestsByFrameNumber(BOOL bLock, UINT32 lastChiFrameNum = 0);
    CDKResult FlushAllSessions(Session* const* ppSession, const UINT32 size);
    CDKResult FlushAllSessionsInParallel(Session* const* ppSession, const UINT32 size);
    CDKResult ProcessCaptureResult(const CHICAPTURERESULT* pResult);
    CDKResult ProcessMessage(const CHIMESSAGEDESCRIPTOR* pMessageDescriptor);
    VOID ProcessErrorMessage(const CHIMESSAGEDESCRIPTOR* pMessageDescriptor);
    VOID DestroyObject(BOOL isForced);
    CDKResult UpdateSensorModeIndex(camera_metadata_t* pMetaData);
    CDKResult UpdateFeatureModeIndex(camera_metadata_t* pMetaData);
    VOID ReturnFrameworkResult(const camera3_capture_result_t* pResult, UINT32 cameraID);
    VOID ReturnFrameworkMessage(const camera3_notify_msg_t* pMessage, UINT32 cameraID);
    virtual VOID LogFeatureRequestMappings(UINT32 inFrameNum, UINT32 reqFrameNum, const CHAR* identifyingData);
    virtual CDKResult Flush();
    virtual CDKResult Dump(int fd);
    CDKResult CheckAndActivatePipeline(Session* pSession);
    camera3_capture_result_t* GetCaptureResult(UINT resultId);
    camera3_capture_result_t* GetDriverPartialCaptureResult(UINT resultId);
    camera3_capture_result_t* GetCHIPartialCaptureResult(UINT resultId);
    UINT GetCameraId();
    UsecaseId GetUsecaseId();
    FlushStatus GetFlushStatus();
    CDKResult MetadataCaptureRequestUpdate(CHICAPTUREREQUEST& captureRequest, UINT32 sessionId, bool isInputSticky = true);
    CDKResult MetadataCaptureResultGet(ChiCaptureResult& captureResult, UINT32 sessionId);
    VOID MetadataCaptureResultRelease(const VOID* pAndroidMetadata);
    CDKResult UpdateAppResultMetadata(ChiMetadata* pChiMetadata, UINT resultId, UINT32 clientId);
    CDKResult CreateMetadataManager(INT32 cameraId = 0, bool initFrameworkMetadata = true,
        Pipeline* pDefaultPipeline = NULL, bool initGenericMeta = true);
    VOID PrepareForRecovery();
    VOID IsReprocessUsecase(BOOL isReprocess);
    VOID DeleteAllPendingResults();
    VOID WaitUntilFlushFinishes();
    BOOL IsUsecaseInBadState();
    VOID SetUsecaseInBadState(BOOL isUsecaseInBadState);
    CDKResult SubmitRequestMC(CHIPIPELINEREQUEST* pSubmitRequestData);
    CDKResult SubmitRequest(CHIPIPELINEREQUEST* pSubmitRequestData);
    UINT32 GetGenericMetadataClientId();

    static VOID* RecoveryThread(VOID* pArg);

protected:
    Usecase() {}
    virtual ~Usecase() {}
};

// Forward declarations of internal usecase types
struct PipelineData;
struct SessionData;
struct SessionPrivateData;
struct TargetBufferInfo;
struct TargetBuffer;
struct ChiMetadataBundle;

#endif // CHXUSECASE_H
