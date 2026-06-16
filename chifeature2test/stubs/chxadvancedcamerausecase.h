#ifndef CHXADVANCEDCAMERAUSECASE_H
#define CHXADVANCEDCAMERAUSECASE_H

#include "chiframework_types.h"

// ── Constants from this header ──
#ifndef MaxRealTimePipelines
#define MaxRealTimePipelines 8
#endif
#ifndef MaxFeaturesPerSnapshot
#define MaxFeaturesPerSnapshot 2
#endif
#ifndef MaxNumOfTargets
#define MaxNumOfTargets 97
#endif

// ── Forward declarations ──
class Usecase;
class Feature;
class ChiMetadata;
class CHIBufferManager;
class Mutex;
class Condition;
class Session;
class Pipeline;
class AdvancedCameraUsecase;

// ── Structs ──
struct SessionPipelines {
    UINT pipelineId[16];
    UINT numPipelines;
};

struct FeatureInputInfo {
    BOOL   valid;
    UINT32 inputBufferQIdx;
    UINT32 numOfInputBuffers;
    UINT32 lastSeqId;
    UINT32 sensorModeIndex;
};

struct FeatureOutputInfo {
    BOOL       valid;
    UINT32     NumOfOutputTargets;
    UINT32     outputTargetIndex[16];
    CHISTREAM* outputStreams[16];
};

struct PipelineData {
    UINT        id;
    Pipeline*   pPipeline;
    CHISTREAM*  pStreams[16];
    UINT        numStreams;
    UINT        seqId;
    UINT        seqIdToFrameNum[128];
    BOOL        isHALInputStream;
};

struct SessionData {
    Session*     pSession;
    UINT32       numPipelines;
    UINT32       rtPipelineIndex;
    PipelineData pipelines[16];
};

struct SessionPrivateData {
    Usecase*  pUsecase;
    UINT32    sessionId;
};

struct TargetBufferInfo {
    UINT32             frameNumber;
    ChiMetadata*       pMetadata;
    VOID*              pDebugData;
    CHISTREAMBUFFER*   pRdiOutputBuffer;
    BOOL               isBufferReady;
    BOOL               isMetadataReady;
};

struct TargetBuffer {
    TargetBufferInfo    bufferQueue[16];
    CHIBufferManager*   pBufferManager;
    Mutex*              pMutex;
    Condition*          pCondition;
    UINT32              lastReadySequenceID;
    UINT32              validBufferLength;
    UINT32              firstReadySequenceID;
    ChiStream*          pChiStream;
};

struct SnapshotFeatureInfo {
    Feature*          pFeature;
    FeatureInputInfo  featureInput;
    FeatureOutputInfo featureOutput;
};

// ── CameraUsecaseBase (base for AdvancedCameraUsecase) ──
class CameraUsecaseBase : public Usecase {
public:
    struct UsecaseInitializationData {};
    struct RequestInfo {};

    CDKResult CheckIfPartialDataCanBeSent(UINT32, BOOL, BOOL) { return CDKResultSuccess; }
    Mutex* GetAppResultMutex() { return nullptr; }
    CDKResult UpdateAppPartialResultMetadataFromDriver(ChiMetadata*, UINT, UINT32, UINT32) { return CDKResultSuccess; }

    UINT32 GetCameraId() { return 0; }
    UINT32 GetSessionId(UINT32) { return 0; }
    UINT32 GetPipelineId(UINT32, UINT32) { return 0; }
    PipelineData* GetPipelineData(UINT32) { return nullptr; }
    SessionData* GetSessionData(UINT32) { return nullptr; }
    TargetBuffer* GetTargetBufferPointer(UINT32, UINT32) { return nullptr; }
    CDKResult SetPipelineToSessionMapping(UINT32, UINT32) { return CDKResultSuccess; }
    ChiUsecase* GetChiUseCase() { return nullptr; }
    BOOL IsMultiCameraUsecase() { return FALSE; }
    CDKResult SetShutterTimestamp(UINT32, UINT64) { return CDKResultSuccess; }
    CDKResult InvalidateFrameNumber(UINT32) { return CDKResultSuccess; }
    CDKResult GetTargetBuffer(UINT32, VOID**) { return CDKResultSuccess; }
    CDKResult ProcessAndReturnFinishedResults() { return CDKResultSuccess; }
    CDKResult ProcessAndReturnFinishedResults(BOOL) { return CDKResultSuccess; }
    CDKResult ProcessFeatureDataNotify(int, class Feature2Wrapper*, UINT*) { return CDKResultSuccess; }
    CDKResult ProcessAndReturnPartialMetadataFinishedResults(PartialResultSender) { return CDKResultSuccess; }
    CHIMETADATAHANDLE GetAvialableResultMetadata() { return nullptr; }
    CDKResult CheckIfPartialDataCanBeSent(PartialResultSender&, UINT32&) { return CDKResultSuccess; }
    CDKResult GetFeature2InputFrame(UINT32& frameNum) { (void)frameNum; return CDKResultSuccess; }
    UINT32 GetPipelineIdFromCamId(UINT32) { return 0; }
    CDKResult GetInputBufferFromRDIQueue(UINT32&, UINT32&, UINT32&, CHISTREAMBUFFER*, ChiMetadata**, int) { return CDKResultSuccess; }
    CHIBufferManager* GetBufferManager(UINT32&) { return nullptr; }
    CDKResult GetInputBufferFromFDQueue(UINT32&, UINT32&, UINT32&, CHISTREAMBUFFER*, int) { return CDKResultSuccess; }
    CHIBufferManager* GetFDBufferManager(UINT32&) { return nullptr; }
    BOOL IsMetadataSent(UINT32&) { return FALSE; }
    CDKResult SetMetadataAvailable(UINT32) { return CDKResultSuccess; }
    CDKResult GetShutterTimestamp(UINT32 frameNum) { (void)frameNum; return CDKResultSuccess; }
    CDKResult ProcessFeatureDone(UINT32&, Feature*, CHICAPTURERESULT*&) { return CDKResultSuccess; }
    CDKResult UpdateValidRDIBufferLength(UINT32, UINT32) { return CDKResultSuccess; }
    CDKResult UpdateValidFDBufferLength(UINT32, UINT32) { return CDKResultSuccess; }
    CDKResult ReleaseReferenceToInputBuffers(CHIPRIVDATA*) { return CDKResultSuccess; }
    CDKResult SetSkipPreviewFlagInRequestMapInfo(UINT32, BOOL) { return CDKResultSuccess; }
    BOOL GetSkipPreviewFlagInRequestMapInfo(UINT32) { return FALSE; }
    operator ChiUsecase*() { return nullptr; }
};

// ── AdvancedCameraUsecase (main usecase class) ──
class AdvancedCameraUsecase : public CameraUsecaseBase {
public:
    enum SharedStreamType { PreviewStream, RdiStream, RdiStreamAux };
};

#endif // CHXADVANCEDCAMERAUSECASE_H
