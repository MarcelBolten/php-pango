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
#include "../color.h"
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_overline_color;

static zend_object_handlers pango_attr_overline_color_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\OverlineColor C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrColor *pango_attr_overline_color_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Color);
}
/* }}} */

zend_class_entry* php_pango_get_attr_overline_color_ce(void)
{
    return ce_pango_attr_overline_color;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\OverlineColor Class API
------------------------------------------------------------------*/

/* {{{ Creates a new overline_color attribute */
PHP_METHOD(Pango_Attribute_OverlineColor, __construct)
{
    zend_object *color_obj;
    zend_long start_index = PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING;
    zend_long end_index = PHP_PANGO_ATTR_INDEX_TO_TEXT_END;
    PangoColor *color;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_OBJ_OF_CLASS(color_obj, php_pango_get_color_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start_index)
        Z_PARAM_LONG(end_index)
    ZEND_PARSE_PARAMETERS_END();

    PANGO_ATTR_CHECK_INDICES(start_index, end_index);

    color = pango_color_fetch_object(color_obj)->color;
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_overline_color_new(
        color->red,
        color->green,
        color->blue
    );
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->start_index = start_index;
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->end_index = end_index;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\OverlineColor Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(overline_color);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(overline_color);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(overline_color);
/* }}} */

/* {{{ */
static zval *pango_attr_overline_color_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_COLOR_READ_PROPERTY;
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_overline_color_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_COLOR_GET_PROPERTIES;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\OverlineColor Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_overline_color)
{
    memcpy(
        &pango_attr_overline_color_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_overline_color_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_overline_color_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_overline_color_object_handlers.clone_obj = pango_attr_overline_color_clone_obj;
    pango_attr_overline_color_object_handlers.read_property = pango_attr_overline_color_object_read_property;
    pango_attr_overline_color_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_overline_color_object_handlers.get_properties_for = pango_attr_overline_color_object_get_properties_for;
    pango_attr_overline_color_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_overline_color = register_class_Pango_Attribute_OverlineColor(php_pango_get_attribute_ce());
    ce_pango_attr_overline_color->create_object = pango_attr_overline_color_create_object;

    return SUCCESS;
}
/* }}} */
