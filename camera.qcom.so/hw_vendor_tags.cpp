////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// hw_vendor_tags.cpp — HW vendor tag data for mock environment
// Extracted from camx/src/hwl/titan17x/camxtitan17xcontext.cpp
// (CAMX-2877: these VTs are HW-independent, belong outside HWL)
//
// Provides the 81 vendor tag section definitions that Titan17xContext::QueryVendorTagsInfo()
// would normally return. In the mock environment, StubQueryVendorTagsInfo() calls
// GetHwVendorTagInfo() from this file instead.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxvendortags.h"
#include "camxipeproperty.h"

#include "chi.h"
#include "chifdproperty.h"
#include "chistatsproperty.h"
#include "chiispstatsdefs.h"
#include "chiiqmodulesettings.h"

CAMX_NAMESPACE_BEGIN

// ── Local stubs ONLY for types truly missing from transitive includes ──
// Most types are available via camxvendortags.h → camxpropertyblob.h → camxifeproperty.h etc.
// Only sizeof() matters for vendor tag registration.

// From camxjpegquanttable.h (not transitively included)
#ifndef QuantizationTableVendorTagSection
#define QuantizationTableVendorTagSection    "org.quic.camera2.jpegquantizationtables"
#define QuantizationTableLumaVendorTagName   "OEMJPEGLumaQuantizationTable"
#define QuantizationTableChromaVendorTagName "OEMJPEGChromaQuantizationTable"
#endif

// From GeoLib.h (proprietary, not in source tree)
struct GeoLibStillFrameConfig { UINT8 pad[2048]; };
struct GeoLibStreamOutput     { UINT32 dummy[4]; };

// ParsedBFStatsOutput — not found anywhere in source tree
struct ParsedBFStatsOutput { UINT8 pad[4096]; };

// ── Vendor Tag Data Arrays ──
// Verbatim from camxtitan17xcontext.cpp lines 644-1228

static VendorTagData g_VendorTagSectionDebugData[] =
{
    { "DebugDataAll", VendorTagType::Byte, sizeof(DebugData) },
    { "DebugDataAEC", VendorTagType::Byte, sizeof(DebugData) },
    { "DebugDataAWB", VendorTagType::Byte, sizeof(DebugData) },
    { "DebugDataAF",  VendorTagType::Byte, sizeof(DebugData) }
};

static VendorTagData g_VendorTagSectionTuningdataDump[] =
{
    { "TuningDataDump",  VendorTagType::Byte, sizeof(DebugData) }
};

static VendorTagData g_VendorTagSectionSaturation[] =
{
    { "use_saturation", VendorTagType::Int32, 1 },
    { "range",          VendorTagType::Int32, 4 }
};

static VendorTagData g_VendorTagSectionSharpness[] =
{
    { "strength", VendorTagType::Int32, 1 },
    { "range",    VendorTagType::Int32, 2 }
};

static VendorTagData g_VendorTagSectionContrast[] =
{
    { "level", VendorTagType::Int32, 1 },
};

static VendorTagData g_VendorTagSectionExposureMetering[] =
{
    { "exposure_metering_mode", VendorTagType::Int32, 1 },
    { "available_modes",        VendorTagType::Int32, 7 }
};

static VendorTagData g_VendorTagSectionAecConvergenceSpeed[] =
{
    { "aec_speed", VendorTagType::Float, 1 },
};

static VendorTagData g_VendorTagSectionIsoExpPriority[] =
{
    { "use_iso_exp_priority",   VendorTagType::Int64, 1 },
    { "use_iso_value",          VendorTagType::Int32, 1 },
    { "select_priority",        VendorTagType::Int32, 1 },
    { "iso_available_modes",    VendorTagType::Int32, 8 },
    { "exposure_time_range",    VendorTagType::Int64, 2 },
    { "use_gain_value",         VendorTagType::Float, 1 },
};

static VendorTagData g_VendorTagSectionHistogram[] =
{
    { "enable",      VendorTagType::Byte,  1 },
    { "buckets",     VendorTagType::Int32, 1 },
    { "max_count",   VendorTagType::Int32, 1 },
    { "stats",       VendorTagType::Int32, MaxBHistBinNum },
    { "stats_type",  VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionBGStats[] =
{
    { "enable",      VendorTagType::Byte,  1 },
    { "width",       VendorTagType::Int32, 1 },
    { "height",      VendorTagType::Int32, 1 },
    { "r_stats",     VendorTagType::Int32, MaxAWBBGStatsNum },
    { "g_stats",     VendorTagType::Int32, MaxAWBBGStatsNum },
    { "b_stats",     VendorTagType::Int32, MaxAWBBGStatsNum },
    { "stats_type",  VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionBEStats[] =
{
    { "enable",        VendorTagType::Byte,  1 },
    { "width",         VendorTagType::Int32, 1 },
    { "height",        VendorTagType::Int32, 1 },
    { "r_stats",       VendorTagType::Int32, MaxAWBBGStatsNum },
    { "g_stats",       VendorTagType::Int32, MaxAWBBGStatsNum },
    { "b_stats",       VendorTagType::Int32, MaxAWBBGStatsNum },
    { "stats_type",    VendorTagType::Int32, 1 },
    { "roi_be_x",      VendorTagType::Float, 1 },
    { "roi_be_y",      VendorTagType::Float, 1 },
    { "roi_be_width",  VendorTagType::Float, 1 },
    { "roi_be_height", VendorTagType::Float, 1 }
};

static VendorTagData g_VendorTagSectionInstanctAec[] =
{
    { "instant_aec_mode",            VendorTagType::Int32, 1 },
    { "instant_aec_available_modes", VendorTagType::Int32, 3 }
};

static VendorTagData g_VendorTagSectionAwbConvSpeed[] =
{
    { "awb_speed",            VendorTagType::Float, 1 }
};

static VendorTagData g_VendorTagSectionAEBracket[] =
{
    { "mode",            VendorTagType::Byte,  1 },
    { "num_frames",      VendorTagType::Int32, 1 },
    { "exposure_values", VendorTagType::Int32, 16 }
};

static VendorTagData g_VendorTagSectionTemporalDenoise[] =
{
    { "enable",         VendorTagType::Byte,  1 },
    { "process_type",   VendorTagType::Int32, 4 }
};

static VendorTagData g_VendorTagSectionStats[] =
{
    { "is_hdr_scene",                  VendorTagType::Byte, 1 },
    { VendorTagNameBSGCAvailable,      VendorTagType::Byte, 1 },
    { VendorTagNameBlinkDetected,      VendorTagType::Byte,  FDMaxFaceCount },
    { VendorTagNameBlinkDegree,        VendorTagType::Byte,  FDMaxFaceCount * sizeof(FDMetaDataBlinkDegree)},
    { VendorTagNameSmileDegree,        VendorTagType::Byte,  FDMaxFaceCount },
    { VendorTagNameSmileConfidence,    VendorTagType::Byte,  FDMaxFaceCount },
    { VendorTagNameGazeFacePose,       VendorTagType::Byte,  FDMaxFaceCount },
    { VendorTagNameGazeFaceDirection,  VendorTagType::Int32, FDMaxFaceCount * sizeof(FDMetaDataFaceDirection) / sizeof(INT32)},
    { VendorTagNameGazeDirection,      VendorTagType::Byte,  FDMaxFaceCount * sizeof(FDMetaDataGazeDirection)},
    { VendorTagNameContourPoints,      VendorTagType::Int32, FDMaxFaceCount * sizeof(FDMetaDataFaceContour) / sizeof(INT32)}
};

static VendorTagData g_VendorTagSectionManualWB[] =
{
    { "color_temperature",            VendorTagType::Int32, 1 },
    { "color_temperature_range",      VendorTagType::Int32, 2 },
    { "gains",                        VendorTagType::Float, 3 },
    { "gains_range",                  VendorTagType::Float, 2 },
    { "partial_mwb_mode",             VendorTagType::Int32, 1 },
};

static VendorTagData g_VendorTagSectionJpegEncodeCrop[] =
{
    { "enable", VendorTagType::Byte,  1 },
    { "rect",   VendorTagType::Int32, 4 },
    { "roi",    VendorTagType::Int32, 4 }
};

static VendorTagData g_VendorTagSectionSensorMeta[] =
{
    { "dynamic_black_level_pattern", VendorTagType::Float, 1 },
    { "is_mono_only",                VendorTagType::Byte,  1 },
    { "sensor_mode_index",           VendorTagType::Int32, MaxSensorModes},
    { "EEPROMInformation",           VendorTagType::Byte,  sizeof(EEPROMInformation)},
    { "integration_information",     VendorTagType::Int32, 3},
    { "mountAngle",                  VendorTagType::Int32, 1},
    { "cameraPosition",              VendorTagType::Int32, 1},
    { "sensor_mode_info",            VendorTagType::Byte,  sizeof(ChiSensorModeInfo)},
    { "sensor_pdaf_info",            VendorTagType::Byte,  sizeof(ChiSensorPDAFInfo)},
    { "current_mode",                VendorTagType::Int32, 1},
    { "targetFPS",                   VendorTagType::Int32, 1}
};

static VendorTagData g_VendorTagSectionAVTimer[] =
{
    { "use_av_timer", VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionStatsConfigs[] =
{
    { "AECStatsControl",        VendorTagType::Byte,    sizeof(AECStatsControl)   },
    { "AWBStatsControl",        VendorTagType::Byte,    sizeof(AWBStatsControl)   },
    { "AFStatsControl",         VendorTagType::Byte,    sizeof(AFStatsControl)    },
    { "AFDStatsControl",        VendorTagType::Byte,    sizeof(AFDStatsControl)   },
    { "IHistStatsControl",      VendorTagType::Byte,    sizeof(IHistStatsControl) },
    { "AECFrameControl",        VendorTagType::Byte,    sizeof(AECFrameControl)   },
    { "AWBFrameControl",        VendorTagType::Byte,    sizeof(AWBFrameControl)   },
    { "AFFrameControl",         VendorTagType::Byte,    sizeof(AFFrameControl)    },
    { "DigitalGainControl",     VendorTagType::Byte,    sizeof(FLOAT)             },
    { "AWBWarmstartGain",       VendorTagType::Float,   3                         },
    { "AWBWarmstartCCT",        VendorTagType::Float,   1                         },
    { "AWBFrameControlRGain",   VendorTagType::Float,   1                         },
    { "AWBFrameControlGGain",   VendorTagType::Float,   1                         },
    { "AWBFrameControlBGain",   VendorTagType::Float,   1                         },
    { "AWBFrameControlCCT",     VendorTagType::Int32,   1                         },
    { "AWBDecisionAfterTC",     VendorTagType::Float,   2                         },
    { "HistNodeLTCRatioIndex",  VendorTagType::Byte,    sizeof(UINT32)            },
    { "AECStartUpSensitivity",  VendorTagType::Float,   3                         },
    { "AECSensitivity",         VendorTagType::Float,   3                         },
    { "AECExposureTime",        VendorTagType::Int64,   3                         },
    { "AECLinearGain",          VendorTagType::Float,   3                         },
    { "AECLuxIndex",            VendorTagType::Float,   1                         },
    { "FOVCFrameControl",       VendorTagType::Byte,    sizeof(FOVCOutput)        },
};

static VendorTagData g_VendorTagSectionIQSettings[] =
{
    { "OEMIFEIQSetting", VendorTagType::Byte, sizeof(OEMIFEIQSetting) },
    { "OEMBPSIQSetting", VendorTagType::Byte, sizeof(OEMBPSIQSetting) },
    { "OEMIPEIQSetting", VendorTagType::Byte, sizeof(OEMIPEIQSetting) }
};

static VendorTagData g_VendorTagSectionICAConfigs[] =
{
    { "ICAInPerspectiveTransform",               VendorTagType::Byte, sizeof(IPEICAPerspectiveTransform) },
    { "ICAInGridOut2InTransform",                VendorTagType::Byte, sizeof(IPEICAGridTransform)        },
    { "ICAInGridIn2OutTransform",                VendorTagType::Byte, sizeof(IPEICAGridTransform)        },
    { "ICAInInterpolationParams",                VendorTagType::Byte, sizeof(IPEICAInterpolationParams)  },
    { "ICARefPerspectiveTransform",              VendorTagType::Byte, sizeof(IPEICAPerspectiveTransform) },
    { "ICARefGridTransform",                     VendorTagType::Byte, sizeof(IPEICAGridTransform)        },
    { "ICARefInterpolationParams",               VendorTagType::Byte, sizeof(IPEICAInterpolationParams)  },
    { "ICAReferenceParams",                      VendorTagType::Byte, sizeof(IPEICAPerspectiveTransform) },
    { "ICAReferenceParamsLookAhead",             VendorTagType::Byte, sizeof(IPEICAPerspectiveTransform) },
    { "ICAInPerspectiveTransformLookAhead",      VendorTagType::Byte, sizeof(IPEICAPerspectiveTransform) },
    { "ICAInGridTransformLookahead",             VendorTagType::Byte, sizeof(IPEICAGridTransform)        },
    { "ExtraFrameworkBuffers",                   VendorTagType::Byte, sizeof(UINT32)                     },
};

static VendorTagData g_VendorTagSectionMFNRConfigs[] =
{
    { "MFNRTotalNumFrames",                 VendorTagType::Int32, 1 },
};

static VendorTagData g_VendorTagSectionMFSRConfigs[] =
{
    { "MFSRTotalNumFrames",                 VendorTagType::Int32, 1 },
};

static VendorTagData g_VendorTagSectionStreamConfigs[] =
{
    { "HDRVideoMode", VendorTagType::Byte, 1},
};

static VendorTagData g_VendorTagSectionJPEGQuantizationTables[] =
{
    { QuantizationTableLumaVendorTagName, VendorTagType::Byte, sizeof(UINT16) * QuantTableSize   },
    { QuantizationTableChromaVendorTagName, VendorTagType::Byte, sizeof(UINT16) * QuantTableSize }
};

static VendorTagData g_VendorTagSectionSensorRegisterControl[] =
{
    { "sensor_register_control", VendorTagType::Int32, 32 }
};

static VendorTagData g_VendorTagSectionBAFStats[] =
{
    { "stats",     VendorTagType::Byte, sizeof(ParsedBFStatsOutput) }
};

static VendorTagData g_VendorTagSectionFocusValue[] =
{
    { "FocusValue",  VendorTagType::Float, 1 }
};

static VendorTagData g_VendorTagSectionIsDepthFocus[] =
{
    { "isDepthFocus",  VendorTagType::Byte, sizeof(BOOL) }
};

static VendorTagData g_VendorTagSectionTuningParam[] =
{
    { "TuningMode",  VendorTagType::Byte, sizeof(ChiTuningModeParameter)  }
};

static VendorTagData g_VendorTagSectionFeatureParam[] =
{
    { "Feature1Mode",  VendorTagType::Byte, 1  },
    { "Feature2Mode",  VendorTagType::Byte, 1  }
};

static VendorTagData g_VendorTagSectionRefCropsize[] =
{
    { "RefCropSize",  VendorTagType::Byte, sizeof(RefCropWindowSize)},
    { "DisableZoomCrop", VendorTagType::Int32, 1}
};

static VendorTagData g_VendorTagSectionIFECropInfo[] =
{
    {"ResidualCrop",         VendorTagType::Byte, sizeof(IFECropInfo) },
    {"AppliedCrop",          VendorTagType::Byte, sizeof(IFECropInfo) },
    {"SensorIFEAppliedCrop", VendorTagType::Byte, sizeof(IFECropInfo) }
};

static VendorTagData g_VendorTagSectionGammaInfo[] =
{
    { "GammaInfo",  VendorTagType::Byte, sizeof(GammaInfo) }
};

static VendorTagData g_VendorTagSectionIntermediateDimension[] =
{
    { "IntermediateDimension",  VendorTagType::Byte, sizeof(IntermediateDimensions) }
};

static VendorTagData g_VendorTagSectionQTimer[] =
{
    { "timestamp",  VendorTagType::Byte, sizeof(ChiTimestampInfo) },
};

static VendorTagData g_VendorTagSectionEISConfig[] =
{
    { "EISV3Enable",  VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionStreamTypePresent[] =
{
    { "preview",  VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionQuadCFA[] =
{
    { "is_qcfa_sensor",  VendorTagType::Byte,  1 },
    { "qcfa_dimension",  VendorTagType::Int32, 2 }
};

static VendorTagData g_VendorTagSectionVideoHDR[] =
{
    { "video_hdr_modes", VendorTagType::Int32, 2 }
};

static VendorTagData g_VendorTagSectionStreamDimension[] =
{
    { "preview",  VendorTagType::Byte, sizeof(ChiBufferDimension) },
    { "video",    VendorTagType::Byte, sizeof(ChiBufferDimension) },
    { "snapshot", VendorTagType::Byte, sizeof(ChiBufferDimension) },
    { "depth",    VendorTagType::Byte, sizeof(ChiBufferDimension) }
};

static VendorTagData g_VendorTagSectionSensorModeTable[] =
{
    { "SensorModeTable", VendorTagType::Int32, MaxSensorModeTableEntries }
};

static VendorTagData g_VendorTagSectionCustomFpsTable[] =
{
    { "CustomHFRFpsTable", VendorTagType::Int32, MaxCustomHFRSizes }
};

static VendorTagData g_VendorTagSectionStreambasedFPSTable[] =
{
    { "StreamBasedFPSTable", VendorTagType::Int32, MaxPreviewVideoFPS },
    { "PreviewFPS",          VendorTagType::Int32, 1 },
    { "VideoFPS",            VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionRecordingConfig[] =
{
    { "endOfStream",           VendorTagType::Byte,  1 },
    { "endOfStreamRequestId",  VendorTagType::Byte,  sizeof(UINT64) },
    { "requestHasVideoBuffer", VendorTagType::Byte,  1 }
};

static VendorTagData g_VendorTagSectionEarlyPCRFlag[] =
{
    { "EarlyPCRenable", VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionBurstFPSFlag[] =
{
    { "burstfps", VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionCustomNoiseReductionFlag[] =
{
    { "CustomNoiseReduction", VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionSensorModeFSFlag[] =
{
    { "isFastShutterModeSupported",  VendorTagType::Byte,  1 },
    { "SensorModeFS",                VendorTagType::Byte,  1 }
};

static VendorTagData g_VendorTagSectionHWResourceInfo[] =
{
    { "IFEMaxLineWidth",       VendorTagType::Int32,  1 },
    { "numIFEsforGivenTarget", VendorTagType::Int32,  1 },
    { "maxIFEsRequired",       VendorTagType::Int32,  1 }
};

static VendorTagData g_VendorTagSectionAECDataPublisherPresent[] =
{
    { "AECDataPublisherPresent", VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionAECData[] =
{
    { "AECData", VendorTagType::Byte, sizeof(ChiAECData) }
};

static VendorTagData g_VendorTagSectionOEMEXIFAppData[] =
{
    { "OEMEXIFAppData1", VendorTagType::Byte, sizeof(OEMJPEGEXIFAppData) }
};

static VendorTagData g_VendorTagSectionManualExposure[] =
{
    { "disableFPSLimits",  VendorTagType::Byte,  1 },
};

static VendorTagData g_VendorTagSectionLogicalCameraType[] =
{
    { "logical_camera_type", VendorTagType::Byte,  1 },
};

static VendorTagData g_VendorTagSectionSessionParameters[] =
{
    { "availableStreamMap",             VendorTagType::Int32, (sizeof(StreamMap) * MaxNumStreams)},
    { "overrideResourceCostValidation", VendorTagType::Byte,                                   1 }
};

static VendorTagData g_VendorTagSectionPlatformCapabilities[] =
{
    { "IPEICACapabilities", VendorTagType::Byte, sizeof(IPEICACapability) }
};

static VendorTagData g_VendorTagSectionExposureTableType[] =
{
    { "isValid",                       VendorTagType::Byte,  1 },
    { "sensitivityCorrectionFactor",   VendorTagType::Float, 1 },
    { "kneeCount",                     VendorTagType::Int32, 1 },
    { "gainKneeEntries",               VendorTagType::Float, MaxTableKnees },
    { "expTimeKneeEntries",            VendorTagType::Int64, MaxTableKnees },
    { "incrementPriorityKneeEntries",  VendorTagType::Int32, MaxTableKnees },
    { "expIndexKneeEntries",           VendorTagType::Float, MaxTableKnees },
    { "thresAntiBandingMinExpTimePct", VendorTagType::Float, 1 },
};

static VendorTagData g_VendorTagSectionADRC[] =
{
    { "disable", VendorTagType::Byte,  1 },
};

static VendorTagData g_VendorTagSectionMeteringTableType[] =
{
    { "meteringTable",     VendorTagType::Float, MaxMeteringTableSize },
    { "meteringTableSize", VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionltmDynamicContrast[] =
{
    {"ltmDynamicContrastStrength",         VendorTagType::Float, 1 },
    {"ltmDarkBoostStrength",               VendorTagType::Float, 1 },
    {"ltmBrightSupressStrength",           VendorTagType::Float, 1 },
    {"ltmDynamicContrastStrengthRange",    VendorTagType::Float, 2 },
    {"ltmDarkBoostStrengthRange",          VendorTagType::Float, 2 },
    {"ltmBrightSupressStrengthRange",      VendorTagType::Float, 2 }
};

static VendorTagData g_VendorTagSectionCSIDBinningInfo[] =
{
    { "csidbinninginfo", VendorTagType::Byte,  sizeof(CSIDBinningInfo) },
};

static VendorTagData g_VendorTagSectionCVPMetaData[] =
{
    { "CVPMetaData",  VendorTagType::Byte, sizeof(CVPMetaDataInternal) }
};

static VendorTagData g_VendorTagSectionNodeCropInfo[] =
{
    {"StreamCropInfo",      VendorTagType::Byte,  sizeof(StreamCropInfo) * MaxNumStreams },
    {"RequestCropInfo",     VendorTagType::Byte,  sizeof(RequestCropInfo) },
    {"AllCropInfo",         VendorTagType::Byte,  sizeof(StreamCropInfo) * MaxCropInfoEntries},
    {"EnableAllCropInfo",   VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionStreamMapInfo[] =
{
    {"StreamMap",  VendorTagType::Byte, sizeof(StreamMapMeta) }
};

static VendorTagData g_VendorTagSectionGeoLibStillFrameConfig[] =
{
    { "GeoLibStillFrameConfigPrefilter",  VendorTagType::Byte, sizeof(GeoLibStillFrameConfig) },
    { "GeoLibStillFrameConfigBlending",   VendorTagType::Byte, sizeof(GeoLibStillFrameConfig) },
    { "GeoLibStillFrameConfigPostFiler",  VendorTagType::Byte, sizeof(GeoLibStillFrameConfig) },
};

static VendorTagData g_VendorTagSectionSnapshotOutputDimension[] =
{
    { "StillOutputDimension",   VendorTagType::Byte, sizeof(GeoLibStreamOutput) },
    { "DisplayOutputDimension", VendorTagType::Byte, sizeof(GeoLibStreamOutput) },
};

static VendorTagData g_VendorTagSectionFacialAttrSettings[] =
{
    { VendorTagNameSmileSetting,   VendorTagType::Byte, 1 },
    { VendorTagNameGazeSetting,    VendorTagType::Byte, 1 },
    { VendorTagNameBlinkSetting,   VendorTagType::Byte, 1 },
    { VendorTagNameContourSetting, VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionScratchBufferData[] =
{
    { "ScratchBufferData",  VendorTagType::Byte, sizeof(ScratchBufferData) }
};

static VendorTagData g_VendorTagSectionISPConfigData[] =
{
    { "numIFEsUsed",  VendorTagType::Int32, 1 }
};

static VendorTagData g_VendorTagSectionOverrideIPEScaleProfile[] =
{
    { "OverrideIPEScaleProfile",  VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionOverrideGPURotation[] =
{
    { "OverrideGPURotationUsecase",  VendorTagType::Byte, 1 }
};

static VendorTagData g_VendorTagSectionTMCUserControl[] =
{
    { "isValidDarkBoostOffset",         VendorTagType::Byte,  1 },
    { "darkBoostOffset",                VendorTagType::Float, 1 },
    { "isValidFourthToneAnchor",        VendorTagType::Byte,  1 },
    { "fourthToneAnchor",               VendorTagType::Float, 1 }
};

// ── CHI Override Module Vendor Tags (normally from chi_override.so) ──
// These tags come from chxextensioninterface.cpp, registered via ProbeChiComponents.
// In the mock environment, no .so files are loaded, so we register them here.

static VendorTagData g_VendorTagSectionMultiCamOutput[] =
{
    { "OutputMetadataOpticalZoom", VendorTagType::Byte, 120 },
    { "OutputMetadataBokeh",      VendorTagType::Byte, 16 }
};

static VendorTagData g_VendorTagSectionMultiCamInput[] =
{
    { "InputMetadataOpticalZoom", VendorTagType::Byte, 3088 },
    { "InputMetadataBokeh",      VendorTagType::Byte, 3096 }
};

static VendorTagData g_VendorTagSectionMultiCamInfo[] =
{
    { "MultiCameraIds", VendorTagType::Byte, 12 },
    { "MasterCamera",   VendorTagType::Byte, 4 },
    { "LowPowerMode",   VendorTagType::Byte, 76 },
    { "SyncMode",        VendorTagType::Byte, 4 }
};

static VendorTagData g_VendorTagSectionBPSRealtimeCam[] =
{
    { "cameraRunningOnBPS", VendorTagType::Byte, 4 }
};

static VendorTagData g_VendorTagSectionLogicalCamInfo[] =
{
    { "NumPhysicalCameras", VendorTagType::Byte, 4 }
};

// ── Main Sections Array (81 entries) ──

static VendorTagSectionData g_HwVendorTagSections[] =
{
    { "org.codeaurora.qcamera3.saturation", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSaturation), g_VendorTagSectionSaturation, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.exposure_metering", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionExposureMetering), g_VendorTagSectionExposureMetering, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.aec_convergence_speed", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAecConvergenceSpeed), g_VendorTagSectionAecConvergenceSpeed, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.sharpness", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSharpness), g_VendorTagSectionSharpness, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.contrast", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionContrast), g_VendorTagSectionContrast, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.iso_exp_priority", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionIsoExpPriority), g_VendorTagSectionIsoExpPriority, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.histogram", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionHistogram), g_VendorTagSectionHistogram, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.bayer_grid", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionBGStats), g_VendorTagSectionBGStats, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.bayer_exposure", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionBEStats), g_VendorTagSectionBEStats, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.instant_aec", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionInstanctAec), g_VendorTagSectionInstanctAec, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.awb_convergence_speed", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAwbConvSpeed), g_VendorTagSectionAwbConvSpeed, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.ae_bracket", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAEBracket), g_VendorTagSectionAEBracket, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.jpeg_encode_crop", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionJpegEncodeCrop), g_VendorTagSectionJpegEncodeCrop, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.codeaurora.qcamera3.sensor_meta_data", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSensorMeta), g_VendorTagSectionSensorMeta, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.codeaurora.qcamera3.av_timer", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAVTimer), g_VendorTagSectionAVTimer, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.statsconfigs", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStatsConfigs), g_VendorTagSectionStatsConfigs, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.iqsettings", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionIQSettings), g_VendorTagSectionIQSettings, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.streamconfigs", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStreamConfigs), g_VendorTagSectionStreamConfigs, TagSectionVisibility::TagSectionVisibleToOEM },
    { QuantizationTableVendorTagSection, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionJPEGQuantizationTables), g_VendorTagSectionJPEGQuantizationTables, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.sensor_register_control", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSensorRegisterControl), g_VendorTagSectionSensorRegisterControl, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.ipeicaconfigs", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionICAConfigs), g_VendorTagSectionICAConfigs, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.mfnrconfigs", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMFNRConfigs), g_VendorTagSectionMFNRConfigs, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.mfsrconfigs", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMFSRConfigs), g_VendorTagSectionMFSRConfigs, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.debugdata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionDebugData), g_VendorTagSectionDebugData, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.tuningdata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTuningdataDump), g_VendorTagSectionTuningdataDump, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.focusvalue", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionFocusValue), g_VendorTagSectionFocusValue, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.bafstats", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionBAFStats), g_VendorTagSectionBAFStats, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.tuning.mode", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTuningParam), g_VendorTagSectionTuningParam, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.tuning.feature", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionFeatureParam), g_VendorTagSectionFeatureParam, TagSectionVisibility::TagSectionVisibleToAll },
    { VendorTagSectionOEMFDConfig, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionOEMFDConfig), g_VendorTagSectionOEMFDConfig, TagSectionVisibility::TagSectionVisibleToOEM },
    { VendorTagSectionOEMFDResults, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionOEMFDResults), g_VendorTagSectionOEMFDResults, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.objectTrackingConfig", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTrackerConfig), g_VendorTagSectionTrackerConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.objectTrackingResults", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTrackerResults), g_VendorTagSectionTrackerResults, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.ref.cropsize", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionRefCropsize), g_VendorTagSectionRefCropsize, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.manualWB", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionManualWB), g_VendorTagSectionManualWB, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.temporal_denoise", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTemporalDenoise), g_VendorTagSectionTemporalDenoise, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.ifecropinfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionIFECropInfo), g_VendorTagSectionIFECropInfo, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.eis3enable", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionEISConfig), g_VendorTagSectionEISConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.streamTypePresent", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStreamTypePresent), g_VendorTagSectionStreamTypePresent, TagSectionVisibility::TagSectionVisibleToOEM },
    { VendorTagSectionEISRealTimeConfig, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionEISRealTimeConfig), g_VendorTagSectionEISRealTimeConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { VendorTagSectionEISLookAheadConfig, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionEISLookAheadConfig), g_VendorTagSectionEISLookAheadConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.qtimer", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionQTimer), g_VendorTagSectionQTimer, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.codeaurora.qcamera3.stats", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStats), g_VendorTagSectionStats, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.quadra_cfa", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionQuadCFA), g_VendorTagSectionQuadCFA, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.available_video_hdr_modes", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionVideoHDR), g_VendorTagSectionVideoHDR, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.streamDimension", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStreamDimension), g_VendorTagSectionStreamDimension, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera2.sensormode.info", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSensorModeTable), g_VendorTagSectionSensorModeTable, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.customhfrfps.info", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionCustomFpsTable), g_VendorTagSectionCustomFpsTable, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera2.streamBasedFPS.info", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStreambasedFPSTable), g_VendorTagSectionStreambasedFPSTable, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.gammainfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionGammaInfo), g_VendorTagSectionGammaInfo, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.intermediateDimension", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionIntermediateDimension), g_VendorTagSectionIntermediateDimension, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.recording", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionRecordingConfig), g_VendorTagSectionRecordingConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.manualExposure", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionManualExposure), g_VendorTagSectionManualExposure, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.EarlyPCRenable", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionEarlyPCRFlag), g_VendorTagSectionEarlyPCRFlag, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.BurstFPS", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionBurstFPSFlag), g_VendorTagSectionBurstFPSFlag, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.CustomNoiseReduction", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionCustomNoiseReductionFlag), g_VendorTagSectionCustomNoiseReductionFlag, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.SensorModeFS", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSensorModeFSFlag), g_VendorTagSectionSensorModeFSFlag, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.HWResourceInfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionHWResourceInfo), g_VendorTagSectionHWResourceInfo, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.AECDataPublisherPresent", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAECDataPublisherPresent), g_VendorTagSectionAECDataPublisherPresent, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.AECData", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionAECData), g_VendorTagSectionAECData, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.oemexifappdata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionOEMEXIFAppData), g_VendorTagSectionOEMEXIFAppData, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.isDepthFocus", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionIsDepthFocus), g_VendorTagSectionIsDepthFocus, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.logicalCameraType", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionLogicalCameraType), g_VendorTagSectionLogicalCameraType, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.platformCapabilities", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionPlatformCapabilities), g_VendorTagSectionPlatformCapabilities, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.exposuretable", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionExposureTableType), g_VendorTagSectionExposureTableType, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.meteringtable", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMeteringTableType), g_VendorTagSectionMeteringTableType, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.adrc", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionADRC), g_VendorTagSectionADRC, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.codeaurora.qcamera3.sessionParameters", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSessionParameters), g_VendorTagSectionSessionParameters, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.ltmDynamicContrast", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionltmDynamicContrast), g_VendorTagSectionltmDynamicContrast, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.ifecsidconfig", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionCSIDBinningInfo), g_VendorTagSectionCSIDBinningInfo, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.cvpMetaData", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionCVPMetaData), g_VendorTagSectionCVPMetaData, TagSectionVisibility::TagSectionVisibleToAll },
    { "com.qti.camera.streamCropInfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionNodeCropInfo), g_VendorTagSectionNodeCropInfo, TagSectionVisibility::TagSectionVisibleToOEM },
    { "com.qti.camera.streamMapMeta", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionStreamMapInfo), g_VendorTagSectionStreamMapInfo, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.geoLibStillFrameConfig", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionGeoLibStillFrameConfig), g_VendorTagSectionGeoLibStillFrameConfig, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.snapshotOutputDimension", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionSnapshotOutputDimension), g_VendorTagSectionSnapshotOutputDimension, TagSectionVisibility::TagSectionVisibleToAll },
    { VendorTagSectionFacialAttrSettings, 0, CAMX_ARRAY_SIZE(g_VendorTagSectionFacialAttrSettings), g_VendorTagSectionFacialAttrSettings, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.scratchbufferdata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionScratchBufferData), g_VendorTagSectionScratchBufferData, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.ISPConfigData", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionISPConfigData), g_VendorTagSectionISPConfigData, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.quic.camera.overrideIPEScaleProfile", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionOverrideIPEScaleProfile), g_VendorTagSectionOverrideIPEScaleProfile, TagSectionVisibility::TagSectionVisibleToOEM },
    { "org.codeaurora.qcamera3.tmcusercontrol", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionTMCUserControl), g_VendorTagSectionTMCUserControl, TagSectionVisibility::TagSectionVisibleToAll },
    { "org.quic.camera.overrideGPURotationUsecase", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionOverrideGPURotation), g_VendorTagSectionOverrideGPURotation, TagSectionVisibility::TagSectionVisibleToOEM },
    // CHI Override Module tags
    { "com.qti.chi.multicameraoutputmetadata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMultiCamOutput), g_VendorTagSectionMultiCamOutput, TagSectionVisibility::TagSectionVisibleToAll },
    { "com.qti.chi.multicamerainputmetadata", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMultiCamInput), g_VendorTagSectionMultiCamInput, TagSectionVisibility::TagSectionVisibleToAll },
    { "com.qti.chi.multicamerainfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionMultiCamInfo), g_VendorTagSectionMultiCamInfo, TagSectionVisibility::TagSectionVisibleToAll },
    { "com.qti.chi.bpsrealtimecam", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionBPSRealtimeCam), g_VendorTagSectionBPSRealtimeCam, TagSectionVisibility::TagSectionVisibleToAll },
    { "com.qti.chi.logicalcamerainfo", 0, CAMX_ARRAY_SIZE(g_VendorTagSectionLogicalCamInfo), g_VendorTagSectionLogicalCamInfo, TagSectionVisibility::TagSectionVisibleToAll },
};

void GetHwVendorTagInfo(VendorTagInfo* pInfo)
{
    pInfo->pVendorTagDataArray = g_HwVendorTagSections;
    pInfo->numSections         = CAMX_ARRAY_SIZE(g_HwVendorTagSections);
}

CAMX_NAMESPACE_END
