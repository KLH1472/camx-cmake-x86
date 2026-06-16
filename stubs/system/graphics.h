#ifndef _STUB_SYSTEM_GRAPHICS_H
#define _STUB_SYSTEM_GRAPHICS_H

#include <stdint.h>

// Minimal pixel format definitions used by nativechitest
#define HAL_PIXEL_FORMAT_RGBA_8888         1
#define HAL_PIXEL_FORMAT_RGBX_8888         2
#define HAL_PIXEL_FORMAT_RGB_888           3
#define HAL_PIXEL_FORMAT_RGB_565           4
#define HAL_PIXEL_FORMAT_BGRA_8888         5
#define HAL_PIXEL_FORMAT_YCrCb_420_SP      0x11
#define HAL_PIXEL_FORMAT_YCbCr_420_888     0x23
#define HAL_PIXEL_FORMAT_YCbCr_422_SP       0x10
#define HAL_PIXEL_FORMAT_YCrCb_422_SP      0x12
#define HAL_PIXEL_FORMAT_YCbCr_420_888     0x23
#define HAL_PIXEL_FORMAT_YCbCr_422_888     0x27
#define HAL_PIXEL_FORMAT_BLOB              0x21
#define HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED 0x22
#define HAL_PIXEL_FORMAT_RAW10             0x25
#define HAL_PIXEL_FORMAT_RAW12             0x26
#define HAL_PIXEL_FORMAT_RAW16             0x20
#define HAL_PIXEL_FORMAT_RAW_OPAQUE        0x24
#define HAL_PIXEL_FORMAT_Y8                0x20203859
#define HAL_PIXEL_FORMAT_Y16               0x20363159
#define HAL_PIXEL_FORMAT_YV12              0x32315659

// Android dataspace
#define HAL_DATASPACE_UNKNOWN             0
#define HAL_DATASPACE_ARBITRARY           0
#define HAL_DATASPACE_STANDARD_SHIFT      16
#define HAL_DATASPACE_STANDARD_BT709      (1 << 16 | 1)
#define HAL_DATASPACE_STANDARD_BT601_625  (1 << 16 | 2)
#define HAL_DATASPACE_STANDARD_BT601_525  (1 << 16 | 3)
#define HAL_DATASPACE_V0_JFIF             (2 << 16 | 1)
#define HAL_DATASPACE_V0_BT601_625        (2 << 16 | 2)
#define HAL_DATASPACE_V0_BT601_525        (2 << 16 | 3)
#define HAL_DATASPACE_JFIF                HAL_DATASPACE_V0_JFIF
#define HAL_DATASPACE_DEPTH               (4096 << 16 | 0)
#define HAL_DATASPACE_UNSPECIFIED         0

typedef int32_t android_pixel_format_t;
typedef int32_t android_dataspace_t;

#endif // _STUB_SYSTEM_GRAPHICS_H
