# camera.qcom.so — CHI stub + CamX Core object library

set(CAMX_ROOT "${CMAKE_SOURCE_DIR}/../CAMX_SAIPAN_LA.UM.8.13.R1")
set(CAMX_API_DIR "${CAMX_ROOT}/chi-cdk/api/common")
set(STUBS_DIR "${CMAKE_SOURCE_DIR}/stubs")
set(CAMX_STUBS_DIR "${CMAKE_SOURCE_DIR}/camx_stubs")
set(CAMX_PATCHED_DIR "${CMAKE_SOURCE_DIR}/camx_patched_srcs")
set(CAMX_GENERATED_DIR "${CMAKE_BINARY_DIR}/generated")
set(METADATA_PORT_DIR "${CMAKE_SOURCE_DIR}/nativechitest")
set(TOOLS_DIR "${CMAKE_SOURCE_DIR}/tools")

file(MAKE_DIRECTORY ${CAMX_GENERATED_DIR})
file(MAKE_DIRECTORY ${CAMX_GENERATED_DIR}/g_sensor)
file(MAKE_DIRECTORY ${CAMX_GENERATED_DIR}/g_parser)

# ══════════════════════════════════════════════════════════════════════
# Code generators (props.pl, settingsgenerator.pl, version.pl, ParameterParser)
# ══════════════════════════════════════════════════════════════════════

# --- libxml2 compatibility symlink for ParameterParser ---
find_file(LIBXML2_REAL NAMES libxml2.so.16 libxml2.so.2 libxml2.so
    PATHS /usr/lib/x86_64-linux-gnu /usr/lib64 /usr/lib
    NO_DEFAULT_PATH)
if(NOT LIBXML2_REAL)
    message(WARNING "libxml2.so not found — ParameterParser generation will fail")
    set(LIBXML2_REAL "/usr/lib/x86_64-linux-gnu/libxml2.so.16")
endif()
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/libxml2.so.2
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${LIBXML2_REAL} ${CMAKE_BINARY_DIR}/libxml2.so.2
    COMMENT "Creating libxml2.so.2 compatibility symlink"
)

# --- props.pl → g_camxproperties.h/.cpp ---
add_custom_command(
    OUTPUT ${CAMX_GENERATED_DIR}/g_camxproperties.h
           ${CAMX_GENERATED_DIR}/g_camxproperties.cpp
    COMMAND perl ${TOOLS_DIR}/props.pl
        ${CAMX_ROOT}/camx/src/core/camxproperties.xml
        ${CAMX_GENERATED_DIR}/g_camxproperties
    DEPENDS ${CAMX_ROOT}/camx/src/core/camxproperties.xml
            ${TOOLS_DIR}/props.pl
    COMMENT "Generating g_camxproperties.h/.cpp"
)

# --- version.pl → g_camxversion.h ---
add_custom_command(
    OUTPUT ${CAMX_GENERATED_DIR}/g_camxversion.h
    COMMAND perl ${TOOLS_DIR}/version.pl ${CAMX_GENERATED_DIR}/g_camxversion.h
    DEPENDS ${TOOLS_DIR}/version.pl
    WORKING_DIRECTORY ${CAMX_ROOT}
    COMMENT "Generating g_camxversion.h"
)

# --- settingsgenerator.pl → g_camxsettings.h/.cpp + g_camxtitan17xsettings.h/.cpp ---
# settingsgenerator writes output next to input XMLs; symlink inputs to build dir
add_custom_command(
    OUTPUT ${CAMX_GENERATED_DIR}/g_camxsettings.h
           ${CAMX_GENERATED_DIR}/g_camxsettings.cpp
           ${CAMX_GENERATED_DIR}/g_camxtitan17xsettings.h
           ${CAMX_GENERATED_DIR}/g_camxtitan17xsettings.cpp
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CAMX_ROOT}/camx/src/settings/g_camxsettings.xml
        ${CAMX_GENERATED_DIR}/g_camxsettings.xml
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CAMX_ROOT}/camx/src/hwl/titan17x/camxtitan17xsettings.xml
        ${CAMX_GENERATED_DIR}/camxtitan17xsettings.xml
    COMMAND perl ${TOOLS_DIR}/settingsgenerator/settingsgenerator.pl
        ${CAMX_GENERATED_DIR}/g_camxsettings.xml
        ${CAMX_GENERATED_DIR}/camxtitan17xsettings.xml
        ${CAMX_GENERATED_DIR}/camxoverridesettings.txt
    COMMAND ${CMAKE_COMMAND} -E remove -f
        ${CAMX_GENERATED_DIR}/g_camxsettings.xml
        ${CAMX_GENERATED_DIR}/camxtitan17xsettings.xml
        ${CAMX_GENERATED_DIR}/camxoverridesettings.txt
        ${CAMX_GENERATED_DIR}/camxoverridesettingsprivate.txt
    DEPENDS ${CAMX_ROOT}/camx/src/settings/g_camxsettings.xml
            ${CAMX_ROOT}/camx/src/hwl/titan17x/camxtitan17xsettings.xml
            ${TOOLS_DIR}/settingsgenerator/settingsgenerator.pl
    COMMENT "Generating g_camxsettings + g_camxtitan17xsettings"
)

# --- ParameterParser → sensor XSD C++ code ---
add_custom_command(
    OUTPUT ${CAMX_GENERATED_DIR}/g_sensor/camxsensordriver.h
           ${CAMX_GENERATED_DIR}/g_sensor/imagesensormodulesetmanager.h
    COMMAND ${CMAKE_COMMAND} -E env "LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}"
        ${TOOLS_DIR}/ParameterParser
        ${CAMX_GENERATED_DIR}/g_sensor s
        ${CAMX_ROOT}/chi-cdk/api/sensor/
        -pImageSensorModule -nCamX -l -q
    DEPENDS ${TOOLS_DIR}/ParameterParser
            ${CMAKE_BINARY_DIR}/libxml2.so.2
    COMMENT "Generating sensor XSD C++ code (ParameterParser)"
)

# --- ParameterParser → parser utility code ---
add_custom_command(
    OUTPUT ${CAMX_GENERATED_DIR}/g_parser/parametermodule.h
           ${CAMX_GENERATED_DIR}/g_parser/parametertuningtypes.h
    COMMAND ${CMAKE_COMMAND} -E env "LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}"
        ${TOOLS_DIR}/ParameterParser
        ${CAMX_GENERATED_DIR}/g_parser u
        ${CAMX_ROOT}/chi-cdk/api/chromatix/XSD/
        -l -q
    DEPENDS ${TOOLS_DIR}/ParameterParser
            ${CMAKE_BINARY_DIR}/libxml2.so.2
    COMMENT "Generating parser utility C++ code (ParameterParser)"
)

add_custom_target(generate_headers DEPENDS
    ${CAMX_GENERATED_DIR}/g_camxproperties.h
    ${CAMX_GENERATED_DIR}/g_camxversion.h
    ${CAMX_GENERATED_DIR}/g_camxsettings.h
    ${CAMX_GENERATED_DIR}/g_sensor/camxsensordriver.h
    ${CAMX_GENERATED_DIR}/g_parser/parametermodule.h
)

# ══════════════════════════════════════════════════════════════════════
# CamX Core sources (52 files)
# ══════════════════════════════════════════════════════════════════════

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
    ${CAMX_ROOT}/camx/src/core/chi/camxchicontext.cpp
)

set(CAMX_CORE_SOURCES
    ${CAMX_ROOT}/camx/src/core/camxcmdbuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camxcmdbuffermanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxdeferredrequestqueue.cpp
    ${CAMX_ROOT}/camx/src/core/camxhwcontext.cpp
    ${CAMX_ROOT}/camx/src/core/camxhwenvironment.cpp
    ${CAMX_ROOT}/camx/src/core/camxhwfactory.cpp
    ${CAMX_ROOT}/camx/src/core/camximagebuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camximagebuffermanager.cpp
    ${CAMX_ROOT}/camx/src/core/camximagesensormoduledatamanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxmempoolgroup.cpp
    ${CAMX_ROOT}/camx/src/core/camxmempoolmgr.cpp
    ${CAMX_ROOT}/camx/src/core/camxmetabuffer.cpp
    ${CAMX_ROOT}/camx/src/core/camxmetadatapool.cpp
    ${CAMX_ROOT}/camx/src/core/camxnode.cpp
    ${CAMX_ROOT}/camx/src/core/camxoverridesettingsfile.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacket.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacketbuilder.cpp
    ${CAMX_ROOT}/camx/src/core/camxpacketresource.cpp
    ${CAMX_ROOT}/camx/src/core/camxpipeline.cpp
    ${CAMX_ROOT}/camx/src/core/camxresourcemanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxsession.cpp
    ${CAMX_ROOT}/camx/src/core/camxsettingsmanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxstatsparser.cpp
    ${CAMX_ROOT}/camx/src/core/camxtest.cpp
    ${CAMX_ROOT}/camx/src/core/camxtuningdatamanager.cpp
    ${CAMX_ROOT}/camx/src/core/camxvendortags.cpp
    ${CAMX_ROOT}/camx/src/core/camxerrorinducer.cpp
)

# ── CamX Core OBJECT library ──

add_library(camx_core OBJECT
    ${CAMX_UTILS_SOURCES}
    ${CAMX_OSUTILS_SOURCES}
    ${CAMX_CSL_SOURCES}
    ${CAMX_CHI_SOURCES}
    ${CAMX_CORE_SOURCES}
)

add_dependencies(camx_core generate_headers)

set_target_properties(camx_core PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_compile_definitions(camx_core PRIVATE
    _LINUX
    OS_LINUX
    OS_ANDROID
    ANDROID
    CAMX
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
    ${CAMX_GENERATED_DIR}
    ${CAMX_GENERATED_DIR}/g_sensor
    ${CAMX_GENERATED_DIR}/g_parser
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
