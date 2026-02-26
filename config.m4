dnl config.m4 for extension h3

PHP_ARG_WITH([h3],
  [for h3 support],
  [AS_HELP_STRING([--with-h3],
    [Include h3 support])])

if test "$PHP_H3" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/h3/h3api.h"

  AC_MSG_CHECKING([for h3 files])

  if test -r $PHP_H3/$SEARCH_FOR; then
    LIBH3_DIR=$PHP_H3
  else
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        LIBH3_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$LIBH3_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Could not find $SEARCH_FOR])
  fi

  PHP_ADD_INCLUDE($LIBH3_DIR/include)

  LIBNAME=h3
  LIBSYMBOL=latLngToCell

  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBH3_DIR/$PHP_LIBDIR, H3_SHARED_LIBADD)
  ],[
    AC_MSG_ERROR([$LIBNAME check error: $LIBSYMBOL symbol not found])
  ],[
    -L$LIBH3_DIR/$PHP_LIBDIR -lm
  ])

  PHP_NEW_EXTENSION(h3, h3.c, $ext_shared)
  PHP_SUBST(H3_SHARED_LIBADD)
fi
