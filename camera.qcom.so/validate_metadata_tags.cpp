#include "camxhal3metadatatags.h"
#include "system/camera_metadata.h"

using namespace CamX;

static_assert(ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE    == SensorInfoActiveArraySize,    "tag mismatch");
static_assert(ANDROID_SENSOR_INFO_PIXEL_ARRAY_SIZE     == SensorInfoPixelArraySize,     "tag mismatch");
static_assert(ANDROID_SENSOR_ORIENTATION               == SensorOrientation,            "tag mismatch");
static_assert(ANDROID_COLOR_CORRECTION_TRANSFORM       == ColorCorrectionTransform,     "tag mismatch");
static_assert(ANDROID_CONTROL_AE_TARGET_FPS_RANGE      == ControlAETargetFpsRange,      "tag mismatch");
static_assert(ANDROID_CONTROL_AE_STATE                 == ControlAEState,               "tag mismatch");
static_assert(ANDROID_CONTROL_AF_STATE                 == ControlAFState,               "tag mismatch");
static_assert(ANDROID_CONTROL_AWB_STATE                == ControlAWBState,              "tag mismatch");
static_assert(ANDROID_CONTROL_VIDEO_STABILIZATION_MODE == ControlVideoStabilizationMode,"tag mismatch");
static_assert(ANDROID_CONTROL_SCENE_MODE               == ControlSceneMode,             "tag mismatch");
static_assert(ANDROID_CONTROL_EFFECT_MODE              == ControlEffectMode,            "tag mismatch");
static_assert(ANDROID_CONTROL_MODE                     == ControlMode,                  "tag mismatch");
static_assert(ANDROID_CONTROL_ENABLE_ZSL               == ControlZslEnable,             "tag mismatch");
static_assert(ANDROID_CONTROL_AE_MODE                  == ControlAEMode,                "tag mismatch");
static_assert(ANDROID_FLASH_STATE                      == FlashState,                   "tag mismatch");
static_assert(ANDROID_SENSOR_EXPOSURE_TIME             == SensorExposureTime,           "tag mismatch");
static_assert(ANDROID_SENSOR_TIMESTAMP                 == SensorTimestamp,              "tag mismatch");
static_assert(ANDROID_STATISTICS_FACE_DETECT_MODE      == StatisticsFaceDetectMode,     "tag mismatch");
static_assert(ANDROID_SCALER_AVAILABLE_STREAM_CONFIGURATIONS == ScalerAvailableStreamConfigurations, "tag mismatch");
static_assert(ANDROID_HOT_PIXEL_MODE                   == HotPixelMode,                "tag mismatch");
static_assert(ANDROID_NOISE_REDUCTION_MODE             == NoiseReductionMode,           "tag mismatch");
static_assert(ANDROID_JPEG_GPS_COORDINATES             == JPEGGpsCoordinates,           "tag mismatch");
static_assert(ANDROID_JPEG_GPS_PROCESSING_METHOD       == JPEGGpsProcessingMethod,      "tag mismatch");
static_assert(ANDROID_JPEG_GPS_TIMESTAMP               == JPEGGpsTimestamp,             "tag mismatch");
static_assert(ANDROID_JPEG_ORIENTATION                 == JPEGOrientation,              "tag mismatch");
static_assert(ANDROID_JPEG_QUALITY                     == JPEGQuality,                  "tag mismatch");
static_assert(ANDROID_JPEG_THUMBNAIL_QUALITY           == JPEGThumbnailQuality,         "tag mismatch");
static_assert(ANDROID_JPEG_THUMBNAIL_SIZE              == JPEGThumbnailSize,            "tag mismatch");
static_assert(ANDROID_REQUEST_AVAILABLE_CAPABILITIES   == RequestAvailableCapabilities, "tag mismatch");
static_assert(ANDROID_REQUEST_MAX_NUM_OUTPUT_STREAMS   == RequestMaxNumOutputStreams,    "tag mismatch");
