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

zend_class_entry *ce_pango_attr_word;

static zend_object_handlers pango_attr_word_object_handlers;

/* ----------------------------------------------------------------
    \Pango\Attribute\Word C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrInt *pango_attr_word_object_get_attr(zval *zv)
{
    PANGO_ATTR_OBJECT_GET_ATTR(Int);
}
/* }}} */

zend_class_entry* php_pango_get_attr_word_ce(void)
{
    return ce_pango_attr_word;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Word Class API
------------------------------------------------------------------*/

/* {{{ Creates a new word attribute */
PHP_METHOD(Pango_Attribute_Word, __construct)
{
    zend_long start_index = PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING;
    zend_long end_index = PHP_PANGO_ATTR_INDEX_TO_TEXT_END;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(start_index)
        Z_PARAM_LONG(end_index)
    ZEND_PARSE_PARAMETERS_END();

    PANGO_ATTR_CHECK_INDICES(start_index, 1, end_index, 2);

    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute = pango_attr_word_new();
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->start_index = start_index;
    Z_PANGO_ATTRIBUTE_P(ZEND_THIS)->attribute->end_index = end_index;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Word Object management
------------------------------------------------------------------*/

/* {{{ */
PANGO_ATTR_OBJ_CTOR(word);
/* }}} */

/* {{{ */
PANGO_ATTR_CREATE_OBJECT(word);
/* }}} */

/* {{{ */
PANGO_ATTR_CLONE_OBJECT(word);
/* }}} */

/* {{{ */
static zval *pango_attr_word_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

    if (!attr_object) {
        return rv;
    }

    PangoAttribute *attr = attr_object->attribute;

    PANGO_ATTR_RANGE_READ_PROPERTY(attr);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_word_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_attribute_object *attr_object = pango_attribute_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!attr_object->attribute) {
        return props;
    }

    PangoAttribute *attr = attr_object->attribute;

    PANGO_ATTR_ADD_RANGE_PROPERTIES(attr);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Word Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_word)
{
    memcpy(
        &pango_attr_word_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_word_object_handlers.offset = offsetof(pango_attribute_object, std);
    pango_attr_word_object_handlers.free_obj = pango_attr_free_obj;
    pango_attr_word_object_handlers.clone_obj = pango_attr_word_clone_obj;
    pango_attr_word_object_handlers.read_property = pango_attr_word_object_read_property;
    pango_attr_word_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_word_object_handlers.get_properties_for = pango_attr_word_object_get_properties_for;
    pango_attr_word_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_word = register_class_Pango_Attribute_Word(php_pango_get_attribute_ce());
    ce_pango_attr_word->create_object = pango_attr_word_create_object;

    return SUCCESS;
}
/* }}} */
