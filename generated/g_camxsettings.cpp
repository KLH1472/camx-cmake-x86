////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  g_camxsettings.cpp
/// @brief Hardware Independent Settings implementation.
///
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///             !!!!!!! AUTO-GENERATED FILE! DO NOT EDIT! Make all changes in camxsettings.xml. !!!!!!!
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxincs.h"
#include "camxsettingsmanager.h"

#include "g_camxsettings.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Type Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EnumeratorToHashMap CSLModeTypeEnumeratorToHashMap[] =
{
    {0x554AF45D, CSLModeHardware                 }, ///< Hardware CSL implementation, using the standard CamX KMD and hardware
    {0x987F38D3, CSLModeIFH                      }, ///< Infinitely Fast Hardware CSL implementation, bypassing the KMD
    {0xAF2E8D73, CSLModePresil                   }, ///< Presil CSIM CSL Implementation
    {0xD7022B21, CSLModePresilRUMI               }, ///< Presil RUMI CSL Implementation
};

EnumeratorToHashMap EnableAFAlgoTypeEnumeratorToHashMap[] =
{
    {0xC55D4949, EnableAFAlgoDisabled            }, ///< AF algorithm tuning override is disabled
    {0xDF52EA11, EnableAFAlgoPDAF                }, ///< Override tuning and enable only PDAF
    {0xBEFA8634, EnableAFAlgoTOF                 }, ///< Override tuning and enable only TOF
    {0xEB1EE2BD, EnableAFAlgoDCIAF               }, ///< Override tuning and enable only DCIAF
    {0xBEFADBF4, EnableAFAlgoCAF                 }, ///< Override tuning and enable only CAF
};

EnumeratorToHashMap AFFullsweepTypeEnumeratorToHashMap[] =
{
    {0x229DDC20, AFFullsweepDisabled             }, ///< AF fullsweep is disabled
    {0x983F5194, AFFullsweepInfinityToMacro      }, ///< Performs fullsweep starting from Infinity to Macro
    {0x57FF43DA, AFFullsweepMacroToInfinity      }, ///< Performs fullsweep starting from Macro to Infinity
    {0xE753B41B, AFFullsweepBothDirection        }, ///< Performs fullsweep starting from Infinity to Macro and back
};

EnumeratorToHashMap AFManualLensControlTypeEnumeratorToHashMap[] =
{
    {0x693BDE49, AFManualLensControlDisabled     }, ///< Manual lens control is disabled
    {0x8DB147A7, AFManualLensControlDAC          }, ///< Move lens manually using DAC value
    {0x660DDB5A, AFManualLensControlLogical      }, ///< Move lens manually giving logical lens position
};

EnumeratorToHashMap MultiCamera3ASyncTypeEnumeratorToHashMap[] =
{
    {0xEF3C7A7E, MultiCamera3ASyncDisabled       }, ///< No 3A sync
    {0x8E630ACE, MultiCamera3ASyncQTI            }, ///< QTI standard 3A sync solution
    {0xAB6B9DD4, MultiCamera3ASyncSingleton      }, ///< 3A sync solution with only one algorithm instance
};

EnumeratorToHashMap MultiCameraHWSyncTypeEnumeratorToHashMap[] =
{
    {0x8F3C7AC9, MultiCameraHWSyncDisabled       }, ///< Disable the HW sync
    {0x8E635D75, MultiCameraHWSyncRTB            }, ///< Enable the HW Sync for RTB usecase
    {0x8E635BC3, MultiCameraHWSyncSAT            }, ///< Enable the HW Sync for SAT usecase
    {0xBC731A6E, MultiCameraHWSyncVR             }, ///< Enable the HW Sync for VR usecase
};

EnumeratorToHashMap OutputFormatTypeEnumeratorToHashMap[] =
{
    {0x48BE7AE6, OutputFormatYUV420NV12          }, ///< Linear NV12 format
    {0xFA4D3C5E, OutputFormatUBWCNV12            }, ///< UBWC NV12 format
    {0xFA40245C, OutputFormatUBWCTP10            }, ///< UBWC TP10 format
    {0xF1ACEEFB, OutputFormatRAWPLAIN16          }, ///< Raw Plain16 format
    {0xBE265F34, OutputFormatPD10                }, ///< PD10 format
    {0xBE270F34, OutputFormatP010                }, ///< LinerP010 format
    {0x48BE7A85, OutputFormatYUV420NV21          }, ///< Linear NV21 format
    {0xF1ACEE19, OutputFormatRAWPLAIN64          }, ///< Raw Plain64 format
};

EnumeratorToHashMap RefOutputFormatTypeEnumeratorToHashMap[] =
{
    {0xFA5C683C, RefOutputFormatUBWCTP10         }, ///< UBWC TP10 format
    {0x45C0FD1B, RefOutputFormatUBWCNV124R       }, ///< UBWCNV124R format
    {0x398FFAE6, RefOutputFormatYUV420NV12       }, ///< Linear NV12 format
    {0xAE585EEF, RefOutputFormatYUV420NV12TP10   }, ///< Linear NV12 format
    {0x7AE10F35, RefOutputFormatP010             }, ///< LinerP010 format
};

EnumeratorToHashMap FDProcessingControlTypeEnumeratorToHashMap[] =
{
    {0x39F5B5EE, FDProcessingControlForceDisable }, ///< Force disable FD processing
    {0x5BB6A065, FDProcessingControlForceEnable  }, ///< Force enable FD processing
    {0x4390D82C, FDProcessingControlAppRequest   }, ///< Enable/Disable FD processing based on App request
};

EnumeratorToHashMap FDBaseResolutionTypeEnumeratorToHashMap[] =
{
    {0x50A9E144, FDBaseResolution640x480         }, ///< FD base resolution width 640 height 480
    {0xD2E9E147, FDBaseResolution854x480         }, ///< FD base resolution width 854 height 480
    {0x1CA9F8C5, FDBaseResolution320x240         }, ///< FD base resolution width 320 height 240
    {0xDCD9F8C4, FDBaseResolution427x240         }, ///< FD base resolution width 427 height 240
};

EnumeratorToHashMap FDConfigSourceTypeEnumeratorToHashMap[] =
{
    {0xCA65EA9B, FDConfigDefault                 }, ///< Fetch default configuration
    {0x9C05716C, FDConfigVendorTag               }, ///< Fetch configuration from vendor tag
    {0x72972FA2, FDConfigBinary                  }, ///< Fetch configuration from tunning binary
};

EnumeratorToHashMap FDMultiCamProcessingTypeEnumeratorToHashMap[] =
{
    {0x42379348, FDMultiCamProcessMasterOnly     }, ///< Process only master requests at full fps
    {0x65DF2BB9, FDMultiCamProcessAuxOnly        }, ///< Process only aux requests at full fps
    {0x3C81223A, FDMultiCamProcessBoth           }, ///< Process both master and aux at half fps
};

EnumeratorToHashMap FDFilterEngineTypeEnumeratorToHashMap[] =
{
    {0x6A325E58, FD_Standard_ARM                 }, ///< Use FD_Standard_ARM as FD filter
    {0x6A324A65, FD_Standard_DSP                 }, ///< Use FD_Standard_DSP as FD filter
    {0x0EEE6F1A, FD_DL_ARM                       }, ///< Use FD_DL_ARM as FD filter
    {0x0EEE7B27, FD_DL_DSP                       }, ///< Use FD_DL_DSP as FD filter
    {0x0E8F8997, FD_DL_DSP_and_Standard_ARM      }, ///< Use FD_DL_DSP and supplement with FD_Standard_ARM when certain conditions are met
};

EnumeratorToHashMap FDClientTypeEnumeratorToHashMap[] =
{
    {0x17AC6219, FDHWHybrid                      }, ///< Use FD HW as FD Client
    {0xE14636D0, FDSWOnly                        }, ///< Use FD SW as FD Client
};

EnumeratorToHashMap FDPreProcessingTypeEnumeratorToHashMap[] =
{
    {0xD50105FC, Disable                         }, ///< Disable FD pre-processing
    {0xD4DBF070, AdaptiveGTM                     }, ///< Adaptive Tone Map preprocessing
    {0x000192ED, GTM                             }, ///< Global Tone Map preprocessing
    {0x0001BEED, LTM                             }, ///< Local Tone Map preprocessing
};

EnumeratorToHashMap FDThreadTaskAllocationTypeEnumeratorToHashMap[] =
{
    {0xDD092B29, PTDOnPriThread                  }, ///< Run PTD on the primary worker thread of FD Manager Node
    {0x5D092893, PTDOnSecThread                  }, ///< Run PTD on the secondary worker thread of FD Manager Node
};

EnumeratorToHashMap ImageDumpTypeEnumeratorToHashMap[] =
{
    {0x3A3E379E, ImageDumpNone                   }, ///< No dumps
    {0xD9D1EC94, ImageDumpIFE                    }, ///< All output ports for IFE
    {0xD9D1EE54, ImageDumpIPE                    }, ///< All output ports for IPE
    {0xD9D1C242, ImageDumpBPS                    }, ///< All output ports for BPS
    {0x3A3C4AFC, ImageDumpJPEG                   }, ///< All JPEG output ports for all JPEG nodes
    {0x3A3A1B4C, ImageDumpFDHw                   }, ///< All output ports for FDHw
    {0x3A3F43FE, ImageDumpLRME                   }, ///< All output ports for LRME
    {0xC03E2CAB, ImageDumpRANSAC                 }, ///< All output ports for RANSAC
    {0x55BB2DF9, ImageDumpChiNode                }, ///< All output ports for all ChiNodes
    {0xD9D1C681, ImageDumpCVP                    }, ///< All output ports for CVP
    {0x3A3FAC38, ImageDumpMisc                   }, ///< All other nodes not explicitly listed above
};

EnumeratorToHashMap DualLEDCalibrationTypeEnumeratorToHashMap[] =
{
    {0xFDD5BFF3, DualLEDCalibrationDisabled      }, ///< Dual LED Calibration is disabled
    {0xEC31D4E7, DualLEDCalibrationTuning        }, ///< Dual LED is being tuned for the golden module
    {0xE3AD4824, DualLEDCalibrationCalibration   }, ///< Dual LED is being calibrated
};

EnumeratorToHashMap CHIPartialDataTypeEnumeratorToHashMap[] =
{
    {0x58FFD925, CHIPartialDataDisable           }, ///< CHI Partial Data will be disabled
    {0x19F31255, CHIPartialDataSeparate          }, ///< CHI Partial Data will be sent separately
    {0xA3CEACF6, CHIPartialDataCombined          }, ///< CHI Partial Data will be sent along with Core Partial Data
};

EnumeratorToHashMap AlignmentFusionModesEnumeratorToHashMap[] =
{
    {0x0B21E2EB, AlignImageBaseOnly              }, ///< Alignment based on image only
    {0x726E6379, AlignGyroBaseOnly               }, ///< Alignment based on gyro only
    {0x88D13895, AlignAuto                       }, ///< Alignment auto, default option
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SettingsManager Method Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsManager::InitializeDefaultSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID SettingsManager::InitializeDefaultSettings()
{
    m_pStaticSettings->outputFormat                   = OutputFormatUBWCNV12;
    m_pStaticSettings->refoutputFormatType            = RefOutputFormatUBWCTP10;
    m_pStaticSettings->IsStrideSettingEnable          = FALSE;
    m_pStaticSettings->numMetadataResults             = 2;
    m_pStaticSettings->maxHalRequests                 = 6;
    m_pStaticSettings->waitAllResultsTimeout          = 3500;
    m_pStaticSettings->numWorkerThreads               = 3;
    m_pStaticSettings->chiOverrideEnable              = TRUE;
    m_pStaticSettings->multiCameraEnable              = FALSE;
    m_pStaticSettings->multiCameraJPEG                = 1;
    m_pStaticSettings->multiCameraEnableFront         = FALSE;
    m_pStaticSettings->multiCameraVREnable            = 0;
    m_pStaticSettings->multiCameraHWSyncMask          = 0x1;
    m_pStaticSettings->multiCameraFrameSync           = 0;
    m_pStaticSettings->enableSensorFpsMatch           = FALSE;
    m_pStaticSettings->multiCamera3ASync              = MultiCamera3ASyncQTI;
    m_pStaticSettings->numberOfAELockFrames           = 1;
    m_pStaticSettings->exportSecureCamera             = FALSE;
    m_pStaticSettings->enableRAWProcessing            = TRUE;
    m_pStaticSettings->maxRAWSizes                    = 1;
    m_pStaticSettings->enableInternalHALPixelStreamConfig = FALSE;
    m_pStaticSettings->enableNCSService               = TRUE;
    m_pStaticSettings->minReprocessInputWidth         = 2592;
    m_pStaticSettings->minReprocessInputHeight        = 1944;
    m_pStaticSettings->minInOutResolution             = 0;
    m_pStaticSettings->maxInOutResolution             = 200;
    m_pStaticSettings->enableTOFInterface             = FALSE;
    m_pStaticSettings->enableThermalMitigation        = TRUE;
    m_pStaticSettings->maxBuffersSecureCamera         = 3;
    m_pStaticSettings->enableNativeHEIF               = TRUE;
    m_pStaticSettings->enableHALFormatOverride        = FALSE;
    m_pStaticSettings->maxNumberOfAcceptedErrors      = 10;
    m_pStaticSettings->enableResourceManager          = FALSE;
    m_pStaticSettings->enableStreamCropZoom           = FALSE;
    m_pStaticSettings->bpsRealtimeSensorId            = 0xFFFFFFFF;
    m_pStaticSettings->enableBLMClient                = 0;
    m_pStaticSettings->assertMask                     = 0;
    m_pStaticSettings->logWarningMask                 = 0xFFFFFFFF;
    m_pStaticSettings->logEntryExitMask               = 0;
    m_pStaticSettings->logConfigMask                  = 0xFFFFFFFF;
    m_pStaticSettings->logDumpMask                    = 0xFFFFFFFF;
    m_pStaticSettings->logInfoMask                    = 0x1C080;
    m_pStaticSettings->logPerfInfoMask                = 0;
    m_pStaticSettings->logVerboseMask                 = 0x0;
    m_pStaticSettings->logDRQEnable                   = FALSE;
    m_pStaticSettings->logMetaEnable                  = FALSE;
    m_pStaticSettings->logRequestMapping              = TRUE;
    m_pStaticSettings->traceErrorEnable               = FALSE;
    m_pStaticSettings->systemLogEnable                = TRUE;
    m_pStaticSettings->enablePipelineFlush            = TRUE;
    OsUtils::StrLCpy(m_pStaticSettings->debugLogFilename, "", sizeof(m_pStaticSettings->debugLogFilename));
    m_pStaticSettings->traceGroupsEnable              = 0;
    m_pStaticSettings->enableFPSLog                   = FALSE;
    m_pStaticSettings->maxMemSpyStats                 = 50;
    m_pStaticSettings->memSpyRequestRate              = 0;
    m_pStaticSettings->enableHJAF                     = TRUE;
    m_pStaticSettings->enableSPD                      = TRUE;
    m_pStaticSettings->spdStatsType                   = 0;
    m_pStaticSettings->disableFocusIndication         = 0;
    m_pStaticSettings->spotlightFallbackToCAF         = 0;
    m_pStaticSettings->afLog                          = 0;
    m_pStaticSettings->fovcEnable                     = 0;
    m_pStaticSettings->gyroDataReportRate             = 10000;
    m_pStaticSettings->gyroSensorSamplingRate         = 104.0F;
    m_pStaticSettings->gravityDataReportRate          = 30000;
    m_pStaticSettings->gravitySensorSamplingRate      = 52.0F;
    m_pStaticSettings->TOFDataReportRate              = 30000;
    m_pStaticSettings->TOFSensorSamplingRate          = 52.0F;
    OsUtils::StrLCpy(m_pStaticSettings->customTOFSensorLib, "", sizeof(m_pStaticSettings->customTOFSensorLib));
    m_pStaticSettings->mwEnable                       = TRUE;
    m_pStaticSettings->enableAFAlgo                   = EnableAFAlgoDisabled;
    m_pStaticSettings->afFullsweep                    = AFFullsweepDisabled;
    m_pStaticSettings->manualAf                       = AFManualLensControlDisabled;
    m_pStaticSettings->lensPos                        = 0;
    OsUtils::StrLCpy(m_pStaticSettings->vmDebugMask, "", sizeof(m_pStaticSettings->vmDebugMask));
    m_pStaticSettings->AFRecorderMode                 = 0;
    m_pStaticSettings->enableLensSagComp              = TRUE;
    OsUtils::StrLCpy(m_pStaticSettings->activeNodeMask, "", sizeof(m_pStaticSettings->activeNodeMask));
    m_pStaticSettings->apiMask                        = 0;
    m_pStaticSettings->manualExposureType             = FALSE;
    m_pStaticSettings->dualBHistSupport               = FALSE;
    m_pStaticSettings->disableBGStatsForAF            = FALSE;
    m_pStaticSettings->enableCustomAlgoAEC            = FALSE;
    m_pStaticSettings->disableAFAWBpreFlash           = FALSE;
    m_pStaticSettings->yuvPlaneAlignment              = 4096;
    m_pStaticSettings->preFlashMaxFrameWaitLimitAF    = 20;
    m_pStaticSettings->preFlashMaxFrameWaitLimitAWB   = 3;
    m_pStaticSettings->disablePreFlashOnForTouchAE    = FALSE;
    m_pStaticSettings->numberOfFramesToSkip           = 2;
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAECName, "com.qtistatic.stats.aec", sizeof(m_pStaticSettings->customAlgoAECName));
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAECPath, "", sizeof(m_pStaticSettings->customAlgoAECPath));
    m_pStaticSettings->enableCustomAlgoAWB            = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAWBName, "com.qtistatic.stats.awb", sizeof(m_pStaticSettings->customAlgoAWBName));
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAWBPath, "", sizeof(m_pStaticSettings->customAlgoAWBPath));
    m_pStaticSettings->enableCustomAlgoAF             = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAFName, "com.qtistatic.stats.af", sizeof(m_pStaticSettings->customAlgoAFName));
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAFPath, "", sizeof(m_pStaticSettings->customAlgoAFPath));
    m_pStaticSettings->enableCustomHAFAlgo            = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customHAFAlgoName, "", sizeof(m_pStaticSettings->customHAFAlgoName));
    OsUtils::StrLCpy(m_pStaticSettings->customHAFAlgoPath, "", sizeof(m_pStaticSettings->customHAFAlgoPath));
    m_pStaticSettings->overrideHAFAlgoMask            = 0;
    m_pStaticSettings->exposureGain                   = 1.0F;
    m_pStaticSettings->exposureTime                   = 22000000;
    m_pStaticSettings->luxIndex                       = 316.771F;
    m_pStaticSettings->extendedTimeForLongExposure    = TRUE;
    m_pStaticSettings->manualWhiteBalanceType         = FALSE;
    m_pStaticSettings->rGain                          = 1.700643F;
    m_pStaticSettings->gGain                          = 1.0F;
    m_pStaticSettings->BGain                          = 2.054097F;
    m_pStaticSettings->colorTemp                      = 4100;
    m_pStaticSettings->ignoreSceneMode                = FALSE;
    m_pStaticSettings->enableCustomAlgoASD            = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoASDName, "libcamxstaticasdalgo", sizeof(m_pStaticSettings->customAlgoASDName));
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoASDPath, "", sizeof(m_pStaticSettings->customAlgoASDPath));
    m_pStaticSettings->enableCustomAlgoAFD            = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAFDName, "libcamxstaticafdalgo", sizeof(m_pStaticSettings->customAlgoAFDName));
    OsUtils::StrLCpy(m_pStaticSettings->customAlgoAFDPath, "", sizeof(m_pStaticSettings->customAlgoAFDPath));
    m_pStaticSettings->enableDualIFE                  = TRUE;
    m_pStaticSettings->forceDualIFEOn                 = FALSE;
    m_pStaticSettings->dualIFESplitPointOffset        = 0;
    m_pStaticSettings->dualIFELeftPadding             = 0;
    m_pStaticSettings->dualIFERightPadding            = 0;
    m_pStaticSettings->IFETestImageSizeWidth          = 1920;
    m_pStaticSettings->IFETestImageSizeHeight         = 1080;
    m_pStaticSettings->IsOEMStatSettingEnable         = FALSE;
    m_pStaticSettings->DisableManual3ACCM             = FALSE;
    m_pStaticSettings->IFENumFramesHighBW             = 10;
    m_pStaticSettings->pdafHWEnable                   = TRUE;
    m_pStaticSettings->enableIFERegDump               = FALSE;
    m_pStaticSettings->enableActiveIFEABVote          = FALSE;
    m_pStaticSettings->IFEDynamicEnableMask           = 0xFFFFFFFF;
    m_pStaticSettings->ifeClockFrequencyMHz           = 0;
    m_pStaticSettings->ifeCamnocBandwidthMBytes       = 0;
    m_pStaticSettings->ifeExternalBandwidthMBytes     = 0;
    m_pStaticSettings->enableHVXStreaming             = FALSE;
    m_pStaticSettings->enableIPEIQModulesMask         = 0xFFFFFF;
    m_pStaticSettings->enableIPEUpscale               = FALSE;
    m_pStaticSettings->enableIPEOnlyDownscale         = FALSE;
    m_pStaticSettings->disableIPEInternalDownscale    = FALSE;
    m_pStaticSettings->enableIPEDependencies          = TRUE;
    m_pStaticSettings->enableIPEIQLogging             = FALSE;
    m_pStaticSettings->enableMCTF                     = TRUE;
    m_pStaticSettings->disableCVPDriver               = FALSE;
    m_pStaticSettings->numIPECoresToUse               = 2;
    m_pStaticSettings->force8BitUBWCAlignment         = FALSE;
    m_pStaticSettings->setLRMETransformTypeMask       = 0x1;
    m_pStaticSettings->isGridFromChromatixEnabled     = FALSE;
    m_pStaticSettings->alignmentFusionMode            = AlignAuto;
    m_pStaticSettings->isFirstFrameLoopbackInputImageEnabled = 0x1;
    m_pStaticSettings->enableLDC                      = TRUE;
    OsUtils::StrLCpy(m_pStaticSettings->debugDataHeaderString, "QTI Debug Metadata", sizeof(m_pStaticSettings->debugDataHeaderString));
    m_pStaticSettings->enable3ADebugData              = FALSE;
    m_pStaticSettings->debugDataSizeAEC               = 540000;
    m_pStaticSettings->debugDataSizeAWB               = 1100000;
    m_pStaticSettings->debugDataSizeAF                = 70000;
    m_pStaticSettings->enableTuningMetadata           = FALSE;
    m_pStaticSettings->tuningDumpDataSizeIFE          = 8800;
    m_pStaticSettings->tuningDumpDataSizeIPE          = 300000;
    m_pStaticSettings->tuningDumpDataSizeBPS          = 23000;
    m_pStaticSettings->dumpDebugDataEveryProcessResult = 0;
    m_pStaticSettings->debugDataOfflineAlloc          = FALSE;
    m_pStaticSettings->disablePDLibCHIOverload        = FALSE;
    m_pStaticSettings->enableCustomPDLib              = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->customPDLibName, "libcom.qtistatic.stats.pdlib", sizeof(m_pStaticSettings->customPDLibName));
    OsUtils::StrLCpy(m_pStaticSettings->customPDLibPath, "", sizeof(m_pStaticSettings->customPDLibPath));
    m_pStaticSettings->tintlessEnable                 = TRUE;
    m_pStaticSettings->enablePDLibLog                 = FALSE;
    m_pStaticSettings->enablePDLibTestMode            = 0;
    m_pStaticSettings->enablePDLibProfiling           = FALSE;
    m_pStaticSettings->enablePDLibDump                = 0;
    m_pStaticSettings->disablePDLibLCR                = FALSE;
    m_pStaticSettings->ifeSWCDMEnable                 = FALSE;
    m_pStaticSettings->enableAEScan                   = 0;
    m_pStaticSettings->overrideLogLevels              = 0x1F;
    m_pStaticSettings->overrideDisableZSL             = 0;
    m_pStaticSettings->enableLRMEDS2                  = FALSE;
    m_pStaticSettings->overrideEnableMFNR             = 0;
    m_pStaticSettings->anchorSelectionAlgoForMFNR     = 2;
    m_pStaticSettings->anchorAlgoSelectionType        = 1;
    m_pStaticSettings->advanceFeatureMask             = 64;
    m_pStaticSettings->enableOfflineNoiseReprocess    = 0;
    m_pStaticSettings->enableGamma15PreCalculate      = 1;
    m_pStaticSettings->overrideForceUsecaseId         = 0xffffffff;
    m_pStaticSettings->overrideForceSensorMode        = 0xffffffff;
    m_pStaticSettings->overrideForceFSCapable         = FALSE;
    m_pStaticSettings->overrideGPURotationUsecase     = 0;
    m_pStaticSettings->overrideGPUDownscaleUsecase    = 0;
    m_pStaticSettings->overrideHFRNo3AUseCase         = 0;
    m_pStaticSettings->overrideCameraClose            = 0;
    m_pStaticSettings->overrideCameraOpen             = 0;
    m_pStaticSettings->overridePDLibClose             = 1;
    m_pStaticSettings->overridePDLibOpen              = 1;
    m_pStaticSettings->EISV2Enable                    = 1;
    m_pStaticSettings->EISV3Enable                    = 1;
    m_pStaticSettings->EISV2Margin                    = 0.2F;
    m_pStaticSettings->EISV2FrameDelay                = 0;
    m_pStaticSettings->EISV3Margin                    = 0.2F;
    m_pStaticSettings->EISV3FrameDelay                = 15;
    m_pStaticSettings->numPCRsBeforeStreamOn          = 1;
    m_pStaticSettings->maxImageBufferTimeoutCount     = 3;
    m_pStaticSettings->imageBufferWaitTime            = 800;
    m_pStaticSettings->overrideMaxImageBufferCountRealTime = 64;
    m_pStaticSettings->overrideMaxImageBufferCountNonRealTime = 64;
    m_pStaticSettings->statsProcessingSkipFactor      = 1;
    m_pStaticSettings->maxNonHfrFps                   = 30;
    m_pStaticSettings->minFrameRateBound              = 10;
    m_pStaticSettings->enableOISOptimization          = FALSE;
    m_pStaticSettings->enableSensorCaching            = TRUE;
    m_pStaticSettings->forceDebugQCFASWRemosaic       = FALSE;
    m_pStaticSettings->enableCHIPartialData           = CHIPartialDataDisable;
    m_pStaticSettings->enableCHIPartialDataRecovery   = 1;
    m_pStaticSettings->dumpMetadata                   = 0;
    m_pStaticSettings->memsetInputMeta                = 1;
    m_pStaticSettings->enableLinearMetaLUT            = TRUE;
    m_pStaticSettings->enableFDStreamInRealTime       = 0;
    m_pStaticSettings->selectInSensorHDR3ExpUsecase   = 0;
    m_pStaticSettings->enableUnifiedBufferManager     = 1;
    m_pStaticSettings->enableCHIImageBufferLateBinding = 1;
    m_pStaticSettings->enableFeature2Dump             = 0;
    m_pStaticSettings->forceHWMFFixedNumOfFrames      = 0;
    m_pStaticSettings->enableTBMChiFence              = 0;
    m_pStaticSettings->enableMFSRChiFence             = 1;
    m_pStaticSettings->enableRawHDR                   = 1;
    m_pStaticSettings->FDProcessingControl            = FDProcessingControlAppRequest;
    m_pStaticSettings->enableFDManagerThreading       = TRUE;
    m_pStaticSettings->FDBaseResolution               = FDBaseResolution640x480;
    m_pStaticSettings->FDConfigSource                 = FDConfigDefault;
    m_pStaticSettings->FDMultiCamProcess              = FDMultiCamProcessBoth;
    m_pStaticSettings->useAlternateFrameSkip          = TRUE;
    m_pStaticSettings->useDeviceOrientationInFD       = TRUE;
    m_pStaticSettings->getAccelInfoUsingVendorTag     = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->accelVendorTagSection, "none", sizeof(m_pStaticSettings->accelVendorTagSection));
    OsUtils::StrLCpy(m_pStaticSettings->accelVendorTagName, "accelerometerValues", sizeof(m_pStaticSettings->accelVendorTagName));
    m_pStaticSettings->FDFilterEngine                 = FD_DL_DSP_and_Standard_ARM;
    m_pStaticSettings->FDClient                       = FDHWHybrid;
    m_pStaticSettings->disablePostingResults          = FALSE;
    m_pStaticSettings->enableOfflineFD                = FALSE;
    m_pStaticSettings->MetadataVisibility             = TRUE;
    m_pStaticSettings->useDifferentTuningForFrontCamera = FALSE;
    m_pStaticSettings->useFDInternalBuffers           = FALSE;
    m_pStaticSettings->useFDUseCasePool               = TRUE;
    m_pStaticSettings->fastFDMetadata                 = FALSE;
    m_pStaticSettings->minReqFdDependency             = 3;
    m_pStaticSettings->FDPreprocessing                = AdaptiveGTM;
    m_pStaticSettings->enableFDPreprocessingAlways    = FALSE;
    m_pStaticSettings->enableFDPreprocessDumping      = FALSE;
    m_pStaticSettings->acceptAppUIFacialAttrSettings  = TRUE;
    m_pStaticSettings->enablePTDetection              = FALSE;
    m_pStaticSettings->enableSMDetection              = FALSE;
    m_pStaticSettings->enableGBDetection              = FALSE;
    m_pStaticSettings->enableCTDetection              = FALSE;
    m_pStaticSettings->FDThreadTaskAllocation         = PTDOnPriThread;
    m_pStaticSettings->enableJPEGEXIFApp2             = FALSE;
    m_pStaticSettings->exposeFullSizeForQCFA          = FALSE;
    m_pStaticSettings->useFeatureForQCFA              = 1;
    m_pStaticSettings->AECGainThresholdForQCFA        = 5.0F;
    m_pStaticSettings->disableFlash                   = FALSE;
    m_pStaticSettings->enableWatchdogRecovery         = TRUE;
    m_pStaticSettings->nodeResponseTime               = 5;
    m_pStaticSettings->sessionResponseTimePadding     = 50;
    m_pStaticSettings->sessionMaxFlushWaitTime        = 500;
    m_pStaticSettings->sessionFallbackWaitTime        = 100;
    m_pStaticSettings->feature1                       = 0;
    m_pStaticSettings->feature2                       = 0;
    m_pStaticSettings->raisesigabrt                   = FALSE;
    m_pStaticSettings->raiserecoverysigabrt           = FALSE;
    m_pStaticSettings->enableRecovery                 = TRUE;
    m_pStaticSettings->enableAsciiLogging             = 0;
    m_pStaticSettings->enableBinaryLogging            = 0;
    m_pStaticSettings->offlineLoggerMinFlushCnt       = 50;
    m_pStaticSettings->enableFenceDrop                = FALSE;
    m_pStaticSettings->inducerIsRealTime              = TRUE;
    OsUtils::StrLCpy(m_pStaticSettings->inducerPipelineName, "", sizeof(m_pStaticSettings->inducerPipelineName));
    OsUtils::StrLCpy(m_pStaticSettings->inducerNodeName, "", sizeof(m_pStaticSettings->inducerNodeName));
    m_pStaticSettings->inducerRequestId               = 50;
    m_pStaticSettings->inducerPortId                  = -1;
    m_pStaticSettings->inducerFenceMarkError          = FALSE;
    m_pStaticSettings->sessionDumpForFlush            = FALSE;
    m_pStaticSettings->sessionDumpToLog               = TRUE;
    m_pStaticSettings->sessionDumpToFile              = FALSE;
    m_pStaticSettings->sessionDumpForRecovery         = TRUE;
    m_pStaticSettings->dumpNodeProcessingInfo         = FALSE;
    m_pStaticSettings->dumpSessionProcessingInfo      = FALSE;
    m_pStaticSettings->numberOfCHIThreads             = 6;
    m_pStaticSettings->useVFETPG                      = TRUE;
    m_pStaticSettings->IFEBufDoneTimeout              = 500000;
    m_pStaticSettings->IFEInputWidth                  = 640;
    m_pStaticSettings->IFEInputHeight                 = 480;
    m_pStaticSettings->IPEBufDoneTimeout              = 80000;
    m_pStaticSettings->IPEUnitTestIQBypassNumOfIteration = 1;
    m_pStaticSettings->enableImageBufferLateBinding   = TRUE;
    m_pStaticSettings->MPMEnable                      = TRUE;
    m_pStaticSettings->MPMValidateMemPoolGroup        = FALSE;
    m_pStaticSettings->MPMDoNotGroupBufferManagers    = FALSE;
    m_pStaticSettings->MPMKeepMinNumFreeBuffers       = 0;
    m_pStaticSettings->MPMAllocateBuffersOnRegister   = FALSE;
    m_pStaticSettings->MPMGroupIfExactDeviceMatch     = FALSE;
    m_pStaticSettings->MPMMinSizeForSharing           = 4096;
    m_pStaticSettings->MPMSizeDiffAllowedToGroup      = 4096;
    m_pStaticSettings->MPMLargeGroupSizeDefinition    = 15000000;
    m_pStaticSettings->MPMSizeDiffAllowedToGroupOverride = 4000000;
    m_pStaticSettings->MPMBufferAddressAlignment      = 4096;
    m_pStaticSettings->forceCHIBufferManagerHeap      = 1;
    m_pStaticSettings->MPMSelfTuneImmediateCount      = TRUE;
    m_pStaticSettings->enableMPMMonitorThread         = TRUE;
    m_pStaticSettings->MPMMonitorTimeInterval         = 1000;
    m_pStaticSettings->MPMMonitorSelfShrinkSizeLimit  = 524288;
    m_pStaticSettings->enableMPMStatelogging          = FALSE;
    m_pStaticSettings->enableMemoryStats              = FALSE;
    m_pStaticSettings->MPMMinSizeToFreeOnDeactivate   = 52428800;
    m_pStaticSettings->validateImageBufferUsageState  = FALSE;
    m_pStaticSettings->MPMSizeThresToDisableDelayedUnmap = 36700160;
    m_pStaticSettings->MPMForceDisableDelayedUnmap    = FALSE;
    m_pStaticSettings->MPMSizeThresToDelayedMap       = 36700160;
    m_pStaticSettings->dumpAF                         = 0x0;
    m_pStaticSettings->dumpAEC                        = 0x0;
    m_pStaticSettings->dumpAWB                        = 0x0;
    m_pStaticSettings->dumpAFDRowsum                  = FALSE;
    m_pStaticSettings->profile3A                      = 0x0;

    // Now initialize the hardware dependent default settings values
    HwInitializeDefaultSettings();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsManager::InitializeDefaultDebugSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID SettingsManager::InitializeDefaultDebugSettings()
{
    m_pStaticSettings->dynamicPropertiesEnabled       = TRUE;
    OsUtils::StrLCpy(m_pStaticSettings->pDebugProcess, "", sizeof(m_pStaticSettings->pDebugProcess));
    m_pStaticSettings->CSLMode                        = CSLModeHardware;
    m_pStaticSettings->enableSensorEmulation          = FALSE;
    m_pStaticSettings->enableExternalSensorModule     = FALSE;
    m_pStaticSettings->enableDebugSensorExposure      = FALSE;
    m_pStaticSettings->sensorExposureTime             = 0;
    m_pStaticSettings->gain                           = 0.0F;
    m_pStaticSettings->sensorShortExposureTime        = 0;
    m_pStaticSettings->shortGain                      = 0.0F;
    m_pStaticSettings->sensorMiddleExposureTime       = 0;
    m_pStaticSettings->middleGain                     = 0.0F;
    m_pStaticSettings->dumpSensorEmulationOutput      = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->sensorEmulator, "sensorsim", sizeof(m_pStaticSettings->sensorEmulator));
    OsUtils::StrLCpy(m_pStaticSettings->sensorEmulatorPath, ".\\..\\..\\..\\..\\tools\\sensorsim\\", sizeof(m_pStaticSettings->sensorEmulatorPath));
    m_pStaticSettings->dualLEDCalibrationMode         = DualLEDCalibrationDisabled;
    m_pStaticSettings->dynamicInlineCalibration       = FALSE;
    m_pStaticSettings->dynamicCalibrationMaxSize      = 32004;
    OsUtils::StrLCpy(m_pStaticSettings->dualLEDCalibrationPath, "", sizeof(m_pStaticSettings->dualLEDCalibrationPath));
    m_pStaticSettings->disableADRC                    = FALSE;
    m_pStaticSettings->disablePreviewManualISO        = FALSE;
    m_pStaticSettings->disablePreviewManualExpTime    = FALSE;
    m_pStaticSettings->disablePreviewManualFull       = FALSE;
    m_pStaticSettings->disableSpeckleDetection        = FALSE;
    m_pStaticSettings->disableAFStatsProcessing       = FALSE;
    m_pStaticSettings->disableAFAlgoCHIOverload       = FALSE;
    m_pStaticSettings->disableAWBStatsProcessing      = FALSE;
    m_pStaticSettings->disableAWBAlgoCHIOverload      = FALSE;
    m_pStaticSettings->disableAFDStatsProcessing      = FALSE;
    m_pStaticSettings->disableAFDAlgoCHIOverload      = TRUE;
    m_pStaticSettings->disableASDStatsProcessing      = 1;
    m_pStaticSettings->disableASDAlgoCHIOverload      = TRUE;
    m_pStaticSettings->debugBufferRegDumpEnable       = FALSE;
    m_pStaticSettings->debugBufferRegDumpSizeInBytes  = 65536;
    OsUtils::StrLCpy(m_pStaticSettings->debugBufferRegDumpFileNamePrefix, "register-dump", sizeof(m_pStaticSettings->debugBufferRegDumpFileNamePrefix));
    m_pStaticSettings->dumpIPEFirmwarePayload         = 0;
    m_pStaticSettings->kpiDebug                       = 0;
    m_pStaticSettings->enableQTimer                   = 1;
    m_pStaticSettings->enableTPG                      = FALSE;
    m_pStaticSettings->enableCSIDBinning              = FALSE;
    m_pStaticSettings->CSIDBinningMode                = 0;
    m_pStaticSettings->force3ALockedResult            = FALSE;
    m_pStaticSettings->forceDisableUBWCOnIfeIpeLink   = FALSE;
    m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink = FALSE;
    m_pStaticSettings->capResolutionForSingleIFE      = FALSE;
    m_pStaticSettings->singleIFESupportedWidth        = 3840;
    m_pStaticSettings->singleIFESupportedHeight       = 2160;
    m_pStaticSettings->enableFlashDebug               = FALSE;
    m_pStaticSettings->dumpSensorEEPROMData           = FALSE;
    m_pStaticSettings->autoImageDump                  = FALSE;
    m_pStaticSettings->dumpInputatOutput              = FALSE;
    m_pStaticSettings->autoInputImageDumpMask         = 0x400001ff;
    m_pStaticSettings->IFERegDumpMask                 = 0xFFFFF;
    m_pStaticSettings->autoImageDumpMask              = 0x400001ff;
    m_pStaticSettings->autoImageDumpIFEoutputPortMask = 0x3FFBFFF;
    m_pStaticSettings->autoImageDumpIFEinputPortMask  = 0x7F;
    m_pStaticSettings->autoImageDumpIFEoutputBatchNum = 0x1;
    m_pStaticSettings->autoImageDumpIFEInstanceMask   = 0x7;
    m_pStaticSettings->autoImageDumpIPEoutputPortMask = 0x3F00;
    m_pStaticSettings->autoImageDumpIPEinputPortMask  = 0x0F;
    m_pStaticSettings->autoImageDumpIPEInstanceMask   = 0xFFFFFFFF;
    m_pStaticSettings->autoImageDumpBPSoutputPortMask = 0x1FE;
    m_pStaticSettings->autoImageDumpBPSinputPortMask  = 0x1;
    m_pStaticSettings->autoImageDumpBPSInstanceMask   = 0xFFFFFFFF;
    m_pStaticSettings->autoImageDumpJpegHwoutputPortMask = 0x2;
    m_pStaticSettings->autoImageDumpJpegHwinputPortMask = 0x1;
    m_pStaticSettings->autoImageDumpJpegHwInstanceMask = 0x3;
    m_pStaticSettings->autoImageDumpFDHwoutputPortMask = 0x7;
    m_pStaticSettings->autoImageDumpFDHwinputPortMask = 0x1;
    m_pStaticSettings->autoImageDumpFDHwInstanceMask  = 0x3;
    m_pStaticSettings->autoImageDumpLRMEoutputPortMask = 0xF;
    m_pStaticSettings->autoImageDumpLRMEinputPortMask = 0x7F;
    m_pStaticSettings->autoImageDumpLRMEInstanceMask  = 0x3;
    m_pStaticSettings->autoImageDumpRANSACoutputPortMask = 0x1;
    m_pStaticSettings->autoImageDumpRANSACinputPortMask = 0x1;
    m_pStaticSettings->autoImageDumpRANSACInstanceMask = 0x3;
    m_pStaticSettings->autoImageDumpCHINodeoutputPortMask = 0x1F;
    m_pStaticSettings->autoImageDumpCHINodeinputPortMask = 0x1;
    m_pStaticSettings->autoImageDumpCHINodeInstanceMask = 0x3F;
    m_pStaticSettings->autoImageDumpCVPoutputPortMask = 0x4;
    m_pStaticSettings->autoImageDumpCVPinputPortMask  = 0x1F8;
    m_pStaticSettings->autoImageDumpCVPInstanceMask   = 0x7;
    m_pStaticSettings->dynamicImageDump               = FALSE;
    m_pStaticSettings->dynamicImageDumpTrigger        = FALSE;
    m_pStaticSettings->watermarkImage                 = FALSE;
    OsUtils::StrLCpy(m_pStaticSettings->watermarkOffset, "", sizeof(m_pStaticSettings->watermarkOffset));
    m_pStaticSettings->reprocessDump                  = FALSE;
    m_pStaticSettings->offlineImageDumpOnly           = FALSE;
    m_pStaticSettings->enableIPEHangDump              = 0x2;
    m_pStaticSettings->enableBPSHangDump              = 0x2;
    m_pStaticSettings->enableIPEStripeDump            = FALSE;
    m_pStaticSettings->enableBPSStripeDump            = FALSE;
    m_pStaticSettings->enableIPEScratchBufferDump     = FALSE;
    m_pStaticSettings->forceMaxFPS                    = 100000;
    m_pStaticSettings->kickTheMachine                 = 30000;
    m_pStaticSettings->perFrameSensorMode             = FALSE;
    m_pStaticSettings->disablePDAF                    = FALSE;
    m_pStaticSettings->enableTouchToTrack             = TRUE;
    m_pStaticSettings->touchToTrackDownscaleRatio     = 1;
    m_pStaticSettings->touchToTrackSCVEOperationMode  = 0;
    m_pStaticSettings->touchToTrackSCVEPrecisionMode  = 0;
    m_pStaticSettings->t2tConfidenceThreshold         = 50;
    m_pStaticSettings->defaultMaxFPS                  = 30;
    m_pStaticSettings->bypassIPEICADependency         = FALSE;
    m_pStaticSettings->disableDRQPreemptionOnStopRecord = FALSE;
    m_pStaticSettings->disableVideoPerfModeSetting    = FALSE;
    m_pStaticSettings->enableSensorAcquireOptimization = TRUE;
    m_pStaticSettings->camVersionOverride             = 0;
    m_pStaticSettings->overrideOPPCLOCK               = 0;
    m_pStaticSettings->dumpGeolibResult               = FALSE;
    m_pStaticSettings->dumpCVPICAInputConfig          = FALSE;
    m_pStaticSettings->tfTestMode                     = 0;

    // Now initialize the hardware dependent default debug settings values
    HwInitializeDefaultDebugSettings();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsManager::LoadOverrideSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CamxResult SettingsManager::LoadOverrideSettings(
    IOverrideSettingsStore* pOverrideSettingsStore)
{
    CamxResult  result      = CamxResultSuccess;
    BOOL        tempBOOL    = FALSE;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashOutputFormat,
        reinterpret_cast<INT*>(&m_pStaticSettings->outputFormat),
        OutputFormatTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(OutputFormatTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashRefoutputFormatType,
        reinterpret_cast<INT*>(&m_pStaticSettings->refoutputFormatType),
        RefOutputFormatTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(RefOutputFormatTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->IsStrideSettingEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIsStrideSettingEnable,
        &tempBOOL);
    m_pStaticSettings->IsStrideSettingEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumMetadataResults,
        &m_pStaticSettings->numMetadataResults);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxHalRequests,
        &m_pStaticSettings->maxHalRequests);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashWaitAllResultsTimeout,
        &m_pStaticSettings->waitAllResultsTimeout);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumWorkerThreads,
        &m_pStaticSettings->numWorkerThreads);

    tempBOOL = (m_pStaticSettings->chiOverrideEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashChiOverrideEnable,
        &tempBOOL);
    m_pStaticSettings->chiOverrideEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->multiCameraEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMultiCameraEnable,
        &tempBOOL);
    m_pStaticSettings->multiCameraEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMultiCameraJPEG,
        &m_pStaticSettings->multiCameraJPEG);

    tempBOOL = (m_pStaticSettings->multiCameraEnableFront == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMultiCameraEnableFront,
        &tempBOOL);
    m_pStaticSettings->multiCameraEnableFront = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMultiCameraVREnable,
        &m_pStaticSettings->multiCameraVREnable);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMultiCameraHWSyncMask,
        &m_pStaticSettings->multiCameraHWSyncMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMultiCameraFrameSync,
        &m_pStaticSettings->multiCameraFrameSync);

    tempBOOL = (m_pStaticSettings->enableSensorFpsMatch == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSensorFpsMatch,
        &tempBOOL);
    m_pStaticSettings->enableSensorFpsMatch = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashMultiCamera3ASync,
        reinterpret_cast<INT*>(&m_pStaticSettings->multiCamera3ASync),
        MultiCamera3ASyncTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(MultiCamera3ASyncTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumberOfAELockFrames,
        &m_pStaticSettings->numberOfAELockFrames);

    tempBOOL = (m_pStaticSettings->exportSecureCamera == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashExportSecureCamera,
        &tempBOOL);
    m_pStaticSettings->exportSecureCamera = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableRAWProcessing == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableRAWProcessing,
        &tempBOOL);
    m_pStaticSettings->enableRAWProcessing = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxRAWSizes,
        &m_pStaticSettings->maxRAWSizes);

    tempBOOL = (m_pStaticSettings->enableInternalHALPixelStreamConfig == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableInternalHALPixelStreamConfig,
        &tempBOOL);
    m_pStaticSettings->enableInternalHALPixelStreamConfig = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableNCSService == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableNCSService,
        &tempBOOL);
    m_pStaticSettings->enableNCSService = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMinReprocessInputWidth,
        &m_pStaticSettings->minReprocessInputWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMinReprocessInputHeight,
        &m_pStaticSettings->minReprocessInputHeight);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMinInOutResolution,
        &m_pStaticSettings->minInOutResolution);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxInOutResolution,
        &m_pStaticSettings->maxInOutResolution);

    tempBOOL = (m_pStaticSettings->enableTOFInterface == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableTOFInterface,
        &tempBOOL);
    m_pStaticSettings->enableTOFInterface = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableThermalMitigation == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableThermalMitigation,
        &tempBOOL);
    m_pStaticSettings->enableThermalMitigation = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxBuffersSecureCamera,
        &m_pStaticSettings->maxBuffersSecureCamera);

    tempBOOL = (m_pStaticSettings->enableNativeHEIF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableNativeHEIF,
        &tempBOOL);
    m_pStaticSettings->enableNativeHEIF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableHALFormatOverride == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableHALFormatOverride,
        &tempBOOL);
    m_pStaticSettings->enableHALFormatOverride = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxNumberOfAcceptedErrors,
        &m_pStaticSettings->maxNumberOfAcceptedErrors);

    tempBOOL = (m_pStaticSettings->enableResourceManager == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableResourceManager,
        &tempBOOL);
    m_pStaticSettings->enableResourceManager = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableStreamCropZoom == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableStreamCropZoom,
        &tempBOOL);
    m_pStaticSettings->enableStreamCropZoom = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashBpsRealtimeSensorId,
        &m_pStaticSettings->bpsRealtimeSensorId);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableBLMClient,
        &m_pStaticSettings->enableBLMClient);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAssertMask,
        &m_pStaticSettings->assertMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogWarningMask,
        &m_pStaticSettings->logWarningMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogEntryExitMask,
        &m_pStaticSettings->logEntryExitMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogConfigMask,
        &m_pStaticSettings->logConfigMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogDumpMask,
        &m_pStaticSettings->logDumpMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogInfoMask,
        &m_pStaticSettings->logInfoMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogPerfInfoMask,
        &m_pStaticSettings->logPerfInfoMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLogVerboseMask,
        &m_pStaticSettings->logVerboseMask);

    tempBOOL = (m_pStaticSettings->logDRQEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashLogDRQEnable,
        &tempBOOL);
    m_pStaticSettings->logDRQEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->logMetaEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashLogMetaEnable,
        &tempBOOL);
    m_pStaticSettings->logMetaEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->logRequestMapping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashLogRequestMapping,
        &tempBOOL);
    m_pStaticSettings->logRequestMapping = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->traceErrorEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashTraceErrorEnable,
        &tempBOOL);
    m_pStaticSettings->traceErrorEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->systemLogEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSystemLogEnable,
        &tempBOOL);
    m_pStaticSettings->systemLogEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enablePipelineFlush == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnablePipelineFlush,
        &tempBOOL);
    m_pStaticSettings->enablePipelineFlush = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashDebugLogFilename,
        m_pStaticSettings->debugLogFilename,
        sizeof(m_pStaticSettings->debugLogFilename));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTraceGroupsEnable,
        &m_pStaticSettings->traceGroupsEnable);

    tempBOOL = (m_pStaticSettings->enableFPSLog == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFPSLog,
        &tempBOOL);
    m_pStaticSettings->enableFPSLog = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxMemSpyStats,
        &m_pStaticSettings->maxMemSpyStats);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMemSpyRequestRate,
        &m_pStaticSettings->memSpyRequestRate);

    tempBOOL = (m_pStaticSettings->dynamicPropertiesEnabled == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDynamicPropertiesEnabled,
        &tempBOOL);
    m_pStaticSettings->dynamicPropertiesEnabled = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashPDebugProcess,
        m_pStaticSettings->pDebugProcess,
        sizeof(m_pStaticSettings->pDebugProcess));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashCSLMode,
        reinterpret_cast<INT*>(&m_pStaticSettings->CSLMode),
        CSLModeTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(CSLModeTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->enableSensorEmulation == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSensorEmulation,
        &tempBOOL);
    m_pStaticSettings->enableSensorEmulation = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableExternalSensorModule == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableExternalSensorModule,
        &tempBOOL);
    m_pStaticSettings->enableExternalSensorModule = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableDebugSensorExposure,
        &m_pStaticSettings->enableDebugSensorExposure);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSensorExposureTime,
        &m_pStaticSettings->sensorExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashGain,
        &m_pStaticSettings->gain);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSensorShortExposureTime,
        &m_pStaticSettings->sensorShortExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashShortGain,
        &m_pStaticSettings->shortGain);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSensorMiddleExposureTime,
        &m_pStaticSettings->sensorMiddleExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashMiddleGain,
        &m_pStaticSettings->middleGain);

    tempBOOL = (m_pStaticSettings->dumpSensorEmulationOutput == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpSensorEmulationOutput,
        &tempBOOL);
    m_pStaticSettings->dumpSensorEmulationOutput = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashSensorEmulator,
        m_pStaticSettings->sensorEmulator,
        sizeof(m_pStaticSettings->sensorEmulator));

    pOverrideSettingsStore->ReadSettingString(
        StringHashSensorEmulatorPath,
        m_pStaticSettings->sensorEmulatorPath,
        sizeof(m_pStaticSettings->sensorEmulatorPath));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashDualLEDCalibrationMode,
        reinterpret_cast<INT*>(&m_pStaticSettings->dualLEDCalibrationMode),
        DualLEDCalibrationTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(DualLEDCalibrationTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->dynamicInlineCalibration == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDynamicInlineCalibration,
        &tempBOOL);
    m_pStaticSettings->dynamicInlineCalibration = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDynamicCalibrationMaxSize,
        &m_pStaticSettings->dynamicCalibrationMaxSize);

    pOverrideSettingsStore->ReadSettingString(
        StringHashDualLEDCalibrationPath,
        m_pStaticSettings->dualLEDCalibrationPath,
        sizeof(m_pStaticSettings->dualLEDCalibrationPath));

    tempBOOL = (m_pStaticSettings->disableADRC == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableADRC,
        &tempBOOL);
    m_pStaticSettings->disableADRC = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disablePreviewManualISO == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePreviewManualISO,
        &tempBOOL);
    m_pStaticSettings->disablePreviewManualISO = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disablePreviewManualExpTime == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePreviewManualExpTime,
        &tempBOOL);
    m_pStaticSettings->disablePreviewManualExpTime = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disablePreviewManualFull == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePreviewManualFull,
        &tempBOOL);
    m_pStaticSettings->disablePreviewManualFull = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableSpeckleDetection == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableSpeckleDetection,
        &tempBOOL);
    m_pStaticSettings->disableSpeckleDetection = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFStatsProcessing == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAFStatsProcessing,
        &tempBOOL);
    m_pStaticSettings->disableAFStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFAlgoCHIOverload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAFAlgoCHIOverload,
        &tempBOOL);
    m_pStaticSettings->disableAFAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAWBStatsProcessing == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAWBStatsProcessing,
        &tempBOOL);
    m_pStaticSettings->disableAWBStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAWBAlgoCHIOverload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAWBAlgoCHIOverload,
        &tempBOOL);
    m_pStaticSettings->disableAWBAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFDStatsProcessing == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAFDStatsProcessing,
        &tempBOOL);
    m_pStaticSettings->disableAFDStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFDAlgoCHIOverload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAFDAlgoCHIOverload,
        &tempBOOL);
    m_pStaticSettings->disableAFDAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDisableASDStatsProcessing,
        &m_pStaticSettings->disableASDStatsProcessing);

    tempBOOL = (m_pStaticSettings->disableASDAlgoCHIOverload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableASDAlgoCHIOverload,
        &tempBOOL);
    m_pStaticSettings->disableASDAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->debugBufferRegDumpEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDebugBufferRegDumpEnable,
        &tempBOOL);
    m_pStaticSettings->debugBufferRegDumpEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDebugBufferRegDumpSizeInBytes,
        &m_pStaticSettings->debugBufferRegDumpSizeInBytes);

    pOverrideSettingsStore->ReadSettingString(
        StringHashDebugBufferRegDumpFileNamePrefix,
        m_pStaticSettings->debugBufferRegDumpFileNamePrefix,
        sizeof(m_pStaticSettings->debugBufferRegDumpFileNamePrefix));

    tempBOOL = (m_pStaticSettings->dumpIPEFirmwarePayload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpIPEFirmwarePayload,
        &tempBOOL);
    m_pStaticSettings->dumpIPEFirmwarePayload = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->kpiDebug == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashKpiDebug,
        &tempBOOL);
    m_pStaticSettings->kpiDebug = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableQTimer == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableQTimer,
        &tempBOOL);
    m_pStaticSettings->enableQTimer = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableTPG == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableTPG,
        &tempBOOL);
    m_pStaticSettings->enableTPG = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCSIDBinning == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCSIDBinning,
        &tempBOOL);
    m_pStaticSettings->enableCSIDBinning = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashCSIDBinningMode,
        &m_pStaticSettings->CSIDBinningMode);

    tempBOOL = (m_pStaticSettings->force3ALockedResult == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashForce3ALockedResult,
        &tempBOOL);
    m_pStaticSettings->force3ALockedResult = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->forceDisableUBWCOnIfeIpeLink == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashForceDisableUBWCOnIfeIpeLink,
        &tempBOOL);
    m_pStaticSettings->forceDisableUBWCOnIfeIpeLink = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableUBWCNV124ROnIFEFullOutIPELink,
        &tempBOOL);
    m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->capResolutionForSingleIFE == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashCapResolutionForSingleIFE,
        &tempBOOL);
    m_pStaticSettings->capResolutionForSingleIFE = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingINT(
        StringHashSingleIFESupportedWidth,
        &m_pStaticSettings->singleIFESupportedWidth);

    pOverrideSettingsStore->ReadSettingINT(
        StringHashSingleIFESupportedHeight,
        &m_pStaticSettings->singleIFESupportedHeight);

    tempBOOL = (m_pStaticSettings->enableFlashDebug == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFlashDebug,
        &tempBOOL);
    m_pStaticSettings->enableFlashDebug = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpSensorEEPROMData == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpSensorEEPROMData,
        &tempBOOL);
    m_pStaticSettings->dumpSensorEEPROMData = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->autoImageDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashAutoImageDump,
        &tempBOOL);
    m_pStaticSettings->autoImageDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpInputatOutput == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpInputatOutput,
        &tempBOOL);
    m_pStaticSettings->dumpInputatOutput = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoInputImageDumpMask,
        &m_pStaticSettings->autoInputImageDumpMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFERegDumpMask,
        &m_pStaticSettings->IFERegDumpMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpMask,
        &m_pStaticSettings->autoImageDumpMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIFEoutputPortMask,
        &m_pStaticSettings->autoImageDumpIFEoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIFEinputPortMask,
        &m_pStaticSettings->autoImageDumpIFEinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIFEoutputBatchNum,
        &m_pStaticSettings->autoImageDumpIFEoutputBatchNum);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIFEInstanceMask,
        &m_pStaticSettings->autoImageDumpIFEInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIPEoutputPortMask,
        &m_pStaticSettings->autoImageDumpIPEoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIPEinputPortMask,
        &m_pStaticSettings->autoImageDumpIPEinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpIPEInstanceMask,
        &m_pStaticSettings->autoImageDumpIPEInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpBPSoutputPortMask,
        &m_pStaticSettings->autoImageDumpBPSoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpBPSinputPortMask,
        &m_pStaticSettings->autoImageDumpBPSinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpBPSInstanceMask,
        &m_pStaticSettings->autoImageDumpBPSInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpJpegHwoutputPortMask,
        &m_pStaticSettings->autoImageDumpJpegHwoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpJpegHwinputPortMask,
        &m_pStaticSettings->autoImageDumpJpegHwinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpJpegHwInstanceMask,
        &m_pStaticSettings->autoImageDumpJpegHwInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpFDHwoutputPortMask,
        &m_pStaticSettings->autoImageDumpFDHwoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpFDHwinputPortMask,
        &m_pStaticSettings->autoImageDumpFDHwinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpFDHwInstanceMask,
        &m_pStaticSettings->autoImageDumpFDHwInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpLRMEoutputPortMask,
        &m_pStaticSettings->autoImageDumpLRMEoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpLRMEinputPortMask,
        &m_pStaticSettings->autoImageDumpLRMEinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpLRMEInstanceMask,
        &m_pStaticSettings->autoImageDumpLRMEInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpRANSACoutputPortMask,
        &m_pStaticSettings->autoImageDumpRANSACoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpRANSACinputPortMask,
        &m_pStaticSettings->autoImageDumpRANSACinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpRANSACInstanceMask,
        &m_pStaticSettings->autoImageDumpRANSACInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCHINodeoutputPortMask,
        &m_pStaticSettings->autoImageDumpCHINodeoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCHINodeinputPortMask,
        &m_pStaticSettings->autoImageDumpCHINodeinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCHINodeInstanceMask,
        &m_pStaticSettings->autoImageDumpCHINodeInstanceMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCVPoutputPortMask,
        &m_pStaticSettings->autoImageDumpCVPoutputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCVPinputPortMask,
        &m_pStaticSettings->autoImageDumpCVPinputPortMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAutoImageDumpCVPInstanceMask,
        &m_pStaticSettings->autoImageDumpCVPInstanceMask);

    tempBOOL = (m_pStaticSettings->dynamicImageDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDynamicImageDump,
        &tempBOOL);
    m_pStaticSettings->dynamicImageDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dynamicImageDumpTrigger == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDynamicImageDumpTrigger,
        &tempBOOL);
    m_pStaticSettings->dynamicImageDumpTrigger = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->watermarkImage == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashWatermarkImage,
        &tempBOOL);
    m_pStaticSettings->watermarkImage = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashWatermarkOffset,
        m_pStaticSettings->watermarkOffset,
        sizeof(m_pStaticSettings->watermarkOffset));

    tempBOOL = (m_pStaticSettings->reprocessDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashReprocessDump,
        &tempBOOL);
    m_pStaticSettings->reprocessDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->offlineImageDumpOnly == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashOfflineImageDumpOnly,
        &tempBOOL);
    m_pStaticSettings->offlineImageDumpOnly = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableIPEHangDump,
        &m_pStaticSettings->enableIPEHangDump);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableBPSHangDump,
        &m_pStaticSettings->enableBPSHangDump);

    tempBOOL = (m_pStaticSettings->enableIPEStripeDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEStripeDump,
        &tempBOOL);
    m_pStaticSettings->enableIPEStripeDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableBPSStripeDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableBPSStripeDump,
        &tempBOOL);
    m_pStaticSettings->enableBPSStripeDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIPEScratchBufferDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEScratchBufferDump,
        &tempBOOL);
    m_pStaticSettings->enableIPEScratchBufferDump = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashForceMaxFPS,
        &m_pStaticSettings->forceMaxFPS);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashKickTheMachine,
        &m_pStaticSettings->kickTheMachine);

    tempBOOL = (m_pStaticSettings->perFrameSensorMode == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashPerFrameSensorMode,
        &tempBOOL);
    m_pStaticSettings->perFrameSensorMode = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disablePDAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePDAF,
        &tempBOOL);
    m_pStaticSettings->disablePDAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableTouchToTrack == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableTouchToTrack,
        &tempBOOL);
    m_pStaticSettings->enableTouchToTrack = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTouchToTrackDownscaleRatio,
        &m_pStaticSettings->touchToTrackDownscaleRatio);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTouchToTrackSCVEOperationMode,
        &m_pStaticSettings->touchToTrackSCVEOperationMode);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTouchToTrackSCVEPrecisionMode,
        &m_pStaticSettings->touchToTrackSCVEPrecisionMode);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashT2tConfidenceThreshold,
        &m_pStaticSettings->t2tConfidenceThreshold);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDefaultMaxFPS,
        &m_pStaticSettings->defaultMaxFPS);

    tempBOOL = (m_pStaticSettings->bypassIPEICADependency == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashBypassIPEICADependency,
        &tempBOOL);
    m_pStaticSettings->bypassIPEICADependency = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableDRQPreemptionOnStopRecord == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableDRQPreemptionOnStopRecord,
        &tempBOOL);
    m_pStaticSettings->disableDRQPreemptionOnStopRecord = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableVideoPerfModeSetting == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableVideoPerfModeSetting,
        &tempBOOL);
    m_pStaticSettings->disableVideoPerfModeSetting = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableSensorAcquireOptimization == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSensorAcquireOptimization,
        &tempBOOL);
    m_pStaticSettings->enableSensorAcquireOptimization = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingINT(
        StringHashCamVersionOverride,
        &m_pStaticSettings->camVersionOverride);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideOPPCLOCK,
        &m_pStaticSettings->overrideOPPCLOCK);

    tempBOOL = (m_pStaticSettings->dumpGeolibResult == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpGeolibResult,
        &tempBOOL);
    m_pStaticSettings->dumpGeolibResult = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpCVPICAInputConfig == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpCVPICAInputConfig,
        &tempBOOL);
    m_pStaticSettings->dumpCVPICAInputConfig = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTfTestMode,
        &m_pStaticSettings->tfTestMode);

    tempBOOL = (m_pStaticSettings->enableHJAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableHJAF,
        &tempBOOL);
    m_pStaticSettings->enableHJAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableSPD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSPD,
        &tempBOOL);
    m_pStaticSettings->enableSPD = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSpdStatsType,
        &m_pStaticSettings->spdStatsType);

    tempBOOL = (m_pStaticSettings->disableFocusIndication == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableFocusIndication,
        &tempBOOL);
    m_pStaticSettings->disableFocusIndication = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->spotlightFallbackToCAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSpotlightFallbackToCAF,
        &tempBOOL);
    m_pStaticSettings->spotlightFallbackToCAF = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAfLog,
        &m_pStaticSettings->afLog);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashFovcEnable,
        &m_pStaticSettings->fovcEnable);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashGyroDataReportRate,
        &m_pStaticSettings->gyroDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashGyroSensorSamplingRate,
        &m_pStaticSettings->gyroSensorSamplingRate);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashGravityDataReportRate,
        &m_pStaticSettings->gravityDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashGravitySensorSamplingRate,
        &m_pStaticSettings->gravitySensorSamplingRate);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTOFDataReportRate,
        &m_pStaticSettings->TOFDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashTOFSensorSamplingRate,
        &m_pStaticSettings->TOFSensorSamplingRate);

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomTOFSensorLib,
        m_pStaticSettings->customTOFSensorLib,
        sizeof(m_pStaticSettings->customTOFSensorLib));

    tempBOOL = (m_pStaticSettings->mwEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMwEnable,
        &tempBOOL);
    m_pStaticSettings->mwEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashEnableAFAlgo,
        reinterpret_cast<INT*>(&m_pStaticSettings->enableAFAlgo),
        EnableAFAlgoTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(EnableAFAlgoTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashAfFullsweep,
        reinterpret_cast<INT*>(&m_pStaticSettings->afFullsweep),
        AFFullsweepTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(AFFullsweepTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashManualAf,
        reinterpret_cast<INT*>(&m_pStaticSettings->manualAf),
        AFManualLensControlTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(AFManualLensControlTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashLensPos,
        &m_pStaticSettings->lensPos);

    pOverrideSettingsStore->ReadSettingString(
        StringHashVmDebugMask,
        m_pStaticSettings->vmDebugMask,
        sizeof(m_pStaticSettings->vmDebugMask));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAFRecorderMode,
        &m_pStaticSettings->AFRecorderMode);

    tempBOOL = (m_pStaticSettings->enableLensSagComp == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableLensSagComp,
        &tempBOOL);
    m_pStaticSettings->enableLensSagComp = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashActiveNodeMask,
        m_pStaticSettings->activeNodeMask,
        sizeof(m_pStaticSettings->activeNodeMask));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashApiMask,
        &m_pStaticSettings->apiMask);

    tempBOOL = (m_pStaticSettings->manualExposureType == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashManualExposureType,
        &tempBOOL);
    m_pStaticSettings->manualExposureType = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dualBHistSupport == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDualBHistSupport,
        &tempBOOL);
    m_pStaticSettings->dualBHistSupport = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableBGStatsForAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableBGStatsForAF,
        &tempBOOL);
    m_pStaticSettings->disableBGStatsForAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAEC == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomAlgoAEC,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAEC = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFAWBpreFlash == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableAFAWBpreFlash,
        &tempBOOL);
    m_pStaticSettings->disableAFAWBpreFlash = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashYuvPlaneAlignment,
        &m_pStaticSettings->yuvPlaneAlignment);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashPreFlashMaxFrameWaitLimitAF,
        &m_pStaticSettings->preFlashMaxFrameWaitLimitAF);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashPreFlashMaxFrameWaitLimitAWB,
        &m_pStaticSettings->preFlashMaxFrameWaitLimitAWB);

    tempBOOL = (m_pStaticSettings->disablePreFlashOnForTouchAE == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePreFlashOnForTouchAE,
        &tempBOOL);
    m_pStaticSettings->disablePreFlashOnForTouchAE = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumberOfFramesToSkip,
        &m_pStaticSettings->numberOfFramesToSkip);

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAECName,
        m_pStaticSettings->customAlgoAECName,
        sizeof(m_pStaticSettings->customAlgoAECName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAECPath,
        m_pStaticSettings->customAlgoAECPath,
        sizeof(m_pStaticSettings->customAlgoAECPath));

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAWB == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomAlgoAWB,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAWB = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAWBName,
        m_pStaticSettings->customAlgoAWBName,
        sizeof(m_pStaticSettings->customAlgoAWBName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAWBPath,
        m_pStaticSettings->customAlgoAWBPath,
        sizeof(m_pStaticSettings->customAlgoAWBPath));

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomAlgoAF,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAF = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAFName,
        m_pStaticSettings->customAlgoAFName,
        sizeof(m_pStaticSettings->customAlgoAFName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAFPath,
        m_pStaticSettings->customAlgoAFPath,
        sizeof(m_pStaticSettings->customAlgoAFPath));

    tempBOOL = (m_pStaticSettings->enableCustomHAFAlgo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomHAFAlgo,
        &tempBOOL);
    m_pStaticSettings->enableCustomHAFAlgo = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomHAFAlgoName,
        m_pStaticSettings->customHAFAlgoName,
        sizeof(m_pStaticSettings->customHAFAlgoName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomHAFAlgoPath,
        m_pStaticSettings->customHAFAlgoPath,
        sizeof(m_pStaticSettings->customHAFAlgoPath));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideHAFAlgoMask,
        &m_pStaticSettings->overrideHAFAlgoMask);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashExposureGain,
        &m_pStaticSettings->exposureGain);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashExposureTime,
        &m_pStaticSettings->exposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashLuxIndex,
        &m_pStaticSettings->luxIndex);

    tempBOOL = (m_pStaticSettings->extendedTimeForLongExposure == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashExtendedTimeForLongExposure,
        &tempBOOL);
    m_pStaticSettings->extendedTimeForLongExposure = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->manualWhiteBalanceType == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashManualWhiteBalanceType,
        &tempBOOL);
    m_pStaticSettings->manualWhiteBalanceType = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashRGain,
        &m_pStaticSettings->rGain);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashGGain,
        &m_pStaticSettings->gGain);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashBGain,
        &m_pStaticSettings->BGain);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashColorTemp,
        &m_pStaticSettings->colorTemp);

    tempBOOL = (m_pStaticSettings->ignoreSceneMode == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIgnoreSceneMode,
        &tempBOOL);
    m_pStaticSettings->ignoreSceneMode = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCustomAlgoASD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomAlgoASD,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoASD = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoASDName,
        m_pStaticSettings->customAlgoASDName,
        sizeof(m_pStaticSettings->customAlgoASDName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoASDPath,
        m_pStaticSettings->customAlgoASDPath,
        sizeof(m_pStaticSettings->customAlgoASDPath));

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAFD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomAlgoAFD,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAFD = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAFDName,
        m_pStaticSettings->customAlgoAFDName,
        sizeof(m_pStaticSettings->customAlgoAFDName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomAlgoAFDPath,
        m_pStaticSettings->customAlgoAFDPath,
        sizeof(m_pStaticSettings->customAlgoAFDPath));

    tempBOOL = (m_pStaticSettings->enableDualIFE == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableDualIFE,
        &tempBOOL);
    m_pStaticSettings->enableDualIFE = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->forceDualIFEOn == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashForceDualIFEOn,
        &tempBOOL);
    m_pStaticSettings->forceDualIFEOn = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingINT(
        StringHashDualIFESplitPointOffset,
        &m_pStaticSettings->dualIFESplitPointOffset);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDualIFELeftPadding,
        &m_pStaticSettings->dualIFELeftPadding);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDualIFERightPadding,
        &m_pStaticSettings->dualIFERightPadding);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFETestImageSizeWidth,
        &m_pStaticSettings->IFETestImageSizeWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFETestImageSizeHeight,
        &m_pStaticSettings->IFETestImageSizeHeight);

    tempBOOL = (m_pStaticSettings->IsOEMStatSettingEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIsOEMStatSettingEnable,
        &tempBOOL);
    m_pStaticSettings->IsOEMStatSettingEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->DisableManual3ACCM == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableManual3ACCM,
        &tempBOOL);
    m_pStaticSettings->DisableManual3ACCM = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFENumFramesHighBW,
        &m_pStaticSettings->IFENumFramesHighBW);

    tempBOOL = (m_pStaticSettings->pdafHWEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashPdafHWEnable,
        &tempBOOL);
    m_pStaticSettings->pdafHWEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIFERegDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIFERegDump,
        &tempBOOL);
    m_pStaticSettings->enableIFERegDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableActiveIFEABVote == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableActiveIFEABVote,
        &tempBOOL);
    m_pStaticSettings->enableActiveIFEABVote = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFEDynamicEnableMask,
        &m_pStaticSettings->IFEDynamicEnableMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIfeClockFrequencyMHz,
        &m_pStaticSettings->ifeClockFrequencyMHz);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIfeCamnocBandwidthMBytes,
        &m_pStaticSettings->ifeCamnocBandwidthMBytes);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIfeExternalBandwidthMBytes,
        &m_pStaticSettings->ifeExternalBandwidthMBytes);

    tempBOOL = (m_pStaticSettings->enableHVXStreaming == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableHVXStreaming,
        &tempBOOL);
    m_pStaticSettings->enableHVXStreaming = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableIPEIQModulesMask,
        &m_pStaticSettings->enableIPEIQModulesMask);

    tempBOOL = (m_pStaticSettings->enableIPEUpscale == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEUpscale,
        &tempBOOL);
    m_pStaticSettings->enableIPEUpscale = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIPEOnlyDownscale == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEOnlyDownscale,
        &tempBOOL);
    m_pStaticSettings->enableIPEOnlyDownscale = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableIPEInternalDownscale == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableIPEInternalDownscale,
        &tempBOOL);
    m_pStaticSettings->disableIPEInternalDownscale = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIPEDependencies == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEDependencies,
        &tempBOOL);
    m_pStaticSettings->enableIPEDependencies = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIPEIQLogging == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIPEIQLogging,
        &tempBOOL);
    m_pStaticSettings->enableIPEIQLogging = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableMCTF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableMCTF,
        &tempBOOL);
    m_pStaticSettings->enableMCTF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableCVPDriver == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableCVPDriver,
        &tempBOOL);
    m_pStaticSettings->disableCVPDriver = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumIPECoresToUse,
        &m_pStaticSettings->numIPECoresToUse);

    tempBOOL = (m_pStaticSettings->force8BitUBWCAlignment == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashForce8BitUBWCAlignment,
        &tempBOOL);
    m_pStaticSettings->force8BitUBWCAlignment = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSetLRMETransformTypeMask,
        &m_pStaticSettings->setLRMETransformTypeMask);

    tempBOOL = (m_pStaticSettings->isGridFromChromatixEnabled == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIsGridFromChromatixEnabled,
        &tempBOOL);
    m_pStaticSettings->isGridFromChromatixEnabled = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashAlignmentFusionMode,
        reinterpret_cast<INT*>(&m_pStaticSettings->alignmentFusionMode),
        AlignmentFusionModesEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(AlignmentFusionModesEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIsFirstFrameLoopbackInputImageEnabled,
        &m_pStaticSettings->isFirstFrameLoopbackInputImageEnabled);

    tempBOOL = (m_pStaticSettings->enableLDC == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableLDC,
        &tempBOOL);
    m_pStaticSettings->enableLDC = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashDebugDataHeaderString,
        m_pStaticSettings->debugDataHeaderString,
        sizeof(m_pStaticSettings->debugDataHeaderString));

    tempBOOL = (m_pStaticSettings->enable3ADebugData == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnable3ADebugData,
        &tempBOOL);
    m_pStaticSettings->enable3ADebugData = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDebugDataSizeAEC,
        &m_pStaticSettings->debugDataSizeAEC);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDebugDataSizeAWB,
        &m_pStaticSettings->debugDataSizeAWB);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDebugDataSizeAF,
        &m_pStaticSettings->debugDataSizeAF);

    tempBOOL = (m_pStaticSettings->enableTuningMetadata == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableTuningMetadata,
        &tempBOOL);
    m_pStaticSettings->enableTuningMetadata = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTuningDumpDataSizeIFE,
        &m_pStaticSettings->tuningDumpDataSizeIFE);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTuningDumpDataSizeIPE,
        &m_pStaticSettings->tuningDumpDataSizeIPE);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashTuningDumpDataSizeBPS,
        &m_pStaticSettings->tuningDumpDataSizeBPS);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpDebugDataEveryProcessResult,
        &m_pStaticSettings->dumpDebugDataEveryProcessResult);

    tempBOOL = (m_pStaticSettings->debugDataOfflineAlloc == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDebugDataOfflineAlloc,
        &tempBOOL);
    m_pStaticSettings->debugDataOfflineAlloc = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disablePDLibCHIOverload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePDLibCHIOverload,
        &tempBOOL);
    m_pStaticSettings->disablePDLibCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCustomPDLib == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCustomPDLib,
        &tempBOOL);
    m_pStaticSettings->enableCustomPDLib = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomPDLibName,
        m_pStaticSettings->customPDLibName,
        sizeof(m_pStaticSettings->customPDLibName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashCustomPDLibPath,
        m_pStaticSettings->customPDLibPath,
        sizeof(m_pStaticSettings->customPDLibPath));

    tempBOOL = (m_pStaticSettings->tintlessEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashTintlessEnable,
        &tempBOOL);
    m_pStaticSettings->tintlessEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnablePDLibLog,
        &m_pStaticSettings->enablePDLibLog);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnablePDLibTestMode,
        &m_pStaticSettings->enablePDLibTestMode);

    tempBOOL = (m_pStaticSettings->enablePDLibProfiling == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnablePDLibProfiling,
        &tempBOOL);
    m_pStaticSettings->enablePDLibProfiling = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnablePDLibDump,
        &m_pStaticSettings->enablePDLibDump);

    tempBOOL = (m_pStaticSettings->disablePDLibLCR == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePDLibLCR,
        &tempBOOL);
    m_pStaticSettings->disablePDLibLCR = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->ifeSWCDMEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIfeSWCDMEnable,
        &tempBOOL);
    m_pStaticSettings->ifeSWCDMEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableAEScan,
        &m_pStaticSettings->enableAEScan);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideLogLevels,
        &m_pStaticSettings->overrideLogLevels);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideDisableZSL,
        &m_pStaticSettings->overrideDisableZSL);

    tempBOOL = (m_pStaticSettings->enableLRMEDS2 == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableLRMEDS2,
        &tempBOOL);
    m_pStaticSettings->enableLRMEDS2 = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideEnableMFNR,
        &m_pStaticSettings->overrideEnableMFNR);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAnchorSelectionAlgoForMFNR,
        &m_pStaticSettings->anchorSelectionAlgoForMFNR);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAnchorAlgoSelectionType,
        &m_pStaticSettings->anchorAlgoSelectionType);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashAdvanceFeatureMask,
        &m_pStaticSettings->advanceFeatureMask);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableOfflineNoiseReprocess,
        &m_pStaticSettings->enableOfflineNoiseReprocess);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableGamma15PreCalculate,
        &m_pStaticSettings->enableGamma15PreCalculate);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideForceUsecaseId,
        &m_pStaticSettings->overrideForceUsecaseId);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideForceSensorMode,
        &m_pStaticSettings->overrideForceSensorMode);

    tempBOOL = (m_pStaticSettings->overrideForceFSCapable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashOverrideForceFSCapable,
        &tempBOOL);
    m_pStaticSettings->overrideForceFSCapable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideGPURotationUsecase,
        &m_pStaticSettings->overrideGPURotationUsecase);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideGPUDownscaleUsecase,
        &m_pStaticSettings->overrideGPUDownscaleUsecase);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideHFRNo3AUseCase,
        &m_pStaticSettings->overrideHFRNo3AUseCase);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideCameraClose,
        &m_pStaticSettings->overrideCameraClose);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideCameraOpen,
        &m_pStaticSettings->overrideCameraOpen);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverridePDLibClose,
        &m_pStaticSettings->overridePDLibClose);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverridePDLibOpen,
        &m_pStaticSettings->overridePDLibOpen);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEISV2Enable,
        &m_pStaticSettings->EISV2Enable);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEISV3Enable,
        &m_pStaticSettings->EISV3Enable);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashEISV2Margin,
        &m_pStaticSettings->EISV2Margin);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEISV2FrameDelay,
        &m_pStaticSettings->EISV2FrameDelay);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashEISV3Margin,
        &m_pStaticSettings->EISV3Margin);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEISV3FrameDelay,
        &m_pStaticSettings->EISV3FrameDelay);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumPCRsBeforeStreamOn,
        &m_pStaticSettings->numPCRsBeforeStreamOn);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxImageBufferTimeoutCount,
        &m_pStaticSettings->maxImageBufferTimeoutCount);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashImageBufferWaitTime,
        &m_pStaticSettings->imageBufferWaitTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideMaxImageBufferCountRealTime,
        &m_pStaticSettings->overrideMaxImageBufferCountRealTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOverrideMaxImageBufferCountNonRealTime,
        &m_pStaticSettings->overrideMaxImageBufferCountNonRealTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashStatsProcessingSkipFactor,
        &m_pStaticSettings->statsProcessingSkipFactor);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMaxNonHfrFps,
        &m_pStaticSettings->maxNonHfrFps);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMinFrameRateBound,
        &m_pStaticSettings->minFrameRateBound);

    tempBOOL = (m_pStaticSettings->enableOISOptimization == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableOISOptimization,
        &tempBOOL);
    m_pStaticSettings->enableOISOptimization = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableSensorCaching == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSensorCaching,
        &tempBOOL);
    m_pStaticSettings->enableSensorCaching = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->forceDebugQCFASWRemosaic == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashForceDebugQCFASWRemosaic,
        &tempBOOL);
    m_pStaticSettings->forceDebugQCFASWRemosaic = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashEnableCHIPartialData,
        reinterpret_cast<INT*>(&m_pStaticSettings->enableCHIPartialData),
        CHIPartialDataTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(CHIPartialDataTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableCHIPartialDataRecovery,
        &m_pStaticSettings->enableCHIPartialDataRecovery);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpMetadata,
        &m_pStaticSettings->dumpMetadata);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMemsetInputMeta,
        &m_pStaticSettings->memsetInputMeta);

    tempBOOL = (m_pStaticSettings->enableLinearMetaLUT == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableLinearMetaLUT,
        &tempBOOL);
    m_pStaticSettings->enableLinearMetaLUT = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableFDStreamInRealTime,
        &m_pStaticSettings->enableFDStreamInRealTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSelectInSensorHDR3ExpUsecase,
        &m_pStaticSettings->selectInSensorHDR3ExpUsecase);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableUnifiedBufferManager,
        &m_pStaticSettings->enableUnifiedBufferManager);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableCHIImageBufferLateBinding,
        &m_pStaticSettings->enableCHIImageBufferLateBinding);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableFeature2Dump,
        &m_pStaticSettings->enableFeature2Dump);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashForceHWMFFixedNumOfFrames,
        &m_pStaticSettings->forceHWMFFixedNumOfFrames);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableTBMChiFence,
        &m_pStaticSettings->enableTBMChiFence);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableMFSRChiFence,
        &m_pStaticSettings->enableMFSRChiFence);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableRawHDR,
        &m_pStaticSettings->enableRawHDR);

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDProcessingControl,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDProcessingControl),
        FDProcessingControlTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDProcessingControlTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->enableFDManagerThreading == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFDManagerThreading,
        &tempBOOL);
    m_pStaticSettings->enableFDManagerThreading = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDBaseResolution,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDBaseResolution),
        FDBaseResolutionTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDBaseResolutionTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDConfigSource,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDConfigSource),
        FDConfigSourceTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDConfigSourceTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDMultiCamProcess,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDMultiCamProcess),
        FDMultiCamProcessingTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDMultiCamProcessingTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->useAlternateFrameSkip == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseAlternateFrameSkip,
        &tempBOOL);
    m_pStaticSettings->useAlternateFrameSkip = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->useDeviceOrientationInFD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseDeviceOrientationInFD,
        &tempBOOL);
    m_pStaticSettings->useDeviceOrientationInFD = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->getAccelInfoUsingVendorTag == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashGetAccelInfoUsingVendorTag,
        &tempBOOL);
    m_pStaticSettings->getAccelInfoUsingVendorTag = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashAccelVendorTagSection,
        m_pStaticSettings->accelVendorTagSection,
        sizeof(m_pStaticSettings->accelVendorTagSection));

    pOverrideSettingsStore->ReadSettingString(
        StringHashAccelVendorTagName,
        m_pStaticSettings->accelVendorTagName,
        sizeof(m_pStaticSettings->accelVendorTagName));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDFilterEngine,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDFilterEngine),
        FDFilterEngineTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDFilterEngineTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDClient,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDClient),
        FDClientTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDClientTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->disablePostingResults == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisablePostingResults,
        &tempBOOL);
    m_pStaticSettings->disablePostingResults = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableOfflineFD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableOfflineFD,
        &tempBOOL);
    m_pStaticSettings->enableOfflineFD = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->MetadataVisibility == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMetadataVisibility,
        &tempBOOL);
    m_pStaticSettings->MetadataVisibility = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->useDifferentTuningForFrontCamera == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseDifferentTuningForFrontCamera,
        &tempBOOL);
    m_pStaticSettings->useDifferentTuningForFrontCamera = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->useFDInternalBuffers == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseFDInternalBuffers,
        &tempBOOL);
    m_pStaticSettings->useFDInternalBuffers = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->useFDUseCasePool == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseFDUseCasePool,
        &tempBOOL);
    m_pStaticSettings->useFDUseCasePool = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->fastFDMetadata == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashFastFDMetadata,
        &tempBOOL);
    m_pStaticSettings->fastFDMetadata = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMinReqFdDependency,
        &m_pStaticSettings->minReqFdDependency);

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDPreprocessing,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDPreprocessing),
        FDPreProcessingTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDPreProcessingTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->enableFDPreprocessingAlways == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFDPreprocessingAlways,
        &tempBOOL);
    m_pStaticSettings->enableFDPreprocessingAlways = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableFDPreprocessDumping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFDPreprocessDumping,
        &tempBOOL);
    m_pStaticSettings->enableFDPreprocessDumping = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->acceptAppUIFacialAttrSettings == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashAcceptAppUIFacialAttrSettings,
        &tempBOOL);
    m_pStaticSettings->acceptAppUIFacialAttrSettings = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enablePTDetection == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnablePTDetection,
        &tempBOOL);
    m_pStaticSettings->enablePTDetection = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableSMDetection == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableSMDetection,
        &tempBOOL);
    m_pStaticSettings->enableSMDetection = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableGBDetection == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableGBDetection,
        &tempBOOL);
    m_pStaticSettings->enableGBDetection = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCTDetection == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableCTDetection,
        &tempBOOL);
    m_pStaticSettings->enableCTDetection = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashFDThreadTaskAllocation,
        reinterpret_cast<INT*>(&m_pStaticSettings->FDThreadTaskAllocation),
        FDThreadTaskAllocationTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(FDThreadTaskAllocationTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->enableJPEGEXIFApp2 == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableJPEGEXIFApp2,
        &tempBOOL);
    m_pStaticSettings->enableJPEGEXIFApp2 = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->exposeFullSizeForQCFA == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashExposeFullSizeForQCFA,
        &tempBOOL);
    m_pStaticSettings->exposeFullSizeForQCFA = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashUseFeatureForQCFA,
        &m_pStaticSettings->useFeatureForQCFA);

    pOverrideSettingsStore->ReadSettingFLOAT(
        StringHashAECGainThresholdForQCFA,
        &m_pStaticSettings->AECGainThresholdForQCFA);

    tempBOOL = (m_pStaticSettings->disableFlash == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableFlash,
        &tempBOOL);
    m_pStaticSettings->disableFlash = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableWatchdogRecovery == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableWatchdogRecovery,
        &tempBOOL);
    m_pStaticSettings->enableWatchdogRecovery = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNodeResponseTime,
        &m_pStaticSettings->nodeResponseTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSessionResponseTimePadding,
        &m_pStaticSettings->sessionResponseTimePadding);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSessionMaxFlushWaitTime,
        &m_pStaticSettings->sessionMaxFlushWaitTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashSessionFallbackWaitTime,
        &m_pStaticSettings->sessionFallbackWaitTime);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashFeature1,
        &m_pStaticSettings->feature1);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashFeature2,
        &m_pStaticSettings->feature2);

    tempBOOL = (m_pStaticSettings->raisesigabrt == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashRaisesigabrt,
        &tempBOOL);
    m_pStaticSettings->raisesigabrt = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->raiserecoverysigabrt == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashRaiserecoverysigabrt,
        &tempBOOL);
    m_pStaticSettings->raiserecoverysigabrt = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableRecovery == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableRecovery,
        &tempBOOL);
    m_pStaticSettings->enableRecovery = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableAsciiLogging,
        &m_pStaticSettings->enableAsciiLogging);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashEnableBinaryLogging,
        &m_pStaticSettings->enableBinaryLogging);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashOfflineLoggerMinFlushCnt,
        &m_pStaticSettings->offlineLoggerMinFlushCnt);

    tempBOOL = (m_pStaticSettings->enableFenceDrop == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableFenceDrop,
        &tempBOOL);
    m_pStaticSettings->enableFenceDrop = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->inducerIsRealTime == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashInducerIsRealTime,
        &tempBOOL);
    m_pStaticSettings->inducerIsRealTime = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        StringHashInducerPipelineName,
        m_pStaticSettings->inducerPipelineName,
        sizeof(m_pStaticSettings->inducerPipelineName));

    pOverrideSettingsStore->ReadSettingString(
        StringHashInducerNodeName,
        m_pStaticSettings->inducerNodeName,
        sizeof(m_pStaticSettings->inducerNodeName));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashInducerRequestId,
        &m_pStaticSettings->inducerRequestId);

    pOverrideSettingsStore->ReadSettingINT(
        StringHashInducerPortId,
        &m_pStaticSettings->inducerPortId);

    tempBOOL = (m_pStaticSettings->inducerFenceMarkError == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashInducerFenceMarkError,
        &tempBOOL);
    m_pStaticSettings->inducerFenceMarkError = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpForFlush == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSessionDumpForFlush,
        &tempBOOL);
    m_pStaticSettings->sessionDumpForFlush = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpToLog == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSessionDumpToLog,
        &tempBOOL);
    m_pStaticSettings->sessionDumpToLog = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpToFile == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSessionDumpToFile,
        &tempBOOL);
    m_pStaticSettings->sessionDumpToFile = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpForRecovery == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashSessionDumpForRecovery,
        &tempBOOL);
    m_pStaticSettings->sessionDumpForRecovery = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpNodeProcessingInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpNodeProcessingInfo,
        &tempBOOL);
    m_pStaticSettings->dumpNodeProcessingInfo = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpSessionProcessingInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpSessionProcessingInfo,
        &tempBOOL);
    m_pStaticSettings->dumpSessionProcessingInfo = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashNumberOfCHIThreads,
        &m_pStaticSettings->numberOfCHIThreads);

    tempBOOL = (m_pStaticSettings->useVFETPG == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseVFETPG,
        &tempBOOL);
    m_pStaticSettings->useVFETPG = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFEBufDoneTimeout,
        &m_pStaticSettings->IFEBufDoneTimeout);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFEInputWidth,
        &m_pStaticSettings->IFEInputWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFEInputHeight,
        &m_pStaticSettings->IFEInputHeight);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEBufDoneTimeout,
        &m_pStaticSettings->IPEBufDoneTimeout);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEUnitTestIQBypassNumOfIteration,
        &m_pStaticSettings->IPEUnitTestIQBypassNumOfIteration);

    tempBOOL = (m_pStaticSettings->enableImageBufferLateBinding == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableImageBufferLateBinding,
        &tempBOOL);
    m_pStaticSettings->enableImageBufferLateBinding = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->MPMEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMEnable,
        &tempBOOL);
    m_pStaticSettings->MPMEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->MPMValidateMemPoolGroup == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMValidateMemPoolGroup,
        &tempBOOL);
    m_pStaticSettings->MPMValidateMemPoolGroup = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->MPMDoNotGroupBufferManagers == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMDoNotGroupBufferManagers,
        &tempBOOL);
    m_pStaticSettings->MPMDoNotGroupBufferManagers = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMKeepMinNumFreeBuffers,
        &m_pStaticSettings->MPMKeepMinNumFreeBuffers);

    tempBOOL = (m_pStaticSettings->MPMAllocateBuffersOnRegister == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMAllocateBuffersOnRegister,
        &tempBOOL);
    m_pStaticSettings->MPMAllocateBuffersOnRegister = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->MPMGroupIfExactDeviceMatch == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMGroupIfExactDeviceMatch,
        &tempBOOL);
    m_pStaticSettings->MPMGroupIfExactDeviceMatch = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMMinSizeForSharing,
        &m_pStaticSettings->MPMMinSizeForSharing);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMSizeDiffAllowedToGroup,
        &m_pStaticSettings->MPMSizeDiffAllowedToGroup);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMLargeGroupSizeDefinition,
        &m_pStaticSettings->MPMLargeGroupSizeDefinition);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMSizeDiffAllowedToGroupOverride,
        &m_pStaticSettings->MPMSizeDiffAllowedToGroupOverride);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMBufferAddressAlignment,
        &m_pStaticSettings->MPMBufferAddressAlignment);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashForceCHIBufferManagerHeap,
        &m_pStaticSettings->forceCHIBufferManagerHeap);

    tempBOOL = (m_pStaticSettings->MPMSelfTuneImmediateCount == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMSelfTuneImmediateCount,
        &tempBOOL);
    m_pStaticSettings->MPMSelfTuneImmediateCount = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableMPMMonitorThread == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableMPMMonitorThread,
        &tempBOOL);
    m_pStaticSettings->enableMPMMonitorThread = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMMonitorTimeInterval,
        &m_pStaticSettings->MPMMonitorTimeInterval);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMMonitorSelfShrinkSizeLimit,
        &m_pStaticSettings->MPMMonitorSelfShrinkSizeLimit);

    tempBOOL = (m_pStaticSettings->enableMPMStatelogging == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableMPMStatelogging,
        &tempBOOL);
    m_pStaticSettings->enableMPMStatelogging = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableMemoryStats == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableMemoryStats,
        &tempBOOL);
    m_pStaticSettings->enableMemoryStats = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMMinSizeToFreeOnDeactivate,
        &m_pStaticSettings->MPMMinSizeToFreeOnDeactivate);

    tempBOOL = (m_pStaticSettings->validateImageBufferUsageState == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashValidateImageBufferUsageState,
        &tempBOOL);
    m_pStaticSettings->validateImageBufferUsageState = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMSizeThresToDisableDelayedUnmap,
        &m_pStaticSettings->MPMSizeThresToDisableDelayedUnmap);

    tempBOOL = (m_pStaticSettings->MPMForceDisableDelayedUnmap == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashMPMForceDisableDelayedUnmap,
        &tempBOOL);
    m_pStaticSettings->MPMForceDisableDelayedUnmap = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashMPMSizeThresToDelayedMap,
        &m_pStaticSettings->MPMSizeThresToDelayedMap);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpAF,
        &m_pStaticSettings->dumpAF);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpAEC,
        &m_pStaticSettings->dumpAEC);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpAWB,
        &m_pStaticSettings->dumpAWB);

    tempBOOL = (m_pStaticSettings->dumpAFDRowsum == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpAFDRowsum,
        &tempBOOL);
    m_pStaticSettings->dumpAFDRowsum = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashProfile3A,
        &m_pStaticSettings->profile3A);

    if (CamxResultSuccess == result)
    {
        // Now load the hardware dependent override settings
        result = HwLoadOverrideSettings(pOverrideSettingsStore);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsManager::LoadOverrideProperties
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CamxResult SettingsManager::LoadOverrideProperties(
    IOverrideSettingsStore* pOverrideSettingsStore,
    BOOL                    updateStatic)
{
    CamxResult  result      = CamxResultSuccess;
    BOOL        tempBOOL    = FALSE;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashOutputFormat,
            reinterpret_cast<INT*>(&m_pStaticSettings->outputFormat),
            OutputFormatTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(OutputFormatTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashRefoutputFormatType,
            reinterpret_cast<INT*>(&m_pStaticSettings->refoutputFormatType),
            RefOutputFormatTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(RefOutputFormatTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNumMetadataResults,
            &m_pStaticSettings->numMetadataResults);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMaxHalRequests,
            &m_pStaticSettings->maxHalRequests);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashWaitAllResultsTimeout,
            &m_pStaticSettings->waitAllResultsTimeout);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNumWorkerThreads,
            &m_pStaticSettings->numWorkerThreads);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->chiOverrideEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashChiOverrideEnable,
            &tempBOOL);
        m_pStaticSettings->chiOverrideEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->multiCameraEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMultiCameraEnable,
            &tempBOOL);
        m_pStaticSettings->multiCameraEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMultiCameraJPEG,
            &m_pStaticSettings->multiCameraJPEG);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->multiCameraEnableFront == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMultiCameraEnableFront,
            &tempBOOL);
        m_pStaticSettings->multiCameraEnableFront = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMultiCameraVREnable,
            &m_pStaticSettings->multiCameraVREnable);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMultiCameraHWSyncMask,
            &m_pStaticSettings->multiCameraHWSyncMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMultiCameraFrameSync,
            &m_pStaticSettings->multiCameraFrameSync);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableSensorFpsMatch == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableSensorFpsMatch,
            &tempBOOL);
        m_pStaticSettings->enableSensorFpsMatch = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashMultiCamera3ASync,
            reinterpret_cast<INT*>(&m_pStaticSettings->multiCamera3ASync),
            MultiCamera3ASyncTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(MultiCamera3ASyncTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNumberOfAELockFrames,
            &m_pStaticSettings->numberOfAELockFrames);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->exportSecureCamera == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashExportSecureCamera,
            &tempBOOL);
        m_pStaticSettings->exportSecureCamera = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableRAWProcessing == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableRAWProcessing,
            &tempBOOL);
        m_pStaticSettings->enableRAWProcessing = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMaxRAWSizes,
            &m_pStaticSettings->maxRAWSizes);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableInternalHALPixelStreamConfig == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableInternalHALPixelStreamConfig,
            &tempBOOL);
        m_pStaticSettings->enableInternalHALPixelStreamConfig = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableNCSService == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableNCSService,
            &tempBOOL);
        m_pStaticSettings->enableNCSService = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMinReprocessInputWidth,
            &m_pStaticSettings->minReprocessInputWidth);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMinReprocessInputHeight,
            &m_pStaticSettings->minReprocessInputHeight);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMinInOutResolution,
            &m_pStaticSettings->minInOutResolution);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMaxInOutResolution,
            &m_pStaticSettings->maxInOutResolution);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableTOFInterface == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableTOFInterface,
            &tempBOOL);
        m_pStaticSettings->enableTOFInterface = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableThermalMitigation == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableThermalMitigation,
            &tempBOOL);
        m_pStaticSettings->enableThermalMitigation = (tempBOOL == TRUE) ? 1 : 0;

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashMaxBuffersSecureCamera,
        &m_pStaticSettings->maxBuffersSecureCamera);

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableNativeHEIF == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableNativeHEIF,
            &tempBOOL);
        m_pStaticSettings->enableNativeHEIF = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableHALFormatOverride == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableHALFormatOverride,
            &tempBOOL);
        m_pStaticSettings->enableHALFormatOverride = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMaxNumberOfAcceptedErrors,
            &m_pStaticSettings->maxNumberOfAcceptedErrors);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableResourceManager == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableResourceManager,
            &tempBOOL);
        m_pStaticSettings->enableResourceManager = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableStreamCropZoom == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableStreamCropZoom,
            &tempBOOL);
        m_pStaticSettings->enableStreamCropZoom = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashBpsRealtimeSensorId,
            &m_pStaticSettings->bpsRealtimeSensorId);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableBLMClient,
            &m_pStaticSettings->enableBLMClient);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAssertMask,
            &m_pStaticSettings->assertMask);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogWarningMask,
        &m_pStaticSettings->logWarningMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogEntryExitMask,
        &m_pStaticSettings->logEntryExitMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogConfigMask,
        &m_pStaticSettings->logConfigMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogDumpMask,
        &m_pStaticSettings->logDumpMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogInfoMask,
        &m_pStaticSettings->logInfoMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogPerfInfoMask,
        &m_pStaticSettings->logPerfInfoMask);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLogVerboseMask,
        &m_pStaticSettings->logVerboseMask);

    tempBOOL = (m_pStaticSettings->logDRQEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashLogDRQEnable,
        &tempBOOL);
    m_pStaticSettings->logDRQEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->logMetaEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashLogMetaEnable,
        &tempBOOL);
    m_pStaticSettings->logMetaEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->logRequestMapping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashLogRequestMapping,
        &tempBOOL);
    m_pStaticSettings->logRequestMapping = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->traceErrorEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashTraceErrorEnable,
            &tempBOOL);
        m_pStaticSettings->traceErrorEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->systemLogEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashSystemLogEnable,
            &tempBOOL);
        m_pStaticSettings->systemLogEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enablePipelineFlush == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnablePipelineFlush,
            &tempBOOL);
        m_pStaticSettings->enablePipelineFlush = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashDebugLogFilename,
            m_pStaticSettings->debugLogFilename,
            sizeof(m_pStaticSettings->debugLogFilename));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashTraceGroupsEnable,
            &m_pStaticSettings->traceGroupsEnable);

    }

    tempBOOL = (m_pStaticSettings->enableFPSLog == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableFPSLog,
        &tempBOOL);
    m_pStaticSettings->enableFPSLog = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashMaxMemSpyStats,
        &m_pStaticSettings->maxMemSpyStats);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashMemSpyRequestRate,
        &m_pStaticSettings->memSpyRequestRate);

    tempBOOL = (m_pStaticSettings->dynamicPropertiesEnabled == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDynamicPropertiesEnabled,
        &tempBOOL);
    m_pStaticSettings->dynamicPropertiesEnabled = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashPDebugProcess,
            m_pStaticSettings->pDebugProcess,
            sizeof(m_pStaticSettings->pDebugProcess));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashCSLMode,
            reinterpret_cast<INT*>(&m_pStaticSettings->CSLMode),
            CSLModeTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(CSLModeTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableSensorEmulation == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableSensorEmulation,
            &tempBOOL);
        m_pStaticSettings->enableSensorEmulation = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableExternalSensorModule == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableExternalSensorModule,
            &tempBOOL);
        m_pStaticSettings->enableExternalSensorModule = (tempBOOL == TRUE) ? 1 : 0;

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnableDebugSensorExposure,
        &m_pStaticSettings->enableDebugSensorExposure);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashSensorExposureTime,
        &m_pStaticSettings->sensorExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashGain,
        &m_pStaticSettings->gain);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashSensorShortExposureTime,
        &m_pStaticSettings->sensorShortExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashShortGain,
        &m_pStaticSettings->shortGain);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashSensorMiddleExposureTime,
        &m_pStaticSettings->sensorMiddleExposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashMiddleGain,
        &m_pStaticSettings->middleGain);

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->dumpSensorEmulationOutput == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDumpSensorEmulationOutput,
            &tempBOOL);
        m_pStaticSettings->dumpSensorEmulationOutput = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashSensorEmulator,
            m_pStaticSettings->sensorEmulator,
            sizeof(m_pStaticSettings->sensorEmulator));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashSensorEmulatorPath,
            m_pStaticSettings->sensorEmulatorPath,
            sizeof(m_pStaticSettings->sensorEmulatorPath));

    }

    pOverrideSettingsStore->ReadSettingEnum(
        PropStringHashDualLEDCalibrationMode,
        reinterpret_cast<INT*>(&m_pStaticSettings->dualLEDCalibrationMode),
        DualLEDCalibrationTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(DualLEDCalibrationTypeEnumeratorToHashMap)));

    tempBOOL = (m_pStaticSettings->dynamicInlineCalibration == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDynamicInlineCalibration,
        &tempBOOL);
    m_pStaticSettings->dynamicInlineCalibration = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashDynamicCalibrationMaxSize,
        &m_pStaticSettings->dynamicCalibrationMaxSize);

    pOverrideSettingsStore->ReadSettingString(
        PropStringHashDualLEDCalibrationPath,
        m_pStaticSettings->dualLEDCalibrationPath,
        sizeof(m_pStaticSettings->dualLEDCalibrationPath));

    tempBOOL = (m_pStaticSettings->disableADRC == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisableADRC,
        &tempBOOL);
    m_pStaticSettings->disableADRC = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disablePreviewManualISO == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisablePreviewManualISO,
            &tempBOOL);
        m_pStaticSettings->disablePreviewManualISO = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disablePreviewManualExpTime == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisablePreviewManualExpTime,
            &tempBOOL);
        m_pStaticSettings->disablePreviewManualExpTime = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disablePreviewManualFull == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisablePreviewManualFull,
            &tempBOOL);
        m_pStaticSettings->disablePreviewManualFull = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableSpeckleDetection == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableSpeckleDetection,
            &tempBOOL);
        m_pStaticSettings->disableSpeckleDetection = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_pStaticSettings->disableAFStatsProcessing == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisableAFStatsProcessing,
        &tempBOOL);
    m_pStaticSettings->disableAFStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableAFAlgoCHIOverload == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableAFAlgoCHIOverload,
            &tempBOOL);
        m_pStaticSettings->disableAFAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableAWBStatsProcessing == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableAWBStatsProcessing,
            &tempBOOL);
        m_pStaticSettings->disableAWBStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableAWBAlgoCHIOverload == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableAWBAlgoCHIOverload,
            &tempBOOL);
        m_pStaticSettings->disableAWBAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableAFDStatsProcessing == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableAFDStatsProcessing,
            &tempBOOL);
        m_pStaticSettings->disableAFDStatsProcessing = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableAFDAlgoCHIOverload == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableAFDAlgoCHIOverload,
            &tempBOOL);
        m_pStaticSettings->disableAFDAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDisableASDStatsProcessing,
            &m_pStaticSettings->disableASDStatsProcessing);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableASDAlgoCHIOverload == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableASDAlgoCHIOverload,
            &tempBOOL);
        m_pStaticSettings->disableASDAlgoCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->debugBufferRegDumpEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDebugBufferRegDumpEnable,
            &tempBOOL);
        m_pStaticSettings->debugBufferRegDumpEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDebugBufferRegDumpSizeInBytes,
            &m_pStaticSettings->debugBufferRegDumpSizeInBytes);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashDebugBufferRegDumpFileNamePrefix,
            m_pStaticSettings->debugBufferRegDumpFileNamePrefix,
            sizeof(m_pStaticSettings->debugBufferRegDumpFileNamePrefix));

    }

    tempBOOL = (m_pStaticSettings->dumpIPEFirmwarePayload == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDumpIPEFirmwarePayload,
        &tempBOOL);
    m_pStaticSettings->dumpIPEFirmwarePayload = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->kpiDebug == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashKpiDebug,
            &tempBOOL);
        m_pStaticSettings->kpiDebug = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableQTimer == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableQTimer,
            &tempBOOL);
        m_pStaticSettings->enableQTimer = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableTPG == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableTPG,
            &tempBOOL);
        m_pStaticSettings->enableTPG = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableCSIDBinning == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableCSIDBinning,
            &tempBOOL);
        m_pStaticSettings->enableCSIDBinning = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashCSIDBinningMode,
            &m_pStaticSettings->CSIDBinningMode);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->force3ALockedResult == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashForce3ALockedResult,
            &tempBOOL);
        m_pStaticSettings->force3ALockedResult = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->forceDisableUBWCOnIfeIpeLink == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashForceDisableUBWCOnIfeIpeLink,
            &tempBOOL);
        m_pStaticSettings->forceDisableUBWCOnIfeIpeLink = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableUBWCNV124ROnIFEFullOutIPELink,
            &tempBOOL);
        m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->capResolutionForSingleIFE == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashCapResolutionForSingleIFE,
            &tempBOOL);
        m_pStaticSettings->capResolutionForSingleIFE = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingINT(
            PropStringHashSingleIFESupportedWidth,
            &m_pStaticSettings->singleIFESupportedWidth);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingINT(
            PropStringHashSingleIFESupportedHeight,
            &m_pStaticSettings->singleIFESupportedHeight);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableFlashDebug == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableFlashDebug,
            &tempBOOL);
        m_pStaticSettings->enableFlashDebug = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_pStaticSettings->dumpSensorEEPROMData == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDumpSensorEEPROMData,
        &tempBOOL);
    m_pStaticSettings->dumpSensorEEPROMData = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->autoImageDump == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashAutoImageDump,
            &tempBOOL);
        m_pStaticSettings->autoImageDump = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->dumpInputatOutput == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDumpInputatOutput,
            &tempBOOL);
        m_pStaticSettings->dumpInputatOutput = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoInputImageDumpMask,
            &m_pStaticSettings->autoInputImageDumpMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFERegDumpMask,
            &m_pStaticSettings->IFERegDumpMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpMask,
            &m_pStaticSettings->autoImageDumpMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIFEoutputPortMask,
            &m_pStaticSettings->autoImageDumpIFEoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIFEinputPortMask,
            &m_pStaticSettings->autoImageDumpIFEinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIFEoutputBatchNum,
            &m_pStaticSettings->autoImageDumpIFEoutputBatchNum);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIFEInstanceMask,
            &m_pStaticSettings->autoImageDumpIFEInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIPEoutputPortMask,
            &m_pStaticSettings->autoImageDumpIPEoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIPEinputPortMask,
            &m_pStaticSettings->autoImageDumpIPEinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpIPEInstanceMask,
            &m_pStaticSettings->autoImageDumpIPEInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpBPSoutputPortMask,
            &m_pStaticSettings->autoImageDumpBPSoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpBPSinputPortMask,
            &m_pStaticSettings->autoImageDumpBPSinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpBPSInstanceMask,
            &m_pStaticSettings->autoImageDumpBPSInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpJpegHwoutputPortMask,
            &m_pStaticSettings->autoImageDumpJpegHwoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpJpegHwinputPortMask,
            &m_pStaticSettings->autoImageDumpJpegHwinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpJpegHwInstanceMask,
            &m_pStaticSettings->autoImageDumpJpegHwInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpFDHwoutputPortMask,
            &m_pStaticSettings->autoImageDumpFDHwoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpFDHwinputPortMask,
            &m_pStaticSettings->autoImageDumpFDHwinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpFDHwInstanceMask,
            &m_pStaticSettings->autoImageDumpFDHwInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpLRMEoutputPortMask,
            &m_pStaticSettings->autoImageDumpLRMEoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpLRMEinputPortMask,
            &m_pStaticSettings->autoImageDumpLRMEinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpLRMEInstanceMask,
            &m_pStaticSettings->autoImageDumpLRMEInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpRANSACoutputPortMask,
            &m_pStaticSettings->autoImageDumpRANSACoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpRANSACinputPortMask,
            &m_pStaticSettings->autoImageDumpRANSACinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpRANSACInstanceMask,
            &m_pStaticSettings->autoImageDumpRANSACInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCHINodeoutputPortMask,
            &m_pStaticSettings->autoImageDumpCHINodeoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCHINodeinputPortMask,
            &m_pStaticSettings->autoImageDumpCHINodeinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCHINodeInstanceMask,
            &m_pStaticSettings->autoImageDumpCHINodeInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCVPoutputPortMask,
            &m_pStaticSettings->autoImageDumpCVPoutputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCVPinputPortMask,
            &m_pStaticSettings->autoImageDumpCVPinputPortMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAutoImageDumpCVPInstanceMask,
            &m_pStaticSettings->autoImageDumpCVPInstanceMask);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->dynamicImageDump == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDynamicImageDump,
            &tempBOOL);
        m_pStaticSettings->dynamicImageDump = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_pStaticSettings->dynamicImageDumpTrigger == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDynamicImageDumpTrigger,
        &tempBOOL);
    m_pStaticSettings->dynamicImageDumpTrigger = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->watermarkImage == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashWatermarkImage,
            &tempBOOL);
        m_pStaticSettings->watermarkImage = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashWatermarkOffset,
            m_pStaticSettings->watermarkOffset,
            sizeof(m_pStaticSettings->watermarkOffset));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->reprocessDump == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashReprocessDump,
            &tempBOOL);
        m_pStaticSettings->reprocessDump = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->offlineImageDumpOnly == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashOfflineImageDumpOnly,
            &tempBOOL);
        m_pStaticSettings->offlineImageDumpOnly = (tempBOOL == TRUE) ? 1 : 0;

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnableIPEHangDump,
        &m_pStaticSettings->enableIPEHangDump);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnableBPSHangDump,
        &m_pStaticSettings->enableBPSHangDump);

    tempBOOL = (m_pStaticSettings->enableIPEStripeDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableIPEStripeDump,
        &tempBOOL);
    m_pStaticSettings->enableIPEStripeDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableBPSStripeDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableBPSStripeDump,
        &tempBOOL);
    m_pStaticSettings->enableBPSStripeDump = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableIPEScratchBufferDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableIPEScratchBufferDump,
        &tempBOOL);
    m_pStaticSettings->enableIPEScratchBufferDump = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashForceMaxFPS,
            &m_pStaticSettings->forceMaxFPS);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashKickTheMachine,
            &m_pStaticSettings->kickTheMachine);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->perFrameSensorMode == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashPerFrameSensorMode,
            &tempBOOL);
        m_pStaticSettings->perFrameSensorMode = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_pStaticSettings->disablePDAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisablePDAF,
        &tempBOOL);
    m_pStaticSettings->disablePDAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableTouchToTrack == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableTouchToTrack,
        &tempBOOL);
    m_pStaticSettings->enableTouchToTrack = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashTouchToTrackDownscaleRatio,
        &m_pStaticSettings->touchToTrackDownscaleRatio);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashTouchToTrackSCVEOperationMode,
        &m_pStaticSettings->touchToTrackSCVEOperationMode);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashTouchToTrackSCVEPrecisionMode,
        &m_pStaticSettings->touchToTrackSCVEPrecisionMode);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashT2tConfidenceThreshold,
        &m_pStaticSettings->t2tConfidenceThreshold);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDefaultMaxFPS,
            &m_pStaticSettings->defaultMaxFPS);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->bypassIPEICADependency == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashBypassIPEICADependency,
            &tempBOOL);
        m_pStaticSettings->bypassIPEICADependency = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableDRQPreemptionOnStopRecord == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableDRQPreemptionOnStopRecord,
            &tempBOOL);
        m_pStaticSettings->disableDRQPreemptionOnStopRecord = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableVideoPerfModeSetting == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableVideoPerfModeSetting,
            &tempBOOL);
        m_pStaticSettings->disableVideoPerfModeSetting = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableSensorAcquireOptimization == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableSensorAcquireOptimization,
            &tempBOOL);
        m_pStaticSettings->enableSensorAcquireOptimization = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingINT(
            PropStringHashCamVersionOverride,
            &m_pStaticSettings->camVersionOverride);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashOverrideOPPCLOCK,
        &m_pStaticSettings->overrideOPPCLOCK);

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->dumpGeolibResult == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDumpGeolibResult,
            &tempBOOL);
        m_pStaticSettings->dumpGeolibResult = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->dumpCVPICAInputConfig == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDumpCVPICAInputConfig,
            &tempBOOL);
        m_pStaticSettings->dumpCVPICAInputConfig = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashTfTestMode,
            &m_pStaticSettings->tfTestMode);

    }

    tempBOOL = (m_pStaticSettings->enableHJAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableHJAF,
        &tempBOOL);
    m_pStaticSettings->enableHJAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableSPD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableSPD,
        &tempBOOL);
    m_pStaticSettings->enableSPD = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashSpdStatsType,
        &m_pStaticSettings->spdStatsType);

    tempBOOL = (m_pStaticSettings->disableFocusIndication == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisableFocusIndication,
        &tempBOOL);
    m_pStaticSettings->disableFocusIndication = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->spotlightFallbackToCAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashSpotlightFallbackToCAF,
        &tempBOOL);
    m_pStaticSettings->spotlightFallbackToCAF = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAfLog,
            &m_pStaticSettings->afLog);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashFovcEnable,
        &m_pStaticSettings->fovcEnable);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashGyroDataReportRate,
        &m_pStaticSettings->gyroDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashGyroSensorSamplingRate,
        &m_pStaticSettings->gyroSensorSamplingRate);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashGravityDataReportRate,
        &m_pStaticSettings->gravityDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashGravitySensorSamplingRate,
        &m_pStaticSettings->gravitySensorSamplingRate);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashTOFDataReportRate,
        &m_pStaticSettings->TOFDataReportRate);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashTOFSensorSamplingRate,
        &m_pStaticSettings->TOFSensorSamplingRate);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomTOFSensorLib,
            m_pStaticSettings->customTOFSensorLib,
            sizeof(m_pStaticSettings->customTOFSensorLib));

    }

    tempBOOL = (m_pStaticSettings->mwEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashMwEnable,
        &tempBOOL);
    m_pStaticSettings->mwEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        PropStringHashEnableAFAlgo,
        reinterpret_cast<INT*>(&m_pStaticSettings->enableAFAlgo),
        EnableAFAlgoTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(EnableAFAlgoTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        PropStringHashAfFullsweep,
        reinterpret_cast<INT*>(&m_pStaticSettings->afFullsweep),
        AFFullsweepTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(AFFullsweepTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        PropStringHashManualAf,
        reinterpret_cast<INT*>(&m_pStaticSettings->manualAf),
        AFManualLensControlTypeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(AFManualLensControlTypeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashLensPos,
        &m_pStaticSettings->lensPos);

    pOverrideSettingsStore->ReadSettingString(
        PropStringHashVmDebugMask,
        m_pStaticSettings->vmDebugMask,
        sizeof(m_pStaticSettings->vmDebugMask));

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashAFRecorderMode,
        &m_pStaticSettings->AFRecorderMode);

    tempBOOL = (m_pStaticSettings->enableLensSagComp == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableLensSagComp,
        &tempBOOL);
    m_pStaticSettings->enableLensSagComp = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        PropStringHashActiveNodeMask,
        m_pStaticSettings->activeNodeMask,
        sizeof(m_pStaticSettings->activeNodeMask));

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashApiMask,
        &m_pStaticSettings->apiMask);

    tempBOOL = (m_pStaticSettings->manualExposureType == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashManualExposureType,
        &tempBOOL);
    m_pStaticSettings->manualExposureType = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dualBHistSupport == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDualBHistSupport,
        &tempBOOL);
    m_pStaticSettings->dualBHistSupport = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableBGStatsForAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisableBGStatsForAF,
        &tempBOOL);
    m_pStaticSettings->disableBGStatsForAF = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAEC == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomAlgoAEC,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAEC = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->disableAFAWBpreFlash == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisableAFAWBpreFlash,
        &tempBOOL);
    m_pStaticSettings->disableAFAWBpreFlash = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashYuvPlaneAlignment,
            &m_pStaticSettings->yuvPlaneAlignment);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashPreFlashMaxFrameWaitLimitAF,
        &m_pStaticSettings->preFlashMaxFrameWaitLimitAF);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashPreFlashMaxFrameWaitLimitAWB,
        &m_pStaticSettings->preFlashMaxFrameWaitLimitAWB);

    tempBOOL = (m_pStaticSettings->disablePreFlashOnForTouchAE == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisablePreFlashOnForTouchAE,
        &tempBOOL);
    m_pStaticSettings->disablePreFlashOnForTouchAE = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashNumberOfFramesToSkip,
        &m_pStaticSettings->numberOfFramesToSkip);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAECName,
            m_pStaticSettings->customAlgoAECName,
            sizeof(m_pStaticSettings->customAlgoAECName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAECPath,
            m_pStaticSettings->customAlgoAECPath,
            sizeof(m_pStaticSettings->customAlgoAECPath));

    }

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAWB == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomAlgoAWB,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAWB = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAWBName,
            m_pStaticSettings->customAlgoAWBName,
            sizeof(m_pStaticSettings->customAlgoAWBName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAWBPath,
            m_pStaticSettings->customAlgoAWBPath,
            sizeof(m_pStaticSettings->customAlgoAWBPath));

    }

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAF == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomAlgoAF,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAF = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAFName,
            m_pStaticSettings->customAlgoAFName,
            sizeof(m_pStaticSettings->customAlgoAFName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAFPath,
            m_pStaticSettings->customAlgoAFPath,
            sizeof(m_pStaticSettings->customAlgoAFPath));

    }

    tempBOOL = (m_pStaticSettings->enableCustomHAFAlgo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomHAFAlgo,
        &tempBOOL);
    m_pStaticSettings->enableCustomHAFAlgo = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomHAFAlgoName,
            m_pStaticSettings->customHAFAlgoName,
            sizeof(m_pStaticSettings->customHAFAlgoName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomHAFAlgoPath,
            m_pStaticSettings->customHAFAlgoPath,
            sizeof(m_pStaticSettings->customHAFAlgoPath));

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashOverrideHAFAlgoMask,
        &m_pStaticSettings->overrideHAFAlgoMask);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashExposureGain,
        &m_pStaticSettings->exposureGain);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashExposureTime,
        &m_pStaticSettings->exposureTime);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashLuxIndex,
        &m_pStaticSettings->luxIndex);

    tempBOOL = (m_pStaticSettings->extendedTimeForLongExposure == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashExtendedTimeForLongExposure,
        &tempBOOL);
    m_pStaticSettings->extendedTimeForLongExposure = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->manualWhiteBalanceType == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashManualWhiteBalanceType,
        &tempBOOL);
    m_pStaticSettings->manualWhiteBalanceType = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashRGain,
        &m_pStaticSettings->rGain);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashGGain,
        &m_pStaticSettings->gGain);

    pOverrideSettingsStore->ReadSettingFLOAT(
        PropStringHashBGain,
        &m_pStaticSettings->BGain);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashColorTemp,
        &m_pStaticSettings->colorTemp);

    tempBOOL = (m_pStaticSettings->ignoreSceneMode == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashIgnoreSceneMode,
        &tempBOOL);
    m_pStaticSettings->ignoreSceneMode = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableCustomAlgoASD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomAlgoASD,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoASD = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoASDName,
            m_pStaticSettings->customAlgoASDName,
            sizeof(m_pStaticSettings->customAlgoASDName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoASDPath,
            m_pStaticSettings->customAlgoASDPath,
            sizeof(m_pStaticSettings->customAlgoASDPath));

    }

    tempBOOL = (m_pStaticSettings->enableCustomAlgoAFD == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableCustomAlgoAFD,
        &tempBOOL);
    m_pStaticSettings->enableCustomAlgoAFD = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAFDName,
            m_pStaticSettings->customAlgoAFDName,
            sizeof(m_pStaticSettings->customAlgoAFDName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomAlgoAFDPath,
            m_pStaticSettings->customAlgoAFDPath,
            sizeof(m_pStaticSettings->customAlgoAFDPath));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableDualIFE == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableDualIFE,
            &tempBOOL);
        m_pStaticSettings->enableDualIFE = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->forceDualIFEOn == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashForceDualIFEOn,
            &tempBOOL);
        m_pStaticSettings->forceDualIFEOn = (tempBOOL == TRUE) ? 1 : 0;

    }

    pOverrideSettingsStore->ReadSettingINT(
        PropStringHashDualIFESplitPointOffset,
        &m_pStaticSettings->dualIFESplitPointOffset);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashDualIFELeftPadding,
        &m_pStaticSettings->dualIFELeftPadding);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashDualIFERightPadding,
        &m_pStaticSettings->dualIFERightPadding);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFETestImageSizeWidth,
            &m_pStaticSettings->IFETestImageSizeWidth);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFETestImageSizeHeight,
            &m_pStaticSettings->IFETestImageSizeHeight);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->DisableManual3ACCM == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableManual3ACCM,
            &tempBOOL);
        m_pStaticSettings->DisableManual3ACCM = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFENumFramesHighBW,
            &m_pStaticSettings->IFENumFramesHighBW);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableActiveIFEABVote == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableActiveIFEABVote,
            &tempBOOL);
        m_pStaticSettings->enableActiveIFEABVote = (tempBOOL == TRUE) ? 1 : 0;

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashIFEDynamicEnableMask,
        &m_pStaticSettings->IFEDynamicEnableMask);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIfeClockFrequencyMHz,
            &m_pStaticSettings->ifeClockFrequencyMHz);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIfeCamnocBandwidthMBytes,
            &m_pStaticSettings->ifeCamnocBandwidthMBytes);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIfeExternalBandwidthMBytes,
            &m_pStaticSettings->ifeExternalBandwidthMBytes);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableHVXStreaming == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableHVXStreaming,
            &tempBOOL);
        m_pStaticSettings->enableHVXStreaming = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableIPEIQModulesMask,
            &m_pStaticSettings->enableIPEIQModulesMask);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableIPEUpscale == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableIPEUpscale,
            &tempBOOL);
        m_pStaticSettings->enableIPEUpscale = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableIPEOnlyDownscale == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableIPEOnlyDownscale,
            &tempBOOL);
        m_pStaticSettings->enableIPEOnlyDownscale = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableIPEInternalDownscale == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableIPEInternalDownscale,
            &tempBOOL);
        m_pStaticSettings->disableIPEInternalDownscale = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableIPEDependencies == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableIPEDependencies,
            &tempBOOL);
        m_pStaticSettings->enableIPEDependencies = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableIPEIQLogging == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableIPEIQLogging,
            &tempBOOL);
        m_pStaticSettings->enableIPEIQLogging = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableMCTF == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableMCTF,
            &tempBOOL);
        m_pStaticSettings->enableMCTF = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableCVPDriver == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableCVPDriver,
            &tempBOOL);
        m_pStaticSettings->disableCVPDriver = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNumIPECoresToUse,
            &m_pStaticSettings->numIPECoresToUse);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->force8BitUBWCAlignment == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashForce8BitUBWCAlignment,
            &tempBOOL);
        m_pStaticSettings->force8BitUBWCAlignment = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashSetLRMETransformTypeMask,
            &m_pStaticSettings->setLRMETransformTypeMask);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->isGridFromChromatixEnabled == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIsGridFromChromatixEnabled,
            &tempBOOL);
        m_pStaticSettings->isGridFromChromatixEnabled = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashAlignmentFusionMode,
            reinterpret_cast<INT*>(&m_pStaticSettings->alignmentFusionMode),
            AlignmentFusionModesEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(AlignmentFusionModesEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIsFirstFrameLoopbackInputImageEnabled,
            &m_pStaticSettings->isFirstFrameLoopbackInputImageEnabled);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableLDC == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableLDC,
            &tempBOOL);
        m_pStaticSettings->enableLDC = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashDebugDataHeaderString,
            m_pStaticSettings->debugDataHeaderString,
            sizeof(m_pStaticSettings->debugDataHeaderString));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enable3ADebugData == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnable3ADebugData,
            &tempBOOL);
        m_pStaticSettings->enable3ADebugData = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDebugDataSizeAEC,
            &m_pStaticSettings->debugDataSizeAEC);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDebugDataSizeAWB,
            &m_pStaticSettings->debugDataSizeAWB);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDebugDataSizeAF,
            &m_pStaticSettings->debugDataSizeAF);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableTuningMetadata == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableTuningMetadata,
            &tempBOOL);
        m_pStaticSettings->enableTuningMetadata = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashTuningDumpDataSizeIFE,
            &m_pStaticSettings->tuningDumpDataSizeIFE);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashTuningDumpDataSizeIPE,
            &m_pStaticSettings->tuningDumpDataSizeIPE);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashTuningDumpDataSizeBPS,
            &m_pStaticSettings->tuningDumpDataSizeBPS);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDumpDebugDataEveryProcessResult,
            &m_pStaticSettings->dumpDebugDataEveryProcessResult);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->debugDataOfflineAlloc == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDebugDataOfflineAlloc,
            &tempBOOL);
        m_pStaticSettings->debugDataOfflineAlloc = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disablePDLibCHIOverload == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisablePDLibCHIOverload,
            &tempBOOL);
        m_pStaticSettings->disablePDLibCHIOverload = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableCustomPDLib == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableCustomPDLib,
            &tempBOOL);
        m_pStaticSettings->enableCustomPDLib = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomPDLibName,
            m_pStaticSettings->customPDLibName,
            sizeof(m_pStaticSettings->customPDLibName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashCustomPDLibPath,
            m_pStaticSettings->customPDLibPath,
            sizeof(m_pStaticSettings->customPDLibPath));

    }

    tempBOOL = (m_pStaticSettings->tintlessEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashTintlessEnable,
        &tempBOOL);
    m_pStaticSettings->tintlessEnable = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnablePDLibLog,
        &m_pStaticSettings->enablePDLibLog);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnablePDLibTestMode,
        &m_pStaticSettings->enablePDLibTestMode);

    tempBOOL = (m_pStaticSettings->enablePDLibProfiling == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnablePDLibProfiling,
        &tempBOOL);
    m_pStaticSettings->enablePDLibProfiling = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashEnablePDLibDump,
        &m_pStaticSettings->enablePDLibDump);

    tempBOOL = (m_pStaticSettings->disablePDLibLCR == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDisablePDLibLCR,
        &tempBOOL);
    m_pStaticSettings->disablePDLibLCR = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->ifeSWCDMEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIfeSWCDMEnable,
            &tempBOOL);
        m_pStaticSettings->ifeSWCDMEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableAEScan,
            &m_pStaticSettings->enableAEScan);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideLogLevels,
            &m_pStaticSettings->overrideLogLevels);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideDisableZSL,
            &m_pStaticSettings->overrideDisableZSL);

    }

    tempBOOL = (m_pStaticSettings->enableLRMEDS2 == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableLRMEDS2,
        &tempBOOL);
    m_pStaticSettings->enableLRMEDS2 = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideEnableMFNR,
            &m_pStaticSettings->overrideEnableMFNR);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAnchorSelectionAlgoForMFNR,
            &m_pStaticSettings->anchorSelectionAlgoForMFNR);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAnchorAlgoSelectionType,
            &m_pStaticSettings->anchorAlgoSelectionType);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashAdvanceFeatureMask,
            &m_pStaticSettings->advanceFeatureMask);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableOfflineNoiseReprocess,
            &m_pStaticSettings->enableOfflineNoiseReprocess);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableGamma15PreCalculate,
            &m_pStaticSettings->enableGamma15PreCalculate);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideForceUsecaseId,
            &m_pStaticSettings->overrideForceUsecaseId);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideForceSensorMode,
            &m_pStaticSettings->overrideForceSensorMode);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->overrideForceFSCapable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashOverrideForceFSCapable,
            &tempBOOL);
        m_pStaticSettings->overrideForceFSCapable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideGPURotationUsecase,
            &m_pStaticSettings->overrideGPURotationUsecase);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideGPUDownscaleUsecase,
            &m_pStaticSettings->overrideGPUDownscaleUsecase);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideHFRNo3AUseCase,
            &m_pStaticSettings->overrideHFRNo3AUseCase);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideCameraClose,
            &m_pStaticSettings->overrideCameraClose);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideCameraOpen,
            &m_pStaticSettings->overrideCameraOpen);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverridePDLibClose,
            &m_pStaticSettings->overridePDLibClose);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverridePDLibOpen,
            &m_pStaticSettings->overridePDLibOpen);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEISV2Enable,
            &m_pStaticSettings->EISV2Enable);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEISV3Enable,
            &m_pStaticSettings->EISV3Enable);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingFLOAT(
            PropStringHashEISV2Margin,
            &m_pStaticSettings->EISV2Margin);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEISV2FrameDelay,
            &m_pStaticSettings->EISV2FrameDelay);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingFLOAT(
            PropStringHashEISV3Margin,
            &m_pStaticSettings->EISV3Margin);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEISV3FrameDelay,
            &m_pStaticSettings->EISV3FrameDelay);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNumPCRsBeforeStreamOn,
            &m_pStaticSettings->numPCRsBeforeStreamOn);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashMaxImageBufferTimeoutCount,
        &m_pStaticSettings->maxImageBufferTimeoutCount);

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashImageBufferWaitTime,
        &m_pStaticSettings->imageBufferWaitTime);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideMaxImageBufferCountRealTime,
            &m_pStaticSettings->overrideMaxImageBufferCountRealTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashOverrideMaxImageBufferCountNonRealTime,
            &m_pStaticSettings->overrideMaxImageBufferCountNonRealTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashStatsProcessingSkipFactor,
            &m_pStaticSettings->statsProcessingSkipFactor);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMaxNonHfrFps,
            &m_pStaticSettings->maxNonHfrFps);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMinFrameRateBound,
            &m_pStaticSettings->minFrameRateBound);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableOISOptimization == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableOISOptimization,
            &tempBOOL);
        m_pStaticSettings->enableOISOptimization = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableSensorCaching == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableSensorCaching,
            &tempBOOL);
        m_pStaticSettings->enableSensorCaching = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->forceDebugQCFASWRemosaic == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashForceDebugQCFASWRemosaic,
            &tempBOOL);
        m_pStaticSettings->forceDebugQCFASWRemosaic = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashEnableCHIPartialData,
            reinterpret_cast<INT*>(&m_pStaticSettings->enableCHIPartialData),
            CHIPartialDataTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(CHIPartialDataTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableCHIPartialDataRecovery,
            &m_pStaticSettings->enableCHIPartialDataRecovery);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashDumpMetadata,
        &m_pStaticSettings->dumpMetadata);

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMemsetInputMeta,
            &m_pStaticSettings->memsetInputMeta);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableLinearMetaLUT == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableLinearMetaLUT,
            &tempBOOL);
        m_pStaticSettings->enableLinearMetaLUT = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableFDStreamInRealTime,
            &m_pStaticSettings->enableFDStreamInRealTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashSelectInSensorHDR3ExpUsecase,
            &m_pStaticSettings->selectInSensorHDR3ExpUsecase);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableUnifiedBufferManager,
            &m_pStaticSettings->enableUnifiedBufferManager);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableCHIImageBufferLateBinding,
            &m_pStaticSettings->enableCHIImageBufferLateBinding);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableFeature2Dump,
            &m_pStaticSettings->enableFeature2Dump);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashForceHWMFFixedNumOfFrames,
            &m_pStaticSettings->forceHWMFFixedNumOfFrames);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableTBMChiFence,
            &m_pStaticSettings->enableTBMChiFence);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableMFSRChiFence,
            &m_pStaticSettings->enableMFSRChiFence);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableRawHDR,
            &m_pStaticSettings->enableRawHDR);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDProcessingControl,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDProcessingControl),
            FDProcessingControlTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDProcessingControlTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableFDManagerThreading == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableFDManagerThreading,
            &tempBOOL);
        m_pStaticSettings->enableFDManagerThreading = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDBaseResolution,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDBaseResolution),
            FDBaseResolutionTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDBaseResolutionTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDConfigSource,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDConfigSource),
            FDConfigSourceTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDConfigSourceTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDMultiCamProcess,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDMultiCamProcess),
            FDMultiCamProcessingTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDMultiCamProcessingTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useAlternateFrameSkip == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseAlternateFrameSkip,
            &tempBOOL);
        m_pStaticSettings->useAlternateFrameSkip = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useDeviceOrientationInFD == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseDeviceOrientationInFD,
            &tempBOOL);
        m_pStaticSettings->useDeviceOrientationInFD = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->getAccelInfoUsingVendorTag == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashGetAccelInfoUsingVendorTag,
            &tempBOOL);
        m_pStaticSettings->getAccelInfoUsingVendorTag = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashAccelVendorTagSection,
            m_pStaticSettings->accelVendorTagSection,
            sizeof(m_pStaticSettings->accelVendorTagSection));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingString(
            PropStringHashAccelVendorTagName,
            m_pStaticSettings->accelVendorTagName,
            sizeof(m_pStaticSettings->accelVendorTagName));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDFilterEngine,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDFilterEngine),
            FDFilterEngineTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDFilterEngineTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDClient,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDClient),
            FDClientTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDClientTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disablePostingResults == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisablePostingResults,
            &tempBOOL);
        m_pStaticSettings->disablePostingResults = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableOfflineFD == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableOfflineFD,
            &tempBOOL);
        m_pStaticSettings->enableOfflineFD = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MetadataVisibility == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMetadataVisibility,
            &tempBOOL);
        m_pStaticSettings->MetadataVisibility = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useDifferentTuningForFrontCamera == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseDifferentTuningForFrontCamera,
            &tempBOOL);
        m_pStaticSettings->useDifferentTuningForFrontCamera = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useFDInternalBuffers == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseFDInternalBuffers,
            &tempBOOL);
        m_pStaticSettings->useFDInternalBuffers = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useFDUseCasePool == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseFDUseCasePool,
            &tempBOOL);
        m_pStaticSettings->useFDUseCasePool = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->fastFDMetadata == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashFastFDMetadata,
            &tempBOOL);
        m_pStaticSettings->fastFDMetadata = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMinReqFdDependency,
            &m_pStaticSettings->minReqFdDependency);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDPreprocessing,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDPreprocessing),
            FDPreProcessingTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDPreProcessingTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableFDPreprocessingAlways == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableFDPreprocessingAlways,
            &tempBOOL);
        m_pStaticSettings->enableFDPreprocessingAlways = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableFDPreprocessDumping == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableFDPreprocessDumping,
            &tempBOOL);
        m_pStaticSettings->enableFDPreprocessDumping = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->acceptAppUIFacialAttrSettings == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashAcceptAppUIFacialAttrSettings,
            &tempBOOL);
        m_pStaticSettings->acceptAppUIFacialAttrSettings = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enablePTDetection == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnablePTDetection,
            &tempBOOL);
        m_pStaticSettings->enablePTDetection = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableSMDetection == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableSMDetection,
            &tempBOOL);
        m_pStaticSettings->enableSMDetection = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableGBDetection == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableGBDetection,
            &tempBOOL);
        m_pStaticSettings->enableGBDetection = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableCTDetection == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableCTDetection,
            &tempBOOL);
        m_pStaticSettings->enableCTDetection = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingEnum(
            PropStringHashFDThreadTaskAllocation,
            reinterpret_cast<INT*>(&m_pStaticSettings->FDThreadTaskAllocation),
            FDThreadTaskAllocationTypeEnumeratorToHashMap,
            static_cast<UINT>(CAMX_ARRAY_SIZE(FDThreadTaskAllocationTypeEnumeratorToHashMap)));

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableJPEGEXIFApp2 == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableJPEGEXIFApp2,
            &tempBOOL);
        m_pStaticSettings->enableJPEGEXIFApp2 = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->disableFlash == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableFlash,
            &tempBOOL);
        m_pStaticSettings->disableFlash = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableWatchdogRecovery == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableWatchdogRecovery,
            &tempBOOL);
        m_pStaticSettings->enableWatchdogRecovery = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashNodeResponseTime,
            &m_pStaticSettings->nodeResponseTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashSessionResponseTimePadding,
            &m_pStaticSettings->sessionResponseTimePadding);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashSessionMaxFlushWaitTime,
            &m_pStaticSettings->sessionMaxFlushWaitTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashSessionFallbackWaitTime,
            &m_pStaticSettings->sessionFallbackWaitTime);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashFeature1,
            &m_pStaticSettings->feature1);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashFeature2,
            &m_pStaticSettings->feature2);

    }

    tempBOOL = (m_pStaticSettings->raisesigabrt == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashRaisesigabrt,
        &tempBOOL);
    m_pStaticSettings->raisesigabrt = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->raiserecoverysigabrt == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashRaiserecoverysigabrt,
        &tempBOOL);
    m_pStaticSettings->raiserecoverysigabrt = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->enableRecovery == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableRecovery,
        &tempBOOL);
    m_pStaticSettings->enableRecovery = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableAsciiLogging,
            &m_pStaticSettings->enableAsciiLogging);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashEnableBinaryLogging,
            &m_pStaticSettings->enableBinaryLogging);

    }

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashOfflineLoggerMinFlushCnt,
        &m_pStaticSettings->offlineLoggerMinFlushCnt);

    tempBOOL = (m_pStaticSettings->enableFenceDrop == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableFenceDrop,
        &tempBOOL);
    m_pStaticSettings->enableFenceDrop = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->inducerIsRealTime == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashInducerIsRealTime,
        &tempBOOL);
    m_pStaticSettings->inducerIsRealTime = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingString(
        PropStringHashInducerPipelineName,
        m_pStaticSettings->inducerPipelineName,
        sizeof(m_pStaticSettings->inducerPipelineName));

    pOverrideSettingsStore->ReadSettingString(
        PropStringHashInducerNodeName,
        m_pStaticSettings->inducerNodeName,
        sizeof(m_pStaticSettings->inducerNodeName));

    pOverrideSettingsStore->ReadSettingUINT(
        PropStringHashInducerRequestId,
        &m_pStaticSettings->inducerRequestId);

    pOverrideSettingsStore->ReadSettingINT(
        PropStringHashInducerPortId,
        &m_pStaticSettings->inducerPortId);

    tempBOOL = (m_pStaticSettings->inducerFenceMarkError == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashInducerFenceMarkError,
        &tempBOOL);
    m_pStaticSettings->inducerFenceMarkError = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpForFlush == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashSessionDumpForFlush,
        &tempBOOL);
    m_pStaticSettings->sessionDumpForFlush = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpToLog == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashSessionDumpToLog,
        &tempBOOL);
    m_pStaticSettings->sessionDumpToLog = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpToFile == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashSessionDumpToFile,
        &tempBOOL);
    m_pStaticSettings->sessionDumpToFile = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->sessionDumpForRecovery == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashSessionDumpForRecovery,
        &tempBOOL);
    m_pStaticSettings->sessionDumpForRecovery = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpNodeProcessingInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDumpNodeProcessingInfo,
        &tempBOOL);
    m_pStaticSettings->dumpNodeProcessingInfo = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_pStaticSettings->dumpSessionProcessingInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDumpSessionProcessingInfo,
        &tempBOOL);
    m_pStaticSettings->dumpSessionProcessingInfo = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->useVFETPG == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseVFETPG,
            &tempBOOL);
        m_pStaticSettings->useVFETPG = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFEBufDoneTimeout,
            &m_pStaticSettings->IFEBufDoneTimeout);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFEInputWidth,
            &m_pStaticSettings->IFEInputWidth);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIFEInputHeight,
            &m_pStaticSettings->IFEInputHeight);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIPEBufDoneTimeout,
            &m_pStaticSettings->IPEBufDoneTimeout);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIPEUnitTestIQBypassNumOfIteration,
            &m_pStaticSettings->IPEUnitTestIQBypassNumOfIteration);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableImageBufferLateBinding == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableImageBufferLateBinding,
            &tempBOOL);
        m_pStaticSettings->enableImageBufferLateBinding = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMEnable,
            &tempBOOL);
        m_pStaticSettings->MPMEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMValidateMemPoolGroup == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMValidateMemPoolGroup,
            &tempBOOL);
        m_pStaticSettings->MPMValidateMemPoolGroup = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMDoNotGroupBufferManagers == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMDoNotGroupBufferManagers,
            &tempBOOL);
        m_pStaticSettings->MPMDoNotGroupBufferManagers = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMKeepMinNumFreeBuffers,
            &m_pStaticSettings->MPMKeepMinNumFreeBuffers);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMAllocateBuffersOnRegister == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMAllocateBuffersOnRegister,
            &tempBOOL);
        m_pStaticSettings->MPMAllocateBuffersOnRegister = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMGroupIfExactDeviceMatch == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMGroupIfExactDeviceMatch,
            &tempBOOL);
        m_pStaticSettings->MPMGroupIfExactDeviceMatch = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMMinSizeForSharing,
            &m_pStaticSettings->MPMMinSizeForSharing);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMSizeDiffAllowedToGroup,
            &m_pStaticSettings->MPMSizeDiffAllowedToGroup);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMLargeGroupSizeDefinition,
            &m_pStaticSettings->MPMLargeGroupSizeDefinition);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMSizeDiffAllowedToGroupOverride,
            &m_pStaticSettings->MPMSizeDiffAllowedToGroupOverride);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMBufferAddressAlignment,
            &m_pStaticSettings->MPMBufferAddressAlignment);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashForceCHIBufferManagerHeap,
            &m_pStaticSettings->forceCHIBufferManagerHeap);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMSelfTuneImmediateCount == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMSelfTuneImmediateCount,
            &tempBOOL);
        m_pStaticSettings->MPMSelfTuneImmediateCount = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableMPMMonitorThread == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableMPMMonitorThread,
            &tempBOOL);
        m_pStaticSettings->enableMPMMonitorThread = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMMonitorTimeInterval,
            &m_pStaticSettings->MPMMonitorTimeInterval);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMMonitorSelfShrinkSizeLimit,
            &m_pStaticSettings->MPMMonitorSelfShrinkSizeLimit);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableMPMStatelogging == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableMPMStatelogging,
            &tempBOOL);
        m_pStaticSettings->enableMPMStatelogging = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->enableMemoryStats == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableMemoryStats,
            &tempBOOL);
        m_pStaticSettings->enableMemoryStats = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMMinSizeToFreeOnDeactivate,
            &m_pStaticSettings->MPMMinSizeToFreeOnDeactivate);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->validateImageBufferUsageState == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashValidateImageBufferUsageState,
            &tempBOOL);
        m_pStaticSettings->validateImageBufferUsageState = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMSizeThresToDisableDelayedUnmap,
            &m_pStaticSettings->MPMSizeThresToDisableDelayedUnmap);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_pStaticSettings->MPMForceDisableDelayedUnmap == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashMPMForceDisableDelayedUnmap,
            &tempBOOL);
        m_pStaticSettings->MPMForceDisableDelayedUnmap = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashMPMSizeThresToDelayedMap,
            &m_pStaticSettings->MPMSizeThresToDelayedMap);

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashProfile3A,
            &m_pStaticSettings->profile3A);

    }

    if (CamxResultSuccess == result)
    {
        // Now load the hardware dependent override properties
        result = HwLoadOverrideProperties(pOverrideSettingsStore, updateStatic);
    }

    return result;
}

#if SETTINGS_DUMP_ENABLE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsManager::DumpSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID SettingsManager::DumpSettings() const
{
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "=============== BEGIN DUMP OF CURRENT HARDWARE-INDEPENDENT SETTINGS VALUES ===============");
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "<Setting> (<Hash>) = <Value>");
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "outputFormat (0xFC924BE1) = %d", m_pStaticSettings->outputFormat);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "refoutputFormatType (0x7AE22340) = %d", m_pStaticSettings->refoutputFormatType);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IsStrideSettingEnable (0x4D7EB8E9) = %d", m_pStaticSettings->IsStrideSettingEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numMetadataResults (0x31A11A6A) = %d", m_pStaticSettings->numMetadataResults);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxHalRequests (0x88CF0DA6) = %d", m_pStaticSettings->maxHalRequests);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "waitAllResultsTimeout (0x9658B9F2) = %d", m_pStaticSettings->waitAllResultsTimeout);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numWorkerThreads (0x915563E3) = %d", m_pStaticSettings->numWorkerThreads);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "chiOverrideEnable (0xDFF77545) = %d", m_pStaticSettings->chiOverrideEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraEnable (0x2CB67083) = %d", m_pStaticSettings->multiCameraEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraJPEG (0x598CD51A) = %d", m_pStaticSettings->multiCameraJPEG);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraEnableFront (0x0001DD55) = %d", m_pStaticSettings->multiCameraEnableFront);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraVREnable (0xD1049DC8) = %d", m_pStaticSettings->multiCameraVREnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraHWSyncMask (0xCC6478FA) = %d", m_pStaticSettings->multiCameraHWSyncMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCameraFrameSync (0x26DB7C18) = %d", m_pStaticSettings->multiCameraFrameSync);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSensorFpsMatch (0xB261B4B7) = %d", m_pStaticSettings->enableSensorFpsMatch);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "multiCamera3ASync (0x804F1CC5) = %d", m_pStaticSettings->multiCamera3ASync);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numberOfAELockFrames (0x83C9E0BF) = %d", m_pStaticSettings->numberOfAELockFrames);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "exportSecureCamera (0xF4E4978B) = %d", m_pStaticSettings->exportSecureCamera);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableRAWProcessing (0x85F8530B) = %d", m_pStaticSettings->enableRAWProcessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxRAWSizes (0xA8BD3F5B) = %d", m_pStaticSettings->maxRAWSizes);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableInternalHALPixelStreamConfig (0x07BEC896) = %d", m_pStaticSettings->enableInternalHALPixelStreamConfig);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableNCSService (0x1A803BC5) = %d", m_pStaticSettings->enableNCSService);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "minReprocessInputWidth (0x03D704D3) = %d", m_pStaticSettings->minReprocessInputWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "minReprocessInputHeight (0x44265614) = %d", m_pStaticSettings->minReprocessInputHeight);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "minInOutResolution (0xD9FFE597) = %d", m_pStaticSettings->minInOutResolution);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxInOutResolution (0xD9F75597) = %d", m_pStaticSettings->maxInOutResolution);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTOFInterface (0xAA6F3236) = %d", m_pStaticSettings->enableTOFInterface);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableThermalMitigation (0xD5D8A0B6) = %d", m_pStaticSettings->enableThermalMitigation);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxBuffersSecureCamera (0x0EFAF926) = %d", m_pStaticSettings->maxBuffersSecureCamera);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableNativeHEIF (0xBDFF08B8) = %d", m_pStaticSettings->enableNativeHEIF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableHALFormatOverride (0x3972766A) = %d", m_pStaticSettings->enableHALFormatOverride);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxNumberOfAcceptedErrors (0xA7C57F21) = %d", m_pStaticSettings->maxNumberOfAcceptedErrors);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableResourceManager (0x0AA402CA) = %d", m_pStaticSettings->enableResourceManager);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableStreamCropZoom (0x15E5861B) = %d", m_pStaticSettings->enableStreamCropZoom);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "bpsRealtimeSensorId (0xE6DF0A40) = %d", m_pStaticSettings->bpsRealtimeSensorId);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableBLMClient (0xA049C155) = %d", m_pStaticSettings->enableBLMClient);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "assertMask (0xA37B5A8A) = %d", m_pStaticSettings->assertMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logWarningMask (0x58175BBF) = %d", m_pStaticSettings->logWarningMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logEntryExitMask (0xB3AA4B35) = %d", m_pStaticSettings->logEntryExitMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logConfigMask (0xA2570664) = %d", m_pStaticSettings->logConfigMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logDumpMask (0x9C8A8E36) = %d", m_pStaticSettings->logDumpMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logInfoMask (0x4B7A8E58) = %d", m_pStaticSettings->logInfoMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logPerfInfoMask (0x035D3480) = %d", m_pStaticSettings->logPerfInfoMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logVerboseMask (0xE233DBDE) = %d", m_pStaticSettings->logVerboseMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logDRQEnable (0xBB618269) = %d", m_pStaticSettings->logDRQEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logMetaEnable (0x7AC0C35B) = %d", m_pStaticSettings->logMetaEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "logRequestMapping (0xEC0E183E) = %d", m_pStaticSettings->logRequestMapping);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "traceErrorEnable (0x4FC888C5) = %d", m_pStaticSettings->traceErrorEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "systemLogEnable (0x0748D6B1) = %d", m_pStaticSettings->systemLogEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePipelineFlush (0xE0B91E97) = %d", m_pStaticSettings->enablePipelineFlush);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugLogFilename (0xFC58346C) = %s", m_pStaticSettings->debugLogFilename);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "traceGroupsEnable (0x6EE31BF9) = %d", m_pStaticSettings->traceGroupsEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFPSLog (0xB80C7CFE) = %d", m_pStaticSettings->enableFPSLog);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxMemSpyStats (0xD8B344AB) = %d", m_pStaticSettings->maxMemSpyStats);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "memSpyRequestRate (0x9C526BF5) = %d", m_pStaticSettings->memSpyRequestRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dynamicPropertiesEnabled (0xD9D0EB44) = %d", m_pStaticSettings->dynamicPropertiesEnabled);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "pDebugProcess (0xD1582C30) = %s", m_pStaticSettings->pDebugProcess);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "CSLMode (0x20F730FD) = %d", m_pStaticSettings->CSLMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSensorEmulation (0xCE36BD91) = %d", m_pStaticSettings->enableSensorEmulation);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableExternalSensorModule (0x072CBCAA) = %d", m_pStaticSettings->enableExternalSensorModule);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableDebugSensorExposure (0xFAA0F8C0) = %d", m_pStaticSettings->enableDebugSensorExposure);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sensorExposureTime (0xBF03A959) = %d", m_pStaticSettings->sensorExposureTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gain (0x0032094E) = %f", m_pStaticSettings->gain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sensorShortExposureTime (0xE32992BB) = %d", m_pStaticSettings->sensorShortExposureTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "shortGain (0x23727915) = %f", m_pStaticSettings->shortGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sensorMiddleExposureTime (0x874E6798) = %d", m_pStaticSettings->sensorMiddleExposureTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "middleGain (0xDE6FC377) = %f", m_pStaticSettings->middleGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpSensorEmulationOutput (0x6F5E0A29) = %d", m_pStaticSettings->dumpSensorEmulationOutput);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sensorEmulator (0xCA30CC41) = %s", m_pStaticSettings->sensorEmulator);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sensorEmulatorPath (0xC42529E4) = %s", m_pStaticSettings->sensorEmulatorPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualLEDCalibrationMode (0x5037E53A) = %d", m_pStaticSettings->dualLEDCalibrationMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dynamicInlineCalibration (0x9A1F172D) = %d", m_pStaticSettings->dynamicInlineCalibration);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dynamicCalibrationMaxSize (0xF3345928) = %d", m_pStaticSettings->dynamicCalibrationMaxSize);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualLEDCalibrationPath (0x50395F37) = %s", m_pStaticSettings->dualLEDCalibrationPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableADRC (0x5FFC4E33) = %d", m_pStaticSettings->disableADRC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePreviewManualISO (0x3CC26D50) = %d", m_pStaticSettings->disablePreviewManualISO);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePreviewManualExpTime (0xC2C865E0) = %d", m_pStaticSettings->disablePreviewManualExpTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePreviewManualFull (0x984A320B) = %d", m_pStaticSettings->disablePreviewManualFull);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableSpeckleDetection (0xCDC83F76) = %d", m_pStaticSettings->disableSpeckleDetection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAFStatsProcessing (0x9932D4C9) = %d", m_pStaticSettings->disableAFStatsProcessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAFAlgoCHIOverload (0xB4EE529F) = %d", m_pStaticSettings->disableAFAlgoCHIOverload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAWBStatsProcessing (0xD9CA50FE) = %d", m_pStaticSettings->disableAWBStatsProcessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAWBAlgoCHIOverload (0xF416D6A8) = %d", m_pStaticSettings->disableAWBAlgoCHIOverload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAFDStatsProcessing (0xD9DB60FE) = %d", m_pStaticSettings->disableAFDStatsProcessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAFDAlgoCHIOverload (0xF407E6A8) = %d", m_pStaticSettings->disableAFDAlgoCHIOverload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableASDStatsProcessing (0xD9CE60FE) = %d", m_pStaticSettings->disableASDStatsProcessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableASDAlgoCHIOverload (0xF412E6A8) = %d", m_pStaticSettings->disableASDAlgoCHIOverload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugBufferRegDumpEnable (0xDA3D5950) = %d", m_pStaticSettings->debugBufferRegDumpEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugBufferRegDumpSizeInBytes (0xF1F1DD58) = %d", m_pStaticSettings->debugBufferRegDumpSizeInBytes);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugBufferRegDumpFileNamePrefix (0xECD602F5) = %s", m_pStaticSettings->debugBufferRegDumpFileNamePrefix);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpIPEFirmwarePayload (0x9FA41F42) = %d", m_pStaticSettings->dumpIPEFirmwarePayload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "kpiDebug (0xD4730583) = %d", m_pStaticSettings->kpiDebug);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableQTimer (0x964179AB) = %d", m_pStaticSettings->enableQTimer);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTPG (0x82F3380F) = %d", m_pStaticSettings->enableTPG);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCSIDBinning (0xA7B2CB1D) = %d", m_pStaticSettings->enableCSIDBinning);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "CSIDBinningMode (0x39C265AF) = %d", m_pStaticSettings->CSIDBinningMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "force3ALockedResult (0x504950E4) = %d", m_pStaticSettings->force3ALockedResult);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceDisableUBWCOnIfeIpeLink (0x8585BB42) = %d", m_pStaticSettings->forceDisableUBWCOnIfeIpeLink);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableUBWCNV124ROnIFEFullOutIPELink (0x7600C890) = %d", m_pStaticSettings->enableUBWCNV124ROnIFEFullOutIPELink);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "capResolutionForSingleIFE (0xCBA34006) = %d", m_pStaticSettings->capResolutionForSingleIFE);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "singleIFESupportedWidth (0xDA5EB222) = %d", m_pStaticSettings->singleIFESupportedWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "singleIFESupportedHeight (0x7510882F) = %d", m_pStaticSettings->singleIFESupportedHeight);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFlashDebug (0x01E89A97) = %d", m_pStaticSettings->enableFlashDebug);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpSensorEEPROMData (0x8774CDD5) = %d", m_pStaticSettings->dumpSensorEEPROMData);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDump (0xA33E53A6) = %d", m_pStaticSettings->autoImageDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpInputatOutput (0x7FC2AA67) = %d", m_pStaticSettings->dumpInputatOutput);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoInputImageDumpMask (0x8B72D4F3) = %d", m_pStaticSettings->autoInputImageDumpMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFERegDumpMask (0xCE73CEE2) = %d", m_pStaticSettings->IFERegDumpMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpMask (0x3A5D39EE) = %d", m_pStaticSettings->autoImageDumpMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIFEoutputPortMask (0x3C0793C3) = %d", m_pStaticSettings->autoImageDumpIFEoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIFEinputPortMask (0xD61C2FE2) = %d", m_pStaticSettings->autoImageDumpIFEinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIFEoutputBatchNum (0xB1752F96) = %d", m_pStaticSettings->autoImageDumpIFEoutputBatchNum);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIFEInstanceMask (0xD7CC328B) = %d", m_pStaticSettings->autoImageDumpIFEInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIPEoutputPortMask (0x3C0723C3) = %d", m_pStaticSettings->autoImageDumpIPEoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIPEinputPortMask (0xD61C2A62) = %d", m_pStaticSettings->autoImageDumpIPEinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpIPEInstanceMask (0xD7CC32A7) = %d", m_pStaticSettings->autoImageDumpIPEInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpBPSoutputPortMask (0x3C0C2643) = %d", m_pStaticSettings->autoImageDumpBPSoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpBPSinputPortMask (0xD61C724E) = %d", m_pStaticSettings->autoImageDumpBPSinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpBPSInstanceMask (0xB7CC3066) = %d", m_pStaticSettings->autoImageDumpBPSInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpJpegHwoutputPortMask (0xB798BAD7) = %d", m_pStaticSettings->autoImageDumpJpegHwoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpJpegHwinputPortMask (0x7240D6AA) = %d", m_pStaticSettings->autoImageDumpJpegHwinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpJpegHwInstanceMask (0x92EED541) = %d", m_pStaticSettings->autoImageDumpJpegHwInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpFDHwoutputPortMask (0xDE9279C7) = %d", m_pStaticSettings->autoImageDumpFDHwoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpFDHwinputPortMask (0xF10880B2) = %d", m_pStaticSettings->autoImageDumpFDHwinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpFDHwInstanceMask (0x56F497F1) = %d", m_pStaticSettings->autoImageDumpFDHwInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpLRMEoutputPortMask (0xDFC45547) = %d", m_pStaticSettings->autoImageDumpLRMEoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpLRMEinputPortMask (0xF10231D6) = %d", m_pStaticSettings->autoImageDumpLRMEinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpLRMEInstanceMask (0x76F4C27A) = %d", m_pStaticSettings->autoImageDumpLRMEInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpRANSACoutputPortMask (0xF2ECF7DB) = %d", m_pStaticSettings->autoImageDumpRANSACoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpRANSACinputPortMask (0x106B74C2) = %d", m_pStaticSettings->autoImageDumpRANSACinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpRANSACInstanceMask (0xD1FF8852) = %d", m_pStaticSettings->autoImageDumpRANSACInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCHINodeoutputPortMask (0x9DB2AF4A) = %d", m_pStaticSettings->autoImageDumpCHINodeoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCHINodeinputPortMask (0x9B118606) = %d", m_pStaticSettings->autoImageDumpCHINodeinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCHINodeInstanceMask (0xF5A45FC4) = %d", m_pStaticSettings->autoImageDumpCHINodeInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCVPoutputPortMask (0x3C0D1683) = %d", m_pStaticSettings->autoImageDumpCVPoutputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCVPinputPortMask (0xD61C7BC8) = %d", m_pStaticSettings->autoImageDumpCVPinputPortMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "autoImageDumpCVPInstanceMask (0x87CC302A) = %d", m_pStaticSettings->autoImageDumpCVPInstanceMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dynamicImageDump (0xAF48ED3A) = %d", m_pStaticSettings->dynamicImageDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dynamicImageDumpTrigger (0x98E5791A) = %d", m_pStaticSettings->dynamicImageDumpTrigger);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "watermarkImage (0x7B3D2679) = %d", m_pStaticSettings->watermarkImage);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "watermarkOffset (0x6B171F5B) = %s", m_pStaticSettings->watermarkOffset);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "reprocessDump (0xB24DF5D6) = %d", m_pStaticSettings->reprocessDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "offlineImageDumpOnly (0x2E91E0BE) = %d", m_pStaticSettings->offlineImageDumpOnly);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEHangDump (0x690FD70A) = %d", m_pStaticSettings->enableIPEHangDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableBPSHangDump (0x6923C10A) = %d", m_pStaticSettings->enableBPSHangDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEStripeDump (0x965BC597) = %d", m_pStaticSettings->enableIPEStripeDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableBPSStripeDump (0x2603C597) = %d", m_pStaticSettings->enableBPSStripeDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEScratchBufferDump (0xBCFFB5D5) = %d", m_pStaticSettings->enableIPEScratchBufferDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceMaxFPS (0x9DB80772) = %d", m_pStaticSettings->forceMaxFPS);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "kickTheMachine (0x24274246) = %d", m_pStaticSettings->kickTheMachine);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "perFrameSensorMode (0x306BBFEB) = %d", m_pStaticSettings->perFrameSensorMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePDAF (0x5FF4CC56) = %d", m_pStaticSettings->disablePDAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTouchToTrack (0xBE075808) = %d", m_pStaticSettings->enableTouchToTrack);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "touchToTrackDownscaleRatio (0xB5B5482A) = %d", m_pStaticSettings->touchToTrackDownscaleRatio);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "touchToTrackSCVEOperationMode (0x5BE14E5A) = %d", m_pStaticSettings->touchToTrackSCVEOperationMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "touchToTrackSCVEPrecisionMode (0xAAE36663) = %d", m_pStaticSettings->touchToTrackSCVEPrecisionMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "t2tConfidenceThreshold (0xAA08A72D) = %d", m_pStaticSettings->t2tConfidenceThreshold);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "defaultMaxFPS (0xAF39C008) = %d", m_pStaticSettings->defaultMaxFPS);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "bypassIPEICADependency (0xB06B45E5) = %d", m_pStaticSettings->bypassIPEICADependency);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableDRQPreemptionOnStopRecord (0xD0A91874) = %d", m_pStaticSettings->disableDRQPreemptionOnStopRecord);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableVideoPerfModeSetting (0xE73415A9) = %d", m_pStaticSettings->disableVideoPerfModeSetting);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSensorAcquireOptimization (0x95DEB12A) = %d", m_pStaticSettings->enableSensorAcquireOptimization);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "camVersionOverride (0x593350CD) = %d", m_pStaticSettings->camVersionOverride);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideOPPCLOCK (0xFEAC3322) = %d", m_pStaticSettings->overrideOPPCLOCK);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpGeolibResult (0x5072EB39) = %d", m_pStaticSettings->dumpGeolibResult);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpCVPICAInputConfig (0xFB8F8C5D) = %d", m_pStaticSettings->dumpCVPICAInputConfig);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "tfTestMode (0xA179D55C) = %d", m_pStaticSettings->tfTestMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableHJAF (0x5E696956) = %d", m_pStaticSettings->enableHJAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSPD (0x82F3240C) = %d", m_pStaticSettings->enableSPD);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "spdStatsType (0x97471ADD) = %d", m_pStaticSettings->spdStatsType);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableFocusIndication (0x83451B44) = %d", m_pStaticSettings->disableFocusIndication);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "spotlightFallbackToCAF (0x1DA1228E) = %d", m_pStaticSettings->spotlightFallbackToCAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "afLog (0x0622BD87) = %d", m_pStaticSettings->afLog);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "fovcEnable (0x0CDDA94D) = %d", m_pStaticSettings->fovcEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gyroDataReportRate (0x04682770) = %d", m_pStaticSettings->gyroDataReportRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gyroSensorSamplingRate (0x3047FC2E) = %f", m_pStaticSettings->gyroSensorSamplingRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gravityDataReportRate (0x825814B8) = %d", m_pStaticSettings->gravityDataReportRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gravitySensorSamplingRate (0x0CCF9F2D) = %f", m_pStaticSettings->gravitySensorSamplingRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "TOFDataReportRate (0x0885CD30) = %d", m_pStaticSettings->TOFDataReportRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "TOFSensorSamplingRate (0x944732F0) = %f", m_pStaticSettings->TOFSensorSamplingRate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customTOFSensorLib (0x876E88A9) = %s", m_pStaticSettings->customTOFSensorLib);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "mwEnable (0x0CD10690) = %d", m_pStaticSettings->mwEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableAFAlgo (0xB7657DF6) = %d", m_pStaticSettings->enableAFAlgo);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "afFullsweep (0xDE82BD63) = %d", m_pStaticSettings->afFullsweep);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "manualAf (0x9B613F36) = %d", m_pStaticSettings->manualAf);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "lensPos (0xCCD84D88) = %d", m_pStaticSettings->lensPos);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "vmDebugMask (0x6D92CD3B) = %s", m_pStaticSettings->vmDebugMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "AFRecorderMode (0x958F3CA8) = %d", m_pStaticSettings->AFRecorderMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableLensSagComp (0xF71A94D6) = %d", m_pStaticSettings->enableLensSagComp);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "activeNodeMask (0x05CDACA4) = %s", m_pStaticSettings->activeNodeMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "apiMask (0xA6A70A13) = %d", m_pStaticSettings->apiMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "manualExposureType (0x5CC7EB64) = %d", m_pStaticSettings->manualExposureType);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualBHistSupport (0xDD97DF0C) = %d", m_pStaticSettings->dualBHistSupport);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableBGStatsForAF (0x1D94430C) = %d", m_pStaticSettings->disableBGStatsForAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomAlgoAEC (0x0CA6EF7E) = %d", m_pStaticSettings->enableCustomAlgoAEC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableAFAWBpreFlash (0xC4DF006B) = %d", m_pStaticSettings->disableAFAWBpreFlash);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "yuvPlaneAlignment (0x79996EA8) = %d", m_pStaticSettings->yuvPlaneAlignment);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "preFlashMaxFrameWaitLimitAF (0xA9C5FE72) = %d", m_pStaticSettings->preFlashMaxFrameWaitLimitAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "preFlashMaxFrameWaitLimitAWB (0x38BFCC17) = %d", m_pStaticSettings->preFlashMaxFrameWaitLimitAWB);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePreFlashOnForTouchAE (0xFB81A79C) = %d", m_pStaticSettings->disablePreFlashOnForTouchAE);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numberOfFramesToSkip (0xA5CD5B0A) = %d", m_pStaticSettings->numberOfFramesToSkip);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAECName (0x4B6FD98B) = %s", m_pStaticSettings->customAlgoAECName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAECPath (0x4B60DAA6) = %s", m_pStaticSettings->customAlgoAECPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomAlgoAWB (0x0CA6ED3F) = %d", m_pStaticSettings->enableCustomAlgoAWB);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAWBName (0x6F7FD98B) = %s", m_pStaticSettings->customAlgoAWBName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAWBPath (0x6F70DAA6) = %s", m_pStaticSettings->customAlgoAWBPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomAlgoAF (0xE865377B) = %d", m_pStaticSettings->enableCustomAlgoAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAFName (0x726DC347) = %s", m_pStaticSettings->customAlgoAFName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAFPath (0x7262C06A) = %s", m_pStaticSettings->customAlgoAFPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomHAFAlgo (0x56B1DB30) = %d", m_pStaticSettings->enableCustomHAFAlgo);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customHAFAlgoName (0x0F8A78F8) = %s", m_pStaticSettings->customHAFAlgoName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customHAFAlgoPath (0x0F857BD5) = %s", m_pStaticSettings->customHAFAlgoPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideHAFAlgoMask (0x094DC34D) = %d", m_pStaticSettings->overrideHAFAlgoMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "exposureGain (0x910C65CB) = %f", m_pStaticSettings->exposureGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "exposureTime (0x9105C540) = %d", m_pStaticSettings->exposureTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "luxIndex (0xB6A69FA5) = %f", m_pStaticSettings->luxIndex);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "extendedTimeForLongExposure (0x5B0480B2) = %d", m_pStaticSettings->extendedTimeForLongExposure);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "manualWhiteBalanceType (0xEB20DB85) = %d", m_pStaticSettings->manualWhiteBalanceType);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "rGain (0x0712094E) = %f", m_pStaticSettings->rGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "gGain (0x0642094E) = %f", m_pStaticSettings->gGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "BGain (0x0612094E) = %f", m_pStaticSettings->BGain);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "colorTemp (0xD91BF9B3) = %d", m_pStaticSettings->colorTemp);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ignoreSceneMode (0x4C23FA6C) = %d", m_pStaticSettings->ignoreSceneMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomAlgoASD (0x0CA6EDB9) = %d", m_pStaticSettings->enableCustomAlgoASD);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoASDName (0x671FD98B) = %s", m_pStaticSettings->customAlgoASDName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoASDPath (0x6710DAA6) = %s", m_pStaticSettings->customAlgoASDPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomAlgoAFD (0x0CA6EF19) = %d", m_pStaticSettings->enableCustomAlgoAFD);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAFDName (0x4D1FD98B) = %s", m_pStaticSettings->customAlgoAFDName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customAlgoAFDPath (0x4D10DAA6) = %s", m_pStaticSettings->customAlgoAFDPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableDualIFE (0x8AAF8792) = %d", m_pStaticSettings->enableDualIFE);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceDualIFEOn (0x56225EF4) = %d", m_pStaticSettings->forceDualIFEOn);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualIFESplitPointOffset (0xDB202240) = %d", m_pStaticSettings->dualIFESplitPointOffset);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualIFELeftPadding (0x9BB97FCF) = %d", m_pStaticSettings->dualIFELeftPadding);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dualIFERightPadding (0x32195890) = %d", m_pStaticSettings->dualIFERightPadding);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFETestImageSizeWidth (0x36B34DC8) = %d", m_pStaticSettings->IFETestImageSizeWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFETestImageSizeHeight (0xE8AF7572) = %d", m_pStaticSettings->IFETestImageSizeHeight);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IsOEMStatSettingEnable (0x165F8225) = %d", m_pStaticSettings->IsOEMStatSettingEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "DisableManual3ACCM (0x64D3CD3F) = %d", m_pStaticSettings->DisableManual3ACCM);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFENumFramesHighBW (0xF923516F) = %d", m_pStaticSettings->IFENumFramesHighBW);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "pdafHWEnable (0x354D40B8) = %d", m_pStaticSettings->pdafHWEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIFERegDump (0x5BD9AFA0) = %d", m_pStaticSettings->enableIFERegDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableActiveIFEABVote (0x79614E2B) = %d", m_pStaticSettings->enableActiveIFEABVote);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEDynamicEnableMask (0xAFA0146A) = %d", m_pStaticSettings->IFEDynamicEnableMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ifeClockFrequencyMHz (0x0C0990FE) = %d", m_pStaticSettings->ifeClockFrequencyMHz);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ifeCamnocBandwidthMBytes (0x3531572C) = %d", m_pStaticSettings->ifeCamnocBandwidthMBytes);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ifeExternalBandwidthMBytes (0x0F5FD453) = %d", m_pStaticSettings->ifeExternalBandwidthMBytes);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableHVXStreaming (0x253D4945) = %d", m_pStaticSettings->enableHVXStreaming);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEIQModulesMask (0x61D815A5) = %d", m_pStaticSettings->enableIPEIQModulesMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEUpscale (0xB09A6994) = %d", m_pStaticSettings->enableIPEUpscale);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEOnlyDownscale (0xD859D69D) = %d", m_pStaticSettings->enableIPEOnlyDownscale);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableIPEInternalDownscale (0x1153DCB5) = %d", m_pStaticSettings->disableIPEInternalDownscale);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEDependencies (0x27657A7A) = %d", m_pStaticSettings->enableIPEDependencies);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIPEIQLogging (0xB1C3F36A) = %d", m_pStaticSettings->enableIPEIQLogging);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableMCTF (0x5E6BCFF6) = %d", m_pStaticSettings->enableMCTF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableCVPDriver (0xEFAAAEDE) = %d", m_pStaticSettings->disableCVPDriver);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numIPECoresToUse (0x08ED3B10) = %d", m_pStaticSettings->numIPECoresToUse);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "force8BitUBWCAlignment (0x689CDBA9) = %d", m_pStaticSettings->force8BitUBWCAlignment);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "setLRMETransformTypeMask (0x1F8302D6) = %d", m_pStaticSettings->setLRMETransformTypeMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "isGridFromChromatixEnabled (0xC8800080) = %d", m_pStaticSettings->isGridFromChromatixEnabled);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "alignmentFusionMode (0x77E1A53A) = %d", m_pStaticSettings->alignmentFusionMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "isFirstFrameLoopbackInputImageEnabled (0xA212B660) = %d", m_pStaticSettings->isFirstFrameLoopbackInputImageEnabled);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableLDC (0x82F35A8B) = %d", m_pStaticSettings->enableLDC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugDataHeaderString (0x4224D04E) = %s", m_pStaticSettings->debugDataHeaderString);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enable3ADebugData (0x9E65A553) = %d", m_pStaticSettings->enable3ADebugData);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugDataSizeAEC (0x778C6654) = %d", m_pStaticSettings->debugDataSizeAEC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugDataSizeAWB (0x778C6415) = %d", m_pStaticSettings->debugDataSizeAWB);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugDataSizeAF (0xBBBC6332) = %d", m_pStaticSettings->debugDataSizeAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTuningMetadata (0xFCCB570C) = %d", m_pStaticSettings->enableTuningMetadata);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "tuningDumpDataSizeIFE (0xC9425926) = %d", m_pStaticSettings->tuningDumpDataSizeIFE);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "tuningDumpDataSizeIPE (0xC9425BE6) = %d", m_pStaticSettings->tuningDumpDataSizeIPE);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "tuningDumpDataSizeBPS (0xC94277F0) = %d", m_pStaticSettings->tuningDumpDataSizeBPS);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpDebugDataEveryProcessResult (0x4A508CB2) = %d", m_pStaticSettings->dumpDebugDataEveryProcessResult);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "debugDataOfflineAlloc (0x6CF72C0D) = %d", m_pStaticSettings->debugDataOfflineAlloc);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePDLibCHIOverload (0xE86996FE) = %d", m_pStaticSettings->disablePDLibCHIOverload);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCustomPDLib (0xEE57057B) = %d", m_pStaticSettings->enableCustomPDLib);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customPDLibName (0xDFA742D3) = %s", m_pStaticSettings->customPDLibName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "customPDLibPath (0xDFA841FE) = %s", m_pStaticSettings->customPDLibPath);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "tintlessEnable (0xAA0CE38F) = %d", m_pStaticSettings->tintlessEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePDLibLog (0x0FA55BD2) = %d", m_pStaticSettings->enablePDLibLog);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePDLibTestMode (0x0B687A90) = %d", m_pStaticSettings->enablePDLibTestMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePDLibProfiling (0x494EE3B9) = %d", m_pStaticSettings->enablePDLibProfiling);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePDLibDump (0xF4AF1371) = %d", m_pStaticSettings->enablePDLibDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePDLibLCR (0xDFA5435E) = %d", m_pStaticSettings->disablePDLibLCR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ifeSWCDMEnable (0xDF93850A) = %d", m_pStaticSettings->ifeSWCDMEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableAEScan (0xB75C4137) = %d", m_pStaticSettings->enableAEScan);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideLogLevels (0x0B1AFF31) = %d", m_pStaticSettings->overrideLogLevels);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideDisableZSL (0x2CFEB8EE) = %d", m_pStaticSettings->overrideDisableZSL);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableLRMEDS2 (0x846B3167) = %d", m_pStaticSettings->enableLRMEDS2);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideEnableMFNR (0xF06AECC0) = %d", m_pStaticSettings->overrideEnableMFNR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "anchorSelectionAlgoForMFNR (0xCB7A2D13) = %d", m_pStaticSettings->anchorSelectionAlgoForMFNR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "anchorAlgoSelectionType (0x29DDC9C3) = %d", m_pStaticSettings->anchorAlgoSelectionType);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "advanceFeatureMask (0xAD34602C) = %d", m_pStaticSettings->advanceFeatureMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableOfflineNoiseReprocess (0x10616FE6) = %d", m_pStaticSettings->enableOfflineNoiseReprocess);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableGamma15PreCalculate (0xDE85B824) = %d", m_pStaticSettings->enableGamma15PreCalculate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideForceUsecaseId (0x0E822F1C) = %d", m_pStaticSettings->overrideForceUsecaseId);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideForceSensorMode (0xCC512DB8) = %d", m_pStaticSettings->overrideForceSensorMode);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideForceFSCapable (0x8B9B20BC) = %d", m_pStaticSettings->overrideForceFSCapable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideGPURotationUsecase (0xDC9A909F) = %d", m_pStaticSettings->overrideGPURotationUsecase);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideGPUDownscaleUsecase (0xCC9A2BD9) = %d", m_pStaticSettings->overrideGPUDownscaleUsecase);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideHFRNo3AUseCase (0xBEFF3AD5) = %d", m_pStaticSettings->overrideHFRNo3AUseCase);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideCameraClose (0x85A17064) = %d", m_pStaticSettings->overrideCameraClose);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideCameraOpen (0x0C2B7ADD) = %d", m_pStaticSettings->overrideCameraOpen);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overridePDLibClose (0x2C08E11D) = %d", m_pStaticSettings->overridePDLibClose);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overridePDLibOpen (0xC1663656) = %d", m_pStaticSettings->overridePDLibOpen);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV2Enable (0x4D485559) = %d", m_pStaticSettings->EISV2Enable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV3Enable (0x0D485559) = %d", m_pStaticSettings->EISV3Enable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV2Margin (0x5DB1C1F2) = %f", m_pStaticSettings->EISV2Margin);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV2FrameDelay (0x87B794DF) = %d", m_pStaticSettings->EISV2FrameDelay);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV3Margin (0x1DB1C1F2) = %f", m_pStaticSettings->EISV3Margin);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "EISV3FrameDelay (0x87B394DF) = %d", m_pStaticSettings->EISV3FrameDelay);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numPCRsBeforeStreamOn (0xBAB395D2) = %d", m_pStaticSettings->numPCRsBeforeStreamOn);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxImageBufferTimeoutCount (0x6F432AB3) = %d", m_pStaticSettings->maxImageBufferTimeoutCount);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "imageBufferWaitTime (0x5E2D59E7) = %d", m_pStaticSettings->imageBufferWaitTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideMaxImageBufferCountRealTime (0x53617233) = %d", m_pStaticSettings->overrideMaxImageBufferCountRealTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "overrideMaxImageBufferCountNonRealTime (0xE971CF81) = %d", m_pStaticSettings->overrideMaxImageBufferCountNonRealTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "statsProcessingSkipFactor (0xD98ACEEF) = %d", m_pStaticSettings->statsProcessingSkipFactor);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "maxNonHfrFps (0x6153FB10) = %d", m_pStaticSettings->maxNonHfrFps);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "minFrameRateBound (0xDD40DBFA) = %d", m_pStaticSettings->minFrameRateBound);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableOISOptimization (0x3C4A768F) = %d", m_pStaticSettings->enableOISOptimization);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSensorCaching (0x9E91AEE3) = %d", m_pStaticSettings->enableSensorCaching);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceDebugQCFASWRemosaic (0x81A88EED) = %d", m_pStaticSettings->forceDebugQCFASWRemosaic);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCHIPartialData (0x05FEA2E8) = %d", m_pStaticSettings->enableCHIPartialData);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCHIPartialDataRecovery (0x7E6871B5) = %d", m_pStaticSettings->enableCHIPartialDataRecovery);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpMetadata (0x9DFA5990) = %d", m_pStaticSettings->dumpMetadata);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "memsetInputMeta (0x056DEB01) = %d", m_pStaticSettings->memsetInputMeta);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableLinearMetaLUT (0xE1E7F792) = %d", m_pStaticSettings->enableLinearMetaLUT);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFDStreamInRealTime (0x7E5625B9) = %d", m_pStaticSettings->enableFDStreamInRealTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "selectInSensorHDR3ExpUsecase (0x2615590F) = %d", m_pStaticSettings->selectInSensorHDR3ExpUsecase);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableUnifiedBufferManager (0x6790B9B0) = %d", m_pStaticSettings->enableUnifiedBufferManager);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCHIImageBufferLateBinding (0xF56EFB80) = %d", m_pStaticSettings->enableCHIImageBufferLateBinding);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFeature2Dump (0x27469E3A) = %d", m_pStaticSettings->enableFeature2Dump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceHWMFFixedNumOfFrames (0x9C069C61) = %d", m_pStaticSettings->forceHWMFFixedNumOfFrames);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTBMChiFence (0x27697285) = %d", m_pStaticSettings->enableTBMChiFence);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableMFSRChiFence (0xBF883559) = %d", m_pStaticSettings->enableMFSRChiFence);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableRawHDR (0x911E6D8B) = %d", m_pStaticSettings->enableRawHDR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDProcessingControl (0xE46903AD) = %d", m_pStaticSettings->FDProcessingControl);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFDManagerThreading (0xF5ADAA76) = %d", m_pStaticSettings->enableFDManagerThreading);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDBaseResolution (0x3772A6CF) = %d", m_pStaticSettings->FDBaseResolution);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDConfigSource (0x50FAE19E) = %d", m_pStaticSettings->FDConfigSource);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDMultiCamProcess (0x190D23CB) = %d", m_pStaticSettings->FDMultiCamProcess);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useAlternateFrameSkip (0x557B5A12) = %d", m_pStaticSettings->useAlternateFrameSkip);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useDeviceOrientationInFD (0x6D17E94F) = %d", m_pStaticSettings->useDeviceOrientationInFD);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "getAccelInfoUsingVendorTag (0xF009E256) = %d", m_pStaticSettings->getAccelInfoUsingVendorTag);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "accelVendorTagSection (0x7A82E410) = %s", m_pStaticSettings->accelVendorTagSection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "accelVendorTagName (0x9B3264D7) = %s", m_pStaticSettings->accelVendorTagName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDFilterEngine (0x3E7BDE5B) = %d", m_pStaticSettings->FDFilterEngine);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDClient (0xC0F51A9D) = %d", m_pStaticSettings->FDClient);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disablePostingResults (0xC5170C04) = %d", m_pStaticSettings->disablePostingResults);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableOfflineFD (0x7E1A4D17) = %d", m_pStaticSettings->enableOfflineFD);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MetadataVisibility (0xA4EBB8F5) = %d", m_pStaticSettings->MetadataVisibility);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useDifferentTuningForFrontCamera (0xC39EB12A) = %d", m_pStaticSettings->useDifferentTuningForFrontCamera);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useFDInternalBuffers (0x5FD202EB) = %d", m_pStaticSettings->useFDInternalBuffers);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useFDUseCasePool (0xF3B00380) = %d", m_pStaticSettings->useFDUseCasePool);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "fastFDMetadata (0x867F2D5A) = %d", m_pStaticSettings->fastFDMetadata);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "minReqFdDependency (0xB525BECD) = %d", m_pStaticSettings->minReqFdDependency);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDPreprocessing (0x35924188) = %d", m_pStaticSettings->FDPreprocessing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFDPreprocessingAlways (0x6B9550A8) = %d", m_pStaticSettings->enableFDPreprocessingAlways);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFDPreprocessDumping (0x88727272) = %d", m_pStaticSettings->enableFDPreprocessDumping);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "acceptAppUIFacialAttrSettings (0xA53740AD) = %d", m_pStaticSettings->acceptAppUIFacialAttrSettings);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enablePTDetection (0x3F232639) = %d", m_pStaticSettings->enablePTDetection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableSMDetection (0x3F2C0639) = %d", m_pStaticSettings->enableSMDetection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableGBDetection (0x3F7DE639) = %d", m_pStaticSettings->enableGBDetection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableCTDetection (0x3F6F2639) = %d", m_pStaticSettings->enableCTDetection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "FDThreadTaskAllocation (0x862D3D60) = %d", m_pStaticSettings->FDThreadTaskAllocation);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableJPEGEXIFApp2 (0xBC509A5A) = %d", m_pStaticSettings->enableJPEGEXIFApp2);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "exposeFullSizeForQCFA (0x63486E91) = %d", m_pStaticSettings->exposeFullSizeForQCFA);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useFeatureForQCFA (0x3831501A) = %d", m_pStaticSettings->useFeatureForQCFA);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "AECGainThresholdForQCFA (0x3861B978) = %f", m_pStaticSettings->AECGainThresholdForQCFA);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableFlash (0xFFFD8803) = %d", m_pStaticSettings->disableFlash);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableWatchdogRecovery (0x80B172CF) = %d", m_pStaticSettings->enableWatchdogRecovery);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "nodeResponseTime (0x08F2D1A8) = %d", m_pStaticSettings->nodeResponseTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionResponseTimePadding (0x057A6840) = %d", m_pStaticSettings->sessionResponseTimePadding);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionMaxFlushWaitTime (0xEB30DFDB) = %d", m_pStaticSettings->sessionMaxFlushWaitTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionFallbackWaitTime (0x4C6284F3) = %d", m_pStaticSettings->sessionFallbackWaitTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "feature1 (0x857B47B8) = %d", m_pStaticSettings->feature1);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "feature2 (0x857B47BB) = %d", m_pStaticSettings->feature2);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "raisesigabrt (0x2CC85600) = %d", m_pStaticSettings->raisesigabrt);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "raiserecoverysigabrt (0x9B45E394) = %d", m_pStaticSettings->raiserecoverysigabrt);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableRecovery (0x51CF7C7C) = %d", m_pStaticSettings->enableRecovery);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableAsciiLogging (0xB5CF33AA) = %d", m_pStaticSettings->enableAsciiLogging);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableBinaryLogging (0x54D473B9) = %d", m_pStaticSettings->enableBinaryLogging);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "offlineLoggerMinFlushCnt (0xB212E762) = %d", m_pStaticSettings->offlineLoggerMinFlushCnt);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableFenceDrop (0x60DF1939) = %d", m_pStaticSettings->enableFenceDrop);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerIsRealTime (0x87D490A0) = %d", m_pStaticSettings->inducerIsRealTime);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerPipelineName (0x2A6B5FB3) = %s", m_pStaticSettings->inducerPipelineName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerNodeName (0x75664234) = %s", m_pStaticSettings->inducerNodeName);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerRequestId (0xCC713F3F) = %d", m_pStaticSettings->inducerRequestId);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerPortId (0xC0561D76) = %d", m_pStaticSettings->inducerPortId);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "inducerFenceMarkError (0xA828396A) = %d", m_pStaticSettings->inducerFenceMarkError);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionDumpForFlush (0x315E8BBA) = %d", m_pStaticSettings->sessionDumpForFlush);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionDumpToLog (0xA2441B95) = %d", m_pStaticSettings->sessionDumpToLog);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionDumpToFile (0x48866BB1) = %d", m_pStaticSettings->sessionDumpToFile);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "sessionDumpForRecovery (0x28138234) = %d", m_pStaticSettings->sessionDumpForRecovery);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpNodeProcessingInfo (0xC1E912ED) = %d", m_pStaticSettings->dumpNodeProcessingInfo);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpSessionProcessingInfo (0xA9FC2049) = %d", m_pStaticSettings->dumpSessionProcessingInfo);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "numberOfCHIThreads (0xCCB173EB) = %d", m_pStaticSettings->numberOfCHIThreads);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useVFETPG (0xAA5328E6) = %d", m_pStaticSettings->useVFETPG);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEBufDoneTimeout (0xB6149662) = %d", m_pStaticSettings->IFEBufDoneTimeout);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEInputWidth (0x0DDC5373) = %d", m_pStaticSettings->IFEInputWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEInputHeight (0x854CA215) = %d", m_pStaticSettings->IFEInputHeight);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEBufDoneTimeout (0xB6142662) = %d", m_pStaticSettings->IPEBufDoneTimeout);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEUnitTestIQBypassNumOfIteration (0x50508738) = %d", m_pStaticSettings->IPEUnitTestIQBypassNumOfIteration);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableImageBufferLateBinding (0x6DD7E808) = %d", m_pStaticSettings->enableImageBufferLateBinding);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMEnable (0x8CD16B7E) = %d", m_pStaticSettings->MPMEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMValidateMemPoolGroup (0xF0A0FFF7) = %d", m_pStaticSettings->MPMValidateMemPoolGroup);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMDoNotGroupBufferManagers (0x04A164F1) = %d", m_pStaticSettings->MPMDoNotGroupBufferManagers);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMKeepMinNumFreeBuffers (0x125E33DB) = %d", m_pStaticSettings->MPMKeepMinNumFreeBuffers);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMAllocateBuffersOnRegister (0x7ED38F5D) = %d", m_pStaticSettings->MPMAllocateBuffersOnRegister);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMGroupIfExactDeviceMatch (0x99499D5A) = %d", m_pStaticSettings->MPMGroupIfExactDeviceMatch);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMMinSizeForSharing (0xF77E567C) = %d", m_pStaticSettings->MPMMinSizeForSharing);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMSizeDiffAllowedToGroup (0xD98BBD05) = %d", m_pStaticSettings->MPMSizeDiffAllowedToGroup);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMLargeGroupSizeDefinition (0x4A6758BD) = %d", m_pStaticSettings->MPMLargeGroupSizeDefinition);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMSizeDiffAllowedToGroupOverride (0xC6A5AE59) = %d", m_pStaticSettings->MPMSizeDiffAllowedToGroupOverride);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMBufferAddressAlignment (0x61DF8963) = %d", m_pStaticSettings->MPMBufferAddressAlignment);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceCHIBufferManagerHeap (0x2D88246B) = %d", m_pStaticSettings->forceCHIBufferManagerHeap);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMSelfTuneImmediateCount (0xD3737A52) = %d", m_pStaticSettings->MPMSelfTuneImmediateCount);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableMPMMonitorThread (0x8D6B772D) = %d", m_pStaticSettings->enableMPMMonitorThread);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMMonitorTimeInterval (0x4C4C9AF1) = %d", m_pStaticSettings->MPMMonitorTimeInterval);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMMonitorSelfShrinkSizeLimit (0x55634264) = %d", m_pStaticSettings->MPMMonitorSelfShrinkSizeLimit);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableMPMStatelogging (0xB8314B54) = %d", m_pStaticSettings->enableMPMStatelogging);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableMemoryStats (0x86552C15) = %d", m_pStaticSettings->enableMemoryStats);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMMinSizeToFreeOnDeactivate (0x1C211758) = %d", m_pStaticSettings->MPMMinSizeToFreeOnDeactivate);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "validateImageBufferUsageState (0x11D9CAE4) = %d", m_pStaticSettings->validateImageBufferUsageState);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMSizeThresToDisableDelayedUnmap (0x8186475D) = %d", m_pStaticSettings->MPMSizeThresToDisableDelayedUnmap);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMForceDisableDelayedUnmap (0x9F846966) = %d", m_pStaticSettings->MPMForceDisableDelayedUnmap);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "MPMSizeThresToDelayedMap (0xD870DF60) = %d", m_pStaticSettings->MPMSizeThresToDelayedMap);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpAF (0xCF674C46) = %d", m_pStaticSettings->dumpAF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpAEC (0xECE988DA) = %d", m_pStaticSettings->dumpAEC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpAWB (0xECE98A9B) = %d", m_pStaticSettings->dumpAWB);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpAFDRowsum (0x99F020E2) = %d", m_pStaticSettings->dumpAFDRowsum);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "profile3A (0x0AA7E18A) = %d", m_pStaticSettings->profile3A);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "================ END DUMP OF CURRENT HARDWARE-INDEPENDENT SETTINGS VALUES ================");

    HwDumpSettings();
}
#endif // SETTINGS_DUMP_ENABLE

CAMX_NAMESPACE_END
