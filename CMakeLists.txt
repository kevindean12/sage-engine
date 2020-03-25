cmake_minimum_required(VERSION 3.14)
project(SageEngine VERSION 0.1.0 LANGUAGES CXX)

#build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(
        STATUS "Build type set to 'RelWithDebInfo' since none was specified."
    )
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(Sage)
add_subdirectory(SandboxApp)