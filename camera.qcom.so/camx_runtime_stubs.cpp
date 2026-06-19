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

#include <cstdio>
#include <unistd.h>

CAMX_NAMESPACE_BEGIN

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
    CAMX_UNREFERENCED_PARAM(pCreateData);
    return CamxResultSuccess;
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
    if (pVendorTagInfo != NULL) Utils::Memset(pVendorTagInfo, 0, sizeof(*pVendorTagInfo));
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
    if (ppOEMInterface != NULL) *ppOEMInterface = NULL;
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
