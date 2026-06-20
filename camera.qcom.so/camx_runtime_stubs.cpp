#include "camxincs.h"
#include "camxsensorproperty.h"
#include "camxsensordriver.h"
#include "camxeepromdriver.h"
#include "camximageformatutils.h"
#include "camximagesensormoduledata.h"
#include "camximagesensordata.h"
#include "camxeebindata.h"
#include "camxhwenvironment.h"
#include "camxthermalmanager.h"
#include "camxhal3defaultrequest.h"
#include "camxhal3metadatatags.h"
#include "camxcustomization.h"
#include "camxdisplayconfig.h"
#include "camxhal3.h"

#include "camxhwcontext.h"
#include "camxmetabuffer.h"

#include <cstdio>
#include <unistd.h>

CAMX_NAMESPACE_BEGIN

class DummyHwContext final : public HwContext
{
public:
    DummyHwContext() = default;
    virtual ~DummyHwContext() override = default;
    virtual BOOL IsNodeTypeSinkNoBuffer(UINT nodeType) const override
    {
        CAMX_UNREFERENCED_PARAM(nodeType);
        return FALSE;
    }
    virtual StatsParser* GetStatsParser() override { return NULL; }
};

// ── ImageFormatUtils ──

SIZE_T ImageFormatUtils::GetPlaneSize(const ImageFormat* pFormat, UINT planeIndex)
{
    if (pFormat == NULL) return 0;
    UINT w = pFormat->width;
    UINT h = pFormat->height;
    if (planeIndex == 0) return static_cast<SIZE_T>(w) * h;
    if (planeIndex == 1) return static_cast<SIZE_T>(w) * h / 2;
    return 0;
}

SIZE_T ImageFormatUtils::GetTotalSize(const ImageFormat* pFormat)
{
    if (pFormat == NULL) return 0;
    SIZE_T total = 0;
    UINT planes = GetNumberOfPlanes(pFormat);
    for (UINT i = 0; i < planes; i++) total += GetPlaneSize(pFormat, i);
    return total;
}

UINT ImageFormatUtils::GetNumberOfPlanes(const ImageFormat* pFormat)
{
    if (pFormat == NULL) return 0;
    switch (pFormat->format)
    {
        case Format::YUV420NV12:
        case Format::YUV420NV21:
        case Format::YUV420NV12TP10:
        case Format::YUV420NV21TP10:
        case Format::UBWCNV12:
        case Format::UBWCNV124R:
        case Format::UBWCTP10:
        case Format::P010:
            return 2;
        case Format::RawMIPI:
        case Format::RawPlain16:
        case Format::RawMeta8BIT:
        case Format::RawPlain64:
        case Format::RawMIPI8:
        case Format::Blob:
        case Format::Jpeg:
        case Format::Y8:
        case Format::Y16:
        case Format::PD10:
            return 1;
        default:
            return 1;
    }
}

BOOL ImageFormatUtils::IsYUV(const ImageFormat* pFormat)
{
    if (pFormat == NULL) return FALSE;
    switch (pFormat->format)
    {
        case Format::YUV420NV12:
        case Format::YUV420NV21:
        case Format::YUV420NV12TP10:
        case Format::YUV420NV21TP10:
        case Format::P010:
            return TRUE;
        default:
            return FALSE;
    }
}

BOOL ImageFormatUtils::IsRAW(const ImageFormat* pFormat)
{
    if (pFormat == NULL) return FALSE;
    switch (pFormat->format)
    {
        case Format::RawMIPI:
        case Format::RawPlain16:
        case Format::RawMeta8BIT:
        case Format::RawPlain64:
        case Format::RawMIPI8:
            return TRUE;
        default:
            return FALSE;
    }
}

BOOL ImageFormatUtils::IsUBWC(Format format)
{
    switch (format)
    {
        case Format::UBWCNV12:
        case Format::UBWCNV124R:
        case Format::UBWCTP10:
            return TRUE;
        default:
            return FALSE;
    }
}

BOOL ImageFormatUtils::Is10BitUBWCFormat(Format format)
{
    return (format == Format::UBWCTP10) ? TRUE : FALSE;
}

CamxResult ImageFormatUtils::GetFormat(GrallocProperties& rGrallocProperties, Format& rFormat)
{
    rFormat = Format::YUV420NV12;
    return CamxResultSuccess;
}

CamxResult ImageFormatUtils::ValidateBufferSize(VOID* phBufferHandle, UINT32 bufferSize)
{
    CAMX_UNREFERENCED_PARAM(phBufferHandle);
    CAMX_UNREFERENCED_PARAM(bufferSize);
    return CamxResultSuccess;
}

const UBWCTileInfo* ImageFormatUtils::GetUBWCTileInfo(const ImageFormat* pFormat)
{
    CAMX_UNREFERENCED_PARAM(pFormat);
    return NULL;
}

VOID ImageFormatUtils::GetUBWCPartialTileInfo(
    const UBWCTileInfo*  pTileInfo,
    UBWCPartialTileInfo* pUBWCPartialTileParam,
    UINT                 startOffsetPixel,
    UINT                 widthPixels)
{
    CAMX_UNREFERENCED_PARAM(pTileInfo);
    CAMX_UNREFERENCED_PARAM(startOffsetPixel);
    CAMX_UNREFERENCED_PARAM(widthPixels);
    if (pUBWCPartialTileParam != NULL) Utils::Memset(pUBWCPartialTileParam, 0, sizeof(*pUBWCPartialTileParam));
}

VOID ImageFormatUtils::InitializeFormatParams(ImageFormat* pFormat, FormatParamInfo* pFormatParamInfo)
{
    if (pFormat == NULL) return;
    CAMX_UNREFERENCED_PARAM(pFormatParamInfo);
    for (UINT i = 0; i < FormatsMaxPlanes; i++)
    {
        pFormat->formatParams.yuvFormat[i].width  = pFormat->width;
        pFormat->formatParams.yuvFormat[i].height = pFormat->height;
        if (i == 0)
        {
            pFormat->formatParams.yuvFormat[i].planeStride = pFormat->width;
            pFormat->formatParams.yuvFormat[i].sliceHeight = pFormat->height;
        }
        else if (i == 1)
        {
            pFormat->formatParams.yuvFormat[i].planeStride = pFormat->width;
            pFormat->formatParams.yuvFormat[i].sliceHeight = pFormat->height / 2;
        }
    }
    pFormat->planeAlignment[0].strideAlignment   = 1;
    pFormat->planeAlignment[0].scanlineAlignment = 1;
    pFormat->planeAlignment[1].strideAlignment   = 1;
    pFormat->planeAlignment[1].scanlineAlignment = 1;
}

// ── ImageSensorModuleData ──

CamxResult ImageSensorModuleData::Create(ImageSensorModuleDataCreateData* pCreateData)
{
    CAMX_UNREFERENCED_PARAM(pCreateData);
    return CamxResultEUnsupported;
}

VOID ImageSensorModuleData::Destroy()
{
}

CamxResult ImageSensorModuleData::Probe(BOOL* pDetected, INT32* pDeviceIndex)
{
    if (pDetected != NULL) *pDetected = FALSE;
    if (pDeviceIndex != NULL) *pDeviceIndex = -1;
    return CamxResultSuccess;
}

VOID ImageSensorModuleData::CreateSensorSubModules(HwSensorInfo* pSensorInfoTable, const HwDeviceTypeInfo* pCSLDeviceTable)
{
    CAMX_UNREFERENCED_PARAM(pSensorInfoTable);
    CAMX_UNREFERENCED_PARAM(pCSLDeviceTable);
}

CamxResult ImageSensorModuleData::CreateAndReadEEPROMData(HwSensorInfo* pSensorInfoTable, const HwDeviceTypeInfo* pCSLDeviceTable, CSLHandle hCSL)
{
    CAMX_UNREFERENCED_PARAM(pSensorInfoTable);
    CAMX_UNREFERENCED_PARAM(pCSLDeviceTable);
    CAMX_UNREFERENCED_PARAM(hCSL);
    return CamxResultSuccess;
}

VOID ImageSensorModuleData::DumpEEPROMData(HwSensorInfo* pSensorInfoTable)
{
    CAMX_UNREFERENCED_PARAM(pSensorInfoTable);
}

CamxResult ImageSensorModuleData::GetStaticCaps(SensorModuleStaticCaps* pCapability, TuningDataManager* pTuningManager, UINT cameraID)
{
    CAMX_UNREFERENCED_PARAM(pTuningManager);
    CAMX_UNREFERENCED_PARAM(cameraID);
    if (pCapability != NULL) Utils::Memset(pCapability, 0, sizeof(*pCapability));
    return CamxResultSuccess;
}

BOOL ImageSensorModuleData::GetOverrideSensorMountAvailable()
{
    return FALSE;
}

CamxResult ImageSensorModuleData::GetOverrideSensorMount(UINT32* pRoll, UINT32* pPitch, UINT32* pYaw)
{
    if (pRoll != NULL) *pRoll = 0;
    if (pPitch != NULL) *pPitch = 0;
    if (pYaw != NULL) *pYaw = 0;
    return CamxResultSuccess;
}

const CSIInformation* ImageSensorModuleData::GetCSIInfo() const
{
    return NULL;
}

const LensInformation* ImageSensorModuleData::GetLensInfo()
{
    return NULL;
}

const CHAR* ImageSensorModuleData::GetChromatixName()
{
    return "";
}

CamxResult ImageSensorModuleData::GetCameraId(UINT16* pCameraId) const
{
    if (pCameraId != NULL) *pCameraId = 0;
    return CamxResultSuccess;
}

BOOL ImageSensorModuleData::IsExternalSensor() const
{
    return FALSE;
}

CamxResult ImageSensorModuleData::GetCameraPosition(UINT* pCameraPosition)
{
    if (pCameraPosition != NULL) *pCameraPosition = 0;
    return CamxResultSuccess;
}

// ── ImageSensorData ──

VOID ImageSensorData::CalculateSensorCrop(CHIRectangle* pSensorCropInfo, UINT resolutionIndex)
{
    CAMX_UNREFERENCED_PARAM(resolutionIndex);
    if (pSensorCropInfo != NULL) Utils::Memset(pSensorCropInfo, 0, sizeof(*pSensorCropInfo));
}

VOID ImageSensorData::PopulateSensorModeData(UsecaseSensorModes* pSensorModeData, UINT32 CSIPHYSlotInfo, BOOL isComboMode)
{
    CAMX_UNREFERENCED_PARAM(CSIPHYSlotInfo);
    CAMX_UNREFERENCED_PARAM(isComboMode);
    if (pSensorModeData != NULL) Utils::Memset(pSensorModeData, 0, sizeof(*pSensorModeData));
}

VOID ImageSensorData::ConfigureImageSensorData(UINT32 sensorVersion)
{
    CAMX_UNREFERENCED_PARAM(sensorVersion);
}

CamxResult ImageSensorData::GetSensorStaticCapability(SensorModuleStaticCaps* pCapability, UINT32 cameraID)
{
    CAMX_UNREFERENCED_PARAM(cameraID);
    if (pCapability != NULL) Utils::Memset(pCapability, 0, sizeof(*pCapability));
    return CamxResultSuccess;
}

const ResolutionInformation* ImageSensorData::GetResolutionInfo() const
{
    return NULL;
}

// ── EEbinData ──

EEbinData::EEbinData(INT32 deviceIndex, CSLHandle hCSL)
{
    CAMX_UNREFERENCED_PARAM(deviceIndex);
    CAMX_UNREFERENCED_PARAM(hCSL);
}

EEbinData::~EEbinData()
{
}

UINT16 EEbinData::GetEEBinModules(CHAR* pFileNames, SIZE_T maxFileNameLength)
{
    CAMX_UNREFERENCED_PARAM(pFileNames);
    CAMX_UNREFERENCED_PARAM(maxFileNameLength);
    return 0;
}

CamxResult EEbinData::ReadEEBin()
{
    return CamxResultSuccess;
}

// ── ThermalManager ──

ThermalManager::ThermalManager()
{
}

ThermalManager::~ThermalManager()
{
}

// ── OsUtils::FDelete ──

CamxResult OsUtils::FDelete(const CHAR* pFilePath)
{
    if (pFilePath == NULL) return CamxResultEInvalidArg;
    return (unlink(pFilePath) == 0) ? CamxResultSuccess : CamxResultEFailed;
}

// ── Titan17xGetStaticEntryMethods ──

static CamxResult StubHwContextCreate(HwContextCreateData* pCreateData)
{
    if (pCreateData == NULL) return CamxResultEInvalidArg;
    pCreateData->pHwContext = CAMX_NEW DummyHwContext;
    return (pCreateData->pHwContext != NULL) ? CamxResultSuccess : CamxResultENoMemory;
}

static CamxResult StubGetStaticMetadataKeysInfo(StaticMetadataKeysInfo* pKeysInfo, CameraMetadataTag tag)
{
    CAMX_UNREFERENCED_PARAM(tag);
    if (pKeysInfo != NULL) Utils::Memset(pKeysInfo, 0, sizeof(*pKeysInfo));
    return CamxResultSuccess;
}

static CamxResult StubGetStaticCaps(PlatformStaticCaps* pCaps)
{
    if (pCaps != NULL) Utils::Memset(pCaps, 0, sizeof(*pCaps));
    return CamxResultSuccess;
}

static HwFactory* StubCreateHwFactory()
{
    extern HwFactory* CreateDummyHwFactory();
    return CreateDummyHwFactory();
}

static CamxResult StubQueryVendorTagsInfo(VendorTagInfo* pVendorTagInfo)
{
    extern void GetHwVendorTagInfo(VendorTagInfo* pInfo);
    if (pVendorTagInfo != NULL)
    {
        GetHwVendorTagInfo(pVendorTagInfo);
    }
    return CamxResultSuccess;
}

static CamxResult StubGetHWBugWorkarounds(HWBugWorkarounds* pWorkarounds)
{
    if (pWorkarounds != NULL) Utils::Memset(pWorkarounds, 0, sizeof(*pWorkarounds));
    return CamxResultSuccess;
}

static CamxResult StubQueryExternalComponentVendorTagsInfo(ComponentVendorTagsInfo* pComponentVendorTagsInfo)
{
    if (pComponentVendorTagsInfo != NULL) Utils::Memset(pComponentVendorTagsInfo, 0, sizeof(*pComponentVendorTagsInfo));
    return CamxResultSuccess;
}

CamxResult Titan17xGetStaticEntryMethods(HwContextStaticEntry* pStaticEntry)
{
    if (pStaticEntry == NULL) return CamxResultEInvalidArg;
    pStaticEntry->Create                                = StubHwContextCreate;
    pStaticEntry->GetStaticMetadataKeysInfo              = StubGetStaticMetadataKeysInfo;
    pStaticEntry->GetStaticCaps                          = StubGetStaticCaps;
    pStaticEntry->CreateHwFactory                        = StubCreateHwFactory;
    pStaticEntry->QueryVendorTagsInfo                    = StubQueryVendorTagsInfo;
    pStaticEntry->GetHWBugWorkarounds                    = StubGetHWBugWorkarounds;
    pStaticEntry->QueryExternalComponentVendorTagsInfo   = StubQueryExternalComponentVendorTagsInfo;
    return CamxResultSuccess;
}

// ── HAL3DefaultRequest ──

const Metadata* HAL3DefaultRequest::ConstructDefaultRequestSettings(UINT32 cameraId, Camera3RequestTemplate requestTemplate)
{
    CAMX_UNREFERENCED_PARAM(cameraId);
    CAMX_UNREFERENCED_PARAM(requestTemplate);
    return NULL;
}

// ── CameraMetadataTagToString ──

CamxResult CameraMetadataTagToString(CameraMetadataTag tag, const CHAR** ppTagPrefix, const CHAR** ppTagName)
{
    CAMX_UNREFERENCED_PARAM(tag);
    static const CHAR unknownPrefix[] = "unknown";
    static const CHAR unknownName[]   = "unknown";
    if (ppTagPrefix != NULL) *ppTagPrefix = unknownPrefix;
    if (ppTagName != NULL)   *ppTagName   = unknownName;
    return CamxResultSuccess;
}

// ── CAMXCustomizeEntry ──

CDK_VISIBILITY_PUBLIC VOID CAMXCustomizeEntry(
    CAMXCustomizeOEMInterface** ppOEMInterface,
    CAMXCustomizeCAMXInterface* pCAMXInterface)
{
    CAMX_UNREFERENCED_PARAM(pCAMXInterface);
    static CAMXCustomizeOEMInterface s_oemInterface = {};
    if (ppOEMInterface != NULL) *ppOEMInterface = &s_oemInterface;
}

// ── DisplayConfigInterface ──

CamxResult DisplayConfigInterface::SetCameraStatus(UINT32 status)
{
    CAMX_UNREFERENCED_PARAM(status);
    return CamxResultSuccess;
}

// ── GenerateExtend* / GenerateModifySettingsData ──

VOID GenerateExtendOpenData(UINT32 numTokens, ChiExtendSettings* pToken)
{
    CAMX_UNREFERENCED_PARAM(numTokens);
    CAMX_UNREFERENCED_PARAM(pToken);
}

VOID GenerateExtendCloseData(UINT32 numTokens, ChiExtendSettings* pToken)
{
    CAMX_UNREFERENCED_PARAM(numTokens);
    CAMX_UNREFERENCED_PARAM(pToken);
}

VOID GenerateModifySettingsData(ChiModifySettings* pToken)
{
    CAMX_UNREFERENCED_PARAM(pToken);
}

CAMX_NAMESPACE_END

// ── CamX Adapter — C-linkage wrappers for chi_stub.cpp ──

#include "camxchicontext.h"
#include "camxdebugprint.h"
#include "camxhal3metadatautil.h"

static CamX::ChiContext* g_pChiContext = nullptr;

extern "C" {

void* CamXAdapter_InitContext()
{
    if (g_pChiContext == nullptr)
    {
        CamX::g_logInfo.systemLogEnable = TRUE;

        fprintf(stderr, "[CamXAdapter] Initializing ChiContext...\n");
        fflush(stderr);
        g_pChiContext = CamX::ChiContext::Create();
        if (g_pChiContext != nullptr)
        {
            CamX::StaticSettings* pSettings = const_cast<CamX::StaticSettings*>(
                CamX::HwEnvironment::GetInstance()->GetStaticSettings());
            pSettings->MPMEnable = FALSE;

            if (FALSE == CamX::HAL3MetadataUtil::IsMetadataTableInitialized())
            {
                CamxResult metaResult = CamX::HAL3MetadataUtil::InitializeMetadataTable();
                fprintf(stderr, "[CamXAdapter] InitializeMetadataTable: result=%d tags=%u\n",
                        metaResult, CamX::HAL3MetadataUtil::GetTotalTagCount());
            }
            fprintf(stderr, "[CamXAdapter] ChiContext initialized successfully\n");
        }
        else
        {
            fprintf(stderr, "[CamXAdapter] ChiContext initialization FAILED\n");
        }
        fflush(stderr);
    }
    return g_pChiContext;
}

void CamXAdapter_DestroyContext()
{
    if (g_pChiContext != nullptr)
    {
        g_pChiContext->Destroy();
        g_pChiContext = nullptr;
    }
}

void* CamXAdapter_CreatePipelineDescriptor(
    const char* pPipelineName, void* pDescriptor,
    unsigned int numOutputs, void* pOutputBufferDescriptors,
    unsigned int numInputs, void* pInputBufferOptions)
{
    if (g_pChiContext == nullptr) return nullptr;
    CamX::PipelineDescriptor* pDesc = g_pChiContext->CreatePipelineDescriptor(
        pPipelineName,
        static_cast<const ChiPipelineCreateDescriptor*>(pDescriptor),
        numOutputs,
        static_cast<ChiPortBufferDescriptor*>(pOutputBufferDescriptors),
        numInputs,
        static_cast<CHIPIPELINEINPUTOPTIONS*>(pInputBufferOptions));
    return pDesc;
}

void* CamXAdapter_CreateSession(
    unsigned int numPipelines, void* pPipelineInfo,
    void* pCallbacks, void* pPrivateCallbackData, void* pFlags)
{
    if (g_pChiContext == nullptr) return nullptr;
    CHISESSIONFLAGS flags = {};
    if (pFlags) flags = *static_cast<CHISESSIONFLAGS*>(pFlags);

    CamX::CHISession* pSession = g_pChiContext->CreateSession(
        numPipelines,
        static_cast<ChiPipelineInfo*>(pPipelineInfo),
        static_cast<ChiCallBacks*>(pCallbacks),
        pPrivateCallbackData,
        flags);

    fprintf(stderr, "[CamXAdapter] CreateSession: %p (pipelines=%u)\n", pSession, numPipelines);
    fflush(stderr);
    return pSession;
}

int CamXAdapter_ActivatePipeline(void* pSession, void* hPipelineDescriptor)
{
    if (g_pChiContext == nullptr || pSession == nullptr) return -1;
    CamxResult result = g_pChiContext->ActivatePipeline(
        static_cast<CamX::CHISession*>(pSession),
        static_cast<CHIPIPELINEHANDLE>(hPipelineDescriptor));
    fprintf(stderr, "[CamXAdapter] ActivatePipeline: result=%d\n", result);
    fflush(stderr);
    return result;
}

int CamXAdapter_SubmitRequest(void* pSession, void* pRequest)
{
    if (g_pChiContext == nullptr || pSession == nullptr) return -1;

    ChiPipelineRequest* pPipelineReq = static_cast<ChiPipelineRequest*>(pRequest);

    for (UINT i = 0; i < pPipelineReq->numRequests; i++) {
        const ChiCaptureRequest* pReq = &pPipelineReq->pCaptureRequests[i];
        fprintf(stderr, "[CamXAdapter] SubmitRequest: req[%u] handle=%p frame=%llu outs=%u meta=%p/%p\n",
                i, pReq->hPipelineHandle, pReq->frameNumber, pReq->numOutputs,
                pReq->pInputMetadata, pReq->pOutputMetadata);
    }

    CamxResult result;
    try {
        result = g_pChiContext->SubmitRequest(
            static_cast<CamX::CHISession*>(pSession), pPipelineReq);
    } catch (...) {
        fprintf(stderr, "[CamXAdapter] SubmitRequest: exception caught\n");
        result = CamxResultEFailed;
    }
    fprintf(stderr, "[CamXAdapter] SubmitRequest: result=%d\n", result);
    return result;
}

void CamXAdapter_DestroySession(void* pSession)
{
    if (g_pChiContext == nullptr || pSession == nullptr) return;
    g_pChiContext->DestroySession(static_cast<CamX::CHISession*>(pSession));
    fprintf(stderr, "[CamXAdapter] DestroySession done\n");
    fflush(stderr);
}

void* CamXAdapter_MetaCreate(void* pPrivateData)
{
    return CamX::MetaBuffer::Create(pPrivateData);
}

int CamXAdapter_MetaDestroy(void* handle, int force)
{
    if (!handle) return 0;
    return static_cast<CamX::MetaBuffer*>(handle)->Destroy(force ? TRUE : FALSE);
}

void* CamXAdapter_MetaGetPrivateData(void* handle)
{
    if (!handle) return nullptr;
    return static_cast<CamX::MetaBuffer*>(handle)->GetPrivateUserHandle();
}

}
