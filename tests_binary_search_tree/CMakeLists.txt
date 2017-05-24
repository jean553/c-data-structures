enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../binary_search_tree)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} binary_search_tree)

add_executable(test_binary_search_tree test_binary_search_tree.c)
target_link_libraries(test_binary_search_tree ${LIBS} -lpthread -lm -lrt)
add_test(test_binary_search_tree ${CMAKE_CURRENT_BINARY_DIR}/test_binary_search_tree)
