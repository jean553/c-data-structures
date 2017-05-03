enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../unrolled_linked_list ../vector)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} unrolled_linked_list vector)

add_executable(test_unrolled_linked_list test_unrolled_linked_list.c)
target_link_libraries(test_unrolled_linked_list ${LIBS} -lpthread -lm -lrt)
add_test(test_unrolled_linked_list ${CMAKE_CURRENT_BINARY_DIR}/test_unrolled_linked_list)
