cmake_minimum_required(VERSION 3.14)

project(Sage VERSION 0.1.0 LANGUAGES CXX)

add_library(
    Sage SHARED 
    ${CMAKE_CURRENT_LIST_DIR}/include/Sage.hpp 
    ${CMAKE_CURRENT_LIST_DIR}/include/Sage/Application.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SageCore/Application.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/include/Sage/Core.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Sage/EntryPoint.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/Sage/Log.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SageCore/Log.cpp
)

target_compile_definitions(Sage PRIVATE SAGE_BUILD_DLL SAGE_PLATFORM_WINDOWS)

target_include_directories(Sage
    PUBLIC src/SageCore
    PUBLIC vendor/spdlog/include
    PUBLIC include
    PUBLIC include/Sage
)

set_target_properties(Sage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}/${PROJECT_NAME})
get_target_property(SAGE_BIN Sage RUNTIME_OUTPUT_DIRECTORY)
add_custom_command(TARGET Sage POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SAGE_BIN}/Debug/Sage.dll C:/dev/Sage/bin/Debug-Windows/SandboxApp/Debug/)
