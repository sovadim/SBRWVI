cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME serial)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

## set up variables
set(ROOT ${PROJECT_SOURCE_DIR})

## Out directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT}/out)

## include directories
include_directories(${ROOT}/include)

## srcs
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/arduino_serial
)
