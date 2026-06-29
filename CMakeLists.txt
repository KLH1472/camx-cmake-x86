cmake_minimum_required(VERSION 3.10)
project(nativechitest-cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Export compile_commands.json for clangd/IDE tooling (Makefile/Ninja generators)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler flags mimicking Android.mk
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_LINUX -DOS_LINUX -D_GLIBCXX_USE_CXX11_ABI=0")

# Subdirectories
add_subdirectory(camera.qcom.so)
add_subdirectory(nativechitest)
add_subdirectory(chifeature2test)
