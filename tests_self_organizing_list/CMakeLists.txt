enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../self_organizing_list)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} self_organizing_list linked_list)

add_executable(test_self_organizing_list test_self_organizing_list.c)
target_link_libraries(test_self_organizing_list ${LIBS} -lpthread -lm -lrt)
add_test(test_self_organizing_list ${CMAKE_CURRENT_BINARY_DIR}/test_self_organizing_list)
