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
#include <Zend/zend_enum.h>

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "item.h"
#include "glyph_string.h"
#include "layout.h"
#include "layout_line.h"
#include "glyph_item.h"
#include "glyph_item_arginfo.h"

zend_class_entry *pango_ce_pango_glyph_item;
zend_class_entry *pango_ce_pango_glyph_item_iter;
zend_class_entry *pango_ce_pango_glyph_item_iter_init_loc;

static zend_object_handlers pango_glyph_item_object_handlers;
static zend_object_handlers pango_glyph_item_iter_object_handlers;

pango_glyph_item_object *pango_glyph_item_fetch_object(zend_object *object)
{
    return (pango_glyph_item_object *) ((char*)(object) - offsetof(pango_glyph_item_object, std));
}

pango_glyph_item_iter_object *pango_glyph_item_iter_fetch_object(zend_object *object)
{
    return (pango_glyph_item_iter_object *) ((char*)(object) - offsetof(pango_glyph_item_iter_object, std));
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        ZVAL_LONG(rv, c_name); \
        return rv; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_item_ce(void)
{
    return pango_ce_pango_glyph_item;
}

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_item_iter_ce(void)
{
    return pango_ce_pango_glyph_item_iter;
}

PHP_PANGO_API zend_class_entry* php_pango_get_glyph_item_iter_init_loc_ce(void)
{
    return pango_ce_pango_glyph_item_iter_init_loc;
}

static const char *get_text_from_layout_line(zval *zv) {
    zval *layout_line_zv = &Z_PANGO_GLYPH_ITEM_P(zv)->layout_line_zv;
    zval *layout_zv = &Z_PANGO_LAYOUT_LINE_P(layout_line_zv)->layout_zval;
    PangoLayout *layout = Z_PANGO_LAYOUT_P(layout_zv)->layout;
    return pango_layout_get_text(layout);
}

/* ----------------------------------------------------------------
    \Pango\GlyphItem Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(Pango_GlyphItem, getLogicalWidths)
{
    PangoGlyphItem *glyph_item;
    int num_chars;
    int *logical_widths;

    ZEND_PARSE_PARAMETERS_NONE();

    glyph_item = Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item;
    num_chars = glyph_item->item->num_chars;

    logical_widths = g_new(int, num_chars);

    pango_glyph_item_get_logical_widths(
        glyph_item,
        get_text_from_layout_line(ZEND_THIS),
        logical_widths
    );

    array_init_size(return_value, num_chars);
    for (int i = 0; i < num_chars; i++) {
        add_next_index_long(return_value, logical_widths[i]);
    }

    g_free(logical_widths);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphItem, applyAttributes)
{
    zval *attr_list_zv;
    GSList* glyph_items;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, php_pango_get_attr_list_ce())
    ZEND_PARSE_PARAMETERS_END();

    glyph_items = pango_glyph_item_apply_attrs(
        // copy the original glyph item before applying attributes
        // as pango_glyph_item_apply_attrs takes ownership of the passed glyph item
        pango_glyph_item_copy(Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item),
        get_text_from_layout_line(ZEND_THIS),
        pango_attr_list_object_get_attr_list(attr_list_zv)
    );

    array_init_size(return_value, g_slist_length(glyph_items));
    for (GSList *list = glyph_items; list != NULL; list = list->next) {
        zval glyph_item_zv;
        object_init_ex(&glyph_item_zv, php_pango_get_glyph_item_ce());
        Z_PANGO_GLYPH_ITEM_P(&glyph_item_zv)->glyph_item = (PangoGlyphItem *) list->data;
        ZVAL_COPY(&Z_PANGO_GLYPH_ITEM_P(&glyph_item_zv)->layout_line_zv, &Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv);
        add_next_index_zval(return_value, &glyph_item_zv);
    }
    g_slist_free(glyph_items);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphItem, letterSpace)
{
    PangoGlyphItem *orig = Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item;
    zval *layout_line_zv = &Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv;
    zval *layout_zv = &Z_PANGO_LAYOUT_LINE_P(layout_line_zv)->layout_zval;
    PangoLayout *layout = Z_PANGO_LAYOUT_P(layout_zv)->layout;
    zend_long spacing;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();

    pango_glyph_item_letter_space(
        orig,
        pango_layout_get_text(layout),
        (PangoLogAttr *) pango_layout_get_log_attrs_readonly(layout, NULL),
        (int) spacing
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphItem, split)
{
    PangoGlyphItem *orig = Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item;
    zend_long split_byte_index;
    PangoGlyphItem *new_glyph_item;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(split_byte_index)
    ZEND_PARSE_PARAMETERS_END();

    if (split_byte_index <= 0 || split_byte_index >= orig->item->length) {
        zend_argument_value_error(1,
            "must be greater than 0 and less than the items byte length (%d) but " ZEND_LONG_FMT " given",
            orig->item->length,
            split_byte_index
        );
        RETURN_THROWS();
    }

    new_glyph_item = pango_glyph_item_split(
        orig,
        get_text_from_layout_line(ZEND_THIS),
        (int) split_byte_index
    );

    if (!new_glyph_item) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_glyph_item_ce());
    Z_PANGO_GLYPH_ITEM_P(return_value)->glyph_item = new_glyph_item;
    ZVAL_COPY(&Z_PANGO_GLYPH_ITEM_P(return_value)->layout_line_zv, &Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphItem, getGlyphItemIterator)
{
    zend_object *init_location = zend_enum_get_case_cstr(php_pango_get_glyph_item_iter_init_loc_ce(), "Beginning");
    const char *text;
    zend_object *init_loc_end = zend_enum_get_case_cstr(php_pango_get_glyph_item_iter_init_loc_ce(), "End");
    gboolean (*init_iterator)(PangoGlyphItemIter *, PangoGlyphItem *, const char *);
    gboolean initialized;
    PangoGlyphItemIter *glyph_item_iter = g_slice_new(PangoGlyphItemIter);
    pango_glyph_item_iter_object *iter_object;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJ_OF_CLASS(init_location, php_pango_get_glyph_item_iter_init_loc_ce())
    ZEND_PARSE_PARAMETERS_END();

    text = get_text_from_layout_line(ZEND_THIS);

    init_iterator = init_location == init_loc_end
        ? pango_glyph_item_iter_init_end
        : pango_glyph_item_iter_init_start;

    initialized = init_iterator(
        glyph_item_iter,
        Z_PANGO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item,
        text
    );

    if (!initialized) {
        pango_glyph_item_iter_free(glyph_item_iter);
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_glyph_item_iter_ce());
    iter_object = Z_PANGO_GLYPH_ITEM_ITER_P(return_value);
    ZVAL_COPY(&iter_object->glyph_item_zv, ZEND_THIS);
    iter_object->glyph_item_iter = glyph_item_iter;
    iter_object->text = zend_string_init(text, strlen(text), 0);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\GlyphItemIterator Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(Pango_GlyphItemIterator, next)
{
    ZEND_PARSE_PARAMETERS_NONE();

    if (pango_glyph_item_iter_next_cluster(Z_PANGO_GLYPH_ITEM_ITER_P(ZEND_THIS)->glyph_item_iter)) {
        RETURN_TRUE;
    }

    RETURN_FALSE;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_GlyphItemIterator, prev)
{
    ZEND_PARSE_PARAMETERS_NONE();

    if (pango_glyph_item_iter_prev_cluster(Z_PANGO_GLYPH_ITEM_ITER_P(ZEND_THIS)->glyph_item_iter)) {
        RETURN_TRUE;
    }

    RETURN_FALSE;
}
/* }}} */

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
    pango_glyph_item_object *glyph_item_object = pango_glyph_item_fetch_object(object);

    if (strcmp(ZSTR_VAL(member), "item") == 0) {
        object_init_ex(rv, php_pango_get_item_ce());
        pango_item_object *item_object = Z_PANGO_ITEM_P(rv);
        item_object->item = pango_item_copy(glyph_item_object->glyph_item->item);
        ZVAL_OBJ_COPY(&item_object->glyph_item_zv, object);
        return rv;
    }
    else if (strcmp(ZSTR_VAL(member), "glyphs") == 0) {
        object_init_ex(rv, php_pango_get_glyph_string_ce());
        pango_glyph_string_object *glyph_string_object = Z_PANGO_GLYPH_STRING_P(rv);
        glyph_string_object->glyph_string = pango_glyph_string_copy(glyph_item_object->glyph_item->glyphs);
        ZVAL_OBJ_COPY(&glyph_string_object->glyph_item_zv, object);
        return rv;
    }

    PANGO_VALUE_FROM_STRUCT(yOffset, glyph_item_object->glyph_item->y_offset);
    PANGO_VALUE_FROM_STRUCT(startXOffset, glyph_item_object->glyph_item->start_x_offset);
    PANGO_VALUE_FROM_STRUCT(endXOffset, glyph_item_object->glyph_item->end_x_offset);

    return zend_std_read_property(object, member, type, cache_slot, rv);
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_item_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_glyph_item_object *glyph_item_object = pango_glyph_item_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!glyph_item_object->glyph_item) {
        return props;
    }

    object_init_ex(&tmp, php_pango_get_item_ce());
    pango_item_object *item_object = Z_PANGO_ITEM_P(&tmp);
    item_object->item = pango_item_copy(glyph_item_object->glyph_item->item);
    ZVAL_OBJ_COPY(&item_object->glyph_item_zv, object);
    zend_hash_str_update(props, "item", sizeof("item")-1, &tmp);

    object_init_ex(&tmp, php_pango_get_glyph_string_ce());
    pango_glyph_string_object *glyph_string_object = Z_PANGO_GLYPH_STRING_P(&tmp);
    glyph_string_object->glyph_string = pango_glyph_string_copy(glyph_item_object->glyph_item->glyphs);
    ZVAL_OBJ_COPY(&glyph_string_object->glyph_item_zv, object);
    zend_hash_str_update(props, "glyphs", sizeof("glyphs")-1, &tmp);

    PANGO_ADD_STRUCT_VALUE(yOffset, glyph_item_object->glyph_item->y_offset);
    PANGO_ADD_STRUCT_VALUE(startXOffset, glyph_item_object->glyph_item->start_x_offset);
    PANGO_ADD_STRUCT_VALUE(endXOffset, glyph_item_object->glyph_item->end_x_offset);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\GlyphItemIterator Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_glyph_item_iter_free_obj(zend_object *zobj)
{
    pango_glyph_item_iter_object *intern = pango_glyph_item_iter_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->glyph_item_iter != NULL) {
        pango_glyph_item_iter_free(intern->glyph_item_iter);
        intern->glyph_item_iter = NULL;
    }

    zval_ptr_dtor(&intern->glyph_item_zv);

    if (intern->text) {
        zend_string_release(intern->text);
        intern->text = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_item_iter_obj_ctor(zend_class_entry *ce, pango_glyph_item_iter_object **intern)
{
    pango_glyph_item_iter_object *object = ecalloc(1, sizeof(pango_glyph_item_iter_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_item_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_glyph_item_iter_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_glyph_item_iter_create_object(zend_class_entry *ce)
{
    pango_glyph_item_iter_object *intern = NULL;
    zend_object *return_value = pango_glyph_item_iter_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_glyph_item_iter_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_glyph_item_iter_object *glyph_item_iter_object = pango_glyph_item_iter_fetch_object(object);

    if (strcmp(ZSTR_VAL(member), "glyphItem") == 0) {
        object_init_ex(rv, php_pango_get_glyph_item_ce());
        pango_glyph_item_object *glyph_item_object = Z_PANGO_GLYPH_ITEM_P(rv);
        glyph_item_object->glyph_item = pango_glyph_item_copy(glyph_item_object->glyph_item);
        ZVAL_COPY(
            &glyph_item_object->layout_line_zv,
            &Z_PANGO_GLYPH_ITEM_P(&glyph_item_iter_object->glyph_item_zv)->layout_line_zv
        );
        return rv;
    }
    else if (strcmp(ZSTR_VAL(member), "text") == 0) {
        ZVAL_STR(rv, zend_string_copy(glyph_item_iter_object->text));
        return rv;
    }

    PANGO_VALUE_FROM_STRUCT(startGlyph, glyph_item_iter_object->glyph_item_iter->start_glyph);
    PANGO_VALUE_FROM_STRUCT(startByteIndex, glyph_item_iter_object->glyph_item_iter->start_index);
    PANGO_VALUE_FROM_STRUCT(startChar, glyph_item_iter_object->glyph_item_iter->start_char);
    PANGO_VALUE_FROM_STRUCT(endGlyph, glyph_item_iter_object->glyph_item_iter->end_glyph);
    PANGO_VALUE_FROM_STRUCT(endByteIndex, glyph_item_iter_object->glyph_item_iter->end_index);
    PANGO_VALUE_FROM_STRUCT(endChar, glyph_item_iter_object->glyph_item_iter->end_char);

    return zend_std_read_property(object, member, type, cache_slot, rv);
}
/* }}} */

/* {{{ */
static HashTable *pango_glyph_item_iter_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_glyph_item_iter_object *glyph_item_iter_object = pango_glyph_item_iter_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!glyph_item_iter_object->glyph_item_iter) {
        return props;
    }

    object_init_ex(&tmp, php_pango_get_glyph_item_ce());
    pango_glyph_item_object *glyph_item_object = Z_PANGO_GLYPH_ITEM_P(&tmp);
    glyph_item_object->glyph_item = pango_glyph_item_copy(glyph_item_object->glyph_item);
    ZVAL_COPY(
        &glyph_item_object->layout_line_zv,
        &Z_PANGO_GLYPH_ITEM_P(&glyph_item_iter_object->glyph_item_zv)->layout_line_zv
    );
    zend_hash_str_update(props, "glyphItem", sizeof("glyphItem")-1, &tmp);

    ZVAL_STR(&tmp, zend_string_copy(glyph_item_iter_object->text));
    zend_hash_str_update(props, "text", sizeof("text")-1, &tmp);

    PANGO_ADD_STRUCT_VALUE(startGlyph, glyph_item_iter_object->glyph_item_iter->start_glyph);
    PANGO_ADD_STRUCT_VALUE(startByteIndex, glyph_item_iter_object->glyph_item_iter->start_index);
    PANGO_ADD_STRUCT_VALUE(startChar, glyph_item_iter_object->glyph_item_iter->start_char);
    PANGO_ADD_STRUCT_VALUE(endGlyph, glyph_item_iter_object->glyph_item_iter->end_glyph);
    PANGO_ADD_STRUCT_VALUE(endByteIndex, glyph_item_iter_object->glyph_item_iter->end_index);
    PANGO_ADD_STRUCT_VALUE(endChar, glyph_item_iter_object->glyph_item_iter->end_char);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_glyph_item)
{
    // GlyphItem
    memcpy(
        &pango_glyph_item_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_item_object_handlers.offset = offsetof(pango_glyph_item_object, std);
    pango_glyph_item_object_handlers.free_obj = pango_glyph_item_free_obj;
    pango_glyph_item_object_handlers.read_property = pango_glyph_item_read_property;
    pango_glyph_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_item_object_handlers.get_properties_for = pango_glyph_item_get_properties_for;

    pango_ce_pango_glyph_item = register_class_Pango_GlyphItem();
    pango_ce_pango_glyph_item->create_object = pango_glyph_item_create_object;

    // GlyphItemIterator
    memcpy(
        &pango_glyph_item_iter_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_glyph_item_iter_object_handlers.offset = offsetof(pango_glyph_item_iter_object, std);
    pango_glyph_item_iter_object_handlers.free_obj = pango_glyph_item_iter_free_obj;
    pango_glyph_item_iter_object_handlers.read_property = pango_glyph_item_iter_read_property;
    pango_glyph_item_iter_object_handlers.get_property_ptr_ptr = NULL;
    pango_glyph_item_iter_object_handlers.get_properties_for = pango_glyph_item_iter_get_properties_for;

    pango_ce_pango_glyph_item_iter = register_class_Pango_GlyphItemIterator();
    pango_ce_pango_glyph_item_iter->create_object = pango_glyph_item_iter_create_object;

    // GlyphItemIterInitLoc
    pango_ce_pango_glyph_item_iter_init_loc = register_class_Pango_GlyphItemIterInitLoc();

    return SUCCESS;
}
/* }}} */
