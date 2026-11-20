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
#include <pango/pangocairo.h>
#include <php_cairo_internal.h>

#include "../../php_pango.h"
#include "../attribute/attribute.h"
#include "../font.h"
#include "../rectangle.h"
#include "../glyph_info.h"
#include "../glyph_item.h"
#include "../glyph_string.h"
#include "pango_cairo.h"
#include "pango_cairo_glyph_item_arginfo.h"

zend_class_entry *pango_ce_pango_cairo_glyph_item;

static zend_object_handlers pango_cairo_glyph_item_object_handlers;

pango_glyph_item_object *pango_cairo_glyph_item_fetch_object(zend_object *object)
{
    return (pango_glyph_item_object *) ((char*)(object) - offsetof(pango_glyph_item_object, std));
}

PHP_PANGO_API zend_class_entry *php_pango_cairo_get_glyph_item_ce()
{
    return pango_ce_pango_cairo_glyph_item;
}

/* ----------------------------------------------------------------
    \PangoCairo\GlyphItem Class API
------------------------------------------------------------------*/

/* {{{ */
PHP_METHOD(PangoCairo_GlyphItem, show)
{
    cairo_t *cairo_context;

    ZEND_PARSE_PARAMETERS_NONE();

    cairo_context = Z_CAIRO_CONTEXT_P(
        &Z_PANGO_CAIRO_LAYOUT_P(
            &Z_PANGO_CAIRO_LAYOUT_LINE_P(
                &Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv
            )->layout_zval
        )->cairo_context_zv
    )->context;

    pango_cairo_show_glyph_item(
        cairo_context,
        get_text_from_layout_line(ZEND_THIS),
        Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_GlyphItem, applyAttributes)
{
    zval *attr_list_zv;
    GSList *glyph_items;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, php_pango_get_attr_list_ce())
    ZEND_PARSE_PARAMETERS_END();

    glyph_items = pango_glyph_item_apply_attrs(
        // copy the original glyph item before applying attributes
        // as pango_glyph_item_apply_attrs takes ownership of the passed glyph item
        pango_glyph_item_copy(Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item),
        get_text_from_layout_line(ZEND_THIS),
        pango_attr_list_object_get_attr_list(attr_list_zv)
    );

    array_init_size(return_value, g_slist_length(glyph_items));
    for (GSList *list = glyph_items; list != NULL; list = list->next) {
        zval glyph_item_zv;
        object_init_ex(&glyph_item_zv, php_pango_cairo_get_glyph_item_ce());
        Z_PANGO_CAIRO_GLYPH_ITEM_P(&glyph_item_zv)->glyph_item = (PangoGlyphItem *) list->data;
        ZVAL_COPY(
            &Z_PANGO_CAIRO_GLYPH_ITEM_P(&glyph_item_zv)->layout_line_zv,
            &Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv
        );
        add_next_index_zval(return_value, &glyph_item_zv);
    }
    g_slist_free(glyph_items);
}
/* }}} */

/* {{{ */
PHP_METHOD(PangoCairo_GlyphItem, split)
{
    PangoGlyphItem *orig = Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->glyph_item;
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

    object_init_ex(return_value, php_pango_cairo_get_glyph_item_ce());
    Z_PANGO_CAIRO_GLYPH_ITEM_P(return_value)->glyph_item = new_glyph_item;
    ZVAL_COPY(
        &Z_PANGO_CAIRO_GLYPH_ITEM_P(return_value)->layout_line_zv,
        &Z_PANGO_CAIRO_GLYPH_ITEM_P(ZEND_THIS)->layout_line_zv
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \PangoCairo\GlyphItem Object management
------------------------------------------------------------------*/

// /* {{{ */
// static void pango_cairo_glyph_item_free_obj(zend_object *zobj)
// {
//     pango_glyph_item_object *intern = pango_glyph_item_fetch_object(zobj);

//     if (!intern) {
//         return;
//     }

//     if (intern->glyph_string != NULL) {
//         pango_glyph_item_free(intern->glyph_string);
//         intern->glyph_string = NULL;
//     }

//     zval_ptr_dtor(&intern->glyph_item_zv);

//     zend_object_std_dtor(&intern->std);
// }
// /* }}} */

// /* {{{ */
// static zend_object *pango_glyph_item_obj_ctor(zend_class_entry *ce, pango_glyph_item_object **intern)
// {
//     pango_glyph_item_object *object = ecalloc(1, sizeof(pango_glyph_item_object) + zend_object_properties_size(ce));

//     ZVAL_UNDEF(&object->glyph_item_zv);

//     zend_object_std_init(&object->std, ce);

//     object->std.handlers = &pango_glyph_item_object_handlers;
//     *intern = object;

//     return &object->std;
// }
// /* }}} */

// /* {{{ */
// static zend_object *pango_glyph_item_create_object(zend_class_entry *ce)
// {
//     pango_glyph_item_object *intern = NULL;
//     zend_object *return_value = pango_glyph_item_obj_ctor(ce, &intern);

//     object_properties_init(&intern->std, ce);
//     return return_value;
// }
// /* }}} */

// /* {{{ */
// static zval *pango_glyph_item_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
// {
//     pango_glyph_item_object *glyph_string_object = pango_glyph_item_fetch_object(object);

//     if (strcmp(ZSTR_VAL(member), "numGlyphs") == 0) {
//         ZVAL_LONG(rv, glyph_string_object->glyph_string->num_glyphs);
//         return rv;
//     }
//     else if (strcmp(ZSTR_VAL(member), "glyphs") == 0) {
//         zval glyph_info_zv;
//         pango_glyph_info_object *glyph_info_object;

//         array_init(rv);
//         for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
//             object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
//             glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
//             glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
//             ZVAL_OBJ_COPY(&glyph_info_object->glyph_string_zv, object);
//             add_next_index_zval(rv, &glyph_info_zv);
//         }

//         return rv;
//     }

//     return zend_std_read_property(object, member, type, cache_slot, rv);
// }
// /* }}} */

// /* {{{ */
// static HashTable *pango_glyph_item_get_properties_for(zend_object *object, zend_prop_purpose purpose)
// {
//     HashTable *props;
//     pango_glyph_item_object *glyph_string_object = pango_glyph_item_fetch_object(object);

//     props = zend_array_dup(zend_std_get_properties(object));

//     if (!glyph_string_object->glyph_string) {
//         return props;
//     }

//     zval num_glyphs;
//     ZVAL_LONG(&num_glyphs, glyph_string_object->glyph_string->num_glyphs);
//     zend_hash_str_update(props, "numGlyphs", sizeof("numGlyphs")-1, &num_glyphs);

//     zval glyph_info_arr_zv;
//     zval glyph_info_zv;
//     array_init(&glyph_info_arr_zv);
//     for (int i = 0; i < glyph_string_object->glyph_string->num_glyphs; i++) {
//         object_init_ex(&glyph_info_zv, php_pango_get_glyph_info_ce());
//         pango_glyph_info_object *glyph_info_object = Z_PANGO_GLYPH_INFO_P(&glyph_info_zv);
//         glyph_info_object->glyph_info = &glyph_string_object->glyph_string->glyphs[i];
//         ZVAL_OBJ_COPY(&glyph_info_object->glyph_string_zv, object);
//         add_next_index_zval(&glyph_info_arr_zv, &glyph_info_zv);
//     }
//     zend_hash_str_update(props, "glyphs", sizeof("glyphs")-1, &glyph_info_arr_zv);

//     return props;
// }
// /* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_cairo_glyph_item)
{
    memcpy(
        &pango_cairo_glyph_item_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_cairo_glyph_item_object_handlers.offset = offsetof(pango_glyph_item_object, std);
    pango_cairo_glyph_item_object_handlers.free_obj = pango_glyph_item_free_obj;
    pango_cairo_glyph_item_object_handlers.read_property = pango_glyph_item_read_property;
    pango_cairo_glyph_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_cairo_glyph_item_object_handlers.get_properties_for = pango_glyph_item_get_properties_for;

    pango_ce_pango_cairo_glyph_item = register_class_PangoCairo_GlyphItem(php_pango_get_glyph_item_ce());
    pango_ce_pango_cairo_glyph_item->create_object = pango_glyph_item_create_object;

    return SUCCESS;
}
/* }}} */
