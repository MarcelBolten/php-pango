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
#include "context.h"
#include "exception.h"
#include "language.h"
#include "font.h"
#include "font_set.h"
#include "font_family.h"
#include "font_description.h"
#include "font_map.h"
#include "font_map_arginfo.h"

zend_class_entry *pango_ce_pango_font_map;

static zend_object_handlers pango_font_map_object_handlers;

pango_font_map_object *pango_font_map_fetch_object(zend_object *object)
{
    return (pango_font_map_object *) ((char*)(object) - offsetof(pango_font_map_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_map_ce()
{
    return pango_ce_pango_font_map;
}

PHP_PANGO_API PangoFontMap* pango_font_map_object_get_font_map(zval *zv)
{
    return Z_PANGO_FONT_MAP_P(zv)->font_map;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
/* {{{ Loads a font file with one or more fonts into the FontMap. */
PHP_METHOD(Pango_FontMap, addFontFile)
{
    zend_string *filename;
    GError* error = NULL;
    bool result;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(filename)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(filename)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    result = pango_font_map_add_font_file(
        pango_font_map_object_get_font_map(ZEND_THIS),
        ZSTR_VAL(filename), &error
    );

    if (error) {
        zend_throw_exception_ex(
            php_pango_get_pango_exception_ce(),
            0,
            "Error adding font file '%s': %s",
            ZSTR_VAL(filename),
            error->message
        );
        g_error_free(error);
        RETURN_THROWS();
    }

    RETURN_BOOL(result);
}
/* }}} */
#endif

/* {{{ Creates a context connected to font map. */
PHP_METHOD(Pango_FontMap, createContext)
{
    PangoFontMap* font_map;
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map = pango_font_map_object_get_font_map(ZEND_THIS);

    object_init_ex(return_value, php_pango_get_context_ce());
    context_object = Z_PANGO_CONTEXT_P(return_value);
    context_object->context = pango_font_map_create_context(font_map);
}
/* }}} */

/* {{{ Gets a font family by name. */
PHP_METHOD(Pango_FontMap, getFamily)
{
    zend_string *name;
    PangoFontFamily *font_family;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(name)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(name)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    font_family = pango_font_map_get_family(
        pango_font_map_object_get_font_map(ZEND_THIS),
        ZSTR_VAL(name)
    );
    if (!font_family) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_family_ce());
    font_family_object = Z_PANGO_FONT_FAMILY_P(return_value);
    font_family_object->font_family = g_object_ref(font_family);
}
/* }}} */

/* {{{ List all families for a font map. */
PHP_METHOD(Pango_FontMap, listFamilies)
{
    PangoFontMap* font_map;
    PangoFontFamily** families;
    int num_families;
    zval family_zv;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map = pango_font_map_object_get_font_map(ZEND_THIS);

    pango_font_map_list_families(font_map, &families, &num_families);

    array_init(return_value);
    for (int i = 0; i < num_families; i++) {
        object_init_ex(&family_zv, php_pango_get_font_family_ce());
        font_family_object = Z_PANGO_FONT_FAMILY_P(&family_zv);
        font_family_object->font_family = g_object_ref(families[i]);
        add_next_index_zval(return_value, &family_zv);
    }

    g_free(families);
}
/* }}} */

/* {{{ Load the font of this FontMap that is the closest match for desc. */
PHP_METHOD(Pango_FontMap, loadFont)
{
    zval *context_zv;
    zval *font_desc_zv;
    PangoFont *font;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(context_zv, php_pango_get_context_ce())
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    font = pango_font_map_load_font(
        pango_font_map_object_get_font_map(ZEND_THIS),
        pango_context_object_get_context(context_zv),
        pango_font_description_object_get_font_description(font_desc_zv)
    );

    if (!font) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_ce());
    Z_PANGO_FONT_P(return_value)->font = font;
}
/* }}} */

/* {{{ Load the set of fonts in this FontMap that is the closest match for desc. */
PHP_METHOD(Pango_FontMap, loadFontSet)
{
    zval *context_zv;
    zval *font_desc_zv;
    zval *font_language_zv;
    PangoFontset *font_set;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(context_zv, php_pango_get_context_ce())
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
        Z_PARAM_OBJECT_OF_CLASS(font_language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    font_set = pango_font_map_load_fontset(
        pango_font_map_object_get_font_map(ZEND_THIS),
        pango_context_object_get_context(context_zv),
        pango_font_description_object_get_font_description(font_desc_zv),
        pango_language_object_get_language(font_language_zv)
    );

    if (!font_set) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_set_ce());
    Z_PANGO_FONT_SET_P(return_value)->font_set = font_set;
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 52, 0)
/* {{{ Returns a new font that is like font, except that it is scaled by scale,
       its backend-dependent configuration (e.g. cairo font options) is
       replaced by the one in context, and its variations are replaced by
       variations.
*/
PHP_METHOD(Pango_FontMap, reloadFont)
{
    zval *font_zv;
    double scale;
    zval *context_zv = NULL;
    zend_string *font_variations = NULL;
    PangoFont * scaled_font;

    ZEND_PARSE_PARAMETERS_START(2, 4)
        Z_PARAM_OBJECT_OF_CLASS(font_zv, php_pango_get_font_ce())
        Z_PARAM_DOUBLE(scale)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(context_zv, php_pango_get_context_ce())
        Z_PARAM_STR_OR_NULL(font_variations)
    ZEND_PARSE_PARAMETERS_END();

    if (font_variations && zend_str_has_nul_byte(font_variations)) {
        zend_argument_value_error(4, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    // scale must be positive
    if (scale <= 0) {
        zend_argument_value_error(2, "must be a positive number");
        RETURN_THROWS();
    }

    scaled_font = pango_font_map_reload_font(
        pango_font_map_object_get_font_map(ZEND_THIS),
        pango_font_object_get_font(font_zv),
        scale,
        context_zv ? pango_context_object_get_context(context_zv) : NULL,
        font_variations ? ZSTR_VAL(font_variations) : NULL
    );

    object_init_ex(return_value, php_pango_get_font_ce());
    Z_PANGO_FONT_P(return_value)->font = scaled_font;
}
/* }}} */
#endif

/* ----------------------------------------------------------------
    \Pango\FontMap Object management
------------------------------------------------------------------*/

/* {{{ */
// static void pango_font_map_free_obj(zend_object *zobj)
// {
//     pango_font_map_object *intern = pango_font_map_fetch_object(zobj);

//     if (!intern) {
//         return;
//     }

//     if (intern->font_map && !intern->is_default) {
//         g_object_unref(intern->font_map);
//     }

//     zend_object_std_dtor(&intern->std);
// }
/* }}} */

/* {{{ */
// static zend_object* pango_font_map_obj_ctor(zend_class_entry *ce, pango_font_map_object **intern)
// {
//     pango_font_map_object *object = ecalloc(1, sizeof(pango_font_map_object) + zend_object_properties_size(ce));

//     zend_object_std_init(&object->std, ce);

//     object->std.handlers = &pango_font_map_object_handlers;
//     *intern = object;

//     return &object->std;
// }
/* }}} */

/* {{{ */
// static zend_object* pango_font_map_create_object(zend_class_entry *ce)
// {
//     pango_font_map_object *intern = NULL;
//     zend_object *return_value = pango_font_map_obj_ctor(ce, &intern);

//     object_properties_init(&intern->std, ce);
//     return return_value;
// }
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_map)
{
    memcpy(
        &pango_font_map_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_map_object_handlers.offset = offsetof(pango_font_map_object, std);
    // pango_font_map_object_handlers.free_obj = pango_font_map_free_obj;

    pango_ce_pango_font_map = register_class_Pango_FontMap();
    // pango_ce_pango_font_map->create_object = pango_font_map_create_object;

    return SUCCESS;
}
/* }}} */
