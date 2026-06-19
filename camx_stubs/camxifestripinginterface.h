#ifndef STUB_CAMXIFESTRIPINGINTERFACE_H
#define STUB_CAMXIFESTRIPINGINTERFACE_H
#include "camxtypes.h"
struct IFEStripeMNScaleDownInputV16 {
    INT16 enable; UINT16 input; UINT16 output; UINT16 pixelOffset;
    UINT16 cntOffset; INT16 interpReso; INT16 rnding_option_v; INT16 rnding_option_h;
    UINT16 inputProcessedLength; UINT16 scaleFactorHoriz; UINT16 scaleFactorVerti;
    UINT16 rightPadEnable; INT16 inputStartIndex;
};
struct IFEStripeMNScaleDownInputV20 : public IFEStripeMNScaleDownInputV16 { UINT16 preScaleCropEnable; };
struct IFEStripeCrop { UINT16 enable; UINT16 inDim; UINT16 firstOut; UINT16 lastOut; };
#endif
