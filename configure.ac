AC_INIT([ovirt-guest-agent],
        [2.0],
        [evilissimo@redhat.com],
        [ovirt-guest-agent],
        [http://github.com/vinzenz/ovirt-guest-agent2])
AC_PREREQ([2.59])

AM_INIT_AUTOMAKE([1.10 -Wall no-define subdir-objects])

AC_PROG_CXX
AC_CONFIG_MACRO_DIR([m4])

m4_pattern_allow([AM_PROG_AR])
AM_PROG_AR
AM_PROG_AS

LT_INIT

OGA_OS_FREEBSD=0
OGA_OS_WIN=0
OGA_OS_LINUX=0
OGA_OS_POSIX=0

case "$host" in
    *-linux-gnu)
        OGA_OS_LINUX=1
        OGA_OS_POSIX=1
    ;;
    *-mingw32*)
        OGA_OS_WIN=1
    ;;
esac
echo $host

AM_CONDITIONAL(OGA_OS_WIN,     [test "$OGA_OS_WIN" == "1" ])
AM_CONDITIONAL(OGA_OS_LINUX,   [test "$OGA_OS_LINUX" == "1" ])
AM_CONDITIONAL(OGA_OS_POSIX,   [test "$OGA_OS_POSIX" == "1" ])
AM_CONDITIONAL(OGA_OS_FREEBSD, [test "$OGA_OS_FREEBSD" == "1" ])

OGA_CXX_INCLUDES="-I\$(top_srcdir)/src -I\$(top_srcdir)/third_party/chromium"
OGA_CXX_FLAGS="-std=c++98 -W -Wall -pedantic \$(OGA_CXX_INCLUDES)"
AC_SUBST([OGA_CXX_INCLUDES])
AC_SUBST([OGA_CXX_FLAGS])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    src/oga/Makefile
    tests/Makefile
    third_party/Makefile
    third_party/chromium/Makefile
    third_party/chromium/third_party/icu/Makefile
])
AC_OUTPUT
