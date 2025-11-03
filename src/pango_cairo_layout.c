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

#include "php.h"
#include "php_pango.h"
#include "pango_cairo_layout_arginfo.h"

#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_cairo_layout;

PHP_PANGO_API zend_class_entry* php_pango_cairo_get_layout_ce() {
    return pango_ce_pango_cairo_layout;
}

static zend_object_handlers pango_cairo_layout_object_handlers;

pango_layout_object *pango_cairo_layout_fetch_object(zend_object *object)
{
    return (pango_layout_object *) ((char*)(object) - XtOffsetOf(pango_layout_object, std));
}

/* {{{ Creates a PangoLayout based on the Cairo Context object */
PHP_METHOD(PangoCairo_Layout, __construct)
{
    zval *cairo_context_zval = NULL;
    cairo_context_object *cairo_context_object;
    pango_layout_object *layout_object;
    PangoFontMap *font_map;
    PangoContext *context;
    PangoLayout *layout;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(cairo_context_zval, php_cairo_get_context_ce())
    ZEND_PARSE_PARAMETERS_END();

    cairo_context_object = Z_CAIRO_CONTEXT_P(cairo_context_zval);

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    // TODO: dont use pango_cairo_create_layout but create our own layout based on a pango context and a font map
    // layout_object->layout = pango_cairo_create_layout(cairo_context_object->context);

    // create a default font map if it does not exist yet
    pango_initialize_default_font_map();

    font_map = PANGO_G(default_font_map);
    context = pango_font_map_create_context(font_map);
    pango_cairo_update_context(cairo_context_object->context, context);
    layout = pango_layout_new(context);
    g_object_unref(context);
    layout_object->layout = layout;

    if (layout_object->layout == NULL) {
        zend_throw_exception(
            pango_ce_pango_exception,
            "Could not create the Pango layout",
            0
        );
        RETURN_THROWS();
    }

    ZVAL_COPY(&layout_object->cairo_context_zv, cairo_context_zval);
}
/* }}} */

/* {{{ Return the Cairo Context for the current layout */
PHP_METHOD(PangoCairo_Layout, getCairoContext)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    RETURN_ZVAL(&layout_object->cairo_context_zv, 1, 0);
}
/* }}} */


/* {{{ Updates the private PangoContext of a PangoLayout to match the current transformation
       and target surface of a Cairo context. */
PHP_METHOD(PangoCairo_Layout, updateLayout)
{
    pango_layout_object *layout_object;
    cairo_context_object *cairo_context_object;
    zval *cairo_context_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    cairo_context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_update_layout(cairo_context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Draws a PangoLayoutLine in the specified cairo context. */
PHP_METHOD(PangoCairo_Layout, showLayout)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_show_layout(context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Adds the specified text to the current path in the specified cairo context. */
PHP_METHOD(PangoCairo_Layout, layoutPath)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_layout_path(context_object->context, layout_object->layout);
}
/* }}} */


/* ----------------------------------------------------------------
    \Pango\Layout Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_cairo_layout_free_obj(zend_object *zobj)
{
    pango_layout_object *intern = pango_cairo_layout_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->layout) {
        g_object_unref(intern->layout);
    }

    zval_ptr_dtor(&intern->pango_context_zv);
    zval_ptr_dtor(&intern->cairo_context_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_layout_obj_ctor(zend_class_entry *ce, pango_layout_object **intern)
{
    pango_layout_object *object = ecalloc(1, sizeof(pango_layout_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->cairo_context_zv);
    ZVAL_UNDEF(&object->pango_context_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_cairo_layout_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_layout_create_object(zend_class_entry *ce)
{
    pango_layout_object *intern = NULL;
    zend_object *return_value = pango_cairo_layout_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_cairo_layout)
{
    memcpy(
        &pango_cairo_layout_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_cairo_layout_object_handlers.offset = XtOffsetOf(pango_layout_object, std);
    pango_cairo_layout_object_handlers.free_obj = pango_cairo_layout_free_obj;

    pango_ce_pango_cairo_layout = register_class_PangoCairo_Layout(php_pango_get_layout_ce());
    pango_ce_pango_cairo_layout->create_object = pango_cairo_layout_create_object;

    return SUCCESS;
}
/* }}} */
