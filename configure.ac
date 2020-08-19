AC_INIT([momus], 0.0.1)
AM_INIT_AUTOMAKE

AC_PROG_CC

LT_INIT([shared disable-static])

PKG_CHECK_MODULES([GUILE], [guile-3.0])

AX_LIB_CURL([7.68])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
