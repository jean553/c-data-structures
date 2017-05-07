enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../hashmap)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} hashmap)

add_executable(test_hashmap test_hashmap.c)
target_link_libraries(test_hashmap ${LIBS} -lpthread -lm -lrt)
add_test(test_hashmap ${CMAKE_CURRENT_BINARY_DIR}/test_hashmap)
