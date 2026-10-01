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
#include "font.h"
#include "rectangle.h"
#include "layout.h"
#include "layout_line.h"
#include "glyph_item.h"
#include "glyph_info.h"
#include "glyph_string.h"
#include "glyph_string_arginfo.h"

zend_class_entry *pango_ce_pango_glyph_string;

static zend_object_handlers pango_glyph_string_object_handlers;

pango_glyph_string_object *pango_glyph_string_fetch_object(zend_object *object)
{
    return (pango_glyph_string_object *) ((char*)(object) - offsetof(pango_glyph_string_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_string_ce()
{
    return pango_ce_pango_glyph_string;
}

/* ----------------------------------------------------------------
    \Pango\GlyphString Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(Pango_GlyphString, getExtents)
{
    zval *font_zv;
    PangoRectangle ink_rect, logical_rect;
    zval rectangle_zv;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_zv, php_pango_get_font_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_glyph_string_extents(
        Z_PANGO_GLYPH_STRING_P(ZEND_THIS)->glyph_string,
        pango_font_object_get_font(font_zv),
        &ink_rect,
        &logical_rect
    );

    array_init(return_value);

    object_init_ex(&rectangle_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&rectangle_zv) = ink_rect;
    add_assoc_zval(return_value, "ink", &rectangle_zv);

    object_init_ex(&rectangle_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&rectangle_zv) = logical_rect;
    add_assoc_zval(return_value, "logical",&rectangle_zv);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphString, getExtentsRange)
{
    zend_long start, end;
    zval *font_zv;
    PangoGlyphString* glyph_string;
    int num_glyphs;
    PangoRectangle ink_rect, logical_rect;
    zval rectangle_zv;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(start)
        Z_PARAM_LONG(end)
        Z_PARAM_OBJECT_OF_CLASS(font_zv, php_pango_get_font_ce())
    ZEND_PARSE_PARAMETERS_END();

    glyph_string = Z_PANGO_GLYPH_STRING_P(ZEND_THIS)->glyph_string;

    num_glyphs = glyph_string->num_glyphs;
    if (start < 0 || start > num_glyphs) {
        zend_argument_value_error(1, "must be between 0 and %d but " ZEND_LONG_FMT " given",
            num_glyphs, start
        );
        RETURN_THROWS();
    }
    if (end < 0 || end > num_glyphs) {
        zend_argument_value_error(2, "must be between 0 and %d but " ZEND_LONG_FMT " given",
            num_glyphs, end
        );
        RETURN_THROWS();
    }
    if (start >= end) {
        const char *start_arg_name = get_active_function_arg_name(1);
        zend_argument_value_error(2, "must be greater than argument #1 ($%s) %d but %d given",
            start_arg_name, (int)start, (int)end
        );
        RETURN_THROWS();
    }

    pango_glyph_string_extents_range(
        glyph_string, start, end, pango_font_object_get_font(font_zv),
        &ink_rect, &logical_rect
    );

    array_init(return_value);

    object_init_ex(&rectangle_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&rectangle_zv) = ink_rect;
    add_assoc_zval(return_value, "ink", &rectangle_zv);

    object_init_ex(&rectangle_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&rectangle_zv) = logical_rect;
    add_assoc_zval(return_value, "logical",&rectangle_zv);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphString, getWidth)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_glyph_string_get_width(Z_PANGO_GLYPH_STRING_P(ZEND_THIS)->glyph_string));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphString, getLogicalWidths)
{
    zend_long embedding_level;
    int *logical_widths;
    int num_chars;

    ZEND_PARSE_PARAMETERS_NONE();
    // ZEND_PARSE_PARAMETERS_START(1, 1)
    //     Z_PARAM_LONG(embedding_level)
    // ZEND_PARSE_PARAMETERS_END();

    zval *glyph_item_zv = &Z_PANGO_GLYPH_STRING_P(ZEND_THIS)->glyph_item_zv;
    zval *layout_line_zv = &Z_PANGO_GLYPH_ITEM_P(glyph_item_zv)->layout_line_zv;
    zval *layout_zv = &Z_PANGO_LAYOUT_LINE_P(layout_line_zv)->layout_zval;
    PangoLayout *layout = Z_PANGO_LAYOUT_P(layout_zv)->layout;
    const char *text = pango_layout_get_text(layout);

    num_chars = Z_PANGO_GLYPH_ITEM_P(glyph_item_zv)->glyph_item->item->num_chars;
    logical_widths = g_new(int, num_chars);

    pango_glyph_string_get_logical_widths(
        Z_PANGO_GLYPH_STRING_P(ZEND_THIS)->glyph_string,
        text + Z_PANGO_GLYPH_ITEM_P(glyph_item_zv)->glyph_item->item->offset,
        Z_PANGO_GLYPH_ITEM_P(glyph_item_zv)->glyph_item->item->length,
        Z_PANGO_GLYPH_ITEM_P(glyph_item_zv)->glyph_item->item->analysis.level,
        // embedding_level,
        logical_widths
    );

    array_init_size(return_value, num_chars);
    for (int i = 0; i < num_chars; i++) {
        add_next_index_long(return_value, logical_widths[i]);
    }

    g_free(logical_widths);
}
/* }}} */

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

        array_init(rv);
        for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
            object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
            glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
            glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
            ZVAL_OBJ_COPY(&glyph_info_object->glyph_string_zv, object);
            add_next_index_zval(rv, &glyph_info_zv);
        }

        return rv;
    }

    return zend_std_read_property(object, member, type, cache_slot, rv);
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_string_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    pango_glyph_string_object *glyph_string_object = pango_glyph_string_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!glyph_string_object->glyph_string) {
        return props;
    }

    zval num_glyphs;
    ZVAL_LONG(&num_glyphs, glyph_string_object->glyph_string->num_glyphs);
    zend_hash_str_update(props, "numGlyphs", sizeof("numGlyphs")-1, &num_glyphs);

    zval glyph_info_arr_zv;
    zval glyph_info_zv;
    array_init(&glyph_info_arr_zv);
    for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
        object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
        pango_glyph_info_object *glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
        glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
        ZVAL_OBJ_COPY(&glyph_info_object->glyph_string_zv, object);
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

    pango_glyph_string_object_handlers.offset = offsetof(pango_glyph_string_object, std);
    pango_glyph_string_object_handlers.free_obj = pango_glyph_string_free_obj;
    pango_glyph_string_object_handlers.read_property = pango_glyph_string_read_property;
    pango_glyph_string_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_string_object_handlers.get_properties_for = pango_glyph_string_get_properties_for;

    pango_ce_pango_glyph_string = register_class_Pango_GlyphString();
    pango_ce_pango_glyph_string->create_object = pango_glyph_string_create_object;

    return SUCCESS;
}
/* }}} */
