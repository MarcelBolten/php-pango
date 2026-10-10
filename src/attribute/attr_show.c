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
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_show;

static zend_object_handlers pango_attr_show_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\Show C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_show_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

zend_class_entry* php_pango_get_attr_show_ce(void)
{
    return ce_pango_attr_show;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Show Class API
------------------------------------------------------------------*/

/* {{{ Creates a new letter spacing attribute */
PHP_METHOD(Pango_Attribute_Show, __construct)
{
    zend_long value;
    zend_long start_index = PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING;
    zend_long end_index = PHP_PANGO_ATTR_INDEX_TO_TEXT_END;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_LONG(value)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start_index)
        Z_PARAM_LONG(end_index)
    ZEND_PARSE_PARAMETERS_END();

    if (value < PANGO_SHOW_NONE
        || value > (PANGO_SHOW_SPACES | PANGO_SHOW_LINE_BREAKS | PANGO_SHOW_IGNORABLES)
    ) {
        zend_argument_value_error(1, "must be a class constant of Pango\\Attribute\\Show or a combination of them");
        RETURN_THROWS();
    }

    PANGO_ATTR_CHECK_INDICES(start_index, end_index);

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_show_new(value);
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->start_index = start_index;
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->end_index = end_index;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Show Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(show);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(show);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(show);
/* }}} */

/* {{{ */
static zval *pango_attr_show_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(Int, LONG, value);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_show_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(Int, LONG, value);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Show Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_show)
{
    memcpy(
        &pango_attr_show_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_show_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_show_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_show_object_handlers.clone_obj = pango_attr_show_clone_obj;
    pango_attr_show_object_handlers.read_property = pango_attr_show_object_read_property;
    pango_attr_show_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_show_object_handlers.get_properties_for = pango_attr_show_object_get_properties_for;
    pango_attr_show_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_show = register_class_Pango_Attribute_Show(php_pango_get_attribute_ce());
    ce_pango_attr_show->create_object = pango_attr_show_create_object;

    return SUCCESS;
}
/* }}} */
