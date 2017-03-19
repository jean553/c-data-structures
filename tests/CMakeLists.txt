enable_testing()

find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIRS} ../src)
set(LIBS ${LIBS} ${CHECK_LIBRARIES} linked_list)

add_executable(test_linked_list test_linked_list.c)
target_link_libraries(test_linked_list ${LIBS})

add_test(test_linked_list ${CMAKE_CURRENT_BINARY_DIR}/test_linked_list)
