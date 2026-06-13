// Minimal stub for tag_info — provides type lookup for standard Android camera metadata tags.
// In the real Android platform, this is generated from camera_metadata_tag_info.mako template.

#include <stdint.h>
#include <system/camera_metadata.h>

// Section bounds: [section][0] = start_index, [section][1] = end_index+1
// These are minimal — only covering tags actually used by nativechitest
const uint32_t camera_metadata_section_bounds[ANDROID_SECTION_COUNT][2] = {
    {0, 3},     // 0: COLOR_CORRECTION
    {0, 9},     // 1: CONTROL
    {0, 0},     // 2: DEMOSAIC
    {0, 0},     // 3: EDGE
    {0, 0},     // 4: FLASH
    {0, 0},     // 5: FLASH_INFO
    {0, 0},     // 6: HOT_PIXEL
    {0, 6},     // 7: JPEG
    {0, 0},     // 8: LENS
    {0, 0},     // 9: LENS_INFO
    {0, 0},     // 10: NOISE_REDUCTION
    {0, 0},     // 11: QUIRKS
    {0, 1},     // 12: REQUEST
    {0, 11},    // 13: SCALER
    {0, 3},     // 14: SENSOR
    {0, 2},     // 15: SENSOR_INFO
    {0, 0},     // 16: SHADING
    {0, 1},     // 17: STATISTICS
    {0, 0},     // 18: STATISTICS_INFO
    {0, 0},     // 19: TONEMAP
    {0, 0},     // 20: LED
    {0, 0},     // 21: INFO
    {0, 0},     // 22: BLACK_LEVEL
    {0, 0},     // 23: SYNC
    {0, 0},     // 24: REPROCESS
    {0, 0},     // 25: DEPTH
    {0, 0},     // 26: LOGICAL_MULTI_CAMERA
    {0, 0},     // 27: DISTORTION_CORRECTION
    {0, 0},     // 28: HEIC
};

// Tag type info for known sections
static const uint8_t color_correction_tags[][1] = {
    {TYPE_RATIONAL},  // TRANSFORM (0x00)
    {TYPE_RATIONAL},  // GAINS (0x01)
    {TYPE_INT32},     // MODE (0x02)
};

static const uint8_t control_tags[][1] = {
    {TYPE_INT32},  // AE_TARGET_FPS_RANGE (0x00)
    {TYPE_INT32},  // AE_ANTIBANDING_MODE (0x01)
    {TYPE_BYTE},   // AE_STATE (0x02)
    {TYPE_BYTE},   // AF_STATE (0x03)
    {TYPE_BYTE},   // AWB_STATE (0x04)
    {TYPE_BYTE},   // VIDEO_STABILIZATION_MODE (0x05)
    {TYPE_INT32},  // SCENE_MODE (0x06)
    {TYPE_BYTE},   // EFFECT_MODE (0x07)
    {TYPE_BYTE},   // MODE (0x08)
};

static const uint8_t jpeg_tags[][1] = {
    {TYPE_DOUBLE},    // GPS_COORDINATES (0x00)
    {TYPE_BYTE},      // GPS_PROCESSING_METHOD (0x01)
    {TYPE_INT64},     // GPS_TIMESTAMP (0x02)
    {TYPE_INT32},     // ORIENTATION (0x03)
    {TYPE_BYTE},      // QUALITY (0x04)
    {TYPE_INT32},     // THUMBNAIL_QUALITY (0x05)
};

static const uint8_t request_tags[][1] = {
    {TYPE_BYTE},  // AVAILABLE_CAPABILITIES (0x00)
};

static const uint8_t scaler_tags[][1] = {
    // 0x00-0x0A: various scaler tags
    {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32},
    {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32}, {TYPE_INT32},
    {TYPE_INT32},  // STREAM_CONFIGURATIONS (0x0A)
};

static const uint8_t sensor_tags[][1] = {
    {TYPE_INT64},  // EXPOSURE_TIME (0x00)
    {TYPE_INT64},  // TIMESTAMP (0x01)
    {TYPE_INT32},  // SENSITIVITY (0x02)
};

static const uint8_t sensor_info_tags[][1] = {
    {TYPE_INT32},  // ACTIVE_ARRAY_SIZE (0x00)
    {TYPE_INT32},  // PIXEL_ARRAY_SIZE (0x01)
};

static const uint8_t statistics_tags[][1] = {
    {TYPE_BYTE},  // FACE_DETECT_MODE (0x00)
};

const uint8_t* tag_info[ANDROID_SECTION_COUNT] = {
    &color_correction_tags[0][0],
    &control_tags[0][0],
    nullptr, nullptr, nullptr, nullptr, nullptr,
    &jpeg_tags[0][0],
    nullptr, nullptr, nullptr, nullptr,
    &request_tags[0][0],
    &scaler_tags[0][0],
    &sensor_tags[0][0],
    &sensor_info_tags[0][0],
    nullptr,
    &statistics_tags[0][0],
};
