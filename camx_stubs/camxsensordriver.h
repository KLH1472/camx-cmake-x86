#ifndef STUB_CAMXSENSORDRIVER_H
#define STUB_CAMXSENSORDRIVER_H
#include "camxtypes.h"
#include "chi.h"

enum class SensorCapability { NORMAL=0,HFR=1,IHDR=2,PDAF=3,QUADCFA=4,ZZHDR=5,FASTAEC=6,DEPTH=7,SHDR=8,FS=9,INTERNAL=10,MAX=11 };
enum class StreamType { BLOB=0,IMAGE=1,PDAF=2,HDR=3,META=4,MAX=5 };
enum class ZZHDRFirstExposurePattern { SHORTEXPOSURE=0,LONGEXPOSURE=1,MAX=2 };
enum class I2CFrequencyMode { STANDARD=0,FAST=1,CUSTOM=2,FASTPLUS=3,MAX=4 };
enum class ColorFilterArrangement { BAYER_RGGB=0,BAYER_GRBG=1,BAYER_GBRG=2,BAYER_BGGR=3,BAYER_Y=4,MAX=5 };
enum class NoiseCoefficientChannel { RGGB=0,GR=1,GB=2,MAX=3 };
enum class EndianType { BIG=0,LITTLE=1 };
enum class DelayInfoType { EXPOSURE=0,GAIN=1,MAX=2 };

struct FrameDimension { UINT32 xStart; UINT32 yStart; UINT32 width; UINT32 height; UINT32 left; UINT32 top; UINT32 right; UINT32 bottom; };
struct Dimension { UINT32 width; UINT32 height; };
struct StreamConfiguration { UINT32 vc; UINT32 dt; FrameDimension frameDimension; UINT32 bitWidth; StreamType type; };

struct HDR3ExposureTypeInfo
{
    UINT32 HDR3ExposureTypeCount;
    UINT32 HDR3ExposureTypeID;
    UINT32 HDR3ExposureType;
};

struct NoiseCoefficent
{
    DOUBLE gradient_S;
    DOUBLE offset_S;
    DOUBLE gradient_O;
    DOUBLE offset_O;
};

struct ExposureContorlInformation
{
    DOUBLE maxAnalogGain;
    DOUBLE maxDigitalGain;
    UINT32 minAnalogGainExists;
    UINT32 minAnalogGainID;
    DOUBLE minAnalogGain;
    UINT32 verticalOffset;
    UINT32 multiCamLineDeltaExists;
    UINT32 multiCamLineDeltaID;
    INT32  multiCamLineDelta;
    UINT32 maxLineCount;
    UINT32 minLineCountExists;
    UINT32 minLineCountID;
    UINT32 minLineCount;
    DOUBLE realToRegDigitalGainConversionFactor;
    CHAR   realToRegGain[256];
    CHAR   regToRealGain[256];
};

struct PixelArrayInfo
{
    UINT32 dummyLines;
    UINT32 activeDimension_width;
    UINT32 activeDimension_height;
    UINT32 activeStartX;
    UINT32 activeStartY;
};

struct DelayInfo
{
    UINT32 maxPipelineDelay;
    UINT32 exposureDelay;
    UINT32 gainDelay;
};

struct StreamInformation
{
    UINT32              streamConfigurationCount;
    UINT32              streamConfigurationID;
    StreamConfiguration streamConfiguration[16];
};

struct ResolutionData
{
    StreamInformation              streamInfo;
    UINT32                         lineLengthPixelClock;
    UINT32                         frameLengthLines;
    UINT32                         minHorizontalBlanking;
    UINT32                         minVerticalBlanking;
    UINT32                         outputPixelClock;
    UINT32                         horizontalBinning;
    UINT32                         verticalBinning;
    DOUBLE                         frameRate;
    UINT32                         laneCount;
    UINT32                         settleTimeNs;
    UINT32                         is3Phase;
    HDR3ExposureTypeInfo           HDR3ExposureInfo;
    UINT32                         RemosaicTypeInfoExists;
    UINT32                         RemosaicTypeInfo;
    UINT32                         capabilityCount;
    UINT32                         capabilityID;
    SensorCapability*              capability;
    ColorFilterArrangement         colorFilterArrangement;
    ZZHDRFirstExposurePattern      ZZHDRFirstExposure;
    FrameDimension                 cropInfo;
};

struct ResolutionInformation
{
    UINT32          sensorVersionExists;
    UINT32          sensorVersionID;
    UINT32          sensorVersion;
    UINT32          resolutionDataCount;
    UINT32          resolutionDataID;
    ResolutionData* resolutionData;
};

typedef UINT32 RegisterData;

struct SensorRegSetting
{
    UINT32        registerAddr;
    UINT32        registerDataCount;
    UINT32        registerDataID;
    RegisterData* registerData;
    UINT32        regAddrType;
    UINT32        regDataType;
    UINT32        operation;
    UINT32        delayUs;
};

struct SensorRegSettings
{
    UINT32           regSettingCount;
    UINT32           regSettingID;
    SensorRegSetting* regSetting;
};

struct SensorSlaveInfo
{
    CHAR   sensorName[256];
    UINT32 slaveAddress;
    UINT32 i2cFrequencyMode;
};

struct SensorProperty
{
    UINT32 sensingMethod;
    FLOAT  cropFactor;
    UINT32 pixelSize;
};

struct RegAddrInfo
{
    UINT32 frameLengthLines;
    UINT32 coarseIntgTimeAddr;
    UINT32 shortCoarseIntgTimeAddr;
    UINT32 globalGainAddr;
    UINT32 shortGlobalGainAddr;
    UINT32 digitalGlobalGainAddr;
    UINT32 digitalGainBlueAddr;
    UINT32 digitalGainGreenBlueAddr;
    UINT32 digitalGainGreenRedAddr;
    UINT32 digitalGainRedAddr;
};

struct SensorInitSettings
{
    UINT32          sensorVersionExists;
    UINT32          sensorVersionID;
    UINT32          sensorVersion;
    SensorRegSettings initSetting;
};

struct SensorDriverData
{
    SensorSlaveInfo               slaveInfo;
    ExposureContorlInformation    exposureControlInfo;
    SensorProperty                sensorProperty;
    UINT32                        initSettingsCount;
    UINT32                        initSettingsID;
    SensorInitSettings*           initSettings;
    UINT32                        resolutionInfoCount;
    UINT32                        resolutionInfoID;
    ResolutionInformation*        resolutionInfo;
    SensorRegSettings             groupHoldOnSettings;
    SensorRegSettings             groupHoldOffSettings;
    RegAddrInfo                   regAddrInfo;
    PixelArrayInfo                pixelArrayInfo;
    DelayInfo                     delayInfo;
    NoiseCoefficent               noiseCoefficient;
};

#endif
