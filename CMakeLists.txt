cmake_minimum_required(VERSION 3.14)
project(SageEngine VERSION 0.1.0 LANGUAGES CXX)

#build type
if(NOT CMAKE_BUILD_TYPE)
    message(
        STATUS "Build type set to 'Debug' since none was specified."
    )
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(Sage)
add_subdirectory(SandboxApp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SandboxApp)