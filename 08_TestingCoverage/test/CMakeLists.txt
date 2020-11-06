find_package(Check REQUIRED)

include_directories(${CHECK_INCLUDE_DIR}) 
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(core_tests core_tests.c)
add_executable(mem_out_err mem_out_err.c)
add_executable(init_over_err init_over_err.c)
add_executable(grow_over_err grow_over_err.c)

target_link_libraries(core_tests ${CHECK_LIBRARIES} buf)
target_link_libraries(mem_out_err buf)
target_link_libraries(init_over_err buf)
target_link_libraries(grow_over_err buf)