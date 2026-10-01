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
#include "php_pango_macros.h"
#include "font.h"
#include "language.h"
#include "font_set.h"
#include "font_set_simple.h"
#include "font_set_simple_arginfo.h"

zend_class_entry *pango_ce_pango_font_set_simple;

static zend_object_handlers pango_font_set_simple_object_handlers;

pango_font_set_simple_object *pango_font_set_simple_fetch_object(zend_object *object)
{
    return (pango_font_set_simple_object *) ((char*)(object) - offsetof(pango_font_set_simple_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_set_simple_ce()
{
    return pango_ce_pango_font_set_simple;
}

PHP_PANGO_API PangoFontsetSimple* pango_font_set_simple_object_get_font_set_simple(zval *zv)
{
    pango_font_set_simple_object *obj = Z_PANGO_FONT_SET_SIMPLE_P(zv);
    return obj->font_set_simple;
}

/* {{{ Creates a new Pango\FontSetSimple object for the given Pango\Language. */
PHP_METHOD(Pango_FontSetSimple, __construct)
{
    zval *language_zv;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    Z_PANGO_FONT_SET_SIMPLE_P(ZEND_THIS)->font_set_simple = pango_fontset_simple_new(
        Z_PANGO_LANGUAGE_P(language_zv)->language
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontSetSimple, append)
{
    PangoFontsetSimple* font_set_simple;
    zval *font_zv;
    PangoFont* font;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_zv, php_pango_get_font_ce())
    ZEND_PARSE_PARAMETERS_END();

    font_set_simple = pango_font_set_simple_object_get_font_set_simple(ZEND_THIS);
    font = pango_font_object_get_font(font_zv);

    pango_fontset_simple_append(
        font_set_simple,
        g_object_ref(font)
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\FontSetSimple Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_set_simple_free_obj(zend_object *zobj)
{
    pango_font_set_simple_object *intern = pango_font_set_simple_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_set_simple) {
        g_object_unref(intern->font_set_simple);
        intern->font_set_simple = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_set_simple_obj_ctor(zend_class_entry *ce, pango_font_set_simple_object **intern)
{
    pango_font_set_simple_object *object = ecalloc(1, sizeof(pango_font_set_simple_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_set_simple_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_set_simple_create_object(zend_class_entry *ce)
{
    pango_font_set_simple_object *intern = NULL;
    zend_object *return_value = pango_font_set_simple_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_font_set_simple_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_font_set_simple_object *font_set_simple_object = pango_font_set_simple_fetch_object(object);

    if (!font_set_simple_object->font_set_simple) {
        return zend_std_read_property(object, member, type, cache_slot, rv);
    }

    PangoFontsetSimple *font_set_simple = font_set_simple_object->font_set_simple;

    PANGO_LONG_VALUE_FROM_STRUCT(pango_fontset_simple_size(font_set_simple), size);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_font_set_simple_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    /* used in macros below */
    zval tmp;
    pango_font_set_simple_object *font_set_simple_object = pango_font_set_simple_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!font_set_simple_object->font_set_simple) {
        return props;
    }

    PangoFontsetSimple *font_set_simple = font_set_simple_object->font_set_simple;

    PANGO_ADD_STRUCT_LONG_VALUE(pango_fontset_simple_size(font_set_simple), size);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_set_simple)
{
    memcpy(
        &pango_font_set_simple_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_set_simple_object_handlers.offset = offsetof(pango_font_set_simple_object, std);
    pango_font_set_simple_object_handlers.free_obj = pango_font_set_simple_free_obj;
    pango_font_set_simple_object_handlers.read_property = pango_font_set_simple_object_read_property;
    pango_font_set_simple_object_handlers.get_properties_for = pango_font_set_simple_object_get_properties_for;

    pango_ce_pango_font_set_simple = register_class_Pango_FontSetSimple(php_pango_get_font_set_ce());
    pango_ce_pango_font_set_simple->create_object = pango_font_set_simple_create_object;

    return SUCCESS;
}
/* }}} */
