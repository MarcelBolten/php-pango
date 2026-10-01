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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_exceptions.h>
#include <pango/pangocairo.h>
#include <php_cairo_internal.h>

#include "../../php_pango.h"
#include "../exception.h"
#include "../glyph_item.h"
#include "../layout.h"
#include "../layout_line.h"
#include "pango_cairo.h"
#include "pango_cairo_layout_line_arginfo.h"

zend_class_entry *pango_ce_pango_cairo_layout_line;

PHP_PANGO_API zend_class_entry* php_pango_cairo_get_layout_line_ce() {
    return pango_ce_pango_cairo_layout_line;
}

static zend_object_handlers pango_cairo_layout_line_object_handlers;

pango_layout_line_object *pango_cairo_layout_line_fetch_object(zend_object *object)
{
    return (pango_layout_line_object *) ((char*)(object) - offsetof(pango_layout_line_object, std));
}

/* {{{ Draws a PangoCairoLayoutLine in the specified cairo context. */
PHP_METHOD(PangoCairo_LayoutLine, show)
{
    pango_layout_line_object *layout_line_object;
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(ZEND_THIS);
    layout_object = Z_PANGO_LAYOUT_P(&layout_line_object->layout_zval);
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_show_layout_line(context_object->context, layout_line_object->line);
}
/* }}} */

/* {{{ Adds the specified text to the current path in the specified cairo context. */
PHP_METHOD(PangoCairo_LayoutLine, path)
{
    pango_layout_line_object *layout_line_object;
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(ZEND_THIS);
    layout_object = Z_PANGO_LAYOUT_P(&layout_line_object->layout_zval);
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_layout_line_path(context_object->context, layout_line_object->line);
}
/* }}} */

/** {{{ Returns the runs (glyph items) in the line, from left to right. */
PHP_METHOD(PangoCairo_LayoutLine, getRuns)
{
    zval *layout_line;
    GSList *runs;
    zval run_zv;
    pango_glyph_item_object *glyph_item_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line = ZEND_THIS;
    runs = Z_PANGO_LAYOUT_LINE_P(layout_line)->line->runs;

    array_init(return_value);
    for (GSList *run = runs; run != NULL; run = run->next) {
        object_init_ex(&run_zv, php_pango_get_glyph_item_ce());
        glyph_item_object = Z_PANGO_GLYPH_ITEM_P(&run_zv);
        glyph_item_object->glyph_item = pango_glyph_item_copy((PangoGlyphItem *)run->data);
        ZVAL_COPY(&glyph_item_object->layout_line_zv, layout_line);
        add_next_index_zval(return_value, &run_zv);
    }
}
/* }}} */


/* ----------------------------------------------------------------
    \PangoCairo\LayoutLine Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_cairo_layout_line_free_obj(zend_object *zobj)
{
    pango_layout_line_object *intern = pango_cairo_layout_line_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->line) {
        pango_layout_line_unref(intern->line);
    }

    zval_ptr_dtor(&intern->layout_zval);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_layout_line_obj_ctor(zend_class_entry *ce, pango_layout_line_object **intern)
{
    pango_layout_line_object *object = ecalloc(1, sizeof(pango_layout_line_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->layout_zval);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_cairo_layout_line_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_layout_line_create_object(zend_class_entry *ce)
{
    pango_layout_line_object *intern = NULL;
    zend_object *return_value = pango_cairo_layout_line_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_cairo_layout_line)
{
    memcpy(
        &pango_cairo_layout_line_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_cairo_layout_line_object_handlers.offset = offsetof(pango_layout_line_object, std);
    pango_cairo_layout_line_object_handlers.free_obj = pango_cairo_layout_line_free_obj;

    pango_ce_pango_cairo_layout_line = register_class_PangoCairo_LayoutLine(php_pango_get_layout_line_ce());
    pango_ce_pango_cairo_layout_line->create_object = pango_cairo_layout_line_create_object;

    return SUCCESS;
}
/* }}} */
