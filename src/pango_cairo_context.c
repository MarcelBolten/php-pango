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
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_pango.h"
#include "pango_cairo_context_arginfo.h"

zend_class_entry *pango_ce_pango_cairo_context;

PHP_PANGO_API zend_class_entry* php_pango_cairo_get_context_ce() {
    return pango_ce_pango_cairo_context;
}

static zend_object_handlers pango_cairo_context_object_handlers;

pango_context_object *pango_cairo_context_fetch_object(zend_object *object)
{
    return (pango_context_object *) ((char*)(object) - XtOffsetOf(pango_context_object, std));
}

/* {{{ Creates a context object set up to match the current transformation and target surface of the Cairo context. */
PHP_METHOD(PangoCairo_Context, __construct)
{
    pango_context_object *context_object;
    zval *cairo_context_zv;
    cairo_context_object *cairo_context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(cairo_context_zv, php_cairo_get_context_ce())
    ZEND_PARSE_PARAMETERS_END();

    cairo_context_object = Z_CAIRO_CONTEXT_P(cairo_context_zv);

    context_object = Z_PANGO_CONTEXT_P(getThis());
    context_object->context = pango_cairo_create_context(cairo_context_object->context);

    // store the cairo context zv in the pango context object to keep a reference
    // cairo_reference(cairo_context_object->context);
    ZVAL_COPY(&context_object->cairo_context_zv, cairo_context_zv);
}
/* }}} */

/* {{{ Gets the Cairo context associated with this Context. */
PHP_METHOD(PangoCairo_Context, getCairoContext)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    RETURN_COPY(&context_object->cairo_context_zv);
}
/* }}} */

/* {{{ Gets the Cairo context associated with this Context. */
PHP_METHOD(PangoCairo_Context, getFontOptions)
{
    pango_context_object *context_object;
    const cairo_font_options_t* font_options;
    cairo_font_options_object *font_options_object;


    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    font_options = pango_cairo_context_get_font_options(context_object->context);
    if (!font_options) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_cairo_get_fontoptions_ce());
    font_options_object = Z_CAIRO_FONT_OPTIONS_P(return_value);
    font_options_object->font_options = cairo_font_options_copy(font_options);
}
/* }}} */

/* {{{ Sets the font options used when rendering text with this context. */
PHP_METHOD(PangoCairo_Context, setFontOptions)
{
    pango_context_object *context_object;
    zval *font_options_zv;
    cairo_font_options_object *font_options_object;
    const cairo_font_options_t *font_options = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_options_zv, php_cairo_get_fontoptions_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    if (font_options_zv && Z_TYPE_P(font_options_zv) != IS_NULL) {
        font_options_object = Z_CAIRO_FONT_OPTIONS_P(font_options_zv);
        font_options = font_options_object->font_options;
    }

    pango_cairo_context_set_font_options(context_object->context, font_options);
    // TODO: store the font options object in the pango context object to keep a reference?
    // it should be returned by getFontOptions()
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_Context, getResolution)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    RETURN_DOUBLE(pango_cairo_context_get_resolution(context_object->context));
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_Context, setResolution)
{
    pango_context_object *context_object;
    double resolution;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(resolution)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    pango_cairo_context_set_resolution(context_object->context, resolution);
}
/* }}} */

/* {{{ Updates the Context previously created for use with Cairo
       to match the current transformation and target surface of the Cairo context used to create it. */
PHP_METHOD(PangoCairo_Context, updateContext)
{
    pango_context_object *pango_context_object;
    cairo_context_object *cairo_context_object;
    zval *cairo_context_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_context_object = Z_PANGO_CONTEXT_P(getThis());
    cairo_context_object = Z_CAIRO_CONTEXT_P(&pango_context_object->cairo_context_zv);
    pango_cairo_update_context(cairo_context_object->context, pango_context_object->context);
}
/* }}} */


/* ----------------------------------------------------------------
    \Pango\Context Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_context_free_obj(zend_object *zobj)
{
    pango_context_object *intern = pango_context_fetch_object(zobj);

    if (!intern) {
        return;
    }

    zval_ptr_dtor(&intern->cairo_context_zv);

    if (intern->context) {
        g_object_unref(intern->context);
    }

    zend_object_std_dtor(&intern->std);
}

/* {{{ */
static zend_object* pango_context_obj_ctor(zend_class_entry *ce, pango_context_object **intern)
{
    pango_context_object *object = ecalloc(1, sizeof(pango_context_object) + zend_object_properties_size(ce));

    object->context = NULL;
    ZVAL_UNDEF(&object->cairo_context_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_cairo_context_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_context_create_object(zend_class_entry *ce)
{
    pango_context_object *intern = NULL;
    zend_object *return_value = pango_context_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_cairo_context)
{
    memcpy(
        &pango_cairo_context_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_cairo_context_object_handlers.offset = XtOffsetOf(pango_context_object, std);
    pango_cairo_context_object_handlers.free_obj = pango_context_free_obj;

    pango_ce_pango_cairo_context = register_class_PangoCairo_Context(php_pango_get_context_ce());
    pango_ce_pango_cairo_context->create_object = pango_context_create_object;

    return SUCCESS;
}
/* }}} */
