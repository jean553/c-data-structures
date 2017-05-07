cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

project(c-data-structures)
enable_testing()

add_compile_options(-std=c99)

add_subdirectory(linked_list)
add_subdirectory(double_linked_list)
add_subdirectory(vector)
add_subdirectory(self_organizing_list)
add_subdirectory(unrolled_linked_list)
add_subdirectory(hashmap)

add_subdirectory(tests_linked_list)
add_subdirectory(tests_double_linked_list)
add_subdirectory(tests_vector)
add_subdirectory(tests_self_organizing_list)
add_subdirectory(tests_unrolled_linked_list)
add_subdirectory(tests_hashmap)
