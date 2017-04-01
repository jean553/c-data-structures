enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../vector)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} vector)

add_executable(test_vector test_vector.c)
target_link_libraries(test_vector ${LIBS} -lpthread -lm -lrt)
add_test(test_vector ${CMAKE_CURRENT_BINARY_DIR}/test_vector)
