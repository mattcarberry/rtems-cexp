# Find out if host_os is *rtems*;
#
# Result is exit status, i.e., this macro can e.g., be used
# in a 'if MACRO ; then list; fi' statement.
#
# TILLAC_RTEMS_HOSTOS_IS_RTEMS
AC_DEFUN([TILLAC_RTEMS_HOSTOS_IS_RTEMS],
	[AC_REQUIRE([AC_CANONICAL_HOST])
    case "${host_os}" in *rtems* ) : ;; *) false;; esac]dnl
)

# Find out if either '--with-rtems-top' was given or
# host_os is *rtems* (or both).
#
# Result is exit status, i.e., this macro can e.g., be used
# in a 'if MACRO ; then list; fi' statement.
#
# TILLAC_RTEMS_OS_IS_RTEMS
AC_DEFUN([TILLAC_RTEMS_OS_IS_RTEMS],
	[AC_REQUIRE([AC_CANONICAL_HOST])
    test "${with_rtems_top+set}" = "set" || TILLAC_RTEMS_HOSTOS_IS_RTEMS]dnl
)

# Find out if we are NOT at the top of the configuration 
# process, i.e., --with-rtems-top is not given OR host_os is
# *rtems*.
#
# TILLAC_RTEMS_NOT_CONFIG_TOP
AC_DEFUN([TILLAC_RTEMS_NOT_CONFIG_TOP],
	[AC_REQUIRE([AC_CANONICAL_HOST])
	test ! "${with_rtems_top+set}" = "set" || TILLAC_RTEMS_HOSTOS_IS_RTEMS]dnl
)
