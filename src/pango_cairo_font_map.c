/*
  +----------------------------------------------------------------------+
  | PHP Version 8                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2008 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Michael Maclean <mgdm@php.net>                              |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_pango.h"
#include "pango_cairo_font_map_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_cairo_font_map;

static zend_object_handlers pango_cairo_font_map_object_handlers;

pango_font_map_object *pango_cairo_font_map_fetch_object(zend_object *object)
{
    return (pango_font_map_object *) ((char*)(object) - XtOffsetOf(pango_font_map_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_cairo_get_font_map_ce()
{
    return pango_ce_pango_cairo_font_map;
}

PHP_PANGO_API PangoFontMap* pango_cairo_font_map_object_get_font_map(zval *zv)
{
    pango_font_map_object *obj = Z_PANGO_CAIRO_FONT_MAP_P(zv);
    return obj->font_map;
}

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, __construct)
{
    pango_font_map_object *font_map_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map_object = Z_PANGO_CAIRO_FONT_MAP_P(getThis());
    font_map_object->font_map = pango_cairo_font_map_new();
    font_map_object->is_default = false;
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, getDefault)
{
    pango_font_map_object *font_map_object;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, pango_ce_pango_cairo_font_map);
    font_map_object = Z_PANGO_CAIRO_FONT_MAP_P(return_value);
    font_map_object->font_map = pango_cairo_font_map_get_default();
    font_map_object->is_default = true;
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, newForFontType)
{
    zend_object *font_type_object;
    pango_font_map_object *font_map_object;
    cairo_font_type_t font_type;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJ_OF_CLASS(font_type_object, ce_cairo_fonttype)
    ZEND_PARSE_PARAMETERS_END();


    object_init_ex(return_value, pango_ce_pango_cairo_font_map);
    font_map_object = Z_PANGO_CAIRO_FONT_MAP_P(return_value);
    font_type = Z_LVAL_P(zend_enum_fetch_case_value(font_type_object));
    font_map_object->font_map = pango_cairo_font_map_new_for_font_type(font_type);
    font_map_object->is_default = false;

    if (!font_map_object->font_map) {
        zend_throw_exception_ex(
            pango_ce_pango_exception,
            0,
            "Could not create new PangoCairo\\FontMap for Cairo\\FontType::%s",
            Z_STRVAL_P(zend_enum_fetch_case_name(font_type_object))
        );
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, getFontType)
{
    PangoFontMap* font_map;
    cairo_font_type_t font_type;
    zend_object *font_type_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map = pango_cairo_font_map_object_get_font_map(getThis());

    zend_enum_get_case_by_value(
        &font_type_case, ce_cairo_fonttype,
        pango_cairo_font_map_get_font_type((PangoCairoFontMap *) font_map),
        NULL, false
    );

    RETURN_OBJ_COPY(font_type_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, getResolution)
{
    PangoFontMap* font_map;

    ZEND_PARSE_PARAMETERS_NONE();

    font_map = pango_cairo_font_map_object_get_font_map(getThis());

    RETURN_DOUBLE(pango_cairo_font_map_get_resolution((PangoCairoFontMap *) font_map));
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, setDefault)
{
    zval *font_map_zv;
    pango_font_map_object *font_map_object;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(font_map_zv, pango_ce_pango_cairo_font_map)
    ZEND_PARSE_PARAMETERS_END();

    font_map_object = Z_PANGO_CAIRO_FONT_MAP_P(font_map_zv);

    pango_cairo_font_map_set_default((PangoCairoFontMap *) font_map_object->font_map);
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_FontMap, setResolution)
{
    double factor;
    PangoFontMap* font_map;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_DOUBLE(factor)
    ZEND_PARSE_PARAMETERS_END();

    font_map = pango_cairo_font_map_object_get_font_map(getThis());

    pango_cairo_font_map_set_resolution((PangoCairoFontMap *) font_map, factor);
}
/* }}} */


/* ----------------------------------------------------------------
    \PangoCairo\FontMap Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_cairo_font_map_free_obj(zend_object *zobj)
{
    pango_font_map_object *intern = pango_cairo_font_map_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_map && !intern->is_default) {
        g_object_unref(intern->font_map);
        intern->font_map = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_font_map_obj_ctor(zend_class_entry *ce, pango_font_map_object **intern)
{
    pango_font_map_object *object = ecalloc(1, sizeof(pango_font_map_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_cairo_font_map_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_cairo_font_map_create_object(zend_class_entry *ce)
{
    pango_font_map_object *intern = NULL;
    zend_object *return_value = pango_cairo_font_map_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_cairo_font_map)
{
    memcpy(
        &pango_cairo_font_map_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_cairo_font_map_object_handlers.offset = XtOffsetOf(pango_font_map_object, std);
    pango_cairo_font_map_object_handlers.free_obj = pango_cairo_font_map_free_obj;

    pango_ce_pango_cairo_font_map = register_class_PangoCairo_FontMap(php_pango_get_font_map_ce());
    pango_ce_pango_cairo_font_map->create_object = pango_cairo_font_map_create_object;

    return SUCCESS;
}
/* }}} */
