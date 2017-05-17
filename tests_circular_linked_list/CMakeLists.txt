enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../circular_linked_list ../linked_list)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} circular_linked_list linked_list)

add_executable(test_circular_linked_list test_circular_linked_list.c)
target_link_libraries(test_circular_linked_list ${LIBS} -lpthread -lm -lrt)
add_test(test_circular_linked_list ${CMAKE_CURRENT_BINARY_DIR}/test_circular_linked_list)
