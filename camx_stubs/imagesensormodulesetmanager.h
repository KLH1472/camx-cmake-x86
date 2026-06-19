#ifndef STUB_IMAGESENSORMODULESETMANAGER_H
#define STUB_IMAGESENSORMODULESETMANAGER_H
#include "camxtypes.h"

CAMX_NAMESPACE_BEGIN

struct CSIInformation
{
    UINT32 laneAssignExists;
    UINT32 laneAssignID;
    UINT16 laneAssign;
    UINT32 isComboModeExists;
    UINT32 isComboModeID;
    UINT8  isComboMode;
};

struct LensInformation
{
    DOUBLE focalLength;
    DOUBLE fNumber;
    DOUBLE minFocusDistance;
    DOUBLE maxFocusDistance;
    DOUBLE horizontalViewAngle;
    DOUBLE verticalViewAngle;
    DOUBLE maxRollDegree;
    DOUBLE maxPitchDegree;
    DOUBLE maxYawDegree;
};

struct CameraModuleData
{
    CSIInformation  CSIInfo;
    LensInformation lensInfo;
};

CAMX_NAMESPACE_END

class ImageSensorModuleSetManager
{
public:
    static ImageSensorModuleSetManager* Create() { return NULL; }
    VOID Destroy() {}
};

#endif
