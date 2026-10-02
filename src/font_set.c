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
  | Author: Marcel Bolten <github@marcelbolten.de>                       |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "exception.h"
#include "font_metrics.h"
#include "font.h"
#include "font_set.h"
#include "font_set_arginfo.h"

zend_class_entry *pango_ce_pango_font_set;

static zend_object_handlers pango_font_set_object_handlers;

pango_font_set_object *pango_font_set_fetch_object(zend_object *object)
{
    return (pango_font_set_object *) ((char*)(object) - offsetof(pango_font_set_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_set_ce(void)
{
    return pango_ce_pango_font_set;
}

PHP_PANGO_API PangoFontset* pango_font_set_object_get_font_set(zval *zv)
{
    pango_font_set_object *obj = Z_PANGO_FONT_SET_P(zv);
    return obj->font_set;
}

typedef struct _php_pango_filter_ctx {
    zend_fcall_info *fci;
    zend_fcall_info_cache *fci_cache;
    bool failed;
    PangoFont *result;
} php_pango_filter_ctx;

static gboolean pango_font_set_find_callback(PangoFontset* fontset, PangoFont* font, gpointer user_data)
{
    php_pango_filter_ctx *ctx = (php_pango_filter_ctx *)user_data;
    zval arg;
    zval retval;
    gboolean result = FALSE;

    object_init_ex(&arg, php_pango_get_font_ce());
    Z_PANGO_FONT_P(&arg)->font = g_object_ref(font);

    ctx->fci->params = &arg;
    ctx->fci->param_count = 1;
    ctx->fci->retval = &retval;

    if (zend_call_function(ctx->fci, ctx->fci_cache) == FAILURE) {
        ctx->failed = true;
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Failed to invoke filter callback",
            0
        );
        goto cleanup;
    }

    /* The PHP callback itself may have thrown, don't try to interpret
     * garbage/undef retval as a bool, and don't stack a second exception
     * on top of it. */
    if (EG(exception)) {
        ctx->failed = true;
        goto cleanup;
    }

    if (Z_TYPE(retval) != IS_TRUE
        && Z_TYPE(retval) != IS_FALSE
    ) {
        ctx->failed = true;
        zend_throw_exception(
            zend_ce_type_error,
            "Pango\\FontSet::find(): Argument #1 ($callback) must return a boolean value",
            0
        );
        goto cleanup;
    }

    result = (Z_TYPE(retval) == IS_TRUE);
    if (result) {
        ctx->result = g_object_ref(font);
    }

cleanup:
    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&arg);

    // If the callback failed, stop the iteration and propagate the exception.
    return ctx->failed ? TRUE : result;
}

/* {{{ Iterates through all the fonts in a fontset, calling func for each one.
       If func returns TRUE, that stops the iteration. */
PHP_METHOD(Pango_FontSet, find)
{
    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fci_cache = empty_fcall_info_cache;
    php_pango_filter_ctx ctx;
    PangoFontset* font_set;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_FUNC(fci, fci_cache)
    ZEND_PARSE_PARAMETERS_END();

    ctx.fci = &fci;
    ctx.fci_cache = &fci_cache;
    ctx.failed = false;
    ctx.result = NULL;

    pango_fontset_foreach(
        pango_font_set_object_get_font_set(ZEND_THIS),
        pango_font_set_find_callback,
        &ctx
    );

    /* If the PHP callback (or our own type-check) threw, propagate it
     * rather than returning a bogus AttrList/null. */
    if (EG(exception)) {
        if (ctx.result) {
            g_object_unref(ctx.result);
        }
        RETURN_THROWS();
    }

    if (!ctx.result) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_ce());
    Z_PANGO_FONT_P(return_value)->font = ctx.result;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontSet, getFont)
{
    PangoFontset* font_set;
    zend_string *letter;
    PangoFont* font;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(letter)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(letter)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    font = pango_fontset_get_font(
        pango_font_set_object_get_font_set(ZEND_THIS),
        g_utf8_get_char(ZSTR_VAL(letter))
    );

    object_init_ex(return_value, php_pango_get_font_ce());
    Z_PANGO_FONT_P(return_value)->font = font;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontSet, getFontForCodepoint)
{
    PangoFontset* font_set;
    zend_long codepoint;
    PangoFont* font;
    pango_font_object *font_obj;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(codepoint)
    ZEND_PARSE_PARAMETERS_END();

    font_set = pango_font_set_object_get_font_set(ZEND_THIS);
    font = pango_fontset_get_font(font_set, codepoint);

    object_init_ex(return_value, php_pango_get_font_ce());
    font_obj = Z_PANGO_FONT_P(return_value);
    font_obj->font = font;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontSet, getMetrics)
{
    PangoFontset* font_set;
    PangoFontMetrics* font_metrics;
    pango_font_metrics_object *metrics_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font_set = pango_font_set_object_get_font_set(ZEND_THIS);
    font_metrics = pango_fontset_get_metrics(font_set);

    object_init_ex(return_value, php_pango_get_font_metrics_ce());
    metrics_obj = Z_PANGO_FONT_METRICS_P(return_value);
    metrics_obj->font_metrics = font_metrics;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\FontSet Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_set_free_obj(zend_object *zobj)
{
    pango_font_set_object *intern = pango_font_set_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_set) {
        g_object_unref(intern->font_set);
        intern->font_set = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_set_obj_ctor(zend_class_entry *ce, pango_font_set_object **intern)
{
    pango_font_set_object *object = ecalloc(1, sizeof(pango_font_set_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_set_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_set_create_object(zend_class_entry *ce)
{
    pango_font_set_object *intern = NULL;
    zend_object *return_value = pango_font_set_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_set)
{
    memcpy(
        &pango_font_set_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_set_object_handlers.offset = offsetof(pango_font_set_object, std);
    pango_font_set_object_handlers.free_obj = pango_font_set_free_obj;

    pango_ce_pango_font_set = register_class_Pango_FontSet();
    pango_ce_pango_font_set->create_object = pango_font_set_create_object;

    return SUCCESS;
}
/* }}} */
