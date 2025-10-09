/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors:  Michael Maclean <mgdm@php.net>                             |
  |           David Marín <davefx@gmail.com>                             |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_PANGO_H
#define PHP_PANGO_H

#define PHP_PANGO_VERSION "0.2.0-dev"

extern zend_module_entry pango_module_entry;
#define phpext_pango_ptr &pango_module_entry

extern zend_class_entry *pango_ce_pango_exception;
extern zend_object_handlers pango_std_object_handlers;

#ifdef PHP_WIN32
#    define PHP_PANGO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#    define PHP_PANGO_API __attribute__ ((visibility("default")))
#else
#    define PHP_PANGO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include <pango/pango.h>
#include <pango/pangocairo.h>
#include "src/php_cairo_internal.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_context_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_direction_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_layout_line_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_font_description_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_layout_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_glyph_item_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_item_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_glyph_string_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_glyph_info_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_matrix_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_rectangle_ce();

/* Objects */
typedef struct _pango_context_object {
    PangoContext *context;
    zval cairo_context_zv;
    zend_object std;
} pango_context_object;
extern pango_context_object *pango_context_fetch_object(zend_object *object);
#define Z_PANGO_CONTEXT_P(zv) pango_context_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_layout_object {
    PangoLayout *layout;
    zval cairo_context_zv;
    zval pango_context_zv;
    zend_object std;
} pango_layout_object;
extern pango_layout_object *pango_layout_fetch_object(zend_object *object);
#define Z_PANGO_LAYOUT_P(zv) pango_layout_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_font_description_object {
    PangoFontDescription *font_description;
    zend_object std;
} pango_font_description_object;
extern pango_font_description_object *pango_font_description_fetch_object(zend_object *object);
#define Z_PANGO_FONT_DESC_P(zv) pango_font_description_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_layout_line_object {
    PangoLayoutLine *line;
    zval layout_zval;
    zend_object std;
} pango_layout_line_object;
extern pango_layout_line_object *pango_layout_line_fetch_object(zend_object *object);
#define Z_PANGO_LAYOUT_LINE_P(zv) pango_layout_line_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_glyph_item_object {
    PangoGlyphItem *glyph_item;
    zval layout_line_zv;
    zend_object std;
} pango_glyph_item_object;
extern pango_glyph_item_object *pango_glyph_item_fetch_object(zend_object *object);
#define Z_PANGO_GLYPH_ITEM_P(zv) pango_glyph_item_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_item_object {
    PangoItem *item;
    zval glyph_item_zv;
    zend_object std;
} pango_item_object;
extern pango_item_object *pango_item_fetch_object(zend_object *object);
#define Z_PANGO_ITEM_P(zv) pango_item_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_glyph_string_object {
    PangoGlyphString *glyph_string;
    zval glyph_item_zv;
    zend_object std;
} pango_glyph_string_object;
extern pango_glyph_string_object *pango_glyph_string_fetch_object(zend_object *object);
#define Z_PANGO_GLYPH_STRING_P(zv) pango_glyph_string_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_glyph_info_object {
    PangoGlyphInfo *glyph_info;
    zval glyph_string_zv;
    zend_object std;
} pango_glyph_info_object;
extern pango_glyph_info_object *pango_glyph_info_fetch_object(zend_object *object);
#define Z_PANGO_GLYPH_INFO_P(zv) pango_glyph_info_fetch_object(Z_OBJ_P(zv))

typedef struct _pango_matrix_object {
    PangoMatrix *matrix;
    zend_object std;
} pango_matrix_object;
extern pango_matrix_object *pango_matrix_fetch_object(zend_object *object);
#define Z_PANGO_MATRIX_P(zv) pango_matrix_fetch_object(Z_OBJ_P(zv))
extern PangoMatrix *pango_matrix_object_get_matrix(zval *zv);

typedef struct _pango_rectangle_object {
    PangoRectangle *rect;
    zend_object std;
} pango_rectangle_object;
extern pango_rectangle_object *pango_rectangle_fetch_object(zend_object *object);
#define Z_PANGO_RECTANGLE_P(zv) pango_rectangle_fetch_object(Z_OBJ_P(zv))
extern PangoRectangle *pango_rectangle_object_get_rectangle(zval *zv);

PHP_MINIT_FUNCTION(pango);
PHP_MSHUTDOWN_FUNCTION(pango);
PHP_MINFO_FUNCTION(pango);

PHP_MINIT_FUNCTION(pango_exception);
PHP_MINIT_FUNCTION(pango_context);
PHP_MINIT_FUNCTION(pango_layout);
PHP_MINIT_FUNCTION(pango_font_description);
PHP_MINIT_FUNCTION(pango_layout_line);
PHP_MINIT_FUNCTION(pango_glyph_item);
PHP_MINIT_FUNCTION(pango_item);
PHP_MINIT_FUNCTION(pango_glyph_string);
PHP_MINIT_FUNCTION(pango_glyph_info);
PHP_MINIT_FUNCTION(pango_matrix);
PHP_MINIT_FUNCTION(pango_rectangle);

#ifdef ZTS
#define PANGO_G(v) TSRMG(pango_globals_id, zend_pango_globals *, v)
#else
#define PANGO_G(v) (pango_globals.v)
#endif

#endif /* PHP_PANGO_H */
