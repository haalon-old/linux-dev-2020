CFLAGS += -Wall

if COND_GCOV
   CFLAGS += -fprofile-arcs -ftest-coverage -O0 -g
endif

lib_LTLIBRARIES = libnamegen.la

bin_PROGRAMS=namegen
namegen_LDADD = libnamegen.la
pkgdata_DATA = namegen.1

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<

gcov:
	gcov .libs/libnamegen -t -j -k
