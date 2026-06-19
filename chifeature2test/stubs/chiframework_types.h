#ifndef CHIFRAMEWORK_TYPES_H
#define CHIFRAMEWORK_TYPES_H

// ==========================================================================
// Include real CHI types (chi.h provides all CHI enums/structs/typedefs)
// ==========================================================================
#include "camxcdktypes.h"
#include "chi.h"
#include "chicommon.h"
#include "camxtypes.h"
#include <cutils/native_handle.h>
#include <sys/time.h>
#include <cstring>
#include <climits>
#include <algorithm>

// Android trace stubs
#define ATRACE_ASYNC_BEGIN(name, cookie) ((void)0)
#define ATRACE_ASYNC_END(name, cookie)   ((void)0)
#define ATRACE_INT(name, value)          ((void)0)

// WAIT_BUFFER_TIMEOUT
#ifndef WAIT_BUFFER_TIMEOUT
#define WAIT_BUFFER_TIMEOUT 700
#endif

// CamxResult type alias (same as CDKResult)
typedef CDKResult CamxResult;

// OS types (from camxosutils.h)
typedef VOID* (*OSThreadFunc)(VOID* pArg);
typedef pthread_t OSThreadHandle;
typedef VOID* OSLIBRARYHANDLE;
typedef pthread_mutex_t OSMutexHandle;

// ── Include camera_metadata.h and camera3.h stubs ──
#include <system/camera_metadata.h>
#include <hardware/camera3.h>
#include <system/graphics.h>

// Defined here because chxmetadata.h (included below) needs these
#ifndef CHX_INLINE
#define CHX_INLINE __inline
#endif
#ifndef BYTE
typedef uint8_t BYTE;
#endif
#ifndef CHX_ASSERT
#define CHX_ASSERT(expr) ((void)0)
#endif

// Dump debug data types (needed early by chxextensionmodule.h)
enum EnableDumpDebugDataType {
    DumpDebugDataNone          = 0,
    DumpDebugDataPerSnapshot   = 1,
    DumpDebugDataPerVideoFrame = 2,
    DumpDebugDataAllFrames     = 3,
};

// Misc forward declarations needed by chxmetadata.h / chxextensionmodule.h
struct LogicalCameraInfo;
struct StreamMap;

#include "chxmetadata.h"

// ── Forward declarations for types not in camera3.h ──
struct camera3_stream_buffer;
struct camera_info;

// ── Misc forward declarations ──
struct ChiUsecase;

// ── CHX_ARRAY_SIZE macro ──
#ifndef CHX_ARRAY_SIZE
#define CHX_ARRAY_SIZE(array) (sizeof((array)) / sizeof((array)[0]))
#endif

// ── CAMX/CDK macros (normally from camxdefs.h) ──
#ifndef CAMX_NAMESPACE_BEGIN
#define CAMX_NAMESPACE_BEGIN namespace CamX {
#endif
#ifndef CAMX_NAMESPACE_END
#define CAMX_NAMESPACE_END }
#endif
#ifndef CAMX_VISIBILITY_PUBLIC
#define CAMX_VISIBILITY_PUBLIC __attribute__ ((visibility ("default")))
#endif
#ifndef CAMX_INLINE
#define CAMX_INLINE __inline
#endif
#ifndef CDK_VISIBILITY_PUBLIC
#define CDK_VISIBILITY_PUBLIC __attribute__ ((visibility ("default")))
#endif
#ifndef CDK_VISIBILITY_LOCAL
#define CDK_VISIBILITY_LOCAL  __attribute__ ((visibility ("hidden")))
#endif
#ifndef CAMX_PACKED
#define CAMX_PACKED __attribute__((__packed__))
#endif
#ifndef CAMX_BEGIN_PACKED
#define CAMX_BEGIN_PACKED
#endif
#ifndef CAMX_END_PACKED
#define CAMX_END_PACKED
#endif
#ifndef CAMX_UNREFERENCED_PARAM
#define CAMX_UNREFERENCED_PARAM(param) (void)param
#endif
#ifndef CHX_STATIC_ASSERT
#define CHX_STATIC_ASSERT(condition) static_assert(condition, #condition)
#endif

// Enums and constants from chxdefs.h — define here (guarded) since
// chxdefs.h may not be included yet when our stub headers need them.
// The real chxdefs.h will be skipped due to CHXDEFS_H guard.
// ==========================================================================
#ifndef CHXDEFS_H
enum class UsecaseId {
    NoMatch = 0, Default = 1, Preview = 2, PreviewZSL = 3,
    MFNR = 4, MFSR = 5, MultiCamera = 6, QuadCFA = 7,
    RawJPEG = 8, MultiCameraVR = 9, Torch = 10,
    YUVInBlobOut = 11, VideoLiveShot = 12, SuperSlowMotionFRC = 13,
    MaxUsecases = 14,
};
enum class VendorTag {
    SensorBpsModeIndex = 0, SensorBpsGain = 1, DebugDataTag = 2,
    SensorModeIndex = 3, CropRegions = 4, TuningMode = 5,
    RefCropSize = 6, MultiCamera = 7,
    IPEOverrideScale = 8, GPUOverrideRotation = 9,
    ZSLTimestampRange = 10, DebugDumpConfig = 11,
    VideoHDR10Mode = 12,
    LivePreview = 13,
};
enum class PartialResultCount {
    NoPartialResult = 0, FirstPartialResult = 1,
    SecondPartialResult = 2, ThirdPartialResult = 3,
};
enum class MetaDataResultCount {
    NoMetaDataCount = 0, OneMetaDataCount = 1,
    TwoMetaDataCount = 2, ThreeMetaDataCount = 3,
};
enum class PartialResultSender {
    DriverPartialData = 0, CHIPartialData = 1, DriverMetaData = 2,
};
enum class PartialMetaSupport : UINT32 {
    NoSupport = 0, SeperatePartialMeta = 1, CombinedPartialMeta = 2,
};
// Static const values from chxdefs.h (must match real values)
static const UINT   MaxChiStreams                  = 16;
static const UINT32 MaxOutstandingRequests         = 128;
static const UINT32 MaxPendingFrameNumber          = 200;
static const INT64  InvalidFrameNumber             = 0x7FFFFFFFFFFFFFFF;
static const UINT32 InvalidIndex                   = 0xFFFFFFFF;
static const UINT32 INVALIDSEQUENCEID              = 0xFFFFFFFF;
static const UINT32 INVALIDFRAMENUMBER             = 0xFFFFFFFF;
static const UINT   tuningUsecasePreviewMask       = 1;
static const UINT   tuningUsecaseVideoMask         = 2;
static const UINT   tuningUsecaseSnapshotMask      = 4;
static const UINT   tuningUsecaseZSLMask           = 8;
static const UINT   CHIImmediateBufferCountDefault = 2;
static const UINT   CHIImmediateBufferCountZSL     = 3;
static const UINT32 UHDResolutionWidth             = 3840;
static const UINT32 UHDResolutionHeight            = 2160;
#endif // !CHXDEFS_H

// Prevent real chxdefs.h from loading (our definitions above suffice)
#ifndef CHXDEFS_H
#define CHXDEFS_H
#endif

// ==========================================================================
// Forward Declarations of CHI Framework Classes
// ==========================================================================
class ExtensionModule;
class MultiCamController;
class MultiCamControllerManager;
class Pipeline;
class Session;
class Usecase;
class UsecaseSelector;
class UsecaseFactory;
class CHIBufferManager;
class ChiMetadata;
class ChiMetadataManager;
class ChxUtils;
class ImageBuffer;
class LightweightDoublyLinkedList;
class Feature;
class PerfLockManager;
class BLMClient;
class CHITargetBufferManager;
class ChiTarget;

// ChiTargetBufferManager and ChiTargetBufferManagerCreateData are
// defined in the real chitargetbuffermanager.h — do NOT define here.

#ifndef MaxDevicePerLogicalCamera
#define MaxDevicePerLogicalCamera 8
#endif

struct Feature2ControllerResult {
    BOOL    isValid;
    BOOL    isSnapshotFusion;
    UINT32  masterCameraId;
    BOOL    activeCameras[MaxDevicePerLogicalCamera];
    UINT32  numActiveCameras;
    UINT32  activeMap;
};
struct ChiTargetPortDescriptor;
struct ChiTargetCreateData;

// ── Minimal ChiMetadataManager (full version in chxmetadata.h) ──
// Defined here only if not already defined by the real chxmetadata.h
#ifndef CHXMETADATA_MANAGER_STUBBED
#define CHXMETADATA_MANAGER_STUBBED
class ChiMetadata;
class ChiMetadataManager;
#endif

// Additional constants used by Feature2 core
#ifndef MaxStringLength64
#define MaxStringLength64 64
#endif
#ifndef MaxStringLength256
#define MaxStringLength256 256
#endif
#ifndef InvalidCameraId
#define InvalidCameraId 0xFFFFFFFF
#endif
#ifndef MaxPipelinesPerSession
#define MaxPipelinesPerSession 16
#endif
#ifndef MaxSessions
#define MaxSessions 32
#endif
#ifndef InvalidSessionId
#define InvalidSessionId 0xFFFFFFFF
#endif
#ifndef MaxNumOfTargets
#define MaxNumOfTargets 97
#endif

// AdvancedPipelineType, FeatureType, SnapshotProcessType, FeatureRequestType,
// FeatureRequestInfo, FeatureRequestInfoForStream are defined in chxfeature.h
// (included normally via chifeature2wrapper.h). Do NOT redefine here.

// CSIDBinningInfo (from chivendortag.h)
enum class CSIDBinningMode { HorizontalBinning = 0, QCFABinning = 1 };
struct CSIDBinningInfo {
    BOOL            isBinningEnabled;
    CSIDBinningMode binningMode;
};

// GeoLibStreamOutput (from chivendortag.h)
struct GeoLibStreamOutput {
    UINT32 dummy[4];
};

// ==========================================================================
// Additional structs (not in chi.h/chicommon.h)
// ==========================================================================
struct LogicalCameraInfo {
    UINT32 cameraId;
    struct {
        UINT32 camera_type;
        INT32  orientation;
    } m_cameraInfo;
    CHICAMERAINFO m_cameraCaps;
    struct ChiSensorModeInfo* pSensorModeInfo;
    UINT32 numPhysicalCameras;
    struct DeviceInfo** ppDeviceInfo;
    const camera3_device_t* m_pCamera3Device;
    int logicalCameraType;
    UINT32 primaryCameraId;
    BOOL publicVisiblity;
    UINT32 numAvailableStreamMap;
    VOID* pAvailableStreamMap;
    UINT32 maxResourceCost;
};

struct DeviceInfo {
    UINT32 cameraId;
    VOID* m_pDeviceCaps;
    VOID* pSensorModeInfo;
    VOID* pDeviceConfig;
};

enum class SnapshotStreamType { UNKNOWN = -1, INVALID = 0, JPEG = 1, HEIC = 2 };

struct SnapshotStreamConfig {
    SnapshotStreamType type;
    CHISTREAM* pSnapshotStream;
    CHISTREAM* pThumbnailStream;
    CHISTREAM* pRawStream;
};

struct Gralloc1Interface {};

struct LightweightDoublyLinkedListNode {
    VOID* pData;
    LightweightDoublyLinkedListNode* pPrev;
    LightweightDoublyLinkedListNode* pNext;
};

struct ChiMetadataBundle {
    CHIMETAHANDLE pInputMetadata;
    CHIMETAHANDLE pOutputMetadata;
    BOOL isInputSticky;
};

union UsecaseRequestFlags {
    struct {
        BIT isMessageAvailable          : 1;
        BIT isMessagePending            : 1;
        BIT isInErrorState              : 1;
        BIT isOutputMetaDataSent        : 1;
        BIT isOutputPartialMetaDataSent : 1;
        BIT isDriverPartialMetaDataSent : 1;
        BIT isMetadataErrorSent         : 1;
        BIT isBufferErrorSent           : 1;
        BIT isZSLMessageAvailable       : 1;
        BIT reserved                    : 23;
    };
    UINT32 value;
};

// ==========================================================================
// Additional enums (not in chi.h/chicommon.h, matching real definitions)
// ==========================================================================
enum SeamlessInSensorState {
    None = 0,
    InSensorHDR3ExpStart = 1,
    InSensorHDR3ExpEnabled = 2,
    InSensorHDR3ExpStop = 3,
};

// ==========================================================================
// Include Feature2 core types needed by test framework
// ==========================================================================
#include "g_pipelines.h"
#include "chitargetbuffermanager.h"

// ==========================================================================
// Logging stub macros (no-ops, guarded)
// ==========================================================================
#ifndef CHX_LOG_ERROR
#define CHX_LOG_ERROR(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_WARN
#define CHX_LOG_WARN(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_INFO
#define CHX_LOG_INFO(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_CONFIG
#define CHX_LOG_CONFIG(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_VERBOSE
#define CHX_LOG_VERBOSE(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG
#define CHX_LOG(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_DEBUG
#define CHX_LOG_DEBUG(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_DUMP
#define CHX_LOG_DUMP(fmt, args...) ((void)0)
#endif
#ifndef CHX_LOG_TO_FILE
#define CHX_LOG_TO_FILE(fd, indent, fmt, ...) ((void)0)
#endif
#ifndef LOG_ERROR
#define LOG_ERROR(group, fmt, args...) ((void)0)
#endif
#ifndef LOG_WARN
#define LOG_WARN(group, fmt, args...) ((void)0)
#endif
#ifndef LOG_VERBOSE
#define LOG_VERBOSE(group, fmt, args...) ((void)0)
#endif
#ifndef LOG_INFO
#define LOG_INFO(group, fmt, args...) ((void)0)
#endif

// DumpFileName struct (used in Feature2 core)
struct DumpFileName {
    CHAR dumpFileName[8][256];
};
struct ChiUsecaseTag {};
extern ChiUsecaseTag g_DefaultUsecase;
// g_pUsecaseZSL is defined in g_pipelines.h as (&Usecases97Target[UsecaseZSLId])
// Do NOT override it here — the real pipeline topology data must be used.
#define GRALLOC1_PRODUCER_USAGE_CAMERA   (1ULL << 17)
#define GRALLOC1_PRODUCER_USAGE_CPU_READ (1ULL << 1)
#define GRALLOC1_PRODUCER_USAGE_CPU_WRITE (1ULL << 5)
#define GRALLOC1_CONSUMER_USAGE_CAMERA   (1ULL << 18)
#define GRALLOC1_CONSUMER_USAGE_CPU_READ (1ULL << 1)
#define GRALLOC1_CONSUMER_USAGE_VIDEO_ENCODER (1ULL << 16)
#define GRALLOC_USAGE_HW_VIDEO_ENCODER   (1U << 16)
#define GRALLOC_USAGE_SW_READ_OFTEN      (1U << 1)
#define HAL_PIXEL_FORMAT_YCbCr_420_888   0x23

// Camera metadata flash mode enum values
#define ANDROID_FLASH_MODE_OFF 0
#define ANDROID_FLASH_MODE 0

#endif // CHIFRAMEWORK_TYPES_H
