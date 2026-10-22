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

#include "../../php_pango.h"
#include "../php_pango_macros.h"
#include "../rectangle.h"
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_shape;

static zend_object_handlers pango_attr_shape_object_handlers;

pango_attr_shape_object *pango_attr_shape_fetch_object(zend_object *object)
{
    return (pango_attr_shape_object *) ((char*)(object) - offsetof(pango_attr_shape_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Attribute\ShapeAttribute C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttribute *pango_attr_shape_object_get_attribute(zval *zv)
{
    return (PangoAttribute *) Z_PANGO_ATTR_SHAPE_P(zv)->attribute;
}
/* }}} */

zend_class_entry* php_pango_get_attr_shape_ce(void)
{
    return ce_pango_attr_shape;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\ShapeAttribute Class API
------------------------------------------------------------------*/

/* {{{ Creates a new font_description attribute */
PHP_METHOD(Pango_Attribute_ShapeAttribute, __construct)
{
    zval *ink_rect_zv;
    zval *logical_rect_zv;
    zend_long start_index = PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING;
    zend_long end_index = PHP_PANGO_ATTR_INDEX_TO_TEXT_END;
    pango_attr_shape_object *attr_object;
    PangoRectangle *ink_rect;
    PangoRectangle *logical_rect;

    ZEND_PARSE_PARAMETERS_START(2, 4)
        Z_PARAM_OBJECT_OF_CLASS(ink_rect_zv, php_pango_get_rectangle_ce())
        Z_PARAM_OBJECT_OF_CLASS(logical_rect_zv, php_pango_get_rectangle_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start_index)
        Z_PARAM_LONG(end_index)
    ZEND_PARSE_PARAMETERS_END();

    PANGO_ATTR_CHECK_INDICES(start_index, 3, end_index, 4);

    attr_object = Z_PANGO_ATTR_SHAPE_P(ZEND_THIS);

    zval_ptr_dtor(&attr_object->ink_rect_zv);
    ZVAL_COPY(&attr_object->ink_rect_zv, ink_rect_zv);
    zval_ptr_dtor(&attr_object->logical_rect_zv);
    ZVAL_COPY(&attr_object->logical_rect_zv, logical_rect_zv);

    ink_rect = Z_PANGO_RECTANGLE_P(ink_rect_zv)->rect;
    logical_rect = Z_PANGO_RECTANGLE_P(logical_rect_zv)->rect;
    attr_object->attribute = pango_attr_shape_new(ink_rect, logical_rect);
    attr_object->attribute->start_index = start_index;
    attr_object->attribute->end_index = end_index;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\ShapeAttribute Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_attr_shape_free_obj(zend_object *object)
{
    pango_attr_shape_object *intern = pango_attr_shape_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->attribute) {
        pango_attribute_destroy(intern->attribute);
        intern->attribute = NULL;
    }

    zval_ptr_dtor(&intern->ink_rect_zv);
    zval_ptr_dtor(&intern->logical_rect_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_shape_obj_ctor(zend_class_entry *ce, pango_attr_shape_object **intern)
{
    pango_attr_shape_object *object = ecalloc(1, sizeof(pango_attr_shape_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->ink_rect_zv);
    ZVAL_UNDEF(&object->logical_rect_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_attr_shape_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_shape_create_object(zend_class_entry *ce)
{
    pango_attr_shape_object *intern = NULL;
    zend_object *return_value = pango_attr_shape_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_shape_clone_obj(zend_object *zobj)
{
    pango_attr_shape_object *new_attr;
    pango_attr_shape_object *old_attr = pango_attr_shape_fetch_object(zobj);
    zend_object *return_value = pango_attr_shape_obj_ctor(zobj->ce, &new_attr);

    if (old_attr->attribute) {
        new_attr->attribute = pango_attribute_copy(old_attr->attribute);
    }

    zval_ptr_dtor(&new_attr->ink_rect_zv);
    zval_ptr_dtor(&new_attr->logical_rect_zv);
    ZVAL_COPY(&new_attr->ink_rect_zv, &old_attr->ink_rect_zv);
    ZVAL_COPY(&new_attr->logical_rect_zv, &old_attr->logical_rect_zv);

    zend_objects_clone_members(&new_attr->std, &old_attr->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_attr_shape_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_attr_shape_object *attr_object = pango_attr_shape_fetch_object(object);

    if (!attr_object) {
        return rv;
    }

    if (strcmp(member->val, "inkRect") == 0) {
        ZVAL_COPY(rv, &attr_object->ink_rect_zv);
        return rv;
    }
    if (strcmp(member->val, "logicalRect") == 0) {
        ZVAL_COPY(rv, &attr_object->logical_rect_zv);
        return rv;
    }

    PangoAttrShape *attr = (PangoAttrShape *)attr_object->attribute;

    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_shape_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_attr_shape_object *attr_object = pango_attr_shape_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!attr_object->attribute) {
        return props;
    }

    PangoAttrShape *attr = (PangoAttrShape *)attr_object->attribute;
    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr);

    ZVAL_COPY(&tmp, &attr_object->ink_rect_zv);
    zend_hash_str_update(props, "inkRect", sizeof("inkRect")-1, &tmp);
    ZVAL_COPY(&tmp, &attr_object->logical_rect_zv);
    zend_hash_str_update(props, "logicalRect", sizeof("logicalRect")-1, &tmp);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\ShapeAttribute Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_shape)
{
    memcpy(
        &pango_attr_shape_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_shape_object_handlers.offset = offsetof(pango_attr_shape_object, std);
    pango_attr_shape_object_handlers.free_obj = pango_attr_shape_free_obj;
    pango_attr_shape_object_handlers.clone_obj = pango_attr_shape_clone_obj;
    pango_attr_shape_object_handlers.read_property = pango_attr_shape_object_read_property;
    pango_attr_shape_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_shape_object_handlers.get_properties_for = pango_attr_shape_object_get_properties_for;
    pango_attr_shape_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_shape = register_class_Pango_Attribute_ShapeAttribute(php_pango_get_attribute_ce());
    ce_pango_attr_shape->create_object = pango_attr_shape_create_object;

    return SUCCESS;
}
/* }}} */
