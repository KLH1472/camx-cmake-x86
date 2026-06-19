#ifndef CHXPIPELINE_H
#define CHXPIPELINE_H

#include "chiframework_types.h"

// Forward declarations
class ExtensionModule;
class ChiMetadata;

typedef enum
{
    Invalid             = 0,
    RealtimePreview     = 1,
    RealtimeZSL         = 2,
    OfflineZSLYUV       = 3,
    OfflineZSLJPEG      = 4,
    Default             = 5,
    MFNRPrefilter       = 6,
    MFNRBlend           = 7,
    MFNRPostfilter      = 8,
    MFNRScale           = 9,
    OfflineYUVJPEG      = 10,
    OfflineCustom       = 11,
    OfflinePreview      = 12,
    MFSRPrefilter       = 13,
    MFSRBlend           = 14,
    MFSRPostfilter      = 15,
    MaxPipelineTypes    = 16,
} PipelineType;

class Pipeline
{
public:
    static Pipeline* Create(UINT32 cameraId, PipelineType type, const CHAR* pName = NULL);
    static BOOL HasSensorNode(const ChiPipelineCreateDescriptor* pCreateDesc);

    VOID Destroy();
    VOID SetOutputBuffers(UINT numOutputs, CHIPORTBUFFERDESCRIPTOR* pOutputs);
    VOID SetInputBuffers(UINT numInputs, CHIPORTBUFFERDESCRIPTOR* pInputs);
    CDKResult SetPreviewStream(CHISTREAM* pStream);
    CDKResult SetRDIStream(CHISTREAM* pStream);
    CDKResult SetSnapshotStream(CHISTREAM* pStream);
    CDKResult SetOutputStream(CHISTREAM* pStream);
    CDKResult SetInputStream(CHISTREAM* pStream);
    VOID SetPipelineActivateFlag();
    VOID SetPipelineDeactivate();
    VOID SetMetadataClientId(UINT clientId);
    CHIPIPELINEDESCRIPTOR GetPipelineHandle() const;
    CHIPORTBUFFERDESCRIPTOR* GetInputBufferDescriptors();
    UINT GetMetadataClientId() const;
    VOID SetPipelineNodePorts(const CHIPIPELINECREATEDESCRIPTOR* pCreateDesc);
    VOID SetPipelineName(const CHAR* const pPipelineName);
    VOID SetPipelineNameF(const CHAR* const pPipelineName, UINT instanceId);
    const CHAR* GetPipelineName() const;
    VOID SetSensorModePickHint(const CHISENSORMODEPICKHINT* pSensorModePickHint);
    CDKResult SetAndroidMetadata(camera3_stream_configuration* pStreamConfig);
    CDKResult SetVendorTag(UINT32 tagID, const VOID* pData, UINT32 count);
    VOID SetPipelineResourcePolicy(CHIRESOURCEPOLICY policy);
    CHIRESOURCEPOLICY GetPipelineResourcePolicy() const;
    VOID SetDeferFinalizeFlag(BOOL isDeferFinalizeNeeded);
    BOOL GetDeferFinalizeFlag() const;
    CHIPIPELINEINPUTOPTIONS* GetInputOptions();
    BOOL IsPipelineActive() const;
    BOOL IsRealTime() const;
    BOOL IsOffline();
    UINT32* GetTagList();
    UINT32 GetTagCount();
    UINT32 GetPartialTagCount();
    UINT32 GetMetadataBufferCount();
    ChiMetadata* GetDescriptorMetadata();
    CDKResult QueryMetadataTags(CHIHANDLE hSession);
    CDKResult CreateDescriptor();
    const CHIPIPELINEINFO GetPipelineInfo() const;
    VOID SetTuningUsecase();
    CHISENSORMODEINFO* GetSensorModeInfo();
    UINT32 GetCameraId();
    INT32 GetNumberOfIFEsUsed();

protected:
    Pipeline() : m_pCreateDesc(NULL), m_pName(NULL), m_numOutputs(0),
                 m_numInputBuffers(0), m_numInputs(0), m_hDescriptor(NULL) {}
    virtual ~Pipeline() {}

private:
    const CHIPIPELINECREATEDESCRIPTOR* m_pCreateDesc;
    const CHAR*                        m_pName;
    UINT                               m_numOutputs;
    CHIPORTBUFFERDESCRIPTOR            m_pOutputs[16];
    UINT                               m_numInputBuffers;
    CHIPORTBUFFERDESCRIPTOR            m_pInputBuffers[16];
    UINT                               m_numInputs;
    CHIPIPELINEINPUTOPTIONS            m_pInputOptions[16];
    CHIPIPELINEDESCRIPTOR              m_hDescriptor;
};

#endif // CHXPIPELINE_H
