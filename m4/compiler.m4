dnl Copyright (C) 2008, 2009, 2010 D. V. Wiebe
dnl
dnl llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
dnl
dnl This file is part of the GetData project.
dnl
dnl GetData is free software; you can redistribute it and/or modify it under
dnl the terms of the GNU Lesser General Public License as published by the
dnl Free Software Foundation; either version 2.1 of the License, or (at your
dnl option) any later version.
dnl
dnl GetData is distributed in the hope that it will be useful, but WITHOUT
dnl ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
dnl FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
dnl License for more details.
dnl
dnl You should have received a copy of the GNU Lesser General Public License
dnl along with GetData; if not, write to the Free Software Foundation, Inc.,
dnl 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

dnl GD_LANG_COMPILER_INTEL
dnl -------------------------------------------------------------
dnl Check whether the compiler for the current language is Intel.
dnl
dnl This is modelled after autoconf's _AC_LANG_COMPILER_GNU macro.
AC_DEFUN([GD_LANG_COMPILER_INTEL],
[AC_CACHE_CHECK([whether we are using the Intel _AC_LANG compiler],
[gd_cv_[]_AC_LANG_ABBREV[]_compiler_intel],
[AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [[#ifndef __INTEL_COMPILER
       choke me
#endif
]])],
[gd_compiler_intel=yes],
[gd_compiler_intel=no])
gd_cv_[]_AC_LANG_ABBREV[]_compiler_intel=$gd_compiler_intel
])])

dnl GD_LANG_F77_COMPILER_INTEL
dnl -------------------------------------------------------------
dnl Check whether the compiler for Fortran is Intel.
AC_DEFUN([GD_LANG_F77_COMPILER_INTEL],
[AC_CACHE_CHECK([whether we are using the Intel Fortran-77 compiler],
[gd_cv_f77_compiler_intel],
[if $F77 -help 2>/dev/null | grep -q 'Intel.R. Fortran Compiler'; then
gd_cv_f77_compiler_intel=yes
else
gd_cv_f77_compiler_intel=no
fi
])])

dnl GD_LANG_FC_COMPILER_INTEL
dnl -------------------------------------------------------------
dnl Check whether the compiler for free-form Fortran is Intel.
AC_DEFUN([GD_LANG_FC_COMPILER_INTEL],
[AC_CACHE_CHECK([whether we are using the Intel Fortran compiler],
[gd_cv_fc_compiler_intel],
[if $FC -help 2>/dev/null | grep -q 'Intel.R. Fortran Compiler'; then
gd_cv_fc_compiler_intel=yes
else
gd_cv_fc_compiler_intel=no
fi
])])

dnl GD_PROG_CC_WEXTRA
dnl -------------------------------------------------------------
dnl Check whether the C compiler accepts -Wextra
AC_DEFUN([GD_PROG_CC_WEXTRA],
[gd_saved_CFLAGS=$CFLAGS
AC_CACHE_CHECK([whether $CC accepts -Wextra], gd_cv_prog_cc_wextra,
[CFLAGS="-Wextra"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_cc_wextra=yes],
[gd_cv_prog_cc_wextra=no])])
CFLAGS=$gd_saved_CFLAGS])


dnl GD_PROG_CXX_WEXTRA
dnl -------------------------------------------------------------
dnl Check whether the C++ compiler accepts -Wextra
AC_DEFUN([GD_PROG_CXX_WEXTRA],
[gd_saved_CXXFLAGS=$CXXFLAGS
AC_CACHE_CHECK([whether $CXX accepts -Wextra], gd_cv_prog_cxx_wextra,
[CXXFLAGS="-Wextra"
AC_LANG_PUSH([C++])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_cxx_wextra=yes],
[gd_cv_prog_cxx_wextra=no])
AC_LANG_POP([C++])])
CXXFLAGS=$gd_saved_CXXFLAGS])


dnl GD_PROG_F77_WEXTRA
dnl -------------------------------------------------------------
dnl Check whether the Fotran-77 compiler accepts -Wextra
AC_DEFUN([GD_PROG_F77_WEXTRA],
[gd_saved_FFLAGS=$FFLAGS
AC_CACHE_CHECK([whether $F77 accepts -Wextra], gd_cv_prog_f77_wextra,
[FFLAGS="-Wextra"
AC_LANG_PUSH([Fortran 77])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_f77_wextra=yes],
[gd_cv_prog_f77_wextra=no])
AC_LANG_POP([Fortran 77])])
FFLAGS=$gd_saved_FFLAGS])


dnl GD_PROG_F77_FNO_BACKSLASH
dnl -------------------------------------------------------------
dnl Check whether the Fotran-77 compiler accepts -fno-backslash
AC_DEFUN([GD_PROG_F77_FNO_BACKSLASH],
[gd_saved_FFLAGS=$FFLAGS
AC_CACHE_CHECK([whether $F77 accepts -fno-backslash],
gd_cv_prog_f77_fno_backslash, [FFLAGS="-fno-backslash"
AC_LANG_PUSH([Fortran 77])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_f77_fno_backslash=yes],
[gd_cv_prog_f77_fno_backslash=no])
AC_LANG_POP([Fortran 77])])
FFLAGS=$gd_saved_FFLAGS])


dnl GD_PROG_FC_WEXTRA
dnl -------------------------------------------------------------
dnl Check whether the free-form Fotran compiler accepts -Wextra
AC_DEFUN([GD_PROG_FC_WEXTRA],
[gd_saved_FCFLAGS=$FCFLAGS
AC_CACHE_CHECK([whether $FC accepts -Wextra], gd_cv_prog_fc_wextra,
[FCFLAGS="-Wextra"
AC_LANG_PUSH([Fortran 77])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_fc_wextra=yes],
[gd_cv_prog_fc_wextra=no])
AC_LANG_POP([Fortran 77])])
FCFLAGS=$gd_saved_FCFLAGS])

dnl GD_PROG_CC_WALL
dnl -------------------------------------------------------------
dnl Check whether the C compiler accepts -Wall
AC_DEFUN([GD_PROG_CC_WALL],
[gd_saved_CFLAGS=$CFLAGS
AC_CACHE_CHECK([whether $CC accepts -Wall], gd_cv_prog_cc_wall,
[CFLAGS="-Wall"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_cc_wall=yes],
[gd_cv_prog_cc_wall=no])])
CFLAGS=$gd_saved_CFLAGS])


dnl GD_PROG_CXX_WALL
dnl -------------------------------------------------------------
dnl Check whether the C++ compiler accepts -Wall
AC_DEFUN([GD_PROG_CXX_WALL],
[gd_saved_CXXFLAGS=$CXXFLAGS
AC_CACHE_CHECK([whether $CXX accepts -Wall], gd_cv_prog_cxx_wall,
[CXXFLAGS="-Wall"
AC_LANG_PUSH([C++])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_cxx_wall=yes],
[gd_cv_prog_cxx_wall=no])
AC_LANG_POP([C++])])
CXXFLAGS=$gd_saved_CXXFLAGS])


dnl GD_PROG_F77_WALL
dnl -------------------------------------------------------------
dnl Check whether the Fotran-77 compiler accepts -Wall
AC_DEFUN([GD_PROG_F77_WALL],
[gd_saved_FFLAGS=$FFLAGS
AC_CACHE_CHECK([whether $F77 accepts -Wall], gd_cv_prog_f77_wall,
[FFLAGS="-Wall"
AC_LANG_PUSH([Fortran 77])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_f77_wall=yes],
[gd_cv_prog_f77_wall=no])
AC_LANG_POP([Fortran 77])])
FFLAGS=$gd_saved_FFLAGS])


dnl GD_PROG_FC_WALL
dnl -------------------------------------------------------------
dnl Check whether the free-form Fotran compiler accepts -Wall
AC_DEFUN([GD_PROG_FC_WALL],
[gd_saved_FCFLAGS=$FCFLAGS
AC_CACHE_CHECK([whether $FC accepts -Wall], gd_cv_prog_fc_wall,
[FCFLAGS="-Wall"
AC_LANG_PUSH([Fortran 77])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [gd_cv_prog_fc_wall=yes],
[gd_cv_prog_fc_wall=no])
AC_LANG_POP([Fortran 77])])
FCFLAGS=$gd_saved_FCFLAGS])

dnl GD_C_RESTRICT_ARRAY
dnl -----------------------------------------------------------
dnl Check whether "<type> *restrict foo[]" is allowed.
AC_DEFUN([GD_C_RESTRICT_ARRAY],[
dnl do nothing if restrict hasn't been found
if ! test "x$ac_cv_c_restrict" = "xno"; then
AC_CACHE_CHECK([whether restrict can be applied to pointer array arguments],
[gd_cv_c_restrict_array],[
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([
    int *foo (int *restrict bar@<:@3@:>@) { return bar@<:@2@:>@; }
], [])],
[gd_cv_c_restrict_array="yes"],[gd_cv_c_restrict_array="no"])
])
fi

if test "x$gd_cv_c_restrict_array" = "xyes"; then
AC_DEFINE([GD_RESTRICT_ARRAY_OK], [1],
[Define to 1 if restrict can used on pointer arrays])
fi
])
