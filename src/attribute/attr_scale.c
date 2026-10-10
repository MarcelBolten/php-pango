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

zend_class_entry *ce_pango_attr_scale;

static zend_object_handlers pango_attr_scale_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\Scale C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrFloat *pango_attr_scale_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Float);
}
/* }}} */

zend_class_entry* php_pango_get_attr_scale_ce(void)
{
    return ce_pango_attr_scale;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Scale Class API
------------------------------------------------------------------*/

/* {{{ Creates a new Scale attribute */
PHP_METHOD(Pango_Attribute_Scale, __construct)
{
    PANGO_ATTR_CONSTRUCT(pango_attr_scale_new, double, DOUBLE);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Scale Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(scale);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(scale);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(scale);
/* }}} */

/* {{{ */
static zval *pango_attr_scale_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(Float, DOUBLE, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_scale_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(Float, DOUBLE, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Scale Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_scale)
{
    memcpy(
        &pango_attr_scale_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_scale_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_scale_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_scale_object_handlers.clone_obj = pango_attr_scale_clone_obj;
    pango_attr_scale_object_handlers.read_property = pango_attr_scale_object_read_property;
    pango_attr_scale_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_scale_object_handlers.get_properties_for = pango_attr_scale_object_get_properties_for;
    pango_attr_scale_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_scale = register_class_Pango_Attribute_Scale(php_pango_get_attribute_ce());
    ce_pango_attr_scale->create_object = pango_attr_scale_create_object;

    return SUCCESS;
}
/* }}} */
