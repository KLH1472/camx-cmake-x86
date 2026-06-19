#ifndef CHXSESSION_H
#define CHXSESSION_H

#include "chiframework_types.h"

// Forward declarations
class Pipeline;

class Session
{
public:
    static Session* Create(Pipeline** ppPipelines, UINT32 numPipelines,
        ChiCallBacks* pCallbacks, VOID* pPrivateData);

    VOID Destroy(BOOL isForced);
    CHIPIPELINEDESCRIPTOR GetPipelineHandle(UINT index = 0) const;
    UINT GetMetadataClientId(UINT index = 0) const;
    CHIHANDLE GetSessionHandle() const;
    CDKResult Finalize();
    UINT32 GetPipelineIndex(UINT32 cameraId);
    UINT32 GetPipelineIndex(CHIPIPELINEHANDLE pipelineHandle);
    UINT32 GetCameraId(UINT32 pipelineIndex);
    VOID SetPipelineActivateFlag(UINT index = 0) const;
    VOID SetPipelineDeactivate(UINT index = 0) const;
    BOOL IsPipelineActive(UINT index = 0) const;
    CHISENSORMODEINFO* GetSensorModeInfo(UINT index = 0) const;
    Pipeline* GetSCRealTimePipeline() const;

    CHIHANDLE m_hSession = nullptr;

protected:
    Session() {}
    virtual ~Session() {}
};

#endif // CHXSESSION_H
