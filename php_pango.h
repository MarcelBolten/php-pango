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

/* $Id: header 252479 2008-02-07 19:39:50Z iliaa $ */

#ifndef PHP_PANGO_H
#define PHP_PANGO_H

#define PHP_PANGO_VERSION "0.1.0-dev"

extern zend_module_entry pango_module_entry;
#define phpext_pango_ptr &pango_module_entry

extern zend_class_entry *pango_ce_pangoexception;

/* TODO: Move this elsewhere */
extern zend_class_entry *pango_ce_pangofontdescription;

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
#include "php_cairo_api.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_context_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_layoutline_ce();
PHP_PANGO_API extern zval* php_pango_make_layoutline_zval(PangoLayoutLine *line, zval *layout _DC);

/* Objects */
typedef struct _pango_context_object {
    zend_object std;
    PangoContext *context;
} pango_context_object;

typedef struct _pango_layout_object {
    zend_object std;
    PangoLayout *layout;
    zval *cairo_context;
    zval *pango_context;
} pango_layout_object;

typedef struct _pango_fontdesc_object {
    zend_object std;
    PangoFontDescription *fontdesc;
} pango_fontdesc_object;

typedef struct _pango_item_object {
    zend_object std;
    PangoItem *item;
} pango_item_object;

typedef struct _pango_layoutline_object {
    zend_object std;
    PangoLayoutLine *line;
    zval *layout_zval;
} pango_layoutline_object;

PHP_MINIT_FUNCTION(pango);
PHP_MSHUTDOWN_FUNCTION(pango);
PHP_MINFO_FUNCTION(pango);

PHP_MINIT_FUNCTION(pango_error);
PHP_MINIT_FUNCTION(pango_context);
PHP_MINIT_FUNCTION(pango_layout);
PHP_MINIT_FUNCTION(pango_font);
PHP_MINIT_FUNCTION(pango_line);

PHP_FUNCTION(pango_version);
PHP_FUNCTION(pango_version_string);

/* PangoLayout functions */
PHP_FUNCTION(pango_layout_new);
PHP_FUNCTION(pango_cairo_update_layout);
PHP_FUNCTION(pango_cairo_show_layout);
PHP_FUNCTION(pango_cairo_show_path);
#ifdef PANGO_VERSION
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 6, 0)
PHP_FUNCTION(pango_context_set_base_gravity);
PHP_FUNCTION(pango_context_get_base_gravity);
PHP_FUNCTION(pango_context_get_gravity);
PHP_FUNCTION(pango_context_set_gravity_hint);
PHP_FUNCTION(pango_context_get_gravity_hint);
#endif
#endif
PHP_FUNCTION(pango_layout_get_context);
PHP_FUNCTION(pango_layout_set_text);
PHP_FUNCTION(pango_layout_get_text);
PHP_FUNCTION(pango_layout_set_markup);
PHP_FUNCTION(pango_layout_get_width);
PHP_FUNCTION(pango_layout_get_height);
PHP_FUNCTION(pango_layout_get_size);
PHP_FUNCTION(pango_layout_get_pixel_size);
PHP_FUNCTION(pango_layout_get_extents);
PHP_FUNCTION(pango_layout_get_pixel_extents);
PHP_FUNCTION(pango_layout_set_width);
PHP_FUNCTION(pango_layout_set_height);
PHP_FUNCTION(pango_layout_set_font_description);
PHP_FUNCTION(pango_layout_get_font_description);
PHP_FUNCTION(pango_layout_get_alignment);
PHP_FUNCTION(pango_layout_set_alignment);
PHP_FUNCTION(pango_layout_get_justify);
PHP_FUNCTION(pango_layout_set_justify);
PHP_FUNCTION(pango_layout_get_wrap);
PHP_FUNCTION(pango_layout_set_wrap);
PHP_FUNCTION(pango_layout_is_wrapped);
PHP_FUNCTION(pango_layout_get_indent);
PHP_FUNCTION(pango_layout_set_indent);
PHP_FUNCTION(pango_layout_get_spacing);
PHP_FUNCTION(pango_layout_set_spacing);
PHP_FUNCTION(pango_layout_set_ellipsize);
PHP_FUNCTION(pango_layout_get_ellipsize);
PHP_FUNCTION(pango_layout_is_ellipsized);
PHP_FUNCTION(pango_layout_get_lines);
PHP_FUNCTION(pango_layout_get_line);
PHP_FUNCTION(pango_layout_get_line_count);
PHP_FUNCTION(pango_layout_context_changed);

/* PangoLayoutLine functions */
PHP_FUNCTION(pango_layout_line_get_extents);
PHP_FUNCTION(pango_layout_line_get_pixel_extents);
PHP_FUNCTION(pango_cairo_show_layout_line);

/* PangoFontDescription functions */
PHP_FUNCTION(pango_font_description_new);
PHP_FUNCTION(pango_font_description_get_variant);
PHP_FUNCTION(pango_font_description_set_variant);
PHP_FUNCTION(pango_font_description_equal);
PHP_FUNCTION(pango_font_description_set_family);
PHP_FUNCTION(pango_font_description_get_family);
PHP_FUNCTION(pango_font_description_set_size);
PHP_FUNCTION(pango_font_description_get_size);
PHP_FUNCTION(pango_font_description_get_style);
PHP_FUNCTION(pango_font_description_set_style);
PHP_FUNCTION(pango_font_description_get_weight);
PHP_FUNCTION(pango_font_description_set_weight);
PHP_FUNCTION(pango_font_description_get_stretch);
PHP_FUNCTION(pango_font_description_set_stretch);
PHP_FUNCTION(pango_font_description_to_string);

/*
 * Declare any global variables you may need between the BEGIN
 * and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(pango)
    long global_value;
    char *global_string;
ZEND_END_MODULE_GLOBALS(pango)
*/

#ifdef ZTS
#define PANGO_G(v) TSRMG(pango_globals_id, zend_pango_globals *, v)
#else
#define PANGO_G(v) (pango_globals.v)
#endif

/* refcount macros */
#ifndef Z_ADDREF_P
#define Z_ADDREF_P(pz)                (pz)->refcount++
#endif

#ifndef Z_DELREF_P
#define Z_DELREF_P(pz)                (pz)->refcount--
#endif

#ifndef Z_SET_REFCOUNT_P
#define Z_SET_REFCOUNT_P(pz, rc)      (pz)->refcount = rc
#endif

#endif /* PHP_PANGO_H */
