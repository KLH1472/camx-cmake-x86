#ifndef STUB_CAMXSTATSDEBUGDATATYPES_H
#define STUB_CAMXSTATSDEBUGDATATYPES_H
#include "camxtypes.h"

enum class DebugDataTagID : UINT32
{
    UnusedSpace = 0,
    TuningBPSNodeInfo,
    TuningBPSChipsetVersion,
    TuningBPSFirmwareHeader,
    TuningIPE2DLUT10Register,
    TuningIFENodeInfo,
    TuningIPENodeInfo,
    MAX = 0xFFFFFFFF,
};

enum class DebugDataTagType : UINT32
{
    UInt8  = 0,
    UInt16 = 1,
    UInt32 = 2,
    Int8   = 3,
    Int16  = 4,
    Int32  = 5,
    Float  = 6,
    MAX    = 7,
};

typedef UINT32 TagCount;

struct DebugDataTag
{
    DebugDataTagID   id;
    DebugDataTagType type;
    TagCount         count;
};

#endif
