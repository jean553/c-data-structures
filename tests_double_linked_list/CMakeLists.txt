enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../double_linked_list)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} double_linked_list)

add_executable(test_double_linked_list test_double_linked_list.c)
target_link_libraries(test_double_linked_list ${LIBS} -lpthread -lm -lrt)
add_test(test_double_linked_list ${CMAKE_CURRENT_BINARY_DIR}/test_double_linked_list)
