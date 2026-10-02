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
  | Authors: Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "context.h"
#include "language.h"
#include "script.h"
#include "script_arginfo.h"
#include "script_iter_arginfo.h"

zend_class_entry *pango_ce_pango_script;
zend_class_entry *pango_ce_pango_script_iter;

static zend_object_handlers pango_script_iter_object_handlers;

PHP_PANGO_API extern zend_class_entry* php_pango_get_script_iter_ce(void)
{
    return pango_ce_pango_script_iter;
}

PHP_PANGO_API extern zend_class_entry* php_pango_get_script_ce(void)
{
    return pango_ce_pango_script;
}

pango_script_iter_object *pango_script_iter_fetch_object(zend_object *object)
{
    return (pango_script_iter_object *) ((char*)(object) - offsetof(pango_script_iter_object, std));
}

PHP_PANGO_API PangoScriptIter *pango_script_iter_object_get_script_iter(zval *zv)
{
    return Z_PANGO_SCRIPT_ITER_P(zv)->script_iter;
}

/* {{{ */
PHP_METHOD(Pango_ScriptIter, __construct)
{
    zend_string *text;
    pango_script_iter_object *script_iter_obj;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    script_iter_obj = Z_PANGO_SCRIPT_ITER_P(ZEND_THIS);
    script_iter_obj->text = zend_string_copy(text);

    script_iter_obj->script_iter = pango_script_iter_new(
        ZSTR_VAL(script_iter_obj->text),
        (int) ZSTR_LEN(script_iter_obj->text)
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_ScriptIter, getRange)
{
    pango_script_iter_object *script_iter_obj;
    const char *start, *end;
    PangoScript script;
    zend_long byte_start, byte_end;
    zend_string *range_text;
    zend_object *script_case_obj;
    zval script_case_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    script_iter_obj = Z_PANGO_SCRIPT_ITER_P(ZEND_THIS);

    pango_script_iter_get_range(script_iter_obj->script_iter,
        &start, &end, &script
    );

    byte_start = (zend_long)(start - ZSTR_VAL(script_iter_obj->text));
    byte_end = (zend_long)(end - ZSTR_VAL(script_iter_obj->text));
    range_text = zend_string_init(start, end - start, 0);

    object_init_ex(return_value, php_pango_get_script_iter_range_ce());

    zend_update_property_str(Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "text", sizeof("text")-1, range_text
    );
    zend_string_release(range_text);

    zend_update_property_long(Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "byteStart", sizeof("byteStart")-1, byte_start
    );

    zend_update_property_long(Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "byteEnd", sizeof("byteEnd")-1, byte_end
    );

    zend_enum_get_case_by_value(
        &script_case_obj, pango_ce_pango_script,
        script,
        NULL, false
    );
    ZVAL_OBJ(&script_case_zv, script_case_obj);
    zend_update_property(Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "script", sizeof("script")-1, &script_case_zv
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_ScriptIter, next)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_script_iter_next(pango_script_iter_object_get_script_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Script, getSampleLanguage)
{
    zend_long script_value;
    PangoLanguage *language = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    script_value = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(ZEND_THIS)));

    // avoid "Pango-CRITICAL **: pango_script_get_sample_language: assertion 'script >= 0' failed"
    // when UnknownNewScript (-9999) or InvalidCode (-1) are used
    if (script_value < 0) {
        RETURN_NULL();
    }

    language = pango_script_get_sample_language(script_value);
    if (!language) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_language_ce());
    Z_PANGO_LANGUAGE_P(return_value)->language = language;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Script, getGravity)
{
    zend_object *base_gravity_obj = NULL;
    zend_object *hint_obj = NULL;
    bool wide = false;
    PangoScript script_value;
    PangoGravity gravity;
    zend_object *gravity_case;

    ZEND_PARSE_PARAMETERS_START(0, 3)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJ_OF_CLASS(base_gravity_obj, php_pango_get_gravity_ce())
        Z_PARAM_OBJ_OF_CLASS(hint_obj, php_pango_get_gravity_hint_ce())
        Z_PARAM_BOOL(wide)
    ZEND_PARSE_PARAMETERS_END();

    script_value = (PangoScript) Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(ZEND_THIS)));

    // avoid "Pango-CRITICAL **: pango_gravity_get_for_script_and_width: assertion 'script >= 0' failed"
    // when UnknownNewScript (-9999) or InvalidCode (-1) are used
    if (script_value < 0) {
        RETURN_NULL();
    }

    gravity = pango_gravity_get_for_script_and_width(
        script_value,
        wide,
        base_gravity_obj
            ? Z_LVAL_P(zend_enum_fetch_case_value(base_gravity_obj))
            : PANGO_GRAVITY_AUTO,
        hint_obj
            ? Z_LVAL_P(zend_enum_fetch_case_value(hint_obj))
            :  PANGO_GRAVITY_HINT_NATURAL
    );

    zend_enum_get_case_by_value(
        &gravity_case, php_pango_get_gravity_ce(),
        gravity,
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_case);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Script Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_script_iter_free_obj(zend_object *zobj)
{
    pango_script_iter_object *intern = pango_script_iter_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->script_iter) {
        pango_script_iter_free(intern->script_iter);
        intern->script_iter = NULL;
    }

    if (intern->text) {
        zend_string_release(intern->text);
        intern->text = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_script_iter_obj_ctor(zend_class_entry *ce, pango_script_iter_object **intern)
{
    pango_script_iter_object *object = ecalloc(1, sizeof(pango_script_iter_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_script_iter_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_script_iter_create_object(zend_class_entry *ce)
{
    pango_script_iter_object *intern = NULL;
    zend_object *return_value = pango_script_iter_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_script_iter)
{
    memcpy(
        &pango_script_iter_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_script_iter_object_handlers.offset = offsetof(pango_script_iter_object, std);
    pango_script_iter_object_handlers.free_obj = pango_script_iter_free_obj;
    pango_script_iter_object_handlers.clone_obj = NULL;

    pango_ce_pango_script_iter = register_class_Pango_ScriptIter();
    pango_ce_pango_script_iter->create_object = pango_script_iter_create_object;

    pango_ce_pango_script = register_class_Pango_Script();

    return SUCCESS;
}
/* }}} */
