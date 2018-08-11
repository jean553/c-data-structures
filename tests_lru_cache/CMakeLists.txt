enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../lru_cache ../self_organizing_list)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} lru_cache self_organizing_list)

add_executable(test_lru_cache test_lru_cache.c)
target_link_libraries(test_lru_cache ${LIBS} -lpthread -lm -lrt)
add_test(test_lru_cache ${CMAKE_CURRENT_BINARY_DIR}/test_lru_cache)
