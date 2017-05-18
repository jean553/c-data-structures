enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../skip_list)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} skip_list)

add_executable(test_skip_list test_skip_list.c)
target_link_libraries(test_skip_list ${LIBS} -lpthread -lm -lrt)
add_test(test_skip_list ${CMAKE_CURRENT_BINARY_DIR}/test_skip_list)
