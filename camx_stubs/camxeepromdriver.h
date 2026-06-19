#ifndef STUB_CAMXEEPROMDRIVER_H
#define STUB_CAMXEEPROMDRIVER_H
#include "camxtypes.h"
#include "camxeepromdriverapi.h"

struct ImageDimensions { UINT32 widthPixels; UINT32 heightLines; };

struct EEPROMDriverData
{
    UINT32 slaveAddress;
    UINT32 memoryType;
};

#endif
