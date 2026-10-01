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

#ifndef PHP_PANGO_GLYPH_STRING_H
#define PHP_PANGO_GLYPH_STRING_H

#include <php.h>
#include <pango/pango.h>
#include "../php_pango.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_glyph_string_ce();

typedef struct _pango_glyph_string_object {
    PangoGlyphString *glyph_string;
    zval glyph_item_zv;
    zend_object std;
} pango_glyph_string_object;
extern pango_glyph_string_object *pango_glyph_string_fetch_object(zend_object *object);
#define Z_PANGO_GLYPH_STRING_P(zv) pango_glyph_string_fetch_object(Z_OBJ_P(zv))

static void pango_glyph_string_free_obj(zend_object *zobj);
static zend_object* pango_glyph_string_create_object(zend_class_entry *ce);
static zval *pango_glyph_string_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv);
static HashTable *pango_glyph_string_get_properties_for(zend_object *object, zend_prop_purpose purpose);

#endif /* PHP_PANGO_GLYPH_STRING_H */
