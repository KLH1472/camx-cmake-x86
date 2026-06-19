////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  g_camxtitan17xsettings.cpp
/// @brief Titan17x-Specific Settings implementation.
///
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///             !!!!!!! AUTO-GENERATED FILE! DO NOT EDIT! Make all changes in camxtitan17xsettings.xml. !!!!!!!
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxincs.h"
#include "camxtitan17xsettingsmanager.h"

#include "g_camxtitan17xsettings.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Type Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EnumeratorToHashMap IQModuleForceModeEnumeratorToHashMap[] =
{
    {0xFE7F187F, IQModuleForceDisable            }, ///< Force an IQ module to be disabled
    {0xD58AF509, IQModuleForceEnable             }, ///< Force an IQ module to be enabled, if available
    {0xE72F446E, IQModuleForceDefault            }, ///< Use driver default settings
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Titan17xSettingsManager Method Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titan17xSettingsManager::HwInitializeDefaultSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID Titan17xSettingsManager::HwInitializeDefaultSettings()
{
    m_titan17xStaticSettings.IPESwStriping                  = TRUE;
    m_titan17xStaticSettings.BPSSwStriping                  = TRUE;
    m_titan17xStaticSettings.disableIPEICADependenciesMFNR  = TRUE;
    m_titan17xStaticSettings.IPEMaxInpWidth                 = 16383;
    m_titan17xStaticSettings.IPEMaxOutWidth                 = 16383;
    m_titan17xStaticSettings.IPEMinInpWidth                 = 640;
    m_titan17xStaticSettings.IPEMinOutputWidth              = 160;
    m_titan17xStaticSettings.IFEEnableHardcodedConfig       = FALSE;
    m_titan17xStaticSettings.IFEUseHardcodedRegisterValues  = FALSE;
    m_titan17xStaticSettings.BPSUseHardcodedRegisterValues  = FALSE;
    m_titan17xStaticSettings.IsOEMIQSettingEnable           = FALSE;
    m_titan17xStaticSettings.disableUBWCv3                  = FALSE;
    m_titan17xStaticSettings.enableIFEOutputGrouping        = TRUE;
    m_titan17xStaticSettings.IFEDualClockThreshold          = 0xffffffff;
    m_titan17xStaticSettings.enableIFEDualStripeInfo        = FALSE;
    m_titan17xStaticSettings.enableIFESettingsDump          = FALSE;
    m_titan17xStaticSettings.dumpIFERegConfigMask           = 0xFFFFFF;
    m_titan17xStaticSettings.IsICAIQSettingEnable           = FALSE;
    m_titan17xStaticSettings.enableICACommonIQModule        = TRUE;
    m_titan17xStaticSettings.enableANRCommonIQModule        = TRUE;
    m_titan17xStaticSettings.enableTFCommonIQModule         = TRUE;
    m_titan17xStaticSettings.enableGRACommonIQModule        = TRUE;
    m_titan17xStaticSettings.IPEDurationInNumFrames         = 0x4;
    m_titan17xStaticSettings.disableLENRDS4Buffer           = TRUE;
    m_titan17xStaticSettings.ignoreChromatixRGammaFlag      = FALSE;
    m_titan17xStaticSettings.useHardcodedGamma              = FALSE;
    m_titan17xStaticSettings.enableICAInGrid                = TRUE;
    m_titan17xStaticSettings.enableICARefGrid               = FALSE;
    m_titan17xStaticSettings.dumpICAOut                     = FALSE;
    m_titan17xStaticSettings.validateTFParams               = FALSE;
    m_titan17xStaticSettings.validateANRSettings            = FALSE;
    m_titan17xStaticSettings.dumpIPERegConfig               = FALSE;
    m_titan17xStaticSettings.dumpIPERegConfigMask           = 0xFFFFFF;
    m_titan17xStaticSettings.disableTFRefinement            = FALSE;
    m_titan17xStaticSettings.HALOutputBufferCombined        = TRUE;
    m_titan17xStaticSettings.forceBPSPedestalCorrection     = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSLinearization          = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSBPCPDPC                = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSDemux                  = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSHDR                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSABF                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSLSC                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSGIC                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSDemosaic               = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSCC                     = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSGTM                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSGamma                  = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSCST                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSChromaSubSample        = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSHNR                    = IQModuleForceDefault;
    m_titan17xStaticSettings.forceBPSWB                     = IQModuleForceDefault;
    m_titan17xStaticSettings.pipelineDelay                  = 4;
    m_titan17xStaticSettings.dumpBPSRegConfigMask           = 0x7FFFFF;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titan17xSettingsManager::HwInitializeDefaultDebugSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID Titan17xSettingsManager::HwInitializeDefaultDebugSettings()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titan17xSettingsManager::HwLoadOverrideSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CamxResult Titan17xSettingsManager::HwLoadOverrideSettings(
    IOverrideSettingsStore* pOverrideSettingsStore)
{
    CamxResult  result      = CamxResultSuccess;
    BOOL        tempBOOL    = FALSE;

    tempBOOL = (m_titan17xStaticSettings.IPESwStriping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIPESwStriping,
        &tempBOOL);
    m_titan17xStaticSettings.IPESwStriping = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.BPSSwStriping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashBPSSwStriping,
        &tempBOOL);
    m_titan17xStaticSettings.BPSSwStriping = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.disableIPEICADependenciesMFNR == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableIPEICADependenciesMFNR,
        &tempBOOL);
    m_titan17xStaticSettings.disableIPEICADependenciesMFNR = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEMaxInpWidth,
        &m_titan17xStaticSettings.IPEMaxInpWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEMaxOutWidth,
        &m_titan17xStaticSettings.IPEMaxOutWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEMinInpWidth,
        &m_titan17xStaticSettings.IPEMinInpWidth);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEMinOutputWidth,
        &m_titan17xStaticSettings.IPEMinOutputWidth);

    tempBOOL = (m_titan17xStaticSettings.IFEEnableHardcodedConfig == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIFEEnableHardcodedConfig,
        &tempBOOL);
    m_titan17xStaticSettings.IFEEnableHardcodedConfig = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.IFEUseHardcodedRegisterValues == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIFEUseHardcodedRegisterValues,
        &tempBOOL);
    m_titan17xStaticSettings.IFEUseHardcodedRegisterValues = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.BPSUseHardcodedRegisterValues == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashBPSUseHardcodedRegisterValues,
        &tempBOOL);
    m_titan17xStaticSettings.BPSUseHardcodedRegisterValues = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.IsOEMIQSettingEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIsOEMIQSettingEnable,
        &tempBOOL);
    m_titan17xStaticSettings.IsOEMIQSettingEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.disableUBWCv3 == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableUBWCv3,
        &tempBOOL);
    m_titan17xStaticSettings.disableUBWCv3 = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableIFEOutputGrouping == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIFEOutputGrouping,
        &tempBOOL);
    m_titan17xStaticSettings.enableIFEOutputGrouping = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIFEDualClockThreshold,
        &m_titan17xStaticSettings.IFEDualClockThreshold);

    tempBOOL = (m_titan17xStaticSettings.enableIFEDualStripeInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIFEDualStripeInfo,
        &tempBOOL);
    m_titan17xStaticSettings.enableIFEDualStripeInfo = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableIFESettingsDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableIFESettingsDump,
        &tempBOOL);
    m_titan17xStaticSettings.enableIFESettingsDump = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpIFERegConfigMask,
        &m_titan17xStaticSettings.dumpIFERegConfigMask);

    tempBOOL = (m_titan17xStaticSettings.IsICAIQSettingEnable == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIsICAIQSettingEnable,
        &tempBOOL);
    m_titan17xStaticSettings.IsICAIQSettingEnable = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableICACommonIQModule == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableICACommonIQModule,
        &tempBOOL);
    m_titan17xStaticSettings.enableICACommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableANRCommonIQModule == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableANRCommonIQModule,
        &tempBOOL);
    m_titan17xStaticSettings.enableANRCommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableTFCommonIQModule == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableTFCommonIQModule,
        &tempBOOL);
    m_titan17xStaticSettings.enableTFCommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableGRACommonIQModule == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableGRACommonIQModule,
        &tempBOOL);
    m_titan17xStaticSettings.enableGRACommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashIPEDurationInNumFrames,
        &m_titan17xStaticSettings.IPEDurationInNumFrames);

    tempBOOL = (m_titan17xStaticSettings.disableLENRDS4Buffer == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableLENRDS4Buffer,
        &tempBOOL);
    m_titan17xStaticSettings.disableLENRDS4Buffer = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.ignoreChromatixRGammaFlag == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashIgnoreChromatixRGammaFlag,
        &tempBOOL);
    m_titan17xStaticSettings.ignoreChromatixRGammaFlag = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.useHardcodedGamma == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashUseHardcodedGamma,
        &tempBOOL);
    m_titan17xStaticSettings.useHardcodedGamma = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableICAInGrid == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableICAInGrid,
        &tempBOOL);
    m_titan17xStaticSettings.enableICAInGrid = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableICARefGrid == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashEnableICARefGrid,
        &tempBOOL);
    m_titan17xStaticSettings.enableICARefGrid = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.dumpICAOut == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpICAOut,
        &tempBOOL);
    m_titan17xStaticSettings.dumpICAOut = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.validateTFParams == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashValidateTFParams,
        &tempBOOL);
    m_titan17xStaticSettings.validateTFParams = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.validateANRSettings == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashValidateANRSettings,
        &tempBOOL);
    m_titan17xStaticSettings.validateANRSettings = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.dumpIPERegConfig == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDumpIPERegConfig,
        &tempBOOL);
    m_titan17xStaticSettings.dumpIPERegConfig = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpIPERegConfigMask,
        &m_titan17xStaticSettings.dumpIPERegConfigMask);

    tempBOOL = (m_titan17xStaticSettings.disableTFRefinement == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashDisableTFRefinement,
        &tempBOOL);
    m_titan17xStaticSettings.disableTFRefinement = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.HALOutputBufferCombined == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        StringHashHALOutputBufferCombined,
        &tempBOOL);
    m_titan17xStaticSettings.HALOutputBufferCombined = (tempBOOL == TRUE) ? 1 : 0;

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSPedestalCorrection,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSPedestalCorrection),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSLinearization,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSLinearization),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSBPCPDPC,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSBPCPDPC),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSDemux,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSDemux),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSHDR,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSHDR),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSABF,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSABF),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSLSC,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSLSC),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSGIC,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSGIC),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSDemosaic,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSDemosaic),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSCC,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSCC),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSGTM,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSGTM),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSGamma,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSGamma),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSCST,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSCST),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSChromaSubSample,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSChromaSubSample),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSHNR,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSHNR),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingEnum(
        StringHashForceBPSWB,
        reinterpret_cast<INT*>(&m_titan17xStaticSettings.forceBPSWB),
        IQModuleForceModeEnumeratorToHashMap,
        static_cast<UINT>(CAMX_ARRAY_SIZE(IQModuleForceModeEnumeratorToHashMap)));

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashPipelineDelay,
        &m_titan17xStaticSettings.pipelineDelay);

    pOverrideSettingsStore->ReadSettingUINT(
        StringHashDumpBPSRegConfigMask,
        &m_titan17xStaticSettings.dumpBPSRegConfigMask);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titan17xSettingsManager::HwLoadOverrideProperties
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CamxResult Titan17xSettingsManager::HwLoadOverrideProperties(
    IOverrideSettingsStore* pOverrideSettingsStore,
    BOOL                    updateStatic)
{
    CamxResult  result      = CamxResultSuccess;
    BOOL        tempBOOL    = FALSE;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.IPESwStriping == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIPESwStriping,
            &tempBOOL);
        m_titan17xStaticSettings.IPESwStriping = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.BPSSwStriping == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashBPSSwStriping,
            &tempBOOL);
        m_titan17xStaticSettings.BPSSwStriping = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.disableIPEICADependenciesMFNR == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableIPEICADependenciesMFNR,
            &tempBOOL);
        m_titan17xStaticSettings.disableIPEICADependenciesMFNR = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.IFEEnableHardcodedConfig == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIFEEnableHardcodedConfig,
            &tempBOOL);
        m_titan17xStaticSettings.IFEEnableHardcodedConfig = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_titan17xStaticSettings.IFEUseHardcodedRegisterValues == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashIFEUseHardcodedRegisterValues,
        &tempBOOL);
    m_titan17xStaticSettings.IFEUseHardcodedRegisterValues = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.BPSUseHardcodedRegisterValues == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashBPSUseHardcodedRegisterValues,
        &tempBOOL);
    m_titan17xStaticSettings.BPSUseHardcodedRegisterValues = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableIFEDualStripeInfo == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableIFEDualStripeInfo,
        &tempBOOL);
    m_titan17xStaticSettings.enableIFEDualStripeInfo = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.enableIFESettingsDump == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashEnableIFESettingsDump,
        &tempBOOL);
    m_titan17xStaticSettings.enableIFESettingsDump = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDumpIFERegConfigMask,
            &m_titan17xStaticSettings.dumpIFERegConfigMask);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.IsICAIQSettingEnable == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIsICAIQSettingEnable,
            &tempBOOL);
        m_titan17xStaticSettings.IsICAIQSettingEnable = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableICACommonIQModule == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableICACommonIQModule,
            &tempBOOL);
        m_titan17xStaticSettings.enableICACommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableANRCommonIQModule == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableANRCommonIQModule,
            &tempBOOL);
        m_titan17xStaticSettings.enableANRCommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableTFCommonIQModule == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableTFCommonIQModule,
            &tempBOOL);
        m_titan17xStaticSettings.enableTFCommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableGRACommonIQModule == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableGRACommonIQModule,
            &tempBOOL);
        m_titan17xStaticSettings.enableGRACommonIQModule = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashIPEDurationInNumFrames,
            &m_titan17xStaticSettings.IPEDurationInNumFrames);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.disableLENRDS4Buffer == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableLENRDS4Buffer,
            &tempBOOL);
        m_titan17xStaticSettings.disableLENRDS4Buffer = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.ignoreChromatixRGammaFlag == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashIgnoreChromatixRGammaFlag,
            &tempBOOL);
        m_titan17xStaticSettings.ignoreChromatixRGammaFlag = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.useHardcodedGamma == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashUseHardcodedGamma,
            &tempBOOL);
        m_titan17xStaticSettings.useHardcodedGamma = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableICAInGrid == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableICAInGrid,
            &tempBOOL);
        m_titan17xStaticSettings.enableICAInGrid = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.enableICARefGrid == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashEnableICARefGrid,
            &tempBOOL);
        m_titan17xStaticSettings.enableICARefGrid = (tempBOOL == TRUE) ? 1 : 0;

    }

    tempBOOL = (m_titan17xStaticSettings.dumpICAOut == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashDumpICAOut,
        &tempBOOL);
    m_titan17xStaticSettings.dumpICAOut = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.validateTFParams == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashValidateTFParams,
        &tempBOOL);
    m_titan17xStaticSettings.validateTFParams = (tempBOOL == TRUE) ? 1 : 0;

    tempBOOL = (m_titan17xStaticSettings.validateANRSettings == 1) ? TRUE : FALSE;
    pOverrideSettingsStore->ReadSettingBOOL(
        PropStringHashValidateANRSettings,
        &tempBOOL);
    m_titan17xStaticSettings.validateANRSettings = (tempBOOL == TRUE) ? 1 : 0;

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.dumpIPERegConfig == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDumpIPERegConfig,
            &tempBOOL);
        m_titan17xStaticSettings.dumpIPERegConfig = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDumpIPERegConfigMask,
            &m_titan17xStaticSettings.dumpIPERegConfigMask);

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.disableTFRefinement == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashDisableTFRefinement,
            &tempBOOL);
        m_titan17xStaticSettings.disableTFRefinement = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        tempBOOL = (m_titan17xStaticSettings.HALOutputBufferCombined == 1) ? TRUE : FALSE;
        pOverrideSettingsStore->ReadSettingBOOL(
            PropStringHashHALOutputBufferCombined,
            &tempBOOL);
        m_titan17xStaticSettings.HALOutputBufferCombined = (tempBOOL == TRUE) ? 1 : 0;

    }

    if (TRUE == updateStatic)
    {
        pOverrideSettingsStore->ReadSettingUINT(
            PropStringHashDumpBPSRegConfigMask,
            &m_titan17xStaticSettings.dumpBPSRegConfigMask);

    }

    return result;
}

#if SETTINGS_DUMP_ENABLE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titan17xSettingsManager::HwDumpSettings
///
/// @note  This method is part of the SettingsManager implementation. See camxsettingsmanager.h.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID Titan17xSettingsManager::HwDumpSettings() const
{
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "=============== BEGIN DUMP OF CURRENT TITAN17X HARDWARE-DEPENDENT SETTINGS VALUES ===============");
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "<Setting> (<Hash>) = <Value>");
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPESwStriping (0x4B33BD24) = %d", m_titan17xStaticSettings.IPESwStriping);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "BPSSwStriping (0xFB6BBD24) = %d", m_titan17xStaticSettings.BPSSwStriping);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableIPEICADependenciesMFNR (0x82E60165) = %d", m_titan17xStaticSettings.disableIPEICADependenciesMFNR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEMaxInpWidth (0x547D456E) = %d", m_titan17xStaticSettings.IPEMaxInpWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEMaxOutWidth (0x9C7D4558) = %d", m_titan17xStaticSettings.IPEMaxOutWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEMinInpWidth (0x547C536E) = %d", m_titan17xStaticSettings.IPEMinInpWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEMinOutputWidth (0x099D50E9) = %d", m_titan17xStaticSettings.IPEMinOutputWidth);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEEnableHardcodedConfig (0x58396CD5) = %d", m_titan17xStaticSettings.IFEEnableHardcodedConfig);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEUseHardcodedRegisterValues (0x59BE998C) = %d", m_titan17xStaticSettings.IFEUseHardcodedRegisterValues);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "BPSUseHardcodedRegisterValues (0x59BE22D4) = %d", m_titan17xStaticSettings.BPSUseHardcodedRegisterValues);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IsOEMIQSettingEnable (0x4E099D1C) = %d", m_titan17xStaticSettings.IsOEMIQSettingEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableUBWCv3 (0xD95A438C) = %d", m_titan17xStaticSettings.disableUBWCv3);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIFEOutputGrouping (0x8E74CD3A) = %d", m_titan17xStaticSettings.enableIFEOutputGrouping);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IFEDualClockThreshold (0x23F2B3DA) = %d", m_titan17xStaticSettings.IFEDualClockThreshold);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIFEDualStripeInfo (0x7B88908A) = %d", m_titan17xStaticSettings.enableIFEDualStripeInfo);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableIFESettingsDump (0xA9361A6F) = %d", m_titan17xStaticSettings.enableIFESettingsDump);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpIFERegConfigMask (0x9E84571C) = %d", m_titan17xStaticSettings.dumpIFERegConfigMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IsICAIQSettingEnable (0x4ECFFD1C) = %d", m_titan17xStaticSettings.IsICAIQSettingEnable);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableICACommonIQModule (0xE729CE11) = %d", m_titan17xStaticSettings.enableICACommonIQModule);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableANRCommonIQModule (0xE721A2D1) = %d", m_titan17xStaticSettings.enableANRCommonIQModule);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableTFCommonIQModule (0x5E1C2120) = %d", m_titan17xStaticSettings.enableTFCommonIQModule);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableGRACommonIQModule (0xE7274611) = %d", m_titan17xStaticSettings.enableGRACommonIQModule);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "IPEDurationInNumFrames (0x53695587) = %d", m_titan17xStaticSettings.IPEDurationInNumFrames);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableLENRDS4Buffer (0x9A56B8B8) = %d", m_titan17xStaticSettings.disableLENRDS4Buffer);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "ignoreChromatixRGammaFlag (0x821EA2C2) = %d", m_titan17xStaticSettings.ignoreChromatixRGammaFlag);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "useHardcodedGamma (0xA6ABB46E) = %d", m_titan17xStaticSettings.useHardcodedGamma);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableICAInGrid (0xB46E96DE) = %d", m_titan17xStaticSettings.enableICAInGrid);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "enableICARefGrid (0x5BC83614) = %d", m_titan17xStaticSettings.enableICARefGrid);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpICAOut (0xD40DC4A0) = %d", m_titan17xStaticSettings.dumpICAOut);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "validateTFParams (0xC5A1C7F4) = %d", m_titan17xStaticSettings.validateTFParams);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "validateANRSettings (0x0833D4D6) = %d", m_titan17xStaticSettings.validateANRSettings);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpIPERegConfig (0x358979EB) = %d", m_titan17xStaticSettings.dumpIPERegConfig);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpIPERegConfigMask (0x9E84529C) = %d", m_titan17xStaticSettings.dumpIPERegConfigMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "disableTFRefinement (0x6CA12FC1) = %d", m_titan17xStaticSettings.disableTFRefinement);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "HALOutputBufferCombined (0x246894F2) = %d", m_titan17xStaticSettings.HALOutputBufferCombined);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSPedestalCorrection (0x53D990B6) = %d", m_titan17xStaticSettings.forceBPSPedestalCorrection);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSLinearization (0x031961B2) = %d", m_titan17xStaticSettings.forceBPSLinearization);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSBPCPDPC (0x7611B4BA) = %d", m_titan17xStaticSettings.forceBPSBPCPDPC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSDemux (0xB6373CD2) = %d", m_titan17xStaticSettings.forceBPSDemux);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSHDR (0x82ADBDF3) = %d", m_titan17xStaticSettings.forceBPSHDR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSABF (0x82AD9927) = %d", m_titan17xStaticSettings.forceBPSABF);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSLSC (0x82ADAF02) = %d", m_titan17xStaticSettings.forceBPSLSC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSGIC (0x82AD8042) = %d", m_titan17xStaticSettings.forceBPSGIC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSDemosaic (0x9FCD5258) = %d", m_titan17xStaticSettings.forceBPSDemosaic);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSCC (0x0C156C8B) = %d", m_titan17xStaticSettings.forceBPSCC);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSGTM (0x82AD83EC) = %d", m_titan17xStaticSettings.forceBPSGTM);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSGamma (0xB6053FCB) = %d", m_titan17xStaticSettings.forceBPSGamma);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSCST (0x82AD9315) = %d", m_titan17xStaticSettings.forceBPSCST);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSChromaSubSample (0x6E35C452) = %d", m_titan17xStaticSettings.forceBPSChromaSubSample);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSHNR (0x82ADBCB3) = %d", m_titan17xStaticSettings.forceBPSHNR);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "forceBPSWB (0x0C156E0A) = %d", m_titan17xStaticSettings.forceBPSWB);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "pipelineDelay (0x793FF30D) = %d", m_titan17xStaticSettings.pipelineDelay);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "dumpBPSRegConfigMask (0x9E840AB0) = %d", m_titan17xStaticSettings.dumpBPSRegConfigMask);
    CAMX_LOG_VERBOSE(CamxLogGroupCore, "================ END DUMP OF CURRENT TITAN17X HARDWARE-DEPENDENT SETTINGS VALUES ================");
}
#endif // SETTINGS_DUMP_ENABLE

CAMX_NAMESPACE_END
