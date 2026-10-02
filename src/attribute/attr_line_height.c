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

zend_class_entry *ce_pango_attr_line_height;

static zend_object_handlers pango_attr_line_height_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\LineHeight C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrFloat *pango_attr_line_height_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Float);
}
/* }}} */

zend_class_entry* php_pango_get_attr_line_height_ce(void)
{
    return ce_pango_attr_line_height;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\LineHeight Class API
------------------------------------------------------------------*/

/* {{{ Creates a new LineHeight attribute */
PHP_METHOD(Pango_Attribute_LineHeight, __construct)
{
    double value;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(value)
    ZEND_PARSE_PARAMETERS_END();

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_line_height_new(value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\LineHeight Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(line_height);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(line_height);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(line_height);
/* }}} */

/* {{{ */
static zval *pango_attr_line_height_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(Float, DOUBLE, value);
}
/* }}} */

/* {{{ */
static zval *pango_attr_line_height_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    PANGO_ATTR_WRITE_PROPERTY(Float, DOUBLE, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_line_height_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(Float, DOUBLE, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\LineHeight Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_line_height)
{
    memcpy(
        &pango_attr_line_height_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_line_height_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_line_height_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_line_height_object_handlers.clone_obj = pango_attr_line_height_clone_obj;
    pango_attr_line_height_object_handlers.read_property = pango_attr_line_height_object_read_property;
    pango_attr_line_height_object_handlers.write_property = pango_attr_line_height_object_write_property;
    pango_attr_line_height_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_line_height_object_handlers.get_properties_for = pango_attr_line_height_object_get_properties_for;
    pango_attr_line_height_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_line_height = register_class_Pango_Attribute_LineHeight(php_pango_get_attribute_ce());
    ce_pango_attr_line_height->create_object = pango_attr_line_height_create_object;

    return SUCCESS;
}
/* }}} */
