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

#include "php.h"
#include "php_pango.h"
#include "glyph_info_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_glyph_info;

static zend_object_handlers pango_glyph_info_object_handlers;

pango_glyph_info_object *pango_glyph_info_fetch_object(zend_object *object)
{
    return (pango_glyph_info_object *) ((char*)(object) - XtOffsetOf(pango_glyph_info_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_info_ce()
{
    return pango_ce_pango_glyph_info;
}

/* ----------------------------------------------------------------
    \Pango\GlyphInfo Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_glyph_info_free_obj(zend_object *zobj)
{
    pango_glyph_info_object *intern = pango_glyph_info_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->glyph_info != NULL) {
        intern->glyph_info = NULL;
    }

    zval_ptr_dtor(&intern->glyph_string_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_info_obj_ctor(zend_class_entry *ce, pango_glyph_info_object **intern)
{
    pango_glyph_info_object *object = ecalloc(1, sizeof(pango_glyph_info_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_string_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_glyph_info_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_info_create_object(zend_class_entry *ce)
{
    pango_glyph_info_object *intern = NULL;
    zend_object *return_value = pango_glyph_info_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_glyph_info_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_glyph_info_object *glyph_info_object = pango_glyph_info_fetch_object(zobj);

    if (strcmp(ZSTR_VAL(member), "glyph") == 0) {
        ZVAL_LONG(rv, glyph_info_object->glyph_info->glyph);
        return rv;
    }
    else if (strcmp(ZSTR_VAL(member), "geometry") == 0) {
        array_init(rv);
        add_assoc_long(rv, "width", glyph_info_object->glyph_info->geometry.width);
        add_assoc_long(rv, "xOffset", glyph_info_object->glyph_info->geometry.x_offset);
        add_assoc_long(rv, "yOffset", glyph_info_object->glyph_info->geometry.y_offset);
        return rv;
    }
    else if (strcmp(ZSTR_VAL(member), "attributes") == 0) {
        array_init(rv);
        add_assoc_long(rv, "isClusterStart", glyph_info_object->glyph_info->attr.is_cluster_start);
        add_assoc_long(rv, "isColor", glyph_info_object->glyph_info->attr.is_color);
        return rv;
    }

    return zend_std_read_property(zobj, member, type, cache_slot, rv);
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_info_get_properties(zend_object *object)
{
    HashTable *props;
    pango_glyph_info_object *glyph_info_object = pango_glyph_info_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!glyph_info_object->glyph_info) {
        return props;
    }

    zval glyph;
    ZVAL_LONG(&glyph, glyph_info_object->glyph_info->glyph);
    zend_hash_str_update(props, "glyph", sizeof("glyph")-1, &glyph);

    zval geometry;
    array_init(&geometry);
    add_assoc_long(&geometry, "width", glyph_info_object->glyph_info->geometry.width);
    add_assoc_long(&geometry, "xOffset", glyph_info_object->glyph_info->geometry.x_offset);
    add_assoc_long(&geometry, "yOffset", glyph_info_object->glyph_info->geometry.y_offset);
    zend_hash_str_update(props, "geometry", sizeof("geometry")-1, &geometry);

    zval attributes;
    array_init(&attributes);
    add_assoc_long(&attributes, "isClusterStart", glyph_info_object->glyph_info->attr.is_cluster_start);
    add_assoc_long(&attributes, "isColor", glyph_info_object->glyph_info->attr.is_color);
    zend_hash_str_update(props, "attributes", sizeof("attributes")-1, &attributes);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_glyph_info)
{
    memcpy(
        &pango_glyph_info_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_info_object_handlers.offset = XtOffsetOf(pango_glyph_info_object, std);
    pango_glyph_info_object_handlers.free_obj = pango_glyph_info_free_obj;
    pango_glyph_info_object_handlers.read_property = pango_glyph_info_read_property;
    pango_glyph_info_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_info_object_handlers.get_properties = pango_glyph_info_get_properties;

    pango_ce_pango_glyph_info = register_class_Pango_GlyphInfo();
    pango_ce_pango_glyph_info->create_object = pango_glyph_info_create_object;

    return SUCCESS;
}
/* }}} */
