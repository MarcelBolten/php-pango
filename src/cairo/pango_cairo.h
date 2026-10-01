/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Michael Maclean <mgdm@php.net>                              |
  |          David Marín <davefx@gmail.com>                              |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_PANGO_PANGO_CAIRO_FONT_MAP_H
#define PHP_PANGO_PANGO_CAIRO_FONT_MAP_H

#include <php.h>
#include <pango/pango.h>

#include "../../php_pango.h"
#include "../font_map.h"
#include "../layout.h"
#include "../glyph_string.h"
#include "../layout_line.h"

PHP_PANGO_API extern zend_class_entry *php_pango_cairo_get_font_map_ce();
PHP_PANGO_API extern zend_class_entry* php_pango_cairo_get_layout_ce();
PHP_PANGO_API extern zend_class_entry* php_pango_cairo_get_layout_line_ce();
PHP_PANGO_API extern zend_class_entry* php_pango_cairo_get_glyph_string_ce();


extern pango_font_map_object *pango_cairo_font_map_fetch_object(zend_object *object);
#define Z_PANGO_CAIRO_FONT_MAP_P(zv) pango_cairo_font_map_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoFontMap *pango_cairo_font_map_object_get_font_map(zval *zv);

extern pango_layout_object *pango_cairo_layout_fetch_object(zend_object *object);
#define Z_PANGO_CAIRO_LAYOUT_P(zv) pango_cairo_layout_fetch_object(Z_OBJ_P(zv))

extern pango_layout_line_object *pango_cairo_layout_line_fetch_object(zend_object *object);
#define Z_PANGO_CAIRO_LAYOUT_LINE_P(zv) pango_cairo_layout_line_fetch_object(Z_OBJ_P(zv))

extern pango_glyph_string_object *pango_cairo_glyph_string_fetch_object(zend_object *object);
#define Z_PANGO_CAIRO_GLYPH_STRING_P(zv) pango_cairo_glyph_string_fetch_object(Z_OBJ_P(zv))

#endif /* PHP_PANGO_PANGO_CAIRO_FONT_MAP_H */
