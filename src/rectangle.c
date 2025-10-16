/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Elizabeth M Smith                                 |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  +----------------------------------------------------------------------+
  | Authors: Elizabeth M Smith <auroraeosrose@gmail.com>                 |
  |          Swen Zanon <swen.zanon@geoglis.de>                          |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>

#include "php_pango.h"
#include "rectangle_arginfo.h"

zend_class_entry *ce_pango_rectangle;
zend_class_entry *ce_pango_rounding_mode;

static zend_object_handlers pango_rectangle_object_handlers;

pango_rectangle_object *pango_rectangle_fetch_object(zend_object *object)
{
    return (pango_rectangle_object *) ((char*)(object) - XtOffsetOf(pango_rectangle_object, std));
}

#define PANGO_ALLOC_RECT(rect_value) if (!rect_value) \
    { rect_value = ecalloc(1, sizeof(PangoRectangle)); }

#define PANGO_VALUE_FROM_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        ZVAL_LONG(rv, rectangle_object->rect->n); \
        return rv; \
    }

#define PANGO_MACRO_VALUE_FROM_STRUCT(n, macro) \
    if (strcmp(member->val, #n) == 0) { \
        ZVAL_LONG(rv, macro((*rectangle_object->rect))); \
        return rv; \
    }

#define PANGO_ADD_STRUCT_VALUE(n) \
    ZVAL_LONG(&tmp, rectangle_object->rect->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp)

#define PANGO_MACRO_ADD_STRUCT_VALUE(n, macro) \
    ZVAL_LONG(&tmp, macro((*rectangle_object->rect))); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp)

/* ----------------------------------------------------------------
    \Pango\Rectangle C API
------------------------------------------------------------------*/

/* {{{ */
PangoRectangle *pango_rectangle_object_get_rectangle(zval *zv)
{
    pango_rectangle_object *rect_object = Z_PANGO_RECTANGLE_P(zv);

    return rect_object->rect;
}
/* }}} */

zend_class_entry* php_pango_get_rectangle_ce()
{
    return ce_pango_rectangle;
}

/* ----------------------------------------------------------------
    \Pango\Rectangle Class API
------------------------------------------------------------------*/

/* {{{ Creates a new rectangle with the properties populated */
PHP_METHOD(Pango_Rectangle, __construct)
{
    zend_long x;
    zend_long y;
    zend_long width;
    zend_long height;
    pango_rectangle_object *rectangle_object;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    rectangle_object = pango_rectangle_fetch_object(Z_OBJ_P(getThis()));
    *rectangle_object->rect = (PangoRectangle){(int)x, (int)y, (int)width, (int)height};
}
/* }}} */

/* {{{ Converts extents from Pango units to device units and rounds based on rounding mode. */
PHP_METHOD(Pango_Rectangle, extentsToPixels)
{
    zval *rectangle_zv;
    zend_object *rounding_mode_case = NULL;
    // Default rounding mode is inclusive
    bool use_inclusive = true;
    PangoRectangle rect;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS(rectangle_zv, ce_pango_rectangle)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJ_OF_CLASS(rounding_mode_case, ce_pango_rounding_mode)
    ZEND_PARSE_PARAMETERS_END();

    if (rounding_mode_case) {
        zend_string *name = Z_STR_P(zend_enum_fetch_case_name(rounding_mode_case));

        if (zend_string_equals_literal(name, "Nearest")) {
            use_inclusive = false;
        }
        // "Inclusive" is the default, so no need to check explicitly
    }

    rect = *pango_rectangle_object_get_rectangle(rectangle_zv);

    // Call with inclusive rounding
    if (use_inclusive) {
        pango_extents_to_pixels(&rect, NULL);
    }
    // Call with nearest rounding
    else {
        pango_extents_to_pixels(NULL, &rect);
    }

    object_init_ex(return_value, ce_pango_rectangle);
    *pango_rectangle_object_get_rectangle(return_value) = rect;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Rectangle Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_rectangle_free_obj(zend_object *object)
{
    pango_rectangle_object *intern = pango_rectangle_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->rect) {
        efree(intern->rect);
        intern->rect = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_rectangle_obj_ctor(zend_class_entry *ce, pango_rectangle_object **intern)
{
    pango_rectangle_object *object = ecalloc(1, sizeof(pango_rectangle_object) + zend_object_properties_size(ce));
    PANGO_ALLOC_RECT(object->rect);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_rectangle_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_rectangle_create_object(zend_class_entry *ce)
{
    pango_rectangle_object *intern = NULL;
    zend_object *return_value = pango_rectangle_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_rectangle_clone_obj(zend_object *zobj)
{
    pango_rectangle_object *new_rectangle;
    pango_rectangle_object *old_rectangle = pango_rectangle_fetch_object(zobj);
    zend_object *return_value = pango_rectangle_obj_ctor(zobj->ce, &new_rectangle);
    PANGO_ALLOC_RECT(new_rectangle->rect);

    *new_rectangle->rect = *old_rectangle->rect;

    zend_objects_clone_members(&new_rectangle->std, &old_rectangle->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_rectangle_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_rectangle_object *rectangle_object = pango_rectangle_fetch_object(object);

    if (!rectangle_object) {
        return rv;
    }

    PANGO_VALUE_FROM_STRUCT(x);
    PANGO_VALUE_FROM_STRUCT(y);
    PANGO_VALUE_FROM_STRUCT(width);
    PANGO_VALUE_FROM_STRUCT(height);
    PANGO_MACRO_VALUE_FROM_STRUCT(ascent, PANGO_ASCENT);
    PANGO_MACRO_VALUE_FROM_STRUCT(descent, PANGO_DESCENT);
    PANGO_MACRO_VALUE_FROM_STRUCT(leftBearing, PANGO_LBEARING);
    PANGO_MACRO_VALUE_FROM_STRUCT(rightBearing, PANGO_RBEARING);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_rectangle_object_get_properties(zend_object *object)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_rectangle_object *rectangle_object = pango_rectangle_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!rectangle_object->rect) {
        return props;
    }

    PANGO_ADD_STRUCT_VALUE(x);
    PANGO_ADD_STRUCT_VALUE(y);
    PANGO_ADD_STRUCT_VALUE(width);
    PANGO_ADD_STRUCT_VALUE(height);
    PANGO_MACRO_ADD_STRUCT_VALUE(ascent, PANGO_ASCENT);
    PANGO_MACRO_ADD_STRUCT_VALUE(descent, PANGO_DESCENT);
    PANGO_MACRO_ADD_STRUCT_VALUE(leftBearing, PANGO_LBEARING);
    PANGO_MACRO_ADD_STRUCT_VALUE(rightBearing, PANGO_RBEARING);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Rectangle Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_rectangle)
{
    memcpy(
        &pango_rectangle_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_rectangle_object_handlers.offset = XtOffsetOf(pango_rectangle_object, std);
    pango_rectangle_object_handlers.free_obj = pango_rectangle_free_obj;
    pango_rectangle_object_handlers.clone_obj = pango_rectangle_clone_obj;
    pango_rectangle_object_handlers.read_property = pango_rectangle_object_read_property;
    // pango_rectangle_object_handlers.write_property = pango_rectangle_object_write_property;
    pango_rectangle_object_handlers.get_property_ptr_ptr = NULL;
    pango_rectangle_object_handlers.get_properties = pango_rectangle_object_get_properties;

    ce_pango_rectangle = register_class_Pango_Rectangle();
    ce_pango_rectangle->create_object = pango_rectangle_create_object;

    // Pango\RoundingMode enum
    ce_pango_rounding_mode = register_class_Pango_RoundingMode();

    return SUCCESS;
}
/* }}} */
