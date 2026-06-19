#ifndef G_CAMXPROPERTIES_H
#define G_CAMXPROPERTIES_H

#include "camxtypes.h"
#include "camxpropertyblob.h"

CAMX_NAMESPACE_BEGIN

static const UINT NodeCompleteCount  = 32;
static const UINT LinkMetadataCount  = 20;

static const PropertyID PropertyIDAECFrameControl                          = PropertyIDPerFrameResultBegin + 0x0;
static const PropertyID PropertyIDAECFrameInfo                             = PropertyIDPerFrameResultBegin + 0x1;
static const PropertyID PropertyIDAWBFrameControl                          = PropertyIDPerFrameResultBegin + 0x2;
static const PropertyID PropertyIDAWBFrameInfo                             = PropertyIDPerFrameResultBegin + 0x3;
static const PropertyID PropertyIDAFFrameControl                           = PropertyIDPerFrameResultBegin + 0x4;
static const PropertyID PropertyIDAFFrameInfo                              = PropertyIDPerFrameResultBegin + 0x5;
static const PropertyID PropertyIDAFPDFrameInfo                            = PropertyIDPerFrameResultBegin + 0x6;
static const PropertyID PropertyIDAFBAFDependencyMet                       = PropertyIDPerFrameResultBegin + 0x7;
static const PropertyID PropertyIDASD                                      = PropertyIDPerFrameResultBegin + 0x8;
static const PropertyID PropertyIDAFDFrameControl                          = PropertyIDPerFrameResultBegin + 0x9;
static const PropertyID PropertyIDAFDFrameInfo                             = PropertyIDPerFrameResultBegin + 0xa;
static const PropertyID PropertyIDAECStatsControl                          = PropertyIDPerFrameResultBegin + 0xb;
static const PropertyID PropertyIDAWBStatsControl                          = PropertyIDPerFrameResultBegin + 0xc;
static const PropertyID PropertyIDAFStatsControl                           = PropertyIDPerFrameResultBegin + 0xd;
static const PropertyID PropertyIDAFDStatsControl                          = PropertyIDPerFrameResultBegin + 0xe;
static const PropertyID PropertyIDIHistStatsControl                        = PropertyIDPerFrameResultBegin + 0xf;
static const PropertyID PropertyIDCrossAECStats                            = PropertyIDPerFrameResultBegin + 0x10;
static const PropertyID PropertyIDCrossAWBStats                            = PropertyIDPerFrameResultBegin + 0x11;
static const PropertyID PropertyIDCrossAFStats                             = PropertyIDPerFrameResultBegin + 0x12;
static const PropertyID PropertyIDAECPeerInfo                              = PropertyIDPerFrameResultBegin + 0x13;
static const PropertyID PropertyIDAWBPeerInfo                              = PropertyIDPerFrameResultBegin + 0x14;
static const PropertyID PropertyIDAFPeerInfo                               = PropertyIDPerFrameResultBegin + 0x15;
static const PropertyID PropertyIDAFDPeerInfo                              = PropertyIDPerFrameResultBegin + 0x16;
static const PropertyID PropertyIDASDPeerInfo                              = PropertyIDPerFrameResultBegin + 0x17;
static const PropertyID PropertyIDFOVCFrameInfo                            = PropertyIDPerFrameResultBegin + 0x18;
static const PropertyID PropertyIDPDHwConfig                               = PropertyIDPerFrameResultBegin + 0x19;
static const PropertyID PropertyIDSensorCurrentMode                        = PropertyIDPerFrameResultBegin + 0x1a;
static const PropertyID PropertyIDPostSensorGainId                         = PropertyIDPerFrameResultBegin + 0x1b;
static const PropertyID PropertyIDSensorFlashCurrent                       = PropertyIDPerFrameResultBegin + 0x1c;
static const PropertyID PropertyIDSensorMetaData                           = PropertyIDPerFrameResultBegin + 0x1d;
static const PropertyID PropertyIDSensorExposureStartTime                  = PropertyIDPerFrameResultBegin + 0x1e;
static const PropertyID PropertyIDSensorProperties                         = PropertyIDPerFrameResultBegin + 0x1f;
static const PropertyID PropertyIDSensorPDAFInfo                           = PropertyIDPerFrameResultBegin + 0x20;
static const PropertyID PropertyIDSensorNumberOfLEDs                       = PropertyIDPerFrameResultBegin + 0x21;
static const PropertyID PropertyIDSensorResolutionInfo                     = PropertyIDPerFrameResultBegin + 0x22;
static const PropertyID PropertyIDRERCompleted                             = PropertyIDPerFrameResultBegin + 0x23;
static const PropertyID PropertyIDIFEDigitalZoom                           = PropertyIDPerFrameResultBegin + 0x24;
static const PropertyID PropertyIDIFEGammaOutput                           = PropertyIDPerFrameResultBegin + 0x25;
static const PropertyID PropertyIDIFEAppliedCrop                           = PropertyIDPerFrameResultBegin + 0x26;
static const PropertyID PropertyIDISPBHistConfig                           = PropertyIDPerFrameResultBegin + 0x27;
static const PropertyID PropertyIDISPTintlessBGConfig                      = PropertyIDPerFrameResultBegin + 0x28;
static const PropertyID PropertyIDIFEScaleOutput                           = PropertyIDPerFrameResultBegin + 0x29;
static const PropertyID PropertyIDParsedAWBBGStatsOutput                   = PropertyIDPerFrameResultBegin + 0x2a;
static const PropertyID PropertyIDParsedBFStatsOutput                      = PropertyIDPerFrameResultBegin + 0x2b;
static const PropertyID PropertyIDParsedBHistStatsOutput                   = PropertyIDPerFrameResultBegin + 0x2c;
static const PropertyID PropertyIDParsedCSStatsOutput                      = PropertyIDPerFrameResultBegin + 0x2d;
static const PropertyID PropertyIDParsedHDRBEStatsOutput                   = PropertyIDPerFrameResultBegin + 0x2e;
static const PropertyID PropertyIDParsedHDRBHistStatsOutput                = PropertyIDPerFrameResultBegin + 0x2f;
static const PropertyID PropertyIDParsedIHistStatsOutput                   = PropertyIDPerFrameResultBegin + 0x30;
static const PropertyID PropertyIDParsedRSStatsOutput                      = PropertyIDPerFrameResultBegin + 0x31;
static const PropertyID PropertyIDParsedTintlessBGStatsOutput              = PropertyIDPerFrameResultBegin + 0x32;
static const PropertyID PropertyIDBPSGammaOutput                           = PropertyIDPerFrameResultBegin + 0x33;
static const PropertyID PropertyIDJPEGEncodeOutInfo                        = PropertyIDPerFrameResultBegin + 0x34;
static const PropertyID PropertyIDJPEGEncodeOutInfoThumbnail               = PropertyIDPerFrameResultBegin + 0x35;
static const PropertyID PropertyIDIPETotalFrameMFNR                        = PropertyIDPerFrameResultBegin + 0x36;
static const PropertyID PropertyIDIPETotalFrameMFSR                        = PropertyIDPerFrameResultBegin + 0x37;
static const PropertyID PropertyIDFDFrameSettings                          = PropertyIDPerFrameResultBegin + 0x38;
static const PropertyID PropertyIDLRMEFrameSettings                        = PropertyIDPerFrameResultBegin + 0x39;
static const PropertyID PropertyIDIFEADRCInfoOutput                        = PropertyIDPerFrameResultBegin + 0x3a;
static const PropertyID PropertyIDBPSADRCInfoOutput                        = PropertyIDPerFrameResultBegin + 0x3b;
static const PropertyID PropertyIDIFEADRCParams                            = PropertyIDPerFrameResultBegin + 0x3c;
static const PropertyID PropertyIDIntermediateDimension                    = PropertyIDPerFrameResultBegin + 0x3d;
static const PropertyID PropertyIDIPEGamma15PreCalculation                 = PropertyIDPerFrameResultBegin + 0x3e;
static const PropertyID PropertyIDNodeComplete0                            = PropertyIDPerFrameResultBegin + 0x3f;
static const PropertyID PropertyIDNodeComplete1                            = PropertyIDPerFrameResultBegin + 0x40;
static const PropertyID PropertyIDNodeComplete2                            = PropertyIDPerFrameResultBegin + 0x41;
static const PropertyID PropertyIDNodeComplete3                            = PropertyIDPerFrameResultBegin + 0x42;
static const PropertyID PropertyIDNodeComplete4                            = PropertyIDPerFrameResultBegin + 0x43;
static const PropertyID PropertyIDNodeComplete5                            = PropertyIDPerFrameResultBegin + 0x44;
static const PropertyID PropertyIDNodeComplete6                            = PropertyIDPerFrameResultBegin + 0x45;
static const PropertyID PropertyIDNodeComplete7                            = PropertyIDPerFrameResultBegin + 0x46;
static const PropertyID PropertyIDNodeComplete8                            = PropertyIDPerFrameResultBegin + 0x47;
static const PropertyID PropertyIDNodeComplete9                            = PropertyIDPerFrameResultBegin + 0x48;
static const PropertyID PropertyIDNodeComplete10                           = PropertyIDPerFrameResultBegin + 0x49;
static const PropertyID PropertyIDNodeComplete11                           = PropertyIDPerFrameResultBegin + 0x4a;
static const PropertyID PropertyIDNodeComplete12                           = PropertyIDPerFrameResultBegin + 0x4b;
static const PropertyID PropertyIDNodeComplete13                           = PropertyIDPerFrameResultBegin + 0x4c;
static const PropertyID PropertyIDNodeComplete14                           = PropertyIDPerFrameResultBegin + 0x4d;
static const PropertyID PropertyIDNodeComplete15                           = PropertyIDPerFrameResultBegin + 0x4e;
static const PropertyID PropertyIDNodeComplete16                           = PropertyIDPerFrameResultBegin + 0x4f;
static const PropertyID PropertyIDNodeComplete17                           = PropertyIDPerFrameResultBegin + 0x50;
static const PropertyID PropertyIDNodeComplete18                           = PropertyIDPerFrameResultBegin + 0x51;
static const PropertyID PropertyIDNodeComplete19                           = PropertyIDPerFrameResultBegin + 0x52;
static const PropertyID PropertyIDNodeComplete20                           = PropertyIDPerFrameResultBegin + 0x53;
static const PropertyID PropertyIDNodeComplete21                           = PropertyIDPerFrameResultBegin + 0x54;
static const PropertyID PropertyIDNodeComplete22                           = PropertyIDPerFrameResultBegin + 0x55;
static const PropertyID PropertyIDNodeComplete23                           = PropertyIDPerFrameResultBegin + 0x56;
static const PropertyID PropertyIDNodeComplete24                           = PropertyIDPerFrameResultBegin + 0x57;
static const PropertyID PropertyIDNodeComplete25                           = PropertyIDPerFrameResultBegin + 0x58;
static const PropertyID PropertyIDNodeComplete26                           = PropertyIDPerFrameResultBegin + 0x59;
static const PropertyID PropertyIDNodeComplete27                           = PropertyIDPerFrameResultBegin + 0x5a;
static const PropertyID PropertyIDNodeComplete28                           = PropertyIDPerFrameResultBegin + 0x5b;
static const PropertyID PropertyIDNodeComplete29                           = PropertyIDPerFrameResultBegin + 0x5c;
static const PropertyID PropertyIDNodeComplete30                           = PropertyIDPerFrameResultBegin + 0x5d;
static const PropertyID PropertyIDNodeComplete31                           = PropertyIDPerFrameResultBegin + 0x5e;
static const PropertyID PropertyIDLinkMetadata0                            = PropertyIDPerFrameResultBegin + 0x5f;
static const PropertyID PropertyIDLinkMetadata1                            = PropertyIDPerFrameResultBegin + 0x60;
static const PropertyID PropertyIDLinkMetadata2                            = PropertyIDPerFrameResultBegin + 0x61;
static const PropertyID PropertyIDLinkMetadata3                            = PropertyIDPerFrameResultBegin + 0x62;
static const PropertyID PropertyIDLinkMetadata4                            = PropertyIDPerFrameResultBegin + 0x63;
static const PropertyID PropertyIDLinkMetadata5                            = PropertyIDPerFrameResultBegin + 0x64;
static const PropertyID PropertyIDLinkMetadata6                            = PropertyIDPerFrameResultBegin + 0x65;
static const PropertyID PropertyIDLinkMetadata7                            = PropertyIDPerFrameResultBegin + 0x66;
static const PropertyID PropertyIDLinkMetadata8                            = PropertyIDPerFrameResultBegin + 0x67;
static const PropertyID PropertyIDLinkMetadata9                            = PropertyIDPerFrameResultBegin + 0x68;
static const PropertyID PropertyIDLinkMetadata10                           = PropertyIDPerFrameResultBegin + 0x69;
static const PropertyID PropertyIDLinkMetadata11                           = PropertyIDPerFrameResultBegin + 0x6a;
static const PropertyID PropertyIDLinkMetadata12                           = PropertyIDPerFrameResultBegin + 0x6b;
static const PropertyID PropertyIDLinkMetadata13                           = PropertyIDPerFrameResultBegin + 0x6c;
static const PropertyID PropertyIDLinkMetadata14                           = PropertyIDPerFrameResultBegin + 0x6d;
static const PropertyID PropertyIDLinkMetadata15                           = PropertyIDPerFrameResultBegin + 0x6e;
static const PropertyID PropertyIDLinkMetadata16                           = PropertyIDPerFrameResultBegin + 0x6f;
static const PropertyID PropertyIDLinkMetadata17                           = PropertyIDPerFrameResultBegin + 0x70;
static const PropertyID PropertyIDLinkMetadata18                           = PropertyIDPerFrameResultBegin + 0x71;
static const PropertyID PropertyIDLinkMetadata19                           = PropertyIDPerFrameResultBegin + 0x72;
static const PropertyID PropertyIDPerFrameResultEnd   = PropertyIDPerFrameResultBegin + 0x73;
static const UINT       PropertyIDPerFrameResultCount = 115;

static const PropertyID PropertyIDAECInternal                              = PropertyIDPerFrameInternalBegin + 0x0;
static const PropertyID PropertyIDAFInternal                               = PropertyIDPerFrameInternalBegin + 0x1;
static const PropertyID PropertyIDASDInternal                              = PropertyIDPerFrameInternalBegin + 0x2;
static const PropertyID PropertyIDAWBInternal                              = PropertyIDPerFrameInternalBegin + 0x3;
static const PropertyID PropertyIDAFDInternal                              = PropertyIDPerFrameInternalBegin + 0x4;
static const PropertyID PropertyIDBasePDInternal                           = PropertyIDPerFrameInternalBegin + 0x5;
static const PropertyID PropertyIDISPAECBG                                 = PropertyIDPerFrameInternalBegin + 0x6;
static const PropertyID PropertyIDISPAWBBGConfig                           = PropertyIDPerFrameInternalBegin + 0x7;
static const PropertyID PropertyIDISPBFConfig                              = PropertyIDPerFrameInternalBegin + 0x8;
static const PropertyID PropertyIDISPCSConfig                              = PropertyIDPerFrameInternalBegin + 0x9;
static const PropertyID PropertyIDISPHDRBEConfig                           = PropertyIDPerFrameInternalBegin + 0xa;
static const PropertyID PropertyIDISPHDRBHistConfig                        = PropertyIDPerFrameInternalBegin + 0xb;
static const PropertyID PropertyIDISPIHistConfig                           = PropertyIDPerFrameInternalBegin + 0xc;
static const PropertyID PropertyIDISPRegionsStats                          = PropertyIDPerFrameInternalBegin + 0xd;
static const PropertyID PropertyIDISPROIStats                              = PropertyIDPerFrameInternalBegin + 0xe;
static const PropertyID PropertyIDISPRSConfig                              = PropertyIDPerFrameInternalBegin + 0xf;
static const PropertyID PropertyIDFDInternalPerFrameSettings               = PropertyIDPerFrameInternalBegin + 0x10;
static const PropertyID PropertyIDSkipStatsParserTypeBF                    = PropertyIDPerFrameInternalBegin + 0x11;
static const PropertyID PropertyIDSkipStatsParserTypeHDRBE                 = PropertyIDPerFrameInternalBegin + 0x12;
static const PropertyID PropertyIDSkipStatsParserTypeBHist                 = PropertyIDPerFrameInternalBegin + 0x13;
static const PropertyID PropertyIDSkipStatsParserTypeHDRBHist              = PropertyIDPerFrameInternalBegin + 0x14;
static const PropertyID PropertyIDSkipStatsParserTypeRS                    = PropertyIDPerFrameInternalBegin + 0x15;
static const PropertyID PropertyIDSkipStatsParserTypeCS                    = PropertyIDPerFrameInternalBegin + 0x16;
static const PropertyID PropertyIDSkipStatsParserTypeAWBBG                 = PropertyIDPerFrameInternalBegin + 0x17;
static const PropertyID PropertyIDSkipStatsParserTypeTintlessBG            = PropertyIDPerFrameInternalBegin + 0x18;
static const PropertyID PropertyIDSkipStatsParserTypeIHist                 = PropertyIDPerFrameInternalBegin + 0x19;
static const PropertyID PropertyIDSkipStatsParserTypeBPSAWBBG              = PropertyIDPerFrameInternalBegin + 0x1a;
static const PropertyID PropertyIDPerFrameInternalEnd   = PropertyIDPerFrameInternalBegin + 0x1b;
static const UINT       PropertyIDPerFrameInternalCount = 27;

static const PropertyID PropertyIDUsecaseSensorModes                       = PropertyIDUsecaseBegin + 0x0;
static const PropertyID PropertyIDUsecaseBatch                             = PropertyIDUsecaseBegin + 0x1;
static const PropertyID PropertyIDUsecaseFPS                               = PropertyIDUsecaseBegin + 0x2;
static const PropertyID PropertyIDUsecaseLensInfo                          = PropertyIDUsecaseBegin + 0x3;
static const PropertyID PropertyIDUsecaseCameraModuleInfo                  = PropertyIDUsecaseBegin + 0x4;
static const PropertyID PropertyIDUsecasePDLibInfo                         = PropertyIDUsecaseBegin + 0x5;
static const PropertyID PropertyIDUsecaseSensorCurrentMode                 = PropertyIDUsecaseBegin + 0x6;
static const PropertyID PropertyIDUsecaseSensorISO100Gain                  = PropertyIDUsecaseBegin + 0x7;
static const PropertyID PropertyIDUsecaseAWBFrameControl                   = PropertyIDUsecaseBegin + 0x8;
static const PropertyID PropertyIDUsecaseAECFrameControl                   = PropertyIDUsecaseBegin + 0x9;
static const PropertyID PropertyIDUsecaseAFFrameControl                    = PropertyIDUsecaseBegin + 0xa;
static const PropertyID PropertyIDUsecaseAFFrameInformation                = PropertyIDUsecaseBegin + 0xb;
static const PropertyID PropertyIDUsecaseAECStatsControl                   = PropertyIDUsecaseBegin + 0xc;
static const PropertyID PropertyIDUsecaseAWBStatsControl                   = PropertyIDUsecaseBegin + 0xd;
static const PropertyID PropertyIDUsecaseAFStatsControl                    = PropertyIDUsecaseBegin + 0xe;
static const PropertyID PropertyIDUsecaseStatsStreamInitConfig             = PropertyIDUsecaseBegin + 0xf;
static const PropertyID PropertyIDUsecasePipelineOutputDimensions          = PropertyIDUsecaseBegin + 0x10;
static const PropertyID PropertyIDUsecaseFDResults                         = PropertyIDUsecaseBegin + 0x11;
static const PropertyID PropertyIDUsecaseFDMetadataResults                 = PropertyIDUsecaseBegin + 0x12;
static const PropertyID PropertyIDUsecaseFDContourResults                  = PropertyIDUsecaseBegin + 0x13;
static const PropertyID PropertyIDUsecaseIFEInputResolution                = PropertyIDUsecaseBegin + 0x14;
static const PropertyID PropertyIDUsecaseIFEOutputResolution               = PropertyIDUsecaseBegin + 0x15;
static const PropertyID PropertyIDUsecaseIFEPDAFInfo                       = PropertyIDUsecaseBegin + 0x16;
static const PropertyID PropertyIDUsecaseHWPDConfig                        = PropertyIDUsecaseBegin + 0x17;
static const PropertyID PropertyIDUsecaseChiTuningModeParameter            = PropertyIDUsecaseBegin + 0x18;
static const PropertyID PropertyIDUsecaseAESyncStartLockTagID              = PropertyIDUsecaseBegin + 0x19;
static const PropertyID PropertyIDUsecaseAESyncStopLockTagID               = PropertyIDUsecaseBegin + 0x1a;
static const PropertyID PropertyIDUsecaseIFEPDHWInfo                       = PropertyIDUsecaseBegin + 0x1b;
static const PropertyID PropertyIDUsecasePDHWEnableConditions              = PropertyIDUsecaseBegin + 0x1c;
static const PropertyID PropertyIDUsecasePDLibInputPDHWEnableConditions    = PropertyIDUsecaseBegin + 0x1d;
static const PropertyID PropertyIDUsecaseTrackerResults                    = PropertyIDUsecaseBegin + 0x1e;
static const PropertyID PropertyIDUsecaseEnd   = PropertyIDUsecaseBegin + 0x1f;
static const UINT       PropertyIDUsecaseCount = 31;

static const PropertyID PropertyIDDebugDataAll                             = PropertyIDPerFrameDebugDataBegin + 0x0;
static const PropertyID PropertyIDDebugDataAEC                             = PropertyIDPerFrameDebugDataBegin + 0x1;
static const PropertyID PropertyIDDebugDataAWB                             = PropertyIDPerFrameDebugDataBegin + 0x2;
static const PropertyID PropertyIDDebugDataAF                              = PropertyIDPerFrameDebugDataBegin + 0x3;
static const PropertyID PropertyIDTuningDataIFE                            = PropertyIDPerFrameDebugDataBegin + 0x4;
static const PropertyID PropertyIDTuningDataIPE                            = PropertyIDPerFrameDebugDataBegin + 0x5;
static const PropertyID PropertyIDTuningDataBPS                            = PropertyIDPerFrameDebugDataBegin + 0x6;
static const PropertyID PropertyIDPerFrameDebugDataEnd   = PropertyIDPerFrameDebugDataBegin + 0x7;
static const UINT       PropertyIDPerFrameDebugDataCount = 7;

static const PropertyID MainPropertyLinearLUT[] = {
    PropertyIDAECFrameControl,
    PropertyIDAECFrameInfo,
    PropertyIDAWBFrameControl,
    PropertyIDAWBFrameInfo,
    PropertyIDAFFrameControl,
    PropertyIDAFFrameInfo,
    PropertyIDAFPDFrameInfo,
    PropertyIDAFBAFDependencyMet,
    PropertyIDASD,
    PropertyIDAFDFrameControl,
    PropertyIDAFDFrameInfo,
    PropertyIDAECStatsControl,
    PropertyIDAWBStatsControl,
    PropertyIDAFStatsControl,
    PropertyIDAFDStatsControl,
    PropertyIDIHistStatsControl,
    PropertyIDCrossAECStats,
    PropertyIDCrossAWBStats,
    PropertyIDCrossAFStats,
    PropertyIDAECPeerInfo,
    PropertyIDAWBPeerInfo,
    PropertyIDAFPeerInfo,
    PropertyIDAFDPeerInfo,
    PropertyIDASDPeerInfo,
    PropertyIDFOVCFrameInfo,
    PropertyIDPDHwConfig,
    PropertyIDSensorCurrentMode,
    PropertyIDPostSensorGainId,
    PropertyIDSensorFlashCurrent,
    PropertyIDSensorMetaData,
    PropertyIDSensorExposureStartTime,
    PropertyIDSensorProperties,
    PropertyIDSensorPDAFInfo,
    PropertyIDSensorNumberOfLEDs,
    PropertyIDSensorResolutionInfo,
    PropertyIDRERCompleted,
    PropertyIDIFEDigitalZoom,
    PropertyIDIFEGammaOutput,
    PropertyIDIFEAppliedCrop,
    PropertyIDISPBHistConfig,
    PropertyIDISPTintlessBGConfig,
    PropertyIDIFEScaleOutput,
    PropertyIDParsedAWBBGStatsOutput,
    PropertyIDParsedBFStatsOutput,
    PropertyIDParsedBHistStatsOutput,
    PropertyIDParsedCSStatsOutput,
    PropertyIDParsedHDRBEStatsOutput,
    PropertyIDParsedHDRBHistStatsOutput,
    PropertyIDParsedIHistStatsOutput,
    PropertyIDParsedRSStatsOutput,
    PropertyIDParsedTintlessBGStatsOutput,
    PropertyIDBPSGammaOutput,
    PropertyIDJPEGEncodeOutInfo,
    PropertyIDJPEGEncodeOutInfoThumbnail,
    PropertyIDIPETotalFrameMFNR,
    PropertyIDIPETotalFrameMFSR,
    PropertyIDFDFrameSettings,
    PropertyIDLRMEFrameSettings,
    PropertyIDIFEADRCInfoOutput,
    PropertyIDBPSADRCInfoOutput,
    PropertyIDIFEADRCParams,
    PropertyIDIntermediateDimension,
    PropertyIDIPEGamma15PreCalculation,
    PropertyIDNodeComplete0,
    PropertyIDNodeComplete1,
    PropertyIDNodeComplete2,
    PropertyIDNodeComplete3,
    PropertyIDNodeComplete4,
    PropertyIDNodeComplete5,
    PropertyIDNodeComplete6,
    PropertyIDNodeComplete7,
    PropertyIDNodeComplete8,
    PropertyIDNodeComplete9,
    PropertyIDNodeComplete10,
    PropertyIDNodeComplete11,
    PropertyIDNodeComplete12,
    PropertyIDNodeComplete13,
    PropertyIDNodeComplete14,
    PropertyIDNodeComplete15,
    PropertyIDNodeComplete16,
    PropertyIDNodeComplete17,
    PropertyIDNodeComplete18,
    PropertyIDNodeComplete19,
    PropertyIDNodeComplete20,
    PropertyIDNodeComplete21,
    PropertyIDNodeComplete22,
    PropertyIDNodeComplete23,
    PropertyIDNodeComplete24,
    PropertyIDNodeComplete25,
    PropertyIDNodeComplete26,
    PropertyIDNodeComplete27,
    PropertyIDNodeComplete28,
    PropertyIDNodeComplete29,
    PropertyIDNodeComplete30,
    PropertyIDNodeComplete31,
    PropertyIDLinkMetadata0,
    PropertyIDLinkMetadata1,
    PropertyIDLinkMetadata2,
    PropertyIDLinkMetadata3,
    PropertyIDLinkMetadata4,
    PropertyIDLinkMetadata5,
    PropertyIDLinkMetadata6,
    PropertyIDLinkMetadata7,
    PropertyIDLinkMetadata8,
    PropertyIDLinkMetadata9,
    PropertyIDLinkMetadata10,
    PropertyIDLinkMetadata11,
    PropertyIDLinkMetadata12,
    PropertyIDLinkMetadata13,
    PropertyIDLinkMetadata14,
    PropertyIDLinkMetadata15,
    PropertyIDLinkMetadata16,
    PropertyIDLinkMetadata17,
    PropertyIDLinkMetadata18,
    PropertyIDLinkMetadata19,
};

struct MainPropertyBlob
{
    BYTE pad_AECFrameControl[256];
    BYTE pad_AECFrameInfo[256];
    BYTE pad_AWBFrameControl[256];
    BYTE pad_AWBFrameInfo[256];
    BYTE pad_AFFrameControl[256];
    BYTE pad_AFFrameInfo[256];
    BYTE pad_AFPDFrameInfo[256];
    BYTE pad_AFBAFDependencyMet[256];
    BYTE pad_ASD[256];
    BYTE pad_AFDFrameControl[256];
    BYTE pad_AFDFrameInfo[256];
    BYTE pad_AECStatsControl[256];
    BYTE pad_AWBStatsControl[256];
    BYTE pad_AFStatsControl[256];
    BYTE pad_AFDStatsControl[256];
    BYTE pad_IHistStatsControl[256];
    BYTE pad_CrossAECStats[256];
    BYTE pad_CrossAWBStats[256];
    BYTE pad_CrossAFStats[256];
    BYTE pad_AECPeerInfo[256];
    BYTE pad_AWBPeerInfo[256];
    BYTE pad_AFPeerInfo[256];
    BYTE pad_AFDPeerInfo[256];
    BYTE pad_ASDPeerInfo[256];
    BYTE pad_FOVCFrameInfo[256];
    BYTE pad_PDHwConfig[256];
    BYTE pad_SensorCurrentMode[256];
    BYTE pad_PostSensorGainId[256];
    BYTE pad_SensorFlashCurrent[256];
    BYTE pad_SensorMetaData[256];
    BYTE pad_SensorExposureStartTime[256];
    BYTE pad_SensorProperties[256];
    BYTE pad_SensorPDAFInfo[256];
    BYTE pad_SensorNumberOfLEDs[256];
    BYTE pad_SensorResolutionInfo[256];
    BYTE pad_RERCompleted[256];
    BYTE pad_IFEDigitalZoom[256];
    BYTE pad_IFEGammaOutput[256];
    BYTE pad_IFEAppliedCrop[256];
    BYTE pad_ISPBHistConfig[256];
    BYTE pad_ISPTintlessBGConfig[256];
    BYTE pad_IFEScaleOutput[256];
    BYTE pad_ParsedAWBBGStatsOutput[256];
    BYTE pad_ParsedBFStatsOutput[256];
    BYTE pad_ParsedBHistStatsOutput[256];
    BYTE pad_ParsedCSStatsOutput[256];
    BYTE pad_ParsedHDRBEStatsOutput[256];
    BYTE pad_ParsedHDRBHistStatsOutput[256];
    BYTE pad_ParsedIHistStatsOutput[256];
    BYTE pad_ParsedRSStatsOutput[256];
    BYTE pad_ParsedTintlessBGStatsOutput[256];
    BYTE pad_BPSGammaOutput[256];
    BYTE pad_JPEGEncodeOutInfo[256];
    BYTE pad_JPEGEncodeOutInfoThumbnail[256];
    BYTE pad_IPETotalFrameMFNR[256];
    BYTE pad_IPETotalFrameMFSR[256];
    BYTE pad_FDFrameSettings[256];
    BYTE pad_LRMEFrameSettings[256];
    BYTE pad_IFEADRCInfoOutput[256];
    BYTE pad_BPSADRCInfoOutput[256];
    BYTE pad_IFEADRCParams[256];
    BYTE pad_IntermediateDimension[256];
    BYTE pad_IPEGamma15PreCalculation[256];
    BYTE pad_NodeComplete0[256];
    BYTE pad_NodeComplete1[256];
    BYTE pad_NodeComplete2[256];
    BYTE pad_NodeComplete3[256];
    BYTE pad_NodeComplete4[256];
    BYTE pad_NodeComplete5[256];
    BYTE pad_NodeComplete6[256];
    BYTE pad_NodeComplete7[256];
    BYTE pad_NodeComplete8[256];
    BYTE pad_NodeComplete9[256];
    BYTE pad_NodeComplete10[256];
    BYTE pad_NodeComplete11[256];
    BYTE pad_NodeComplete12[256];
    BYTE pad_NodeComplete13[256];
    BYTE pad_NodeComplete14[256];
    BYTE pad_NodeComplete15[256];
    BYTE pad_NodeComplete16[256];
    BYTE pad_NodeComplete17[256];
    BYTE pad_NodeComplete18[256];
    BYTE pad_NodeComplete19[256];
    BYTE pad_NodeComplete20[256];
    BYTE pad_NodeComplete21[256];
    BYTE pad_NodeComplete22[256];
    BYTE pad_NodeComplete23[256];
    BYTE pad_NodeComplete24[256];
    BYTE pad_NodeComplete25[256];
    BYTE pad_NodeComplete26[256];
    BYTE pad_NodeComplete27[256];
    BYTE pad_NodeComplete28[256];
    BYTE pad_NodeComplete29[256];
    BYTE pad_NodeComplete30[256];
    BYTE pad_NodeComplete31[256];
    BYTE pad_LinkMetadata0[256];
    BYTE pad_LinkMetadata1[256];
    BYTE pad_LinkMetadata2[256];
    BYTE pad_LinkMetadata3[256];
    BYTE pad_LinkMetadata4[256];
    BYTE pad_LinkMetadata5[256];
    BYTE pad_LinkMetadata6[256];
    BYTE pad_LinkMetadata7[256];
    BYTE pad_LinkMetadata8[256];
    BYTE pad_LinkMetadata9[256];
    BYTE pad_LinkMetadata10[256];
    BYTE pad_LinkMetadata11[256];
    BYTE pad_LinkMetadata12[256];
    BYTE pad_LinkMetadata13[256];
    BYTE pad_LinkMetadata14[256];
    BYTE pad_LinkMetadata15[256];
    BYTE pad_LinkMetadata16[256];
    BYTE pad_LinkMetadata17[256];
    BYTE pad_LinkMetadata18[256];
    BYTE pad_LinkMetadata19[256];
};

struct InternalPropertyBlob
{
    BYTE pad_AECInternal[256];
    BYTE pad_AFInternal[256];
    BYTE pad_ASDInternal[256];
    BYTE pad_AWBInternal[256];
    BYTE pad_AFDInternal[256];
    BYTE pad_BasePDInternal[256];
    BYTE pad_ISPAECBG[256];
    BYTE pad_ISPAWBBGConfig[256];
    BYTE pad_ISPBFConfig[256];
    BYTE pad_ISPCSConfig[256];
    BYTE pad_ISPHDRBEConfig[256];
    BYTE pad_ISPHDRBHistConfig[256];
    BYTE pad_ISPIHistConfig[256];
    BYTE pad_ISPRegionsStats[256];
    BYTE pad_ISPROIStats[256];
    BYTE pad_ISPRSConfig[256];
    BYTE pad_FDInternalPerFrameSettings[256];
    BYTE pad_SkipStatsParserTypeBF[256];
    BYTE pad_SkipStatsParserTypeHDRBE[256];
    BYTE pad_SkipStatsParserTypeBHist[256];
    BYTE pad_SkipStatsParserTypeHDRBHist[256];
    BYTE pad_SkipStatsParserTypeRS[256];
    BYTE pad_SkipStatsParserTypeCS[256];
    BYTE pad_SkipStatsParserTypeAWBBG[256];
    BYTE pad_SkipStatsParserTypeTintlessBG[256];
    BYTE pad_SkipStatsParserTypeIHist[256];
    BYTE pad_SkipStatsParserTypeBPSAWBBG[256];
};

static const SIZE_T InternalPropertyOffsets[] = {
    offsetof(InternalPropertyBlob, pad_AECInternal),
    offsetof(InternalPropertyBlob, pad_AFInternal),
    offsetof(InternalPropertyBlob, pad_ASDInternal),
    offsetof(InternalPropertyBlob, pad_AWBInternal),
    offsetof(InternalPropertyBlob, pad_AFDInternal),
    offsetof(InternalPropertyBlob, pad_BasePDInternal),
    offsetof(InternalPropertyBlob, pad_ISPAECBG),
    offsetof(InternalPropertyBlob, pad_ISPAWBBGConfig),
    offsetof(InternalPropertyBlob, pad_ISPBFConfig),
    offsetof(InternalPropertyBlob, pad_ISPCSConfig),
    offsetof(InternalPropertyBlob, pad_ISPHDRBEConfig),
    offsetof(InternalPropertyBlob, pad_ISPHDRBHistConfig),
    offsetof(InternalPropertyBlob, pad_ISPIHistConfig),
    offsetof(InternalPropertyBlob, pad_ISPRegionsStats),
    offsetof(InternalPropertyBlob, pad_ISPROIStats),
    offsetof(InternalPropertyBlob, pad_ISPRSConfig),
    offsetof(InternalPropertyBlob, pad_FDInternalPerFrameSettings),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeBF),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeHDRBE),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeBHist),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeHDRBHist),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeRS),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeCS),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeAWBBG),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeTintlessBG),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeIHist),
    offsetof(InternalPropertyBlob, pad_SkipStatsParserTypeBPSAWBBG),
};

struct DebugDataPropertyBlob
{
    BYTE pad_DebugDataAll[256];
    BYTE pad_DebugDataAEC[256];
    BYTE pad_DebugDataAWB[256];
    BYTE pad_DebugDataAF[256];
    BYTE pad_TuningDataIFE[256];
    BYTE pad_TuningDataIPE[256];
    BYTE pad_TuningDataBPS[256];
};

static const SIZE_T DebugDataPropertyOffsets[] = {
    offsetof(DebugDataPropertyBlob, pad_DebugDataAll),
    offsetof(DebugDataPropertyBlob, pad_DebugDataAEC),
    offsetof(DebugDataPropertyBlob, pad_DebugDataAWB),
    offsetof(DebugDataPropertyBlob, pad_DebugDataAF),
    offsetof(DebugDataPropertyBlob, pad_TuningDataIFE),
    offsetof(DebugDataPropertyBlob, pad_TuningDataIPE),
    offsetof(DebugDataPropertyBlob, pad_TuningDataBPS),
};

CAMX_NAMESPACE_END

#endif
