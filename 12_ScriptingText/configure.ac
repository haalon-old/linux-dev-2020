#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([namegen], [0.0], [george@altlinux.org])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(namegen)
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/namegen.h])
AC_CONFIG_HEADERS([config.h])

#
PKG_CHECK_MODULES([CHECK],[check])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([HELP2MAN], [help2man])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
		 tests/Makefile
                 src/Makefile
         script.sh
		 Doxyfile
		 src/namegen.md
		 src/libnamegen.md
		 ])

AC_ARG_ENABLE([gcov],
  [AS_HELP_STRING([--enable-gcov],
    [use Gcov to test the test suite])],
    [],
    [enable_gcov=no])

AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])

AC_OUTPUT

echo "Bruh"
chmod +x script.sh
./script.sh "Breh"
