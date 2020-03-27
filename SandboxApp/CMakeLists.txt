cmake_minimum_required(VERSION 3.14)

project(SandboxApp VERSION 0.1.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(SandboxApp src/SandboxApp.cpp)

target_compile_definitions(SandboxApp PRIVATE SAGE_PLATFORM_WINDOWS)

target_link_libraries(SandboxApp Sage)

set_target_properties(SandboxApp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}/${PROJECT_NAME})
