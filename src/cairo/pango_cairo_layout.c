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
#include "../layout.h"
#include "pango_cairo.h"
#include "pango_cairo_layout_arginfo.h"

zend_class_entry *pango_ce_pango_cairo_layout;

PHP_PANGO_API zend_class_entry* php_pango_cairo_get_layout_ce() {
    return pango_ce_pango_cairo_layout;
}

static zend_object_handlers pango_cairo_layout_object_handlers;

pango_layout_object *pango_cairo_layout_fetch_object(zend_object *object)
{
    return (pango_layout_object *) ((char*)(object) - offsetof(pango_layout_object, std));
}

/* {{{ Creates a PangoLayout based on the Cairo Context object */
PHP_METHOD(PangoCairo_Layout, __construct)
{
    zval *cairo_context_zval = NULL;
    cairo_context_object *cairo_context_object;
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(cairo_context_zval, php_cairo_get_context_ce())
    ZEND_PARSE_PARAMETERS_END();

    cairo_context_object = Z_CAIRO_CONTEXT_P(cairo_context_zval);

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    layout_object->layout = pango_cairo_create_layout(cairo_context_object->context);

    if (layout_object->layout == NULL) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
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
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_OBJ_COPY(Z_OBJ(Z_PANGO_LAYOUT_P(ZEND_THIS)->cairo_context_zv));
}
/* }}} */

/* {{{ Updates the private PangoContext of a PangoLayout to match the current transformation
       and target surface of a Cairo context. */
PHP_METHOD(PangoCairo_Layout, update)
{
    pango_layout_object *layout_object;
    cairo_context_object *cairo_context_object;
    zval *cairo_context_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    cairo_context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_update_layout(cairo_context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Draws a PangoLayoutLine in the specified cairo context. */
PHP_METHOD(PangoCairo_Layout, show)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_show_layout(context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Adds the specified text to the current path in the specified cairo context. */
PHP_METHOD(PangoCairo_Layout, path)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_layout_path(context_object->context, layout_object->layout);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
/* {{{ Adds components of a Layout to the current path in the specified cairo context. */
PHP_METHOD(PangoCairo_Layout, layoutPathForComponents)
{
    zend_long component;
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(component)
    ZEND_PARSE_PARAMETERS_END();

    if (component < 0 || component > PANGO_RENDER_COMPONENT_ALL) {
        zend_argument_value_error(1,
            "must be between 0 and %d but " ZEND_LONG_FMT " given",
            PANGO_RENDER_COMPONENT_ALL,
            component
        );
        RETURN_THROWS();
    }

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);

    pango_cairo_layout_path_for_components(
        context_object->context,
        layout_object->layout,
        (PangoRenderComponent) component
    );
}
/* }}} */
#endif

/* {{{ Returns a particular LayoutLine from the layout */
PHP_METHOD(PangoCairo_Layout, getLine)
{
    zval *layout;
    pango_layout_object *layout_object;
    zend_long line_number = 0;
    int line_count;
    PangoLayoutLine *layout_line;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(line_number)
    ZEND_PARSE_PARAMETERS_END();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);

    line_count = pango_layout_get_line_count(layout_object->layout);
    if (line_number < 0 || line_number >= line_count) {
        zend_argument_value_error(1, "must be between 0 and %d but %ld given", line_count - 1, line_number);
        RETURN_THROWS();
    }

    layout_line = pango_layout_get_line(layout_object->layout, (int) line_number);
    if (UNEXPECTED(!layout_line)) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_cairo_get_layout_line_ce());
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(return_value);
    layout_line_object->line = pango_layout_line_ref(layout_line);
    ZVAL_COPY(&layout_line_object->layout_zval, layout);
}

/* {{{ Returns a particular LayoutLine from the layout */
PHP_METHOD(PangoCairo_Layout, getLineReadonly)
{
    zval *layout;
    pango_layout_object *layout_object;
    zend_long line_number = 0;
    PangoLayoutLine *layout_line;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(line_number)
    ZEND_PARSE_PARAMETERS_END();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);

    if (!(layout_line = pango_layout_get_line_readonly(layout_object->layout, (int) line_number))) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_cairo_get_layout_line_ce());
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(return_value);
    layout_line_object->line = pango_layout_line_ref(layout_line);
    ZVAL_COPY(&layout_line_object->layout_zval, layout);
}

/* {{{ Returns an array of LayoutLines representing each line of the layout */
PHP_METHOD(PangoCairo_Layout, getLines)
{
    zval *layout;
    pango_layout_object *layout_object;
    GSList *lines;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (GSList *line = lines; line != NULL; line = line->next) {
        object_init_ex(&line_zv, php_pango_cairo_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)line->data);
        ZVAL_COPY(&line_object->layout_zval, layout);

        add_next_index_zval(return_value, &line_zv);
    }
}
/* }}} */

/* {{{ Returns an array of LayoutLines representing each line of the layout */
PHP_METHOD(PangoCairo_Layout, getLinesReadonly)
{
    zval *layout;
    pango_layout_object *layout_object;
    GSList *lines;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines_readonly(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (GSList *line = lines; line != NULL; line = line->next) {
        object_init_ex(&line_zv, php_pango_cairo_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)line->data);
        ZVAL_COPY(&line_object->layout_zval, layout);

        add_next_index_zval(return_value, &line_zv);
    }
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

    pango_cairo_layout_object_handlers.offset = offsetof(pango_layout_object, std);
    pango_cairo_layout_object_handlers.free_obj = pango_cairo_layout_free_obj;

    pango_ce_pango_cairo_layout = register_class_PangoCairo_Layout(php_pango_get_layout_ce());
    pango_ce_pango_cairo_layout->create_object = pango_cairo_layout_create_object;

    return SUCCESS;
}
/* }}} */
