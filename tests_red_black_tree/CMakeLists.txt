enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../red_black_tree)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} red_black_tree)

add_executable(test_red_black_tree test_red_black_tree.c)
target_link_libraries(test_red_black_tree ${LIBS} -lpthread -lm -lrt)
add_test(test_red_black_tree ${CMAKE_CURRENT_BINARY_DIR}/test_red_black_tree)
