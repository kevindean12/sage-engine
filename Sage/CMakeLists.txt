cmake_minimum_required(VERSION 3.14)

project(Sage VERSION 0.1.0 LANGUAGES CXX)

include_directories(vendor/spdlog/include)

add_library(Sage SHARED src/Sage.hpp)

install(TARGETS Sage DESTINATION bin)