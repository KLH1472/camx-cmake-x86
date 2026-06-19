#ifndef STUB_TUNINGSETMANAGER_H
#define STUB_TUNINGSETMANAGER_H
#include "camxtypes.h"
#include "chituningmodeparam.h"

CAMX_NAMESPACE_BEGIN

struct TuningMode
{
    UINT32 mode;
    UINT32 subMode[16];
    UINT32 usage;
    UINT32 opMode;
};

struct TuningModeSelector
{
    UINT32     modeCount;
    TuningMode mode;
};

class TuningSetManager
{
public:
    static TuningSetManager* Create(TuningModeSelector*, UINT32) { return NULL; }
    VOID Destroy() {}
    TuningSetManager* GetChromatix() { return NULL; }
};

CAMX_NAMESPACE_END

#endif
