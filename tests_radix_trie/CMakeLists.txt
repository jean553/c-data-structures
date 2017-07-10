enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../radix_trie)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} radix_trie)

add_executable(test_radix_trie test_radix_trie.c)
target_link_libraries(test_radix_trie ${LIBS} -lpthread -lm -lrt)
add_test(test_radix_trie ${CMAKE_CURRENT_BINARY_DIR}/test_radix_trie)
