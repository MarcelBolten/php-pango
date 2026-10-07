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
#include <zend_exceptions.h>

#include "../php_pango.h"
#include "exception.h"
#include "php_pango_macros.h"
#include "color.h"
#include "color_arginfo.h"

zend_class_entry *ce_pango_color;

static zend_object_handlers pango_color_object_handlers;

pango_color_object *pango_color_fetch_object(zend_object *object)
{
    return (pango_color_object *) ((char*)(object) - offsetof(pango_color_object, std));
}

#define PANGO_ALLOC_COLOR(ptr) \
    if (!ptr) { \
        ptr = ecalloc(1, sizeof(PangoColor)); \
    }

/* ----------------------------------------------------------------
    \Pango\Color C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoColor *pango_color_object_get_color(zval *zv)
{
    return (PangoColor *) Z_PANGO_COLOR_P(zv)->color;
}
/* }}} */

zend_class_entry* php_pango_get_color_ce(void)
{
    return ce_pango_color;
}

/* ----------------------------------------------------------------
    \Pango\Color Class API
------------------------------------------------------------------*/

/* {{{ Creates a new size attribute */
PHP_METHOD(Pango_Color, __construct)
{
    PangoColor *pango_color;
    zend_long red;
    zend_long green;
    zend_long blue;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(red)
        Z_PARAM_LONG(green)
        Z_PARAM_LONG(blue)
    ZEND_PARSE_PARAMETERS_END();

    if (red < 0 || red > 0xFFFF) {
        zend_argument_value_error(1, "must be equal or greater than 0 and smaller or equal than 65536");
    }
    if (green < 0 || green > 0xFFFF) {
        zend_argument_value_error(2, "must be equal or greater than 0 and smaller or equal than 65536");
    }
    if (blue < 0 || blue > 0xFFFF) {
        zend_argument_value_error(3, "must be equal or greater than 0 and smaller or equal than 65536");
    }

    pango_color = pango_color_object_get_color(ZEND_THIS);
    pango_color->red = red;
    pango_color->green = green;
    pango_color->blue = blue;
}
/* }}} */

/* {{{ Fill in the fields of a color from a string specification. */
PHP_METHOD(Pango_Color, fromString)
{
    zend_string *spec = NULL;
    PangoColor *color;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(spec)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(spec)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    object_init_ex(return_value, ce_pango_color);
    color = pango_color_object_get_color(return_value);

    if (!pango_color_parse(color, ZSTR_VAL(spec))) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Failed to parse color from string",
            0
        );
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Color, fromStringWithAlpha)
{
    zend_string *spec = NULL;
    PangoColor *color;
    guint16 alpha;
    zval color_zv;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(spec)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(spec)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    object_init_ex(&color_zv, ce_pango_color);
    color = pango_color_object_get_color(&color_zv);

    if (!pango_color_parse_with_alpha(color, &alpha, ZSTR_VAL(spec))) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Failed to parse color with alpha from string",
            0
        );
        zval_ptr_dtor(&color_zv);
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_zval(return_value, "color", &color_zv);
    add_assoc_long(return_value, "alpha", alpha);
}
/* }}} */

/* {{{ Returns a textual specification of color */
PHP_METHOD(Pango_Color, __toString)
{
    char *spec = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    spec = pango_color_to_string(Z_PANGO_COLOR_P(ZEND_THIS)->color);

    RETURN_STRING(spec);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Color Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_color_free_obj(zend_object *object)
{
    pango_color_object *intern = pango_color_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->color) {
        efree(intern->color);
        intern->color = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_color_obj_ctor(zend_class_entry *ce, pango_color_object **intern)
{
    pango_color_object *object = ecalloc(1, sizeof(pango_color_object) + zend_object_properties_size(ce));
    PANGO_ALLOC_COLOR(object->color);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_color_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_color_create_object(zend_class_entry *ce)
{
    pango_color_object *intern = NULL;
    zend_object *return_value = pango_color_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_color_clone_obj(zend_object *zobj)
{
    pango_color_object *new_color;
    pango_color_object *old_color = pango_color_fetch_object(zobj);
    zend_object *return_value = pango_color_obj_ctor(zobj->ce, &new_color);

    if (old_color->color) {
        *new_color->color = *old_color->color;
    }

    zend_objects_clone_members(&new_color->std, &old_color->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_color_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_color_object *color_object = pango_color_fetch_object(object);

    if (!color_object) {
        return rv;
    }

    PangoColor *color = color_object->color;

    PANGO_LONG_VALUE_FROM_STRUCT(color->red, red);
    PANGO_LONG_VALUE_FROM_STRUCT(color->green, green);
    PANGO_LONG_VALUE_FROM_STRUCT(color->blue, blue);

    return rv;
}
/* }}} */

/* {{{ */
static zval *pango_color_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    pango_color_object *color_object = pango_color_fetch_object(object);
    zval *retval = NULL;

    if (!color_object) {
        return retval;
    }

    do {
        PangoColor *color = color_object->color;

        PANGO_LONG_VALUE_TO_STRUCT(color->red, red);
        PANGO_LONG_VALUE_TO_STRUCT(color->green, green);
        PANGO_LONG_VALUE_TO_STRUCT(color->blue, blue);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);
    } while(0);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *pango_color_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_color_object *color_object = pango_color_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!color_object->color) {
        return props;
    }

    PangoColor *color = color_object->color;

    PANGO_ADD_STRUCT_LONG_VALUE(color->red, red);
    PANGO_ADD_STRUCT_LONG_VALUE(color->green, green);
    PANGO_ADD_STRUCT_LONG_VALUE(color->blue, blue);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Color Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_color)
{
    memcpy(
        &pango_color_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_color_object_handlers.offset = offsetof(pango_color_object, std);
    pango_color_object_handlers.free_obj = pango_color_free_obj;
    pango_color_object_handlers.clone_obj = pango_color_clone_obj;
    pango_color_object_handlers.read_property = pango_color_object_read_property;
    pango_color_object_handlers.write_property = pango_color_object_write_property;
    pango_color_object_handlers.get_property_ptr_ptr = NULL;
    pango_color_object_handlers.get_properties_for = pango_color_object_get_properties_for;

    ce_pango_color = register_class_Pango_Color();
    ce_pango_color->create_object = pango_color_create_object;

    return SUCCESS;
}
/* }}} */
