cmake_minimum_required(VERSION 3.10)

project(Guess)
add_executable(guess guess.c)

include(FindGettext)
include(GNUInstallDirs)

GETTEXT_PROCESS_PO_FILES(ru ALL INSTALL_DESTINATION ${CMAKE_INSTALL_LOCALEDIR} PO_FILES guess.po)
install(TARGETS guess RUNTIME)

configure_file(config.h.in config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
# so we ll include generated config.h