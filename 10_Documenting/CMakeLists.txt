cmake_minimum_required(VERSION 3.10)

project(guess)
add_executable(guess guess.c ru.po guess.pot)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    set(MAINPAGE_IN ${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md.in)
	set(MAINPAGE_OUT ${CMAKE_CURRENT_BINARY_DIR}/mainpage.md)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    configure_file(${MAINPAGE_IN} ${MAINPAGE_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

find_program(HELP2MAN_FOUND help2man)
if (HELP2MAN_FOUND)
	add_custom_target(man
		DEPENDS guess
		COMMAND help2man --no-info --output=guess.1 --name=${PROJECT_NAME} ./${PROJECT_NAME}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
		COMMENT "Generating MAN page"
		VERBATIM
	)
endif(HELP2MAN_FOUND)


add_custom_command(
	OUTPUT ru/LC_MESSAGES/guess.mo
	DEPENDS ${CMAKE_SOURCE_DIR}/ru.po
	COMMAND mkdir -p ru/LC_MESSAGES
	COMMAND msgfmt ${CMAKE_SOURCE_DIR}/ru.po -o ru/LC_MESSAGES/guess.mo
)

add_custom_command(
	OUTPUT ${CMAKE_SOURCE_DIR}/ru.po
	DEPENDS ${CMAKE_SOURCE_DIR}/guess.pot
	COMMAND msgmerge -U ${CMAKE_SOURCE_DIR}/ru.po ${CMAKE_SOURCE_DIR}/guess.pot
)

add_custom_command(
	OUTPUT ${CMAKE_SOURCE_DIR}/guess.pot
	DEPENDS ${CMAKE_SOURCE_DIR}/guess.c
	COMMAND xgettext -k_ -c ${CMAKE_SOURCE_DIR}/guess.c -o new.pot
	COMMAND msgmerge -U ${CMAKE_SOURCE_DIR}/guess.pot new.pot
	COMMAND rm -f new.pot
)

add_custom_target(translate
        DEPENDS ru/LC_MESSAGES/guess.mo
)

