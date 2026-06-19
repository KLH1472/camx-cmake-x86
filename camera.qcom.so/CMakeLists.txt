# camera.qcom.so — CHI stub + CamX Core object library

set(CAMX_ROOT "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1")
set(CAMX_API_DIR "${CAMX_ROOT}/chi-cdk/api/common")
set(STUBS_DIR "${CMAKE_SOURCE_DIR}/stubs")
set(CAMX_STUBS_DIR "${CMAKE_SOURCE_DIR}/camx_stubs")
set(CAMX_PATCHED_DIR "${CMAKE_SOURCE_DIR}/camx_patched_srcs")
set(METADATA_PORT_DIR "${CMAKE_SOURCE_DIR}/nativechitest")

# ── CamX Core sources (36 files) ──

set(CAMX_UTILS_SOURCES
    ${CAMX_ROOT}/camx/src/utils/camxdebug.cpp
    ${CAMX_ROOT}/camx/src/utils/camxdebugprint.cpp
    ${CAMX_ROOT}/camx/src/utils/camxhashmap.cpp
    ${CAMX_ROOT}/camx/src/utils/camximagedump.cpp
    ${CAMX_ROOT}/camx/src/utils/camxmemspy.cpp
    ${CAMX_ROOT}/camx/src/utils/camxnodeutils.cpp
    ${CAMX_ROOT}/camx/src/utils/camxstabilization.cpp
    ${CAMX_ROOT}/camx/src/utils/camxthreadcore.cpp
    ${CAMX_ROOT}/camx/src/utils/camxthreadjoblist.cpp
    ${CAMX_ROOT}/camx/src/utils/camxthreadjobregistry.cpp
    ${CAMX_ROOT}/camx/src/utils/camxthreadmanager.cpp
    ${CAMX_ROOT}/camx/src/utils/camxthreadqueue.cpp
    ${CAMX_ROOT}/camx/src/utils/camxtrace.cpp
    ${CAMX_ROOT}/camx/src/utils/camxtranslator.cpp
    ${CAMX_ROOT}/camx/src/utils/camxtypes.cpp
    ${CAMX_ROOT}/camx/src/utils/log/camxchiofflinelogger.cpp
    ${CAMX_PATCHED_DIR}/camxatomic.cpp
)

set(CAMX_OSUTILS_SOURCES
    ${CAMX_ROOT}/camx/src/osutils/camxosutilslinuxembedded.cpp
)

set(CAMX_CSL_SOURCES
    ${CAMX_ROOT}/camx/src/csl/camxcsl.cpp
    ${CAMX_ROOT}/camx/src/csl/camxcsljumptable.cpp
    ${CAMX_ROOT}/camx/src/csl/camxcdmdefs.cpp
)

set(CAMX_CHI_SOURCES
    ${CAMX_ROOT}/camx/src/core/chi/camxchisession.cpp
    ${CAMX_ROOT}/camx/src/core/chi/camxchicomponent.cpp
    ${CAMX_ROOT}/camx/src/core/chi/camxchi.cpp
)

set(CAMX_CORE_SOURCES
    ${CAMX_ROOT}/camx/src/core/camxcmdbuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camxcmdbuffermanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxdeferredrequestqueue.cpp
    ${CAMX_ROOT}/camx/src/core/camxhwfactory.cpp
    ${CAMX_ROOT}/camx/src/core/camximagebuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camximagebuffermanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxmempoolgroup.cpp
    ${CAMX_ROOT}/camx/src/core/camxmempoolmgr.cpp
    ${CAMX_ROOT}/camx/src/core/camxmetabuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camxmetadatapool.cpp
    ${CAMX_ROOT}/camx/src/core/camxnode.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacket.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacketbuilder.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacketresource.cpp
    ${CAMX_ROOT}/camx/src/core/camxresourcemanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxsession.cpp
    ${CAMX_ROOT}/camx/src/core/camxstatsparser.cpp
    ${CAMX_ROOT}/camx/src/core/camxtest.cpp
)

# ── CamX Core OBJECT library (separate compile flags from chi_stub) ──

add_library(camx_core OBJECT
    ${CAMX_UTILS_SOURCES}
    ${CAMX_OSUTILS_SOURCES}
    ${CAMX_CSL_SOURCES}
    ${CAMX_CHI_SOURCES}
    ${CAMX_CORE_SOURCES}
)

set_target_properties(camx_core PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_compile_definitions(camx_core PRIVATE
    _LINUX
    OS_LINUX
    OS_ANDROID
    ANDROID
    CAMX_ANDROID_API=28
    __clang__=1
    CAMX_LOGS_ENABLED=1
    strlcpy=g_strlcpy
    strlcat=g_strlcat
)

target_compile_options(camx_core PRIVATE
    -Wno-changes-meaning
    "SHELL:-include ${CAMX_STUBS_DIR}/camxmem.h"
    "SHELL:-include ${CAMX_ROOT}/camx/src/utils/camxincs.h"
    "SHELL:-include sys/time.h"
    -Wno-unused-parameter
    -Wno-missing-field-initializers
)

target_include_directories(camx_core PRIVATE
    ${CAMX_STUBS_DIR}
    ${CAMX_ROOT}/camx/src/utils
    ${CAMX_ROOT}/camx/src/osutils
    ${CAMX_ROOT}/camx/src/csl
    ${CAMX_ROOT}/camx/src/core
    ${CAMX_ROOT}/camx/src/core/hal
    ${CAMX_ROOT}/camx/src/core/halutils
    ${CAMX_ROOT}/camx/src/core/chi
    ${CAMX_ROOT}/camx/src/core/ncs
    ${CAMX_ROOT}/camx/src/core/oem
    ${CAMX_ROOT}/camx/src/hwl/titan17x
    ${CAMX_ROOT}/camx/src/mapperutils/formatmapper
    ${CAMX_ROOT}/camx/src/settings
    ${CAMX_ROOT}/chi-cdk/api/common
    ${CAMX_ROOT}/chi-cdk/api/node
    ${CAMX_ROOT}/chi-cdk/api/stats
    ${CAMX_ROOT}/chi-cdk/api/isp
    ${CAMX_ROOT}/chi-cdk/api/sensor
    ${CAMX_ROOT}/chi-cdk/api/ncs
    ${CAMX_ROOT}/chi-cdk/api/fd
    ${CAMX_ROOT}/chi-cdk/api/utils
    ${CAMX_ROOT}/chi-cdk/api/pdlib
    ${CAMX_ROOT}/chi-cdk/core/chiutils
    ${STUBS_DIR}
    ${STUBS_DIR}/log
)

# ── camera_qcom shared library ──

add_library(camera_qcom SHARED
    chi_stub.cpp
    ${METADATA_PORT_DIR}/camera_metadata_port.cpp
    ${METADATA_PORT_DIR}/camera_metadata_tag_info.cpp
    ${METADATA_PORT_DIR}/string_compat.cpp
)

target_compile_definitions(camera_qcom PRIVATE
    _LINUX
    OS_ANDROID
    ANDROID
    CAMX_ANDROID_API=28
    CDK_VISIBILITY_PUBLIC=__attribute__\(\(visibility\(\"default\"\)\)\)
)

target_include_directories(camera_qcom PRIVATE
    ${CAMX_API_DIR}
    ${STUBS_DIR}
)

target_link_libraries(camera_qcom PRIVATE
    pthread
    dl
)

set_target_properties(camera_qcom PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
