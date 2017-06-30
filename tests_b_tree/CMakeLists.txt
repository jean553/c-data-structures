enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../b_tree)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} b_tree)

add_executable(test_b_tree test_b_tree.c)
target_link_libraries(test_b_tree ${LIBS} -lpthread -lm -lrt)
add_test(test_b_tree ${CMAKE_CURRENT_BINARY_DIR}/test_b_tree)
