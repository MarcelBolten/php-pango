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
#include "layout_line_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_layout_line;

static zend_object_handlers pango_layout_line_object_handlers;

pango_layout_line_object *pango_layout_line_fetch_object(zend_object *object)
{
    return (pango_layout_line_object *) ((char*)(object) - XtOffsetOf(pango_layout_line_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_layout_line_ce()
{
    return pango_ce_pango_layout_line;
}

/* {{{ Get the logical and ink extents for the line */
ZEND_METHOD(Pango_LayoutLine, getExtents)
{
    pango_layout_line_object *layout_line_object;
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    pango_layout_line_get_extents(layout_line_object->line, &pango_ink_rect, &pango_logical_rect);

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
    pango_layout_line_object *layout_line_object = NULL;
    int height = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    pango_layout_line_get_height(layout_line_object->line, &height);
    RETURN_LONG((zend_long) height);
}
/* }}} */

/* {{{ Returns the length of the line, in bytes. */
ZEND_METHOD(Pango_LayoutLine, getLength)
{
    pango_layout_line_object *layout_line_object = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    RETURN_LONG(pango_layout_line_get_length(layout_line_object->line));
}
/* }}} */


/* {{{ Get the logical and ink extents for the line, in device units */
ZEND_METHOD(Pango_LayoutLine, getPixelExtents)
{
    pango_layout_line_object *layout_line_object = NULL;
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    pango_layout_line_get_pixel_extents(layout_line_object->line, &pango_ink_rect, &pango_logical_rect);

    array_init(return_value);
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = pango_ink_rect;
    add_assoc_zval(return_value, "ink", &ink_rect_zv);

    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = pango_logical_rect;
    add_assoc_zval(return_value, "logical", &logical_rect_zv);
}
/* }}} */

/* {{{ Draws a PangoLayoutLine in the specified cairo context. If no context
       is specified, use the cached one from when the LayoutLine was created */
ZEND_METHOD(Pango_LayoutLine, showLayoutLine)
{
    zval *cairo_context_zval = NULL;
    pango_layout_line_object *layout_line_object = NULL;
    pango_layout_object *layout_object = NULL;
    cairo_context_object *cairo_context_object = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(cairo_context_zval, php_cairo_get_context_ce())
    ZEND_PARSE_PARAMETERS_END();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());

    if (cairo_context_zval == NULL) {
        layout_object = Z_PANGO_LAYOUT_P(&layout_line_object->layout_zval);
        cairo_context_zval = &layout_object->cairo_context_zv;
    }

    cairo_context_object = Z_CAIRO_CONTEXT_P(cairo_context_zval);

    pango_cairo_show_layout_line(cairo_context_object->context, layout_line_object->line);
}
/* }}} */

/** {{{ Returns the resolved direction of the line. */
PHP_METHOD(Pango_LayoutLine, getResolvedDirection)
{
    pango_layout_line_object *layout_line_object = NULL;
    zend_object *direction_case;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    zend_enum_get_case_by_value(
        &direction_case, php_pango_get_direction_ce(),
        pango_layout_line_get_resolved_direction(layout_line_object->line),
        NULL, false
    );

    RETURN_OBJ_COPY(direction_case);
}
/** }}} */

/** {{{ Returns the start index of the line, as byte index into the text of the layout. */
PHP_METHOD(Pango_LayoutLine, getStartIndex)
{
    pango_layout_line_object *layout_line_object = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    RETURN_LONG(pango_layout_line_get_start_index(layout_line_object->line));
}
/** }}} */

/** {{{ Returns whether this is the first line of the paragraph. */
PHP_METHOD(Pango_LayoutLine, isParagraphStart)
{
    pango_layout_line_object *layout_line_object = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line_object = Z_PANGO_LAYOUT_LINE_P(getThis());
    RETURN_BOOL(pango_layout_line_is_paragraph_start(layout_line_object->line));
}
/** }}} */

/** {{{ Returns the runs (glyph items) in the line, from left to right. */
PHP_METHOD(Pango_LayoutLine, getRuns)
{
    zval *layout_line;
    pango_layout_line_object *layout_line_object = NULL;
    GSList *runs;
    GSList *iter;
    zval run_zv;
    pango_glyph_item_object *glyph_item_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_line = getThis();
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(layout_line);
    runs = layout_line_object->line->runs;

    array_init(return_value);
    for (iter = runs; iter != NULL; iter = iter->next) {
        object_init_ex(&run_zv, php_pango_get_glyph_item_ce());
        glyph_item_object = Z_PANGO_GLYPH_ITEM_P(&run_zv);
        glyph_item_object->glyph_item = pango_glyph_item_copy((PangoGlyphItem *)iter->data);
        ZVAL_COPY(&glyph_item_object->layout_line_zv, layout_line);

        add_next_index_zval(return_value, &run_zv);
    }
}
/** }}} */

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

    object_properties_init(&intern->std, ce);
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

    pango_layout_line_object_handlers.offset = XtOffsetOf(pango_layout_line_object, std);
    pango_layout_line_object_handlers.free_obj = pango_layout_line_free_obj;

    pango_ce_pango_layout_line = register_class_Pango_LayoutLine();
    pango_ce_pango_layout_line->create_object = pango_layout_line_create_object;

    return SUCCESS;
}
/* }}} */
