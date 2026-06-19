#ifndef STUB_CAMXEXTERNALSENSOR_H
#define STUB_CAMXEXTERNALSENSOR_H
#include "camxtypes.h"

CAMX_NAMESPACE_BEGIN

class HwContext;

class ExternalSensor
{
public:
    static ExternalSensor* Create() { return NULL; }
    VOID   Destroy() {}
    CamxResult Initialize(UINT32, INT32, HwContext*, UINT32) { return CamxResultSuccess; }
    VOID   Uninitialize() {}
    UINT32 GetCurrentSensorMode() const { return 0; }
    CamxResult StreamOn() { return CamxResultSuccess; }
    CamxResult StreamOff() { return CamxResultSuccess; }
};

CAMX_NAMESPACE_END

#endif
