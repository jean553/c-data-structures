enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../trie)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} trie)

add_executable(tests_trie tests_trie.c)
target_link_libraries(tests_trie ${LIBS} -lpthread -lm -lrt)
add_test(tests_trie ${CMAKE_CURRENT_BINARY_DIR}/tests_trie)
