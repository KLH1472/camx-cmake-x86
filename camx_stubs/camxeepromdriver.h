#ifndef STUB_CAMXEEPROMDRIVER_H
#define STUB_CAMXEEPROMDRIVER_H
#include "camxtypes.h"
struct ImageDimensions { UINT32 widthPixels; UINT32 heightLines; };
enum class EEPROMIlluminantType { D65=0, TL84=1, A=2, D50=3, H=4, MAX=5 };
struct RegisterSetting { UINT32 registerAddr; UINT32 registerData; UINT32 regAddrType; UINT32 regDataType; UINT32 delayUs; };
struct SettingsInfo { UINT32 regSettingCount; UINT32 regSettingID; RegisterSetting* regSetting; };
#endif
