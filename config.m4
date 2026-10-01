PHP_ARG_WITH([pango],
  [for Pango text layout library support],
  [AS_HELP_STRING([--with-pango],
    [Enable Pango support])],
  [yes])

if test "$PHP_PANGO" != "no"; then
  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_PANGO"

  AC_MSG_CHECKING([PHP version])
  AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([#include <php_version.h>], [
#if PHP_VERSION_ID < 80200
#error this extension requires at least PHP version 8.2.0
#endif
    ])],
    [AC_MSG_RESULT(ok)],
    [AC_MSG_ERROR([need at least PHP 8.2.0])]
  )

  export CPPFLAGS="$OLD_CPPFLAGS"

  PHP_SUBST([PANGO_SHARED_LIBADD])
  AC_DEFINE([HAVE_PANGO], [1], [ ])

  PHP_NEW_EXTENSION([pango], m4_normalize([
    src/analysis.c
    src/color.c
    src/context.c
    src/coverage.c
    src/exception.c
    src/font.c
    src/font_description.c
    src/font_face.c
    src/font_family.c
    src/font_metrics.c
    src/font_map.c
    src/font_set.c
    src/font_set_simple.c
    src/glyph_geometry.c
    src/glyph_info.c
    src/glyph_item.c
    src/glyph_string.c
    src/glyph_vis_attr.c
    src/item.c
    src/language.c
    src/layout_line.c
    src/layout_iter.c
    src/layout.c
    src/logattr.c
    src/logattr_list.c
    src/matrix.c
    src/pango.c
    src/rectangle.c
    src/script_iter.c
    src/script_iter_range.c
    src/tabstop.c
    src/tabstops.c
    src/attribute/attr_absolute_line_height.c
    src/attribute/attr_absolute_size.c
    src/attribute/attr_allow_breaks.c
    src/attribute/attr_background_alpha.c
    src/attribute/attr_background.c
    src/attribute/attr_baseline_shift.c
    src/attribute/attr_common.c
    src/attribute/attr_fallback.c
    src/attribute/attr_family.c
    src/attribute/attr_font_description.c
    src/attribute/attr_font_features.c
    src/attribute/attr_font_scale.c
    src/attribute/attr_foreground_alpha.c
    src/attribute/attr_foreground.c
    src/attribute/attr_gravity_hint.c
    src/attribute/attr_gravity.c
    src/attribute/attr_insert_hyphens.c
    src/attribute/attr_iter.c
    src/attribute/attr_language.c
    src/attribute/attr_letter_spacing.c
    src/attribute/attr_line_height.c
    src/attribute/attr_list.c
    src/attribute/attr_overline_color.c
    src/attribute/attr_overline.c
    src/attribute/attr_rise.c
    src/attribute/attr_scale.c
    src/attribute/attr_sentence.c
    src/attribute/attr_show.c
    src/attribute/attr_size.c
    src/attribute/attr_stretch.c
    src/attribute/attr_strikethrough_color.c
    src/attribute/attr_strikethrough.c
    src/attribute/attr_style.c
    src/attribute/attr_text_transform.c
    src/attribute/attr_type_to_ce_table.c
    src/attribute/attr_underline_color.c
    src/attribute/attr_underline.c
    src/attribute/attr_variant.c
    src/attribute/attr_weight.c
    src/attribute/attr_width.c
    src/attribute/attr_word.c
    src/attribute/attribute.c
    src/cairo/pango_cairo_context.c
    src/cairo/pango_cairo_font_map.c
    src/cairo/pango_cairo_layout.c
    src/cairo/pango_cairo_layout_line.c
    src/fc/pango_fc_font_map.c
    src/ft2/pango_ft2_font_map.c
  ]), [$ext_shared],, [-Isrc -Isrc/attribute -Isrc/cairo -Isrc/fc -Isrc/ft2])

  EXT_PANGO_HEADERS="php_pango.h src/attribute/attribute.h src/cairo/pango_cairo.h src/fc/pango_fc.h src/ft2/pango_ft2.h src/analysis.h src/color.h src/context.h src/coverage.h src/exception.h src/font.h src/font_description.h src/font_face.h src/font_family.h src/font_map.h src/font_metrics.h src/font_set.h src/font_set_simple.h src/glyph_geometry.h src/glyph_info.h src/glyph_item.h src/glyph_string.h src/glyph_vis_attr.h src/item.h src/language.h src/layout.h src/layout_iter.h src/layout_line.h src/logattr.h src/logattr_list.h src/matrix.h src/pango.h src/rectangle.h src/script.h src/tabstops.h"

  ifdef([PHP_INSTALL_HEADERS], [
    PHP_INSTALL_HEADERS([ext/pango], [$EXT_PANGO_HEADERS])
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
    AC_MSG_CHECKING([for pkg-config])

    if test ! -f "$PKG_CONFIG"; then
      PKG_CONFIG=`which pkg-config`
    fi

    if test ! -f "$PKG_CONFIG"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Ooops ! no pkg-config found .... ])
    fi

    AC_MSG_RESULT([found])
    AC_MSG_CHECKING([for pango])

    if ! $PKG_CONFIG --exists pango; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Ooops ! no pango detected in the system])
    fi

    PANGO_MIN_VERSION="1.50"
    if ! $PKG_CONFIG --atleast-version=$PANGO_MIN_VERSION pango; then
      AC_MSG_RESULT([too old])
      AC_MSG_ERROR([Ooops ! You need at least pango $PANGO_MIN_VERSION])
    fi

    pango_version_full=`$PKG_CONFIG --modversion pango`
    AC_MSG_RESULT([found $pango_version_full])

    PANGO_LIBS="$LDFLAGS `$PKG_CONFIG --libs pango`"
    PHP_EVAL_LIBLINE([$PANGO_LIBS], [PANGO_SHARED_LIBADD])
    PANGO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I pango`"
    PHP_EVAL_INCLINE([$PANGO_INCS])

    CAIRO_LIBS="$LDFLAGS `$PKG_CONFIG --libs cairo`"
    PHP_EVAL_LIBLINE([$CAIRO_LIBS], [PANGO_SHARED_LIBADD])
    CAIRO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I cairo`"
    PHP_EVAL_INCLINE([$CAIRO_INCS])

    PANGOCAIRO_LIBS="$LDFLAGS `$PKG_CONFIG --libs pangocairo`"
    PHP_EVAL_LIBLINE([$PANGOCAIRO_LIBS], [PANGO_SHARED_LIBADD])
    PANGOCAIRO_INCS="$CFLAGS `$PKG_CONFIG --cflags-only-I pangocairo`"
    PHP_EVAL_INCLINE([$PANGOCAIRO_INCS])

    AC_DEFINE([HAVE_PANGO], [1], [whether pango exists in the system])
  fi

  AC_MSG_CHECKING([for cairo php extension])
  if test ! -f "$phpincludedir/ext/cairo/src/php_cairo_internal.h"; then
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([cairo php extension not found.])
  fi

  if test "$PANGO_COVERAGE" = "yes"; then
      CFLAGS="$CFLAGS --coverage"
      LDFLAGS="$LDFLAGS --coverage"
  fi

  PHP_ADD_INCLUDE([$phpincludedir/ext/cairo/src])
  AC_DEFINE([CAIRO], [1], [whether cairo exists in the system])
  AC_MSG_RESULT([yes])
fi
