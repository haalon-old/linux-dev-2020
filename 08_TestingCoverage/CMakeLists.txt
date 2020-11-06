cmake_minimum_required(VERSION 3.13)
project(buf)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(inc)
add_library(buf src/buf.c)

add_subdirectory(test)

enable_testing()

# original buf.h uses abort() in case of errors
# i changed it to use exit(1)
# so WILL_FAIL will indeed catch them as a successful failure

add_test(NAME core_tests    COMMAND core_tests)
add_test(NAME mem_out_err   COMMAND mem_out_err)
add_test(NAME init_over_err COMMAND init_over_err)
add_test(NAME grow_over_err COMMAND grow_over_err)
set_tests_properties(mem_out_err init_over_err grow_over_err PROPERTIES WILL_FAIL TRUE)