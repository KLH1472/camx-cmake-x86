#ifndef CHXMULTICAMCONTROLLER_H
#define CHXMULTICAMCONTROLLER_H

#include "chiframework_types.h"

class ChiMetadata;

// ── MultiCamController base ──
class MultiCamController
{
public:
    static CDKResult ConsolidateCameraInfo(LogicalCameraInfo* pLogicalCameraInfo);

    virtual CDKResult Reconfigure(struct MccCreateData* pMccCreateData);
    virtual CDKResult TranslateRequestSettings(struct MulticamReqSettings* pMultiCamSettings);
    virtual VOID TranslateFaceResultMetadata(VOID* pResultMetadata);
    virtual VOID TranslateTrackingResultRegions(VOID* pResultMetadata);
    virtual VOID TranslateResultMetadata(camera_metadata_t* pResultMetadata);
    virtual VOID ProcessResultMetadata(ChiMetadata* pResultMetadata);
    virtual VOID Destroy() = 0;
    virtual struct ControllerResult GetResult(ChiMetadata* pMetadata);
    virtual VOID UpdateResults(ChiMetadata* pMetadata);
    virtual VOID SetParam(VOID* pData);
    virtual VOID GetParam(VOID* pOutData);
    virtual CDKResult FillOfflinePipelineInputMetadata(struct MulticamResultMetadata* pMultiCamResultMetadata,
        ChiMetadata* pOfflineMetadata, BOOL isSnapshotPipeline);
    virtual VOID UpdateVendorTags(MulticamReqSettings* pMultiCamSettings);
    virtual VOID UpdateScalerCropForSnapshot(ChiMetadata* pMetadata);

    VOID ExtractCameraMetadata(ChiMetadata* pResultMetadata, struct CameraMetadata* pExtractedCameraMetadata);
    VOID PrepareAndSetParam(UINT32 numSetParam, struct MCCSetParam* pParamDataList);
    VOID PrepareAndGetParam(UINT32 numQueryParam, struct MCCGetParamInput* pQueryList,
        struct MCCGetParamOutput* pOutputList);

protected:
    MultiCamController() {}
    virtual ~MultiCamController() {}
};

// ── MultiCamControllerManager ──
class MultiCamControllerManager
{
public:
    static MultiCamControllerManager* GetInstance();
    MultiCamController* GetController(struct MccCreateData* pMccCreateData);
    VOID DestroyController(MultiCamController* pMultiCamController);
    VOID Destroy();
};

#endif // CHXMULTICAMCONTROLLER_H
