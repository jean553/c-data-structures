enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../merkle_tree)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} merkle_tree)

add_executable(test_merkle_tree test_merkle_tree.c)
target_link_libraries(test_merkle_tree ${LIBS} -lpthread -lm -lrt -lcrypto)
add_test(test_merkle_tree ${CMAKE_CURRENT_BINARY_DIR}/test_merkle_tree)
