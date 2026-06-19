////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  g_camxtitan17xsettings.h
/// @brief Titan17x-Specific Settings definitions.
///
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///             !!!!!!! AUTO-GENERATED FILE! DO NOT EDIT! Make all changes in camxtitan17xsettings.xml. !!!!!!!
///             !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef G_CAMXTITAN17XSETTINGS_H
#define G_CAMXTITAN17XSETTINGS_H

#include "camxdefs.h"
#include "camxtypes.h"
#include "g_camxsettings.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constant Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setting string hash constant definitions
static const UINT32 StringHashIPESwStriping             = 0x4B33BD24;   ///< IPESwStriping
static const UINT32 PropStringHashIPESwStriping         = 0x1A56F7DF;   ///< IPESwStriping
static const UINT32 StringHashBPSSwStriping             = 0xFB6BBD24;   ///< BPSSwStriping
static const UINT32 PropStringHashBPSSwStriping         = 0x1156F7C9;   ///< BPSSwStriping
static const UINT32 StringHashDisableIPEICADependenciesMFNR  = 0x82E60165;   ///< disableIPEICADependenciesMFNR
static const UINT32 PropStringHashDisableIPEICADependenciesMFNR  = 0xB62F4738;   ///< disableIPEICADependenciesMFNR
static const UINT32 StringHashIPEMaxInpWidth            = 0x547D456E;   ///< IPEMaxInpWidth
static const UINT32 StringHashIPEMaxOutWidth            = 0x9C7D4558;   ///< IPEMaxOutWidth
static const UINT32 StringHashIPEMinInpWidth            = 0x547C536E;   ///< IPEMinInpWidth
static const UINT32 StringHashIPEMinOutputWidth         = 0x099D50E9;   ///< IPEMinOutputWidth
static const UINT32 StringHashIFEEnableHardcodedConfig  = 0x58396CD5;   ///< IFEEnableHardcodedConfig
static const UINT32 PropStringHashIFEEnableHardcodedConfig  = 0x3C9A424F;   ///< IFEEnableHardcodedConfig
static const UINT32 StringHashIFEUseHardcodedRegisterValues  = 0x59BE998C;   ///< IFEUseHardcodedRegisterValues
static const UINT32 PropStringHashIFEUseHardcodedRegisterValues  = 0x6D77DFD1;   ///< IFEUseHardcodedRegisterValues
static const UINT32 StringHashBPSUseHardcodedRegisterValues  = 0x59BE22D4;   ///< BPSUseHardcodedRegisterValues
static const UINT32 PropStringHashBPSUseHardcodedRegisterValues  = 0x6D776489;   ///< BPSUseHardcodedRegisterValues
static const UINT32 StringHashIsOEMIQSettingEnable      = 0x4E099D1C;   ///< IsOEMIQSettingEnable
static const UINT32 StringHashDisableUBWCv3             = 0xD95A438C;   ///< disableUBWCv3
static const UINT32 StringHashEnableIFEOutputGrouping   = 0x8E74CD3A;   ///< enableIFEOutputGrouping
static const UINT32 StringHashIFEDualClockThreshold     = 0x23F2B3DA;   ///< IFEDualClockThreshold
static const UINT32 StringHashEnableIFEDualStripeInfo   = 0x7B88908A;   ///< enableIFEDualStripeInfo
static const UINT32 PropStringHashEnableIFEDualStripeInfo  = 0x6B0410EF;   ///< enableIFEDualStripeInfo
static const UINT32 StringHashEnableIFESettingsDump     = 0xA9361A6F;   ///< enableIFESettingsDump
static const UINT32 PropStringHashEnableIFESettingsDump  = 0xF402D329;   ///< enableIFESettingsDump
static const UINT32 StringHashDumpIFERegConfigMask      = 0x9E84571C;   ///< dumpIFERegConfigMask
static const UINT32 PropStringHashDumpIFERegConfigMask  = 0xAC6DF156;   ///< dumpIFERegConfigMask
static const UINT32 StringHashIsICAIQSettingEnable      = 0x4ECFFD1C;   ///< IsICAIQSettingEnable
static const UINT32 PropStringHashIsICAIQSettingEnable  = 0xF63A4904;   ///< IsICAIQSettingEnable
static const UINT32 StringHashEnableICACommonIQModule   = 0xE729CE11;   ///< enableICACommonIQModule
static const UINT32 PropStringHashEnableICACommonIQModule  = 0x340CD765;   ///< enableICACommonIQModule
static const UINT32 StringHashEnableANRCommonIQModule   = 0xE721A2D1;   ///< enableANRCommonIQModule
static const UINT32 PropStringHashEnableANRCommonIQModule  = 0x3404BBA5;   ///< enableANRCommonIQModule
static const UINT32 StringHashEnableTFCommonIQModule    = 0x5E1C2120;   ///< enableTFCommonIQModule
static const UINT32 PropStringHashEnableTFCommonIQModule  = 0xF88509EB;   ///< enableTFCommonIQModule
static const UINT32 StringHashEnableGRACommonIQModule   = 0xE7274611;   ///< enableGRACommonIQModule
static const UINT32 PropStringHashEnableGRACommonIQModule  = 0x34025F65;   ///< enableGRACommonIQModule
static const UINT32 StringHashIPEDurationInNumFrames    = 0x53695587;   ///< IPEDurationInNumFrames
static const UINT32 PropStringHashIPEDurationInNumFrames  = 0xF5F07D4C;   ///< IPEDurationInNumFrames
static const UINT32 StringHashDisableLENRDS4Buffer      = 0x9A56B8B8;   ///< disableLENRDS4Buffer
static const UINT32 PropStringHashDisableLENRDS4Buffer  = 0xA8BF1EF2;   ///< disableLENRDS4Buffer
static const UINT32 StringHashIgnoreChromatixRGammaFlag  = 0x821EA2C2;   ///< ignoreChromatixRGammaFlag
static const UINT32 PropStringHashIgnoreChromatixRGammaFlag  = 0x167B718E;   ///< ignoreChromatixRGammaFlag
static const UINT32 StringHashUseHardcodedGamma         = 0xA6ABB46E;   ///< useHardcodedGamma
static const UINT32 PropStringHashUseHardcodedGamma     = 0xEA3FD1BD;   ///< useHardcodedGamma
static const UINT32 StringHashEnableICAInGrid           = 0xB46E96DE;   ///< enableICAInGrid
static const UINT32 PropStringHashEnableICAInGrid       = 0xC0BDB3C7;   ///< enableICAInGrid
static const UINT32 StringHashEnableICARefGrid          = 0x5BC83614;   ///< enableICARefGrid
static const UINT32 PropStringHashEnableICARefGrid      = 0xC1AC953A;   ///< enableICARefGrid
static const UINT32 StringHashDumpICAOut                = 0xD40DC4A0;   ///< dumpICAOut
static const UINT32 PropStringHashDumpICAOut            = 0xBD9F481A;   ///< dumpICAOut
static const UINT32 StringHashValidateTFParams          = 0xC5A1C7F4;   ///< validateTFParams
static const UINT32 PropStringHashValidateTFParams      = 0x5FC564DA;   ///< validateTFParams
static const UINT32 StringHashValidateANRSettings       = 0x0833D4D6;   ///< validateANRSettings
static const UINT32 PropStringHashValidateANRSettings   = 0x59A499E4;   ///< validateANRSettings
static const UINT32 StringHashDumpIPERegConfig          = 0x358979EB;   ///< dumpIPERegConfig
static const UINT32 PropStringHashDumpIPERegConfig      = 0xAFEDDAC5;   ///< dumpIPERegConfig
static const UINT32 StringHashDumpIPERegConfigMask      = 0x9E84529C;   ///< dumpIPERegConfigMask
static const UINT32 PropStringHashDumpIPERegConfigMask  = 0xAC6DF4D6;   ///< dumpIPERegConfigMask
static const UINT32 StringHashDisableTFRefinement       = 0x6CA12FC1;   ///< disableTFRefinement
static const UINT32 PropStringHashDisableTFRefinement   = 0x3D3662F3;   ///< disableTFRefinement
static const UINT32 StringHashHALOutputBufferCombined   = 0x246894F2;   ///< HALOutputBufferCombined
static const UINT32 PropStringHashHALOutputBufferCombined  = 0xF74D8D86;   ///< HALOutputBufferCombined
static const UINT32 StringHashForceBPSPedestalCorrection  = 0x53D990B6;   ///< forceBPSPedestalCorrection
static const UINT32 StringHashForceBPSLinearization     = 0x031961B2;   ///< forceBPSLinearization
static const UINT32 StringHashForceBPSBPCPDPC           = 0x7611B4BA;   ///< forceBPSBPCPDPC
static const UINT32 StringHashForceBPSDemux             = 0xB6373CD2;   ///< forceBPSDemux
static const UINT32 StringHashForceBPSHDR               = 0x82ADBDF3;   ///< forceBPSHDR
static const UINT32 StringHashForceBPSABF               = 0x82AD9927;   ///< forceBPSABF
static const UINT32 StringHashForceBPSLSC               = 0x82ADAF02;   ///< forceBPSLSC
static const UINT32 StringHashForceBPSGIC               = 0x82AD8042;   ///< forceBPSGIC
static const UINT32 StringHashForceBPSDemosaic          = 0x9FCD5258;   ///< forceBPSDemosaic
static const UINT32 StringHashForceBPSCC                = 0x0C156C8B;   ///< forceBPSCC
static const UINT32 StringHashForceBPSGTM               = 0x82AD83EC;   ///< forceBPSGTM
static const UINT32 StringHashForceBPSGamma             = 0xB6053FCB;   ///< forceBPSGamma
static const UINT32 StringHashForceBPSCST               = 0x82AD9315;   ///< forceBPSCST
static const UINT32 StringHashForceBPSChromaSubSample   = 0x6E35C452;   ///< forceBPSChromaSubSample
static const UINT32 StringHashForceBPSHNR               = 0x82ADBCB3;   ///< forceBPSHNR
static const UINT32 StringHashForceBPSWB                = 0x0C156E0A;   ///< forceBPSWB
static const UINT32 StringHashPipelineDelay             = 0x793FF30D;   ///< pipelineDelay
static const UINT32 StringHashDumpBPSRegConfigMask      = 0x9E840AB0;   ///< dumpBPSRegConfigMask
static const UINT32 PropStringHashDumpBPSRegConfigMask  = 0xAC6DACFA;   ///< dumpBPSRegConfigMask

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Type Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Override default and force enable/disable an IQ module
enum IQModuleForceMode
{
    IQModuleForceDisable = 0,               ///< Force an IQ module to be disabled
    IQModuleForceEnable = 1,                ///< Force an IQ module to be enabled, if available
    IQModuleForceDefault = 2,               ///< Use driver default settings
};

/// @brief Encapsulates all Titan17x static settings values
struct Titan17xStaticSettings : public StaticSettings
{
    BIT                     BPSSwStriping:1;                    ///< Setting indicating if BPS striping is in UMD or in firmware
    BIT                     BPSUseHardcodedRegisterValues:1;    ///< Initializes registers with known set of values
    BIT                     HALOutputBufferCombined:1;          ///< Enable HAL output buffer combined mode for HFR
    BIT                     IFEEnableHardcodedConfig:1;         ///< Overwrites config with hardcoded values
    BIT                     IFEUseHardcodedRegisterValues:1;    ///< Initializes registers with known set of values
    BIT                     IPESwStriping:1;                    ///< Setting indicating if IPE striping is in UMD or in firmware
    BIT                     IsICAIQSettingEnable:1;             ///< Use the ICA Setings/Interpolation data provided by OEM
    BIT                     IsOEMIQSettingEnable:1;             ///< Use the IQ Interpolation data provided by OEM
    BIT                     disableIPEICADependenciesMFNR:1;    ///< Setting IPE ICA Dependencies for MFNR
    BIT                     disableLENRDS4Buffer:1;             ///< Disable LENR dsref buffer and use BPS output
    BIT                     disableTFRefinement:1;              ///< disable TF refinement
    BIT                     disableUBWCv3:1;                    ///< disable UBWC 3.0
    BIT                     dumpICAOut:1;                       ///< Dump ICA output
    BIT                     dumpIPERegConfig:1;                 ///< dump IPE reg config
    BIT                     enableANRCommonIQModule:1;          ///< Enable ANR common IQ module
    BIT                     enableGRACommonIQModule:1;          ///< Enable GRA common IQ module
    BIT                     enableICACommonIQModule:1;          ///< Enable common IQ module
    BIT                     enableICAInGrid:1;                  ///< Enable ICA1 grid transform
    BIT                     enableICARefGrid:1;                 ///< Enable ICA2 grid transform
    BIT                     enableIFEDualStripeInfo:1;          ///< IFE Dual Stripe library input and output
    BIT                     enableIFEOutputGrouping:1;          ///< Group IFE output clients
    BIT                     enableIFESettingsDump:1;            ///< IFE Per Fraem settings dump
    BIT                     enableTFCommonIQModule:1;           ///< Enable TF  common IQ module
    BIT                     ignoreChromatixRGammaFlag:1;        ///< Ignore Chromatix Reverse Gamma Enable Flag
    BIT                     useHardcodedGamma:1;                ///< Use Hardcoded IFE/BPS Gamma
    BIT                     validateANRSettings:1;              ///< Validate ANR Settings
    BIT                     validateTFParams:1;                 ///< Validate And Correct TF Parameters
    IQModuleForceMode       forceBPSABF;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSBPCPDPC;                    ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSCC;                         ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSCST;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSChromaSubSample;            ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSDemosaic;                   ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSDemux;                      ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSGIC;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSGTM;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSGamma;                      ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSHDR;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSHNR;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSLSC;                        ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSLinearization;              ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSPedestalCorrection;         ///< Use to force enable or force disable this IQ module
    IQModuleForceMode       forceBPSWB;                         ///< Use to force enable or force disable this IQ module
    UINT                    IFEDualClockThreshold;              ///< IFE Clock Threshold for Dual IFE Decision
    UINT                    IPEDurationInNumFrames;             ///< IPE Duration in number of frames for timeout for frame processing
                                                                ///< first 16 bit corresponds to realtime delay and next 16 bit for non realtime.
    UINT                    IPEMaxInpWidth;                     ///< Setting of IPE max input width supported
    UINT                    IPEMaxOutWidth;                     ///< Setting of IPE max output width supported
    UINT                    IPEMinInpWidth;                     ///< Setting of IPE min input width supported
    UINT                    IPEMinOutputWidth;                  ///< Setting of IPE min output width supported
    UINT                    dumpBPSRegConfigMask;               ///< BPS enable mask:
                                                                ///< BPSPedestalCorrection = 0x1
                                                                ///< BPSLinearization      = 0x2
                                                                ///< BPSBPCPDPC            = 0x4
                                                                ///< BPSDemux              = 0x8
                                                                ///< BPSHDR                = 0x10
                                                                ///< BPSABF                = 0x20
                                                                ///< BPSLSC                = 0x40
                                                                ///< BPSGIC                = 0x80
                                                                ///< BPSDemosaic           = 0x100
                                                                ///< BPSCC                 = 0x200
                                                                ///< BPSGTM                = 0x400
                                                                ///< BPSGamma              = 0x800
                                                                ///< BPSCST                = 0x1000
                                                                ///< BPSHNR                = 0x4000
                                                                ///< BPSWB                 = 0x8000
                                                                ///< ALLBPSIQModules       = 0x7FFFFF
    UINT                    dumpIFERegConfigMask;               ///< IFE enable mask:
                                                                ///< IFECAMIF              =0x1
                                                                ///< IFECAMIFLite          =0x2
                                                                ///< IFECAMIFDualPD        =0x4
                                                                ///< IFECAMIFLCR           =0x8
                                                                ///< IFECAMIFRDI0          =0x10
                                                                ///< IFECAMIFRDI1          =0x20
                                                                ///< IFECAMIFRDI2          =0x40
                                                                ///< IFECAMIFRDI3          =0x80
                                                                ///< IFEPedestalCorrection =0x100
                                                                ///< IFEBLS                =0x200
                                                                ///< IFELinearization      =0x400
                                                                ///< IFEDemux              =0x800
                                                                ///< IFEHDR                =0x1000
                                                                ///< IFEPDPC               =0x2000
                                                                ///< IFEBPCBCC             =0x4000
                                                                ///< IFEABF                =0x8000
                                                                ///< IFELSC                =0x10000
                                                                ///< IFEDemosaic           =0x20000
                                                                ///< IFECC                 =0x40000
                                                                ///< IFEGTM                =0x80000
                                                                ///< IFEGamma              =0x100000
                                                                ///< IFECST                =0x200000
                                                                ///< IFEMNDS               =0x400000
                                                                ///< IFEPreCrop            =0x800000
                                                                ///< IFEDS4                =0x1000000
                                                                ///< IFECrop               =0x2000000
                                                                ///< IFERoundClamp         =0x4000000
                                                                ///< IFER2PD               =0x8000000
                                                                ///< IFEWB                 =0x10000000
                                                                ///< IFEDUALPD             =0x20000000
                                                                ///< IFEPDAF               =0x40000000
                                                                ///< IFELCR                =0x80000000
                                                                ///< ALLIFEIQModules      = 0xFFFFFFFF
    UINT                    dumpIPERegConfigMask;               ///< IPE enable mask:
                                                                ///< IPEICA               = 0x1
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
                                                                ///< IPESCE               = 0x8000
                                                                ///< IPEASF               = 0x10000
                                                                ///< IPEUpscaler          = 0x20000
                                                                ///< IPEGrainAdder        = 0x40000
                                                                ///< IPEHNR               = 0x400000
                                                                ///< IPELENR              = 0x800000
                                                                ///< ALLIPEIQModules      = 0xFFFFFF
    UINT                    pipelineDelay;                      ///< Stats parse node pipeline delay
};

CAMX_NAMESPACE_END

#endif // G_CAMXTITAN17XSETTINGS_H
