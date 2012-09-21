# --
# Copyright (c) 2012 by itopia.pl team.
# 
# configure.ac
# Author: Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
# --

AC_PREREQ(2.61)

AC_INIT([npa],[0.1.1],[lukasz@podkalicki.com])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_HEADER([config.h])

AC_PREFIX_DEFAULT("/usr")

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checking header files
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset pow])

# List of common (for CFLAGS and CXXFLAGS) flags.
COMMONFLAGS="-Wall -static-libgcc -Wno-format-y2k -W -Wpointer-arith -Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch -Wshadow -Wcast-align -Wchar-subscripts -Winline -Wuninitialized -O2 -Wredundant-decls -Wcomment -Wformat -Wimplicit -Wlong-long -Wno-import -Wparentheses -Wpointer-arith -Wreturn-type -Wshadow -Wswitch -Wtrigraphs -Wwrite-strings -ggdb -Wunused"

# List of CXXFLAGS.
CXXFLAGS="$COMMONFLAGS -Wno-variadic-macros -Wno-format -std=gnu++98"

AC_SUBST(CXXFLAGS)

# List of CFLAGS.
CFLAGS="$COMMONFLAGS -pedantic -Waggregate-return -Wmissing-prototypes -Wbad-function-cast -Wnested-externs -Wimplicit-int -Wimplicit-function-declaration -Wmain -Wmissing-declarations -std=c99"

AC_SUBST(CFLAGS)

# List of linker flags.
LDFLAGS="-L/usr/local/lib -R/usr/local/lib"

AC_CONFIG_FILES([
Makefile
src/Makefile
src/libnpa/Makefile
])

AC_OUTPUT
