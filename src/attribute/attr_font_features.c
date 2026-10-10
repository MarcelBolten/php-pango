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

zend_class_entry *ce_pango_attr_font_features;

static zend_object_handlers pango_attr_font_features_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\FontFeatures C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrFontFeatures *pango_attr_font_features_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(FontFeatures);
}
/* }}} */

zend_class_entry* php_pango_get_attr_font_features_ce(void)
{
    return ce_pango_attr_font_features;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\FontFeatures Class API
------------------------------------------------------------------*/

/* {{{ Creates a new font_features attribute */
PHP_METHOD(Pango_Attribute_FontFeatures, __construct)
{
    zend_string *font_features = NULL;
    zend_long start_index = PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING;
    zend_long end_index = PHP_PANGO_ATTR_INDEX_TO_TEXT_END;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_STR(font_features)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start_index)
        Z_PARAM_LONG(end_index)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(font_features)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    PANGO_ATTR_CHECK_INDICES(start_index, 2, end_index, 3);

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_font_features_new(ZSTR_VAL(font_features));
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->start_index = start_index;
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->end_index = end_index;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\FontFeatures Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(font_features);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(font_features);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(font_features);
/* }}} */

/* {{{ */
static zval *pango_attr_font_features_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    PANGO_ATTR_READ_PROPERTY(FontFeatures, STRING, features);
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_font_features_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    PANGO_ATTR_GET_PROPERTIES(FontFeatures, STRING, features);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\FontFeatures Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_font_features)
{
    memcpy(
        &pango_attr_font_features_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_font_features_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_font_features_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_font_features_object_handlers.clone_obj = pango_attr_font_features_clone_obj;
    pango_attr_font_features_object_handlers.read_property = pango_attr_font_features_object_read_property;
    pango_attr_font_features_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_font_features_object_handlers.get_properties_for = pango_attr_font_features_object_get_properties_for;
    pango_attr_font_features_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_font_features = register_class_Pango_Attribute_FontFeatures(php_pango_get_attribute_ce());
    ce_pango_attr_font_features->create_object = pango_attr_font_features_create_object;

    return SUCCESS;
}
/* }}} */
