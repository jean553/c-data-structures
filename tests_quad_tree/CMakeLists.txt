enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../quad_tree)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} quad_tree)

add_executable(test_quad_tree test_quad_tree.c)
target_link_libraries(test_quad_tree ${LIBS} -lpthread -lm -lrt)
add_test(test_quad_tree ${CMAKE_CURRENT_BINARY_DIR}/test_quad_tree)
