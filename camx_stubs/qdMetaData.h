#ifndef STUB_QDMETADATA_H
#define STUB_QDMETADATA_H

#include <stdint.h>

enum ColorPrimaries {
    ColorPrimaries_BT709_5     = 0,
    ColorPrimaries_BT2020      = 1,
    ColorPrimaries_BT601_6_625 = 2,
    ColorPrimaries_BT601_6_525 = 3,
};

enum ColorRange {
    Range_Limited = 0,
    Range_Full    = 1,
};

enum GammaTransfer {
    Transfer_SMPTE_170M    = 0,
    Transfer_HLG           = 1,
    Transfer_SMPTE_ST2084  = 2,
    Transfer_Gamma2_2      = 3,
    Transfer_Gamma2_8      = 4,
    Transfer_Linear        = 5,
};

enum MatrixCoEfficients {
    MatrixCoEff_BT709_5     = 0,
    MatrixCoEff_BT2020      = 1,
    MatrixCoEff_BT601_6_625 = 2,
    MatrixCoEff_BT601_6_525 = 3,
};

struct Primaries {
    uint32_t rgbPrimaries[3][2];
    uint32_t whitePoint[2];
};

struct MasteringDisplay {
    uint32_t  colorVolumeSEIEnabled;
    uint32_t  maxDisplayLuminance;
    uint32_t  minDisplayLuminance;
    Primaries primaries;
};

struct ContentLightLevel {
    uint32_t lightLevelSEIEnabled;
    uint32_t maxContentLightLevel;
    uint32_t minPicAverageLightLevel;
};

struct ColorMetaData {
    ColorPrimaries     colorPrimaries;
    ColorRange         range;
    GammaTransfer      transfer;
    MatrixCoEfficients matrixCoefficients;
    ContentLightLevel  contentLightLevel;
    MasteringDisplay   masteringDisplayInfo;
};

enum DispParamType {
    SET_VT_TIMESTAMP    = 0,
    COLOR_METADATA      = 1,
    PP_PARAM_INTERLACED = 2,
    SET_VIDEO_PERF_MODE = 3,
    SET_CVP_METADATA    = 4,
};

struct private_handle_t;

static inline int setMetaData(struct private_handle_t*, enum DispParamType, void*) { return 0; }

#endif
