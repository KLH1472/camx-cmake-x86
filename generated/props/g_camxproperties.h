////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file g_camxproperties.h
/// @brief Define Qualcomm Technologies, Inc. Property IDs and structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef G_CAMXPROPERTIES_H
#define G_CAMXPROPERTIES_H

#include "camxdefs.h"

CAMX_NAMESPACE_BEGIN



// 32 Properties reserved for tracking dependencies on the previous request
// Use Node->GetNodeCompleteProperty() to identify the prop
static const UINT NodeCompleteCount = 32;

// 20 Properties reserved for tracking link based metadata
static const UINT LinkMetadataCount = 20;

/* Beginning of MainProperty */

static const PropertyID PropertyIDAECFrameControl                     = PropertyIDPerFrameResultBegin + 0x00;
static const PropertyID PropertyIDAECFrameInfo                        = PropertyIDPerFrameResultBegin + 0x01;
static const PropertyID PropertyIDAWBFrameControl                     = PropertyIDPerFrameResultBegin + 0x02;
static const PropertyID PropertyIDAWBFrameInfo                        = PropertyIDPerFrameResultBegin + 0x03;
static const PropertyID PropertyIDAFFrameControl                      = PropertyIDPerFrameResultBegin + 0x04;
static const PropertyID PropertyIDAFFrameInfo                         = PropertyIDPerFrameResultBegin + 0x05;
static const PropertyID PropertyIDAFPDFrameInfo                       = PropertyIDPerFrameResultBegin + 0x06;
static const PropertyID PropertyIDAFBAFDependencyMet                  = PropertyIDPerFrameResultBegin + 0x07;
static const PropertyID PropertyIDASD                                 = PropertyIDPerFrameResultBegin + 0x08;
static const PropertyID PropertyIDAFDFrameControl                     = PropertyIDPerFrameResultBegin + 0x09;
static const PropertyID PropertyIDAFDFrameInfo                        = PropertyIDPerFrameResultBegin + 0x0A;
static const PropertyID PropertyIDAECStatsControl                     = PropertyIDPerFrameResultBegin + 0x0B;
static const PropertyID PropertyIDAWBStatsControl                     = PropertyIDPerFrameResultBegin + 0x0C;
static const PropertyID PropertyIDAFStatsControl                      = PropertyIDPerFrameResultBegin + 0x0D;
static const PropertyID PropertyIDAFDStatsControl                     = PropertyIDPerFrameResultBegin + 0x0E;
static const PropertyID PropertyIDIHistStatsControl                   = PropertyIDPerFrameResultBegin + 0x0F;
static const PropertyID PropertyIDCrossAECStats                       = PropertyIDPerFrameResultBegin + 0x10;
static const PropertyID PropertyIDCrossAWBStats                       = PropertyIDPerFrameResultBegin + 0x11;
static const PropertyID PropertyIDCrossAFStats                        = PropertyIDPerFrameResultBegin + 0x12;
static const PropertyID PropertyIDAECPeerInfo                         = PropertyIDPerFrameResultBegin + 0x13;
static const PropertyID PropertyIDAWBPeerInfo                         = PropertyIDPerFrameResultBegin + 0x14;
static const PropertyID PropertyIDAFPeerInfo                          = PropertyIDPerFrameResultBegin + 0x15;
static const PropertyID PropertyIDAFDPeerInfo                         = PropertyIDPerFrameResultBegin + 0x16;
static const PropertyID PropertyIDASDPeerInfo                         = PropertyIDPerFrameResultBegin + 0x17;
static const PropertyID PropertyIDFOVCFrameInfo                       = PropertyIDPerFrameResultBegin + 0x18;
static const PropertyID PropertyIDPDHwConfig                          = PropertyIDPerFrameResultBegin + 0x19;
static const PropertyID PropertyIDSensorCurrentMode                   = PropertyIDPerFrameResultBegin + 0x1A;
static const PropertyID PropertyIDPostSensorGainId                    = PropertyIDPerFrameResultBegin + 0x1B;
static const PropertyID PropertyIDSensorFlashCurrent                  = PropertyIDPerFrameResultBegin + 0x1C;
static const PropertyID PropertyIDSensorMetaData                      = PropertyIDPerFrameResultBegin + 0x1D;
static const PropertyID PropertyIDSensorExposureStartTime             = PropertyIDPerFrameResultBegin + 0x1E;
static const PropertyID PropertyIDSensorProperties                    = PropertyIDPerFrameResultBegin + 0x1F;
static const PropertyID PropertyIDSensorPDAFInfo                      = PropertyIDPerFrameResultBegin + 0x20;
static const PropertyID PropertyIDSensorNumberOfLEDs                  = PropertyIDPerFrameResultBegin + 0x21;
static const PropertyID PropertyIDSensorResolutionInfo                = PropertyIDPerFrameResultBegin + 0x22;
static const PropertyID PropertyIDRERCompleted                        = PropertyIDPerFrameResultBegin + 0x23;
static const PropertyID PropertyIDIFEDigitalZoom                      = PropertyIDPerFrameResultBegin + 0x24;
static const PropertyID PropertyIDIFEGammaOutput                      = PropertyIDPerFrameResultBegin + 0x25;
static const PropertyID PropertyIDIFEAppliedCrop                      = PropertyIDPerFrameResultBegin + 0x26;
static const PropertyID PropertyIDISPBHistConfig                      = PropertyIDPerFrameResultBegin + 0x27;
static const PropertyID PropertyIDISPTintlessBGConfig                 = PropertyIDPerFrameResultBegin + 0x28;
static const PropertyID PropertyIDIFEScaleOutput                      = PropertyIDPerFrameResultBegin + 0x29;
static const PropertyID PropertyIDParsedAWBBGStatsOutput              = PropertyIDPerFrameResultBegin + 0x2A;
static const PropertyID PropertyIDParsedBFStatsOutput                 = PropertyIDPerFrameResultBegin + 0x2B;
static const PropertyID PropertyIDParsedBHistStatsOutput              = PropertyIDPerFrameResultBegin + 0x2C;
static const PropertyID PropertyIDParsedCSStatsOutput                 = PropertyIDPerFrameResultBegin + 0x2D;
static const PropertyID PropertyIDParsedHDRBEStatsOutput              = PropertyIDPerFrameResultBegin + 0x2E;
static const PropertyID PropertyIDParsedHDRBHistStatsOutput           = PropertyIDPerFrameResultBegin + 0x2F;
static const PropertyID PropertyIDParsedIHistStatsOutput              = PropertyIDPerFrameResultBegin + 0x30;
static const PropertyID PropertyIDParsedRSStatsOutput                 = PropertyIDPerFrameResultBegin + 0x31;
static const PropertyID PropertyIDParsedTintlessBGStatsOutput         = PropertyIDPerFrameResultBegin + 0x32;
static const PropertyID PropertyIDBPSGammaOutput                      = PropertyIDPerFrameResultBegin + 0x33;
static const PropertyID PropertyIDJPEGEncodeOutInfo                   = PropertyIDPerFrameResultBegin + 0x34;
static const PropertyID PropertyIDJPEGEncodeOutInfoThumbnail          = PropertyIDPerFrameResultBegin + 0x35;
static const PropertyID PropertyIDIPETotalFrameMFNR                   = PropertyIDPerFrameResultBegin + 0x36;
static const PropertyID PropertyIDIPETotalFrameMFSR                   = PropertyIDPerFrameResultBegin + 0x37;
static const PropertyID PropertyIDFDFrameSettings                     = PropertyIDPerFrameResultBegin + 0x38;
static const PropertyID PropertyIDLRMEFrameSettings                   = PropertyIDPerFrameResultBegin + 0x39;
static const PropertyID PropertyIDIFEADRCInfoOutput                   = PropertyIDPerFrameResultBegin + 0x3A;
static const PropertyID PropertyIDBPSADRCInfoOutput                   = PropertyIDPerFrameResultBegin + 0x3B;
static const PropertyID PropertyIDIFEADRCParams                       = PropertyIDPerFrameResultBegin + 0x3C;
static const PropertyID PropertyIDIntermediateDimension               = PropertyIDPerFrameResultBegin + 0x3D;
static const PropertyID PropertyIDIPEGamma15PreCalculation            = PropertyIDPerFrameResultBegin + 0x3E;
static const PropertyID PropertyIDNodeComplete0                       = PropertyIDPerFrameResultBegin + 0x3F;
static const PropertyID PropertyIDNodeComplete1                       = PropertyIDPerFrameResultBegin + 0x40;
static const PropertyID PropertyIDNodeComplete2                       = PropertyIDPerFrameResultBegin + 0x41;
static const PropertyID PropertyIDNodeComplete3                       = PropertyIDPerFrameResultBegin + 0x42;
static const PropertyID PropertyIDNodeComplete4                       = PropertyIDPerFrameResultBegin + 0x43;
static const PropertyID PropertyIDNodeComplete5                       = PropertyIDPerFrameResultBegin + 0x44;
static const PropertyID PropertyIDNodeComplete6                       = PropertyIDPerFrameResultBegin + 0x45;
static const PropertyID PropertyIDNodeComplete7                       = PropertyIDPerFrameResultBegin + 0x46;
static const PropertyID PropertyIDNodeComplete8                       = PropertyIDPerFrameResultBegin + 0x47;
static const PropertyID PropertyIDNodeComplete9                       = PropertyIDPerFrameResultBegin + 0x48;
static const PropertyID PropertyIDNodeComplete10                      = PropertyIDPerFrameResultBegin + 0x49;
static const PropertyID PropertyIDNodeComplete11                      = PropertyIDPerFrameResultBegin + 0x4A;
static const PropertyID PropertyIDNodeComplete12                      = PropertyIDPerFrameResultBegin + 0x4B;
static const PropertyID PropertyIDNodeComplete13                      = PropertyIDPerFrameResultBegin + 0x4C;
static const PropertyID PropertyIDNodeComplete14                      = PropertyIDPerFrameResultBegin + 0x4D;
static const PropertyID PropertyIDNodeComplete15                      = PropertyIDPerFrameResultBegin + 0x4E;
static const PropertyID PropertyIDNodeComplete16                      = PropertyIDPerFrameResultBegin + 0x4F;
static const PropertyID PropertyIDNodeComplete17                      = PropertyIDPerFrameResultBegin + 0x50;
static const PropertyID PropertyIDNodeComplete18                      = PropertyIDPerFrameResultBegin + 0x51;
static const PropertyID PropertyIDNodeComplete19                      = PropertyIDPerFrameResultBegin + 0x52;
static const PropertyID PropertyIDNodeComplete20                      = PropertyIDPerFrameResultBegin + 0x53;
static const PropertyID PropertyIDNodeComplete21                      = PropertyIDPerFrameResultBegin + 0x54;
static const PropertyID PropertyIDNodeComplete22                      = PropertyIDPerFrameResultBegin + 0x55;
static const PropertyID PropertyIDNodeComplete23                      = PropertyIDPerFrameResultBegin + 0x56;
static const PropertyID PropertyIDNodeComplete24                      = PropertyIDPerFrameResultBegin + 0x57;
static const PropertyID PropertyIDNodeComplete25                      = PropertyIDPerFrameResultBegin + 0x58;
static const PropertyID PropertyIDNodeComplete26                      = PropertyIDPerFrameResultBegin + 0x59;
static const PropertyID PropertyIDNodeComplete27                      = PropertyIDPerFrameResultBegin + 0x5A;
static const PropertyID PropertyIDNodeComplete28                      = PropertyIDPerFrameResultBegin + 0x5B;
static const PropertyID PropertyIDNodeComplete29                      = PropertyIDPerFrameResultBegin + 0x5C;
static const PropertyID PropertyIDNodeComplete30                      = PropertyIDPerFrameResultBegin + 0x5D;
static const PropertyID PropertyIDNodeComplete31                      = PropertyIDPerFrameResultBegin + 0x5E;
static const PropertyID PropertyIDLinkMetadata0                       = PropertyIDPerFrameResultBegin + 0x5F;
static const PropertyID PropertyIDLinkMetadata1                       = PropertyIDPerFrameResultBegin + 0x60;
static const PropertyID PropertyIDLinkMetadata2                       = PropertyIDPerFrameResultBegin + 0x61;
static const PropertyID PropertyIDLinkMetadata3                       = PropertyIDPerFrameResultBegin + 0x62;
static const PropertyID PropertyIDLinkMetadata4                       = PropertyIDPerFrameResultBegin + 0x63;
static const PropertyID PropertyIDLinkMetadata5                       = PropertyIDPerFrameResultBegin + 0x64;
static const PropertyID PropertyIDLinkMetadata6                       = PropertyIDPerFrameResultBegin + 0x65;
static const PropertyID PropertyIDLinkMetadata7                       = PropertyIDPerFrameResultBegin + 0x66;
static const PropertyID PropertyIDLinkMetadata8                       = PropertyIDPerFrameResultBegin + 0x67;
static const PropertyID PropertyIDLinkMetadata9                       = PropertyIDPerFrameResultBegin + 0x68;
static const PropertyID PropertyIDLinkMetadata10                      = PropertyIDPerFrameResultBegin + 0x69;
static const PropertyID PropertyIDLinkMetadata11                      = PropertyIDPerFrameResultBegin + 0x6A;
static const PropertyID PropertyIDLinkMetadata12                      = PropertyIDPerFrameResultBegin + 0x6B;
static const PropertyID PropertyIDLinkMetadata13                      = PropertyIDPerFrameResultBegin + 0x6C;
static const PropertyID PropertyIDLinkMetadata14                      = PropertyIDPerFrameResultBegin + 0x6D;
static const PropertyID PropertyIDLinkMetadata15                      = PropertyIDPerFrameResultBegin + 0x6E;
static const PropertyID PropertyIDLinkMetadata16                      = PropertyIDPerFrameResultBegin + 0x6F;
static const PropertyID PropertyIDLinkMetadata17                      = PropertyIDPerFrameResultBegin + 0x70;
static const PropertyID PropertyIDLinkMetadata18                      = PropertyIDPerFrameResultBegin + 0x71;
static const PropertyID PropertyIDLinkMetadata19                      = PropertyIDPerFrameResultBegin + 0x72;

extern const CHAR* pMainPropertyStrings[115];

static const PropertyID PropertyIDPerFrameResultEnd = PropertyIDPerFrameResultBegin + 0x72;

/// @brief LUT of each member in the property blob
static const PropertyID MainPropertyLinearLUT[] =
{
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

/// @brief Collection of properties in a struct
struct MainPropertyBlob
{
    AECFrameControl                     mAECFrameControl;                  ///< AECFrameControl
    AECFrameInformation                 mAECFrameInfo;                     ///< AECFrameInfo
    AWBFrameControl                     mAWBFrameControl;                  ///< AWBFrameControl
    AWBFrameInfo                        mAWBFrameInfo;                     ///< AWBFrameInfo
    AFFrameControl                      mAFFrameControl;                   ///< AFFrameControl
    AFFrameInformation                  mAFFrameInfo;                      ///< AFFrameInfo
    AFPDAFData                          mAFPDFrameInfo;                    ///< AFPDFrameInfo
    BOOL                                mAFBAFDependencyMet;               ///< AFBAFDependencyMet
    ASDOutput                           mASD;                              ///< ASD
    UINT32                              mAFDFrameControl;                  ///< AFDFrameControl
    AFDFrameInfo                        mAFDFrameInfo;                     ///< AFDFrameInfo
    AECStatsControl                     mAECStatsControl;                  ///< AECStatsControl
    AWBStatsControl                     mAWBStatsControl;                  ///< AWBStatsControl
    AFStatsControl                      mAFStatsControl;                   ///< AFStatsControl
    AFDStatsControl                     mAFDStatsControl;                  ///< AFDStatsControl
    IHistStatsControl                   mIHistStatsControl;                ///< IHistStatsControl
    UINT64                              mCrossAECStats;                    ///< CrossAECStats
    UINT64                              mCrossAWBStats;                    ///< CrossAWBStats
    UINT64                              mCrossAFStats;                     ///< CrossAFStats
    VOID*                               pAECPeerInfo;                      ///< AECPeerInfo
    VOID*                               pAWBPeerInfo;                      ///< AWBPeerInfo
    VOID*                               pAFPeerInfo;                       ///< AFPeerInfo
    VOID*                               pAFDPeerInfo;                      ///< AFDPeerInfo
    VOID*                               pASDPeerInfo;                      ///< ASDPeerInfo
    FOVCOutput                          mFOVCFrameInfo;                    ///< FOVCFrameInfo
    PDHwConfig                          mPDHwConfig;                       ///< PDHwConfig
    UINT32                              mSensorCurrentMode;                ///< SensorCurrentMode
    FLOAT                               mPostSensorGainId;                 ///< PostSensorGainId
    UINT                                mSensorFlashCurrent;               ///< SensorFlashCurrent
    SensorMetaData                      mSensorMetaData;                   ///< SensorMetaData
    UINT64                              mSensorExposureStartTime;          ///< SensorExposureStartTime
    SensorProperties                    mSensorProperties;                 ///< SensorProperties
    SensorPDAFInfo                      mSensorPDAFInfo;                   ///< SensorPDAFInfo
    UINT                                mSensorNumberOfLEDs;               ///< SensorNumberOfLEDs
    SensorResolutionInfo                mSensorResolutionInfo;             ///< SensorResolutionInfo
    BOOL                                mRERCompleted;                     ///< RERCompleted
    IFECropInfo                         mIFEDigitalZoom;                   ///< IFEDigitalZoom
    GammaInfo                           mIFEGammaOutput;                   ///< IFEGammaOutput
    IFECropInfo                         mIFEAppliedCrop;                   ///< IFEAppliedCrop
    PropertyISPBHistStats               mISPBHistConfig;                   ///< ISPBHistConfig
    PropertyISPTintlessBG               mISPTintlessBGConfig;              ///< ISPTintlessBGConfig
    IFEScalerOutput                     mIFEScaleOutput;                   ///< IFEScaleOutput
    ParsedAWBBGStatsOutput*             pParsedAWBBGStatsOutput;           ///< ParsedAWBBGStatsOutput
    ParsedBFStatsOutput*                pParsedBFStatsOutput;              ///< ParsedBFStatsOutput
    ParsedBHistStatsOutput*             pParsedBHistStatsOutput;           ///< ParsedBHistStatsOutput
    ParsedCSStatsOutput*                pParsedCSStatsOutput;              ///< ParsedCSStatsOutput
    ParsedHDRBEStatsOutput*             pParsedHDRBEStatsOutput;           ///< ParsedHDRBEStatsOutput
    ParsedHDRBHistStatsOutput*          pParsedHDRBHistStatsOutput;        ///< ParsedHDRBHistStatsOutput
    ParsedIHistStatsOutput*             pParsedIHistStatsOutput;           ///< ParsedIHistStatsOutput
    ParsedRSStatsOutput*                pParsedRSStatsOutput;              ///< ParsedRSStatsOutput
    ParsedTintlessBGStatsOutput*        pParsedTintlessBGStatsOutput;      ///< ParsedTintlessBGStatsOutput
    GammaInfo                           mBPSGammaOutput;                   ///< BPSGammaOutput
    EncoderOutInfo                      mJPEGEncodeOutInfo;                ///< JPEGEncodeOutInfo
    EncoderOutInfo                      mJPEGEncodeOutInfoThumbnail;       ///< JPEGEncodeOutInfoThumbnail
    UINT                                mIPETotalFrameMFNR;                ///< IPETotalFrameMFNR
    UINT                                mIPETotalFrameMFSR;                ///< IPETotalFrameMFSR
    FDPropertyFrameSettings             mFDFrameSettings;                  ///< FDFrameSettings
    LRMEPropertyFrameSettings           mLRMEFrameSettings;                ///< LRMEFrameSettings
    PropertyISPADRCInfo                 mIFEADRCInfoOutput;                ///< IFEADRCInfoOutput
    PropertyISPADRCInfo                 mBPSADRCInfoOutput;                ///< BPSADRCInfoOutput
    PropertyISPADRCParams               mIFEADRCParams;                    ///< IFEADRCParams
    PropertyISPIntermediateDimension    mIntermediateDimension;            ///< IntermediateDimension
    IPEGammaPreOutput                   mIPEGamma15PreCalculation;         ///< IPEGamma15PreCalculation
    BOOL                                mNodeComplete0;                    ///< NodeComplete0
    BOOL                                mNodeComplete1;                    ///< NodeComplete1
    BOOL                                mNodeComplete2;                    ///< NodeComplete2
    BOOL                                mNodeComplete3;                    ///< NodeComplete3
    BOOL                                mNodeComplete4;                    ///< NodeComplete4
    BOOL                                mNodeComplete5;                    ///< NodeComplete5
    BOOL                                mNodeComplete6;                    ///< NodeComplete6
    BOOL                                mNodeComplete7;                    ///< NodeComplete7
    BOOL                                mNodeComplete8;                    ///< NodeComplete8
    BOOL                                mNodeComplete9;                    ///< NodeComplete9
    BOOL                                mNodeComplete10;                   ///< NodeComplete10
    BOOL                                mNodeComplete11;                   ///< NodeComplete11
    BOOL                                mNodeComplete12;                   ///< NodeComplete12
    BOOL                                mNodeComplete13;                   ///< NodeComplete13
    BOOL                                mNodeComplete14;                   ///< NodeComplete14
    BOOL                                mNodeComplete15;                   ///< NodeComplete15
    BOOL                                mNodeComplete16;                   ///< NodeComplete16
    BOOL                                mNodeComplete17;                   ///< NodeComplete17
    BOOL                                mNodeComplete18;                   ///< NodeComplete18
    BOOL                                mNodeComplete19;                   ///< NodeComplete19
    BOOL                                mNodeComplete20;                   ///< NodeComplete20
    BOOL                                mNodeComplete21;                   ///< NodeComplete21
    BOOL                                mNodeComplete22;                   ///< NodeComplete22
    BOOL                                mNodeComplete23;                   ///< NodeComplete23
    BOOL                                mNodeComplete24;                   ///< NodeComplete24
    BOOL                                mNodeComplete25;                   ///< NodeComplete25
    BOOL                                mNodeComplete26;                   ///< NodeComplete26
    BOOL                                mNodeComplete27;                   ///< NodeComplete27
    BOOL                                mNodeComplete28;                   ///< NodeComplete28
    BOOL                                mNodeComplete29;                   ///< NodeComplete29
    BOOL                                mNodeComplete30;                   ///< NodeComplete30
    BOOL                                mNodeComplete31;                   ///< NodeComplete31
    INT                                 mLinkMetadata0;                    ///< LinkMetadata0
    INT                                 mLinkMetadata1;                    ///< LinkMetadata1
    INT                                 mLinkMetadata2;                    ///< LinkMetadata2
    INT                                 mLinkMetadata3;                    ///< LinkMetadata3
    INT                                 mLinkMetadata4;                    ///< LinkMetadata4
    INT                                 mLinkMetadata5;                    ///< LinkMetadata5
    INT                                 mLinkMetadata6;                    ///< LinkMetadata6
    INT                                 mLinkMetadata7;                    ///< LinkMetadata7
    INT                                 mLinkMetadata8;                    ///< LinkMetadata8
    INT                                 mLinkMetadata9;                    ///< LinkMetadata9
    INT                                 mLinkMetadata10;                   ///< LinkMetadata10
    INT                                 mLinkMetadata11;                   ///< LinkMetadata11
    INT                                 mLinkMetadata12;                   ///< LinkMetadata12
    INT                                 mLinkMetadata13;                   ///< LinkMetadata13
    INT                                 mLinkMetadata14;                   ///< LinkMetadata14
    INT                                 mLinkMetadata15;                   ///< LinkMetadata15
    INT                                 mLinkMetadata16;                   ///< LinkMetadata16
    INT                                 mLinkMetadata17;                   ///< LinkMetadata17
    INT                                 mLinkMetadata18;                   ///< LinkMetadata18
    INT                                 mLinkMetadata19;                   ///< LinkMetadata19
};

/// @brief Offsets of each member in the property blob
static const SIZE_T MainPropertyOffsets[] =
{
    offsetof(MainPropertyBlob, mAECFrameControl),
    offsetof(MainPropertyBlob, mAECFrameInfo),
    offsetof(MainPropertyBlob, mAWBFrameControl),
    offsetof(MainPropertyBlob, mAWBFrameInfo),
    offsetof(MainPropertyBlob, mAFFrameControl),
    offsetof(MainPropertyBlob, mAFFrameInfo),
    offsetof(MainPropertyBlob, mAFPDFrameInfo),
    offsetof(MainPropertyBlob, mAFBAFDependencyMet),
    offsetof(MainPropertyBlob, mASD),
    offsetof(MainPropertyBlob, mAFDFrameControl),
    offsetof(MainPropertyBlob, mAFDFrameInfo),
    offsetof(MainPropertyBlob, mAECStatsControl),
    offsetof(MainPropertyBlob, mAWBStatsControl),
    offsetof(MainPropertyBlob, mAFStatsControl),
    offsetof(MainPropertyBlob, mAFDStatsControl),
    offsetof(MainPropertyBlob, mIHistStatsControl),
    offsetof(MainPropertyBlob, mCrossAECStats),
    offsetof(MainPropertyBlob, mCrossAWBStats),
    offsetof(MainPropertyBlob, mCrossAFStats),
    offsetof(MainPropertyBlob, pAECPeerInfo),
    offsetof(MainPropertyBlob, pAWBPeerInfo),
    offsetof(MainPropertyBlob, pAFPeerInfo),
    offsetof(MainPropertyBlob, pAFDPeerInfo),
    offsetof(MainPropertyBlob, pASDPeerInfo),
    offsetof(MainPropertyBlob, mFOVCFrameInfo),
    offsetof(MainPropertyBlob, mPDHwConfig),
    offsetof(MainPropertyBlob, mSensorCurrentMode),
    offsetof(MainPropertyBlob, mPostSensorGainId),
    offsetof(MainPropertyBlob, mSensorFlashCurrent),
    offsetof(MainPropertyBlob, mSensorMetaData),
    offsetof(MainPropertyBlob, mSensorExposureStartTime),
    offsetof(MainPropertyBlob, mSensorProperties),
    offsetof(MainPropertyBlob, mSensorPDAFInfo),
    offsetof(MainPropertyBlob, mSensorNumberOfLEDs),
    offsetof(MainPropertyBlob, mSensorResolutionInfo),
    offsetof(MainPropertyBlob, mRERCompleted),
    offsetof(MainPropertyBlob, mIFEDigitalZoom),
    offsetof(MainPropertyBlob, mIFEGammaOutput),
    offsetof(MainPropertyBlob, mIFEAppliedCrop),
    offsetof(MainPropertyBlob, mISPBHistConfig),
    offsetof(MainPropertyBlob, mISPTintlessBGConfig),
    offsetof(MainPropertyBlob, mIFEScaleOutput),
    offsetof(MainPropertyBlob, pParsedAWBBGStatsOutput),
    offsetof(MainPropertyBlob, pParsedBFStatsOutput),
    offsetof(MainPropertyBlob, pParsedBHistStatsOutput),
    offsetof(MainPropertyBlob, pParsedCSStatsOutput),
    offsetof(MainPropertyBlob, pParsedHDRBEStatsOutput),
    offsetof(MainPropertyBlob, pParsedHDRBHistStatsOutput),
    offsetof(MainPropertyBlob, pParsedIHistStatsOutput),
    offsetof(MainPropertyBlob, pParsedRSStatsOutput),
    offsetof(MainPropertyBlob, pParsedTintlessBGStatsOutput),
    offsetof(MainPropertyBlob, mBPSGammaOutput),
    offsetof(MainPropertyBlob, mJPEGEncodeOutInfo),
    offsetof(MainPropertyBlob, mJPEGEncodeOutInfoThumbnail),
    offsetof(MainPropertyBlob, mIPETotalFrameMFNR),
    offsetof(MainPropertyBlob, mIPETotalFrameMFSR),
    offsetof(MainPropertyBlob, mFDFrameSettings),
    offsetof(MainPropertyBlob, mLRMEFrameSettings),
    offsetof(MainPropertyBlob, mIFEADRCInfoOutput),
    offsetof(MainPropertyBlob, mBPSADRCInfoOutput),
    offsetof(MainPropertyBlob, mIFEADRCParams),
    offsetof(MainPropertyBlob, mIntermediateDimension),
    offsetof(MainPropertyBlob, mIPEGamma15PreCalculation),
    offsetof(MainPropertyBlob, mNodeComplete0),
    offsetof(MainPropertyBlob, mNodeComplete1),
    offsetof(MainPropertyBlob, mNodeComplete2),
    offsetof(MainPropertyBlob, mNodeComplete3),
    offsetof(MainPropertyBlob, mNodeComplete4),
    offsetof(MainPropertyBlob, mNodeComplete5),
    offsetof(MainPropertyBlob, mNodeComplete6),
    offsetof(MainPropertyBlob, mNodeComplete7),
    offsetof(MainPropertyBlob, mNodeComplete8),
    offsetof(MainPropertyBlob, mNodeComplete9),
    offsetof(MainPropertyBlob, mNodeComplete10),
    offsetof(MainPropertyBlob, mNodeComplete11),
    offsetof(MainPropertyBlob, mNodeComplete12),
    offsetof(MainPropertyBlob, mNodeComplete13),
    offsetof(MainPropertyBlob, mNodeComplete14),
    offsetof(MainPropertyBlob, mNodeComplete15),
    offsetof(MainPropertyBlob, mNodeComplete16),
    offsetof(MainPropertyBlob, mNodeComplete17),
    offsetof(MainPropertyBlob, mNodeComplete18),
    offsetof(MainPropertyBlob, mNodeComplete19),
    offsetof(MainPropertyBlob, mNodeComplete20),
    offsetof(MainPropertyBlob, mNodeComplete21),
    offsetof(MainPropertyBlob, mNodeComplete22),
    offsetof(MainPropertyBlob, mNodeComplete23),
    offsetof(MainPropertyBlob, mNodeComplete24),
    offsetof(MainPropertyBlob, mNodeComplete25),
    offsetof(MainPropertyBlob, mNodeComplete26),
    offsetof(MainPropertyBlob, mNodeComplete27),
    offsetof(MainPropertyBlob, mNodeComplete28),
    offsetof(MainPropertyBlob, mNodeComplete29),
    offsetof(MainPropertyBlob, mNodeComplete30),
    offsetof(MainPropertyBlob, mNodeComplete31),
    offsetof(MainPropertyBlob, mLinkMetadata0),
    offsetof(MainPropertyBlob, mLinkMetadata1),
    offsetof(MainPropertyBlob, mLinkMetadata2),
    offsetof(MainPropertyBlob, mLinkMetadata3),
    offsetof(MainPropertyBlob, mLinkMetadata4),
    offsetof(MainPropertyBlob, mLinkMetadata5),
    offsetof(MainPropertyBlob, mLinkMetadata6),
    offsetof(MainPropertyBlob, mLinkMetadata7),
    offsetof(MainPropertyBlob, mLinkMetadata8),
    offsetof(MainPropertyBlob, mLinkMetadata9),
    offsetof(MainPropertyBlob, mLinkMetadata10),
    offsetof(MainPropertyBlob, mLinkMetadata11),
    offsetof(MainPropertyBlob, mLinkMetadata12),
    offsetof(MainPropertyBlob, mLinkMetadata13),
    offsetof(MainPropertyBlob, mLinkMetadata14),
    offsetof(MainPropertyBlob, mLinkMetadata15),
    offsetof(MainPropertyBlob, mLinkMetadata16),
    offsetof(MainPropertyBlob, mLinkMetadata17),
    offsetof(MainPropertyBlob, mLinkMetadata18),
    offsetof(MainPropertyBlob, mLinkMetadata19),
};

/// @brief Sizes of each member in the property blob
static const SIZE_T MainPropertySizes[] =
{
    sizeof(AECFrameControl),
    sizeof(AECFrameInformation),
    sizeof(AWBFrameControl),
    sizeof(AWBFrameInfo),
    sizeof(AFFrameControl),
    sizeof(AFFrameInformation),
    sizeof(AFPDAFData),
    sizeof(BOOL),
    sizeof(ASDOutput),
    sizeof(UINT32),
    sizeof(AFDFrameInfo),
    sizeof(AECStatsControl),
    sizeof(AWBStatsControl),
    sizeof(AFStatsControl),
    sizeof(AFDStatsControl),
    sizeof(IHistStatsControl),
    sizeof(UINT64),
    sizeof(UINT64),
    sizeof(UINT64),
    sizeof(VOID*),
    sizeof(VOID*),
    sizeof(VOID*),
    sizeof(VOID*),
    sizeof(VOID*),
    sizeof(FOVCOutput),
    sizeof(PDHwConfig),
    sizeof(UINT32),
    sizeof(FLOAT),
    sizeof(UINT),
    sizeof(SensorMetaData),
    sizeof(UINT64),
    sizeof(SensorProperties),
    sizeof(SensorPDAFInfo),
    sizeof(UINT),
    sizeof(SensorResolutionInfo),
    sizeof(BOOL),
    sizeof(IFECropInfo),
    sizeof(GammaInfo),
    sizeof(IFECropInfo),
    sizeof(PropertyISPBHistStats),
    sizeof(PropertyISPTintlessBG),
    sizeof(IFEScalerOutput),
    sizeof(ParsedAWBBGStatsOutput*),
    sizeof(ParsedBFStatsOutput*),
    sizeof(ParsedBHistStatsOutput*),
    sizeof(ParsedCSStatsOutput*),
    sizeof(ParsedHDRBEStatsOutput*),
    sizeof(ParsedHDRBHistStatsOutput*),
    sizeof(ParsedIHistStatsOutput*),
    sizeof(ParsedRSStatsOutput*),
    sizeof(ParsedTintlessBGStatsOutput*),
    sizeof(GammaInfo),
    sizeof(EncoderOutInfo),
    sizeof(EncoderOutInfo),
    sizeof(UINT),
    sizeof(UINT),
    sizeof(FDPropertyFrameSettings),
    sizeof(LRMEPropertyFrameSettings),
    sizeof(PropertyISPADRCInfo),
    sizeof(PropertyISPADRCInfo),
    sizeof(PropertyISPADRCParams),
    sizeof(PropertyISPIntermediateDimension),
    sizeof(IPEGammaPreOutput),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
    sizeof(INT),
};

/* End of MainProperty */


/* Beginning of InternalProperty */

static const PropertyID PropertyIDAECInternal                         = PropertyIDPerFrameInternalBegin + 0x00;
static const PropertyID PropertyIDAFInternal                          = PropertyIDPerFrameInternalBegin + 0x01;
static const PropertyID PropertyIDASDInternal                         = PropertyIDPerFrameInternalBegin + 0x02;
static const PropertyID PropertyIDAWBInternal                         = PropertyIDPerFrameInternalBegin + 0x03;
static const PropertyID PropertyIDAFDInternal                         = PropertyIDPerFrameInternalBegin + 0x04;
static const PropertyID PropertyIDBasePDInternal                      = PropertyIDPerFrameInternalBegin + 0x05;
static const PropertyID PropertyIDISPAECBG                            = PropertyIDPerFrameInternalBegin + 0x06;
static const PropertyID PropertyIDISPAWBBGConfig                      = PropertyIDPerFrameInternalBegin + 0x07;
static const PropertyID PropertyIDISPBFConfig                         = PropertyIDPerFrameInternalBegin + 0x08;
static const PropertyID PropertyIDISPCSConfig                         = PropertyIDPerFrameInternalBegin + 0x09;
static const PropertyID PropertyIDISPHDRBEConfig                      = PropertyIDPerFrameInternalBegin + 0x0A;
static const PropertyID PropertyIDISPHDRBHistConfig                   = PropertyIDPerFrameInternalBegin + 0x0B;
static const PropertyID PropertyIDISPIHistConfig                      = PropertyIDPerFrameInternalBegin + 0x0C;
static const PropertyID PropertyIDISPRegionsStats                     = PropertyIDPerFrameInternalBegin + 0x0D;
static const PropertyID PropertyIDISPROIStats                         = PropertyIDPerFrameInternalBegin + 0x0E;
static const PropertyID PropertyIDISPRSConfig                         = PropertyIDPerFrameInternalBegin + 0x0F;
static const PropertyID PropertyIDFDInternalPerFrameSettings          = PropertyIDPerFrameInternalBegin + 0x10;
static const PropertyID PropertyIDSkipStatsParserTypeBF               = PropertyIDPerFrameInternalBegin + 0x11;
static const PropertyID PropertyIDSkipStatsParserTypeHDRBE            = PropertyIDPerFrameInternalBegin + 0x12;
static const PropertyID PropertyIDSkipStatsParserTypeBHist            = PropertyIDPerFrameInternalBegin + 0x13;
static const PropertyID PropertyIDSkipStatsParserTypeHDRBHist         = PropertyIDPerFrameInternalBegin + 0x14;
static const PropertyID PropertyIDSkipStatsParserTypeRS               = PropertyIDPerFrameInternalBegin + 0x15;
static const PropertyID PropertyIDSkipStatsParserTypeCS               = PropertyIDPerFrameInternalBegin + 0x16;
static const PropertyID PropertyIDSkipStatsParserTypeAWBBG            = PropertyIDPerFrameInternalBegin + 0x17;
static const PropertyID PropertyIDSkipStatsParserTypeTintlessBG       = PropertyIDPerFrameInternalBegin + 0x18;
static const PropertyID PropertyIDSkipStatsParserTypeIHist            = PropertyIDPerFrameInternalBegin + 0x19;
static const PropertyID PropertyIDSkipStatsParserTypeBPSAWBBG         = PropertyIDPerFrameInternalBegin + 0x1A;

extern const CHAR* pInternalPropertyStrings[27];

static const PropertyID PropertyIDPerFrameInternalEnd = PropertyIDPerFrameInternalBegin + 0x1A;

/// @brief LUT of each member in the property blob
static const PropertyID InternalPropertyLinearLUT[] =
{
    PropertyIDAECInternal,
    PropertyIDAFInternal,
    PropertyIDASDInternal,
    PropertyIDAWBInternal,
    PropertyIDAFDInternal,
    PropertyIDBasePDInternal,
    PropertyIDISPAECBG,
    PropertyIDISPAWBBGConfig,
    PropertyIDISPBFConfig,
    PropertyIDISPCSConfig,
    PropertyIDISPHDRBEConfig,
    PropertyIDISPHDRBHistConfig,
    PropertyIDISPIHistConfig,
    PropertyIDISPRegionsStats,
    PropertyIDISPROIStats,
    PropertyIDISPRSConfig,
    PropertyIDFDInternalPerFrameSettings,
    PropertyIDSkipStatsParserTypeBF,
    PropertyIDSkipStatsParserTypeHDRBE,
    PropertyIDSkipStatsParserTypeBHist,
    PropertyIDSkipStatsParserTypeHDRBHist,
    PropertyIDSkipStatsParserTypeRS,
    PropertyIDSkipStatsParserTypeCS,
    PropertyIDSkipStatsParserTypeAWBBG,
    PropertyIDSkipStatsParserTypeTintlessBG,
    PropertyIDSkipStatsParserTypeIHist,
    PropertyIDSkipStatsParserTypeBPSAWBBG,
};

/// @brief Collection of properties in a struct
struct InternalPropertyBlob
{
    AECOutputInternal                   mAECInternal;                      ///< AECInternal
    AFOutputInternal                    mAFInternal;                       ///< AFInternal
    ASDOutputInternal                   mASDInternal;                      ///< ASDInternal
    AWBOutputInternal                   mAWBInternal;                      ///< AWBInternal
    AFDOutputInternal                   mAFDInternal;                      ///< AFDInternal
    BOOL                                mBasePDInternal;                   ///< BasePDInternal
    BGStatsOutput                       mISPAECBG;                         ///< ISPAECBG
    PropertyISPAWBBGStats               mISPAWBBGConfig;                   ///< ISPAWBBGConfig
    PropertyISPBFStats                  mISPBFConfig;                      ///< ISPBFConfig
    PropertyISPCSStats                  mISPCSConfig;                      ///< ISPCSConfig
    PropertyISPHDRBEStats               mISPHDRBEConfig;                   ///< ISPHDRBEConfig
    PropertyISPHDRBHistStats            mISPHDRBHistConfig;                ///< ISPHDRBHistConfig
    PropertyISPIHistStats               mISPIHistConfig;                   ///< ISPIHistConfig
    ISPRegionsStatsParams               mISPRegionsStats;                  ///< ISPRegionsStats
    ISPStatsROIParams                   mISPROIStats;                      ///< ISPROIStats
    PropertyISPRSStats                  mISPRSConfig;                      ///< ISPRSConfig
    FDPerFrameSettings                  mFDInternalPerFrameSettings;       ///< FDInternalPerFrameSettings
    BOOL                                mSkipStatsParserTypeBF;            ///< SkipStatsParserTypeBF
    BOOL                                mSkipStatsParserTypeHDRBE;         ///< SkipStatsParserTypeHDRBE
    BOOL                                mSkipStatsParserTypeBHist;         ///< SkipStatsParserTypeBHist
    BOOL                                mSkipStatsParserTypeHDRBHist;      ///< SkipStatsParserTypeHDRBHist
    BOOL                                mSkipStatsParserTypeRS;            ///< SkipStatsParserTypeRS
    BOOL                                mSkipStatsParserTypeCS;            ///< SkipStatsParserTypeCS
    BOOL                                mSkipStatsParserTypeAWBBG;         ///< SkipStatsParserTypeAWBBG
    BOOL                                mSkipStatsParserTypeTintlessBG;    ///< SkipStatsParserTypeTintlessBG
    BOOL                                mSkipStatsParserTypeIHist;         ///< SkipStatsParserTypeIHist
    BOOL                                mSkipStatsParserTypeBPSAWBBG;      ///< SkipStatsParserTypeBPSAWBBG
};

/// @brief Offsets of each member in the property blob
static const SIZE_T InternalPropertyOffsets[] =
{
    offsetof(InternalPropertyBlob, mAECInternal),
    offsetof(InternalPropertyBlob, mAFInternal),
    offsetof(InternalPropertyBlob, mASDInternal),
    offsetof(InternalPropertyBlob, mAWBInternal),
    offsetof(InternalPropertyBlob, mAFDInternal),
    offsetof(InternalPropertyBlob, mBasePDInternal),
    offsetof(InternalPropertyBlob, mISPAECBG),
    offsetof(InternalPropertyBlob, mISPAWBBGConfig),
    offsetof(InternalPropertyBlob, mISPBFConfig),
    offsetof(InternalPropertyBlob, mISPCSConfig),
    offsetof(InternalPropertyBlob, mISPHDRBEConfig),
    offsetof(InternalPropertyBlob, mISPHDRBHistConfig),
    offsetof(InternalPropertyBlob, mISPIHistConfig),
    offsetof(InternalPropertyBlob, mISPRegionsStats),
    offsetof(InternalPropertyBlob, mISPROIStats),
    offsetof(InternalPropertyBlob, mISPRSConfig),
    offsetof(InternalPropertyBlob, mFDInternalPerFrameSettings),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeBF),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeHDRBE),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeBHist),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeHDRBHist),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeRS),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeCS),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeAWBBG),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeTintlessBG),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeIHist),
    offsetof(InternalPropertyBlob, mSkipStatsParserTypeBPSAWBBG),
};

/// @brief Sizes of each member in the property blob
static const SIZE_T InternalPropertySizes[] =
{
    sizeof(AECOutputInternal),
    sizeof(AFOutputInternal),
    sizeof(ASDOutputInternal),
    sizeof(AWBOutputInternal),
    sizeof(AFDOutputInternal),
    sizeof(BOOL),
    sizeof(BGStatsOutput),
    sizeof(PropertyISPAWBBGStats),
    sizeof(PropertyISPBFStats),
    sizeof(PropertyISPCSStats),
    sizeof(PropertyISPHDRBEStats),
    sizeof(PropertyISPHDRBHistStats),
    sizeof(PropertyISPIHistStats),
    sizeof(ISPRegionsStatsParams),
    sizeof(ISPStatsROIParams),
    sizeof(PropertyISPRSStats),
    sizeof(FDPerFrameSettings),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
    sizeof(BOOL),
};

/* End of InternalProperty */


/* Beginning of UsecaseProperty */

static const PropertyID PropertyIDUsecaseSensorModes                  = PropertyIDUsecaseBegin + 0x00;
static const PropertyID PropertyIDUsecaseBatch                        = PropertyIDUsecaseBegin + 0x01;
static const PropertyID PropertyIDUsecaseFPS                          = PropertyIDUsecaseBegin + 0x02;
static const PropertyID PropertyIDUsecaseLensInfo                     = PropertyIDUsecaseBegin + 0x03;
static const PropertyID PropertyIDUsecaseCameraModuleInfo             = PropertyIDUsecaseBegin + 0x04;
static const PropertyID PropertyIDUsecasePDLibInfo                    = PropertyIDUsecaseBegin + 0x05;
static const PropertyID PropertyIDUsecaseSensorCurrentMode            = PropertyIDUsecaseBegin + 0x06;
static const PropertyID PropertyIDUsecaseSensorISO100Gain             = PropertyIDUsecaseBegin + 0x07;
static const PropertyID PropertyIDUsecaseAWBFrameControl              = PropertyIDUsecaseBegin + 0x08;
static const PropertyID PropertyIDUsecaseAECFrameControl              = PropertyIDUsecaseBegin + 0x09;
static const PropertyID PropertyIDUsecaseAFFrameControl               = PropertyIDUsecaseBegin + 0x0A;
static const PropertyID PropertyIDUsecaseAFFrameInformation           = PropertyIDUsecaseBegin + 0x0B;
static const PropertyID PropertyIDUsecaseAECStatsControl              = PropertyIDUsecaseBegin + 0x0C;
static const PropertyID PropertyIDUsecaseAWBStatsControl              = PropertyIDUsecaseBegin + 0x0D;
static const PropertyID PropertyIDUsecaseAFStatsControl               = PropertyIDUsecaseBegin + 0x0E;
static const PropertyID PropertyIDUsecaseStatsStreamInitConfig        = PropertyIDUsecaseBegin + 0x0F;
static const PropertyID PropertyIDUsecasePipelineOutputDimensions     = PropertyIDUsecaseBegin + 0x10;
static const PropertyID PropertyIDUsecaseFDResults                    = PropertyIDUsecaseBegin + 0x11;
static const PropertyID PropertyIDUsecaseFDMetadataResults            = PropertyIDUsecaseBegin + 0x12;
static const PropertyID PropertyIDUsecaseFDContourResults             = PropertyIDUsecaseBegin + 0x13;
static const PropertyID PropertyIDUsecaseIFEInputResolution           = PropertyIDUsecaseBegin + 0x14;
static const PropertyID PropertyIDUsecaseIFEOutputResolution          = PropertyIDUsecaseBegin + 0x15;
static const PropertyID PropertyIDUsecaseIFEPDAFInfo                  = PropertyIDUsecaseBegin + 0x16;
static const PropertyID PropertyIDUsecaseHWPDConfig                   = PropertyIDUsecaseBegin + 0x17;
static const PropertyID PropertyIDUsecaseChiTuningModeParameter       = PropertyIDUsecaseBegin + 0x18;
static const PropertyID PropertyIDUsecaseAESyncStartLockTagID         = PropertyIDUsecaseBegin + 0x19;
static const PropertyID PropertyIDUsecaseAESyncStopLockTagID          = PropertyIDUsecaseBegin + 0x1A;
static const PropertyID PropertyIDUsecaseIFEPDHWInfo                  = PropertyIDUsecaseBegin + 0x1B;
static const PropertyID PropertyIDUsecasePDHWEnableConditions         = PropertyIDUsecaseBegin + 0x1C;
static const PropertyID PropertyIDUsecasePDLibInputPDHWEnableConditions = PropertyIDUsecaseBegin + 0x1D;
static const PropertyID PropertyIDUsecaseTrackerResults               = PropertyIDUsecaseBegin + 0x1E;

extern const CHAR* pUsecasePropertyStrings[31];

static const PropertyID PropertyIDUsecaseEnd = PropertyIDUsecaseBegin + 0x1E;

/// @brief LUT of each member in the property blob
static const PropertyID UsecasePropertyLinearLUT[] =
{
    PropertyIDUsecaseSensorModes,
    PropertyIDUsecaseBatch,
    PropertyIDUsecaseFPS,
    PropertyIDUsecaseLensInfo,
    PropertyIDUsecaseCameraModuleInfo,
    PropertyIDUsecasePDLibInfo,
    PropertyIDUsecaseSensorCurrentMode,
    PropertyIDUsecaseSensorISO100Gain,
    PropertyIDUsecaseAWBFrameControl,
    PropertyIDUsecaseAECFrameControl,
    PropertyIDUsecaseAFFrameControl,
    PropertyIDUsecaseAFFrameInformation,
    PropertyIDUsecaseAECStatsControl,
    PropertyIDUsecaseAWBStatsControl,
    PropertyIDUsecaseAFStatsControl,
    PropertyIDUsecaseStatsStreamInitConfig,
    PropertyIDUsecasePipelineOutputDimensions,
    PropertyIDUsecaseFDResults,
    PropertyIDUsecaseFDMetadataResults,
    PropertyIDUsecaseFDContourResults,
    PropertyIDUsecaseIFEInputResolution,
    PropertyIDUsecaseIFEOutputResolution,
    PropertyIDUsecaseIFEPDAFInfo,
    PropertyIDUsecaseHWPDConfig,
    PropertyIDUsecaseChiTuningModeParameter,
    PropertyIDUsecaseAESyncStartLockTagID,
    PropertyIDUsecaseAESyncStopLockTagID,
    PropertyIDUsecaseIFEPDHWInfo,
    PropertyIDUsecasePDHWEnableConditions,
    PropertyIDUsecasePDLibInputPDHWEnableConditions,
    PropertyIDUsecaseTrackerResults,
};

/// @brief Collection of properties in a struct
struct UsecasePropertyBlob
{
    UsecaseSensorModes                  mUsecaseSensorModes;               ///< UsecaseSensorModes
    UINT                                mUsecaseBatch;                     ///< UsecaseBatch
    UINT                                mUsecaseFPS;                       ///< UsecaseFPS
    LensInfo                            mUsecaseLensInfo;                  ///< UsecaseLensInfo
    CameraConfigurationInformation      mUsecaseCameraModuleInfo;          ///< UsecaseCameraModuleInfo
    UINTPTR_T                           mUsecasePDLibInfo;                 ///< UsecasePDLibInfo
    UINT                                mUsecaseSensorCurrentMode;         ///< UsecaseSensorCurrentMode
    FLOAT                               mUsecaseSensorISO100Gain;          ///< UsecaseSensorISO100Gain
    AWBFrameControl                     mUsecaseAWBFrameControl;           ///< UsecaseAWBFrameControl
    AECFrameControl                     mUsecaseAECFrameControl;           ///< UsecaseAECFrameControl
    AFFrameControl                      mUsecaseAFFrameControl;            ///< UsecaseAFFrameControl
    AFFrameInformation                  mUsecaseAFFrameInformation;        ///< UsecaseAFFrameInformation
    AECStatsControl                     mUsecaseAECStatsControl;           ///< UsecaseAECStatsControl
    AWBStatsControl                     mUsecaseAWBStatsControl;           ///< UsecaseAWBStatsControl
    AFStatsControl                      mUsecaseAFStatsControl;            ///< UsecaseAFStatsControl
    StatsStreamInitConfig               mUsecaseStatsStreamInitConfig;     ///< UsecaseStatsStreamInitConfig
    PropertyPipelineOutputDimensions    mUsecasePipelineOutputDimensions;  ///< UsecasePipelineOutputDimensions
    FaceROIInformation                  mUsecaseFDResults;                 ///< UsecaseFDResults
    FDMetaDataResults                   mUsecaseFDMetadataResults;         ///< UsecaseFDMetadataResults
    FDMetaDataFaceContourResults        mUsecaseFDContourResults;          ///< UsecaseFDContourResults
    IFEInputResolution                  mUsecaseIFEInputResolution;        ///< UsecaseIFEInputResolution
    IFEOutputResolution                 mUsecaseIFEOutputResolution;       ///< UsecaseIFEOutputResolution
    PDLibDataBufferInfo                 mUsecaseIFEPDAFInfo;               ///< UsecaseIFEPDAFInfo
    PDHwConfig                          mUsecaseHWPDConfig;                ///< UsecaseHWPDConfig
    ChiTuningModeParameter              mUsecaseChiTuningModeParameter;    ///< UsecaseChiTuningModeParameter
    UINT64                              mUsecaseAESyncStartLockTagID;      ///< UsecaseAESyncStartLockTagID
    UINT64                              mUsecaseAESyncStopLockTagID;       ///< UsecaseAESyncStopLockTagID
    PDHwAvailablity                     mUsecaseIFEPDHWInfo;               ///< UsecaseIFEPDHWInfo
    PDHWEnableConditions                mUsecasePDHWEnableConditions;      ///< UsecasePDHWEnableConditions
    PDHWEnableConditions                mUsecasePDLibInputPDHWEnableConditions;///< UsecasePDLibInputPDHWEnableConditions
    TrackerROIInformation               mUsecaseTrackerResults;            ///< UsecaseTrackerResults
};

/// @brief Offsets of each member in the property blob
static const SIZE_T UsecasePropertyOffsets[] =
{
    offsetof(UsecasePropertyBlob, mUsecaseSensorModes),
    offsetof(UsecasePropertyBlob, mUsecaseBatch),
    offsetof(UsecasePropertyBlob, mUsecaseFPS),
    offsetof(UsecasePropertyBlob, mUsecaseLensInfo),
    offsetof(UsecasePropertyBlob, mUsecaseCameraModuleInfo),
    offsetof(UsecasePropertyBlob, mUsecasePDLibInfo),
    offsetof(UsecasePropertyBlob, mUsecaseSensorCurrentMode),
    offsetof(UsecasePropertyBlob, mUsecaseSensorISO100Gain),
    offsetof(UsecasePropertyBlob, mUsecaseAWBFrameControl),
    offsetof(UsecasePropertyBlob, mUsecaseAECFrameControl),
    offsetof(UsecasePropertyBlob, mUsecaseAFFrameControl),
    offsetof(UsecasePropertyBlob, mUsecaseAFFrameInformation),
    offsetof(UsecasePropertyBlob, mUsecaseAECStatsControl),
    offsetof(UsecasePropertyBlob, mUsecaseAWBStatsControl),
    offsetof(UsecasePropertyBlob, mUsecaseAFStatsControl),
    offsetof(UsecasePropertyBlob, mUsecaseStatsStreamInitConfig),
    offsetof(UsecasePropertyBlob, mUsecasePipelineOutputDimensions),
    offsetof(UsecasePropertyBlob, mUsecaseFDResults),
    offsetof(UsecasePropertyBlob, mUsecaseFDMetadataResults),
    offsetof(UsecasePropertyBlob, mUsecaseFDContourResults),
    offsetof(UsecasePropertyBlob, mUsecaseIFEInputResolution),
    offsetof(UsecasePropertyBlob, mUsecaseIFEOutputResolution),
    offsetof(UsecasePropertyBlob, mUsecaseIFEPDAFInfo),
    offsetof(UsecasePropertyBlob, mUsecaseHWPDConfig),
    offsetof(UsecasePropertyBlob, mUsecaseChiTuningModeParameter),
    offsetof(UsecasePropertyBlob, mUsecaseAESyncStartLockTagID),
    offsetof(UsecasePropertyBlob, mUsecaseAESyncStopLockTagID),
    offsetof(UsecasePropertyBlob, mUsecaseIFEPDHWInfo),
    offsetof(UsecasePropertyBlob, mUsecasePDHWEnableConditions),
    offsetof(UsecasePropertyBlob, mUsecasePDLibInputPDHWEnableConditions),
    offsetof(UsecasePropertyBlob, mUsecaseTrackerResults),
};

/// @brief Sizes of each member in the property blob
static const SIZE_T UsecasePropertySizes[] =
{
    sizeof(UsecaseSensorModes),
    sizeof(UINT),
    sizeof(UINT),
    sizeof(LensInfo),
    sizeof(CameraConfigurationInformation),
    sizeof(UINTPTR_T),
    sizeof(UINT),
    sizeof(FLOAT),
    sizeof(AWBFrameControl),
    sizeof(AECFrameControl),
    sizeof(AFFrameControl),
    sizeof(AFFrameInformation),
    sizeof(AECStatsControl),
    sizeof(AWBStatsControl),
    sizeof(AFStatsControl),
    sizeof(StatsStreamInitConfig),
    sizeof(PropertyPipelineOutputDimensions),
    sizeof(FaceROIInformation),
    sizeof(FDMetaDataResults),
    sizeof(FDMetaDataFaceContourResults),
    sizeof(IFEInputResolution),
    sizeof(IFEOutputResolution),
    sizeof(PDLibDataBufferInfo),
    sizeof(PDHwConfig),
    sizeof(ChiTuningModeParameter),
    sizeof(UINT64),
    sizeof(UINT64),
    sizeof(PDHwAvailablity),
    sizeof(PDHWEnableConditions),
    sizeof(PDHWEnableConditions),
    sizeof(TrackerROIInformation),
};

/* End of UsecaseProperty */


/* Beginning of DebugDataProperty */

static const PropertyID PropertyIDDebugDataAll                        = PropertyIDPerFrameDebugDataBegin + 0x00;
static const PropertyID PropertyIDDebugDataAEC                        = PropertyIDPerFrameDebugDataBegin + 0x01;
static const PropertyID PropertyIDDebugDataAWB                        = PropertyIDPerFrameDebugDataBegin + 0x02;
static const PropertyID PropertyIDDebugDataAF                         = PropertyIDPerFrameDebugDataBegin + 0x03;
static const PropertyID PropertyIDTuningDataIFE                       = PropertyIDPerFrameDebugDataBegin + 0x04;
static const PropertyID PropertyIDTuningDataIPE                       = PropertyIDPerFrameDebugDataBegin + 0x05;
static const PropertyID PropertyIDTuningDataBPS                       = PropertyIDPerFrameDebugDataBegin + 0x06;

extern const CHAR* pDebugDataPropertyStrings[7];

static const PropertyID PropertyIDPerFrameDebugDataEnd = PropertyIDPerFrameDebugDataBegin + 0x06;

/// @brief LUT of each member in the property blob
static const PropertyID DebugDataPropertyLinearLUT[] =
{
    PropertyIDDebugDataAll,
    PropertyIDDebugDataAEC,
    PropertyIDDebugDataAWB,
    PropertyIDDebugDataAF,
    PropertyIDTuningDataIFE,
    PropertyIDTuningDataIPE,
    PropertyIDTuningDataBPS,
};

/// @brief Collection of properties in a struct
struct DebugDataPropertyBlob
{
    DebugData                           mDebugDataAll;                     ///< DebugDataAll
    DebugData                           mDebugDataAEC;                     ///< DebugDataAEC
    DebugData                           mDebugDataAWB;                     ///< DebugDataAWB
    DebugData                           mDebugDataAF;                      ///< DebugDataAF
    DebugData                           mTuningDataIFE;                    ///< TuningDataIFE
    DebugData                           mTuningDataIPE;                    ///< TuningDataIPE
    DebugData                           mTuningDataBPS;                    ///< TuningDataBPS
};

/// @brief Offsets of each member in the property blob
static const SIZE_T DebugDataPropertyOffsets[] =
{
    offsetof(DebugDataPropertyBlob, mDebugDataAll),
    offsetof(DebugDataPropertyBlob, mDebugDataAEC),
    offsetof(DebugDataPropertyBlob, mDebugDataAWB),
    offsetof(DebugDataPropertyBlob, mDebugDataAF),
    offsetof(DebugDataPropertyBlob, mTuningDataIFE),
    offsetof(DebugDataPropertyBlob, mTuningDataIPE),
    offsetof(DebugDataPropertyBlob, mTuningDataBPS),
};

/// @brief Sizes of each member in the property blob
static const SIZE_T DebugDataPropertySizes[] =
{
    sizeof(DebugData),
    sizeof(DebugData),
    sizeof(DebugData),
    sizeof(DebugData),
    sizeof(DebugData),
    sizeof(DebugData),
    sizeof(DebugData),
};

/* End of DebugDataProperty */

CAMX_NAMESPACE_END
#endif // G_CAMXPROPERTIES_H
