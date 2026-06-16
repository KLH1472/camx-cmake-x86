# Stub camera.qcom.so - provides ChiEntry + HMI + all ChiOps implementations

set(CAMX_API_DIR "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1/chi-cdk/api/common")
set(STUBS_DIR "${CMAKE_SOURCE_DIR}/stubs")
set(METADATA_PORT_DIR "${CMAKE_SOURCE_DIR}/nativechitest")

add_library(camera_qcom SHARED
    chi_stub.cpp
    ${METADATA_PORT_DIR}/camera_metadata_port.cpp
    ${METADATA_PORT_DIR}/camera_metadata_tag_info.cpp
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
