/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2026 Marcel Bolten                                     |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  +----------------------------------------------------------------------+
  | Authors: Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_interfaces.h>
#include <ext/spl/spl_array.h>

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "analysis.h"
#include "language.h"
#include "logattr.h"
#include "php_pango_macros.h"
#include "logattr_list.h"
#include "logattr_list_arginfo.h"

zend_class_entry *ce_pango_logattr_list;

static zend_object_handlers pango_logattr_list_object_handlers;

pango_logattr_list_object *pango_logattr_list_fetch_object(zend_object *object)
{
    return (pango_logattr_list_object *) ((char*)(object) - offsetof(pango_logattr_list_object, std));
}

#define PANGO_ALLOC_LOGATTR_ARR(logattr_arr, arr_length) \
    if (!logattr_arr) { \
        logattr_arr = ecalloc(arr_length, sizeof(PangoLogAttr)); \
    }

/* ----------------------------------------------------------------
    \Pango\LogAttrList C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoLogAttr *pango_logattr_list_object_get_logattr_arr(zval *zv)
{
    return Z_PANGO_LOGATTR_LIST_P(zv)->logattr_arr;
}
/* }}} */

zend_class_entry* php_pango_get_logattr_list_ce()
{
    return ce_pango_logattr_list;
}

/* ----------------------------------------------------------------
    \Pango\LogAttrList Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(Pango_LogAttrList, __construct)
{
    zend_string *text;
    zval *language_zv = NULL;
    PangoLanguage *language = NULL;
    zend_long level = -1;
    pango_logattr_list_object *logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(ZEND_THIS);

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_STR(text)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(language_zv, php_pango_get_language_ce())
        Z_PARAM_LONG(level)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (level < -1 || level > INT_MAX) {
        zend_argument_value_error(3,
            "must be between -1 and " ZEND_LONG_FMT,
            (zend_long)INT_MAX
        );
        RETURN_THROWS();
    }

    if (language_zv) {
        language = Z_PANGO_LANGUAGE_P(language_zv)->language;
    }

    // allocate the logattr array with the length of the text
    // plus one extra at the end of the text
    logattr_list_obj->logattr_arr_len = ZSTR_LEN(text) + 1;
    PANGO_ALLOC_LOGATTR_ARR(
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );

    zend_update_property_str(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "text", sizeof("text") - 1,
        text
    );

    pango_get_log_attrs(
        ZSTR_VAL(text), ZSTR_LEN(text),
        (int)level,
        language,
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );
}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, defaultBreak)
{
    zend_string *text;
    pango_logattr_list_object *logattr_list_obj;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    object_init_ex(return_value, ce_pango_logattr_list);
    logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(return_value);

    // allocate the logattr array with the length of the text
    // plus one extra at the end of the text
    logattr_list_obj->logattr_arr_len = ZSTR_LEN(text) + 1;
    PANGO_ALLOC_LOGATTR_ARR(
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );

    zend_update_property_str(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "text", sizeof("text") - 1,
        text
    );

    pango_default_break (
        ZSTR_VAL(text), ZSTR_LEN(text),
        NULL,
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );

}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, tailorBreak)
{
    zval *this_zv = ZEND_THIS;
    pango_logattr_list_object *logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(ZEND_THIS);
    zval *analysis_zv = NULL;
    PangoAnalysis analysis = { NULL };
    zend_long byte_offset = -1;
    zval *text_zv;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(analysis_zv, php_pango_get_analysis_ce())
        Z_PARAM_LONG(byte_offset)
    ZEND_PARSE_PARAMETERS_END();

    if (byte_offset < -1 || byte_offset > INT_MAX) {
        zend_argument_value_error(2,
            "must be between -1 and " ZEND_LONG_FMT,
            (zend_long)INT_MAX
        );
        RETURN_THROWS();
    }

    text_zv = zend_read_property(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "text", sizeof("text") - 1,
        0, NULL
    );

    pango_tailor_break(
        Z_STRVAL_P(text_zv),
        Z_STRLEN_P(text_zv),
        analysis_zv
            ? pango_analysis_object_get_analysis(analysis_zv)
            : &analysis,
        byte_offset,
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, attrBreak)
{
    zval *this_zv = ZEND_THIS;
    pango_logattr_list_object *logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(this_zv);
    zval *attr_list_zv;
    zend_long byte_offset = 0;
    zval *text_zv;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, php_pango_get_attr_list_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(byte_offset)
    ZEND_PARSE_PARAMETERS_END();

    if (byte_offset < 0 || byte_offset > INT_MAX) {
        zend_argument_value_error(2,
            "must be between 0 and " ZEND_LONG_FMT,
            (zend_long)INT_MAX
        );
        RETURN_THROWS();
    }

    text_zv = zend_read_property(
        Z_OBJCE_P(this_zv), Z_OBJ_P(this_zv),
        "text", sizeof("text") - 1,
        0, NULL
    );

    pango_attr_break(
        Z_STRVAL_P(text_zv),
        Z_STRLEN_P(text_zv),
        pango_attr_list_object_get_attr_list(attr_list_zv),
        byte_offset,
        logattr_list_obj->logattr_arr,
        logattr_list_obj->logattr_arr_len
    );

RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, count)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(Z_PANGO_LOGATTR_LIST_P(ZEND_THIS)->logattr_arr_len);
}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, get)
{
    zend_long byte_index;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(byte_index)
    ZEND_PARSE_PARAMETERS_END();

    if (byte_index < 0 || byte_index >= Z_PANGO_LOGATTR_LIST_P(ZEND_THIS)->logattr_arr_len) {
        zend_argument_value_error(1,
            "must be between 0 and " ZEND_LONG_FMT,
            (zend_long)(Z_PANGO_LOGATTR_LIST_P(ZEND_THIS)->logattr_arr_len - 1)
        );
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_logattr_ce());
    *Z_PANGO_LOGATTR_P(return_value)->logattr = Z_PANGO_LOGATTR_LIST_P(ZEND_THIS)->logattr_arr[byte_index];
}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, getAttributes)
{
    pango_logattr_list_object *logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(ZEND_THIS);
    zval tmp_logattr_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    array_init_size(return_value, logattr_list_obj->logattr_arr_len);
    for (int i = 0; i < logattr_list_obj->logattr_arr_len; i++) {
        object_init_ex(&tmp_logattr_zv, php_pango_get_logattr_ce());
        *Z_PANGO_LOGATTR_P(&tmp_logattr_zv)->logattr = logattr_list_obj->logattr_arr[i];
        add_index_zval(return_value, i, &tmp_logattr_zv);
    }
}
/* }}} */

/* {{{ */
ZEND_METHOD(Pango_LogAttrList, getIterator)
{
    pango_logattr_list_object *logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(ZEND_THIS);
    zval tmp_arr_zv;
    zval tmp_logattr_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    array_init_size(&tmp_arr_zv, logattr_list_obj->logattr_arr_len);
    for (int i = 0; i < logattr_list_obj->logattr_arr_len; i++) {
        object_init_ex(&tmp_logattr_zv, php_pango_get_logattr_ce());
        *Z_PANGO_LOGATTR_P(&tmp_logattr_zv)->logattr = logattr_list_obj->logattr_arr[i];
        add_index_zval(&tmp_arr_zv, i, &tmp_logattr_zv);
    }

    object_init_ex(return_value, spl_ce_ArrayIterator);
    zend_call_method_with_1_params(
        Z_OBJ_P(return_value), spl_ce_ArrayIterator,
        &spl_ce_ArrayIterator->constructor, "__construct",
        NULL, &tmp_arr_zv
    );

    zval_ptr_dtor(&tmp_arr_zv);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\LogAttrList Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_logattr_list_free_obj(zend_object *object)
{
    pango_logattr_list_object *intern = pango_logattr_list_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->logattr_arr) {
        efree(intern->logattr_arr);
        intern->logattr_arr = NULL;
        intern->logattr_arr_len = 0;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_list_obj_ctor(zend_class_entry *ce, pango_logattr_list_object **intern)
{
    pango_logattr_list_object *object = ecalloc(1, sizeof(pango_logattr_list_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_logattr_list_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_list_create_object(zend_class_entry *ce)
{
    pango_logattr_list_object *intern = NULL;
    zend_object *return_value = pango_logattr_list_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_list_clone_obj(zend_object *zobj)
{
    pango_logattr_list_object *new_logattr_list;
    pango_logattr_list_object *old_logattr_list = pango_logattr_list_fetch_object(zobj);
    zend_object *return_value = pango_logattr_list_obj_ctor(zobj->ce, &new_logattr_list);

    new_logattr_list->logattr_arr_len = old_logattr_list->logattr_arr_len;
    PANGO_ALLOC_LOGATTR_ARR(new_logattr_list->logattr_arr, new_logattr_list->logattr_arr_len);

    memcpy(new_logattr_list->logattr_arr,
        old_logattr_list->logattr_arr,
        old_logattr_list->logattr_arr_len * sizeof(PangoLogAttr)
    );

    zend_objects_clone_members(&new_logattr_list->std, &old_logattr_list->std);

    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\LogAttrList Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_logattr_list)
{
    memcpy(
        &pango_logattr_list_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_logattr_list_object_handlers.offset = offsetof(pango_logattr_list_object, std);
    pango_logattr_list_object_handlers.free_obj = pango_logattr_list_free_obj;
    pango_logattr_list_object_handlers.clone_obj = pango_logattr_list_clone_obj;
    pango_logattr_list_object_handlers.get_property_ptr_ptr = NULL;

    ce_pango_logattr_list = register_class_Pango_LogAttrList(zend_ce_countable, zend_ce_aggregate);
    ce_pango_logattr_list->create_object = pango_logattr_list_create_object;

    return SUCCESS;
}
/* }}} */
