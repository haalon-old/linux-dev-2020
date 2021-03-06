cmake_minimum_required(VERSION 3.10)

# add FindPCRE
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(Environmental)

find_package(Curses REQUIRED)
find_package(PCRE2 REQUIRED)

# It actually works without PCRE2_INCLUDE_DIR
# But I ll keep it anyway 
include_directories(${CURSES_INCLUDE_DIRS} ${PCRE2_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})


# Also found a way to do it manually

# find_library(PCRE2_LIBRARY pcre2-8)

# find_path(PCRE2_INCLUDE_DIRS pcre2.h)
# find_path(LOCALE_INCLUDE_DIRS locale.h)

# include_directories(${CURSES_INCLUDE_DIR} ${PCRE2_INCLUDE_DIRS} ${LOCALE_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
# target_link_libraries(Window ${CURSES_LIBRARY} ${PCRE2_LIBRARY})

add_executable(main main.c)

target_link_libraries( main ${CURSES_LIBRARIES} ${PCRE2_LIBRARY})

option(USE_UTF "Use utf in regexps" ON)

configure_file(config.h.in config.h)