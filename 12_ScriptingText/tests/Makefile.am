TESTS = dummy fixed errors
check_PROGRAMS = dummy fixed errors

CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libnamegen.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
