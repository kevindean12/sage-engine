cmake_minimum_required(VERSION 3.14)

project(Sage VERSION 0.1.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

add_library(Sage SHARED src/Sage.hpp)

install(TARGETS Sage DESTINATION bin)