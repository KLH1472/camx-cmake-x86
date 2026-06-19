////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  g_camxsettings.h
/// @brief Hardware Independent Settings definitions.
///
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///             !!!!!!! AUTO-GENERATED FILE! DO NOT EDIT! Make all changes in camxsettings.xml. !!!!!!!
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef G_CAMXSETTINGS_H
#define G_CAMXSETTINGS_H

#include "camxdefs.h"
#include "camxtypes.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constant Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static const UINT32 MaxStringLength                     = 512;          ///< Maximum value string length

// Setting string hash constant definitions
static const UINT32 StringHashOutputFormat              = 0xFC924BE1;   ///< outputFormat
static const UINT32 PropStringHashOutputFormat          = 0xB6A0A247;   ///< outputFormat
static const UINT32 StringHashRefoutputFormatType       = 0x7AE22340;   ///< refoutputFormatType
static const UINT32 PropStringHashRefoutputFormatType   = 0x2B756E72;   ///< refoutputFormatType
static const UINT32 StringHashIsStrideSettingEnable     = 0x4D7EB8E9;   ///< IsStrideSettingEnable
static const UINT32 StringHashNumMetadataResults        = 0x31A11A6A;   ///< numMetadataResults
static const UINT32 PropStringHashNumMetadataResults    = 0xA32DA003;   ///< numMetadataResults
static const UINT32 StringHashMaxHalRequests            = 0x88CF0DA6;   ///< maxHalRequests
static const UINT32 PropStringHashMaxHalRequests        = 0x4369948E;   ///< maxHalRequests
static const UINT32 StringHashWaitAllResultsTimeout     = 0x9658B9F2;   ///< waitAllResultsTimeout
static const UINT32 PropStringHashWaitAllResultsTimeout  = 0xCB6C70B4;   ///< waitAllResultsTimeout
static const UINT32 StringHashNumWorkerThreads          = 0x915563E3;   ///< numWorkerThreads
static const UINT32 PropStringHashNumWorkerThreads      = 0x0B31C0CD;   ///< numWorkerThreads
static const UINT32 StringHashChiOverrideEnable         = 0xDFF77545;   ///< chiOverrideEnable
static const UINT32 PropStringHashChiOverrideEnable     = 0x93631096;   ///< chiOverrideEnable
static const UINT32 StringHashMultiCameraEnable         = 0x2CB67083;   ///< multiCameraEnable
static const UINT32 PropStringHashMultiCameraEnable     = 0xB1EF679B;   ///< multiCameraEnable
static const UINT32 StringHashMultiCameraJPEG           = 0x598CD51A;   ///< multiCameraJPEG
static const UINT32 PropStringHashMultiCameraJPEG       = 0x798FD231;   ///< multiCameraJPEG
static const UINT32 StringHashMultiCameraEnableFront    = 0x0001DD55;   ///< multiCameraEnableFront
static const UINT32 PropStringHashMultiCameraEnableFront  = 0xB6236852;   ///< multiCameraEnableFront
static const UINT32 StringHashMultiCameraVREnable       = 0xD1049DC8;   ///< multiCameraVREnable
static const UINT32 PropStringHashMultiCameraVREnable   = 0xB3CD6E45;   ///< multiCameraVREnable
static const UINT32 StringHashMultiCameraHWSyncMask     = 0xCC6478FA;   ///< multiCameraHWSyncMask
static const UINT32 PropStringHashMultiCameraHWSyncMask  = 0x576A893E;   ///< multiCameraHWSyncMask
static const UINT32 StringHashMultiCameraFrameSync      = 0x26DB7C18;   ///< multiCameraFrameSync
static const UINT32 PropStringHashMultiCameraFrameSync  = 0x02030B96;   ///< multiCameraFrameSync
static const UINT32 StringHashEnableSensorFpsMatch      = 0xB261B4B7;   ///< enableSensorFpsMatch
static const UINT32 PropStringHashEnableSensorFpsMatch  = 0x0C120719;   ///< enableSensorFpsMatch
static const UINT32 StringHashMultiCamera3ASync         = 0x804F1CC5;   ///< multiCamera3ASync
static const UINT32 PropStringHashMultiCamera3ASync     = 0x8C53B045;   ///< multiCamera3ASync
static const UINT32 StringHashNumberOfAELockFrames      = 0x83C9E0BF;   ///< numberOfAELockFrames
static const UINT32 PropStringHashNumberOfAELockFrames  = 0x37F7665E;   ///< numberOfAELockFrames
static const UINT32 StringHashExportSecureCamera        = 0xF4E4978B;   ///< exportSecureCamera
static const UINT32 PropStringHashExportSecureCamera    = 0x66682DE2;   ///< exportSecureCamera
static const UINT32 StringHashEnableRAWProcessing       = 0x85F8530B;   ///< enableRAWProcessing
static const UINT32 PropStringHashEnableRAWProcessing   = 0xD46F1E39;   ///< enableRAWProcessing
static const UINT32 StringHashMaxRAWSizes               = 0xA8BD3F5B;   ///< maxRAWSizes
static const UINT32 PropStringHashMaxRAWSizes           = 0x9AECA816;   ///< maxRAWSizes
static const UINT32 StringHashEnableInternalHALPixelStreamConfig  = 0x07BEC896;   ///< enableInternalHALPixelStreamConfig
static const UINT32 PropStringHashEnableInternalHALPixelStreamConfig  = 0xBDD75A1A;   ///< enableInternalHALPixelStreamConfig
static const UINT32 StringHashEnableNCSService          = 0x1A803BC5;   ///< enableNCSService
static const UINT32 PropStringHashEnableNCSService      = 0x80E498EB;   ///< enableNCSService
static const UINT32 StringHashMinReprocessInputWidth    = 0x03D704D3;   ///< minReprocessInputWidth
static const UINT32 PropStringHashMinReprocessInputWidth  = 0xA54E2C18;   ///< minReprocessInputWidth
static const UINT32 StringHashMinReprocessInputHeight   = 0x44265614;   ///< minReprocessInputHeight
static const UINT32 PropStringHashMinReprocessInputHeight  = 0x97034F60;   ///< minReprocessInputHeight
static const UINT32 StringHashMinInOutResolution        = 0xD9FFE597;   ///< minInOutResolution
static const UINT32 PropStringHashMinInOutResolution    = 0xC246EE0D;   ///< minInOutResolution
static const UINT32 StringHashMaxInOutResolution        = 0xD9F75597;   ///< maxInOutResolution
static const UINT32 PropStringHashMaxInOutResolution    = 0xC24E5E0D;   ///< maxInOutResolution
static const UINT32 StringHashEnableTOFInterface        = 0xAA6F3236;   ///< enableTOFInterface
static const UINT32 PropStringHashEnableTOFInterface    = 0x38E3885F;   ///< enableTOFInterface
static const UINT32 StringHashEnableThermalMitigation   = 0xD5D8A0B6;   ///< enableThermalMitigation
static const UINT32 PropStringHashEnableThermalMitigation  = 0xF6BDA3B6;   ///< enableThermalMitigation
static const UINT32 StringHashMaxBuffersSecureCamera    = 0x0EFAF926;   ///< maxBuffersSecureCamera
static const UINT32 PropStringHashMaxBuffersSecureCamera  = 0xA863D1ED;   ///< maxBuffersSecureCamera
static const UINT32 StringHashEnableNativeHEIF          = 0xBDFF08B8;   ///< enableNativeHEIF
static const UINT32 PropStringHashEnableNativeHEIF      = 0x279BAB96;   ///< enableNativeHEIF
static const UINT32 StringHashEnableHALFormatOverride   = 0x3972766A;   ///< enableHALFormatOverride
static const UINT32 PropStringHashEnableHALFormatOverride  = 0xEA576F1E;   ///< enableHALFormatOverride
static const UINT32 StringHashMaxNumberOfAcceptedErrors  = 0xA7C57F21;   ///< maxNumberOfAcceptedErrors
static const UINT32 PropStringHashMaxNumberOfAcceptedErrors  = 0x33A0AC6D;   ///< maxNumberOfAcceptedErrors
static const UINT32 StringHashEnableResourceManager     = 0x0AA402CA;   ///< enableResourceManager
static const UINT32 PropStringHashEnableResourceManager  = 0x5790CB8C;   ///< enableResourceManager
static const UINT32 StringHashEnableStreamCropZoom      = 0x15E5861B;   ///< enableStreamCropZoom
static const UINT32 PropStringHashEnableStreamCropZoom  = 0x270C2051;   ///< enableStreamCropZoom
static const UINT32 StringHashBpsRealtimeSensorId       = 0xE6DF0A40;   ///< bpsRealtimeSensorId
static const UINT32 PropStringHashBpsRealtimeSensorId   = 0xB7484772;   ///< bpsRealtimeSensorId
static const UINT32 StringHashEnableBLMClient           = 0xA049C155;   ///< enableBLMClient
static const UINT32 PropStringHashEnableBLMClient       = 0xD49AE44C;   ///< enableBLMClient
static const UINT32 StringHashAssertMask                = 0xA37B5A8A;   ///< assertMask
static const UINT32 PropStringHashAssertMask            = 0xCAE9D630;   ///< assertMask
static const UINT32 StringHashLogWarningMask            = 0x58175BBF;   ///< logWarningMask
static const UINT32 PropStringHashLogWarningMask        = 0x93B1C297;   ///< logWarningMask
static const UINT32 StringHashLogEntryExitMask          = 0xB3AA4B35;   ///< logEntryExitMask
static const UINT32 PropStringHashLogEntryExitMask      = 0x29CEE81B;   ///< logEntryExitMask
static const UINT32 StringHashLogConfigMask             = 0xA2570664;   ///< logConfigMask
static const UINT32 PropStringHashLogConfigMask         = 0xE40A32AD;   ///< logConfigMask
static const UINT32 StringHashLogDumpMask               = 0x9C8A8E36;   ///< logDumpMask
static const UINT32 PropStringHashLogDumpMask           = 0xAEDB197B;   ///< logDumpMask
static const UINT32 StringHashLogInfoMask               = 0x4B7A8E58;   ///< logInfoMask
static const UINT32 PropStringHashLogInfoMask           = 0x792B1915;   ///< logInfoMask
static const UINT32 StringHashLogPerfInfoMask           = 0x035D3480;   ///< logPerfInfoMask
static const UINT32 PropStringHashLogPerfInfoMask       = 0x778E1199;   ///< logPerfInfoMask
static const UINT32 StringHashLogVerboseMask            = 0xE233DBDE;   ///< logVerboseMask
static const UINT32 PropStringHashLogVerboseMask        = 0x299542F6;   ///< logVerboseMask
static const UINT32 StringHashLogDRQEnable              = 0xBB618269;   ///< logDRQEnable
static const UINT32 PropStringHashLogDRQEnable          = 0xF1536BCF;   ///< logDRQEnable
static const UINT32 StringHashLogMetaEnable             = 0x7AC0C35B;   ///< logMetaEnable
static const UINT32 PropStringHashLogMetaEnable         = 0x3C9DF792;   ///< logMetaEnable
static const UINT32 StringHashLogRequestMapping         = 0xEC0E183E;   ///< logRequestMapping
static const UINT32 PropStringHashLogRequestMapping     = 0xA09A7DED;   ///< logRequestMapping
static const UINT32 StringHashTraceErrorEnable          = 0x4FC888C5;   ///< traceErrorEnable
static const UINT32 PropStringHashTraceErrorEnable      = 0xD5AC2BEB;   ///< traceErrorEnable
static const UINT32 StringHashSystemLogEnable           = 0x0748D6B1;   ///< systemLogEnable
static const UINT32 PropStringHashSystemLogEnable       = 0x739BF3A8;   ///< systemLogEnable
static const UINT32 StringHashEnablePipelineFlush       = 0xE0B91E97;   ///< enablePipelineFlush
static const UINT32 PropStringHashEnablePipelineFlush   = 0xB12E53A5;   ///< enablePipelineFlush
static const UINT32 StringHashDebugLogFilename          = 0xFC58346C;   ///< debugLogFilename
static const UINT32 PropStringHashDebugLogFilename      = 0x663C9742;   ///< debugLogFilename
static const UINT32 StringHashTraceGroupsEnable         = 0x6EE31BF9;   ///< traceGroupsEnable
static const UINT32 PropStringHashTraceGroupsEnable     = 0x22777E2A;   ///< traceGroupsEnable
static const UINT32 StringHashEnableFPSLog              = 0xB80C7CFE;   ///< enableFPSLog
static const UINT32 PropStringHashEnableFPSLog          = 0xF23E9558;   ///< enableFPSLog
static const UINT32 StringHashMaxMemSpyStats            = 0xD8B344AB;   ///< maxMemSpyStats
static const UINT32 PropStringHashMaxMemSpyStats        = 0x1315DD83;   ///< maxMemSpyStats
static const UINT32 StringHashMemSpyRequestRate         = 0x9C526BF5;   ///< memSpyRequestRate
static const UINT32 PropStringHashMemSpyRequestRate     = 0xD0C60E26;   ///< memSpyRequestRate
static const UINT32 StringHashDynamicPropertiesEnabled  = 0xD9D0EB44;   ///< dynamicPropertiesEnabled
static const UINT32 PropStringHashDynamicPropertiesEnabled  = 0xBD73C5DE;   ///< dynamicPropertiesEnabled
static const UINT32 StringHashPDebugProcess             = 0xD1582C30;   ///< pDebugProcess
static const UINT32 PropStringHashPDebugProcess         = 0x0DDDE13D;   ///< pDebugProcess
static const UINT32 StringHashCSLMode                   = 0x20F730FD;   ///< CSLMode
static const UINT32 PropStringHashCSLMode               = 0x52E004CA;   ///< CSLMode
static const UINT32 StringHashEnableSensorEmulation     = 0xCE36BD91;   ///< enableSensorEmulation
static const UINT32 PropStringHashEnableSensorEmulation  = 0x4BFBB04D;   ///< enableSensorEmulation
static const UINT32 StringHashEnableExternalSensorModule  = 0x072CBCAA;   ///< enableExternalSensorModule
static const UINT32 PropStringHashEnableExternalSensorModule  = 0xBE2726B1;   ///< enableExternalSensorModule
static const UINT32 StringHashEnableDebugSensorExposure  = 0xFAA0F8C0;   ///< enableDebugSensorExposure
static const UINT32 PropStringHashEnableDebugSensorExposure  = 0x2768A410;   ///< enableDebugSensorExposure
static const UINT32 StringHashSensorExposureTime        = 0xBF03A959;   ///< sensorExposureTime
static const UINT32 PropStringHashSensorExposureTime    = 0xA4BAA2C3;   ///< sensorExposureTime
static const UINT32 StringHashGain                      = 0x0032094E;   ///< gain
static const UINT32 PropStringHashGain                  = 0x685CED60;   ///< gain
static const UINT32 StringHashSensorShortExposureTime   = 0xE32992BB;   ///< sensorShortExposureTime
static const UINT32 PropStringHashSensorShortExposureTime  = 0xD71EE0AC;   ///< sensorShortExposureTime
static const UINT32 StringHashShortGain                 = 0x23727915;   ///< shortGain
static const UINT32 PropStringHashShortGain             = 0x7FA2A4DD;   ///< shortGain
static const UINT32 StringHashSensorMiddleExposureTime  = 0x874E6798;   ///< sensorMiddleExposureTime
static const UINT32 PropStringHashSensorMiddleExposureTime  = 0x01A0257E;   ///< sensorMiddleExposureTime
static const UINT32 StringHashMiddleGain                = 0xDE6FC377;   ///< middleGain
static const UINT32 PropStringHashMiddleGain            = 0x44747A7C;   ///< middleGain
static const UINT32 StringHashDumpSensorEmulationOutput  = 0x6F5E0A29;   ///< dumpSensorEmulationOutput
static const UINT32 PropStringHashDumpSensorEmulationOutput  = 0xB29656F9;   ///< dumpSensorEmulationOutput
static const UINT32 StringHashSensorEmulator            = 0xCA30CC41;   ///< sensorEmulator
static const UINT32 PropStringHashSensorEmulator        = 0x5A896DFA;   ///< sensorEmulator
static const UINT32 StringHashSensorEmulatorPath        = 0xC42529E4;   ///< sensorEmulatorPath
static const UINT32 PropStringHashSensorEmulatorPath    = 0xDF9C227E;   ///< sensorEmulatorPath
static const UINT32 StringHashDualLEDCalibrationMode    = 0x5037E53A;   ///< dualLEDCalibrationMode
static const UINT32 PropStringHashDualLEDCalibrationMode  = 0xE9965EAA;   ///< dualLEDCalibrationMode
static const UINT32 StringHashDynamicInlineCalibration  = 0x9A1F172D;   ///< dynamicInlineCalibration
static const UINT32 PropStringHashDynamicInlineCalibration  = 0x1CF155CB;   ///< dynamicInlineCalibration
static const UINT32 StringHashDynamicCalibrationMaxSize  = 0xF3345928;   ///< dynamicCalibrationMaxSize
static const UINT32 PropStringHashDynamicCalibrationMaxSize  = 0x2EFC05F8;   ///< dynamicCalibrationMaxSize
static const UINT32 StringHashDualLEDCalibrationPath    = 0x50395F37;   ///< dualLEDCalibrationPath
static const UINT32 PropStringHashDualLEDCalibrationPath  = 0xE998E4A7;   ///< dualLEDCalibrationPath
static const UINT32 StringHashDisableADRC               = 0x5FFC4E33;   ///< disableADRC
static const UINT32 PropStringHashDisableADRC           = 0x1C8B6F40;   ///< disableADRC
static const UINT32 StringHashDisablePreviewManualISO   = 0x3CC26D50;   ///< disablePreviewManualISO
static const UINT32 PropStringHashDisablePreviewManualISO  = 0x08F51F47;   ///< disablePreviewManualISO
static const UINT32 StringHashDisablePreviewManualExpTime  = 0xC2C865E0;   ///< disablePreviewManualExpTime
static const UINT32 PropStringHashDisablePreviewManualExpTime  = 0xE3BB2697;   ///< disablePreviewManualExpTime
static const UINT32 StringHashDisablePreviewManualFull  = 0x984A320B;   ///< disablePreviewManualFull
static const UINT32 PropStringHashDisablePreviewManualFull  = 0x1EA470ED;   ///< disablePreviewManualFull
static const UINT32 StringHashDisableSpeckleDetection   = 0xCDC83F76;   ///< disableSpeckleDetection
static const UINT32 PropStringHashDisableSpeckleDetection  = 0xF9FF4D61;   ///< disableSpeckleDetection
static const UINT32 StringHashDisableAFStatsProcessing  = 0x9932D4C9;   ///< disableAFStatsProcessing
static const UINT32 PropStringHashDisableAFStatsProcessing  = 0x1FDC962F;   ///< disableAFStatsProcessing
static const UINT32 StringHashDisableAFAlgoCHIOverload  = 0xB4EE529F;   ///< disableAFAlgoCHIOverload
static const UINT32 PropStringHashDisableAFAlgoCHIOverload  = 0x32001079;   ///< disableAFAlgoCHIOverload
static const UINT32 StringHashDisableAWBStatsProcessing  = 0xD9CA50FE;   ///< disableAWBStatsProcessing
static const UINT32 PropStringHashDisableAWBStatsProcessing  = 0x04020C2E;   ///< disableAWBStatsProcessing
static const UINT32 StringHashDisableAWBAlgoCHIOverload  = 0xF416D6A8;   ///< disableAWBAlgoCHIOverload
static const UINT32 PropStringHashDisableAWBAlgoCHIOverload  = 0x29DE8A78;   ///< disableAWBAlgoCHIOverload
static const UINT32 StringHashDisableAFDStatsProcessing  = 0xD9DB60FE;   ///< disableAFDStatsProcessing
static const UINT32 PropStringHashDisableAFDStatsProcessing  = 0x04133C2E;   ///< disableAFDStatsProcessing
static const UINT32 StringHashDisableAFDAlgoCHIOverload  = 0xF407E6A8;   ///< disableAFDAlgoCHIOverload
static const UINT32 PropStringHashDisableAFDAlgoCHIOverload  = 0x29CFBA78;   ///< disableAFDAlgoCHIOverload
static const UINT32 StringHashDisableASDStatsProcessing  = 0xD9CE60FE;   ///< disableASDStatsProcessing
static const UINT32 PropStringHashDisableASDStatsProcessing  = 0x04063C2E;   ///< disableASDStatsProcessing
static const UINT32 StringHashDisableASDAlgoCHIOverload  = 0xF412E6A8;   ///< disableASDAlgoCHIOverload
static const UINT32 PropStringHashDisableASDAlgoCHIOverload  = 0x29DABA78;   ///< disableASDAlgoCHIOverload
static const UINT32 StringHashDebugBufferRegDumpEnable  = 0xDA3D5950;   ///< debugBufferRegDumpEnable
static const UINT32 PropStringHashDebugBufferRegDumpEnable  = 0xBE9E77CA;   ///< debugBufferRegDumpEnable
static const UINT32 StringHashDebugBufferRegDumpSizeInBytes  = 0xF1F1DD58;   ///< debugBufferRegDumpSizeInBytes
static const UINT32 PropStringHashDebugBufferRegDumpSizeInBytes  = 0xC5389B05;   ///< debugBufferRegDumpSizeInBytes
static const UINT32 StringHashDebugBufferRegDumpFileNamePrefix  = 0xECD602F5;   ///< debugBufferRegDumpFileNamePrefix
static const UINT32 PropStringHashDebugBufferRegDumpFileNamePrefix  = 0x4FF89891;   ///< debugBufferRegDumpFileNamePrefix
static const UINT32 StringHashDumpIPEFirmwarePayload    = 0x9FA41F42;   ///< dumpIPEFirmwarePayload
static const UINT32 PropStringHashDumpIPEFirmwarePayload  = 0x393D3789;   ///< dumpIPEFirmwarePayload
static const UINT32 StringHashKpiDebug                  = 0xD4730583;   ///< kpiDebug
static const UINT32 PropStringHashKpiDebug              = 0xC93FFA38;   ///< kpiDebug
static const UINT32 StringHashEnableQTimer              = 0x964179AB;   ///< enableQTimer
static const UINT32 PropStringHashEnableQTimer          = 0xCDBE9E4B;   ///< enableQTimer
static const UINT32 StringHashEnableTPG                 = 0x82F3380F;   ///< enableTPG
static const UINT32 PropStringHashEnableTPG             = 0xDE23E5C7;   ///< enableTPG
static const UINT32 StringHashEnableCSIDBinning         = 0xA7B2CB1D;   ///< enableCSIDBinning
static const UINT32 PropStringHashEnableCSIDBinning     = 0x776F0341;   ///< enableCSIDBinning
static const UINT32 StringHashCSIDBinningMode           = 0x39C265AF;   ///< CSIDBinningMode
static const UINT32 PropStringHashCSIDBinningMode       = 0x2EF652DD;   ///< CSIDBinningMode
static const UINT32 StringHashForce3ALockedResult       = 0x504950E4;   ///< force3ALockedResult
static const UINT32 PropStringHashForce3ALockedResult   = 0x276823A7;   ///< force3ALockedResult
static const UINT32 StringHashForceDisableUBWCOnIfeIpeLink  = 0x8585BB42;   ///< forceDisableUBWCOnIfeIpeLink
static const UINT32 PropStringHashForceDisableUBWCOnIfeIpeLink  = 0x6C23F170;   ///< forceDisableUBWCOnIfeIpeLink
static const UINT32 StringHashEnableUBWCNV124ROnIFEFullOutIPELink  = 0x7600C890;   ///< enableUBWCNV124ROnIFEFullOutIPELink
static const UINT32 PropStringHashEnableUBWCNV124ROnIFEFullOutIPELink  = 0x3B329907;   ///< enableUBWCNV124ROnIFEFullOutIPELink
static const UINT32 StringHashCapResolutionForSingleIFE  = 0xCBA34006;   ///< capResolutionForSingleIFE
static const UINT32 PropStringHashCapResolutionForSingleIFE  = 0x5FC6934A;   ///< capResolutionForSingleIFE
static const UINT32 StringHashSingleIFESupportedWidth   = 0xDA5EB222;   ///< singleIFESupportedWidth
static const UINT32 PropStringHashSingleIFESupportedWidth  = 0x097BAB56;   ///< singleIFESupportedWidth
static const UINT32 StringHashSingleIFESupportedHeight  = 0x7510882F;   ///< singleIFESupportedHeight
static const UINT32 PropStringHashSingleIFESupportedHeight  = 0x11B3A6B5;   ///< singleIFESupportedHeight
static const UINT32 StringHashEnableFlashDebug          = 0x01E89A97;   ///< enableFlashDebug
static const UINT32 PropStringHashEnableFlashDebug      = 0x9B8C39B9;   ///< enableFlashDebug
static const UINT32 StringHashDumpSensorEEPROMData      = 0x8774CDD5;   ///< dumpSensorEEPROMData
static const UINT32 PropStringHashDumpSensorEEPROMData  = 0x635AA5BB;   ///< dumpSensorEEPROMData
static const UINT32 StringHashAutoImageDump             = 0xA33E53A6;   ///< autoImageDump
static const UINT32 PropStringHashAutoImageDump         = 0xE563676F;   ///< autoImageDump
static const UINT32 StringHashDumpInputatOutput         = 0x7FC2AA67;   ///< dumpInputatOutput
static const UINT32 PropStringHashDumpInputatOutput     = 0x3356CFB4;   ///< dumpInputatOutput
static const UINT32 StringHashAutoInputImageDumpMask    = 0x8B72D4F3;   ///< autoInputImageDumpMask
static const UINT32 PropStringHashAutoInputImageDumpMask  = 0x2DEBFC38;   ///< autoInputImageDumpMask
static const UINT32 StringHashIFERegDumpMask            = 0xCE73CEE2;   ///< IFERegDumpMask
static const UINT32 PropStringHashIFERegDumpMask        = 0x8742AF41;   ///< IFERegDumpMask
static const UINT32 StringHashAutoImageDumpMask         = 0x3A5D39EE;   ///< autoImageDumpMask
static const UINT32 PropStringHashAutoImageDumpMask     = 0x76C95C3D;   ///< autoImageDumpMask
static const UINT32 StringHashAutoImageDumpIFEoutputPortMask  = 0x3C0793C3;   ///< autoImageDumpIFEoutputPortMask
static const UINT32 PropStringHashAutoImageDumpIFEoutputPortMask  = 0xA52F5865;   ///< autoImageDumpIFEoutputPortMask
static const UINT32 StringHashAutoImageDumpIFEinputPortMask  = 0xD61C2FE2;   ///< autoImageDumpIFEinputPortMask
static const UINT32 PropStringHashAutoImageDumpIFEinputPortMask  = 0xE2D569BF;   ///< autoImageDumpIFEinputPortMask
static const UINT32 StringHashAutoImageDumpIFEoutputBatchNum  = 0xB1752F96;   ///< autoImageDumpIFEoutputBatchNum
static const UINT32 PropStringHashAutoImageDumpIFEoutputBatchNum  = 0x285DE430;   ///< autoImageDumpIFEoutputBatchNum
static const UINT32 StringHashAutoImageDumpIFEInstanceMask  = 0xD7CC328B;   ///< autoImageDumpIFEInstanceMask
static const UINT32 PropStringHashAutoImageDumpIFEInstanceMask  = 0x3E6A78B9;   ///< autoImageDumpIFEInstanceMask
static const UINT32 StringHashAutoImageDumpIPEoutputPortMask  = 0x3C0723C3;   ///< autoImageDumpIPEoutputPortMask
static const UINT32 PropStringHashAutoImageDumpIPEoutputPortMask  = 0xA52FE865;   ///< autoImageDumpIPEoutputPortMask
static const UINT32 StringHashAutoImageDumpIPEinputPortMask  = 0xD61C2A62;   ///< autoImageDumpIPEinputPortMask
static const UINT32 PropStringHashAutoImageDumpIPEinputPortMask  = 0xE2D56C3F;   ///< autoImageDumpIPEinputPortMask
static const UINT32 StringHashAutoImageDumpIPEInstanceMask  = 0xD7CC32A7;   ///< autoImageDumpIPEInstanceMask
static const UINT32 PropStringHashAutoImageDumpIPEInstanceMask  = 0x3E6A7895;   ///< autoImageDumpIPEInstanceMask
static const UINT32 StringHashAutoImageDumpBPSoutputPortMask  = 0x3C0C2643;   ///< autoImageDumpBPSoutputPortMask
static const UINT32 PropStringHashAutoImageDumpBPSoutputPortMask  = 0xA524EDE5;   ///< autoImageDumpBPSoutputPortMask
static const UINT32 StringHashAutoImageDumpBPSinputPortMask  = 0xD61C724E;   ///< autoImageDumpBPSinputPortMask
static const UINT32 PropStringHashAutoImageDumpBPSinputPortMask  = 0xE2D53413;   ///< autoImageDumpBPSinputPortMask
static const UINT32 StringHashAutoImageDumpBPSInstanceMask  = 0xB7CC3066;   ///< autoImageDumpBPSInstanceMask
static const UINT32 PropStringHashAutoImageDumpBPSInstanceMask  = 0x5E6A7A54;   ///< autoImageDumpBPSInstanceMask
static const UINT32 StringHashAutoImageDumpJpegHwoutputPortMask  = 0xB798BAD7;   ///< autoImageDumpJpegHwoutputPortMask
static const UINT32 PropStringHashAutoImageDumpJpegHwoutputPortMask  = 0xD24BF643;   ///< autoImageDumpJpegHwoutputPortMask
static const UINT32 StringHashAutoImageDumpJpegHwinputPortMask  = 0x7240D6AA;   ///< autoImageDumpJpegHwinputPortMask
static const UINT32 PropStringHashAutoImageDumpJpegHwinputPortMask  = 0xD16E4CCE;   ///< autoImageDumpJpegHwinputPortMask
static const UINT32 StringHashAutoImageDumpJpegHwInstanceMask  = 0x92EED541;   ///< autoImageDumpJpegHwInstanceMask
static const UINT32 PropStringHashAutoImageDumpJpegHwInstanceMask  = 0xB7F7A192;   ///< autoImageDumpJpegHwInstanceMask
static const UINT32 StringHashAutoImageDumpFDHwoutputPortMask  = 0xDE9279C7;   ///< autoImageDumpFDHwoutputPortMask
static const UINT32 PropStringHashAutoImageDumpFDHwoutputPortMask  = 0xFB8B0D14;   ///< autoImageDumpFDHwoutputPortMask
static const UINT32 StringHashAutoImageDumpFDHwinputPortMask  = 0xF10880B2;   ///< autoImageDumpFDHwinputPortMask
static const UINT32 PropStringHashAutoImageDumpFDHwinputPortMask  = 0x68204B14;   ///< autoImageDumpFDHwinputPortMask
static const UINT32 StringHashAutoImageDumpFDHwInstanceMask  = 0x56F497F1;   ///< autoImageDumpFDHwInstanceMask
static const UINT32 PropStringHashAutoImageDumpFDHwInstanceMask  = 0x623DD1AC;   ///< autoImageDumpFDHwInstanceMask
static const UINT32 StringHashAutoImageDumpLRMEoutputPortMask  = 0xDFC45547;   ///< autoImageDumpLRMEoutputPortMask
static const UINT32 PropStringHashAutoImageDumpLRMEoutputPortMask  = 0xFADD2194;   ///< autoImageDumpLRMEoutputPortMask
static const UINT32 StringHashAutoImageDumpLRMEinputPortMask  = 0xF10231D6;   ///< autoImageDumpLRMEinputPortMask
static const UINT32 PropStringHashAutoImageDumpLRMEinputPortMask  = 0x682AFA70;   ///< autoImageDumpLRMEinputPortMask
static const UINT32 StringHashAutoImageDumpLRMEInstanceMask  = 0x76F4C27A;   ///< autoImageDumpLRMEInstanceMask
static const UINT32 PropStringHashAutoImageDumpLRMEInstanceMask  = 0x423D8427;   ///< autoImageDumpLRMEInstanceMask
static const UINT32 StringHashAutoImageDumpRANSACoutputPortMask  = 0xF2ECF7DB;   ///< autoImageDumpRANSACoutputPortMask
static const UINT32 PropStringHashAutoImageDumpRANSACoutputPortMask  = 0x973FBB4F;   ///< autoImageDumpRANSACoutputPortMask
static const UINT32 StringHashAutoImageDumpRANSACinputPortMask  = 0x106B74C2;   ///< autoImageDumpRANSACinputPortMask
static const UINT32 PropStringHashAutoImageDumpRANSACinputPortMask  = 0xB345EEA6;   ///< autoImageDumpRANSACinputPortMask
static const UINT32 StringHashAutoImageDumpRANSACInstanceMask  = 0xD1FF8852;   ///< autoImageDumpRANSACInstanceMask
static const UINT32 PropStringHashAutoImageDumpRANSACInstanceMask  = 0xF4E6FC81;   ///< autoImageDumpRANSACInstanceMask
static const UINT32 StringHashAutoImageDumpCHINodeoutputPortMask  = 0x9DB2AF4A;   ///< autoImageDumpCHINodeoutputPortMask
static const UINT32 PropStringHashAutoImageDumpCHINodeoutputPortMask  = 0x27DB3DC6;   ///< autoImageDumpCHINodeoutputPortMask
static const UINT32 StringHashAutoImageDumpCHINodeinputPortMask  = 0x9B118606;   ///< autoImageDumpCHINodeinputPortMask
static const UINT32 PropStringHashAutoImageDumpCHINodeinputPortMask  = 0xFEC2CA92;   ///< autoImageDumpCHINodeinputPortMask
static const UINT32 StringHashAutoImageDumpCHINodeInstanceMask  = 0xF5A45FC4;   ///< autoImageDumpCHINodeInstanceMask
static const UINT32 PropStringHashAutoImageDumpCHINodeInstanceMask  = 0x568AC5A0;   ///< autoImageDumpCHINodeInstanceMask
static const UINT32 StringHashAutoImageDumpCVPoutputPortMask  = 0x3C0D1683;   ///< autoImageDumpCVPoutputPortMask
static const UINT32 PropStringHashAutoImageDumpCVPoutputPortMask  = 0xA525DD25;   ///< autoImageDumpCVPoutputPortMask
static const UINT32 StringHashAutoImageDumpCVPinputPortMask  = 0xD61C7BC8;   ///< autoImageDumpCVPinputPortMask
static const UINT32 PropStringHashAutoImageDumpCVPinputPortMask  = 0xE2D53D95;   ///< autoImageDumpCVPinputPortMask
static const UINT32 StringHashAutoImageDumpCVPInstanceMask  = 0x87CC302A;   ///< autoImageDumpCVPInstanceMask
static const UINT32 PropStringHashAutoImageDumpCVPInstanceMask  = 0x6E6A7A18;   ///< autoImageDumpCVPInstanceMask
static const UINT32 StringHashDynamicImageDump          = 0xAF48ED3A;   ///< dynamicImageDump
static const UINT32 PropStringHashDynamicImageDump      = 0x352C4E14;   ///< dynamicImageDump
static const UINT32 StringHashDynamicImageDumpTrigger   = 0x98E5791A;   ///< dynamicImageDumpTrigger
static const UINT32 PropStringHashDynamicImageDumpTrigger  = 0x4BC0606E;   ///< dynamicImageDumpTrigger
static const UINT32 StringHashWatermarkImage            = 0x7B3D2679;   ///< watermarkImage
static const UINT32 PropStringHashWatermarkImage        = 0xB09BBF51;   ///< watermarkImage
static const UINT32 StringHashWatermarkOffset           = 0x6B171F5B;   ///< watermarkOffset
static const UINT32 PropStringHashWatermarkOffset       = 0x1FC43A42;   ///< watermarkOffset
static const UINT32 StringHashReprocessDump             = 0xB24DF5D6;   ///< reprocessDump
static const UINT32 PropStringHashReprocessDump         = 0xF410C11F;   ///< reprocessDump
static const UINT32 StringHashOfflineImageDumpOnly      = 0x2E91E0BE;   ///< offlineImageDumpOnly
static const UINT32 PropStringHashOfflineImageDumpOnly  = 0x1C7846F4;   ///< offlineImageDumpOnly
static const UINT32 StringHashEnableIPEHangDump         = 0x690FD70A;   ///< enableIPEHangDump
static const UINT32 PropStringHashEnableIPEHangDump     = 0x5E1BCE2C;   ///< enableIPEHangDump
static const UINT32 StringHashEnableBPSHangDump         = 0x6923C10A;   ///< enableBPSHangDump
static const UINT32 PropStringHashEnableBPSHangDump     = 0x6F883EB6;   ///< enableBPSHangDump
static const UINT32 StringHashEnableIPEStripeDump       = 0x965BC597;   ///< enableIPEStripeDump
static const UINT32 PropStringHashEnableIPEStripeDump   = 0x9C1FF433;   ///< enableIPEStripeDump
static const UINT32 StringHashEnableBPSStripeDump       = 0x2603C597;   ///< enableBPSStripeDump
static const UINT32 PropStringHashEnableBPSStripeDump   = 0x1C1FFF36;   ///< enableBPSStripeDump
static const UINT32 StringHashEnableIPEScratchBufferDump  = 0xBCFFB5D5;   ///< enableIPEScratchBufferDump
static const UINT32 PropStringHashEnableIPEScratchBufferDump  = 0x281C3164;   ///< enableIPEScratchBufferDump
static const UINT32 StringHashForceMaxFPS               = 0x9DB80772;   ///< forceMaxFPS
static const UINT32 PropStringHashForceMaxFPS           = 0xAFE9903F;   ///< forceMaxFPS
static const UINT32 StringHashKickTheMachine            = 0x24274246;   ///< kickTheMachine
static const UINT32 PropStringHashKickTheMachine        = 0xEF81DB6E;   ///< kickTheMachine
static const UINT32 StringHashPerFrameSensorMode        = 0x306BBFEB;   ///< perFrameSensorMode
static const UINT32 PropStringHashPerFrameSensorMode    = 0xA2E70582;   ///< perFrameSensorMode
static const UINT32 StringHashDisablePDAF               = 0x5FF4CC56;   ///< disablePDAF
static const UINT32 PropStringHashDisablePDAF           = 0x6DA55B1B;   ///< disablePDAF
static const UINT32 StringHashEnableTouchToTrack        = 0xBE075808;   ///< enableTouchToTrack
static const UINT32 PropStringHashEnableTouchToTrack    = 0x2C8BE261;   ///< enableTouchToTrack
static const UINT32 StringHashTouchToTrackDownscaleRatio  = 0xB5B5482A;   ///< touchToTrackDownscaleRatio
static const UINT32 PropStringHashTouchToTrackDownscaleRatio  = 0x390F21B8;   ///< touchToTrackDownscaleRatio
static const UINT32 StringHashTouchToTrackSCVEOperationMode  = 0x5BE14E5A;   ///< touchToTrackSCVEOperationMode
static const UINT32 PropStringHashTouchToTrackSCVEOperationMode  = 0x6F280807;   ///< touchToTrackSCVEOperationMode
static const UINT32 StringHashTouchToTrackSCVEPrecisionMode  = 0xAAE36663;   ///< touchToTrackSCVEPrecisionMode
static const UINT32 PropStringHashTouchToTrackSCVEPrecisionMode  = 0x9E2A203E;   ///< touchToTrackSCVEPrecisionMode
static const UINT32 StringHashT2tConfidenceThreshold    = 0xAA08A72D;   ///< t2tConfidenceThreshold
static const UINT32 PropStringHashT2tConfidenceThreshold  = 0x0C918FE6;   ///< t2tConfidenceThreshold
static const UINT32 StringHashDefaultMaxFPS             = 0xAF39C008;   ///< defaultMaxFPS
static const UINT32 PropStringHashDefaultMaxFPS         = 0xE964F4C1;   ///< defaultMaxFPS
static const UINT32 StringHashBypassIPEICADependency    = 0xB06B45E5;   ///< bypassIPEICADependency
static const UINT32 PropStringHashBypassIPEICADependency  = 0x16F26D2E;   ///< bypassIPEICADependency
static const UINT32 StringHashDisableDRQPreemptionOnStopRecord  = 0xD0A91874;   ///< disableDRQPreemptionOnStopRecord
static const UINT32 PropStringHashDisableDRQPreemptionOnStopRecord  = 0x7D1A750A;   ///< disableDRQPreemptionOnStopRecord
static const UINT32 StringHashDisableVideoPerfModeSetting  = 0xE73415A9;   ///< disableVideoPerfModeSetting
static const UINT32 PropStringHashDisableVideoPerfModeSetting  = 0x707927F8;   ///< disableVideoPerfModeSetting
static const UINT32 StringHashEnableSensorAcquireOptimization  = 0x95DEB12A;   ///< enableSensorAcquireOptimization
static const UINT32 PropStringHashEnableSensorAcquireOptimization  = 0xB0C7C5F9;   ///< enableSensorAcquireOptimization
static const UINT32 StringHashCamVersionOverride        = 0x593350CD;   ///< camVersionOverride
static const UINT32 PropStringHashCamVersionOverride    = 0xCBBFEAA4;   ///< camVersionOverride
static const UINT32 StringHashOverrideOPPCLOCK          = 0xFEAC3322;   ///< overrideOPPCLOCK
static const UINT32 PropStringHashOverrideOPPCLOCK      = 0x64C8900C;   ///< overrideOPPCLOCK
static const UINT32 StringHashDumpGeolibResult          = 0x5072EB39;   ///< dumpGeolibResult
static const UINT32 PropStringHashDumpGeolibResult      = 0xCA164817;   ///< dumpGeolibResult
static const UINT32 StringHashDumpCVPICAInputConfig     = 0xFB8F8C5D;   ///< dumpCVPICAInputConfig
static const UINT32 PropStringHashDumpCVPICAInputConfig  = 0xA6BB451B;   ///< dumpCVPICAInputConfig
static const UINT32 StringHashTfTestMode                = 0xA179D55C;   ///< tfTestMode
static const UINT32 PropStringHashTfTestMode            = 0xC8EB59E6;   ///< tfTestMode
static const UINT32 StringHashEnableHJAF                = 0x5E696956;   ///< enableHJAF
static const UINT32 PropStringHashEnableHJAF            = 0x3B8C5D99;   ///< enableHJAF
static const UINT32 StringHashEnableSPD                 = 0x82F3240C;   ///< enableSPD
static const UINT32 PropStringHashEnableSPD             = 0xF9DC0DAA;   ///< enableSPD
static const UINT32 StringHashSpdStatsType              = 0x97471ADD;   ///< spdStatsType
static const UINT32 PropStringHashSpdStatsType          = 0x0394274A;   ///< spdStatsType
static const UINT32 StringHashDisableFocusIndication    = 0x83451B44;   ///< disableFocusIndication
static const UINT32 PropStringHashDisableFocusIndication  = 0xB3BFD081;   ///< disableFocusIndication
static const UINT32 StringHashSpotlightFallbackToCAF    = 0x1DA1228E;   ///< spotlightFallbackToCAF
static const UINT32 PropStringHashSpotlightFallbackToCAF  = 0xEBFF71C2;   ///< spotlightFallbackToCAF
static const UINT32 StringHashAfLog                     = 0x0622BD87;   ///< afLog
static const UINT32 PropStringHashAfLog                 = 0xECBD1B1E;   ///< afLog
static const UINT32 StringHashFovcEnable                = 0x0CDDA94D;   ///< fovcEnable
static const UINT32 PropStringHashFovcEnable            = 0x7F1507BB;   ///< fovcEnable
static const UINT32 StringHashGyroDataReportRate        = 0x04682770;   ///< gyroDataReportRate
static const UINT32 PropStringHashGyroDataReportRate    = 0x409D9052;   ///< gyroDataReportRate
static const UINT32 StringHashGyroSensorSamplingRate    = 0x3047FC2E;   ///< gyroSensorSamplingRate
static const UINT32 PropStringHashGyroSensorSamplingRate  = 0xBD8DB4BD;   ///< gyroSensorSamplingRate
static const UINT32 StringHashGravityDataReportRate     = 0x825814B8;   ///< gravityDataReportRate
static const UINT32 PropStringHashGravityDataReportRate  = 0xC1530342;   ///< gravityDataReportRate
static const UINT32 StringHashGravitySensorSamplingRate  = 0x0CCF9F2D;   ///< gravitySensorSamplingRate
static const UINT32 PropStringHashGravitySensorSamplingRate  = 0x3C4327AD;   ///< gravitySensorSamplingRate
static const UINT32 StringHashTOFDataReportRate         = 0x0885CD30;   ///< TOFDataReportRate
static const UINT32 PropStringHashTOFDataReportRate     = 0x2B6835B8;   ///< TOFDataReportRate
static const UINT32 StringHashTOFSensorSamplingRate     = 0x944732F0;   ///< TOFSensorSamplingRate
static const UINT32 PropStringHashTOFSensorSamplingRate  = 0xD6781157;   ///< TOFSensorSamplingRate
static const UINT32 StringHashCustomTOFSensorLib        = 0x876E88A9;   ///< customTOFSensorLib
static const UINT32 PropStringHashCustomTOFSensorLib    = 0x9CD78333;   ///< customTOFSensorLib
static const UINT32 StringHashMwEnable                  = 0x0CD10690;   ///< mwEnable
static const UINT32 PropStringHashMwEnable              = 0x9F9DFF33;   ///< mwEnable
static const UINT32 StringHashEnableAFAlgo              = 0xB7657DF6;   ///< enableAFAlgo
static const UINT32 PropStringHashEnableAFAlgo          = 0xE71AF209;   ///< enableAFAlgo
static const UINT32 StringHashAfFullsweep               = 0xDE82BD63;   ///< afFullsweep
static const UINT32 PropStringHashAfFullsweep           = 0x80F3930B;   ///< afFullsweep
static const UINT32 StringHashManualAf                  = 0x9B613F36;   ///< manualAf
static const UINT32 PropStringHashManualAf              = 0x00F667BF;   ///< manualAf
static const UINT32 StringHashLensPos                   = 0xCCD84D88;   ///< lensPos
static const UINT32 PropStringHashLensPos               = 0x0BB24F04;   ///< lensPos
static const UINT32 StringHashVmDebugMask               = 0x6D92CD3B;   ///< vmDebugMask
static const UINT32 PropStringHashVmDebugMask           = 0xA08BD2A5;   ///< vmDebugMask
static const UINT32 StringHashAFRecorderMode            = 0x958F3CA8;   ///< AFRecorderMode
static const UINT32 PropStringHashAFRecorderMode        = 0x615C01FB;   ///< AFRecorderMode
static const UINT32 StringHashEnableLensSagComp         = 0xF71A94D6;   ///< enableLensSagComp
static const UINT32 PropStringHashEnableLensSagComp     = 0xD83332AD;   ///< enableLensSagComp
static const UINT32 StringHashActiveNodeMask            = 0x05CDACA4;   ///< activeNodeMask
static const UINT32 PropStringHashActiveNodeMask        = 0xCF8FC490;   ///< activeNodeMask
static const UINT32 StringHashApiMask                   = 0xA6A70A13;   ///< apiMask
static const UINT32 PropStringHashApiMask               = 0x856E7C37;   ///< apiMask
static const UINT32 StringHashManualExposureType        = 0x5CC7EB64;   ///< manualExposureType
static const UINT32 PropStringHashManualExposureType    = 0xC6312754;   ///< manualExposureType
static const UINT32 StringHashDualBHistSupport          = 0xDD97DF0C;   ///< dualBHistSupport
static const UINT32 PropStringHashDualBHistSupport      = 0x21F7B753;   ///< dualBHistSupport
static const UINT32 StringHashDisableBGStatsForAF       = 0x1D94430C;   ///< disableBGStatsForAF
static const UINT32 PropStringHashDisableBGStatsForAF   = 0x29BBBD3C;   ///< disableBGStatsForAF
static const UINT32 StringHashEnableCustomAlgoAEC       = 0x0CA6EF7E;   ///< enableCustomAlgoAEC
static const UINT32 PropStringHashEnableCustomAlgoAEC   = 0x3889114E;   ///< enableCustomAlgoAEC
static const UINT32 StringHashDisableAFAWBpreFlash      = 0xC4DF006B;   ///< disableAFAWBpreFlash
static const UINT32 PropStringHashDisableAFAWBpreFlash  = 0x4120C66D;   ///< disableAFAWBpreFlash
static const UINT32 StringHashYuvPlaneAlignment         = 0x79996EA8;   ///< yuvPlaneAlignment
static const UINT32 PropStringHashYuvPlaneAlignment     = 0x350D0B7B;   ///< yuvPlaneAlignment
static const UINT32 StringHashPreFlashMaxFrameWaitLimitAF  = 0xA9C5FE72;   ///< preFlashMaxFrameWaitLimitAF
static const UINT32 PropStringHashPreFlashMaxFrameWaitLimitAF  = 0x01090FAD;   ///< preFlashMaxFrameWaitLimitAF
static const UINT32 StringHashPreFlashMaxFrameWaitLimitAWB  = 0x38BFCC17;   ///< preFlashMaxFrameWaitLimitAWB
static const UINT32 PropStringHashPreFlashMaxFrameWaitLimitAWB  = 0x2121F7E2;   ///< preFlashMaxFrameWaitLimitAWB
static const UINT32 StringHashDisablePreFlashOnForTouchAE  = 0xFB81A79C;   ///< disablePreFlashOnForTouchAE
static const UINT32 PropStringHashDisablePreFlashOnForTouchAE  = 0x7E9CCE67;   ///< disablePreFlashOnForTouchAE
static const UINT32 StringHashNumberOfFramesToSkip      = 0xA5CD5B0A;   ///< numberOfFramesToSkip
static const UINT32 PropStringHashNumberOfFramesToSkip  = 0x33EF774A;   ///< numberOfFramesToSkip
static const UINT32 StringHashCustomAlgoAECName         = 0x4B6FD98B;   ///< customAlgoAECName
static const UINT32 PropStringHashCustomAlgoAECName     = 0x9BB211D7;   ///< customAlgoAECName
static const UINT32 StringHashCustomAlgoAECPath         = 0x4B60DAA6;   ///< customAlgoAECPath
static const UINT32 PropStringHashCustomAlgoAECPath     = 0x9BBD12FA;   ///< customAlgoAECPath
static const UINT32 StringHashEnableCustomAlgoAWB       = 0x0CA6ED3F;   ///< enableCustomAlgoAWB
static const UINT32 PropStringHashEnableCustomAlgoAWB   = 0x3889371F;   ///< enableCustomAlgoAWB
static const UINT32 StringHashCustomAlgoAWBName         = 0x6F7FD98B;   ///< customAlgoAWBName
static const UINT32 PropStringHashCustomAlgoAWBName     = 0xBFA211D7;   ///< customAlgoAWBName
static const UINT32 StringHashCustomAlgoAWBPath         = 0x6F70DAA6;   ///< customAlgoAWBPath
static const UINT32 PropStringHashCustomAlgoAWBPath     = 0xBFAD12FA;   ///< customAlgoAWBPath
static const UINT32 StringHashEnableCustomAlgoAF        = 0xE865377B;   ///< enableCustomAlgoAF
static const UINT32 PropStringHashEnableCustomAlgoAF    = 0xD5A83C84;   ///< enableCustomAlgoAF
static const UINT32 StringHashCustomAlgoAFName          = 0x726DC347;   ///< customAlgoAFName
static const UINT32 PropStringHashCustomAlgoAFName      = 0x94EB2D05;   ///< customAlgoAFName
static const UINT32 StringHashCustomAlgoAFPath          = 0x7262C06A;   ///< customAlgoAFPath
static const UINT32 PropStringHashCustomAlgoAFPath      = 0x94E42E28;   ///< customAlgoAFPath
static const UINT32 StringHashEnableCustomHAFAlgo       = 0x56B1DB30;   ///< enableCustomHAFAlgo
static const UINT32 PropStringHashEnableCustomHAFAlgo   = 0xEF10A4D7;   ///< enableCustomHAFAlgo
static const UINT32 StringHashCustomHAFAlgoName         = 0x0F8A78F8;   ///< customHAFAlgoName
static const UINT32 PropStringHashCustomHAFAlgoName     = 0x8BF00595;   ///< customHAFAlgoName
static const UINT32 StringHashCustomHAFAlgoPath         = 0x0F857BD5;   ///< customHAFAlgoPath
static const UINT32 PropStringHashCustomHAFAlgoPath     = 0xDF58B389;   ///< customHAFAlgoPath
static const UINT32 StringHashOverrideHAFAlgoMask       = 0x094DC34D;   ///< overrideHAFAlgoMask
static const UINT32 PropStringHashOverrideHAFAlgoMask   = 0xD841730A;   ///< overrideHAFAlgoMask
static const UINT32 StringHashExposureGain              = 0x910C65CB;   ///< exposureGain
static const UINT32 PropStringHashExposureGain          = 0xA55E64F9;   ///< exposureGain
static const UINT32 StringHashExposureTime              = 0x9105C540;   ///< exposureTime
static const UINT32 PropStringHashExposureTime          = 0x81E07B6A;   ///< exposureTime
static const UINT32 StringHashLuxIndex                  = 0xB6A69FA5;   ///< luxIndex
static const UINT32 PropStringHashLuxIndex              = 0x6DDCC963;   ///< luxIndex
static const UINT32 StringHashExtendedTimeForLongExposure  = 0x5B0480B2;   ///< extendedTimeForLongExposure
static const UINT32 PropStringHashExtendedTimeForLongExposure  = 0x74FAB086;   ///< extendedTimeForLongExposure
static const UINT32 StringHashManualWhiteBalanceType    = 0xEB20DB85;   ///< manualWhiteBalanceType
static const UINT32 PropStringHashManualWhiteBalanceType  = 0xC631355C;   ///< manualWhiteBalanceType
static const UINT32 StringHashRGain                     = 0x0712094E;   ///< rGain
static const UINT32 PropStringHashRGain                 = 0x8A1FBFBB;   ///< rGain
static const UINT32 StringHashGGain                     = 0x0642094E;   ///< gGain
static const UINT32 PropStringHashGGain                 = 0x8B4FBFBB;   ///< gGain
static const UINT32 StringHashBGain                     = 0x0612094E;   ///< BGain
static const UINT32 PropStringHashBGain                 = 0x8B1FBFBB;   ///< BGain
static const UINT32 StringHashColorTemp                 = 0xD91BF9B3;   ///< colorTemp
static const UINT32 PropStringHashColorTemp             = 0xB6432968;   ///< colorTemp
static const UINT32 StringHashIgnoreSceneMode           = 0x4C23FA6C;   ///< ignoreSceneMode
static const UINT32 PropStringHashIgnoreSceneMode       = 0x9737C75F;   ///< ignoreSceneMode
static const UINT32 StringHashEnableCustomAlgoASD       = 0x0CA6EDB9;   ///< enableCustomAlgoASD
static const UINT32 PropStringHashEnableCustomAlgoASD   = 0x6BFA7111;   ///< enableCustomAlgoASD
static const UINT32 StringHashCustomAlgoASDName         = 0x671FD98B;   ///< customAlgoASDName
static const UINT32 PropStringHashCustomAlgoASDName     = 0xB772270D;   ///< customAlgoASDName
static const UINT32 StringHashCustomAlgoASDPath         = 0x6710DAA6;   ///< customAlgoASDPath
static const UINT32 PropStringHashCustomAlgoASDPath     = 0xB77D2420;   ///< customAlgoASDPath
static const UINT32 StringHashEnableCustomAlgoAFD       = 0x0CA6EF19;   ///< enableCustomAlgoAFD
static const UINT32 PropStringHashEnableCustomAlgoAFD   = 0x3FFA7111;   ///< enableCustomAlgoAFD
static const UINT32 StringHashCustomAlgoAFDName         = 0x4D1FD98B;   ///< customAlgoAFDName
static const UINT32 PropStringHashCustomAlgoAFDName     = 0xB767270D;   ///< customAlgoAFDName
static const UINT32 StringHashCustomAlgoAFDPath         = 0x4D10DAA6;   ///< customAlgoAFDPath
static const UINT32 PropStringHashCustomAlgoAFDPath     = 0xB7682420;   ///< customAlgoAFDPath
static const UINT32 StringHashEnableDualIFE             = 0x8AAF8792;   ///< enableDualIFE
static const UINT32 PropStringHashEnableDualIFE         = 0xE64AD921;   ///< enableDualIFE
static const UINT32 StringHashForceDualIFEOn            = 0x56225EF4;   ///< forceDualIFEOn
static const UINT32 PropStringHashForceDualIFEOn        = 0xD2C60985;   ///< forceDualIFEOn
static const UINT32 StringHashDualIFESplitPointOffset   = 0xDB202240;   ///< dualIFESplitPointOffset
static const UINT32 PropStringHashDualIFESplitPointOffset  = 0xE2C10874;   ///< dualIFESplitPointOffset
static const UINT32 StringHashDualIFELeftPadding        = 0x9BB97FCF;   ///< dualIFELeftPadding
static const UINT32 PropStringHashDualIFELeftPadding    = 0x6B2C65D3;   ///< dualIFELeftPadding
static const UINT32 StringHashDualIFERightPadding       = 0x32195890;   ///< dualIFERightPadding
static const UINT32 PropStringHashDualIFERightPadding   = 0x20BA1B0E;   ///< dualIFERightPadding
static const UINT32 StringHashIFETestImageSizeWidth     = 0x36B34DC8;   ///< IFETestImageSizeWidth
static const UINT32 PropStringHashIFETestImageSizeWidth  = 0xEE5ACE15;   ///< IFETestImageSizeWidth
static const UINT32 StringHashIFETestImageSizeHeight    = 0xE8AF7572;   ///< IFETestImageSizeHeight
static const UINT32 PropStringHashIFETestImageSizeHeight  = 0xF59F0EC9;   ///< IFETestImageSizeHeight
static const UINT32 StringHashIsOEMStatSettingEnable    = 0x165F8225;   ///< IsOEMStatSettingEnable
static const UINT32 StringHashDisableManual3ACCM        = 0x64D3CD3F;   ///< DisableManual3ACCM
static const UINT32 PropStringHashDisableManual3ACCM    = 0xF65F7756;   ///< DisableManual3ACCM
static const UINT32 StringHashIFENumFramesHighBW        = 0xF923516F;   ///< IFENumFramesHighBW
static const UINT32 PropStringHashIFENumFramesHighBW    = 0x6BAFEB06;   ///< IFENumFramesHighBW
static const UINT32 StringHashPdafHWEnable              = 0x354D40B8;   ///< pdafHWEnable
static const UINT32 StringHashEnableIFERegDump          = 0x5BD9AFA0;   ///< enableIFERegDump
static const UINT32 StringHashEnableActiveIFEABVote     = 0x79614E2B;   ///< enableActiveIFEABVote
static const UINT32 PropStringHashEnableActiveIFEABVote  = 0xFCAC43F7;   ///< enableActiveIFEABVote
static const UINT32 StringHashIFEDynamicEnableMask      = 0xAFA0146A;   ///< IFEDynamicEnableMask
static const UINT32 PropStringHashIFEDynamicEnableMask  = 0x9D49B220;   ///< IFEDynamicEnableMask
static const UINT32 StringHashIfeClockFrequencyMHz      = 0x0C0990FE;   ///< ifeClockFrequencyMHz
static const UINT32 PropStringHashIfeClockFrequencyMHz  = 0xD45D5F2F;   ///< ifeClockFrequencyMHz
static const UINT32 StringHashIfeCamnocBandwidthMBytes  = 0x3531572C;   ///< ifeCamnocBandwidthMBytes
static const UINT32 PropStringHashIfeCamnocBandwidthMBytes  = 0xC82CD260;   ///< ifeCamnocBandwidthMBytes
static const UINT32 StringHashIfeExternalBandwidthMBytes  = 0x0F5FD453;   ///< ifeExternalBandwidthMBytes
static const UINT32 PropStringHashIfeExternalBandwidthMBytes  = 0x794AE7A7;   ///< ifeExternalBandwidthMBytes
static const UINT32 StringHashEnableHVXStreaming        = 0x253D4945;   ///< enableHVXStreaming
static const UINT32 PropStringHashEnableHVXStreaming    = 0xD2C48007;   ///< enableHVXStreaming
static const UINT32 StringHashEnableIPEIQModulesMask    = 0x61D815A5;   ///< enableIPEIQModulesMask
static const UINT32 PropStringHashEnableIPEIQModulesMask  = 0xC7413D6E;   ///< enableIPEIQModulesMask
static const UINT32 StringHashEnableIPEUpscale          = 0xB09A6994;   ///< enableIPEUpscale
static const UINT32 PropStringHashEnableIPEUpscale      = 0x2AFECABA;   ///< enableIPEUpscale
static const UINT32 StringHashEnableIPEOnlyDownscale    = 0xD859D69D;   ///< enableIPEOnlyDownscale
static const UINT32 PropStringHashEnableIPEOnlyDownscale  = 0x7EC0FE56;   ///< enableIPEOnlyDownscale
static const UINT32 StringHashDisableIPEInternalDownscale  = 0x1153DCB5;   ///< disableIPEInternalDownscale
static const UINT32 PropStringHashDisableIPEInternalDownscale  = 0x861EEEE4;   ///< disableIPEInternalDownscale
static const UINT32 StringHashEnableIPEDependencies     = 0x27657A7A;   ///< enableIPEDependencies
static const UINT32 PropStringHashEnableIPEDependencies  = 0x7A51B33C;   ///< enableIPEDependencies
static const UINT32 StringHashEnableIPEIQLogging        = 0xB1C3F36A;   ///< enableIPEIQLogging
static const UINT32 PropStringHashEnableIPEIQLogging    = 0x56444FB0;   ///< enableIPEIQLogging
static const UINT32 StringHashEnableMCTF                = 0x5E6BCFF6;   ///< enableMCTF
static const UINT32 PropStringHashEnableMCTF            = 0x37F9434C;   ///< enableMCTF
static const UINT32 StringHashDisableCVPDriver          = 0xEFAAAEDE;   ///< disableCVPDriver
static const UINT32 PropStringHashDisableCVPDriver      = 0x75CE0DF0;   ///< disableCVPDriver
static const UINT32 StringHashNumIPECoresToUse          = 0x08ED3B10;   ///< numIPECoresToUse
static const UINT32 PropStringHashNumIPECoresToUse      = 0x9289983E;   ///< numIPECoresToUse
static const UINT32 StringHashForce8BitUBWCAlignment    = 0x689CDBA9;   ///< force8BitUBWCAlignment
static const UINT32 PropStringHashForce8BitUBWCAlignment  = 0xCE05F362;   ///< force8BitUBWCAlignment
static const UINT32 StringHashSetLRMETransformTypeMask  = 0x1F8302D6;   ///< setLRMETransformTypeMask
static const UINT32 PropStringHashSetLRMETransformTypeMask  = 0x7B202C4C;   ///< setLRMETransformTypeMask
static const UINT32 StringHashIsGridFromChromatixEnabled  = 0xC8800080;   ///< isGridFromChromatixEnabled
static const UINT32 PropStringHashIsGridFromChromatixEnabled  = 0x443A6912;   ///< isGridFromChromatixEnabled
static const UINT32 StringHashAlignmentFusionMode       = 0x77E1A53A;   ///< alignmentFusionMode
static const UINT32 PropStringHashAlignmentFusionMode   = 0x2676E808;   ///< alignmentFusionMode
static const UINT32 StringHashIsFirstFrameLoopbackInputImageEnabled  = 0xA212B660;   ///< isFirstFrameLoopbackInputImageEnabled
static const UINT32 PropStringHashIsFirstFrameLoopbackInputImageEnabled  = 0x6B54EB54;   ///< isFirstFrameLoopbackInputImageEnabled
static const UINT32 StringHashEnableLDC                 = 0x82F35A8B;   ///< enableLDC
static const UINT32 PropStringHashEnableLDC             = 0x51BFCEEE;   ///< enableLDC
static const UINT32 StringHashDebugDataHeaderString     = 0x4224D04E;   ///< debugDataHeaderString
static const UINT32 PropStringHashDebugDataHeaderString  = 0xCAFE1DF8;   ///< debugDataHeaderString
static const UINT32 StringHashEnable3ADebugData         = 0x9E65A553;   ///< enable3ADebugData
static const UINT32 PropStringHashEnable3ADebugData     = 0xAB2128D3;   ///< enable3ADebugData
static const UINT32 StringHashDebugDataSizeAEC          = 0x778C6654;   ///< debugDataSizeAEC
static const UINT32 PropStringHashDebugDataSizeAEC      = 0x1AEABD10;   ///< debugDataSizeAEC
static const UINT32 StringHashDebugDataSizeAWB          = 0x778C6415;   ///< debugDataSizeAWB
static const UINT32 PropStringHashDebugDataSizeAWB      = 0x1AEABF51;   ///< debugDataSizeAWB
static const UINT32 StringHashDebugDataSizeAF           = 0xBBBC6332;   ///< debugDataSizeAF
static const UINT32 PropStringHashDebugDataSizeAF       = 0x98D755E8;   ///< debugDataSizeAF
static const UINT32 StringHashEnableTuningMetadata      = 0xFCCB570C;   ///< enableTuningMetadata
static const UINT32 PropStringHashEnableTuningMetadata  = 0xE2383C92;   ///< enableTuningMetadata
static const UINT32 StringHashTuningDumpDataSizeIFE     = 0xC9425926;   ///< tuningDumpDataSizeIFE
static const UINT32 PropStringHashTuningDumpDataSizeIFE  = 0x172F2AE5;   ///< tuningDumpDataSizeIFE
static const UINT32 StringHashTuningDumpDataSizeIPE     = 0xC9425BE6;   ///< tuningDumpDataSizeIPE
static const UINT32 PropStringHashTuningDumpDataSizeIPE  = 0x172F2825;   ///< tuningDumpDataSizeIPE
static const UINT32 StringHashTuningDumpDataSizeBPS     = 0xC94277F0;   ///< tuningDumpDataSizeBPS
static const UINT32 PropStringHashTuningDumpDataSizeBPS  = 0x172F0433;   ///< tuningDumpDataSizeBPS
static const UINT32 StringHashDumpDebugDataEveryProcessResult  = 0x4A508CB2;   ///< dumpDebugDataEveryProcessResult
static const UINT32 PropStringHashDumpDebugDataEveryProcessResult  = 0x7D229B86;   ///< dumpDebugDataEveryProcessResult
static const UINT32 StringHashDebugDataOfflineAlloc     = 0x6CF72C0D;   ///< debugDataOfflineAlloc
static const UINT32 PropStringHashDebugDataOfflineAlloc  = 0xB29A5FCE;   ///< debugDataOfflineAlloc
static const UINT32 StringHashDisablePDLibCHIOverload   = 0xE86996FE;   ///< disablePDLibCHIOverload
static const UINT32 PropStringHashDisablePDLibCHIOverload  = 0xDC5EE4E9;   ///< disablePDLibCHIOverload
static const UINT32 StringHashEnableCustomPDLib         = 0xEE57057B;   ///< enableCustomPDLib
static const UINT32 PropStringHashEnableCustomPDLib     = 0x30AED2FA;   ///< enableCustomPDLib
static const UINT32 StringHashCustomPDLibName           = 0xDFA742D3;   ///< customPDLibName
static const UINT32 PropStringHashCustomPDLibName       = 0xC89375A1;   ///< customPDLibName
static const UINT32 StringHashCustomPDLibPath           = 0xDFA841FE;   ///< customPDLibPath
static const UINT32 PropStringHashCustomPDLibPath       = 0xC89C768C;   ///< customPDLibPath
static const UINT32 StringHashTintlessEnable            = 0xAA0CE38F;   ///< tintlessEnable
static const UINT32 PropStringHashTintlessEnable        = 0x3AB54234;   ///< tintlessEnable
static const UINT32 StringHashEnablePDLibLog            = 0x0FA55BD2;   ///< enablePDLibLog
static const UINT32 PropStringHashEnablePDLibLog        = 0xABEC84E2;   ///< enablePDLibLog
static const UINT32 StringHashEnablePDLibTestMode       = 0x0B687A90;   ///< enablePDLibTestMode
static const UINT32 PropStringHashEnablePDLibTestMode   = 0x5A877D49;   ///< enablePDLibTestMode
static const UINT32 StringHashEnablePDLibProfiling      = 0x494EE3B9;   ///< enablePDLibProfiling
static const UINT32 PropStringHashEnablePDLibProfiling  = 0xB012A3E2;   ///< enablePDLibProfiling
static const UINT32 StringHashEnablePDLibDump           = 0xF4AF1371;   ///< enablePDLibDump
static const UINT32 PropStringHashEnablePDLibDump       = 0x5A8F3E8D;   ///< enablePDLibDump
static const UINT32 StringHashDisablePDLibLCR           = 0xDFA5435E;   ///< disablePDLibLCR
static const UINT32 PropStringHashDisablePDLibLCR       = 0xE6EC81C1;   ///< disablePDLibLCR
static const UINT32 StringHashIfeSWCDMEnable            = 0xDF93850A;   ///< ifeSWCDMEnable
static const UINT32 PropStringHashIfeSWCDMEnable        = 0x4F2A24B1;   ///< ifeSWCDMEnable
static const UINT32 StringHashEnableAEScan              = 0xB75C4137;   ///< enableAEScan
static const UINT32 PropStringHashEnableAEScan          = 0x2DF6CAE7;   ///< enableAEScan
static const UINT32 StringHashOverrideLogLevels         = 0x0B1AFF31;   ///< overrideLogLevels
static const UINT32 PropStringHashOverrideLogLevels     = 0xDBC7376D;   ///< overrideLogLevels
static const UINT32 StringHashOverrideDisableZSL        = 0x2CFEB8EE;   ///< overrideDisableZSL
static const UINT32 PropStringHashOverrideDisableZSL    = 0x3747B374;   ///< overrideDisableZSL
static const UINT32 StringHashEnableLRMEDS2             = 0x846B3167;   ///< enableLRMEDS2
static const UINT32 PropStringHashEnableLRMEDS2         = 0x58EEFC6A;   ///< enableLRMEDS2
static const UINT32 StringHashOverrideEnableMFNR        = 0xF06AECC0;   ///< overrideEnableMFNR
static const UINT32 PropStringHashOverrideEnableMFNR    = 0xEBD3E75A;   ///< overrideEnableMFNR
static const UINT32 StringHashAnchorSelectionAlgoForMFNR  = 0xCB7A2D13;   ///< anchorSelectionAlgoForMFNR
static const UINT32 PropStringHashAnchorSelectionAlgoForMFNR  = 0x7271B708;   ///< anchorSelectionAlgoForMFNR
static const UINT32 StringHashAnchorAlgoSelectionType   = 0x29DDC9C3;   ///< anchorAlgoSelectionType
static const UINT32 PropStringHashAnchorAlgoSelectionType  = 0x1DEABBD4;   ///< anchorAlgoSelectionType
static const UINT32 StringHashAdvanceFeatureMask        = 0xAD34602C;   ///< advanceFeatureMask
static const UINT32 PropStringHashAdvanceFeatureMask    = 0xD9AD79CF;   ///< advanceFeatureMask
static const UINT32 StringHashEnableOfflineNoiseReprocess  = 0x10616FE6;   ///< enableOfflineNoiseReprocess
static const UINT32 PropStringHashEnableOfflineNoiseReprocess  = 0x31122C91;   ///< enableOfflineNoiseReprocess
static const UINT32 StringHashEnableGamma15PreCalculate  = 0xDE85B824;   ///< enableGamma15PreCalculate
static const UINT32 PropStringHashEnableGamma15PreCalculate  = 0x034DE4F4;   ///< enableGamma15PreCalculate
static const UINT32 StringHashOverrideForceUsecaseId    = 0x0E822F1C;   ///< overrideForceUsecaseId
static const UINT32 PropStringHashOverrideForceUsecaseId  = 0xB723948C;   ///< overrideForceUsecaseId
static const UINT32 StringHashOverrideForceSensorMode   = 0xCC512DB8;   ///< overrideForceSensorMode
static const UINT32 PropStringHashOverrideForceSensorMode  = 0xF8665FAF;   ///< overrideForceSensorMode
static const UINT32 StringHashOverrideForceFSCapable    = 0x8B9B20BC;   ///< overrideForceFSCapable
static const UINT32 PropStringHashOverrideForceFSCapable  = 0x323A9B2C;   ///< overrideForceFSCapable
static const UINT32 StringHashOverrideGPURotationUsecase  = 0xDC9A909F;   ///< overrideGPURotationUsecase
static const UINT32 PropStringHashOverrideGPURotationUsecase  = 0x65910A84;   ///< overrideGPURotationUsecase
static const UINT32 StringHashOverrideGPUDownscaleUsecase  = 0xCC9A2BD9;   ///< overrideGPUDownscaleUsecase
static const UINT32 PropStringHashOverrideGPUDownscaleUsecase  = 0xEDE968AE;   ///< overrideGPUDownscaleUsecase
static const UINT32 StringHashOverrideHFRNo3AUseCase    = 0xBEFF3AD5;   ///< overrideHFRNo3AUseCase
static const UINT32 PropStringHashOverrideHFRNo3AUseCase  = 0x075E8145;   ///< overrideHFRNo3AUseCase
static const UINT32 StringHashOverrideCameraClose       = 0x85A17064;   ///< overrideCameraClose
static const UINT32 PropStringHashOverrideCameraClose   = 0xF2800327;   ///< overrideCameraClose
static const UINT32 StringHashOverrideCameraOpen        = 0x0C2B7ADD;   ///< overrideCameraOpen
static const UINT32 PropStringHashOverrideCameraOpen    = 0x17927147;   ///< overrideCameraOpen
static const UINT32 StringHashOverridePDLibClose        = 0x2C08E11D;   ///< overridePDLibClose
static const UINT32 PropStringHashOverridePDLibClose    = 0x37B1EA87;   ///< overridePDLibClose
static const UINT32 StringHashOverridePDLibOpen         = 0xC1663656;   ///< overridePDLibOpen
static const UINT32 PropStringHashOverridePDLibOpen     = 0x11BBFE0A;   ///< overridePDLibOpen
static const UINT32 StringHashEISV2Enable               = 0x4D485559;   ///< EISV2Enable
static const UINT32 PropStringHashEISV2Enable           = 0x0E3F742A;   ///< EISV2Enable
static const UINT32 StringHashEISV3Enable               = 0x0D485559;   ///< EISV3Enable
static const UINT32 PropStringHashEISV3Enable           = 0x4E3F742A;   ///< EISV3Enable
static const UINT32 StringHashEISV2Margin               = 0x5DB1C1F2;   ///< EISV2Margin
static const UINT32 PropStringHashEISV2Margin           = 0x1EC6E081;   ///< EISV2Margin
static const UINT32 StringHashEISV2FrameDelay           = 0x87B794DF;   ///< EISV2FrameDelay
static const UINT32 PropStringHashEISV2FrameDelay       = 0x9083A3AD;   ///< EISV2FrameDelay
static const UINT32 StringHashEISV3Margin               = 0x1DB1C1F2;   ///< EISV3Margin
static const UINT32 PropStringHashEISV3Margin           = 0x5EC6E081;   ///< EISV3Margin
static const UINT32 StringHashEISV3FrameDelay           = 0x87B394DF;   ///< EISV3FrameDelay
static const UINT32 PropStringHashEISV3FrameDelay       = 0x9087A3AD;   ///< EISV3FrameDelay
static const UINT32 StringHashNumPCRsBeforeStreamOn     = 0xBAB395D2;   ///< numPCRsBeforeStreamOn
static const UINT32 PropStringHashNumPCRsBeforeStreamOn  = 0x3F7E980E;   ///< numPCRsBeforeStreamOn
static const UINT32 StringHashMaxImageBufferTimeoutCount  = 0x6F432AB3;   ///< maxImageBufferTimeoutCount
static const UINT32 PropStringHashMaxImageBufferTimeoutCount  = 0xD648B0A8;   ///< maxImageBufferTimeoutCount
static const UINT32 StringHashImageBufferWaitTime       = 0x5E2D59E7;   ///< imageBufferWaitTime
static const UINT32 PropStringHashImageBufferWaitTime   = 0x290C2AA4;   ///< imageBufferWaitTime
static const UINT32 StringHashOverrideMaxImageBufferCountRealTime  = 0x53617233;   ///< overrideMaxImageBufferCountRealTime
static const UINT32 PropStringHashOverrideMaxImageBufferCountRealTime  = 0x20220512;   ///< overrideMaxImageBufferCountRealTime
static const UINT32 StringHashOverrideMaxImageBufferCountNonRealTime  = 0xE971CF81;   ///< overrideMaxImageBufferCountNonRealTime
static const UINT32 PropStringHashOverrideMaxImageBufferCountNonRealTime  = 0x52E17620;   ///< overrideMaxImageBufferCountNonRealTime
static const UINT32 StringHashStatsProcessingSkipFactor  = 0xD98ACEEF;   ///< statsProcessingSkipFactor
static const UINT32 PropStringHashStatsProcessingSkipFactor  = 0x68754FC9;   ///< statsProcessingSkipFactor
static const UINT32 StringHashMaxNonHfrFps              = 0x6153FB10;   ///< maxNonHfrFps
static const UINT32 PropStringHashMaxNonHfrFps          = 0x0FB7D578;   ///< maxNonHfrFps
static const UINT32 StringHashMinFrameRateBound         = 0xDD40DBFA;   ///< minFrameRateBound
static const UINT32 PropStringHashMinFrameRateBound     = 0x0D9D13A6;   ///< minFrameRateBound
static const UINT32 StringHashEnableOISOptimization     = 0x3C4A768F;   ///< enableOISOptimization
static const UINT32 PropStringHashEnableOISOptimization  = 0xB9877B53;   ///< enableOISOptimization
static const UINT32 StringHashEnableSensorCaching       = 0x9E91AEE3;   ///< enableSensorCaching
static const UINT32 PropStringHashEnableSensorCaching   = 0xE9B0DDA0;   ///< enableSensorCaching
static const UINT32 StringHashForceDebugQCFASWRemosaic  = 0x81A88EED;   ///< forceDebugQCFASWRemosaic
static const UINT32 PropStringHashForceDebugQCFASWRemosaic  = 0x0746CC0B;   ///< forceDebugQCFASWRemosaic
static const UINT32 StringHashEnableCHIPartialData      = 0x05FEA2E8;   ///< enableCHIPartialData
static const UINT32 PropStringHashEnableCHIPartialData  = 0xE1D0CA86;   ///< enableCHIPartialData
static const UINT32 StringHashEnableCHIPartialDataRecovery  = 0x7E6871B5;   ///< enableCHIPartialDataRecovery
static const UINT32 PropStringHashEnableCHIPartialDataRecovery  = 0x50001F51;   ///< enableCHIPartialDataRecovery
static const UINT32 StringHashDumpMetadata              = 0x9DFA5990;   ///< dumpMetadata
static const UINT32 PropStringHashDumpMetadata          = 0xD7C8B036;   ///< dumpMetadata
static const UINT32 StringHashMemsetInputMeta           = 0x056DEB01;   ///< memsetInputMeta
static const UINT32 PropStringHashMemsetInputMeta       = 0x088FC8BB;   ///< memsetInputMeta
static const UINT32 StringHashEnableLinearMetaLUT       = 0xE1E7F792;   ///< enableLinearMetaLUT
static const UINT32 PropStringHashEnableLinearMetaLUT   = 0xB070BAA0;   ///< enableLinearMetaLUT
static const UINT32 StringHashEnableFDStreamInRealTime  = 0x7E5625B9;   ///< enableFDStreamInRealTime
static const UINT32 PropStringHashEnableFDStreamInRealTime  = 0xF8B8675F;   ///< enableFDStreamInRealTime
static const UINT32 StringHashSelectInSensorHDR3ExpUsecase  = 0x2615590F;   ///< selectInSensorHDR3ExpUsecase
static const UINT32 PropStringHashSelectInSensorHDR3ExpUsecase  = 0x087D37EB;   ///< selectInSensorHDR3ExpUsecase
static const UINT32 StringHashEnableUnifiedBufferManager  = 0x6790B9B0;   ///< enableUnifiedBufferManager
static const UINT32 PropStringHashEnableUnifiedBufferManager  = 0xDE9B23AB;   ///< enableUnifiedBufferManager
static const UINT32 StringHashEnableCHIImageBufferLateBinding  = 0xF56EFB80;   ///< enableCHIImageBufferLateBinding
static const UINT32 PropStringHashEnableCHIImageBufferLateBinding  = 0xE747216E;   ///< enableCHIImageBufferLateBinding
static const UINT32 StringHashEnableFeature2Dump        = 0x27469E3A;   ///< enableFeature2Dump
static const UINT32 PropStringHashEnableFeature2Dump    = 0x3CFF95A0;   ///< enableFeature2Dump
static const UINT32 StringHashForceHWMFFixedNumOfFrames  = 0x9C069C61;   ///< forceHWMFFixedNumOfFrames
static const UINT32 PropStringHashForceHWMFFixedNumOfFrames  = 0x41CEC0B1;   ///< forceHWMFFixedNumOfFrames
static const UINT32 StringHashEnableTBMChiFence         = 0x27697285;   ///< enableTBMChiFence
static const UINT32 PropStringHashEnableTBMChiFence     = 0xF7B4BAD9;   ///< enableTBMChiFence
static const UINT32 StringHashEnableMFSRChiFence        = 0xBF883559;   ///< enableMFSRChiFence
static const UINT32 PropStringHashEnableMFSRChiFence    = 0xA4313EC3;   ///< enableMFSRChiFence
static const UINT32 StringHashEnableRawHDR              = 0x911E6D8B;   ///< enableRawHDR
static const UINT32 PropStringHashEnableRawHDR          = 0xFFFA43E3;   ///< enableRawHDR
static const UINT32 StringHashFDProcessingControl       = 0xE46903AD;   ///< FDProcessingControl
static const UINT32 PropStringHashFDProcessingControl   = 0xCB9734D1;   ///< FDProcessingControl
static const UINT32 StringHashEnableFDManagerThreading  = 0xF5ADAA76;   ///< enableFDManagerThreading
static const UINT32 PropStringHashEnableFDManagerThreading  = 0x7343E890;   ///< enableFDManagerThreading
static const UINT32 StringHashFDBaseResolution          = 0x3772A6CF;   ///< FDBaseResolution
static const UINT32 PropStringHashFDBaseResolution      = 0xAD1605E1;   ///< FDBaseResolution
static const UINT32 StringHashFDConfigSource            = 0x50FAE19E;   ///< FDConfigSource
static const UINT32 PropStringHashFDConfigSource        = 0x9B5C78B6;   ///< FDConfigSource
static const UINT32 StringHashFDMultiCamProcess         = 0x190D23CB;   ///< FDMultiCamProcess
static const UINT32 PropStringHashFDMultiCamProcess     = 0x55994618;   ///< FDMultiCamProcess
static const UINT32 StringHashUseAlternateFrameSkip     = 0x557B5A12;   ///< useAlternateFrameSkip
static const UINT32 PropStringHashUseAlternateFrameSkip  = 0x084F9354;   ///< useAlternateFrameSkip
static const UINT32 StringHashUseDeviceOrientationInFD  = 0x6D17E94F;   ///< useDeviceOrientationInFD
static const UINT32 PropStringHashUseDeviceOrientationInFD  = 0x09B4C7D5;   ///< useDeviceOrientationInFD
static const UINT32 StringHashGetAccelInfoUsingVendorTag  = 0xF009E256;   ///< getAccelInfoUsingVendorTag
static const UINT32 PropStringHashGetAccelInfoUsingVendorTag  = 0x7CB38BC4;   ///< getAccelInfoUsingVendorTag
static const UINT32 StringHashAccelVendorTagSection     = 0x7A82E410;   ///< accelVendorTagSection
static const UINT32 PropStringHashAccelVendorTagSection  = 0x27B62D56;   ///< accelVendorTagSection
static const UINT32 StringHashAccelVendorTagName        = 0x9B3264D7;   ///< accelVendorTagName
static const UINT32 PropStringHashAccelVendorTagName    = 0x09BEDEBE;   ///< accelVendorTagName
static const UINT32 StringHashFDFilterEngine            = 0x3E7BDE5B;   ///< FDFilterEngine
static const UINT32 PropStringHashFDFilterEngine        = 0xF5DD4773;   ///< FDFilterEngine
static const UINT32 StringHashFDClient                  = 0xC0F51A9D;   ///< FDClient
static const UINT32 PropStringHashFDClient              = 0xE3D50C92;   ///< FDClient
static const UINT32 StringHashDisablePostingResults     = 0xC5170C04;   ///< disablePostingResults
static const UINT32 PropStringHashDisablePostingResults  = 0x862D03FA;   ///< disablePostingResults
static const UINT32 StringHashEnableOfflineFD           = 0x7E1A4D17;   ///< enableOfflineFD
static const UINT32 PropStringHashEnableOfflineFD       = 0x0AC9680E;   ///< enableOfflineFD
static const UINT32 StringHashMetadataVisibility        = 0xA4EBB8F5;   ///< MetadataVisibility
static const UINT32 PropStringHashMetadataVisibility    = 0x3667029C;   ///< MetadataVisibility
static const UINT32 StringHashUseDifferentTuningForFrontCamera  = 0xC39EB12A;   ///< useDifferentTuningForFrontCamera
static const UINT32 PropStringHashUseDifferentTuningForFrontCamera  = 0x60B02B4E;   ///< useDifferentTuningForFrontCamera
static const UINT32 StringHashUseFDInternalBuffers      = 0x5FD202EB;   ///< useFDInternalBuffers
static const UINT32 PropStringHashUseFDInternalBuffers  = 0x6D3BA4A1;   ///< useFDInternalBuffers
static const UINT32 StringHashUseFDUseCasePool          = 0xF3B00380;   ///< useFDUseCasePool
static const UINT32 PropStringHashUseFDUseCasePool      = 0x1536EDC2;   ///< useFDUseCasePool
static const UINT32 StringHashFastFDMetadata            = 0x867F2D5A;   ///< fastFDMetadata
static const UINT32 PropStringHashFastFDMetadata        = 0x16C68CE1;   ///< fastFDMetadata
static const UINT32 StringHashMinReqFdDependency        = 0xB525BECD;   ///< minReqFdDependency
static const UINT32 PropStringHashMinReqFdDependency    = 0x27A904A4;   ///< minReqFdDependency
static const UINT32 StringHashFDPreprocessing           = 0x35924188;   ///< FDPreprocessing
static const UINT32 PropStringHashFDPreprocessing       = 0x41416491;   ///< FDPreprocessing
static const UINT32 StringHashEnableFDPreprocessingAlways  = 0x6B9550A8;   ///< enableFDPreprocessingAlways
static const UINT32 PropStringHashEnableFDPreprocessingAlways  = 0x4FE74F55;   ///< enableFDPreprocessingAlways
static const UINT32 StringHashEnableFDPreprocessDumping  = 0x88727272;   ///< enableFDPreprocessDumping
static const UINT32 PropStringHashEnableFDPreprocessDumping  = 0x773B6EF5;   ///< enableFDPreprocessDumping
static const UINT32 StringHashAcceptAppUIFacialAttrSettings  = 0xA53740AD;   ///< acceptAppUIFacialAttrSettings
static const UINT32 PropStringHashAcceptAppUIFacialAttrSettings  = 0x6D48B43C;   ///< acceptAppUIFacialAttrSettings
static const UINT32 StringHashEnablePTDetection         = 0x3F232639;   ///< enablePTDetection
static const UINT32 PropStringHashEnablePTDetection     = 0xB8DC6F25;   ///< enablePTDetection
static const UINT32 StringHashEnableSMDetection         = 0x3F2C0639;   ///< enableSMDetection
static const UINT32 PropStringHashEnableSMDetection     = 0xB8D34F25;   ///< enableSMDetection
static const UINT32 StringHashEnableGBDetection         = 0x3F7DE639;   ///< enableGBDetection
static const UINT32 PropStringHashEnableGBDetection     = 0xB882AF25;   ///< enableGBDetection
static const UINT32 StringHashEnableCTDetection         = 0x3F6F2639;   ///< enableCTDetection
static const UINT32 PropStringHashEnableCTDetection     = 0xB8906F25;   ///< enableCTDetection
static const UINT32 StringHashFDThreadTaskAllocation    = 0x862D3D60;   ///< FDThreadTaskAllocation
static const UINT32 PropStringHashFDThreadTaskAllocation  = 0xBF22C3F2;   ///< FDThreadTaskAllocation
static const UINT32 StringHashEnableJPEGEXIFApp2        = 0xBC509A5A;   ///< enableJPEGEXIFApp2
static const UINT32 PropStringHashEnableJPEGEXIFApp2    = 0x2EDC2033;   ///< enableJPEGEXIFApp2
static const UINT32 StringHashExposeFullSizeForQCFA     = 0x63486E91;   ///< exposeFullSizeForQCFA
static const UINT32 StringHashUseFeatureForQCFA         = 0x3831501A;   ///< useFeatureForQCFA
static const UINT32 StringHashAECGainThresholdForQCFA   = 0x3861B978;   ///< AECGainThresholdForQCFA
static const UINT32 StringHashDisableFlash              = 0xFFFD8803;   ///< disableFlash
static const UINT32 PropStringHashDisableFlash          = 0x9119A66B;   ///< disableFlash
static const UINT32 StringHashEnableWatchdogRecovery    = 0x80B172CF;   ///< enableWatchdogRecovery
static const UINT32 PropStringHashEnableWatchdogRecovery  = 0x3910C95F;   ///< enableWatchdogRecovery
static const UINT32 StringHashNodeResponseTime          = 0x08F2D1A8;   ///< nodeResponseTime
static const UINT32 PropStringHashNodeResponseTime      = 0x41F9CC0C;   ///< nodeResponseTime
static const UINT32 StringHashSessionResponseTimePadding  = 0x057A6840;   ///< sessionResponseTimePadding
static const UINT32 PropStringHashSessionResponseTimePadding  = 0xBC71F25B;   ///< sessionResponseTimePadding
static const UINT32 StringHashSessionMaxFlushWaitTime   = 0xEB30DFDB;   ///< sessionMaxFlushWaitTime
static const UINT32 PropStringHashSessionMaxFlushWaitTime  = 0xDF07ADCC;   ///< sessionMaxFlushWaitTime
static const UINT32 StringHashSessionFallbackWaitTime   = 0x4C6284F3;   ///< sessionFallbackWaitTime
static const UINT32 PropStringHashSessionFallbackWaitTime  = 0x7855F6E4;   ///< sessionFallbackWaitTime
static const UINT32 StringHashFeature1                  = 0x857B47B8;   ///< feature1
static const UINT32 PropStringHashFeature1              = 0xC79DC156;   ///< feature1
static const UINT32 StringHashFeature2                  = 0x857B47BB;   ///< feature2
static const UINT32 PropStringHashFeature2              = 0xC79DC155;   ///< feature2
static const UINT32 StringHashRaisesigabrt              = 0x2CC85600;   ///< raisesigabrt
static const UINT32 PropStringHashRaisesigabrt          = 0x66FABFA6;   ///< raisesigabrt
static const UINT32 StringHashRaiserecoverysigabrt      = 0x9B45E394;   ///< raiserecoverysigabrt
static const UINT32 PropStringHashRaiserecoverysigabrt  = 0xA9AC45DE;   ///< raiserecoverysigabrt
static const UINT32 StringHashEnableRecovery            = 0x51CF7C7C;   ///< enableRecovery
static const UINT32 PropStringHashEnableRecovery        = 0x9A69E554;   ///< enableRecovery
static const UINT32 StringHashEnableAsciiLogging        = 0xB5CF33AA;   ///< enableAsciiLogging
static const UINT32 PropStringHashEnableAsciiLogging    = 0x274389C3;   ///< enableAsciiLogging
static const UINT32 StringHashEnableBinaryLogging       = 0x54D473B9;   ///< enableBinaryLogging
static const UINT32 PropStringHashEnableBinaryLogging   = 0x05433E8B;   ///< enableBinaryLogging
static const UINT32 StringHashOfflineLoggerMinFlushCnt  = 0xB212E762;   ///< offlineLoggerMinFlushCnt
static const UINT32 PropStringHashOfflineLoggerMinFlushCnt  = 0xD6B1C9F8;   ///< offlineLoggerMinFlushCnt
static const UINT32 StringHashEnableFenceDrop           = 0x60DF1939;   ///< enableFenceDrop
static const UINT32 PropStringHashEnableFenceDrop       = 0x140C3C20;   ///< enableFenceDrop
static const UINT32 StringHashInducerIsRealTime         = 0x87D490A0;   ///< inducerIsRealTime
static const UINT32 PropStringHashInducerIsRealTime     = 0xCB40F573;   ///< inducerIsRealTime
static const UINT32 StringHashInducerPipelineName       = 0x2A6B5FB3;   ///< inducerPipelineName
static const UINT32 PropStringHashInducerPipelineName   = 0x7BFC1281;   ///< inducerPipelineName
static const UINT32 StringHashInducerNodeName           = 0x75664234;   ///< inducerNodeName
static const UINT32 PropStringHashInducerNodeName       = 0x01B5672D;   ///< inducerNodeName
static const UINT32 StringHashInducerRequestId          = 0xCC713F3F;   ///< inducerRequestId
static const UINT32 PropStringHashInducerRequestId      = 0x56159C11;   ///< inducerRequestId
static const UINT32 StringHashInducerPortId             = 0xC0561D76;   ///< inducerPortId
static const UINT32 PropStringHashInducerPortId         = 0x860B29BF;   ///< inducerPortId
static const UINT32 StringHashInducerFenceMarkError     = 0xA828396A;   ///< inducerFenceMarkError
static const UINT32 PropStringHashInducerFenceMarkError  = 0xF51CF02C;   ///< inducerFenceMarkError
static const UINT32 StringHashSessionDumpForFlush       = 0x315E8BBA;   ///< sessionDumpForFlush
static const UINT32 PropStringHashSessionDumpForFlush   = 0x60C9C688;   ///< sessionDumpForFlush
static const UINT32 StringHashSessionDumpToLog          = 0xA2441B95;   ///< sessionDumpToLog
static const UINT32 PropStringHashSessionDumpToLog      = 0x3820B8BB;   ///< sessionDumpToLog
static const UINT32 StringHashSessionDumpToFile         = 0x48866BB1;   ///< sessionDumpToFile
static const UINT32 PropStringHashSessionDumpToFile     = 0x04120E62;   ///< sessionDumpToFile
static const UINT32 StringHashSessionDumpForRecovery    = 0x28138234;   ///< sessionDumpForRecovery
static const UINT32 PropStringHashSessionDumpForRecovery  = 0x8E8AAAFF;   ///< sessionDumpForRecovery
static const UINT32 StringHashDumpNodeProcessingInfo    = 0xC1E912ED;   ///< dumpNodeProcessingInfo
static const UINT32 PropStringHashDumpNodeProcessingInfo  = 0x67703A26;   ///< dumpNodeProcessingInfo
static const UINT32 StringHashDumpSessionProcessingInfo  = 0xA9FC2049;   ///< dumpSessionProcessingInfo
static const UINT32 PropStringHashDumpSessionProcessingInfo  = 0x3D99F305;   ///< dumpSessionProcessingInfo
static const UINT32 StringHashNumberOfCHIThreads        = 0xCCB173EB;   ///< numberOfCHIThreads
static const UINT32 StringHashUseVFETPG                 = 0xAA5328E6;   ///< useVFETPG
static const UINT32 PropStringHashUseVFETPG             = 0x95693EF9;   ///< useVFETPG
static const UINT32 StringHashIFEBufDoneTimeout         = 0xB6149662;   ///< IFEBufDoneTimeout
static const UINT32 PropStringHashIFEBufDoneTimeout     = 0xFA1A6AD2;   ///< IFEBufDoneTimeout
static const UINT32 StringHashIFEInputWidth             = 0x0DDC5373;   ///< IFEInputWidth
static const UINT32 PropStringHashIFEInputWidth         = 0xE21757B3;   ///< IFEInputWidth
static const UINT32 StringHashIFEInputHeight            = 0x854CA215;   ///< IFEInputHeight
static const UINT32 PropStringHashIFEInputHeight        = 0x7C2C3A08;   ///< IFEInputHeight
static const UINT32 StringHashIPEBufDoneTimeout         = 0xB6142662;   ///< IPEBufDoneTimeout
static const UINT32 PropStringHashIPEBufDoneTimeout     = 0xFA1ADAD2;   ///< IPEBufDoneTimeout
static const UINT32 StringHashIPEUnitTestIQBypassNumOfIteration  = 0x50508738;   ///< IPEUnitTestIQBypassNumOfIteration
static const UINT32 PropStringHashIPEUnitTestIQBypassNumOfIteration  = 0xACE0CB36;   ///< IPEUnitTestIQBypassNumOfIteration
static const UINT32 StringHashEnableImageBufferLateBinding  = 0x6DD7E808;   ///< enableImageBufferLateBinding
static const UINT32 PropStringHashEnableImageBufferLateBinding  = 0xD8C03068;   ///< enableImageBufferLateBinding
static const UINT32 StringHashMPMEnable                 = 0x8CD16B7E;   ///< MPMEnable
static const UINT32 PropStringHashMPMEnable             = 0x5F9DFF1B;   ///< MPMEnable
static const UINT32 StringHashMPMValidateMemPoolGroup   = 0xF0A0FFF7;   ///< MPMValidateMemPoolGroup
static const UINT32 PropStringHashMPMValidateMemPoolGroup  = 0x3981ECC3;   ///< MPMValidateMemPoolGroup
static const UINT32 StringHashMPMDoNotGroupBufferManagers  = 0x04A164F1;   ///< MPMDoNotGroupBufferManagers
static const UINT32 PropStringHashMPMDoNotGroupBufferManagers  = 0xB5A9DE2B;   ///< MPMDoNotGroupBufferManagers
static const UINT32 StringHashMPMKeepMinNumFreeBuffers  = 0x125E33DB;   ///< MPMKeepMinNumFreeBuffers
static const UINT32 PropStringHashMPMKeepMinNumFreeBuffers  = 0x74634925;   ///< MPMKeepMinNumFreeBuffers
static const UINT32 StringHashMPMAllocateBuffersOnRegister  = 0x7ED38F5D;   ///< MPMAllocateBuffersOnRegister
static const UINT32 PropStringHashMPMAllocateBuffersOnRegister  = 0x9775C56F;   ///< MPMAllocateBuffersOnRegister
static const UINT32 StringHashMPMGroupIfExactDeviceMatch  = 0x99499D5A;   ///< MPMGroupIfExactDeviceMatch
static const UINT32 PropStringHashMPMGroupIfExactDeviceMatch  = 0x15F3F4C8;   ///< MPMGroupIfExactDeviceMatch
static const UINT32 StringHashMPMMinSizeForSharing      = 0xF77E567C;   ///< MPMMinSizeForSharing
static const UINT32 PropStringHashMPMMinSizeForSharing  = 0xC597F036;   ///< MPMMinSizeForSharing
static const UINT32 StringHashMPMSizeDiffAllowedToGroup  = 0xD98BBD05;   ///< MPMSizeDiffAllowedToGroup
static const UINT32 PropStringHashMPMSizeDiffAllowedToGroup  = 0xD40A3981;   ///< MPMSizeDiffAllowedToGroup
static const UINT32 StringHashMPMLargeGroupSizeDefinition  = 0x4A6758BD;   ///< MPMLargeGroupSizeDefinition
static const UINT32 PropStringHashMPMLargeGroupSizeDefinition  = 0x08F0386F;   ///< MPMLargeGroupSizeDefinition
static const UINT32 StringHashMPMSizeDiffAllowedToGroupOverride  = 0xC6A5AE59;   ///< MPMSizeDiffAllowedToGroupOverride
static const UINT32 PropStringHashMPMSizeDiffAllowedToGroupOverride  = 0x47212A54;   ///< MPMSizeDiffAllowedToGroupOverride
static const UINT32 StringHashMPMBufferAddressAlignment  = 0x61DF8963;   ///< MPMBufferAddressAlignment
static const UINT32 PropStringHashMPMBufferAddressAlignment  = 0xB5E86705;   ///< MPMBufferAddressAlignment
static const UINT32 StringHashForceCHIBufferManagerHeap  = 0x2D88246B;   ///< forceCHIBufferManagerHeap
static const UINT32 PropStringHashForceCHIBufferManagerHeap  = 0x81C3C1E8;   ///< forceCHIBufferManagerHeap
static const UINT32 StringHashMPMSelfTuneImmediateCount  = 0xD3737A52;   ///< MPMSelfTuneImmediateCount
static const UINT32 PropStringHashMPMSelfTuneImmediateCount  = 0x4716A91E;   ///< MPMSelfTuneImmediateCount
static const UINT32 StringHashEnableMPMMonitorThread    = 0x8D6B772D;   ///< enableMPMMonitorThread
static const UINT32 PropStringHashEnableMPMMonitorThread  = 0x2BF25FE6;   ///< enableMPMMonitorThread
static const UINT32 StringHashMPMMonitorTimeInterval    = 0x4C4C9AF1;   ///< MPMMonitorTimeInterval
static const UINT32 PropStringHashMPMMonitorTimeInterval  = 0xEAD5B23A;   ///< MPMMonitorTimeInterval
static const UINT32 StringHashMPMMonitorSelfShrinkSizeLimit  = 0x55634264;   ///< MPMMonitorSelfShrinkSizeLimit
static const UINT32 PropStringHashMPMMonitorSelfShrinkSizeLimit  = 0x61AA0439;   ///< MPMMonitorSelfShrinkSizeLimit
static const UINT32 StringHashEnableMPMStatelogging     = 0xB8314B54;   ///< enableMPMStatelogging
static const UINT32 PropStringHashEnableMPMStatelogging  = 0xE5058212;   ///< enableMPMStatelogging
static const UINT32 StringHashEnableMemoryStats         = 0x86552C15;   ///< enableMemoryStats
static const UINT32 PropStringHashEnableMemoryStats     = 0xCAC149C6;   ///< enableMemoryStats
static const UINT32 StringHashMPMMinSizeToFreeOnDeactivate  = 0x1C211758;   ///< MPMMinSizeToFreeOnDeactivate
static const UINT32 PropStringHashMPMMinSizeToFreeOnDeactivate  = 0xF5875D6A;   ///< MPMMinSizeToFreeOnDeactivate
static const UINT32 StringHashValidateImageBufferUsageState  = 0x11D9CAE4;   ///< validateImageBufferUsageState
static const UINT32 PropStringHashValidateImageBufferUsageState  = 0x25108CB9;   ///< validateImageBufferUsageState
static const UINT32 StringHashMPMSizeThresToDisableDelayedUnmap  = 0x8186475D;   ///< MPMSizeThresToDisableDelayedUnmap
static const UINT32 PropStringHashMPMSizeThresToDisableDelayedUnmap  = 0xE4550BC9;   ///< MPMSizeThresToDisableDelayedUnmap
static const UINT32 StringHashMPMForceDisableDelayedUnmap  = 0x9F846966;   ///< MPMForceDisableDelayedUnmap
static const UINT32 PropStringHashMPMForceDisableDelayedUnmap  = 0x08C95B37;   ///< MPMForceDisableDelayedUnmap
static const UINT32 StringHashMPMSizeThresToDelayedMap  = 0xD870DF60;   ///< MPMSizeThresToDelayedMap
static const UINT32 PropStringHashMPMSizeThresToDelayedMap  = 0xE4550BC9;   ///< MPMSizeThresToDelayedMap
static const UINT32 StringHashDumpAF                    = 0xCF674C46;   ///< dumpAF
static const UINT32 StringHashDumpAEC                   = 0xECE988DA;   ///< dumpAEC
static const UINT32 StringHashDumpAWB                   = 0xECE98A9B;   ///< dumpAWB
static const UINT32 StringHashDumpAFDRowsum             = 0x99F020E2;   ///< dumpAFDRowsum
static const UINT32 StringHashProfile3A                 = 0x0AA7E18A;   ///< profile3A
static const UINT32 PropStringHashProfile3A             = 0x56773C42;   ///< profile3A

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Type Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Enumerates CSL mode types
enum CSLModeType
{
    CSLModeHardware,                        ///< Hardware CSL implementation, using the standard CamX KMD and hardware
    CSLModeIFH,                             ///< Infinitely Fast Hardware CSL implementation, bypassing the KMD
    CSLModePresil,                          ///< Presil CSIM CSL Implementation
    CSLModePresilRUMI,                      ///< Presil RUMI CSL Implementation
};

/// List of HAF algorithm that can be enabled overriding tuning
enum EnableAFAlgoType
{
    EnableAFAlgoDisabled,                   ///< AF algorithm tuning override is disabled
    EnableAFAlgoPDAF,                       ///< Override tuning and enable only PDAF
    EnableAFAlgoTOF,                        ///< Override tuning and enable only TOF
    EnableAFAlgoDCIAF,                      ///< Override tuning and enable only DCIAF
    EnableAFAlgoCAF,                        ///< Override tuning and enable only CAF
};

/// Enumerates AF fullsweep types
enum AFFullsweepType
{
    AFFullsweepDisabled,                    ///< AF fullsweep is disabled
    AFFullsweepInfinityToMacro,             ///< Performs fullsweep starting from Infinity to Macro
    AFFullsweepMacroToInfinity,             ///< Performs fullsweep starting from Macro to Infinity
    AFFullsweepBothDirection,               ///< Performs fullsweep starting from Infinity to Macro and back
};

/// Enumerates type of AF manual lens control
enum AFManualLensControlType
{
    AFManualLensControlDisabled,            ///< Manual lens control is disabled
    AFManualLensControlDAC,                 ///< Move lens manually using DAC value
    AFManualLensControlLogical,             ///< Move lens manually giving logical lens position
};

/// Enumerates type of multi camera 3A sync scheme
enum MultiCamera3ASyncType
{
    MultiCamera3ASyncDisabled,              ///< No 3A sync
    MultiCamera3ASyncQTI,                   ///< QTI standard 3A sync solution
    MultiCamera3ASyncSingleton,             ///< 3A sync solution with only one algorithm instance
};

/// Used as a mask to enable the HW Sync
enum MultiCameraHWSyncType
{
    MultiCameraHWSyncDisabled = 0x0,        ///< Disable the HW sync
    MultiCameraHWSyncRTB = 0x1,             ///< Enable the HW Sync for RTB usecase
    MultiCameraHWSyncSAT = 0x2,             ///< Enable the HW Sync for SAT usecase
    MultiCameraHWSyncVR = 0x4,              ///< Enable the HW Sync for VR usecase
};

/// Enumerates output format types
enum OutputFormatType
{
    OutputFormatYUV420NV12,                 ///< Linear NV12 format
    OutputFormatUBWCNV12,                   ///< UBWC NV12 format
    OutputFormatUBWCTP10,                   ///< UBWC TP10 format
    OutputFormatRAWPLAIN16,                 ///< Raw Plain16 format
    OutputFormatPD10,                       ///< PD10 format
    OutputFormatP010,                       ///< LinerP010 format
    OutputFormatYUV420NV21,                 ///< Linear NV21 format
    OutputFormatRAWPLAIN64,                 ///< Raw Plain64 format
};

/// Enumerates Ref output format types
enum RefOutputFormatType
{
    RefOutputFormatUBWCTP10,                ///< UBWC TP10 format
    RefOutputFormatUBWCNV124R,              ///< UBWCNV124R format
    RefOutputFormatYUV420NV12,              ///< Linear NV12 format
    RefOutputFormatYUV420NV12TP10,          ///< Linear NV12 format
    RefOutputFormatP010,                    ///< LinerP010 format
};

/// Enumerates FD processing controls
enum FDProcessingControlType
{
    FDProcessingControlForceDisable,        ///< Force disable FD processing
    FDProcessingControlForceEnable,         ///< Force enable FD processing
    FDProcessingControlAppRequest,          ///< Enable/Disable FD processing based on App request
};

/// FD base resolutions, 0:15 width 16:32 height
enum FDBaseResolutionType
{
    FDBaseResolution640x480 = 31457920,     ///< FD base resolution width 640 height 480
    FDBaseResolution854x480 = 31458134,     ///< FD base resolution width 854 height 480
    FDBaseResolution320x240 = 15728960,     ///< FD base resolution width 320 height 240
    FDBaseResolution427x240 = 15729067,     ///< FD base resolution width 427 height 240
};

/// Enumerates FD config source types
enum FDConfigSourceType
{
    FDConfigDefault,                        ///< Fetch default configuration
    FDConfigVendorTag,                      ///< Fetch configuration from vendor tag
    FDConfigBinary,                         ///< Fetch configuration from tunning binary
};

/// Processing criteria in multi-cam when both running
enum FDMultiCamProcessingType
{
    FDMultiCamProcessMasterOnly,            ///< Process only master requests at full fps
    FDMultiCamProcessAuxOnly,               ///< Process only aux requests at full fps
    FDMultiCamProcessBoth,                  ///< Process both master and aux at half fps
};

/// Enumerates FD filter engine types
enum FDFilterEngineType
{
    FD_Standard_ARM,                        ///< Use FD_Standard_ARM as FD filter
    FD_Standard_DSP,                        ///< Use FD_Standard_DSP as FD filter
    FD_DL_ARM,                              ///< Use FD_DL_ARM as FD filter
    FD_DL_DSP,                              ///< Use FD_DL_DSP as FD filter
    FD_DL_DSP_and_Standard_ARM,             ///< Use FD_DL_DSP and supplement with FD_Standard_ARM when certain conditions are met
};

/// Enumerates FD Client types
enum FDClientType
{
    FDHWHybrid,                             ///< Use FD HW as FD Client
    FDSWOnly,                               ///< Use FD SW as FD Client
};

/// Enumerates FD pre-processing types
enum FDPreProcessingType
{
    Disable,                                ///< Disable FD pre-processing
    AdaptiveGTM,                            ///< Adaptive Tone Map preprocessing
    GTM,                                    ///< Global Tone Map preprocessing
    LTM,                                    ///< Local Tone Map preprocessing
};

/// Enumerates FD thread task allocation types
enum FDThreadTaskAllocationType
{
    PTDOnPriThread,                         ///< Run PTD on the primary worker thread of FD Manager Node
    PTDOnSecThread,                         ///< Run PTD on the secondary worker thread of FD Manager Node
};

/// Used as a mask to enable image dumps for specific nodes
enum ImageDumpType
{
    ImageDumpNone = 0x0,                    ///< No dumps
    ImageDumpIFE = 0x1,                     ///< All output ports for IFE
    ImageDumpIPE = 0x2,                     ///< All output ports for IPE
    ImageDumpBPS = 0x4,                     ///< All output ports for BPS
    ImageDumpJPEG = 0x8,                    ///< All JPEG output ports for all JPEG nodes
    ImageDumpFDHw = 0x10,                   ///< All output ports for FDHw
    ImageDumpLRME = 0x20,                   ///< All output ports for LRME
    ImageDumpRANSAC = 0x40,                 ///< All output ports for RANSAC
    ImageDumpChiNode = 0x80,                ///< All output ports for all ChiNodes
    ImageDumpCVP = 0x100,                   ///< All output ports for CVP
    ImageDumpMisc = 0x40000000,             ///< All other nodes not explicitly listed above
};

/// Dual LED Calibration modes
enum DualLEDCalibrationType
{
    DualLEDCalibrationDisabled,             ///< Dual LED Calibration is disabled
    DualLEDCalibrationTuning,               ///< Dual LED is being tuned for the golden module
    DualLEDCalibrationCalibration,          ///< Dual LED is being calibrated
};

/// Enumerates CHI Partial Data types
enum CHIPartialDataType
{
    CHIPartialDataDisable,                  ///< CHI Partial Data will be disabled
    CHIPartialDataSeparate,                 ///< CHI Partial Data will be sent separately
    CHIPartialDataCombined,                 ///< CHI Partial Data will be sent along with Core Partial Data
};

/// Enumerates alignment fusion modes
enum AlignmentFusionModes
{
    AlignImageBaseOnly,                     ///< Alignment based on image only
    AlignGyroBaseOnly,                      ///< Alignment based on gyro only
    AlignAuto,                              ///< Alignment auto, default option
};

/// @brief Maps an enumerator to its hash value
struct EnumeratorToHashMap
{
    UINT32  enumeratorStringHash;   ///< The hash value used for obfuscation
    INT     enumerator;             ///< The numerical value of the enumerator
};

/// @brief Encapsulates all  static settings values
struct StaticSettings
{
    AFFullsweepType         afFullsweep;                        ///< Enable/Disable Full-sweep Mode
                                                                ///< Disabled:         FullSweep mode is off,
                                                                ///< InfinityToMacro:  FullSweep mode is far to near end,
                                                                ///< MacroToInfinity:  FullSweep mode is near to far end,
                                                                ///< BothDirection:    Fullsweep mode is dual direction
    AFManualLensControlType manualAf;                           ///< Enable/Disable Manual Lens Control
                                                                ///< Disabled: Disable Manual Lens Movement,
                                                                ///< DAC:      Enable Control via DAC,
                                                                ///< Logical:  Enable Control via Logical Position
    AlignmentFusionModes    alignmentFusionMode;                ///< This is to indicate MCTF alignment fusion mode
    BIT                     DisableManual3ACCM:1;               ///< Disable the support to consume manual 3A CCM update
    BIT                     IsOEMStatSettingEnable:1;           ///< Use the Stats Configuration data provided by OEM
    BIT                     IsStrideSettingEnable:1;            ///< Use the Stride Configuration data provided by OEM
    BIT                     MPMAllocateBuffersOnRegister:1;     ///< Allocates buffers at the time of register
    BIT                     MPMDoNotGroupBufferManagers:1;      ///< Each Buffer manager will have its own group, no sharing of buffers among Buffer Managers
    BIT                     MPMEnable:1;                        ///< Whether to use Memory Pool Manager for image buffer allocations
    BIT                     MPMForceDisableDelayedUnmap:1;      ///< Disable Delayed Unamp feature while mapping to SMMU for all buffers
    BIT                     MPMGroupIfExactDeviceMatch:1;       ///< Share buffers among Buffer Managers having exact list of devices to map.
                                                                ///< Valid only if MPMDoNotGroupBufferManagers is FALSE
                                                                ///< If Grouping and MPMGroupIfExactDeviceMatch is enabled : Buffer managers will share buffers only if
                                                                ///< the Buffer Managers needs buffers that needs to be mapped to exact same devices.
                                                                ///< If Grouping is enabled and MPMGroupIfExactDeviceMatch is disabled : Device list is not considered to
                                                                ///< decide whether Buffer Managers can share buffers. Buffers will be mapped to all devices that are
                                                                ///< required by both the Buffer Managers.
    BIT                     MPMSelfTuneImmediateCount:1;        ///< When enabled, immediate count configured in Buffer Manager create data is ignored and self tuned
                                                                ///< based on different link properties (node type, real time/offline pipeline, etc)
    BIT                     MPMValidateMemPoolGroup:1;          ///< Verifies whether input MemPoolGroup handle exists in the list
    BIT                     MetadataVisibility:1;               ///< Enable/Disable framework metadata optimization
    BIT                     acceptAppUIFacialAttrSettings:1;    ///< Whether to accept App UI settings of facial atttibutes detection or not
                                                                ///< Valid only when FD is enabled
                                                                ///< TRUE  - Accept App UI settings
                                                                ///< FALSE - Ignore App UI settings
    BIT                     autoImageDump:1;                    ///< Dumps output images for all enabled nodes. This will run extremely slow
    BIT                     bypassIPEICADependency:1;           ///< Bypass IPE ICA dependency
    BIT                     capResolutionForSingleIFE:1;        ///< When enabled, available stream resolution will be cap within single IFE supported range
    BIT                     chiOverrideEnable:1;                ///< Enable/Disable CHI Override path
    BIT                     debugBufferRegDumpEnable:1;         ///< Whether or not UMD sends a buffer to KMD for resgister dump logging
    BIT                     debugDataOfflineAlloc:1;            ///< Setting this to TRUE will allocate debug-data for offline sessions.
                                                                ///< Disabling allocation for offline sessions, reduce memory usage. For usecases where realtime session is available,
                                                                ///< offline debug-data is not required in the metadata. Deep-copy and allocation takes place already by the framework
    BIT                     disableADRC:1;                      ///< Enables/Disables ADRC
    BIT                     disableAFAWBpreFlash:1;             ///< Flag to disable AF and AWB preflash states
    BIT                     disableAFAlgoCHIOverload:1;         ///< Enables/Disables  Algo CHI Overload
    BIT                     disableAFDAlgoCHIOverload:1;        ///< Enables/Disables AFD Algo CHI Overload
    BIT                     disableAFDStatsProcessing:1;        ///< Enables/Disables AFD Stats Processing
    BIT                     disableAFStatsProcessing:1;         ///< Enables/Disables AF Stats Processing
    BIT                     disableASDAlgoCHIOverload:1;        ///< Enables/Disables ASD Algo CHI Overload
    BIT                     disableAWBAlgoCHIOverload:1;        ///< Enables/Disables AWB Algo CHI Overload
    BIT                     disableAWBStatsProcessing:1;        ///< Enables/Disables AWB Stats Processing
    BIT                     disableBGStatsForAF:1;              ///< Disable Reading BG Stats for AF
    BIT                     disableCVPDriver:1;                 ///< This is to disable CVP driver
    BIT                     disableDRQPreemptionOnStopRecord:1; ///< Disables DRQ preemption on stop record
    BIT                     disableFlash:1;                     ///< Disables Flash
    BIT                     disableFocusIndication:1;           ///< Enable/Disable Focus Circle for Depth Based Algorithm
    BIT                     disableIPEInternalDownscale:1;      ///< Disable IPE's way to generate downscale ports internally
    BIT                     disablePDAF:1;                      ///< Completely disable PDAF
    BIT                     disablePDLibCHIOverload:1;          ///< Enables/Disables Library CHI Overload
    BIT                     disablePDLibLCR:1;                  ///< Enable/Disable PD Library LCR
    BIT                     disablePostingResults:1;            ///< Enable/Disable posting FD results to metadata, property
    BIT                     disablePreFlashOnForTouchAE:1;      ///< Turn on preflash over touch AE in always flash or auto flash mode
    BIT                     disablePreviewManualExpTime:1;      ///< Enables/Disables Exposure Time Priority
    BIT                     disablePreviewManualFull:1;         ///< Complete Manual
    BIT                     disablePreviewManualISO:1;          ///< Enables/Disables ISO Priority
    BIT                     disableSpeckleDetection:1;          ///< Enables/Disables Speckle Detection
    BIT                     disableVideoPerfModeSetting:1;      ///< Disables video perf mode setting
    BIT                     dualBHistSupport:1;                 ///< Enable Dual BHist Support
    BIT                     dumpAFDRowsum:1;                    ///< If flag is enabled then row sum stats will be dumped into mobile device.
                                                                ///< To enable/disable dump, use below flag values.
                                                                ///< TRUE:  Enable dump
                                                                ///< FALSE: Disable dump
    BIT                     dumpCVPICAInputConfig:1;            ///< Enable the CVP ICA input config dump
    BIT                     dumpGeolibResult:1;                 ///< Enable the Geolib result dump in BPS, IPE, EVA(formal CVP)
    BIT                     dumpIPEFirmwarePayload:1;           ///< Enables/Disables dumping of IPE command buffers which represent payload sent to firmware
    BIT                     dumpInputatOutput:1;                ///< Dumps input port when output port is dumped. This will run extremely slow
    BIT                     dumpNodeProcessingInfo:1;           ///< Dumps basic stats about node processing time to logcat
    BIT                     dumpSensorEEPROMData:1;             ///< Enables/Disables dumping of EEPROM data
    BIT                     dumpSensorEmulationOutput:1;        ///< Enables/Disables dumping of emulated sensor output
    BIT                     dumpSessionProcessingInfo:1;        ///< Dumps basic stats about session request processing time to logcat
    BIT                     dynamicImageDump:1;                 ///< Triggers an image dump only when org.codeaurora.qcamera3.hal_private_data.debug_image_dump is TRUE
                                                                ///< in a request, or if the dynamicImageDumpTrigger property is toggled to TRUE.  This Setting must be
                                                                ///< set to TRUE to enable debug_image_dump, or dynamicImageDumpTrigger to dump images per request.
    BIT                     dynamicImageDumpTrigger:1;          ///< If dynamicImageDump == TRUE, a set of images per request is dumped when this property is toggled to TRUE.
                                                                ///< For now, dumps continue until it is reset to FALSE.  In the future, this may be a true trigger which
                                                                ///< resets itself
    BIT                     dynamicInlineCalibration:1;         ///< Enables/Disables dynamic inline LED Calibration
    BIT                     dynamicPropertiesEnabled:1;         ///< Properties can be dynamically updated and read per processRequest
    BIT                     enable3ADebugData:1;                ///< General switch to enable 3A debug data. See size settings to set a new size or use default.
    BIT                     enableActiveIFEABVote:1;            ///< Enable AB votes computed based on active IFE output dimensions
    BIT                     enableBPSStripeDump:1;              ///< Enables/Disables dumping of BPS striping debug information
    BIT                     enableCSIDBinning:1;                ///< Enables/Disables CSID binning
    BIT                     enableCTDetection:1;                ///< Enable/Disable facial contour detection (AKA dense landmark)
                                                                ///< Valid only when FD and facial parts detection are enabled
                                                                ///< TRUE  - Enable facial contour detection
                                                                ///< FALSE - Disable
    BIT                     enableCustomAlgoAEC:1;              ///< Enable/Disable custom AEC algo
    BIT                     enableCustomAlgoAF:1;               ///< Enable/Disable custom AF algo
    BIT                     enableCustomAlgoAFD:1;              ///< Enable/Disable custom AFD algo
    BIT                     enableCustomAlgoASD:1;              ///< Enable/Disable custom ASD algo
    BIT                     enableCustomAlgoAWB:1;              ///< Enable/Disable custom AWB algo
    BIT                     enableCustomHAFAlgo:1;              ///< Enable/Disable custom HAF algo
    BIT                     enableCustomPDLib:1;                ///< Enable/Disable custom PD Library
    BIT                     enableDualIFE:1;                    ///< Used to control if dual IFE mode is allowed
    BIT                     enableExternalSensorModule:1;       ///< Enables/Disables external sensor module
    BIT                     enableFDManagerThreading:1;         ///< Enable/Disable FD Manager threading
    BIT                     enableFDPreprocessDumping:1;        ///< Dump input and output frames of preprocessing and profile processing time
                                                                ///< TRUE  - Enable frame dumping, profiling
                                                                ///< FALSE - Disable
    BIT                     enableFDPreprocessingAlways:1;      ///< Valid only if FDPreprocessing is not Disable
                                                                ///< TRUE  - Enable preprocessing on all requests
                                                                ///< FALSE - Selectively enable preprocessing, exa - enable only on low light scenes
    BIT                     enableFPSLog:1;                     ///< Enables printing of FPS to logs
    BIT                     enableFenceDrop:1;                  ///< Enable Inducer Flag
    BIT                     enableFlashDebug:1;                 ///< Bypass 3A block so flash always fire base on the captureIntent from application
    BIT                     enableGBDetection:1;                ///< Enable/Disable gaze and blink detection
                                                                ///< Valid only when FD and facial parts detection are enabled
                                                                ///< TRUE  - Enable gaze and blink detection
                                                                ///< FALSE - Disable
    BIT                     enableHALFormatOverride:1;          ///< Enable/Disable HAL format override
    BIT                     enableHJAF:1;                       ///< Enable HJ AF
    BIT                     enableHVXStreaming:1;               ///< Used to control HVX streaming
    BIT                     enableIFERegDump:1;                 ///< Enables the Per frame IFE register dump
    BIT                     enableIPEDependencies:1;            ///< Enable Dependencies in IPE to request AAA Stats and IFE Information
    BIT                     enableIPEIQLogging:1;               ///< This is to enable the debug log in the IPE IQ module
    BIT                     enableIPEOnlyDownscale:1;           ///< Enable IPE to request a certain resolution to downscale
    BIT                     enableIPEScratchBufferDump:1;       ///< Enables/Disables dumping of IPE Scratch buffer
    BIT                     enableIPEStripeDump:1;              ///< Enables/Disables dumping of IPE striping debug information
    BIT                     enableIPEUpscale:1;                 ///< Enable IPE to request a smaller input resolution to upscale
    BIT                     enableImageBufferLateBinding:1;     ///< Wheter to enable late bind of memory/buffers to ImageBuffer
    BIT                     enableInternalHALPixelStreamConfig:1; ///< Enables/Disables Internal HAL Pixel Stream Configuration
    BIT                     enableJPEGEXIFApp2:1;               ///< Enable/Disable JPEG EXIF App2
    BIT                     enableLDC:1;                        ///< enable Lens distortion correction
    BIT                     enableLRMEDS2:1;                    ///< Enable LRME DS2 link.  FALSE to disable, TRUE to enable
    BIT                     enableLensSagComp:1;                ///< Enable Lens Sag Compensation
    BIT                     enableLinearMetaLUT:1;              ///< Enable linear LUT for metadata operations
    BIT                     enableMCTF:1;                       ///< This is to enable LRME/Ransac dependancies for MCTF
    BIT                     enableMPMMonitorThread:1;           ///< Whether to enable Memory Pool Manager monitor thread
    BIT                     enableMPMStatelogging:1;            ///< Whether to enable more debug logging printing state of Buffers, Buffer Managers, Groups
                                                                ///< at different stages of their lifecycle.
    BIT                     enableMemoryStats:1;                ///< When enabled, memory statistics are tracked and printed for CmdBuffers, Memory Pool Manager
    BIT                     enableNCSService:1;                 ///< Enables/Disable NCS service
    BIT                     enableNativeHEIF:1;                 ///< Enable/Disable native HEIF
    BIT                     enableOISOptimization:1;            ///<  Enable OIS Optimization
    BIT                     enableOfflineFD:1;                  ///< Enable/Disable offline FD processing
    BIT                     enablePDLibProfiling:1;             ///< Enable/Disable PD Library Profiling
    BIT                     enablePTDetection:1;                ///< Enable/Disable facial parts detection (AKA sparse landmark or landmark)
                                                                ///< Valid only when FD is enabled
                                                                ///< TRUE  - Enable facial parts detection
                                                                ///< FALSE - Disable
    BIT                     enablePipelineFlush:1;              ///< Flush a given pipeline in the Session
    BIT                     enableQTimer:1;                     ///< Enable/Disable QTimer for SOF timestamps
    BIT                     enableRAWProcessing:1;              ///< Enables/Disables RAW Processing
    BIT                     enableRecovery:1;                   ///< Enable Recovery
    BIT                     enableResourceManager:1;            ///< Enable/Disable CamX Resource Manager
    BIT                     enableSMDetection:1;                ///< Enable/Disable smile detection
                                                                ///< Valid only when FD and facial parts detection are enabled
                                                                ///< TRUE  - Enable smile detection
                                                                ///< FALSE - Disable
    BIT                     enableSPD:1;                        ///< Disable Spotlight Detection
    BIT                     enableSensorAcquireOptimization:1;  ///< Enables optimization during sensor acquire by offloading the call
    BIT                     enableSensorCaching:1;              ///<  Enable Sensor Handle Caching
    BIT                     enableSensorEmulation:1;            ///< Enables/Disables sensor emulation
    BIT                     enableSensorFpsMatch:1;             ///< Enable/Disable multi camera fps match
    BIT                     enableStreamCropZoom:1;             ///< Enable/Disable zoom to use PSM stream crop info
    BIT                     enableTOFInterface:1;               ///< Enables/Disable TOF interface
    BIT                     enableTPG:1;                        ///< Enables/Disables IFE or CSID TPG
    BIT                     enableThermalMitigation:1;          ///< Enables/Disable thermal mitigation
    BIT                     enableTouchToTrack:1;               ///< Enable Touch to Track feature
    BIT                     enableTuningMetadata:1;             ///< General switch to enable tuning data dump. See size settings to set a new size or use default.
    BIT                     enableUBWCNV124ROnIFEFullOutIPELink:1; ///< When enabled, will always use UBWCNV124R (8 bit) on IFE FullOut --> IPE link
    BIT                     enableWatchdogRecovery:1;           ///< Induce recovery if continuous invalid SOF occurs and hits set threshold
    BIT                     exportSecureCamera:1;               ///< Export the secure camera for IR camera application
    BIT                     exposeFullSizeForQCFA:1;            ///< Expose Full Size for Quad CFA Sensor
    BIT                     extendedTimeForLongExposure:1;      ///< Enable/Disable extended timeout for Long Exposure
    BIT                     fastFDMetadata:1;                   ///< Determine when the FD metadata is returned
                                                                ///< TRUE  - Return metadata after IFE completes hw submission
                                                                ///< FALSE - Defer to the point when buffers return for the request
    BIT                     force3ALockedResult:1;              ///< Always returns locked in results, regardless of the actual algo state
    BIT                     force8BitUBWCAlignment:1;           ///< Force enable 8bit alignment for UBWC
    BIT                     forceDebugQCFASWRemosaic:1;         ///<  Force Enable QuadCFA and SW Remosaic in Sensor Capability for Debug/Test purposes only
    BIT                     forceDisableUBWCOnIfeIpeLink:1;     ///< When enabled, will always use YUV420NV12 on IFE output and follow-up links
    BIT                     forceDualIFEOn:1;                   ///< Forces dual IFE mode on
    BIT                     getAccelInfoUsingVendorTag:1;       ///< Get Accelerometer info using vendor tag
    BIT                     ifeSWCDMEnable:1;                   ///< Enables SW CDM for IFE
    BIT                     ignoreSceneMode:1;                  ///< If true, InputControlSceneMode is ignored, and scene mode is reported as disabled
    BIT                     inducerFenceMarkError:1;            ///< Fence will be mark as error by inducer
    BIT                     inducerIsRealTime:1;                ///< Trigger inducer in realtime system
    BIT                     isGridFromChromatixEnabled:1;       ///< This is to enable IPE fetch grid from chromatix
    BIT                     kpiDebug:1;                         ///< Enable/Disable Systrace Logs
    BIT                     logDRQEnable:1;                     ///< Enable DRQ logging
    BIT                     logMetaEnable:1;                    ///< Enable Metadata logging
    BIT                     logRequestMapping:1;                ///< Write request mappings to the log
    BIT                     manualExposureType:1;               ///< Enable/Disable Manual Exposure Control
    BIT                     manualWhiteBalanceType:1;           ///< Enable/Disable Manual White Balance Control
    BIT                     multiCameraEnable:1;                ///< Enable/Disable multi camera framework with Back Aux camera
    BIT                     multiCameraEnableFront:1;           ///< Enable/Disable multi camera framework with Front Main camera
    BIT                     mwEnable:1;                         ///< Enable/Disable Multi-window PDAF
    BIT                     offlineImageDumpOnly:1;             ///< Dumps offline processing output images for all enabled nodes. This will run extremely slow
    BIT                     overrideForceFSCapable:1;           ///< Mark the sensor as FS capable inspite of having no explicit FS mode
    BIT                     pdafHWEnable:1;                     ///< Enable PDAF HW enable/disable setting.
    BIT                     perFrameSensorMode:1;               ///< Update the sensor mode index per frame
    BIT                     raiserecoverysigabrt:1;             ///< Raise recovery sigabrt for debug builds to track critical failures
    BIT                     raisesigabrt:1;                     ///< Raise sigabrt for debug builds to track critical failures
    BIT                     reprocessDump:1;                    ///< Dumps reprocess input image and metadata
    BIT                     sessionDumpForFlush:1;              ///< Dumps session info if in error state at Flush
    BIT                     sessionDumpForRecovery:1;           ///< Dumps session to logcat if in recovery state
    BIT                     sessionDumpToFile:1;                ///< Dumps session to file if in error state
    BIT                     sessionDumpToLog:1;                 ///< Dumps session to logcat if in error state
    BIT                     spotlightFallbackToCAF:1;           ///< Enable/Disable Fallback to Contrast AF for Spotlight Scene
    BIT                     systemLogEnable:1;                  ///< Controls if CamX logs are output to the system logging mechanism
    BIT                     tintlessEnable:1;                   ///< Enables tintless algorithm
    BIT                     traceErrorEnable:1;                 ///< Enable error logging in trace logs
    BIT                     useAlternateFrameSkip:1;            ///< FD frame skip
    BIT                     useDeviceOrientationInFD:1;         ///< Use device orienation to improve FD
    BIT                     useDifferentTuningForFrontCamera:1; ///< Enable/Disable different tuning for front camera for processing
    BIT                     useFDInternalBuffers:1;             ///< Enable/Disable using internal buffers and copy frames for processing
    BIT                     useFDUseCasePool:1;                 ///< Use UseCase Pool for FD data
    BIT                     useVFETPG:1;                        ///< Use VFE_TPG: Valid for presil test modes (CSIM against RUMI)
    BIT                     validateImageBufferUsageState:1;    ///< Check whether ImageBuffer object is in a state where clients can access it legally
    BIT                     watermarkImage:1;                   ///< Watermark request id onto frame. Only support YUV format
    CHAR                    accelVendorTagName[MaxStringLength]; ///< Vendor tag to read accelerometer information
    CHAR                    accelVendorTagSection[MaxStringLength]; ///< Vendor tag to read accelerometer information
    CHAR                    activeNodeMask[MaxStringLength];    ///< Used to create debug probes for active node mask
                                                                ///< String value for this property should be Active Node names delimited
                                                                ///< with any delimiter or none to enable corresponding Node logs. Default is ""
                                                                ///< Ex: 1. PDAF: Create debug probe for PDAF Node
                                                                ///< 2. TOF: Create debug probe for TOF Node
                                                                ///< 3. CAF: Create debug probe for CAF Node
                                                                ///< 4. FOLLOWER: Create debug probe for FOLLOWER Node
                                                                ///< 5. MAIN: Create debug probe for algo
    CHAR                    customAlgoAECName[MaxStringLength]; ///< Custom AEC Algo library name
    CHAR                    customAlgoAECPath[MaxStringLength]; ///< Custom AEC Algo library path
    CHAR                    customAlgoAFDName[MaxStringLength]; ///< Custom AFD Algo Library Name
    CHAR                    customAlgoAFDPath[MaxStringLength]; ///< Custom AFD Algo Library Path
    CHAR                    customAlgoAFName[MaxStringLength];  ///< Custom AF Algo library name
    CHAR                    customAlgoAFPath[MaxStringLength];  ///< Custom AF Algo Library path
    CHAR                    customAlgoASDName[MaxStringLength]; ///< Custom ASD Algo Library Name
    CHAR                    customAlgoASDPath[MaxStringLength]; ///< Custom ASD Algo Library Path
    CHAR                    customAlgoAWBName[MaxStringLength]; ///< Custom AWB Algo library name
    CHAR                    customAlgoAWBPath[MaxStringLength]; ///< Custom AWB Algo Library path
    CHAR                    customHAFAlgoName[MaxStringLength]; ///< Custom HAF Algo library name
    CHAR                    customHAFAlgoPath[MaxStringLength]; ///< Custom HAF Algo Library path
    CHAR                    customPDLibName[MaxStringLength];   ///< Custom PD library name
    CHAR                    customPDLibPath[MaxStringLength];   ///< Custom PD Library path
    CHAR                    customTOFSensorLib[MaxStringLength]; ///< TOF sensor default library
                                                                ///< Update the lib path in DefaultValue section below
                                                                ///< e.g. /system/lib/sensors.hal.tof.so
    CHAR                    debugBufferRegDumpFileNamePrefix[MaxStringLength]; ///< Name of the register dump file
    CHAR                    debugDataHeaderString[MaxStringLength]; ///< Set header string needed by parser to know the type of debug data
    CHAR                    debugLogFilename[MaxStringLength];  ///< Controls if CamX logs are output to the filename provided (NULL to disable)
    CHAR                    dualLEDCalibrationPath[MaxStringLength]; ///< Location of the dual LED calibration output file
    CHAR                    inducerNodeName[MaxStringLength];   ///< Which node need to be trigger by inducer
    CHAR                    inducerPipelineName[MaxStringLength]; ///< Which pipeline need to be trigger by inducer
    CHAR                    pDebugProcess[MaxStringLength];     ///< Debug settings are only applied to the given process (no process by default)
    CHAR                    sensorEmulatorPath[MaxStringLength]; ///< Sensor emulator application path
    CHAR                    sensorEmulator[MaxStringLength];    ///< Sensor emulator application name
    CHAR                    vmDebugMask[MaxStringLength];       ///< Used to control VM logs for visualizing VM using tool
                                                                ///< String value for this property should be "ALL" or VM topology names delimited
                                                                ///< with ',' to enable corresponding topology's VM logs. Default is ""
                                                                ///< Ex: 1. PDAF: Enables VM logs only under PDAF topology
                                                                ///< 2. CAF,PDAF: Enables VM logs under CAF and PDAF
                                                                ///< 3. FD,PDAF,ToF : Enables VM logs for FD, PDAF and ToF topologies
                                                                ///< 4. ALL : Enable VM logs under all topologies
    CHAR                    watermarkOffset[MaxStringLength];   ///< Pass the x and y offsets to offset the location of the watermark.
                                                                ///< Example to offset x position by 40 and y position by 220:
                                                                ///< 40x220
    CHIPartialDataType      enableCHIPartialData;               ///< Enable Partial Data Support from CHI:
                                                                ///< CHIPartialDataDisable for no CHI Partial Data,
                                                                ///< CHIPartialDataSeparate to send CHI Partial Data independently,
                                                                ///< CHIPartialDataCombined to send it along with Core Driver.
    CSLModeType             CSLMode;                            ///< Selects run-time CSL mode
    DualLEDCalibrationType  dualLEDCalibrationMode;             ///< Enables/Disables Dual LED Calibration or Tuning
    EnableAFAlgoType        enableAFAlgo;                       ///< Override Tuning Enabled Algorithm,
                                                                ///< Disabled: No Override,
                                                                ///< PDAF:     Enable only PDAF,
                                                                ///< TOF:      Enable only TOF,
                                                                ///< DCIAF:    Enable only DCIAF,
                                                                ///< CAF:      Enabled only CAF
    FDBaseResolutionType    FDBaseResolution;                   ///< Select one of the following base resolutions
                                                                ///< 640x480,
                                                                ///< 854x480,
                                                                ///< 320x240,
                                                                ///< 427x240
    FDClientType            FDClient;                           ///< Override to control FD engine filter,
                                                                ///< FDHWHybrid: Use FD Hybrid as clinet type
                                                                ///< FDSWOnly  : Use FD SW only as client type
    FDConfigSourceType      FDConfigSource;                     ///< Override to control source for FD configuration,
                                                                ///< Default:   Default config populated by driver
                                                                ///< VendorTag: Config fetched from vendor tag
                                                                ///< Binary:    Config fetched from tuning binary
    FDFilterEngineType      FDFilterEngine;                     ///< Override to control FD engine filter,
                                                                ///< FD_Standard_ARM:            Use FD_Standard_ARM as FD filter
                                                                ///< FD_Standard_DSP:            Use FD_Standard_DSP as FD filter
                                                                ///< FD_DL_ARM:                  Use FD_DL_ARM as FD filter
                                                                ///< FD_DL_DSP:                  Use FD_DL_DSP as FD filter
                                                                ///< FD_DL_DSP_and_Standard_ARM: Use FD_DL_DSP and supplement with FD_Standard_ARM when certain conditions are met
    FDMultiCamProcessingType FDMultiCamProcess;                 ///< Criteria to select which camera to run when both running,
                                                                ///< ProcessMasterOnly: Process only master requests at full fps
                                                                ///< ProcessAuxOnly:    Process only aux requests at full fps
                                                                ///< ProcessBoth:       Process both master and aux at half fps
    FDPreProcessingType     FDPreprocessing;                    ///< To improve FD detection rate, preprocess the frame
                                                                ///< Disable     : Disable any pre processing. For all other options, whether pre-processing is
                                                                ///< really done or not depends on few other factors based on scene.
                                                                ///< AdaptiveGTM : Enable Adaptive Global Tone Map
                                                                ///< GTM         : Enable Global Tone Map
                                                                ///< LTM         : Enable Local Tone Map
    FDProcessingControlType FDProcessingControl;                ///< Override to control FD processing,
                                                                ///< ForceDisable:   Force disable FD processing eventhough App requests for processing. Android tests will fail
                                                                ///< ForceEnable:    Force enbale FD processing eventhough App doesn't enable FD. Android tests still pass
                                                                ///< AppRequest:     Enable/Disable based on App request. Android tests pass
    FDThreadTaskAllocationType FDThreadTaskAllocation;          ///< Allocation of facial attributes detection tasks between FD worker threads
                                                                ///< Valid only when FD and FD Manager threading are enabled
                                                                ///< PTDOnPriThread - Run facial parts detection on the primary worker thread
                                                                ///< PTDOnSecThread - Run facial parts detection on the secondary worker thread
    FLOAT                   AECGainThresholdForQCFA;            ///< AEC Gain Threshold for Quad CFA Feature
    FLOAT                   BGain;                              ///< Value of White Balance B Gain
    FLOAT                   EISV2Margin;                        ///< Set EIS V2 Margin
    FLOAT                   EISV3Margin;                        ///< Set EIS V3 Margin
    FLOAT                   TOFSensorSamplingRate;              ///< Sampling rate for TOF sensor in hertz
    FLOAT                   exposureGain;                       ///< Value of Exposure Gain
    FLOAT                   gGain;                              ///< Value of White Balance G Gain
    FLOAT                   gain;                               ///< Sensor Gain
    FLOAT                   gravitySensorSamplingRate;          ///< Sampling rate for gravity sensor in hertz
    FLOAT                   gyroSensorSamplingRate;             ///< Sampling rate for gyro sensor in hertz
    FLOAT                   luxIndex;                           ///< Value of Lux Index
    FLOAT                   middleGain;                         ///< camera sensor middle gain
    FLOAT                   rGain;                              ///< Value of White Balance R Gain
    FLOAT                   shortGain;                          ///< camera sensor short gain
    INT                     camVersionOverride;                 ///< Camera HW version override useful for testing purpose
    INT                     dualIFESplitPointOffset;            ///< Overwrites dual IFE split point (offset from sensor horizontal center)
    INT                     inducerPortId;                      ///< Which port need to be trigger by inducer
    INT                     singleIFESupportedHeight;           ///< The max height supported by single IFE
    INT                     singleIFESupportedWidth;            ///< The max width supported by single IFE
    MultiCamera3ASyncType   multiCamera3ASync;                  ///< Select 3A sync scheme
                                                                ///< Disabled:       No 3A sync
                                                                ///< QTI:            QTI standard 3A sync solution
                                                                ///< Singleton:      3A sync solution with only one algorithm instance
    OutputFormatType        outputFormat;                       ///< Output format for IPE Preview and Video output
    RefOutputFormatType     refoutputFormatType;                ///< Output format for IPE Ref port output
    UINT                    AFRecorderMode;                     ///< AF Core Recorder Mode:
                                                                ///< 0. Diable AF Core Recorder Mode
                                                                ///< 1. Enable AF Core Recorder Mode
                                                                ///< 2. Enable AF Core Recorder Mode and Print Set/Input Parameter as well
    UINT                    CSIDBinningMode;                    ///< This setting is valid only if CSID Binning is enable: enableCSIDBinning=TRUE
                                                                ///< Set binning mode:
                                                                ///< 0: Bayer Binning mode
                                                                ///< 1: QCFA Binning mode
    UINT                    EISV2Enable;                        ///< Enable EIS V2. 0 for Disable, 1 for Operation Mode match, 2 for force select
    UINT                    EISV2FrameDelay;                    ///< Set EIS V2 Frame Delay
    UINT                    EISV3Enable;                        ///< Enable EIS V3. 0 for Disable, 1 for Operation Mode match, 2 for force select
    UINT                    EISV3FrameDelay;                    ///< Set EIS V3 Frame Delay
    UINT                    IFEBufDoneTimeout;                  ///< IFE Buf-done fence wait timeout in millisecond
    UINT                    IFEDynamicEnableMask;               ///< IFE Dynamic Enable Mask:
                                                                ///< None                    = 0x0
                                                                ///< SWTMC                   = 0x1
                                                                ///< IFEHVX                  = 0x2       Currently doesn't have enable/disable functionality
                                                                ///< IFECAMIF                = 0x4
                                                                ///< IFEPedestalCorrection   = 0x8
                                                                ///< IFEABF                  = 0x10
                                                                ///< IFELinearization        = 0x20
                                                                ///< IFEPDPC                 = 0x40
                                                                ///< IFEDemux                = 0x80
                                                                ///< IFEHDR                  = 0x100
                                                                ///< IFELSC                  = 0x200
                                                                ///< IFEWB                   = 0x400     Cannot be enabled/disabled since there's no En bit
                                                                ///< IFEDemosaic             = 0x800
                                                                ///< IFECC                   = 0x1000
                                                                ///< IFEGTM                  = 0x2000
                                                                ///< IFEGamma                = 0x4000
                                                                ///< IFECST                  = 0x8000
                                                                ///< ALSC                    = 0x10000
                                                                ///< All Modules             = 0xFFFFF
    UINT                    IFEInputHeight;                     ///< IFE input height in pixel
    UINT                    IFEInputWidth;                      ///< IFE input width in pixel
    UINT                    IFENumFramesHighBW;                 ///< IFE initial frames to multiply bandwidth. Voted bw will be multiplied by 5 for these many frames
    UINT                    IFERegDumpMask;                     ///< No dumps        = 0x0
                                                                ///< IFETop          = 0x1
                                                                ///< ChromaUp        = 0x2
                                                                ///< Pedestal        = 0x4
                                                                ///< Linearization   = 0x8
                                                                ///< BPC             = 0x10
                                                                ///< HDR             = 0x20
                                                                ///< ABF             = 0x40
                                                                ///< LSC             = 0x80
                                                                ///< ColorCorrect    = 0x100
                                                                ///< GTM             = 0x200
                                                                ///< Gamma           = 0x400
                                                                ///< Stats           = 0x800
                                                                ///< VidPath         = 0x1000
                                                                ///< DispPath        = 0x2000
                                                                ///< FD              = 0x4000
                                                                ///< PixelRaw        = 0x8000
                                                                ///< PDAF            = 0x10000
                                                                ///< PDOUT           = 0x20000
                                                                ///< LCR             = 0x40000
                                                                ///< Common          = 0x80000
    UINT                    IFETestImageSizeHeight;             ///< Overwrites testgen output height
    UINT                    IFETestImageSizeWidth;              ///< Overwrites testgen output width
    UINT                    IPEBufDoneTimeout;                  ///< IPE Buf-done fence wait timeout in millisecond
    UINT                    IPEUnitTestIQBypassNumOfIteration;  ///< A setting to IPE IQ bypass unit test to specify number of iterations to run.
    UINT                    MPMBufferAddressAlignment;          ///< Address alignment with which all buffers are allocated, valid only for CSL allocations
    UINT                    MPMKeepMinNumFreeBuffers;           ///< These many buffer will always be there in free list of a specific group
    UINT                    MPMLargeGroupSizeDefinition;        ///< Groups above this defined size will use MPMSizeDiffAllowedToGroupOverride to define difference
                                                                ///< allowed when matching buffer managers' required size
    UINT                    MPMMinSizeForSharing;               ///< Buffer Managers with size less than this value will have dedicated groups, i.e no sharing
    UINT                    MPMMinSizeToFreeOnDeactivate;       ///< If the buffer size in the current group is more than this threshold, we free the buffers
                                                                ///< immediately on Deactivate, keeping max 1 buffer in free list for any immediate usage.
                                                                ///< Current value 50MB
    UINT                    MPMMonitorSelfShrinkSizeLimit;      ///< The advantages we get with self shrinking on small buffers may be less than the costs of allocating
                                                                ///< those buffers again when needed. Hence MPM monitor thread won't free up idle buffers of sizes less
                                                                ///< than this pre-defined size in bytes.
    UINT                    MPMMonitorTimeInterval;             ///< The time interval (in milliseconds) of MPM monitor thread that wakes up
                                                                ///< periodically to perform certain tasks
    UINT                    MPMSizeDiffAllowedToGroup;          ///< Buffer Managers are attached to same Group if buffer size difference (in bytes) is within
                                                                ///< this range
    UINT                    MPMSizeDiffAllowedToGroupOverride;  ///< This byte range is used when a group size is larger than the defined large group size
                                                                ///< (MPMLargeGroupSizeDefinition) to determine if buffer managers should have a different group
    UINT                    MPMSizeThresToDelayedMap;           ///< Size threshold above which a gralloc buffer may be delayed to be mapped to smmu.
                                                                ///< Delay mapping depends on few other condition apart from size threshold.
                                                                ///< Default value of 35MB allows upto 4K resolution buffers to be mapped immediately (not delayed map)
    UINT                    MPMSizeThresToDisableDelayedUnmap;  ///< Disable Delayed Unamp feature while mapping to SMMU for buffers of size more than this threshold.
                                                                ///< Current threshold is 35MB
    UINT                    TOFDataReportRate;                  ///< Report rate for TOF data in microsecs
    UINT                    advanceFeatureMask;                 ///< Mask to enable Advance Features in AdvancedCameraUsecase
                                                                ///< No extra features enabled               = 0x0
                                                                ///< Enable FeatureZSL (by default)          = 0x1
                                                                ///< Enable FeatureMFNR (HW multi frame)     = 0x2
                                                                ///< Enable FeatureHDR/AE_Bracket            = 0x4
                                                                ///< Enable FeatureSWMF (SW multi frame)     = 0x8
                                                                ///< Enable FeatureMFSR (HW multi frame)     = 0x10
                                                                ///< Enable FeatureQCFA                      = 0x20
                                                                ///< Enable Feature2 Wrapper                 = 0x40
    UINT                    afLog;                              ///< Set AF log levels [0-7]
    UINT                    anchorAlgoSelectionType;            ///< Select Anchor Algorithm Selection Type for MFNR
                                                                ///< Timestamp        = 0.
                                                                ///< Sharpness        = 1,
                                                                ///< Lighting         = 2
    UINT                    anchorSelectionAlgoForMFNR;         ///< Select Anchor Selection Algorithm for MFNR
                                                                ///< NONE        = 0.
                                                                ///< FIXED       = 1,
                                                                ///< NON-FIXED   = 2
    UINT                    apiMask;                            ///< Used to set API mask
                                                                ///< Ex: 0. Process Monitor
                                                                ///< 1. Process Search
                                                                ///< 2. Set Parameters
                                                                ///< 3. Set Inputs
                                                                ///< 4. Set Tuning
                                                                ///< 5. Set Mode
                                                                ///< 6. Set Camera Mode
                                                                ///< 7. Set ROI
                                                                ///< 8. Set Range
                                                                ///< 9. Get Debug Data
                                                                ///< 10. Rebase
                                                                ///< 11. Destroy
                                                                ///< 12. Set Sensitivity
                                                                ///< 13. Get Parameters
                                                                ///< 14. Clear Data
    UINT                    assertMask;                         ///< Mask of asserts which will trigger the runtime assert code
    UINT                    autoImageDumpBPSInstanceMask;       ///< Instance mask BPS:
                                                                ///< BPSInstanceName0            = 0x1;
                                                                ///< BPSInstanceName1            = 0x2;
                                                                ///< BPSInstanceName2            = 0x4;
                                                                ///< BPSInstanceName3            = 0x8;
                                                                ///< ALLInstances                = 0xFFFFFFFF
    UINT                    autoImageDumpBPSinputPortMask;      ///< Input port mask BPS:
                                                                ///< BPSInputPort            = 0x1;
    UINT                    autoImageDumpBPSoutputPortMask;     ///< Output port mask BPS:
                                                                ///< BPSOutputPortFull            = 0x2;
                                                                ///< BPSOutputPortDS4             = 0x4;
                                                                ///< BPSOutputPortDS16            = 0x8;
                                                                ///< BPSOutputPortDS64            = 0x10;
                                                                ///< BPSOutputPortStatsBG         = 0x20;
                                                                ///< BPSOutputPortStatsHDRBHist   = 0x40;
                                                                ///< BPSOutputPortReg1            = 0x80;
                                                                ///< BPSOutputPortReg2            = 0x100;
                                                                ///< ALLports                     = 0x1FE
    UINT                    autoImageDumpCHINodeInstanceMask;   ///< Instance mask ChiNode:
                                                                ///< ChiNodeInstanceName0            = 0x1;
                                                                ///< ChiNodeInstanceName1            = 0x2;
                                                                ///< ChiNodeInstanceName2            = 0x4;
                                                                ///< ChiNodeInstanceName3            = 0x8;
                                                                ///< ChiNodeInstanceName4            = 0x10;
                                                                ///< ChiNodeInstanceName5            = 0x20;
                                                                ///< AllInstances                    = 0x3F
    UINT                    autoImageDumpCHINodeinputPortMask;  ///< Input port mask ChiNode:
                                                                ///< ChiNodeInputPort            = 0x1
    UINT                    autoImageDumpCHINodeoutputPortMask; ///< Output port mask ChiNode:
                                                                ///< ChiNodeOutputFull            = 0x1;
                                                                ///< ChiNodeOutputDS4             = 0x2;
                                                                ///< ChiNodeOutputDS16            = 0x4;
                                                                ///< ChiNodeOutputDS64            = 0x8;
                                                                ///< ChiNodeOutputDS              = 0x10;
                                                                ///< ALLports                     = 0x1F
    UINT                    autoImageDumpCVPInstanceMask;       ///< Instance mask CVP:
                                                                ///< CVPInstanceName0             = 0x1;
                                                                ///< CVPInstanceName1             = 0x2;
                                                                ///< CVPInstanceName2             = 0x4;
                                                                ///< AllInstances                 = 0x7
    UINT                    autoImageDumpCVPinputPortMask;      ///< Input port mask CVP:
                                                                ///< CVPInputPortTARIFEFull               = 0x8;
                                                                ///< CVPInputPortREFIFEFull               = 0x10;
                                                                ///< CVPInputPortTARIFEDS4                = 0x20;
                                                                ///< CVPInputPortREFIFEDS4                = 0x40;
                                                                ///< CVPInputPortTARIFEDS16               = 0x80;
                                                                ///< CVPInputPortREFIFEDS16               = 0x100;
                                                                ///< CVPInputPortData                     = 0x200;
                                                                ///< ALLports                             = 0x3F8
    UINT                    autoImageDumpCVPoutputPortMask;     ///< Output port mask CVP:
                                                                ///< CVPOutputPortVector             = 0x1;
                                                                ///< CVPOutputPortData               = 0x2;
                                                                ///< CVPOutputPortImage              = 0x4;
                                                                ///< ALLports                        = 0x7
    UINT                    autoImageDumpFDHwInstanceMask;      ///< Instance mask FDHw:
                                                                ///< FDHwInstanceName0             = 0x1;
                                                                ///< FDHwInstanceName1             = 0x2;
                                                                ///< AllInstances                  = 0x3
    UINT                    autoImageDumpFDHwinputPortMask;     ///< Input port mask FDHw:
                                                                ///< FDHwInputPortImage            = 0x1
    UINT                    autoImageDumpFDHwoutputPortMask;    ///< Output port mask FDHw:
                                                                ///< FDHwOutputPortResults         = 0x1;
                                                                ///< FDHwOutputPortRawResults      = 0x2;
                                                                ///< FDHwOutputPortWorkBuffer      = 0x4;
                                                                ///< ALLports                      = 0x7
    UINT                    autoImageDumpIFEInstanceMask;       ///< Instance mask:
                                                                ///< IFE:
                                                                ///< IFEInstanceName0            = 0x1;
                                                                ///< IFEInstanceName1            = 0x2;
                                                                ///< IFEInstanceName2            = 0x4;
                                                                ///< AllInstances                = 0x7
    UINT                    autoImageDumpIFEinputPortMask;      ///< Input Port mask:
                                                                ///< IFE:
                                                                ///< IFEInputPortCSIDTPG         = 0x1;
                                                                ///< IFEInputPortCAMIFTPG        = 0x2;
                                                                ///< IFEInputPortSensor          = 0x4;
                                                                ///< IFEInputPortRDI0            = 0x8;
                                                                ///< IFEInputPortRDI1            = 0x10;
                                                                ///< IFEInputPortRDI2            = 0x20;
                                                                ///< IFEInpurPortDualPD          = 0x40;
                                                                ///< ALLports                    = 0x7F;
    UINT                    autoImageDumpIFEoutputBatchNum;     ///< Output IFE batched frames(HFR):
                                                                ///< IFE:
                                                                ///< Dump only ONE frame from  IFE Batch    = 0x1
                                                                ///< Dump only TWO frames from IFE Batch    = 0x2
                                                                ///< Dump only THREE frames from IFE Batch  = 0x3
                                                                ///< Dump only FOUR frames from IFE Batch   = 0x4
                                                                ///< Dump only FIVE frames from IFE Batch   = 0x5
                                                                ///< Dump only SIX frames from IFE Batch    = 0x6
                                                                ///< Dump only SEVEN frames from IFE Batch  = 0x7
                                                                ///< Dump only EIGHT frames from IFE Batch  = 0x8
    UINT                    autoImageDumpIFEoutputPortMask;     ///< Output port mask:
                                                                ///< IFE:
                                                                ///< IFEOutputPortFull            = 0x1;
                                                                ///< IFEOutputPortDS4             = 0x2;
                                                                ///< IFEOutputPortDS16            = 0x4;
                                                                ///< IFEOutputPortCAMIFRaw        = 0x8;
                                                                ///< IFEOutputPortLSCRaw          = 0x10;
                                                                ///< IFEOutputPortGTMRaw          = 0x20;
                                                                ///< IFEOutputPortFD              = 0x40;
                                                                ///< IFEOutputPortPDAF            = 0x80;
                                                                ///< IFEOutputPortRDI0            = 0x100;
                                                                ///< IFEOutputPortRDI1            = 0x200;
                                                                ///< IFEOutputPortRDI2            = 0x400;
                                                                ///< IFEOutputPortRDI3            = 0x800;
                                                                ///< IFEOutputPortStatsRS         = 0x1000;
                                                                ///< IFEOutputPortStatsCS         = 0x2000;
                                                                ///< IFEOutputPortStatsIHIST      = 0x8000;
                                                                ///< IFEOutputPortStatsBHIST      = 0x10000;
                                                                ///< IFEOutputPortStatsHDRBE      = 0x20000;
                                                                ///< IFEOutputPortStatsHDRBHIST   = 0x40000;
                                                                ///< IFEOutputPortStatsTLBG       = 0x80000;
                                                                ///< IFEOutputPortStatsBF         = 0x100000;
                                                                ///< IFEOutputPortStatsAWBBG      = 0x200000;
                                                                ///< IFEOutputPortDisplayFull     = 0x400000;
                                                                ///< IFEOutputPortDisplayDS4      = 0x800000;
                                                                ///< IFEOutputPortDisplayDS16     = 0x1000000;
                                                                ///< IFEOutputPortStatsDualPD     = 0x2000000;
                                                                ///< ALLports                     = 0x3FFBFFF
                                                                ///< AllPixelOutput               = 0x1C00047
                                                                ///< AllRawOutput                 = 0xFB8
                                                                ///< AllRDIOutput                 = 0xF00
                                                                ///< AllStatsOutput               = 0x3FB000
    UINT                    autoImageDumpIPEInstanceMask;       ///< IPEInstanceName0             = 0x1;
                                                                ///< IPEInstanceName1             = 0x2;
                                                                ///< IPEInstanceName2             = 0x4;
                                                                ///< IPEInstanceName3             = 0x8;
                                                                ///< IPEInstanceName4             = 0x10;
                                                                ///< IPEInstanceName5             = 0x20;
                                                                ///< IPEInstanceName6             = 0x40;
                                                                ///< IPEInstanceName7             = 0x80;
                                                                ///< IPEInstanceName8             = 0x100;
                                                                ///< IPEInstanceName9             = 0x200;
                                                                ///< IPEInstanceName10            = 0x400;
                                                                ///< IPEInstanceName11            = 0x800;
                                                                ///< IPEInstanceName12            = 0x1000;
                                                                ///< IPEInstanceName13            = 0x2000;
                                                                ///< IPEInstanceName14            = 0x4000;
                                                                ///< IPEInstanceName15            = 0x8000;
                                                                ///< IPEInstanceName16            = 0x10000;
                                                                ///< IPEInstanceName17            = 0x20000;
                                                                ///< IPEInstanceName18            = 0x40000;
                                                                ///< IPEInstanceName19            = 0x80000;
                                                                ///< IPEInstanceName20            = 0x100000;
                                                                ///< IPEInstanceName21            = 0x200000;
                                                                ///< AllInstances                 = 0xFFFFFFFF
    UINT                    autoImageDumpIPEinputPortMask;      ///< Input port mask for IPE:
                                                                ///< IPEInputPortFull             = 0x1;
                                                                ///< IPEInputPortDS4              = 0x2;
                                                                ///< IPEInputPortDS16             = 0x4;
                                                                ///< IPEInputPortDS64             = 0x8;
                                                                ///< IPEInputPortFullRef          = 0x10;
                                                                ///< IPEInputPortDS4Ref           = 0x20;
                                                                ///< IPEInputPortDS16Ref          = 0x40;
                                                                ///< IPEInputPortDS64Ref          = 0x80;
                                                                ///< ALLports                     = 0xFF
    UINT                    autoImageDumpIPEoutputPortMask;     ///< Output port mask for IPE:
                                                                ///< IPEOutputPortDisplay         = 0x100;
                                                                ///< IPEOutputPortVideo           = 0x200;
                                                                ///< IPEOutputPortFullRef         = 0x400;
                                                                ///< IPEOutputPortDS4Ref          = 0x800;
                                                                ///< IPEOutputPortDS16Ref         = 0x1000;
                                                                ///< IPEOutputPortDS64Ref         = 0x2000;
                                                                ///< ALLports                     = 0x3F00
    UINT                    autoImageDumpJpegHwInstanceMask;    ///< Instance mask JpegHw:
                                                                ///< JPEGInstanceName0            = 0x1;
                                                                ///< JPEGInstanceName1            = 0x2;
                                                                ///< ALLInstances                 = 0x3
    UINT                    autoImageDumpJpegHwinputPortMask;   ///< Input port mask JpegHw:
                                                                ///< JPEGInputPort0             = 0x1;
    UINT                    autoImageDumpJpegHwoutputPortMask;  ///< Output port mask JpegHw:
                                                                ///< JPEGOutputPort0             = 0x1;
    UINT                    autoImageDumpLRMEInstanceMask;      ///< Instance mask LRME:
                                                                ///< LRMEInstanceName0            = 0x1;
                                                                ///< LRMEInstanceName1            = 0x2;
                                                                ///< AllInstances                 = 0x3
    UINT                    autoImageDumpLRMEinputPortMask;     ///< Input port mask LRME:
                                                                ///< LRMEInputPortTARIFEFull               = 0x1;
                                                                ///< LRMEInputPortREFIFEFull               = 0x2;
                                                                ///< LRMEInputPortTARIFEDS4                = 0x4;
                                                                ///< LRMEInputPortREFIFEDS4                = 0x8;
                                                                ///< LRMEInputPortTARIFEDS16               = 0x10;
                                                                ///< LRMEInputPortREFIFEDS16               = 0x20;
                                                                ///< LRMEMaxIntputPorts                    = 0x40;
                                                                ///< ALLports                              = 07F
    UINT                    autoImageDumpLRMEoutputPortMask;    ///< Output port mask LRME:
                                                                ///< LRMEOutputPortVector            = 0x1;
                                                                ///< LRMEOutputPortDS2               = 0x2;
                                                                ///< LRMEMaxOutputPorts              = 0x4;
                                                                ///< ALLports                        = 0xF
    UINT                    autoImageDumpMask;                  ///< Will limit dumps to only the specified nodes and ports when autoImageDump is enabled
                                                                ///< Uses ImageDumpType to define the flags
                                                                ///< No dumps                                      = 0x0
                                                                ///< All output ports for IFE                      = 0x1
                                                                ///< All output ports for IPE                      = 0x2
                                                                ///< All output ports for BPS                      = 0x4
                                                                ///< All JPEG output ports for all JPEG nodes      = 0x8
                                                                ///< All output ports for FDHw                     = 0x10
                                                                ///< All output ports for LRME                     = 0x20
                                                                ///< All output ports for RANSAC                   = 0x40
                                                                ///< All output ports for all ChiNodes             = 0x80
                                                                ///< All output ports for CVP                      = 0x100
                                                                ///< All other nodes not explicitly listed above   = 0x40000000
    UINT                    autoImageDumpRANSACInstanceMask;    ///< Instance mask RANSAC:
                                                                ///< RANSACInstanceName0          = 0x1;
                                                                ///< RANSACInstanceName1          = 0x2;
                                                                ///< AllInstances                 = 0x3
    UINT                    autoImageDumpRANSACinputPortMask;   ///< Input port mask RANSAC:
                                                                ///< RANSACInputPort0           = 0x1
    UINT                    autoImageDumpRANSACoutputPortMask;  ///< Output port mask RANSAC:
                                                                ///< RANSACOutputPort0            = 0x1
    UINT                    autoInputImageDumpMask;             ///< Will limit dumps to only the specified nodes when autoInputImageDump is enabled
                                                                ///< Uses ImageDumpType to define the flags
                                                                ///< No dumps                                      = 0x0
                                                                ///< All input ports for IFE                       = 0x1
                                                                ///< All input ports for IPE                       = 0x2
                                                                ///< All input ports for BPS                       = 0x4
                                                                ///< All JPEG input ports for all JPEG nodes       = 0x8
                                                                ///< All input ports for FDHw                      = 0x10
                                                                ///< All input ports for LRME                      = 0x20
                                                                ///< All input ports for RANSAC                    = 0x40
                                                                ///< All input ports for all ChiNodes              = 0x80
                                                                ///< All input ports for CVP                       = 0x100
                                                                ///< All other nodes not explicitly listed above   = 0x40000000
    UINT                    bpsRealtimeSensorId;                ///< Sensor ID for BPS Based Realtime Camera
    UINT                    colorTemp;                          ///< Value of White Balance color temperature
    UINT                    debugBufferRegDumpSizeInBytes;      ///< Size in bytes for each register dump buffer
    UINT                    debugDataSizeAEC;                   ///< Debug-data size reserved for AEC
    UINT                    debugDataSizeAF;                    ///< Debug data size reserved for AF
    UINT                    debugDataSizeAWB;                   ///< Debug data size reserved for AWB
    UINT                    defaultMaxFPS;                      ///< Set the default fps for sensor mode pick
    UINT                    disableASDStatsProcessing;          ///< Enables/Disables ASD Stats Processing. 0 for enable, 1 for disable
    UINT                    dualIFELeftPadding;                 ///< Overwrites dual IFE left padding
    UINT                    dualIFERightPadding;                ///< Overwrites dual IFE right padding
    UINT                    dumpAEC;                            ///< Mask info:
                                                                ///< dump AEC Stats: 0x1
                                                                ///< dump AEC Info:  0x2
                                                                ///< dump AEC HAL Data: 0x4
                                                                ///< dump Stats, Info and HAL Data: 0x7
    UINT                    dumpAF;                             ///< Mask info:
                                                                ///< dump AF Stats: 0x1
                                                                ///< dump AF Info:  0x2
                                                                ///< dump AF HWPD Config: 0x4
                                                                ///< dump Stats, Info and HWPD config: 0x7
    UINT                    dumpAWB;                            ///< Mask info:
                                                                ///< dump AWB Stats: 0x1
                                                                ///< dump AWB Info:  0x2
                                                                ///< dump AWB HAL Data: 0x4
                                                                ///< dump Stats, Info and HAL Data: 0x7
    UINT                    dumpDebugDataEveryProcessResult;    ///< Control debug-data dump per process result
                                                                ///< If enable this setting and implemented dump by CHI, debug-data including Tuning metadata will be dump into a file
                                                                ///< on every process result.
                                                                ///< Note that to dump data, debug-data should be also enable using the corresponding settings.
                                                                ///< Values:
                                                                ///< 0: Disable, do not dump any data.
                                                                ///< 1: Enable for multi-frame snapshot.
                                                                ///< 2: Enable only while video port is enable.
                                                                ///< 3: Enable for all processed buffers. This include all preview frames.
    UINT                    dumpMetadata;                       ///< 0 - disable:
                                                                ///< 1 - Enable text metadata dump for offline pipelines,
                                                                ///< 2 - Enable text metadata dump for real-time pipelines,
                                                                ///< 3 - Enable text metadata dump for both offline and real-time pipelines
                                                                ///< 4 - Enable binary metadata dump for offline pipelines,
                                                                ///< 8 - Enable binary metadata dump for real-time pipelines,
                                                                ///< 12 - Enable binary metadata dump for both offline and real-time pipelines
    UINT                    dynamicCalibrationMaxSize;          ///< max allocated space for dynamic inline LED Calibration data
    UINT                    enableAEScan;                       ///< Enable/Disable AE Scan
                                                                ///< 0  Disable
                                                                ///< 1  Enable AE Scan Time Sweep
                                                                ///< 2  Enable AE Scan Gain Sweep
                                                                ///< 4  Enable AE Scan Toogle
                                                                ///< 8  Enable AE Scan Time Sweep delayed
                                                                ///< 16 Enable AE Scan Gain Sweep delayed
                                                                ///< 32 Enable AE Scan Toogle delayed
                                                                ///< To Enable more then one test case bitwise or the value.
    UINT                    enableAsciiLogging;                 ///< Set offline ASCII Logging
                                                                ///< Disable = 0,
                                                                ///< Enable  = 1
                                                                ///< Note: The setting is independent from binary logger setting.
                                                                ///< It does not effect binary logging
    UINT                    enableBLMClient;                    ///< Enables/Disable Bandwidth Limits Manager Client
    UINT                    enableBPSHangDump;                  ///< Enables/Disables dumping of BPS BL buffer which represent debug info from firmware
                                                                ///< 0x1 = Dump always
                                                                ///< 0x2 = Dump on error
    UINT                    enableBinaryLogging;                ///< Set offline binary Logging.
                                                                ///< Disable = 0,
                                                                ///< Enable  = 1
                                                                ///< Note: The setting is independent from ASCII logging setting.
                                                                ///< It does not effect ASCII logging.
    UINT                    enableCHIImageBufferLateBinding;    ///< Whether to enable late bind of memory/buffers to ImageBuffer for CHI buffer managers.
                                                                ///< 0 for FALSE, i.e Buffers are allocated/bound at the time of GetImageBufferInfo
                                                                ///< 1 for TRUE, i.e holder ImageBuffer objects are returned in GetImageBufferInfo
    UINT                    enableCHIPartialDataRecovery;       ///< Enable Partial Data Recovery
    UINT                    enableDebugSensorExposure;          ///< Enable setting exposure settings manually to sensor driver for debugging purpose
    UINT                    enableFDStreamInRealTime;           ///< Enable FD Stream in Real Time from CHI:
                                                                ///< FALSE   = 0,
                                                                ///< TRUE    = 1
    UINT                    enableFeature2Dump;                 ///< Flag to enable raw image and/or metadata dump in feature2.
                                                                ///< Disable    = 0,
                                                                ///< Enable     = 1
    UINT                    enableGamma15PreCalculate;          ///< Flag to enable gamma15 pre-calculation for TMC 1.1
                                                                ///< Disable   = 0,
                                                                ///< Enable    = 1
    UINT                    enableIPEHangDump;                  ///< ARRAY(0x573c65947520)
    UINT                    enableIPEIQModulesMask;             ///< IPE enable mask:
                                                                ///< IPEANR               = 0x8
                                                                ///< IPETF                = 0x10
                                                                ///< IPECAC               = 0x20
                                                                ///< IPECST               = 0x100
                                                                ///< IPELTM               = 0x200
                                                                ///< IPEColorCorrection   = 0x400
                                                                ///< IPEGamma             = 0x800
                                                                ///< IPE2DLUT             = 0x1000
                                                                ///< IPEChromaEnhancement = 0x2000
                                                                ///< IPEChromaSuppression = 0x4000
                                                                ///< IPEASF               = 0x10000
                                                                ///< IPEUpscaler          = 0x20000
                                                                ///< IPEGrainAdder        = 0x40000
                                                                ///< IPEHNR               = 0x400000
                                                                ///< IPELENR              = 0x800000
                                                                ///< ALLIPEIQModules      = 0xFFFFFF
                                                                ///< To enable/disable IPE IQ modules appropriately, please double check the corresponding
                                                                ///< IPE IQ module list which depends on platforms under folder src\hwl\isphwsetting\pipeline\ipe
    UINT                    enableMFSRChiFence;                 ///< Enable this setting so that CHI fence support is enabled on MFSR CHITargetBufferManager.
                                                                ///< 0 for FALSE, 1 for TRUE.
    UINT                    enableOfflineNoiseReprocess;        ///< Flag to enable offline noise reprocessing in MFNR
                                                                ///< Disable   = 0,
                                                                ///< Enable    = 1
    UINT                    enablePDLibDump;                    ///< Enable/Disable PD Library Data Dump
                                                                ///< 1 - Single raw input with configuration dump.
                                                                ///< 2 - Raw input dump according to lens position and configuration.
    UINT                    enablePDLibLog;                     ///< Enable/Disable PD Library Logging
                                                                ///< 1 - Enable all PDLib general logging
                                                                ///< 2 - Enable all PDLib general + verbose logging
                                                                ///< 3 - Enable all PDLib general + verbose logging with Adaptive K logging
    UINT                    enablePDLibTestMode;                ///< Enable/Disable PD Library Test Mode
                                                                ///< 1 - General test mode to check gainmap uniformity
    UINT                    enableRawHDR;                       ///< Enable/Disable RAW HDR Snapshot by set this value.
                                                                ///< 0 for FALSE, Disable
                                                                ///< 1 for TRUE, Enable
    UINT                    enableTBMChiFence;                  ///< Enable this setting so that CHI fence support is enabled on CHITargetBufferManager class.
                                                                ///< 0 for FALSE, 1 for TRUE.
    UINT                    enableUnifiedBufferManager;         ///< Enable this setting so that CHI and CAMX use the unified image buffer manager.
                                                                ///< 0 for FALSE, i.e CHIBufferManager uses Gralloc interface to allocate Buffers
                                                                ///< 1 for TRUE, i.e CHIBufferManager uses CamXBufferManager interface to allocate Buffers
    UINT                    exposureTime;                       ///< Value of Exposure Time in nanoseconds
    UINT                    feature1;                           ///< set tuning feature1
                                                                ///< None            = 0,
                                                                ///< ISPHDR          = 1,
                                                                ///< ADRC            = 2,
                                                                ///< InSensorHDR3Exp = 3
    UINT                    feature2;                           ///< set tuning feature2
                                                                ///< None           = 0,
                                                                ///< OISCapture     = 1,
                                                                ///< HLG            = 2,
                                                                ///< HDR10          = 3,
                                                                ///< MFNRBlend      = 4,
                                                                ///< MFNRPostFilter = 5,
                                                                ///< MFSRBlend      = 6,
                                                                ///< MFSRPostFilter = 7
    UINT                    forceCHIBufferManagerHeap;          ///< Force to use CHI Buffer Managers to use a specified heap if bufferHeap field is not explicitly set
                                                                ///< in CHIBufferManagerCreateData.
                                                                ///< 0 - System
                                                                ///< 1 - Ion
                                                                ///< 2 - DSP
                                                                ///< 3 - EGL (Gralloc)
    UINT                    forceHWMFFixedNumOfFrames;          ///< Integer to force HWMF fixed number of frames
                                                                ///< Disable                     = 0,
                                                                ///< Enable and num of frames    > 0
    UINT                    forceMaxFPS;                        ///< Do not pick a sensor mode above forceMaxFPS.  Primarily used for debugging.
                                                                ///< Set to a huge number to disable
    UINT                    fovcEnable;                         ///< Enable/Disable Field Of View Compensation
    UINT                    gravityDataReportRate;              ///< Report rate for gravity data in microsecs
    UINT                    gyroDataReportRate;                 ///< Report rate for gyro data in microsecs
    UINT                    ifeCamnocBandwidthMBytes;           ///< Overrides driver's calculated CAMNOC BW vote with the provided value.
                                                                ///< 0xffffffff (-1) will completely disable bandwidth settings from UMD.
                                                                ///< 0 will disable the override, driver will calculate optimal rate and set it.
                                                                ///< Any positive value can be used as an override. Recommended value is 10640.
    UINT                    ifeClockFrequencyMHz;               ///< Overrides driver's calculated clock rate with the provided value.
                                                                ///< 0xffffffff (-1) will completely disable Clock settings from UMD. KMD will set to MAX clock.
                                                                ///< 0 will disable the override, driver will calculate optimal rate and set it.
                                                                ///< Any positive value can be used as an override.
    UINT                    ifeExternalBandwidthMBytes;         ///< Overrides driver's calculated non-CAMNOC or external BW vote with the provided value.
                                                                ///< 0xffffffff (-1) will completely disable bandwidth settings from UMD.
                                                                ///< 0 will disable the override, driver will calculate optimal rate and set it.
                                                                ///< Any positive value can be used as an override. Recommended value is 10640.
    UINT                    imageBufferWaitTime;                ///< How long to wait for an image buffer to be free when all are busy in milliseconds.
    UINT                    inducerRequestId;                   ///< Greater than the reqId wiil trigger inducer
    UINT                    isFirstFrameLoopbackInputImageEnabled; ///< This is to indicate that loopback input for first frame is input image
    UINT                    kickTheMachine;                     ///< If 3A struggles to converge, fake it.  Value is the number of requests before forcing convergance
    UINT                    lensPos;                            ///< Lens Position Which Interpreted Based on Manual Lens Control
    UINT                    logConfigMask;                      ///< Mask of which config logs are output
    UINT                    logDumpMask;                        ///< Mask of which Dump logs are output
    UINT                    logEntryExitMask;                   ///< Mask of which entry/exit logs are output
    UINT                    logInfoMask;                        ///< Mask of which info logs are output
    UINT                    logPerfInfoMask;                    ///< Mask of which perf info logs are output
    UINT                    logVerboseMask;                     ///< Mask of which verbose logs are output
    UINT                    logWarningMask;                     ///< Mask of which warning logs are output
    UINT                    maxBuffersSecureCamera;             ///< Limits max_buffers of producer for secure camera usecase
    UINT                    maxHalRequests;                     ///< Max HAL requests the driver accepts before queueing.
    UINT                    maxImageBufferTimeoutCount;         ///< How many times to wait for an image buffer to be free when all are busy.
                                                                ///< Effective wait time = imageBufferWaitTime*MaxImageBufferTimeoutCount.
    UINT                    maxInOutResolution;                 ///< Maximum input output resolution for stream configuration
                                                                ///< Default value is 200MP
    UINT                    maxMemSpyStats;                     ///< The maximum number of MemSpy statistics to report
    UINT                    maxNonHfrFps;                       ///< Maximum fps bound exposed in capability to App in Non HFR mode
    UINT                    maxNumberOfAcceptedErrors;          ///< Limit the max number of duplicate result or notification related errors accepted
    UINT                    maxRAWSizes;                        ///< Max RAW sizes exposed in static capability to APP and minimum should be 1
    UINT                    memSpyRequestRate;                  ///< Controls the printing of the Memspy runtime report every N requests (0 to disable)
    UINT                    memsetInputMeta;                    ///< Enable proving memset data to the nodes when input data for tag ID is
                                                                ///< NULL. 0 - disable, 1 - only properties, 2 - all tags.
    UINT                    minFrameRateBound;                  ///< Minimum fps bound of frame duration for max resolution
    UINT                    minInOutResolution;                 ///< Minimum input output resolution for stream configuration
                                                                ///< Default value is 0MP
    UINT                    minReprocessInputHeight;            ///< Cap minimum reprocess height of input dimension supported by HAL.
                                                                ///< By default all sizes upto 5MP(2592x1944) will be advertised.
                                                                ///< Default value of this is 1944
    UINT                    minReprocessInputWidth;             ///< Cap minimum reprocess width of input dimension supported by HAL.
                                                                ///< By default all sizes upto 5MP(2592x1944) will be advertised.
                                                                ///< Default value of this is 2592
    UINT                    minReqFdDependency;                 ///< Can't set dependency on for FD on req id lesser than 5
    UINT                    multiCameraFrameSync;               ///< Enable/Disable multi camera framework kernel frame sync.
                                                                ///< This will help to apply both the real time request settings
                                                                ///< as close as possible.
                                                                ///< 0 for enable, 1 for disable.
                                                                ///< This works only if multiCameraEnable is set.
    UINT                    multiCameraHWSyncMask;              ///< Will limit enable HW sync to only the specified  usecase
                                                                ///< Uses MultiCameraHWSyncType to define the flags
                                                                ///< Disabled                                      = 0x0
                                                                ///< Enable HW Sync for RTB                        = 0x1
                                                                ///< Enable HW Sync for SAT                        = 0x2
                                                                ///< Enable HW Sync for VR                         = 0x4
    UINT                    multiCameraJPEG;                    ///< Enable/Disable JPEG Capture per Physical Camera
    UINT                    multiCameraVREnable;                ///< Enable/Disable multi camera framework with VR
    UINT                    nodeResponseTime;                   ///< The time a node needs to process a request in Milliseconds. Used when taking the maximum time a pipeline is
                                                                ///< expected to be done.
    UINT                    numIPECoresToUse;                   ///< This is the number of cores the ICP may utilize
    UINT                    numMetadataResults;                 ///< Max number of metadata results supported. Value > 1 means partial metadata results
                                                                ///< are enabled. 2 is the max value supported
    UINT                    numPCRsBeforeStreamOn;              ///< Set number of PCRs to handle before stream on
    UINT                    numWorkerThreads;                   ///< The number of threads to use in the device's threadpool
    UINT                    numberOfAELockFrames;               ///< Number of Frames where AE is locked for HW sync to latch on
    UINT                    numberOfCHIThreads;                 ///< Allows to configure the number of CHI Threads to be used
    UINT                    numberOfFramesToSkip;               ///< Number of frames to skip after flash
    UINT                    offlineLoggerMinFlushCnt;           ///< Offline Log minium flush count
    UINT                    overrideCameraClose;                ///< Camera close status.  0 for FALSE, 1 for TRUE
    UINT                    overrideCameraOpen;                 ///< Camera open status.  0 for FALSE, 1 for TRUE
    UINT                    overrideDisableZSL;                 ///< Do not select a ZSL usecase.  0 for FALSE, 1 for TRUE
    UINT                    overrideEnableMFNR;                 ///< Enable MFNR selection criteria
                                                                ///< FALSE   = 0,
                                                                ///< TRUE    = 1
    UINT                    overrideForceSensorMode;            ///< Pass in an ID to force a specific sensor mode to be selected, and bypass the selection logic
    UINT                    overrideForceUsecaseId;             ///< Pass in an ID to force a specific use case to be selected, and bypass the selection logic
    UINT                    overrideGPUDownscaleUsecase;        ///< Select only GPU Node Usecase.  0 for FALSE, 1 for TRUE
    UINT                    overrideGPURotationUsecase;         ///< Select only GPU Node Usecase.  0 for FALSE, 1 for TRUE
    UINT                    overrideHAFAlgoMask;                ///<  Bit Mask to control which HAF algorithm will be override
                                                                ///< Bit 0: Override CAF
                                                                ///< BIT 1: Override PDAF
                                                                ///< BIT 2: Override TOF
                                                                ///< BIT 3: Override default mixer
                                                                ///< BIT 4: Override AF Follower
                                                                ///< BIT 5: Override PDAF+TOF Mixer
    UINT                    overrideHFRNo3AUseCase;             ///< Select HFR without 3A Usecase.  0 for FALSE, 1 for TRUE
    UINT                    overrideLogLevels;                  ///< Bitmask of log levels,
                                                                ///< bit 0 - error,
                                                                ///< bit 1 - warning,
                                                                ///< bit 2 - config,
                                                                ///< bit 3 - info,
                                                                ///< bit 4 - dump
                                                                ///< bit 5 - verbose,
                                                                ///< bit 6 - log
                                                                ///< Set bit HIGH to enable
                                                                ///< Bits 0,1,2,3,4 are enabled by default
    UINT                    overrideMaxImageBufferCountNonRealTime; ///< Maximum number of Image Buffers to allocate for non-real time nodes
                                                                ///< 0xffffffff (-1) will completely disable the maximum image buffer count override
                                                                ///< Any positive value can be used as an override.
    UINT                    overrideMaxImageBufferCountRealTime; ///< Maximum number of Image Buffers to allocate for real time nodes
                                                                ///< 0xffffffff (-1) will completely disable the maximum image buffer count override
                                                                ///< Any positive value can be used as an override.
    UINT                    overrideOPPCLOCK;                   ///< Increase the sensor output pixel clock by x %
    UINT                    overridePDLibClose;                 ///< PDLib close status.  0 for FALSE, 1 for TRUE
    UINT                    overridePDLibOpen;                  ///< PDLib open status.  0 for FALSE, 1 for TRUE
    UINT                    preFlashMaxFrameWaitLimitAF;        ///< Max Frames to wait for AF to settle
    UINT                    preFlashMaxFrameWaitLimitAWB;       ///< Max Frames to wait for AWB to settle
    UINT                    profile3A;                          ///< Bit mask for profiling
                                                                ///< Bit       0: AEC module (Range- 0:Disable,1:Enable)
                                                                ///< Bit       1: AWB module (Range- 0:Disable,1:Enable)
                                                                ///< Bit       2: AFD module (Range- 0:Disable,1:Enable)
                                                                ///< Bit       3: ASD module (Range- 0:Disable,1:Enable)
                                                                ///< Bit       4: AF module  (Range- 0:Disable,1:Enable)
                                                                ///< Bit       5: PDLIB module (Range- 0:Disable,1:Enable)
                                                                ///< Bit      24: Camera ID based profiling (Range- 0:Disable,1:Enable)
                                                                ///< Bit 25 - 28: Camera ID (Range- 0-15)
                                                                ///< Bit      31: Time/Trace (Range- 0:Time,1:Trace)
                                                                ///< To enable multiple modules, set corresponding bits.
    UINT                    selectInSensorHDR3ExpUsecase;       ///< Select in-Sensor HDR 3 Exposure usecase and sensor mode:
                                                                ///< 0x0  = None
                                                                ///< 0x1  = Preview
                                                                ///< 0x2  = Seamless snapshot
                                                                ///< 0x10 = Force enable seamless snapshot (for debug usage only and please make sure current sensor is supported)
    UINT                    sensorExposureTime;                 ///< Camera exposure time in nanoseconds
    UINT                    sensorMiddleExposureTime;           ///< Camera middle exposure time in nanoseconds
    UINT                    sensorShortExposureTime;            ///< Camera short exposure time in nanoseconds
    UINT                    sessionFallbackWaitTime;            ///< The time flush will wait after it has timed out (Do not factor this in with max flush wait time).
    UINT                    sessionMaxFlushWaitTime;            ///< The maximum amount of time flush should wait for regardless of what the maximum node reported is.
    UINT                    sessionResponseTimePadding;         ///< The padding time in milliseconds added to the maximum time reported by pipelines. Used by flush to let pipelines
                                                                ///< have some room to inject results and do other processing besides the request processing.
    UINT                    setLRMETransformTypeMask;           ///< This is to set LRME/RANSAC transform type mask:
                                                                ///< Regular LRME/Ransac transform           = 0x1
                                                                ///< HFR interpolation LRME/Ransac transform = 0x2
                                                                ///< Unity LRME/Ransac transform             = 0x4
    UINT                    spdStatsType;                       ///< Spotlight Detection Stats Type
    UINT                    statsProcessingSkipFactor;          ///< Factor to skip stats processing. e.g. 0: invalid. 1: No Skip. 2: skip 1 frame. 3: skip 2 frames
    UINT                    t2tConfidenceThreshold;             ///< T2T SCVE minimum confidence for object to be considered present. 0-100
    UINT                    tfTestMode;                         ///< OVERRIDE_FS_TO_A_MAPPING = 1,
                                                                ///< DISABLE_REFIMEMENT       = 2,
                                                                ///< DISABLE_LMC              = 4,
                                                                ///< TEST_MCTF                = 0x7
    UINT                    touchToTrackDownscaleRatio;         ///< Further downscale ratio from T2T IFE buffer. 1 or 2
    UINT                    touchToTrackSCVEOperationMode;      ///< T2T SCVE operation mode. 0 through 4
    UINT                    touchToTrackSCVEPrecisionMode;      ///< T2T SCVE precision mode. 0 for high 1 for low
    UINT                    traceGroupsEnable;                  ///< Mask of which traces are enabled
    UINT                    tuningDumpDataSizeBPS;              ///< Tuning data size reserved for BPS
    UINT                    tuningDumpDataSizeIFE;              ///< Tuning data reserved for IFE
    UINT                    tuningDumpDataSizeIPE;              ///< Tuning data size reserved for IPE.
    UINT                    useFeatureForQCFA;                  ///< Use Feature Model for Quad CFA Sensor
    UINT                    waitAllResultsTimeout;              ///< Timeout value when waiting for all results
    UINT                    yuvPlaneAlignment;                  ///< This is to update plane align value for internal YUV nodes
};

CAMX_NAMESPACE_END

#endif // G_CAMXSETTINGS_H
