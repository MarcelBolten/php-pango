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

zend_class_entry *ce_pango_attr_foreground_alpha;

static zend_object_handlers pango_attr_foreground_alpha_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\ForegroundAlpha C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_foreground_alpha_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

zend_class_entry* php_pango_get_attr_foreground_alpha_ce(void)
{
    return ce_pango_attr_foreground_alpha;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\ForegroundAlpha Class API
------------------------------------------------------------------*/

/* {{{ Creates a new letter spacing attribute */
PHP_METHOD(Pango_Attribute_ForegroundAlpha, __construct)
{
    PANGO_ATTR_CONSTRUCT(pango_attr_foreground_alpha_new, zend_long, LONG);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\ForegroundAlpha Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(foreground_alpha);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(foreground_alpha);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(foreground_alpha);
/* }}} */

/* {{{ */
static zval *pango_attr_foreground_alpha_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(Int, LONG, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_foreground_alpha_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(Int, LONG, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\ForegroundAlpha Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_foreground_alpha)
{
    memcpy(
        &pango_attr_foreground_alpha_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_foreground_alpha_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_foreground_alpha_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_foreground_alpha_object_handlers.clone_obj = pango_attr_foreground_alpha_clone_obj;
    pango_attr_foreground_alpha_object_handlers.read_property = pango_attr_foreground_alpha_object_read_property;
    pango_attr_foreground_alpha_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_foreground_alpha_object_handlers.get_properties_for = pango_attr_foreground_alpha_object_get_properties_for;
    pango_attr_foreground_alpha_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_foreground_alpha = register_class_Pango_Attribute_ForegroundAlpha(php_pango_get_attribute_ce());
    ce_pango_attr_foreground_alpha->create_object = pango_attr_foreground_alpha_create_object;

    return SUCCESS;
}
/* }}} */
