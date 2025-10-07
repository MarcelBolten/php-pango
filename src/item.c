/*
  +----------------------------------------------------------------------+
  | PHP Version 8                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2008 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Michael Maclean <mgdm@php.net>                              |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_pango.h"
#include "item_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_item;

static zend_object_handlers pango_item_object_handlers;

pango_item_object *pango_item_fetch_object(zend_object *object)
{
    return (pango_item_object *) ((char*)(object) - XtOffsetOf(pango_item_object, std));
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        value = item_object->item->c_name; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, item_object->item->c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);


PHP_PANGO_API zend_class_entry* php_pango_get_item_ce()
{
    return pango_ce_pango_item;
}

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

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_item_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zend_long value = 0;
    pango_item_object *item_object = pango_item_fetch_object(zobj);

    PANGO_VALUE_FROM_STRUCT(offset, offset);
    PANGO_VALUE_FROM_STRUCT(length, length);
    PANGO_VALUE_FROM_STRUCT(numChars, num_chars);

    ZVAL_LONG(rv, value);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_item_get_properties(zend_object *object)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_item_object *item_object = pango_item_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!item_object->item) {
        return props;
    }

    PANGO_ADD_STRUCT_VALUE(offset, offset);
    PANGO_ADD_STRUCT_VALUE(length, length);
    PANGO_ADD_STRUCT_VALUE(numChars, num_chars);

    return props;
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

    pango_item_object_handlers.offset = XtOffsetOf(pango_item_object, std);
    pango_item_object_handlers.free_obj = pango_item_free_obj;
    pango_item_object_handlers.read_property = pango_item_read_property;
    pango_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_item_object_handlers.get_properties = pango_item_get_properties;

    pango_ce_pango_item = register_class_Pango_Item();
    pango_ce_pango_item->create_object = pango_item_create_object;

    return SUCCESS;
}
/* }}} */
