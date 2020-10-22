cmake_minimum_required(VERSION 3.10)

# add FindPCRE
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(Environmental)

find_package(Curses REQUIRED)
find_package(PCRE2 REQUIRED)

# It actually works without PCRE2_INCLUDE_DIR
# But I ll keep it anyway 
include_directories(${CURSES_INCLUDE_DIRS} ${PCRE2_INCLUDE_DIR})


add_executable(main main.c)

target_link_libraries( main ${CURSES_LIBRARIES} ${PCRE2_LIBRARY})
