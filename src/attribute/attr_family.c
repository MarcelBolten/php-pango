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

zend_class_entry *ce_pango_attr_family;

static zend_object_handlers pango_attr_family_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\Family C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrString *pango_attr_family_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(String);
}
/* }}} */

zend_class_entry* php_pango_get_attr_family_ce(void)
{
    return ce_pango_attr_family;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Family Class API
------------------------------------------------------------------*/

/* {{{ Creates a new family attribute */
PHP_METHOD(Pango_Attribute_Family, __construct)
{
    zend_string *family = NULL;
    size_t family_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(family)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(family)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_family_new(ZSTR_VAL(family));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Family Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(family);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(family);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(family);
/* }}} */

/* {{{ */
static zval *pango_attr_family_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(String, STRING, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_family_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(String, STRING, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Family Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_family)
{
    memcpy(
        &pango_attr_family_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_family_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_family_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_family_object_handlers.clone_obj = pango_attr_family_clone_obj;
    pango_attr_family_object_handlers.read_property = pango_attr_family_object_read_property;
    pango_attr_family_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_family_object_handlers.get_properties_for = pango_attr_family_object_get_properties_for;
    pango_attr_family_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_family = register_class_Pango_Attribute_Family(php_pango_get_attribute_ce());
    ce_pango_attr_family->create_object = pango_attr_family_create_object;

    return SUCCESS;
}
/* }}} */
