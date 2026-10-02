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
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "php_pango_macros.h"
#include "exception.h"
#include "script.h"
#include "language.h"
#include "language_arginfo.h"

zend_class_entry *ce_pango_language;

static zend_object_handlers pango_language_object_handlers;

pango_language_object *pango_language_fetch_object(zend_object *object)
{
    return (pango_language_object *) ((char*)(object) - offsetof(pango_language_object, std));
}

#define PANGO_ALLOC_LANGUAGE(ptr) \
    if (!ptr) { \
        ptr = ecalloc(1, sizeof(PangoLanguage)); \
    }

/* ----------------------------------------------------------------
    \Pango\Language C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoLanguage *pango_language_object_get_language(zval *zv)
{
    return (PangoLanguage *) Z_PANGO_LANGUAGE_P(zv)->language;
}
/* }}} */

zend_class_entry* php_pango_get_language_ce(void)
{
    return ce_pango_language;
}

/* ----------------------------------------------------------------
    \Pango\Language Class API
------------------------------------------------------------------*/

/* {{{ Creates a new language object */
PHP_METHOD(Pango_Language, __construct)
{
    zend_string *language_str;
    PangoLanguage *lang;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(language_str)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(language_str)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    lang = pango_language_from_string(ZSTR_VAL(language_str));

    if (!lang) {
        zend_throw_exception_ex(
            php_pango_get_pango_exception_ce(),
            0,
            "Failed to create Pango\\Language from string \"%s\"",
            ZSTR_VAL(language_str)
        );
        RETURN_THROWS();
    }

    Z_PANGO_LANGUAGE_P(ZEND_THIS)->language = lang;
}
/* }}} */

/* {{{ Returns the Language for the current locale of the process. */
PHP_METHOD(Pango_Language, getDefault)
{
    PangoLanguage *language;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, ce_pango_language);
    Z_PANGO_LANGUAGE_P(return_value)->language = pango_language_get_default();
}
/* }}} */

/* {{{ Returns the list of languages that the user prefers. */
PHP_METHOD(Pango_Language, getPreferred)
{
    PangoLanguage *language;
    PangoLanguage** preferred_languages;

    ZEND_PARSE_PARAMETERS_NONE();

    preferred_languages = pango_language_get_preferred();

    if (!preferred_languages) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (int i = 0; preferred_languages[i] != NULL; i++) {
        zval language_obj;
        object_init_ex(&language_obj, ce_pango_language);
        Z_PANGO_LANGUAGE_P(&language_obj)->language = preferred_languages[i];
        add_next_index_zval(return_value, &language_obj);
    }
}
/* }}} */

/* {{{ Get a string that is representative of the characters needed to render a
       particular language. */
PHP_METHOD(Pango_Language, getSampleString)
{
    PangoLanguage *language;
    const char *sample_string;

    ZEND_PARSE_PARAMETERS_NONE();

    language = pango_language_object_get_language(ZEND_THIS);
    sample_string = pango_language_get_sample_string(language);

    if (!sample_string) {
        RETURN_NULL();
    }
    RETURN_STRING(sample_string);
}

/* {{{ */
PHP_METHOD(Pango_Language, getScripts)
{
    PangoLanguage *language;
    const PangoScript *scripts;
    int num_scripts;
    zend_object *script_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    language = pango_language_object_get_language(ZEND_THIS);
    scripts = pango_language_get_scripts(language, &num_scripts);

    if (!scripts) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (int i = 0; i < num_scripts; i++) {
        PangoScript script = scripts[i];
        zend_result result = zend_enum_get_case_by_value(
            &script_obj, php_pango_get_script_ce(),
            script,
            NULL, false
        );

        // If the script is not found in the enum, use fallback value -9999
        // (UnknownNewScript) to indicate that the script is unknown
        if (result == FAILURE) {
            zend_enum_get_case_by_value(
                &script_obj, php_pango_get_script_ce(),
                -9999,
                NULL, false
            );
        }

        GC_ADDREF(script_obj);
        add_next_index_object(return_value, script_obj);
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Language, includesScript)
{
    PangoLanguage *language;
    zend_object *script_obj;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(script_obj, php_pango_get_script_ce())
    ZEND_PARSE_PARAMETERS_END();

    language = pango_language_object_get_language(ZEND_THIS);

    RETURN_BOOL(pango_language_includes_script(
        language,
        Z_LVAL_P(zend_enum_fetch_case_value(script_obj))
    ));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Language, matches)
{
    pango_language_object *language_object;
    zend_string *range_list;
    PangoLanguage *language;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(range_list)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(range_list)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    RETURN_BOOL(pango_language_matches(
        pango_language_object_get_language(ZEND_THIS),
        ZSTR_VAL(range_list)
    ));
}
/* }}} */

/* {{{ Gets the RFC-3066 format string representing the given language tag */
PHP_METHOD(Pango_Language, __toString)
{
    PangoLanguage *language;
    const char *string_representation;

    ZEND_PARSE_PARAMETERS_NONE();

    language = pango_language_object_get_language(ZEND_THIS);
    string_representation = pango_language_to_string(language);

    if (!string_representation) {
        RETURN_NULL();
    }

    RETURN_STRING(string_representation);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Language Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_language_free_obj(zend_object *object)
{
    pango_language_object *intern = pango_language_fetch_object(object);

    if (!intern) {
        return;
    }

    // no need to free intern->language, as it is managed by Pango and should not be freed manually
    if (intern->language) {
        intern->language = NULL;
    }

    zend_object_std_dtor(&intern->std);

}
/* }}} */

/* {{{ */
static zend_object* pango_language_obj_ctor(zend_class_entry *ce, pango_language_object **intern)
{
    pango_language_object *object = ecalloc(1, sizeof(pango_language_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_language_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_language_create_object(zend_class_entry *ce)
{
    pango_language_object *intern = NULL;
    zend_object *return_value = pango_language_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_language_clone_obj(zend_object *zobj)
{
    pango_language_object *new_language;
    pango_language_object *old_language = pango_language_fetch_object(zobj);
    zend_object *return_value = pango_language_obj_ctor(zobj->ce, &new_language);

    if (old_language->language) {
        new_language->language = old_language->language;
    }

    zend_objects_clone_members(&new_language->std, &old_language->std);

    return return_value;
}
/* }}} */

/* {{{ */
static HashTable* pango_language_get_debug_info_obj(zend_object *zobj, int *is_temp)
{
    pango_language_object *intern = pango_language_fetch_object(zobj);
    HashTable *debug_info = zend_std_get_properties(zobj);

    zval language_str_zv;
    const char *language_str = pango_language_to_string(intern->language);
    ZVAL_STRING(&language_str_zv, language_str);
    zend_hash_str_update(debug_info, "string-representation", sizeof("string-representation") - 1, &language_str_zv);

    *is_temp = 0;
    return debug_info;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Language Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_language)
{
    memcpy(
        &pango_language_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_language_object_handlers.offset = offsetof(pango_language_object, std);
    pango_language_object_handlers.free_obj = pango_language_free_obj;
    pango_language_object_handlers.clone_obj = pango_language_clone_obj;
    pango_language_object_handlers.get_property_ptr_ptr = NULL;
    pango_language_object_handlers.get_debug_info = pango_language_get_debug_info_obj;

    ce_pango_language = register_class_Pango_Language();
    ce_pango_language->create_object = pango_language_create_object;

    return SUCCESS;
}
/* }}} */
