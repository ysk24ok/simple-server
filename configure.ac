#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Ensure that a recent enough version of Autoconf is being used.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Versioning.html
AC_PREREQ([2.69])

# Process any command-line arguments and perform initialization and verification.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Initializing-configure.html
AC_INIT([simple_server], [0.1.0], [yusuke.nishioka.0713@gmail.com])

# Specify dir as the location of additional local Autoconf macros.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Input.html
AC_CONFIG_MACRO_DIR([m4])

# Runs many macros required for proper operation of the generated Makefiles.
# https://www.gnu.org/software/automake/manual/html_node/Public-Macros.html
AM_INIT_AUTOMAKE([foreign subdir-objects])

# This macro adds many new tests to the configure script
# so that the generated libtool script will understand the characteristics of the host.
# https://www.gnu.org/software/libtool/manual/html_node/LT_005fINIT.html
LT_INIT

# Make AC_OUTPUT create the file(s)
# in the blank-or-newline-separated list header containing C preprocessor #define statements,
# and replace ‘@DEFS@’ in generated files with -DHAVE_CONFIG_H instead of the value of DEFS.)
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Configuration-Headers.html
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
# Set output variable INSTALL to the name of a BSD-compatible install program
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Particular-Programs.html
AC_PROG_INSTALL

# Determine a C++ compiler to use.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/C_002b_002b-Compiler.html
AC_PROG_CXX([g++])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Make AC_OUTPUT create each file by copying an input file (by default file.in),
# substituting the output variable values.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Configuration-Files.html
AC_CONFIG_FILES([Makefile])
# Generate config.status and launch it. Call this macro once, at the end of configure.ac.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Output.html
AC_OUTPUT
