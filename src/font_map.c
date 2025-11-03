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

#include "php.h"
#include "php_pango.h"
#include "font_map_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_font_map;

static zend_object_handlers pango_font_map_object_handlers;

pango_font_map_object *pango_font_map_fetch_object(zend_object *object)
{
    return (pango_font_map_object *) ((char*)(object) - XtOffsetOf(pango_font_map_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_map_ce()
{
    return pango_ce_pango_font_map;
}

PHP_PANGO_API PangoFontMap* pango_font_map_object_get_font_map(zval *zv)
{
    pango_font_map_object *obj = Z_PANGO_FONT_MAP_P(zv);
    return obj->font_map;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
/* {{{ Loads a font file with one or more fonts into the FontMap. */
PHP_METHOD(Pango_FontMap, addFontFile)
{
    char *filename;
    size_t filename_len;
    PangoFontMap* font_map;
    GError* error = NULL;
    bool result;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(filename, filename_len)
    ZEND_PARSE_PARAMETERS_END();

    font_map = pango_font_map_object_get_font_map(getThis());

    result = pango_font_map_add_font_file(font_map, filename, &error);
    if (error) {
        zend_throw_exception_ex(
            pango_ce_pango_exception,
            0,
            "Error adding font file '%s': %s",
            filename,
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

    font_map = pango_font_map_object_get_font_map(getThis());

    object_init_ex(return_value, php_pango_get_context_ce());
    context_object = Z_PANGO_CONTEXT_P(return_value);
    context_object->context = pango_font_map_create_context(font_map);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
/* {{{ Gets a font family by name. */
PHP_METHOD(Pango_FontMap, getFamily)
{
    char *name;
    size_t name_len;
    PangoFontMap* font_map;
    PangoFontFamily *font_family;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(name, name_len)
    ZEND_PARSE_PARAMETERS_END();

    font_map = pango_font_map_object_get_font_map(getThis());

    font_family = pango_font_map_get_family(font_map, name);
    if (!font_family) {
        zend_throw_exception_ex(
            pango_ce_pango_exception,
            0,
            "Font family '%s' not found.",
            name
        );
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_font_family_ce());
    font_family_object = Z_PANGO_FONT_FAMILY_P(return_value);
    font_family_object->font_family = g_object_ref(font_family);
}
/* }}} */
#endif

/* {{{ List all families for a font map. */
PHP_METHOD(Pango_FontMap, listFamilies)
{
    PangoFontMap* font_map;
    PangoFontFamily** families;
    int num_families;
    zval family_zv;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map = pango_font_map_object_get_font_map(getThis());

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

    pango_font_map_object_handlers.offset = XtOffsetOf(pango_font_map_object, std);
    // pango_font_map_object_handlers.free_obj = pango_font_map_free_obj;

    pango_ce_pango_font_map = register_class_Pango_FontMap();
    // pango_ce_pango_font_map->create_object = pango_font_map_create_object;

    return SUCCESS;
}
/* }}} */
