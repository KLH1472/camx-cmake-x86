# Build nativechitest executable

set(CAMX_API_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/api/common")
set(CAMX_UTILS_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/api/utils")
set(CHIUTILS_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/core/chiutils")
set(CHIFRAMEWORK_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/core/chiframework")
set(CHIUSECASE_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/core/chiusecase")
set(CHICOMMONLIB_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/core/lib/common")
set(CAMX_UTILS_DIR2 "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/camx/src/utils")
set(STUBS_DIR "${CMAKE_SOURCE_DIR}/stubs")
set(NATIVETEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/nativechitest")
set(UTILS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/nativetestutils")
set(CHIUTILS_LOCAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/chiutils")

# Main test sources (from nativechitest/)
set(NATIVETEST_SOURCES
    ${NATIVETEST_DIR}/binary_comp_test.cpp
    ${NATIVETEST_DIR}/camera_manager_test.cpp
    ${NATIVETEST_DIR}/camera_module_test.cpp
    ${NATIVETEST_DIR}/chibuffermanager.cpp
    ${NATIVETEST_DIR}/chimetadata_test.cpp
    ${NATIVETEST_DIR}/chimetadatautil.cpp
    ${NATIVETEST_DIR}/chimodule.cpp
    ${NATIVETEST_DIR}/chipipeline.cpp
    ${NATIVETEST_DIR}/chipipelineutils.cpp
    ${NATIVETEST_DIR}/chisession.cpp
    ${NATIVETEST_DIR}/chitestcase.cpp
    ${NATIVETEST_DIR}/chitests.cpp
    ${NATIVETEST_DIR}/custom_node_test.cpp
    ${NATIVETEST_DIR}/flush_test.cpp
    ${NATIVETEST_DIR}/mixed_pipeline_test.cpp
    ${NATIVETEST_DIR}/offline_pipeline_test.cpp
    ${NATIVETEST_DIR}/pip_camera_test.cpp
    ${NATIVETEST_DIR}/recipe_test.cpp
    ${NATIVETEST_DIR}/realtime_pipeline_test.cpp
)

# nativetestutils sources
set(NATIVEUTILS_SOURCES
    ${UTILS_DIR}/buffermanager.cpp
    ${UTILS_DIR}/camera3metadata.cpp
    ${UTILS_DIR}/camera3stream.cpp
    ${UTILS_DIR}/cmdlineparser.cpp
    ${UTILS_DIR}/commonutilslinux.cpp
    ${UTILS_DIR}/nativetest.cpp
    ${UTILS_DIR}/nativetestlog.cpp
)

# camera_metadata port (real implementation)
set(METADATA_PORT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/camera_metadata_port.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera_metadata_tag_info.cpp
)

# chiutils sources
set(CHIUTILS_SOURCES
    ${CHIUTILS_LOCAL_DIR}/chxutils.cpp
    ${CHIUTILS_LOCAL_DIR}/chxperf.cpp
    ${CHIUTILS_LOCAL_DIR}/chxmetadata.cpp
    ${CHIUTILS_LOCAL_DIR}/chxblmclient.cpp
    ${CHIUTILS_LOCAL_DIR}/log_compat.cpp
    ${CHIUTILS_LOCAL_DIR}/extension_stub.cpp
)

# Compatibility stubs
set(COMPAT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/string_compat.cpp
)

add_executable(nativechitest
    ${NATIVETEST_SOURCES}
    ${NATIVEUTILS_SOURCES}
    ${CHIUTILS_SOURCES}
    ${COMPAT_SOURCES}
    ${METADATA_PORT_SOURCES}
)

# Compile definitions
target_compile_definitions(nativechitest PRIVATE
    _LINUX
    OS_LINUX
    OS_ANDROID
    ANDROID
    CAMX_ANDROID_API=28
    strlcpy=g_strlcpy
    strlcat=g_strlcat
)

# Include paths
target_include_directories(nativechitest PRIVATE
    ${NATIVETEST_DIR}
    ${UTILS_DIR}
    ${CHIUTILS_LOCAL_DIR}
    ${CAMX_API_DIR}
    ${CAMX_UTILS_DIR}
    ${CHIUTILS_DIR}
    ${CHIFRAMEWORK_DIR}
    ${CHIUSECASE_DIR}
    ${CHICOMMONLIB_DIR}
    ${CAMX_UTILS_DIR2}
    ${STUBS_DIR}
)

# Link libraries
target_link_libraries(nativechitest PRIVATE
    pthread
    dl
    rt
)

# Export symbols so camera.qcom.so (loaded via dlopen) can resolve them
set_target_properties(nativechitest PROPERTIES
    ENABLE_EXPORTS ON
)

# NOTE: The test uses dlopen() to load camera.qcom.so at runtime.
# The test must be run from a directory where it can find the stub shared library.
# e.g.: LD_LIBRARY_PATH=../build/lib ./nativechitest
