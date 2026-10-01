/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Marcel Bolten <github@marcelbolten.de>                       |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "analysis.h"
#include "item.h"
#include "item_arginfo.h"

zend_class_entry *pango_ce_pango_item;

static zend_object_handlers pango_item_object_handlers;

pango_item_object *pango_item_fetch_object(zend_object *object)
{
    return (pango_item_object *) ((char*)(object) - offsetof(pango_item_object, std));
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        zend_long value = 0; \
        value = item_object->item->c_name; \
        ZVAL_LONG(rv, value); \
        return rv; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, item_object->item->c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);

PHP_PANGO_API zend_class_entry* php_pango_get_item_ce()
{
    return pango_ce_pango_item;
}

/* ----------------------------------------------------------------
    \Pango\Item Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(Pango_Item, applyAttributes)
{
    zval *attr_iter_zv;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_iter_zv, php_pango_get_attr_iter_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_item_apply_attrs(
        Z_PANGO_ITEM_P(ZEND_THIS)->item,
        pango_attr_iter_object_get_attr_iter(attr_iter_zv)
    );
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 54, 0)
/* {{{ */
PHP_METHOD(Pango_Item, getCharOffset)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_item_get_char_offset(Z_PANGO_ITEM_P(ZEND_THIS)->item));
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_Item, split)
{
    PangoItem *orig = Z_PANGO_ITEM_P(ZEND_THIS)->item;
    zend_long byte_index;
    zend_long char_offset;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(byte_index)
        Z_PARAM_LONG(char_offset)
    ZEND_PARSE_PARAMETERS_END();

    if (byte_index <= 0 || byte_index >= orig->length) {
        zend_argument_value_error(1,
            "must be greater than 0 and less than the items byte length (%d) but " ZEND_LONG_FMT " given",
            orig->length,
            byte_index
        );
        RETURN_THROWS();
    }
    if (char_offset <= 0 || char_offset >= orig->num_chars) {
        zend_argument_value_error(2,
            "must be greater than 0 and less than the items character count (%d) but " ZEND_LONG_FMT " given",
            orig->num_chars,
            char_offset
        );
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_item_ce());
    Z_PANGO_ITEM_P(return_value)->item = pango_item_split(orig, byte_index, char_offset);
    ZVAL_COPY(&Z_PANGO_ITEM_P(return_value)->glyph_item_zv, &Z_PANGO_ITEM_P(ZEND_THIS)->glyph_item_zv);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Item Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_item_free_obj(zend_object *zobj)
{
    pango_item_object *intern = pango_item_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->item != NULL) {
        pango_item_free(intern->item);
        intern->item = NULL;
    }

    zval_ptr_dtor(&intern->glyph_item_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_item_obj_ctor(zend_class_entry *ce, pango_item_object **intern)
{
    pango_item_object *object = ecalloc(1, sizeof(pango_item_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_item_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_item_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_item_create_object(zend_class_entry *ce)
{
    pango_item_object *intern = NULL;
    zend_object *return_value = pango_item_obj_ctor(ce, &intern);

    object_properties_init(return_value, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_item_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_item_object *item_object = pango_item_fetch_object(zobj);

    if (!item_object) {
        return rv;
    }

    if (strcmp(ZSTR_VAL(member), "analysis") == 0) {
        object_init_ex(rv, php_pango_get_analysis_ce());
        pango_analysis_object *analysis_object = Z_PANGO_ANALYSIS_P(rv);
        analysis_object->analysis = &item_object->item->analysis;
        ZVAL_OBJ_COPY(&analysis_object->item_zv, zobj);
        return rv;
    }

    PANGO_VALUE_FROM_STRUCT(offset, offset);
    PANGO_VALUE_FROM_STRUCT(length, length);
    PANGO_VALUE_FROM_STRUCT(numChars, num_chars);

    return zend_std_read_property(zobj, member, type, cache_slot, rv);
}
/* }}} */

static HashTable *pango_item_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_item_object *item_object = pango_item_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!item_object->item) {
        return props;
    }

    PANGO_ADD_STRUCT_VALUE(offset, offset);
    PANGO_ADD_STRUCT_VALUE(length, length);
    PANGO_ADD_STRUCT_VALUE(numChars, num_chars);

    object_init_ex(&tmp, php_pango_get_analysis_ce());
    pango_analysis_object *analysis_object = Z_PANGO_ANALYSIS_P(&tmp);
    analysis_object->analysis = &item_object->item->analysis;
    ZVAL_OBJ_COPY(&analysis_object->item_zv, object);
    zend_hash_str_update(props, "analysis", sizeof("analysis")-1, &tmp);

    return props;
}

/* {{{ */
static zend_object* pango_item_clone_obj(zend_object *zobj)
{
    pango_item_object *new_item;
    pango_item_object *old_item = pango_item_fetch_object(zobj);
    zend_object *return_value = pango_item_obj_ctor(zobj->ce, &new_item);

    new_item->item = pango_item_copy(old_item->item);

    ZVAL_COPY(&new_item->glyph_item_zv, &old_item->glyph_item_zv);

    zend_objects_clone_members(&new_item->std, &old_item->std);

    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_item)
{
    memcpy(
        &pango_item_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_item_object_handlers.offset = offsetof(pango_item_object, std);
    pango_item_object_handlers.free_obj = pango_item_free_obj;
    pango_item_object_handlers.clone_obj = pango_item_clone_obj;
    pango_item_object_handlers.read_property = pango_item_read_property;
    pango_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_item_object_handlers.get_properties_for = pango_item_get_properties_for;

    pango_ce_pango_item = register_class_Pango_Item();
    pango_ce_pango_item->create_object = pango_item_create_object;

    return SUCCESS;
}
/* }}} */
