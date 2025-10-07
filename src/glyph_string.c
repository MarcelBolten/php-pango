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
#include "glyph_string_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_glyph_string;

static zend_object_handlers pango_glyph_string_object_handlers;

pango_glyph_string_object *pango_glyph_string_fetch_object(zend_object *object)
{
    return (pango_glyph_string_object *) ((char*)(object) - XtOffsetOf(pango_glyph_string_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_string_ce()
{
    return pango_ce_pango_glyph_string;
}

/* ----------------------------------------------------------------
    \Pango\GlyphString Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_glyph_string_free_obj(zend_object *zobj)
{
    pango_glyph_string_object *intern = pango_glyph_string_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->glyph_string != NULL) {
        pango_glyph_string_free(intern->glyph_string);
        intern->glyph_string = NULL;
    }

    zval_ptr_dtor(&intern->glyph_item_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_string_obj_ctor(zend_class_entry *ce, pango_glyph_string_object **intern)
{
    pango_glyph_string_object *object = ecalloc(1, sizeof(pango_glyph_string_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_item_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_glyph_string_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_string_create_object(zend_class_entry *ce)
{
    pango_glyph_string_object *intern = NULL;
    zend_object *return_value = pango_glyph_string_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_glyph_string_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_glyph_string_object *glyph_string_object = pango_glyph_string_fetch_object(object);

    if (strcmp(ZSTR_VAL(member), "numGlyphs") == 0) {
        ZVAL_LONG(rv, glyph_string_object->glyph_string->num_glyphs);
        return rv;
    }
    else if (strcmp(ZSTR_VAL(member), "glyphs") == 0) {
        zval glyph_info_zv;
        pango_glyph_info_object *glyph_info_object;
        zval tmp_glyph_string_zval;
        ZVAL_OBJ(&tmp_glyph_string_zval, object);

        array_init(rv);
        for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
            object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
            glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
            glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
            ZVAL_COPY(&glyph_info_object->glyph_string_zv, &tmp_glyph_string_zval);
            add_next_index_zval(rv, &glyph_info_zv);
        }

        return rv;
    }

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_string_get_properties(zend_object *object)
{
    HashTable *props;
    pango_glyph_string_object *glyph_string_object = pango_glyph_string_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!glyph_string_object->glyph_string) {
        return props;
    }

    zval num_glyphs;
    ZVAL_LONG(&num_glyphs, glyph_string_object->glyph_string->num_glyphs);
    zend_hash_str_update(props, "numGlyphs", sizeof("numGlyphs")-1, &num_glyphs);

    // TODO: return the object properly
    // TODO: refactor this to a read-only view.
    // See Claude chat from 06/10/2025 22:57
    zval glyph_info_arr_zv;
    zval glyph_info_zv;
    array_init(&glyph_info_arr_zv);
    for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
        object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
        pango_glyph_info_object *glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
        glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
        // zval tmp_glyph_string_zval;
        // TODO: is the zval copy needed?
        // ZVAL_OBJ(&tmp_glyph_string_zval, object);
        // ZVAL_COPY(&glyph_info_zv->glyph_string_zv, &tmp_glyph_string_zval);
        add_next_index_zval(&glyph_info_arr_zv, &glyph_info_zv);
    }
    zend_hash_str_update(props, "glyphs", sizeof("glyphs")-1, &glyph_info_arr_zv);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_glyph_string)
{
    memcpy(
        &pango_glyph_string_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_string_object_handlers.offset = XtOffsetOf(pango_glyph_string_object, std);
    pango_glyph_string_object_handlers.free_obj = pango_glyph_string_free_obj;
    pango_glyph_string_object_handlers.read_property = pango_glyph_string_read_property;
    pango_glyph_string_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_string_object_handlers.get_properties = pango_glyph_string_get_properties;

    pango_ce_pango_glyph_string = register_class_Pango_GlyphString();
    pango_ce_pango_glyph_string->create_object = pango_glyph_string_create_object;

    return SUCCESS;
}
/* }}} */
