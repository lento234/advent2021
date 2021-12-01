cmake_minimum_required(VERSION 3.15)

project(advent2021)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add all days
file(GLOB SOURCES "day*")
foreach(DIR ${SOURCES})
    add_subdirectory(${DIR})
endforeach()
