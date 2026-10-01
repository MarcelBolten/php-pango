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
#include "font_metrics.h"
#include "font_metrics_arginfo.h"

zend_class_entry *pango_ce_pango_font_metrics;

static zend_object_handlers pango_font_metrics_object_handlers;

pango_font_metrics_object *pango_font_metrics_fetch_object(zend_object *object)
{
    return (pango_font_metrics_object *) ((char*)(object) - offsetof(pango_font_metrics_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_metrics_ce()
{
    return pango_ce_pango_font_metrics;
}

PHP_PANGO_API PangoFontMetrics* pango_font_metrics_object_get_font_metrics(zval *zv)
{
    return Z_PANGO_FONT_METRICS_P(zv)->font_metrics;
}

#define PANGO_FONT_METRICS_GETTER(_getter) \
    ZEND_PARSE_PARAMETERS_NONE(); \
    RETURN_LONG(_getter(pango_font_metrics_object_get_font_metrics(ZEND_THIS)));

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getApproximateCharWidth)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_approximate_char_width);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getApproximateDigitWidth)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_approximate_digit_width);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getAscent)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_ascent);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getDescent)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_descent);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getHeight)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_height);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getStrikethroughPosition)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_strikethrough_position);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getStrikethroughThickness)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_strikethrough_thickness);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getUnderlinePosition)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_underline_position);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontMetrics, getUnderlineThickness)
{
    PANGO_FONT_METRICS_GETTER(pango_font_metrics_get_underline_thickness);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\FontMetrics Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_metrics_free_obj(zend_object *zobj)
{
    pango_font_metrics_object *intern = pango_font_metrics_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_metrics) {
        pango_font_metrics_unref(intern->font_metrics);
        intern->font_metrics = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_metrics_obj_ctor(zend_class_entry *ce, pango_font_metrics_object **intern)
{
    pango_font_metrics_object *object = ecalloc(1, sizeof(pango_font_metrics_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_metrics_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_metrics_create_object(zend_class_entry *ce)
{
    pango_font_metrics_object *intern = NULL;
    zend_object *return_value = pango_font_metrics_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_metrics)
{
    memcpy(
        &pango_font_metrics_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_metrics_object_handlers.offset = offsetof(pango_font_metrics_object, std);
    pango_font_metrics_object_handlers.free_obj = pango_font_metrics_free_obj;

    pango_ce_pango_font_metrics = register_class_Pango_FontMetrics();
    pango_ce_pango_font_metrics->create_object = pango_font_metrics_create_object;

    return SUCCESS;
}
/* }}} */
