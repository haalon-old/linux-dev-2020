cmake_minimum_required(VERSION 3.13)
project(buf)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CTest)

include_directories(inc)
add_library(buf STATIC src/buf.c)
add_library(buf_test STATIC src/buf.c)


target_compile_options(buf_test PUBLIC ${CMAKE_C_FLAGS} -g -Wall -O0  -fprofile-arcs -ftest-coverage)
target_link_options(buf_test PUBLIC -fprofile-arcs)

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

# Coverage
add_custom_target(coverage)
add_custom_command(TARGET coverage
	COMMAND echo "====== coverage ======"
	COMMAND mkdir -p coverage
	COMMAND find ./ -name "*.gcno" -exec gcov -k {} "\;"
	COMMAND mv *.gcov ./coverage
	COMMAND echo ".gcov files in ./Coverage"
)