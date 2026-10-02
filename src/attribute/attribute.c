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
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attribute;
zend_class_entry *ce_pango_underline;
zend_class_entry *ce_pango_overline;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
zend_class_entry *ce_pango_text_transform;
zend_class_entry *ce_pango_baseline_shift;
zend_class_entry *ce_pango_font_scale;
#endif
zend_class_entry *ce_pango_attribute_type;

static zend_object_handlers pango_attribute_object_handlers;

pango_attribute_object *pango_attribute_fetch_object(zend_object *object)
{
    return (pango_attribute_object *) ((char*)(object) - offsetof(pango_attribute_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Attribute C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttribute *pango_attribute_object_get_attribute(zval *zv)
{
    pango_attribute_object *attribute_object = Z_PANGO_ATTRIBUTE_P(zv);

    return attribute_object->attribute;
}
/* }}} */

zend_class_entry* php_pango_get_attribute_ce(void)
{
    return ce_pango_attribute;
}

zend_class_entry* php_pango_get_underline_ce(void)
{
    return ce_pango_underline;
}

zend_class_entry* php_pango_get_overline_ce(void)
{
    return ce_pango_overline;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
zend_class_entry* php_pango_get_text_transform_ce(void)
{
    return ce_pango_text_transform;
}

zend_class_entry* php_pango_get_baseline_shift_ce(void)
{
    return ce_pango_baseline_shift;
}

zend_class_entry* php_pango_get_font_scale_ce(void)
{
    return ce_pango_font_scale;
}
#endif

zend_class_entry* php_pango_get_attribute_type_ce(void)
{
    return ce_pango_attribute_type;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Attribute Class API
------------------------------------------------------------------*/

/* {{{  */
PHP_METHOD(Pango_Attribute_Attribute, equalValue)
{
    zval *other_zv;
    PangoAttribute *this_attr;
    PangoAttribute *other_attr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(other_zv, php_pango_get_attribute_ce())
    ZEND_PARSE_PARAMETERS_END();

    this_attr = pango_attribute_object_get_attribute(ZEND_THIS);
    other_attr = pango_attribute_object_get_attribute(other_zv);

    if (!this_attr || !other_attr) {
        RETURN_FALSE;
    }

    RETURN_BOOL(pango_attribute_equal(this_attr, other_attr));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Attribute Object management
------------------------------------------------------------------*/

/* {{{ */
// static void pango_attribute_free_obj(zend_object *object)
// {
//     pango_attribute_object *intern = pango_attribute_fetch_object(object);

//     if (!intern) {
//         return;
//     }

//     zend_object_std_dtor(&intern->std);
// }
/* }}} */

/* {{{ */
// static zend_object* pango_attribute_obj_ctor(zend_class_entry *ce, pango_attribute_object **intern)
// {
//     pango_attribute_object *object = ecalloc(1, sizeof(pango_attribute_object) + zend_object_properties_size(ce));

//     zend_object_std_init(&object->std, ce);

//     object->std.handlers = &pango_attribute_object_handlers;
//     *intern = object;

//     return &object->std;
// }
/* }}} */

/* {{{ */
// static zend_object* pango_attribute_create_object(zend_class_entry *ce)
// {
//     pango_attribute_object *intern = NULL;
//     zend_object *return_value = pango_attribute_obj_ctor(ce, &intern);

//     object_properties_init(&intern->std, ce);
//     return return_value;
// }
/* }}} */

// /* {{{ */
// static zend_object* pango_attribute_clone_obj(zend_object *zobj)
// {
//     pango_attribute_object *new_attribute;
//     pango_attribute_object *old_attribute = pango_attribute_fetch_object(zobj);
//     zend_object *return_value = pango_attribute_obj_ctor(zobj->ce, &new_attribute);

//     new_attribute->attribute = pango_attribute_copy(old_attribute->attribute);

//     zend_objects_clone_members(&new_attribute->std, &old_attribute->std);

//     return return_value;
// }
// /* }}} */

// /* {{{ */
// static zval *pango_attribute_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
// {
//     pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

//     if (!attr_object) {
//         return rv;
//     }

//     PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute;

//     PANGO_LONG_VALUE_FROM_STRUCT(attr->attr.start_index, startIndex);
//     PANGO_LONG_VALUE_FROM_STRUCT(attr->attr.end_index, endIndex);

//     return rv;
// }
// /* }}} */

// /* {{{ */
// static HashTable *pango_attribute_object_get_properties(zend_object *object)
// {
//     HashTable *props;
//     // used in macros below
//     zval tmp;
//     pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

//     props = zend_std_get_properties(object);

//     if (!attr_object->attribute) {
//         return props;
//     }

//     PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute;

//     PANGO_ADD_STRUCT_LONG_VALUE(attr->attr.start_index, startIndex);
//     PANGO_ADD_STRUCT_LONG_VALUE(attr->attr.end_index, endIndex);

//     return props;
// }
// /* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Attribute Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attribute)
{
    memcpy(
        &pango_attribute_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attribute_object_handlers.offset = offsetof(pango_attribute_object, std);
    // pango_attribute_object_handlers.free_obj = pango_attribute_free_obj;
    // pango_attribute_object_handlers.clone_obj = pango_attribute_clone_obj;
    // pango_attribute_object_handlers.read_property = pango_attribute_object_read_property;
    // pango_attribute_object_handlers.write_property = pango_attribute_object_write_property;
    pango_attribute_object_handlers.get_property_ptr_ptr = NULL;
    // pango_attribute_object_handlers.get_properties_for = pango_attribute_object_get_properties;
    // pango_attribute_object_handlers.compare = pango_attribute_object_compare;

    ce_pango_attribute = register_class_Pango_Attribute_Attribute();
    // ce_pango_attribute->create_object = pango_attribute_create_object;

    ce_pango_underline = register_class_Pango_Underline();
    ce_pango_overline = register_class_Pango_Overline();

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    ce_pango_text_transform = register_class_Pango_TextTransform();
    ce_pango_baseline_shift = register_class_Pango_BaselineShift();
    ce_pango_font_scale = register_class_Pango_FontScale();
#endif

    ce_pango_attribute_type = register_class_Pango_Attribute_AttributeType();

    return SUCCESS;
}
/* }}} */
