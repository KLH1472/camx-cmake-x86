# Build chifeature2test executable

# ── Paths to original CAMX source tree ──
set(CAMX_ROOT        "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1")
set(CAMX_API_DIR     "${CAMX_ROOT}/chi-cdk/api/common")
set(CAMX_UTILS_DIR   "${CAMX_ROOT}/chi-cdk/api/utils")
set(CHIUTILS_DIR     "${CAMX_ROOT}/chi-cdk/core/chiutils")
set(CHIFRAMEWORK_DIR "${CAMX_ROOT}/chi-cdk/core/chiframework")
set(CHIUSECASE_DIR   "${CAMX_ROOT}/chi-cdk/core/chiusecase")
set(CHIFEATURE2_DIR  "${CAMX_ROOT}/chi-cdk/core/chifeature2")
set(CHICOMMONLIB_DIR "${CAMX_ROOT}/chi-cdk/core/lib/common")
set(OEM_FEATURE2_DIR "${CAMX_ROOT}/chi-cdk/oem/qcom/feature2")
set(CHITEST_DIR      "${CAMX_ROOT}/chi-cdk/test")
set(CAMX_HAL_DIR     "${CAMX_ROOT}/camx/src/core/hal")
set(CAMX_EXT_SYSTEM  "${CAMX_ROOT}/ext/system")
set(CAMX_EXT_HW      "${CAMX_ROOT}/ext/hardware")
set(CAMX_EXT         "${CAMX_ROOT}/ext")
set(STUBS_DIR        "${CMAKE_SOURCE_DIR}/stubs")

# ── Local test directories ──
set(F2TEST_FRAMEWORK "${CMAKE_CURRENT_SOURCE_DIR}/../nativechitest/nativetestutils")  # reuse buffers, common utils
set(F2TEST_STUBS     "${CMAKE_CURRENT_SOURCE_DIR}/stubs")
set(F2FRAMEWORK_SRC  "${CHITEST_DIR}/chifeature2testframework")
set(F2TEST_SRC       "${CHITEST_DIR}/chifeature2test")

# ── Test framework sources (16 .cpp, matching original Android.mk) ──
# NOTE: chifeature2testbase.cpp and chifeature2testrequestobject.cpp are NOT
# in the original LOCAL_SRC_FILES — they use undefined macros (CHIFEATURE2TEST_TEST_ORDERED,
# CHIFEATURE2TEST_CHECK2) and their 3 ORDERED test cases are excluded from the build.
set(F2FRAMEWORK_SOURCES
    ${F2FRAMEWORK_SRC}/chibufferutils.cpp
    ${F2FRAMEWORK_SRC}/chifeature2log.cpp
    ${F2FRAMEWORK_SRC}/chifeature2test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patched_srcs/chimetadatautil.cpp
    ${F2FRAMEWORK_SRC}/chimodule.cpp
    ${F2FRAMEWORK_SRC}/cmdlineparser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patched_srcs/feature2buffermanager.cpp
    ${F2FRAMEWORK_SRC}/feature2mfxrtest.cpp
    ${F2FRAMEWORK_SRC}/feature2offlinetest.cpp
    ${F2FRAMEWORK_SRC}/feature2realtimetest.cpp
    ${F2FRAMEWORK_SRC}/feature2testcase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patched_srcs/genericbuffermanager.cpp
    ${F2FRAMEWORK_SRC}/metaconfigparser.cpp
    ${F2FRAMEWORK_SRC}/spectraconfigparser.cpp
    ${F2FRAMEWORK_SRC}/streamconfigparser.cpp
    ${F2FRAMEWORK_SRC}/xmlparser.cpp
)

set(F2MAIN_SOURCES
    ${F2TEST_SRC}/chifeature2testmain.cpp
)

# ── Feature2 core sources (from chi-cdk/core/chifeature2/) ──
set(F2CORE_SOURCES
    ${CHIFEATURE2_DIR}/chifeature2base.cpp
    ${CHIFEATURE2_DIR}/chifeature2baserequestflow.cpp
    ${CHIFEATURE2_DIR}/chifeature2featurepool.cpp
    ${CHIFEATURE2_DIR}/chifeature2graph.cpp
    ${CHIFEATURE2_DIR}/chifeature2graphmanager.cpp
    ${CHIFEATURE2_DIR}/chifeature2multistagedescriptor.cpp
    ${CHIFEATURE2_DIR}/chifeature2requestobject.cpp
    ${CHIFEATURE2_DIR}/chifeature2usecaserequestobject.cpp
    ${CHIFEATURE2_DIR}/chifeature2wrapper.cpp
    ${CHIFEATURE2_DIR}/chitargetbuffermanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/patched_srcs/chithreadmanager.cpp
)

# ── OEM Feature2 sources (used by test)
# chifeature2generic.cpp was previously #included by chifeature2testbase.cpp;
# now compiled directly since chifeature2testbase.cpp is removed from the build.
set(OEM_F2_SOURCES
    ${OEM_FEATURE2_DIR}/chifeature2generic/chifeature2generic.cpp
    ${OEM_FEATURE2_DIR}/chifeature2rt/chifeature2realtime.cpp
    ${OEM_FEATURE2_DIR}/chifeature2mfsr/chifeature2hwmultiframe.cpp
    ${OEM_FEATURE2_DIR}/chifeature2graphselector/chifeature2bayer2yuvdescriptor.cpp
)

# ── Stubs ──
set(F2STUB_SOURCES
    ${F2TEST_STUBS}/xmllib_stub.cpp
    ${F2TEST_STUBS}/chiframework_stubs.cpp
)

# ── Real CHI framework sources (needed for vtable emission, etc.) ──
set(CHIFRAMEWORK_REAL_SOURCES
    ${CHIFRAMEWORK_DIR}/chxfeature.cpp
)

# ── Reuse from nativechitest ──
set(NT_UTILS_DIR "${CMAKE_SOURCE_DIR}/nativechitest")
set(F2_COMPAT_SOURCES
    ${NT_UTILS_DIR}/string_compat.cpp
    ${NT_UTILS_DIR}/camera_metadata_port.cpp
    ${NT_UTILS_DIR}/camera_metadata_tag_info.cpp
    ${NT_UTILS_DIR}/chiutils/log_compat.cpp
    ${NT_UTILS_DIR}/chiutils/chxmetadata.cpp
    ${STUBS_DIR}/utils/RefBase.cpp
)

add_executable(chifeature2test
    ${F2FRAMEWORK_SOURCES}
    ${F2MAIN_SOURCES}
    ${F2CORE_SOURCES}
    ${OEM_F2_SOURCES}
    ${F2STUB_SOURCES}
    ${F2_COMPAT_SOURCES}
)

# ── Compile definitions ──
target_compile_definitions(chifeature2test PRIVATE
    _LINUX
    OS_LINUX
    OS_ANDROID
    ANDROID
    CAMX_ANDROID_API=28
    strlcpy=g_strlcpy
    strlcat=g_strlcat
    FEATURE_XMLLIB
    INVALID_INDEX=0xFFFFFFFF
    "CAMX_TEST_INPUT_PATH=\"./testdata/\""
    "CAMX_TEST_OUTPUT_PATH=\"./testdata/output/\""
)

# ── Force-include our types header to ensure camera metadata types are
#    available before chxutils.h is parsed
target_compile_options(chifeature2test PRIVATE
    -include ${CMAKE_CURRENT_SOURCE_DIR}/stubs/chiframework_types.h
)

# ── Include paths: stubs BEFORE real dirs so they override ──
target_include_directories(chifeature2test PRIVATE
    ${F2TEST_STUBS}                    # xmllib_parser.h, chiframework stubs
    ${F2FRAMEWORK_SRC}                 # chifeature2test.h, etc.
    ${F2TEST_SRC}                      # chifeature2testmain.cpp
    ${CHIFEATURE2_DIR}                 # chifeature2base.h, chifeature2types.h, etc.
    ${CHIFRAMEWORK_DIR}                # chxextensionmodule.h, chxpipeline.h, etc.
    ${CHIUSECASE_DIR}                  # chxusecaseutils.h, etc.
    ${CHIUTILS_DIR}                    # chxutils.h, chxmetadata.h, etc.
    ${CAMX_API_DIR}                    # camxcdktypes.h, chi.h, etc.
    ${CAMX_UTILS_DIR}                  # API utils
    ${CHICOMMONLIB_DIR}                # common lib
    ${OEM_FEATURE2_DIR}                # OEM features (multiple subdirs needed)
    ${OEM_FEATURE2_DIR}/chifeature2generic
    ${OEM_FEATURE2_DIR}/chifeature2rt
    ${OEM_FEATURE2_DIR}/chifeature2mfsr
    ${OEM_FEATURE2_DIR}/chifeature2hdr
    ${OEM_FEATURE2_DIR}/chifeature2anchorsync
    ${OEM_FEATURE2_DIR}/chifeature2demux
    ${OEM_FEATURE2_DIR}/chifeature2fusion
    ${OEM_FEATURE2_DIR}/chifeature2graphselector
    ${OEM_FEATURE2_DIR}/chifeature2qcfa
    ${OEM_FEATURE2_DIR}/chifeature2rawhdr
    ${OEM_FEATURE2_DIR}/chifeature2serializer
    ${OEM_FEATURE2_DIR}/chifeature2swmf
    ${OEM_FEATURE2_DIR}/chifeature2memcpy
    ${OEM_FEATURE2_DIR}/chifeature2frameselect
    ${CAMX_ROOT}/chi-cdk/api/stats       # chistatspropertydefines.h
    ${CAMX_ROOT}/chi-cdk/api/isp         # chiispstatsdefs.h
    ${CAMX_ROOT}/chi-cdk/api/pdlib       # chipdlibcommon.h
    ${OEM_FEATURE2_DIR}/chifeature2stub
    ${CAMX_HAL_DIR}                    # camx hal headers
    ${CAMX_ROOT}/camx/src/utils         # camxtypes.h etc.
    ${CAMX_ROOT}/chi-cdk/api/common      # chi.h, camxcdktypes.h
    ${CAMX_ROOT}/chi-cdk/api/utils       # chxdebugprint.h, cdkutils.h
    ${CAMX_ROOT}/chi-cdk/api/stats       # chistatspropertydefines.h
    ${CAMX_ROOT}/chi-cdk/api/isp         # chiispstatsdefs.h
    ${CAMX_ROOT}/chi-cdk/api/pdlib       # chipdlibcommon.h
    ${CAMX_ROOT}/chi-cdk/api/fd          # fd headers
    ${CAMX_ROOT}/chi-cdk/api/node        # node headers
    ${CAMX_ROOT}/chi-cdk/api/generated   # generated headers
    ${CAMX_ROOT}/chi-cdk/api/sensor      # sensor headers
    ${CAMX_EXT_SYSTEM}                 # ext/system headers
    ${CAMX_EXT_HW}                     # ext/hardware headers
    ${CAMX_EXT}                        # ext headers
    ${STUBS_DIR}                       # Android system stubs (log.h, etc.)
    ${STUBS_DIR}/system                # camera_metadata.h, etc.
    ${STUBS_DIR}/hardware              # camera_common.h, camera3.h
    ${STUBS_DIR}/cutils                # native_handle.h
    ${STUBS_DIR}/sync                  # sync.h
    ${STUBS_DIR}/ui                    # GraphicBuffer.h
    ${STUBS_DIR}/utils                 # StrongPointer.h
    ${F2TEST_FRAMEWORK}                # buffermanager.h, commonutilslinux.cpp
    ${NT_UTILS_DIR}/chiutils           # chxutils stub headers
    ${NT_UTILS_DIR}                    # camera_metadata_tag_info.cpp compat
)

# ── Link libraries ──
target_link_libraries(chifeature2test PRIVATE
    pthread
    dl
    rt
)

# Allow multiple definitions (OEM feature .cpp files share common globals)
target_link_options(chifeature2test PRIVATE
    -Wl,--allow-multiple-definition
)

# ── Export symbols for dlopen camera.qcom.so ──
set_target_properties(chifeature2test PROPERTIES
    ENABLE_EXPORTS ON
)
