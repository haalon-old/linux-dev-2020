cmake_minimum_required(VERSION 3.10)

project(Guess)
add_executable(guess guess.c ru.po guess.pot)

# ru/LC_MESSAGES/ahello.mo: ru.po
# 	mkdir -p `dirname $@`
# 	msgfmt $< -o $@

# ru.po:	messages.pot
# 	msgmerge -U $@ $<

# messages.pot:	ahello.pot ahello.c
# 	xgettext -k_ -c ahello.c -o messages.new.pot
# 	cp ahello.pot messages.pot
# 	msgmerge -U messages.pot messages.new.pot

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

