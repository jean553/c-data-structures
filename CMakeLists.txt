cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

project(c-data-structures)
enable_testing()

add_compile_options(-std=c99 -lpthread)

add_subdirectory(src)
add_subdirectory(tests)
