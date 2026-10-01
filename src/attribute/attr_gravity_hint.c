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
#include "../context.h"
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_gravity_hint;

static zend_object_handlers pango_attr_gravity_hint_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\GravityHint C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_gravity_hint_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

PHP_PANGO_API zend_class_entry* php_pango_get_attr_gravity_hint_ce()
{
    return ce_pango_attr_gravity_hint;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\GravityHint Class API
------------------------------------------------------------------*/

/* {{{ Creates a new gravity_hint attribute */
PHP_METHOD(Pango_Attribute_GravityHint, __construct)
{
    zend_object *gravity_hint;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(gravity_hint, php_pango_get_gravity_hint_ce())
    ZEND_PARSE_PARAMETERS_END();

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_gravity_hint_new(
        Z_LVAL_P(zend_enum_fetch_case_value(gravity_hint))
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\GravityHint Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(gravity_hint);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(gravity_hint);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(gravity_hint);
/* }}} */

/* {{{ */
static zval *pango_attr_gravity_hint_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_ENUM_READ_PROPERTY(php_pango_get_gravity_hint_ce());
}
/* }}} */

/* {{{ */
static zval *pango_attr_gravity_hint_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    PANGO_ATTR_ENUM_WRITE_PROPERTY(php_pango_get_gravity_hint_ce());
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_gravity_hint_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_ENUM_GET_PROPERTIES(php_pango_get_gravity_hint_ce());
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\GravityHint Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_gravity_hint)
{
    memcpy(
        &pango_attr_gravity_hint_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_gravity_hint_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_gravity_hint_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_gravity_hint_object_handlers.clone_obj = pango_attr_gravity_hint_clone_obj;
    pango_attr_gravity_hint_object_handlers.read_property = pango_attr_gravity_hint_object_read_property;
    pango_attr_gravity_hint_object_handlers.write_property = pango_attr_gravity_hint_object_write_property;
    pango_attr_gravity_hint_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_gravity_hint_object_handlers.get_properties_for = pango_attr_gravity_hint_object_get_properties_for;
    pango_attr_gravity_hint_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_gravity_hint = register_class_Pango_Attribute_GravityHint(php_pango_get_attribute_ce());
    ce_pango_attr_gravity_hint->create_object = pango_attr_gravity_hint_create_object;

    return SUCCESS;
}
/* }}} */
