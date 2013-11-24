#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(cspec, 0.3.0-snapshot, quanyangyi0323@gmail.com)
AC_CONFIG_SRCDIR([src/cspec_output.c])
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])

dnl LT_INIT replaces AC_PROG_RANLIB
LT_INIT

AM_CFLAGS="-Wall -Wextra"

AC_ARG_ENABLE(debug,
[AS_HELP_STRING([--enable-debug],[turn on debugging])],
[case "${enableval}" in
  yes) AM_CFLAGS="${AM_CFLAGS}" ;;
  no)  AM_CFLAGS="${AM_CFLAGS} -DNDEBUG" ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
esac],[AM_CFLAGS="${AM_CFLAGS} -DNDEBUG"])

AC_ARG_ENABLE(profile,
[AS_HELP_STRING([--enable-profile],[turn on profiling])],
[case "${enableval}" in
  yes) AM_CFLAGS="${AM_CFLAGS} -pg" ;;
  no) ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-profile) ;;
esac])

AC_ARG_ENABLE(coverage,
[AS_HELP_STRING([--enable-coverage],[turn on coverage feature])],
[case "${enableval}" in
  yes) AM_CFLAGS="${AM_CFLAGS} -fprofile-arcs -ftest-coverage" ;;
  no) ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-coverage) ;;
esac])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([memory.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([memset strdup])

AC_CONFIG_FILES([Makefile
                 inc/Makefile
                 src/Makefile
                 examples/sample/Makefile
                 examples/skip/Makefile
                 examples/spec/Makefile
                 examples/xml_output/Makefile])
AC_SUBST(AM_CFLAGS)
AC_OUTPUT
