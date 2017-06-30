enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../trie)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} trie)

add_executable(test_trie test_trie.c)
target_link_libraries(test_trie ${LIBS} -lpthread -lm -lrt)
add_test(test_trie ${CMAKE_CURRENT_BINARY_DIR}/test_trie)
