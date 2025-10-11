dnl
dnl $ Id: pango 1.0.1$
dnl

PHP_ARG_WITH(pango, for Pango text layout library support,
[  --with-pango            Enable Pango support], yes)

if test "$PHP_PANGO" != "no"; then
  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_PANGO"

  AC_MSG_CHECKING(PHP version)
  AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([#include <php_version.h>], [
#if PHP_VERSION_ID < 80100
#error this extension requires at least PHP version 8.1.0
#endif
    ])],
    [AC_MSG_RESULT(ok)],
    [AC_MSG_ERROR([need at least PHP 8.1.0])]
  )

  export CPPFLAGS="$OLD_CPPFLAGS"

  PHP_SUBST(PANGO_SHARED_LIBADD)
  AC_DEFINE(HAVE_PANGO, 1, [ ])

  PHP_NEW_EXTENSION(pango, src/pango.c src/exception.c src/context.c src/layout.c src/font_description.c src/layout_line.c src/glyph_item.c src/item.c src/glyph_string.c src/glyph_info.c src/matrix.c src/rectangle.c, $ext_shared)

  EXT_PANGO_HEADERS="php_pango_api.h"

  ifdef([PHP_INSTALL_HEADERS], [
    PHP_INSTALL_HEADERS(ext/pango, $EXT_PANGO_HEADERS)
  ])

  if test "$PHP_PANGO" != "no"; then
    PANGO_CHECK_DIR=$PHP_PANGO
    PANGO_TEST_FILE=/include/pango.h
    PANGO_LIBNAME=pango
  fi
  condition="$PANGO_CHECK_DIR$PANGO_TEST_FILE"

  if test -r $condition; then
    PANGO_DIR=$PANGO_CHECK_DIR
    CFLAGS="$CFLAGS -I$PANGO_DIR/include"
    LDFLAGS=`$PANGO_DIR/bin/pango-config --libs`
  else
    AC_MSG_CHECKING(for pkg-config)

    if test ! -f "$PKG_CONFIG"; then
      PKG_CONFIG=`which pkg-config`
    fi

    if test ! -f "$PKG_CONFIG"; then
      AC_MSG_RESULT(not found)
      AC_MSG_ERROR(Ooops ! no pkg-config found .... )
    fi

    AC_MSG_RESULT(found)
    AC_MSG_CHECKING(for pango)

    if ! $PKG_CONFIG --exists pango; then
      AC_MSG_RESULT(not found)
      AC_MSG_ERROR(Ooops ! no pango detected in the system)
    fi

    PANGO_MIN_VERSION="1.50"
    if ! $PKG_CONFIG --atleast-version=$PANGO_MIN_VERSION pango; then
      AC_MSG_RESULT(too old)
      AC_MSG_ERROR(Ooops ! You need at least pango $PANGO_MIN_VERSION)
    fi

    pango_version_full=`$PKG_CONFIG --modversion pango`
    AC_MSG_RESULT([found $pango_version_full])

    PANGO_LIBS="$LDFLAGS `$PKG_CONFIG --libs pango`"
    PHP_EVAL_LIBLINE($PANGO_LIBS, PANGO_SHARED_LIBADD)
    PANGO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I pango`"
    PHP_EVAL_INCLINE($PANGO_INCS)

    CAIRO_LIBS="$LDFLAGS `$PKG_CONFIG --libs cairo`"
    PHP_EVAL_LIBLINE($CAIRO_LIBS, PANGO_SHARED_LIBADD)
    CAIRO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I cairo`"
    PHP_EVAL_INCLINE($CAIRO_INCS)

    PANGOCAIRO_LIBS="$LDFLAGS `$PKG_CONFIG --libs pangocairo`"
    PHP_EVAL_LIBLINE($PANGOCAIRO_LIBS, PANGO_SHARED_LIBADD)
    PANGOCAIRO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I pangocairo`"
    PHP_EVAL_INCLINE($PANGOCAIRO_INCS)

    AC_DEFINE(HAVE_PANGO, 1, [whether pango exists in the system])
  fi

  AC_MSG_CHECKING(for cairo php extension)
  if test ! -f "$phpincludedir/ext/cairo/src/php_cairo_internal.h"; then
    AC_MSG_RESULT(no)
    AC_MSG_ERROR(cairo php extension not found.)
  fi

  if test "$PANGO_COVERAGE" = "yes"; then
      CFLAGS="$CFLAGS --coverage"
      LDFLAGS="$LDFLAGS --coverage"
  fi


  PHP_ADD_INCLUDE($phpincludedir/ext/cairo)
  AC_DEFINE(CAIRO, 1, [whether cairo exists in the system])
  AC_MSG_RESULT(yes)
fi
