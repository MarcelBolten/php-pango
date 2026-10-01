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
#include <Zend/zend_enum.h>

#include "../../php_pango.h"
#include "../php_pango_macros.h"
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_baseline_shift;

static zend_object_handlers pango_attr_baseline_shift_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\BaselineShift C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_baseline_shift_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

zend_class_entry* php_pango_get_attr_baseline_shift_ce()
{
    return ce_pango_attr_baseline_shift;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\BaselineShift Class API
------------------------------------------------------------------*/

/* {{{ Creates a new baseline_shift attribute */
PHP_METHOD(Pango_Attribute_BaselineShift, __construct)
{
    zend_object *baseline_shift_enum = NULL;
    zend_long baseline_shift_value;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS_OR_LONG(baseline_shift_enum, php_pango_get_baseline_shift_ce(), baseline_shift_value)
    ZEND_PARSE_PARAMETERS_END();

    if (baseline_shift_enum) {
        baseline_shift_value = Z_LVAL_P(zend_enum_fetch_case_value(baseline_shift_enum));
    }

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_baseline_shift_new(baseline_shift_value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\BaselineShift Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(baseline_shift);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(baseline_shift);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(baseline_shift);
/* }}} */

/* {{{ */
static zval *pango_attr_baseline_shift_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

    if (!attr_object) {
        return rv;
    }

    PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute;

    if (attr->value > 1024) {
        PANGO_LONG_VALUE_FROM_STRUCT(attr->value, value);
    } else {
        PANGO_ENUM_VALUE_FROM_STRUCT(attr->value, value, php_pango_get_baseline_shift_ce());
    }
    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr);

    return rv;
}
/* }}} */

/* {{{ */
static zval *pango_attr_baseline_shift_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object);
    zval *retval = NULL;

    if (!attr_object) {
        return retval;
    }

    do {
        PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute;

        if (zend_string_equals_literal(member, "value")) {
            if (Z_TYPE_P(value) == IS_OBJECT && Z_OBJCE_P(value) == php_pango_get_baseline_shift_ce()) {
                value = zend_enum_fetch_case_value(Z_OBJ_P(value));
            }

            if (Z_TYPE_P(value) != IS_LONG) {
                zend_type_error(
                    "Cannot assign %s to property %s::$%s of type %s|int",
                    zend_zval_type_name(value),
                    ZSTR_VAL(object->ce->name),
                    "value",
                    ZSTR_VAL(php_pango_get_baseline_shift_ce()->name)
                );
                return retval;
            }

            attr->value = zval_get_long(value);
            break;
        }

        PANGO_ATTR_RANGE_WRITE_PROPERTY(&attr->attr);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);
    } while(0);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_baseline_shift_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!attr_object->attribute) {
        return props;
    }

    PangoAttrInt *attr = (PangoAttrInt *)attr_object->attribute;

    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr);

    if (attr->value > 1024) {
        PANGO_ADD_STRUCT_LONG_VALUE(attr->value, value);
    } else {
        PANGO_ADD_STRUCT_ENUM_VALUE(attr->value, value, php_pango_get_baseline_shift_ce());
    }

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\BaselineShift Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_baseline_shift)
{
    memcpy(
        &pango_attr_baseline_shift_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_baseline_shift_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_baseline_shift_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_baseline_shift_object_handlers.clone_obj = pango_attr_baseline_shift_clone_obj;
    pango_attr_baseline_shift_object_handlers.read_property = pango_attr_baseline_shift_object_read_property;
    pango_attr_baseline_shift_object_handlers.write_property = pango_attr_baseline_shift_object_write_property;
    pango_attr_baseline_shift_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_baseline_shift_object_handlers.get_properties_for = pango_attr_baseline_shift_object_get_properties_for;
    pango_attr_baseline_shift_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_baseline_shift = register_class_Pango_Attribute_BaselineShift(php_pango_get_attribute_ce());
    ce_pango_attr_baseline_shift->create_object = pango_attr_baseline_shift_create_object;

    return SUCCESS;
}
/* }}} */
