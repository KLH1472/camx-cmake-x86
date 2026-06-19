#ifndef G_CAMXSETTINGS_H
#define G_CAMXSETTINGS_H

#include "camxtypes.h"
#include "camxdefs.h"

CAMX_NAMESPACE_BEGIN

static const UINT32 MaxStringLength = 512;

enum CSLModeType
{
    CSLModeHardware = 0,
    CSLModeIFH = 1,
    CSLModePresil = 2,
    CSLModePresilRUMI = 3,
    CSLModeTypeCount
};

enum EnableAFAlgoType
{
    EnableAFAlgoDisabled = 0,
    EnableAFAlgoPDAF = 1,
    EnableAFAlgoTOF = 2,
    EnableAFAlgoDCIAF = 3,
    EnableAFAlgoCAF = 4,
    EnableAFAlgoTypeCount
};

enum AFFullsweepType
{
    AFFullsweepDisabled = 0,
    AFFullsweepInfinityToMacro = 1,
    AFFullsweepMacroToInfinity = 2,
    AFFullsweepBothDirection = 3,
    AFFullsweepTypeCount
};

enum AFManualLensControlType
{
    AFManualLensControlDisabled = 0,
    AFManualLensControlDAC = 1,
    AFManualLensControlLogical = 2,
    AFManualLensControlTypeCount
};

enum MultiCamera3ASyncType
{
    MultiCamera3ASyncDisabled = 0,
    MultiCamera3ASyncQTI = 1,
    MultiCamera3ASyncSingleton = 2,
    MultiCamera3ASyncTypeCount
};

enum MultiCameraHWSyncType
{
    MultiCameraHWSyncDisabled = 0x0,
    MultiCameraHWSyncRTB = 0x1,
    MultiCameraHWSyncSAT = 0x2,
    MultiCameraHWSyncVR = 0x4,
    MultiCameraHWSyncTypeCount
};

enum OutputFormatType
{
    OutputFormatYUV420NV12 = 0,
    OutputFormatUBWCNV12 = 1,
    OutputFormatUBWCTP10 = 2,
    OutputFormatRAWPLAIN16 = 3,
    OutputFormatPD10 = 4,
    OutputFormatP010 = 5,
    OutputFormatYUV420NV21 = 6,
    OutputFormatRAWPLAIN64 = 7,
    OutputFormatTypeCount
};

enum RefOutputFormatType
{
    RefOutputFormatUBWCTP10 = 0,
    RefOutputFormatUBWCNV124R = 1,
    RefOutputFormatYUV420NV12 = 2,
    RefOutputFormatYUV420NV12TP10 = 3,
    RefOutputFormatP010 = 4,
    RefOutputFormatTypeCount
};

enum FDProcessingControlType
{
    FDProcessingControlForceDisable = 0,
    FDProcessingControlForceEnable = 1,
    FDProcessingControlAppRequest = 2,
    FDProcessingControlTypeCount
};

enum FDBaseResolutionType
{
    FDBaseResolution640x480 = 31457920,
    FDBaseResolution854x480 = 31458134,
    FDBaseResolution320x240 = 15728960,
    FDBaseResolution427x240 = 15729067,
    FDBaseResolutionTypeCount
};

enum FDConfigSourceType
{
    FDConfigDefault = 0,
    FDConfigVendorTag = 1,
    FDConfigBinary = 2,
    FDConfigSourceTypeCount
};

enum FDMultiCamProcessingType
{
    FDMultiCamProcessMasterOnly = 0,
    FDMultiCamProcessAuxOnly = 1,
    FDMultiCamProcessBoth = 2,
    FDMultiCamProcessingTypeCount
};

enum FDFilterEngineType
{
    FD_Standard_ARM = 0,
    FD_Standard_DSP = 1,
    FD_DL_ARM = 2,
    FD_DL_DSP = 3,
    FD_DL_DSP_and_Standard_ARM = 4,
    FDFilterEngineTypeCount
};

enum FDClientType
{
    FDHWHybrid = 0,
    FDSWOnly = 1,
    FDClientTypeCount
};

enum FDPreProcessingType
{
    Disable = 0,
    AdaptiveGTM = 1,
    GTM = 2,
    LTM = 3,
    FDPreProcessingTypeCount
};

enum FDThreadTaskAllocationType
{
    PTDOnPriThread = 0,
    PTDOnSecThread = 1,
    FDThreadTaskAllocationTypeCount
};

enum ImageDumpType
{
    ImageDumpNone = 0x0,
    ImageDumpIFE = 0x1,
    ImageDumpIPE = 0x2,
    ImageDumpBPS = 0x4,
    ImageDumpJPEG = 0x8,
    ImageDumpFDHw = 0x10,
    ImageDumpLRME = 0x20,
    ImageDumpRANSAC = 0x40,
    ImageDumpChiNode = 0x80,
    ImageDumpCVP = 0x100,
    ImageDumpMisc = 0x40000000,
    ImageDumpTypeCount
};

enum DualLEDCalibrationType
{
    DualLEDCalibrationDisabled = 0,
    DualLEDCalibrationTuning = 1,
    DualLEDCalibrationCalibration = 2,
    DualLEDCalibrationTypeCount
};

enum CHIPartialDataType
{
    CHIPartialDataDisable = 0,
    CHIPartialDataSeparate = 1,
    CHIPartialDataCombined = 2,
    CHIPartialDataTypeCount
};

enum AlignmentFusionModes
{
    AlignImageBaseOnly = 0,
    AlignGyroBaseOnly = 1,
    AlignAuto = 2,
    AlignmentFusionModesCount
};

struct StaticSettings
{
    OutputFormatType               outputFormat;
    RefOutputFormatType            refoutputFormatType;
    BOOL    IsStrideSettingEnable;
    UINT32  numMetadataResults;
    UINT32  maxHalRequests;
    UINT32  waitAllResultsTimeout;
    UINT32  numWorkerThreads;
    BOOL    chiOverrideEnable;
    BOOL    multiCameraEnable;
    UINT32  multiCameraJPEG;
    BOOL    multiCameraEnableFront;
    UINT32  multiCameraVREnable;
    UINT32  multiCameraHWSyncMask;
    UINT32  multiCameraFrameSync;
    BOOL    enableSensorFpsMatch;
    MultiCamera3ASyncType          multiCamera3ASync;
    UINT32  numberOfAELockFrames;
    BOOL    exportSecureCamera;
    BOOL    enableRAWProcessing;
    UINT32  maxRAWSizes;
    BOOL    enableInternalHALPixelStreamConfig;
    BOOL    enableNCSService;
    UINT32  minReprocessInputWidth;
    UINT32  minReprocessInputHeight;
    UINT32  minInOutResolution;
    UINT32  maxInOutResolution;
    BOOL    enableTOFInterface;
    BOOL    enableThermalMitigation;
    UINT32  maxBuffersSecureCamera;
    BOOL    enableNativeHEIF;
    BOOL    enableHALFormatOverride;
    UINT32  maxNumberOfAcceptedErrors;
    BOOL    enableResourceManager;
    BOOL    enableStreamCropZoom;
    UINT32  bpsRealtimeSensorId;
    UINT32  enableBLMClient;
    UINT32  assertMask;
    UINT32  logWarningMask;
    UINT32  logEntryExitMask;
    UINT32  logConfigMask;
    UINT32  logDumpMask;
    UINT32  logInfoMask;
    UINT32  logPerfInfoMask;
    UINT32  logVerboseMask;
    BOOL    logDRQEnable;
    BOOL    logMetaEnable;
    BOOL    logRequestMapping;
    BOOL    traceErrorEnable;
    BOOL    systemLogEnable;
    BOOL    enablePipelineFlush;
    CHAR    debugLogFilename[256];
    UINT32  traceGroupsEnable;
    BOOL    enableFPSLog;
    UINT32  maxMemSpyStats;
    UINT32  memSpyRequestRate;
    BOOL    dynamicPropertiesEnabled;
    CHAR    pDebugProcess[256];
    CSLModeType                    CSLMode;
    BOOL    enableSensorEmulation;
    BOOL    enableExternalSensorModule;
    UINT32  enableDebugSensorExposure;
    UINT32  sensorExposureTime;
    FLOAT   gain;
    UINT32  sensorShortExposureTime;
    FLOAT   shortGain;
    UINT32  sensorMiddleExposureTime;
    FLOAT   middleGain;
    BOOL    dumpSensorEmulationOutput;
    CHAR    sensorEmulator[256];
    CHAR    sensorEmulatorPath[256];
    DualLEDCalibrationType         dualLEDCalibrationMode;
    BOOL    dynamicInlineCalibration;
    UINT32  dynamicCalibrationMaxSize;
    CHAR    dualLEDCalibrationPath[256];
    BOOL    disableADRC;
    BOOL    disablePreviewManualISO;
    BOOL    disablePreviewManualExpTime;
    BOOL    disablePreviewManualFull;
    BOOL    disableSpeckleDetection;
    BOOL    disableAFStatsProcessing;
    BOOL    disableAFAlgoCHIOverload;
    BOOL    disableAWBStatsProcessing;
    BOOL    disableAWBAlgoCHIOverload;
    BOOL    disableAFDStatsProcessing;
    BOOL    disableAFDAlgoCHIOverload;
    UINT32  disableASDStatsProcessing;
    BOOL    disableASDAlgoCHIOverload;
    BOOL    debugBufferRegDumpEnable;
    UINT32  debugBufferRegDumpSizeInBytes;
    CHAR    debugBufferRegDumpFileNamePrefix[256];
    BOOL    dumpIPEFirmwarePayload;
    BOOL    kpiDebug;
    BOOL    enableQTimer;
    BOOL    enableTPG;
    BOOL    enableCSIDBinning;
    UINT32  CSIDBinningMode;
    BOOL    force3ALockedResult;
    BOOL    forceDisableUBWCOnIfeIpeLink;
    BOOL    enableUBWCNV124ROnIFEFullOutIPELink;
    BOOL    capResolutionForSingleIFE;
    INT32   singleIFESupportedWidth;
    INT32   singleIFESupportedHeight;
    BOOL    enableFlashDebug;
    BOOL    dumpSensorEEPROMData;
    BOOL    autoImageDump;
    BOOL    dumpInputatOutput;
    UINT32  autoInputImageDumpMask;
    UINT32  IFERegDumpMask;
    UINT32  autoImageDumpMask;
    UINT32  autoImageDumpIFEoutputPortMask;
    UINT32  autoImageDumpIFEinputPortMask;
    UINT32  autoImageDumpIFEoutputBatchNum;
    UINT32  autoImageDumpIFEInstanceMask;
    UINT32  autoImageDumpIPEoutputPortMask;
    UINT32  autoImageDumpIPEinputPortMask;
    UINT32  autoImageDumpIPEInstanceMask;
    UINT32  autoImageDumpBPSoutputPortMask;
    UINT32  autoImageDumpBPSinputPortMask;
    UINT32  autoImageDumpBPSInstanceMask;
    UINT32  autoImageDumpJpegHwoutputPortMask;
    UINT32  autoImageDumpJpegHwinputPortMask;
    UINT32  autoImageDumpJpegHwInstanceMask;
    UINT32  autoImageDumpFDHwoutputPortMask;
    UINT32  autoImageDumpFDHwinputPortMask;
    UINT32  autoImageDumpFDHwInstanceMask;
    UINT32  autoImageDumpLRMEoutputPortMask;
    UINT32  autoImageDumpLRMEinputPortMask;
    UINT32  autoImageDumpLRMEInstanceMask;
    UINT32  autoImageDumpRANSACoutputPortMask;
    UINT32  autoImageDumpRANSACinputPortMask;
    UINT32  autoImageDumpRANSACInstanceMask;
    UINT32  autoImageDumpCHINodeoutputPortMask;
    UINT32  autoImageDumpCHINodeinputPortMask;
    UINT32  autoImageDumpCHINodeInstanceMask;
    UINT32  autoImageDumpCVPoutputPortMask;
    UINT32  autoImageDumpCVPinputPortMask;
    UINT32  autoImageDumpCVPInstanceMask;
    BOOL    dynamicImageDump;
    BOOL    dynamicImageDumpTrigger;
    BOOL    watermarkImage;
    CHAR    watermarkOffset[256];
    BOOL    reprocessDump;
    BOOL    offlineImageDumpOnly;
    UINT32  enableIPEHangDump;
    UINT32  enableBPSHangDump;
    BOOL    enableIPEStripeDump;
    BOOL    enableBPSStripeDump;
    BOOL    enableIPEScratchBufferDump;
    UINT32  forceMaxFPS;
    UINT32  kickTheMachine;
    BOOL    perFrameSensorMode;
    BOOL    disablePDAF;
    BOOL    enableTouchToTrack;
    UINT32  touchToTrackDownscaleRatio;
    UINT32  touchToTrackSCVEOperationMode;
    UINT32  touchToTrackSCVEPrecisionMode;
    UINT32  t2tConfidenceThreshold;
    UINT32  defaultMaxFPS;
    BOOL    bypassIPEICADependency;
    BOOL    disableDRQPreemptionOnStopRecord;
    BOOL    disableVideoPerfModeSetting;
    BOOL    enableSensorAcquireOptimization;
    INT32   camVersionOverride;
    UINT32  overrideOPPCLOCK;
    BOOL    dumpGeolibResult;
    BOOL    dumpCVPICAInputConfig;
    UINT32  tfTestMode;
    BOOL    enableHJAF;
    BOOL    enableSPD;
    UINT32  spdStatsType;
    BOOL    disableFocusIndication;
    BOOL    spotlightFallbackToCAF;
    UINT32  afLog;
    UINT32  fovcEnable;
    UINT32  gyroDataReportRate;
    FLOAT   gyroSensorSamplingRate;
    UINT32  gravityDataReportRate;
    FLOAT   gravitySensorSamplingRate;
    UINT32  TOFDataReportRate;
    FLOAT   TOFSensorSamplingRate;
    CHAR    customTOFSensorLib[256];
    BOOL    mwEnable;
    EnableAFAlgoType               enableAFAlgo;
    AFFullsweepType                afFullsweep;
    AFManualLensControlType        manualAf;
    UINT32  lensPos;
    CHAR    vmDebugMask[256];
    UINT32  AFRecorderMode;
    BOOL    enableLensSagComp;
    CHAR    activeNodeMask[256];
    UINT32  apiMask;
    BOOL    manualExposureType;
    BOOL    dualBHistSupport;
    BOOL    disableBGStatsForAF;
    BOOL    enableCustomAlgoAEC;
    BOOL    disableAFAWBpreFlash;
    UINT32  yuvPlaneAlignment;
    UINT32  preFlashMaxFrameWaitLimitAF;
    UINT32  preFlashMaxFrameWaitLimitAWB;
    BOOL    disablePreFlashOnForTouchAE;
    UINT32  numberOfFramesToSkip;
    CHAR    customAlgoAECName[256];
    CHAR    customAlgoAECPath[256];
    BOOL    enableCustomAlgoAWB;
    CHAR    customAlgoAWBName[256];
    CHAR    customAlgoAWBPath[256];
    BOOL    enableCustomAlgoAF;
    CHAR    customAlgoAFName[256];
    CHAR    customAlgoAFPath[256];
    BOOL    enableCustomHAFAlgo;
    CHAR    customHAFAlgoName[256];
    CHAR    customHAFAlgoPath[256];
    UINT32  overrideHAFAlgoMask;
    FLOAT   exposureGain;
    UINT32  exposureTime;
    FLOAT   luxIndex;
    BOOL    extendedTimeForLongExposure;
    BOOL    manualWhiteBalanceType;
    FLOAT   rGain;
    FLOAT   gGain;
    FLOAT   BGain;
    UINT32  colorTemp;
    BOOL    ignoreSceneMode;
    BOOL    enableCustomAlgoASD;
    CHAR    customAlgoASDName[256];
    CHAR    customAlgoASDPath[256];
    BOOL    enableCustomAlgoAFD;
    CHAR    customAlgoAFDName[256];
    CHAR    customAlgoAFDPath[256];
    BOOL    enableDualIFE;
    BOOL    forceDualIFEOn;
    INT32   dualIFESplitPointOffset;
    UINT32  dualIFELeftPadding;
    UINT32  dualIFERightPadding;
    UINT32  IFETestImageSizeWidth;
    UINT32  IFETestImageSizeHeight;
    BOOL    IsOEMStatSettingEnable;
    BOOL    DisableManual3ACCM;
    UINT32  IFENumFramesHighBW;
    BOOL    pdafHWEnable;
    BOOL    enableIFERegDump;
    BOOL    enableActiveIFEABVote;
    UINT32  IFEDynamicEnableMask;
    UINT32  ifeClockFrequencyMHz;
    UINT32  ifeCamnocBandwidthMBytes;
    UINT32  ifeExternalBandwidthMBytes;
    BOOL    enableHVXStreaming;
    UINT32  enableIPEIQModulesMask;
    BOOL    enableIPEUpscale;
    BOOL    enableIPEOnlyDownscale;
    BOOL    disableIPEInternalDownscale;
    BOOL    enableIPEDependencies;
    BOOL    enableIPEIQLogging;
    BOOL    enableMCTF;
    BOOL    disableCVPDriver;
    UINT32  numIPECoresToUse;
    BOOL    force8BitUBWCAlignment;
    UINT32  setLRMETransformTypeMask;
    BOOL    isGridFromChromatixEnabled;
    AlignmentFusionModes           alignmentFusionMode;
    UINT32  isFirstFrameLoopbackInputImageEnabled;
    BOOL    enableLDC;
    CHAR    debugDataHeaderString[256];
    BOOL    enable3ADebugData;
    UINT32  debugDataSizeAEC;
    UINT32  debugDataSizeAWB;
    UINT32  debugDataSizeAF;
    BOOL    enableTuningMetadata;
    UINT32  tuningDumpDataSizeIFE;
    UINT32  tuningDumpDataSizeIPE;
    UINT32  tuningDumpDataSizeBPS;
    UINT32  dumpDebugDataEveryProcessResult;
    BOOL    debugDataOfflineAlloc;
    BOOL    disablePDLibCHIOverload;
    BOOL    enableCustomPDLib;
    CHAR    customPDLibName[256];
    CHAR    customPDLibPath[256];
    BOOL    tintlessEnable;
    UINT32  enablePDLibLog;
    UINT32  enablePDLibTestMode;
    BOOL    enablePDLibProfiling;
    UINT32  enablePDLibDump;
    BOOL    disablePDLibLCR;
    BOOL    ifeSWCDMEnable;
    UINT32  enableAEScan;
    UINT32  overrideLogLevels;
    UINT32  overrideDisableZSL;
    BOOL    enableLRMEDS2;
    UINT32  overrideEnableMFNR;
    UINT32  anchorSelectionAlgoForMFNR;
    UINT32  anchorAlgoSelectionType;
    UINT32  advanceFeatureMask;
    UINT32  enableOfflineNoiseReprocess;
    UINT32  enableGamma15PreCalculate;
    UINT32  overrideForceUsecaseId;
    UINT32  overrideForceSensorMode;
    BOOL    overrideForceFSCapable;
    UINT32  overrideGPURotationUsecase;
    UINT32  overrideGPUDownscaleUsecase;
    UINT32  overrideHFRNo3AUseCase;
    UINT32  overrideCameraClose;
    UINT32  overrideCameraOpen;
    UINT32  overridePDLibClose;
    UINT32  overridePDLibOpen;
    UINT32  EISV2Enable;
    UINT32  EISV3Enable;
    FLOAT   EISV2Margin;
    UINT32  EISV2FrameDelay;
    FLOAT   EISV3Margin;
    UINT32  EISV3FrameDelay;
    UINT32  numPCRsBeforeStreamOn;
    UINT32  maxImageBufferTimeoutCount;
    UINT32  imageBufferWaitTime;
    UINT32  overrideMaxImageBufferCountRealTime;
    UINT32  overrideMaxImageBufferCountNonRealTime;
    UINT32  statsProcessingSkipFactor;
    UINT32  maxNonHfrFps;
    UINT32  minFrameRateBound;
    BOOL    enableOISOptimization;
    BOOL    enableSensorCaching;
    BOOL    forceDebugQCFASWRemosaic;
    CHIPartialDataType             enableCHIPartialData;
    UINT32  enableCHIPartialDataRecovery;
    UINT32  dumpMetadata;
    UINT32  memsetInputMeta;
    BOOL    enableLinearMetaLUT;
    UINT32  enableFDStreamInRealTime;
    UINT32  selectInSensorHDR3ExpUsecase;
    UINT32  enableUnifiedBufferManager;
    UINT32  enableCHIImageBufferLateBinding;
    UINT32  enableFeature2Dump;
    UINT32  forceHWMFFixedNumOfFrames;
    UINT32  enableTBMChiFence;
    UINT32  enableMFSRChiFence;
    UINT32  enableRawHDR;
    FDProcessingControlType        FDProcessingControl;
    BOOL    enableFDManagerThreading;
    FDBaseResolutionType           FDBaseResolution;
    FDConfigSourceType             FDConfigSource;
    FDMultiCamProcessingType       FDMultiCamProcess;
    BOOL    useAlternateFrameSkip;
    BOOL    useDeviceOrientationInFD;
    BOOL    getAccelInfoUsingVendorTag;
    CHAR    accelVendorTagSection[256];
    CHAR    accelVendorTagName[256];
    FDFilterEngineType             FDFilterEngine;
    FDClientType                   FDClient;
    BOOL    disablePostingResults;
    BOOL    enableOfflineFD;
    BOOL    MetadataVisibility;
    BOOL    useDifferentTuningForFrontCamera;
    BOOL    useFDInternalBuffers;
    BOOL    useFDUseCasePool;
    BOOL    fastFDMetadata;
    UINT32  minReqFdDependency;
    FDPreProcessingType            FDPreprocessing;
    BOOL    enableFDPreprocessingAlways;
    BOOL    enableFDPreprocessDumping;
    BOOL    acceptAppUIFacialAttrSettings;
    BOOL    enablePTDetection;
    BOOL    enableSMDetection;
    BOOL    enableGBDetection;
    BOOL    enableCTDetection;
    FDThreadTaskAllocationType     FDThreadTaskAllocation;
    BOOL    enableJPEGEXIFApp2;
    BOOL    exposeFullSizeForQCFA;
    UINT32  useFeatureForQCFA;
    FLOAT   AECGainThresholdForQCFA;
    BOOL    disableFlash;
    BOOL    enableWatchdogRecovery;
    UINT32  nodeResponseTime;
    UINT32  sessionResponseTimePadding;
    UINT32  sessionMaxFlushWaitTime;
    UINT32  sessionFallbackWaitTime;
    UINT32  feature1;
    UINT32  feature2;
    BOOL    raisesigabrt;
    BOOL    raiserecoverysigabrt;
    BOOL    enableRecovery;
    UINT32  enableAsciiLogging;
    UINT32  enableBinaryLogging;
    UINT32  offlineLoggerMinFlushCnt;
    BOOL    enableFenceDrop;
    BOOL    inducerIsRealTime;
    CHAR    inducerPipelineName[256];
    CHAR    inducerNodeName[256];
    UINT32  inducerRequestId;
    INT32   inducerPortId;
    BOOL    inducerFenceMarkError;
    BOOL    sessionDumpForFlush;
    BOOL    sessionDumpToLog;
    BOOL    sessionDumpToFile;
    BOOL    sessionDumpForRecovery;
    BOOL    dumpNodeProcessingInfo;
    BOOL    dumpSessionProcessingInfo;
    UINT32  numberOfCHIThreads;
    BOOL    useVFETPG;
    UINT32  IFEBufDoneTimeout;
    UINT32  IFEInputWidth;
    UINT32  IFEInputHeight;
    UINT32  IPEBufDoneTimeout;
    UINT32  IPEUnitTestIQBypassNumOfIteration;
    BOOL    enableImageBufferLateBinding;
    BOOL    MPMEnable;
    BOOL    MPMValidateMemPoolGroup;
    BOOL    MPMDoNotGroupBufferManagers;
    UINT32  MPMKeepMinNumFreeBuffers;
    BOOL    MPMAllocateBuffersOnRegister;
    BOOL    MPMGroupIfExactDeviceMatch;
    UINT32  MPMMinSizeForSharing;
    UINT32  MPMSizeDiffAllowedToGroup;
    UINT32  MPMLargeGroupSizeDefinition;
    UINT32  MPMSizeDiffAllowedToGroupOverride;
    UINT32  MPMBufferAddressAlignment;
    UINT32  forceCHIBufferManagerHeap;
    BOOL    MPMSelfTuneImmediateCount;
    BOOL    enableMPMMonitorThread;
    UINT32  MPMMonitorTimeInterval;
    UINT32  MPMMonitorSelfShrinkSizeLimit;
    BOOL    enableMPMStatelogging;
    BOOL    enableMemoryStats;
    UINT32  MPMMinSizeToFreeOnDeactivate;
    BOOL    validateImageBufferUsageState;
    UINT32  MPMSizeThresToDisableDelayedUnmap;
    BOOL    MPMForceDisableDelayedUnmap;
    UINT32  MPMSizeThresToDelayedMap;
    UINT32  dumpAF;
    UINT32  dumpAEC;
    UINT32  dumpAWB;
    BOOL    dumpAFDRowsum;
    UINT32  profile3A;
};

CAMX_NAMESPACE_END

#endif
