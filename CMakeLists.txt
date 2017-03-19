cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_COMPILER gcc)
project(c-data-structures)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE c-data-structures)

file(
    GLOB
    sources
    src/*
)

include_directories(includes)

add_executable(
    ${EXECUTABLE}
    src/main.c
    ${sources}
)
