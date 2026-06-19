#ifndef STUB_CAMXSENSORDRIVER_H
#define STUB_CAMXSENSORDRIVER_H
#include "camxtypes.h"
enum class SensorCapability { NORMAL=0,HFR=1,IHDR=2,PDAF=3,QUADCFA=4,ZZHDR=5,FASTAEC=6,DEPTH=7,SHDR=8,FS=9,INTERNAL=10,MAX=11 };
enum class StreamType { BLOB=0,IMAGE=1,PDAF=2,HDR=3,META=4,MAX=5 };
enum class ZZHDRFirstExposurePattern { SHORTEXPOSURE=0,LONGEXPOSURE=1,MAX=2 };
struct FrameDimension { UINT32 xStart; UINT32 yStart; UINT32 width; UINT32 height; };
struct StreamConfiguration { UINT32 vc; UINT32 dt; FrameDimension frameDimension; UINT32 bitWidth; StreamType type; };
#endif
