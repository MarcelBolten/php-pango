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
#include "glyph_geometry.h"
#include "glyph_geometry_arginfo.h"

zend_class_entry *pango_ce_pango_glyph_geometry;

static zend_object_handlers pango_glyph_geometry_object_handlers;

pango_glyph_geometry_object *pango_glyph_geometry_fetch_object(zend_object *object)
{
    return (pango_glyph_geometry_object *) ((char*)(object) - offsetof(pango_glyph_geometry_object, std));
}

PangoGlyphGeometry *pango_glyph_geometry_object_get_glyph_geometry(zval *zv)
{
    return Z_PANGO_GLYPH_GEOMETRY_P(zv)->glyph_geometry;
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        ZVAL_LONG(rv, glyph_geometry_object->glyph_geometry->c_name); \
        return rv; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, glyph_geometry_object->glyph_geometry->c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_geometry_ce(void)
{
    return pango_ce_pango_glyph_geometry;
}

/* ----------------------------------------------------------------
    \Pango\GlyphGeometry Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_glyph_geometry_free_obj(zend_object *zobj)
{
    pango_glyph_geometry_object *intern = pango_glyph_geometry_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->glyph_geometry != NULL) {
        intern->glyph_geometry = NULL;
    }

    zval_ptr_dtor(&intern->glyph_info_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_geometry_obj_ctor(zend_class_entry *ce, pango_glyph_geometry_object **intern)
{
    pango_glyph_geometry_object *object = ecalloc(1, sizeof(pango_glyph_geometry_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_info_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_glyph_geometry_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_geometry_create_object(zend_class_entry *ce)
{
    pango_glyph_geometry_object *intern = NULL;
    zend_object *return_value = pango_glyph_geometry_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_glyph_geometry_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_glyph_geometry_object *glyph_geometry_object = pango_glyph_geometry_fetch_object(zobj);

    PANGO_VALUE_FROM_STRUCT(width, width);
    PANGO_VALUE_FROM_STRUCT(xOffset, x_offset);
    PANGO_VALUE_FROM_STRUCT(yOffset, y_offset);

    return zend_std_read_property(zobj, member, type, cache_slot, rv);
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_geometry_get_properties_for(zend_object *zobj, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_glyph_geometry_object *glyph_geometry_object = pango_glyph_geometry_fetch_object(zobj);

    props = zend_array_dup(zend_std_get_properties(zobj));

    if (!glyph_geometry_object->glyph_geometry) {
        return props;
    }

    PANGO_ADD_STRUCT_VALUE(width, width);
    PANGO_ADD_STRUCT_VALUE(xOffset, x_offset);
    PANGO_ADD_STRUCT_VALUE(yOffset, y_offset);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_glyph_geometry)
{
    memcpy(
        &pango_glyph_geometry_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_geometry_object_handlers.offset = offsetof(pango_glyph_geometry_object, std);
    pango_glyph_geometry_object_handlers.free_obj = pango_glyph_geometry_free_obj;
    pango_glyph_geometry_object_handlers.read_property = pango_glyph_geometry_read_property;
    pango_glyph_geometry_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_geometry_object_handlers.get_properties_for = pango_glyph_geometry_get_properties_for;

    pango_ce_pango_glyph_geometry = register_class_Pango_GlyphGeometry();
    pango_ce_pango_glyph_geometry->create_object = pango_glyph_geometry_create_object;

    return SUCCESS;
}
/* }}} */
