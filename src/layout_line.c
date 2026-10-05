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
#include <php_cairo_internal.h>
#include <pango/pangocairo.h>

#include "../php_pango.h"
#include "context.h"
#include "glyph_item.h"
#include "layout.h"
#include "rectangle.h"
#include "layout_line.h"
#include "layout_line_arginfo.h"

zend_class_entry *pango_ce_pango_layout_line;

static zend_object_handlers pango_layout_line_object_handlers;

pango_layout_line_object *pango_layout_line_fetch_object(zend_object *object)
{
    return (pango_layout_line_object *) ((char*)(object) - offsetof(pango_layout_line_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_layout_line_ce(void)
{
    return pango_ce_pango_layout_line;
}

/* {{{ Get the logical and ink extents for the line */
ZEND_METHOD(Pango_LayoutLine, getExtents)
{
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_line_get_extents(
        Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line,
        &pango_ink_rect, &pango_logical_rect
    );

    array_init(return_value);
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = pango_ink_rect;
    add_assoc_zval(return_value, "ink", &ink_rect_zv);

    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = pango_logical_rect;
    add_assoc_zval(return_value, "logical", &logical_rect_zv);
}
/* }}} */

/* {{{ Computes the height of the line, as the maximum of the heights of fonts used in this line. */
ZEND_METHOD(Pango_LayoutLine, getHeight)
{
    int height = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_line_get_height(Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line, &height);
    RETURN_LONG((zend_long) height);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/* {{{ Returns the length of the line, in bytes. */
ZEND_METHOD(Pango_LayoutLine, getLength)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_line_get_length(Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line));
}
/* }}} */
#endif

/* {{{ Get the logical and ink extents for the line, in device units */
ZEND_METHOD(Pango_LayoutLine, getPixelExtents)
{
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_line_get_pixel_extents(
        Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line,
        &pango_ink_rect, &pango_logical_rect
    );

    array_init(return_value);
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = pango_ink_rect;
    add_assoc_zval(return_value, "ink", &ink_rect_zv);

    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = pango_logical_rect;
    add_assoc_zval(return_value, "logical", &logical_rect_zv);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/** {{{ Returns the resolved direction of the line. */
PHP_METHOD(Pango_LayoutLine, getResolvedDirection)
{
    zend_object *direction_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &direction_case, php_pango_get_direction_ce(),
        pango_layout_line_get_resolved_direction(Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line),
        NULL, false
    );

    RETURN_OBJ_COPY(direction_case);
}
/* }}} */

/** {{{ Returns the start index of the line, as byte index into the text of the layout. */
PHP_METHOD(Pango_LayoutLine, getStartIndex)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_line_get_start_index(Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line));
}
/* }}} */

/** {{{ Returns whether this is the first line of the paragraph. */
PHP_METHOD(Pango_LayoutLine, isParagraphStart)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_line_is_paragraph_start(Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line));
}
/* }}} */
#endif

/** {{{ Returns the runs (glyph items) in the line, from left to right. */
PHP_METHOD(Pango_LayoutLine, getRuns)
{
    zval *layout_line;
    pango_layout_line_object *layout_line_object = NULL;
    GSList *runs;
    zval run_zv;
    pango_glyph_item_object *glyph_item_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line = ZEND_THIS;
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(layout_line);
    runs = layout_line_object->line->runs;

    array_init(return_value);
    for (GSList *run = runs; run != NULL; run = run->next) {
        object_init_ex(&run_zv, php_pango_get_glyph_item_ce());
        glyph_item_object = Z_PANGO_GLYPH_ITEM_P(&run_zv);
        glyph_item_object->glyph_item = pango_glyph_item_copy((PangoGlyphItem *)run->data);
        ZVAL_COPY(&glyph_item_object->layout_line_zv, layout_line);
        add_next_index_zval(return_value, &run_zv);
    }
}
/* }}} */

/** {{{ Gets a list of visual ranges corresponding to a given logical range. */
PHP_METHOD(Pango_LayoutLine, getXRanges)
{
    zend_long start_byte_index = 0, end_byte_index = 0;
    bool start_byte_index_is_null, end_byte_index_is_null;
    const char *start_arg_name;
    PangoLayoutLine *line;
    int n_ranges = -1;
    int *ranges = NULL;
    zval tmp_zv;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG_OR_NULL(start_byte_index, start_byte_index_is_null)
        Z_PARAM_LONG_OR_NULL(end_byte_index, end_byte_index_is_null)
    ZEND_PARSE_PARAMETERS_END();

    if (!start_byte_index_is_null && (start_byte_index < 0 || start_byte_index > INT_MAX)) {
        zend_argument_value_error(1, "must be between 0 and %d but %ld given", INT_MAX, start_byte_index);
        RETURN_THROWS();
    }
    if (!end_byte_index_is_null && (end_byte_index < 0 || end_byte_index > INT_MAX)) {
        zend_argument_value_error(2, "must be between 0 and %d but %ld given", INT_MAX, end_byte_index);
        RETURN_THROWS();
    }
    if (!start_byte_index_is_null && !end_byte_index_is_null && start_byte_index > end_byte_index) {
        start_arg_name = get_active_function_arg_name(1);
        zend_argument_value_error(2, "must be be greater than argument #1 ($%s) %d but %d given",
            start_arg_name, start_byte_index, end_byte_index
        );
        RETURN_THROWS();
    }

    line = Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->line;

    if (start_byte_index_is_null) {
        start_byte_index = line->start_index;
    }
    if (end_byte_index_is_null) {
        end_byte_index = line->start_index + line->length;
    }

    zend_printf("line: %p, layout: %p, layout from zv: %p, start_byte_index: %ld, end_byte_index: %ld\n", line, line->layout, Z_PANGO_LAYOUT_P(&Z_PANGO_LAYOUT_LINE_P(ZEND_THIS)->layout_zval)->layout, start_byte_index, end_byte_index);

    pango_layout_line_get_x_ranges(
        line,
        (int) start_byte_index, (int) end_byte_index,
        &ranges, &n_ranges
    );

    zend_printf("line: %p, n_ranges: %d\n", line, n_ranges);
    if (n_ranges < 0) {
        zend_throw_error(NULL, "Failed to get x ranges for the line");
        RETURN_THROWS();
    }

    array_init_size(return_value, n_ranges);
    for (int n = 0; n < n_ranges; n++) {
        array_init(&tmp_zv);
        add_assoc_long(&tmp_zv, "start", ranges[2*n]);
        add_assoc_long(&tmp_zv, "end", ranges[2*n + 1]);
        add_assoc_long(&tmp_zv, "width", ranges[2*n + 1] - ranges[2*n]);
        add_next_index_zval(return_value, &tmp_zv);
    }
    g_free(ranges);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Layout Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_layout_line_free_obj(zend_object *zobj)
{
    pango_layout_line_object *intern = pango_layout_line_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->line != NULL) {
        pango_layout_line_unref(intern->line);
        intern->line = NULL;
    }

    zval_ptr_dtor(&intern->layout_zval);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_line_obj_ctor(zend_class_entry *ce, pango_layout_line_object **intern)
{
    pango_layout_line_object *object = ecalloc(1, sizeof(pango_layout_line_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->layout_zval);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_layout_line_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_line_create_object(zend_class_entry *ce)
{
    pango_layout_line_object *intern = NULL;
    zend_object *return_value = pango_layout_line_obj_ctor(ce, &intern);

    object_properties_init(return_value, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_layout_line)
{
    memcpy(
        &pango_layout_line_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_layout_line_object_handlers.offset = offsetof(pango_layout_line_object, std);
    pango_layout_line_object_handlers.free_obj = pango_layout_line_free_obj;

    pango_ce_pango_layout_line = register_class_Pango_LayoutLine();
    pango_ce_pango_layout_line->create_object = pango_layout_line_create_object;

    return SUCCESS;
}
/* }}} */
