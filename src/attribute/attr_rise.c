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
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_rise;

static zend_object_handlers pango_attr_rise_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\Rise C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_rise_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

zend_class_entry* php_pango_get_attr_rise_ce(void)
{
    return ce_pango_attr_rise;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Rise Class API
------------------------------------------------------------------*/

/* {{{ Creates a new rise attribute */
PHP_METHOD(Pango_Attribute_Rise, __construct)
{
    zend_long value;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(value)
    ZEND_PARSE_PARAMETERS_END();

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_rise_new(value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Rise Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(rise);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(rise);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(rise);
/* }}} */

/* {{{ */
static zval *pango_attr_rise_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(Int, LONG, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_rise_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(Int, LONG, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Rise Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_rise)
{
    memcpy(
        &pango_attr_rise_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_rise_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_rise_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_rise_object_handlers.clone_obj = pango_attr_rise_clone_obj;
    pango_attr_rise_object_handlers.read_property = pango_attr_rise_object_read_property;
    pango_attr_rise_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_rise_object_handlers.get_properties_for = pango_attr_rise_object_get_properties_for;
    pango_attr_rise_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_rise = register_class_Pango_Attribute_Rise(php_pango_get_attribute_ce());
    ce_pango_attr_rise->create_object = pango_attr_rise_create_object;

    return SUCCESS;
}
/* }}} */
