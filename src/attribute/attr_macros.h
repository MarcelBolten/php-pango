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

#include "../../php_pango.h"
#include "../php_pango_macros.h"
#include "attribute.h"

#define PANGO_ATTR_OBJECT_GET_ATTR(type) \
    pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(zv); \
    return (PangoAttr ## type *) attr_object->attribute;

#define PANGO_ATTR_OBJ_CTOR(name) \
static zend_object* pango_attr_ ## name ## _obj_ctor(zend_class_entry *ce, pango_attribute_object **intern) \
{ \
    pango_attribute_object *object = ecalloc(1, sizeof(pango_attribute_object) + zend_object_properties_size(ce)); \
    zend_object_std_init(&object->std, ce); \
\
    object->std.handlers = &pango_attr_ ## name ## _object_handlers; \
    *intern = object; \
\
    return &object->std; \
}

#define PANGO_ATTR_CREATE_OBJECT(name) \
static zend_object* pango_attr_ ## name ## _create_object(zend_class_entry *ce) \
{ \
    pango_attribute_object *intern = NULL; \
    zend_object *return_value = pango_attr_ ## name ## _obj_ctor(ce, &intern); \
\
    object_properties_init(&intern->std, ce); \
    return return_value; \
}

#define PANGO_ATTR_CLONE_OBJECT(name) \
static zend_object* pango_attr_ ## name ## _clone_obj(zend_object *zobj) \
{ \
    pango_attribute_object *new_attr; \
    pango_attribute_object *old_attr = pango_attribute_fetch_object(zobj); \
    zend_object *return_value = pango_attr_ ## name ## _obj_ctor(zobj->ce, &new_attr); \
\
    if (old_attr->attribute) { \
        new_attr->attribute = pango_attribute_copy(old_attr->attribute); \
    } \
\
    zend_objects_clone_members(&new_attr->std, &old_attr->std); \
\
    return return_value; \
}

#define PANGO_ATTR_RANGE_READ_PROPERTY(_attr) \
    PANGO_LONG_VALUE_FROM_STRUCT((_attr)->start_index, startIndex); \
    PANGO_LONG_VALUE_FROM_STRUCT((_attr)->end_index, endIndex);

#define PANGO_ATTR_RANGE_WRITE_PROPERTY(_attr) \
    PANGO_LONG_VALUE_TO_STRUCT((_attr)->start_index, startIndex); \
    PANGO_LONG_VALUE_TO_STRUCT((_attr)->end_index, endIndex);

#define PANGO_ATTR_ADD_RANGE_PROPERTIES(_attr) \
    PANGO_ADD_STRUCT_LONG_VALUE((_attr)->start_index, startIndex); \
    PANGO_ADD_STRUCT_LONG_VALUE((_attr)->end_index, endIndex);

#define PANGO_ATTR_READ_PROPERTY(pango_type, php_type, pango_member) \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    if (!attr_object) { \
        return rv; \
    } \
\
    PangoAttr ## pango_type *attr = (PangoAttr ## pango_type *)attr_object->attribute; \
\
    PANGO_ ## php_type ## _VALUE_FROM_STRUCT(attr->pango_member, value); \
    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr); \
\
    return rv;

#define PANGO_ATTR_WRITE_PROPERTY(pango_type, php_type, pango_member) \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
    zval *retval = NULL; \
\
    if (!attr_object) { \
        return retval; \
    } \
\
    do { \
        PangoAttr ## pango_type *attr = (PangoAttr ## pango_type *)attr_object->attribute; \
\
        PANGO_ ## php_type ## _VALUE_TO_STRUCT(attr->pango_member, value); \
        PANGO_ATTR_RANGE_WRITE_PROPERTY(&attr->attr); \
\
        /* not a struct member */ \
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot); \
    } while(0); \
\
    return retval;

#define PANGO_ATTR_GET_PROPERTIES(pango_type, php_type, pango_member) \
    HashTable *props; \
    /* used in macros below */ \
    zval tmp; \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    props = zend_array_dup(zend_std_get_properties(object)); \
\
    if (!attr_object->attribute) { \
        return props; \
    } \
\
    PangoAttr ## pango_type *attr = (PangoAttr ## pango_type *)attr_object->attribute; \
\
    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr); \
    PANGO_ADD_STRUCT_ ## php_type ## _VALUE(attr->pango_member, value); \
\
    return props; \

#define PANGO_ATTR_ENUM_READ_PROPERTY(_ce) \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    if (!attr_object) { \
        return rv; \
    } \
\
    PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute; \
\
    PANGO_ENUM_VALUE_FROM_STRUCT(attr->value, value, _ce); \
    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr); \
\
    return rv;

#define PANGO_ATTR_ENUM_WRITE_PROPERTY(_ce) \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
    zval *retval = NULL; \
\
    if (!attr_object) { \
        return retval; \
    } \
\
    do { \
        PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute; \
\
        PANGO_ENUM_VALUE_TO_STRUCT(attr->value, value, _ce); \
        PANGO_ATTR_RANGE_WRITE_PROPERTY(&attr->attr); \
\
        /* not a struct member */ \
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot); \
    } while(0); \
\
    return retval;

#define PANGO_ATTR_ENUM_GET_PROPERTIES(_ce) \
    HashTable *props; \
    /* used in macros below */ \
    zval tmp; \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    props = zend_array_dup(zend_std_get_properties(object)); \
\
    if (!attr_object->attribute) { \
        return props; \
    } \
\
    PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute; \
\
    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr); \
    PANGO_ADD_STRUCT_ENUM_VALUE(attr->value, value, _ce); \
\
    return props;

#define PANGO_ATTR_COLOR_READ_PROPERTY \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    if (!attr_object) { \
        return rv; \
    } \
\
    PangoAttrColor *attr = (PangoAttrColor *)attr_object->attribute; \
\
    PANGO_COLOR_VALUE_FROM_STRUCT; \
    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr); \
\
    return rv;

#define PANGO_ATTR_COLOR_WRITE_PROPERTY \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
    zval *retval = NULL; \
\
    if (!attr_object) { \
        return retval; \
    } \
\
    do { \
        PangoAttrColor *attr = (PangoAttrColor *)attr_object->attribute; \
\
        PANGO_COLOR_VALUE_TO_STRUCT; \
        PANGO_ATTR_RANGE_WRITE_PROPERTY(&attr->attr); \
\
        /* not a struct member */ \
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot); \
    } while(0); \
\
    return retval;

#define PANGO_ATTR_COLOR_GET_PROPERTIES \
    HashTable *props; \
    /* used in macros below */ \
    zval tmp; \
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object); \
\
    props = zend_array_dup(zend_std_get_properties(object)); \
\
    if (!attr_object->attribute) { \
        return props; \
    } \
\
    PangoAttrColor *attr = (PangoAttrColor *)attr_object->attribute; \
\
    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr); \
    PANGO_ADD_STRUCT_COLOR_VALUE; \
\
    return props;

