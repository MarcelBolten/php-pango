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
#include "glyph_item_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_glyph_item;

static zend_object_handlers pango_glyph_item_object_handlers;

pango_glyph_item_object *pango_glyph_item_fetch_object(zend_object *object)
{
    return (pango_glyph_item_object *) ((char*)(object) - XtOffsetOf(pango_glyph_item_object, std));
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        value = glyph_item_object->glyph_item->c_name; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, glyph_item_object->glyph_item->c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);


PHP_PANGO_API zend_class_entry* php_pango_get_glyph_item_ce()
{
    return pango_ce_pango_glyph_item;
}

/* ----------------------------------------------------------------
    \Pango\GlyphItem Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_glyph_item_free_obj(zend_object *zobj)
{
    pango_glyph_item_object *intern = pango_glyph_item_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->glyph_item != NULL) {
        pango_glyph_item_free(intern->glyph_item);
        intern->glyph_item = NULL;
    }

    zval_ptr_dtor(&intern->layout_line_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_item_obj_ctor(zend_class_entry *ce, pango_glyph_item_object **intern)
{
    pango_glyph_item_object *object = ecalloc(1, sizeof(pango_glyph_item_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->layout_line_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_glyph_item_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_item_create_object(zend_class_entry *ce)
{
    pango_glyph_item_object *intern = NULL;
    zend_object *return_value = pango_glyph_item_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_glyph_item_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zend_long value = 0;
    pango_glyph_item_object *glyph_item_object = pango_glyph_item_fetch_object(object);

    // TODO: refactor this to a read-only view.
    // See Claude chat from 06/10/2025 22:57
    if (strcmp(ZSTR_VAL(member), "item") == 0) {
        object_init_ex(rv, php_pango_get_item_ce());
        pango_item_object *item_object = Z_PANGO_ITEM_P(rv);
        item_object->item = pango_item_copy(glyph_item_object->glyph_item->item);
        zval tmp_glyph_item_zval;
        ZVAL_OBJ(&tmp_glyph_item_zval, object);
        ZVAL_COPY(&item_object->glyph_item_zv, &tmp_glyph_item_zval);
        return rv;
    }

    if (strcmp(ZSTR_VAL(member), "glyphs") == 0) {
        object_init_ex(rv, php_pango_get_glyph_string_ce());
        pango_glyph_string_object *glyph_string_object = Z_PANGO_GLYPH_STRING_P(rv);
        glyph_string_object->glyph_string = pango_glyph_string_copy(glyph_item_object->glyph_item->glyphs);
        zval tmp_glyph_item_zval;
        ZVAL_OBJ(&tmp_glyph_item_zval, object);
        ZVAL_COPY(&glyph_string_object->glyph_item_zv, &tmp_glyph_item_zval);
        return rv;
    }


    PANGO_VALUE_FROM_STRUCT(yOffset, y_offset);
    PANGO_VALUE_FROM_STRUCT(startXOffset, start_x_offset);
    PANGO_VALUE_FROM_STRUCT(endXOffset, end_x_offset);

    ZVAL_LONG(rv, value);

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_item_get_properties(zend_object *object)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_glyph_item_object *glyph_item_object = pango_glyph_item_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!glyph_item_object->glyph_item) {
        return props;
    }

    // TODO: return the object properly
    // TODO: refactor this to a read-only view.
    // See Claude chat from 06/10/2025 22:57
    object_init_ex(&tmp, php_pango_get_item_ce());
    pango_item_object *item_object = Z_PANGO_ITEM_P(&tmp);
    item_object->item = pango_item_copy(glyph_item_object->glyph_item->item);
    // zval tmp_glyph_item_zval;
    // TODO: is the zval copy needed?
    // ZVAL_OBJ(&tmp_glyph_item_zval, object);
    // ZVAL_COPY(&item_object->glyph_item_zv, &tmp_glyph_item_zval);
    zend_hash_str_update(props, "item", sizeof("item")-1, &tmp);

    object_init_ex(&tmp, php_pango_get_glyph_string_ce());
    pango_glyph_string_object *glyph_string_object = Z_PANGO_GLYPH_STRING_P(&tmp);
    glyph_string_object->glyph_string = pango_glyph_string_copy(glyph_item_object->glyph_item->glyphs);
    // zval tmp_glyph_item_zval;
    // TODO: is the zval copy needed?
    // ZVAL_OBJ(&tmp_glyph_item_zval, object);
    // ZVAL_COPY(&item_object->glyph_item_zv, &tmp_glyph_item_zval);
    zend_hash_str_update(props, "glyphs", sizeof("glyphs")-1, &tmp);


    PANGO_ADD_STRUCT_VALUE(yOffset, y_offset);
    PANGO_ADD_STRUCT_VALUE(startXOffset, start_x_offset);
    PANGO_ADD_STRUCT_VALUE(endXOffset, end_x_offset);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_glyph_item)
{
    memcpy(
        &pango_glyph_item_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_item_object_handlers.offset = XtOffsetOf(pango_glyph_item_object, std);
    pango_glyph_item_object_handlers.free_obj = pango_glyph_item_free_obj;
    pango_glyph_item_object_handlers.read_property = pango_glyph_item_read_property;
    pango_glyph_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_item_object_handlers.get_properties = pango_glyph_item_get_properties;

    pango_ce_pango_glyph_item = register_class_Pango_GlyphItem();
    pango_ce_pango_glyph_item->create_object = pango_glyph_item_create_object;

    return SUCCESS;
}
/* }}} */
