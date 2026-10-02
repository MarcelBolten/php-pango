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
  | Authors: Michael Maclean <mgdm@php.net>                              |
  |          David Marín <davefx@gmail.com>                              |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_enum.h>

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "context.h"
#include "exception.h"
#include "font_description.h"
#include "layout_iter.h"
#include "layout_line.h"
#include "logattr_list.h"
#include "rectangle.h"
#include "tabstops.h"
#include "layout.h"
#include "layout_arginfo.h"

zend_class_entry *pango_ce_pango_layout;
zend_class_entry *pango_ce_pango_alignment;
zend_class_entry *pango_ce_pango_wrap_mode;
zend_class_entry *pango_ce_pango_ellipsize_mode;

PHP_PANGO_API zend_class_entry* php_pango_get_layout_ce(void) {
    return pango_ce_pango_layout;
}

static zend_object_handlers pango_layout_object_handlers;

pango_layout_object *pango_layout_fetch_object(zend_object *object)
{
    return (pango_layout_object *) ((char*)(object) - offsetof(pango_layout_object, std));
}

/* {{{ Creates a PangoLayout based on the Pango Context object */
PHP_METHOD(Pango_Layout, __construct)
{
    zval *context_zval = NULL;
    pango_context_object *context_object;
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(context_zval, php_pango_get_context_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(context_zval);

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    layout_object->layout = pango_layout_new(context_object->context);

    if (layout_object->layout == NULL) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Could not create the Pango layout",
            0
        );
        RETURN_THROWS();
    }

    ZVAL_COPY(&layout_object->pango_context_zv, context_zval);
}
/* }}} */

/* {{{ Return the PangoContext for the current layout */
PHP_METHOD(Pango_Layout, getContext)
{
    pango_layout_object *layout_object;
    pango_context_object *context_object;
    PangoContext *context;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);

    if (Z_TYPE(layout_object->pango_context_zv) != IS_UNDEF) {
        ZVAL_COPY(return_value, &layout_object->pango_context_zv);
    } else {
        object_init_ex(return_value, php_pango_get_context_ce());
    }

    /* Get the context_object */
    context_object = Z_PANGO_CONTEXT_P(return_value);
    /* Destroy an existing pango context cause we’re getting a new one */
    if (context_object->context != NULL) {
        g_object_unref(context_object->context);
    }

    /* (Re-)Set the internal pango context pointer */
    context_object->context = pango_layout_get_context(layout_object->layout);
    g_object_ref(context_object->context);

    // Store the pango context zval in the layout object for later reuse
    // ZVAL_COPY(&layout_object->pango_context_zv, return_value);
}
/* }}} */

/* {{{ Sets the text of the layout. */
PHP_METHOD(Pango_Layout, setText)
{
    zend_string *text;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_layout_set_text(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, ZSTR_VAL(text), ZSTR_LEN(text));

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Gets the text currently in the layout */
PHP_METHOD(Pango_Layout, getText)
{
    const char *text;

    ZEND_PARSE_PARAMETERS_NONE();

    if (text = pango_layout_get_text(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout)) {
        RETURN_STRING((char *)text);
    }
    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ Sets the markup of the layout. */
PHP_METHOD(Pango_Layout, setMarkup)
{
    zend_string *markup;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(markup)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(markup)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_layout_set_markup(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, ZSTR_VAL(markup), ZSTR_LEN(markup));

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Updates the private PangoContext of a PangoLayout to match the current transformation
       and target surface of a Cairo context.
       PARAMS ARE REVERSED FROM NATIVE PANGO */
PHP_METHOD(Pango_Layout, contextChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_context_changed(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout);
}
/* }}} */

/* {{{ Sets the markup of the layout with accelerator markers. */
PHP_METHOD(Pango_Layout, setMarkupWithAccel)
{
    zend_string *markup;
    zend_string *accel_marker;
    gunichar first_accel_codepoint = 0;
    gunichar accel_marker_char = 0;
    char first_accel_char[6]; // Max UTF-8 char is 6 bytes
    int first_accel_char_len;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(markup)
        Z_PARAM_STR(accel_marker)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(markup)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    // Convert UTF-8 string to gunichar
    if (ZSTR_LEN(accel_marker) > 0) {
        accel_marker_char = g_utf8_get_char(ZSTR_VAL(accel_marker));
    }

    pango_layout_set_markup_with_accel(
        Z_PANGO_LAYOUT_P(ZEND_THIS)->layout,
        ZSTR_VAL(markup),
        ZSTR_LEN(markup),
        accel_marker_char,
        &first_accel_codepoint
    );

    zend_string_release_ex(Z_PANGO_LAYOUT_P(ZEND_THIS)->accel_char, 0);
    if (first_accel_codepoint == 0) {
        Z_PANGO_LAYOUT_P(ZEND_THIS)->accel_char = ZSTR_EMPTY_ALLOC();
    } else {
        first_accel_char_len = g_unichar_to_utf8(first_accel_codepoint, first_accel_char);
        Z_PANGO_LAYOUT_P(ZEND_THIS)->accel_char = zend_string_init(first_accel_char, first_accel_char_len, 0);
    }
    GC_ADDREF(Z_PANGO_LAYOUT_P(ZEND_THIS)->accel_char);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Layout, getAccelChar)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STR(Z_PANGO_LAYOUT_P(ZEND_THIS)->accel_char);
}
/* }}} */

/* {{{ Gets the width of the layout. */
PHP_METHOD(Pango_Layout, getWidth)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_width(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Gets the height of the layout. */
PHP_METHOD(Pango_Layout, getHeight)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG((zend_long) pango_layout_get_height(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Gets the size of the layout. */
PHP_METHOD(Pango_Layout, getSize)
{
    pango_layout_object *layout_object;
    int height = 0, width = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    if (!layout_object->layout) {
        RETURN_NULL();
    }
    pango_layout_get_size(layout_object->layout, &width, &height);

    // TODO: don’t return an array but an object with properties
    array_init(return_value);
    add_assoc_long(return_value, "width", (zend_long) width);
    add_assoc_long(return_value, "height", (zend_long) height);
}
/* }}} */

/* {{{ Gets the size of layout in pixels */
PHP_METHOD(Pango_Layout, getPixelSize)
{
    int height = 0, width = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_get_pixel_size(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, &width, &height);

    // TODO: don’t return an array but an object with properties
    array_init(return_value);
    add_assoc_long(return_value, "width", width);
    add_assoc_long(return_value, "height", height);
}
/* }}} */

/* {{{ Gets the extents of layout in */
PHP_METHOD(Pango_Layout, getExtents)
{
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_get_extents(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, &pango_ink_rect, &pango_logical_rect);

    array_init(return_value);
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = pango_ink_rect;
    add_assoc_zval(return_value, "ink", &ink_rect_zv);

    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = pango_logical_rect;
    add_assoc_zval(return_value, "logical", &logical_rect_zv);
}
/* }}} */

/* {{{ Gets the extents of layout in pixels */
PHP_METHOD(Pango_Layout, getPixelExtents)
{
    PangoRectangle pango_ink_rect;
    PangoRectangle pango_logical_rect;
    zval ink_rect_zv;
    zval logical_rect_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_get_pixel_extents(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, &pango_ink_rect, &pango_logical_rect);

    array_init(return_value);
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = pango_ink_rect;
    add_assoc_zval(return_value, "ink", &ink_rect_zv);

    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = pango_logical_rect;
    add_assoc_zval(return_value, "logical", &logical_rect_zv);
}
/* }}} */

/* {{{ Sets the width of the layout. */
PHP_METHOD(Pango_Layout, setWidth)
{
    zend_long width;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(width)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_width(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, width);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the height of the layout. */
PHP_METHOD(Pango_Layout, setHeight)
{
    zend_long height;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_height(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, height);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the font_description of the layout. */
PHP_METHOD(Pango_Layout, setFontDescription)
{
    zval *font_desc_zv = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_font_description(
        Z_PANGO_LAYOUT_P(ZEND_THIS)->layout,
        Z_PANGO_FONT_DESC_P(font_desc_zv)->font_description
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Gets the font_description of the layout. */
PHP_METHOD(Pango_Layout, getFontDescription)
{
    pango_font_description_object *font_description_object = NULL;
    const PangoFontDescription *font_description = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    // font_description can be NULL, in that case the font description is from the context and not set on the layout
    if (!(font_description = pango_layout_get_font_description(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout))) {
        // TODO: should the font description of the context be returned instead?
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_description_ce());
    font_description_object = Z_PANGO_FONT_DESC_P(return_value);
    font_description_object->font_description = pango_font_description_copy(font_description);
}
/* }}} */

/* {{{ Sets whether each line should be justified. */
PHP_METHOD(Pango_Layout, setJustify)
{
    bool justify;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(justify)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_justify(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, justify);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns whether text will be justified or not in the current layout */
PHP_METHOD(Pango_Layout, getJustify)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_get_justify(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets whether each line should be justified. */
PHP_METHOD(Pango_Layout, setAlignment)
{
    zend_object *alignment;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(alignment, pango_ce_pango_alignment)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_alignment(
        Z_PANGO_LAYOUT_P(ZEND_THIS)->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(alignment))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns whether text will be justified or not in the current layout */
PHP_METHOD(Pango_Layout, getAlignment)
{
    zend_object *alignment_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &alignment_case, pango_ce_pango_alignment,
        pango_layout_get_alignment(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(alignment_case);
}
/* }}} */

/* {{{ Sets how each line should be wrapped. */
PHP_METHOD(Pango_Layout, setWrap)
{
    zend_object *wrap;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(wrap, pango_ce_pango_wrap_mode)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_wrap(
        Z_PANGO_LAYOUT_P(ZEND_THIS)->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(wrap))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns how text will be wrapped or not in the current layout. */
PHP_METHOD(Pango_Layout, getWrap)
{
    zend_object *wrap_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &wrap_case, pango_ce_pango_wrap_mode,
        pango_layout_get_wrap(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(wrap_case);
}
/* }}} */

/* {{{ Queries whether the layout had to wrap any paragraphs. */
PHP_METHOD(Pango_Layout, isWrapped)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_is_wrapped(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets how far each paragraph should be indented. */
PHP_METHOD(Pango_Layout, setIndent)
{
    zend_long indent;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(indent)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_indent(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, indent);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns how text will be indented or not in the current layout */
PHP_METHOD(Pango_Layout, getIndent)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_indent(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets the line spacing for the paragraph */
PHP_METHOD(Pango_Layout, setSpacing)
{
    zend_long spacing;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_spacing(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, spacing);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns the spacing for the current layout */
PHP_METHOD(Pango_Layout, getSpacing)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_spacing(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets the ellipsize mode for the layout */
PHP_METHOD(Pango_Layout, setEllipsize)
{
    zend_object *ellipsize;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(ellipsize, pango_ce_pango_ellipsize_mode)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_ellipsize(
        Z_PANGO_LAYOUT_P(ZEND_THIS)->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(ellipsize))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Returns the ellipsize for the current layout */
PHP_METHOD(Pango_Layout, getEllipsize)
{
    zend_object *ellipsize_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &ellipsize_case, pango_ce_pango_ellipsize_mode,
        pango_layout_get_ellipsize(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(ellipsize_case);
}
/* }}} */

/* {{{ Queries whether the layout had to ellipsize any paragraphs */
PHP_METHOD(Pango_Layout, isEllipsized)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_is_ellipsized(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Returns an array of LayoutLines representing each line of the layout */
PHP_METHOD(Pango_Layout, getLines)
{
    zval *layout;
    pango_layout_object *layout_object;
    GSList *lines;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (GSList *line = lines; line != NULL; line = line->next) {
        object_init_ex(&line_zv, php_pango_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)line->data);
        ZVAL_COPY(&line_object->layout_zval, layout);

        add_next_index_zval(return_value, &line_zv);
    }
}
/* }}} */

/* {{{ Returns an array of LayoutLines representing each line of the layout */
PHP_METHOD(Pango_Layout, getLinesReadonly)
{
    zval *layout;
    pango_layout_object *layout_object;
    GSList *lines;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines_readonly(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (GSList *line = lines; line != NULL; line = line->next) {
        object_init_ex(&line_zv, php_pango_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)line->data);
        ZVAL_COPY(&line_object->layout_zval, layout);

        add_next_index_zval(return_value, &line_zv);
    }
}
/* }}} */

/* {{{ Returns a particular LayoutLine from the layout */
PHP_METHOD(Pango_Layout, getLine)
{
    zval *layout;
    pango_layout_object *layout_object;
    zend_long line_number = 0;
    int line_count;
    PangoLayoutLine *layout_line;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(line_number)
    ZEND_PARSE_PARAMETERS_END();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);

    line_count = pango_layout_get_line_count(layout_object->layout);
    if (line_number < 0 || line_number >= line_count) {
        zend_argument_value_error(1, "must be between 0 and %d but %ld given", line_count - 1, line_number);
        RETURN_THROWS();
    }

    layout_line = pango_layout_get_line(layout_object->layout, (int) line_number);
    if (UNEXPECTED(!layout_line)) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_layout_line_ce());
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(return_value);
    layout_line_object->line = pango_layout_line_ref(layout_line);
    ZVAL_COPY(&layout_line_object->layout_zval, layout);
}

/* {{{ Returns a particular LayoutLine from the layout */
PHP_METHOD(Pango_Layout, getLineReadonly)
{
    zval *layout;
    pango_layout_object *layout_object;
    zend_long line_number = 0;
    PangoLayoutLine *layout_line;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(line_number)
    ZEND_PARSE_PARAMETERS_END();

    layout = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout);

    if (!(layout_line = pango_layout_get_line_readonly(layout_object->layout, (int) line_number))) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_layout_line_ce());
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(return_value);
    layout_line_object->line = pango_layout_line_ref(layout_line);
    ZVAL_COPY(&layout_line_object->layout_zval, layout);
}

/* {{{ Returns the number of LayoutLines in the layout */
PHP_METHOD(Pango_Layout, getLineCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG((zend_long) pango_layout_get_line_count(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/* {{{ The intended use of this function is testing, benchmarking and debugging. The format is not meant as a permanent storage format. */
PHP_METHOD(Pango_Layout, serialize)
{
    zend_long flags = PANGO_LAYOUT_SERIALIZE_DEFAULT;
    pango_layout_object *layout_object;
    GBytes* serialized_layout;
    const char *text;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(flags)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(ZEND_THIS);
    if (!layout_object->layout) {
        RETURN_NULL();
    }
    if (serialized_layout = pango_layout_serialize(layout_object->layout, flags)) {
        text = g_bytes_get_data(serialized_layout, NULL);
        RETURN_STRING(text);
    }

    RETURN_EMPTY_STRING();
}
/* }}} */
#endif

/* {{{ Gets the Y position of baseline of the first line in layout.*/
PHP_METHOD(Pango_Layout, getBaseline)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_baseline(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Gets whether to calculate the base direction for the layout according to its contents. */
PHP_METHOD(Pango_Layout, getAutoDir)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_get_auto_dir(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets whether to calculate the base direction for the layout according to its contents. */
PHP_METHOD(Pango_Layout, setAutoDir)
{
    bool auto_dir;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(auto_dir)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_auto_dir(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, auto_dir);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Layout, getCharacterCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_character_count(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Gets the text direction at the given character position in layout. */
PHP_METHOD(Pango_Layout, getDirection)
{
    zend_long byte_index;
    zend_object *direction_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(byte_index)
    ZEND_PARSE_PARAMETERS_END();

    zend_enum_get_case_by_value(
        &direction_case, php_pango_get_direction_ce(),
        pango_layout_get_direction(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, byte_index),
        NULL, false
    );

    RETURN_OBJ_COPY(direction_case);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/* {{{ Gets whether the last line should be stretched to fill the entire width of the layout. */
PHP_METHOD(Pango_Layout, getJustifyLastLine)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_get_justify_last_line(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/* {{{ Sets whether the last line should be stretched to fill the entire width of the layout. */
PHP_METHOD(Pango_Layout, setJustifyLastLine)
{
    bool justify_last_line;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(justify_last_line)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_justify_last_line(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, justify_last_line);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_Layout, getLineSpacing)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_DOUBLE(pango_layout_get_line_spacing(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Layout, setLineSpacing)
{
    double factor;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(factor)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_line_spacing(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, factor);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */


/* {{{ */
PHP_METHOD(Pango_Layout, getUnknownGlyphsCount)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_unknown_glyphs_count(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Obtains whether layout is in single paragraph mode. */
PHP_METHOD(Pango_Layout, getSingleParagraphMode)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_get_single_paragraph_mode(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Sets the single paragraph mode. */
PHP_METHOD(Pango_Layout, setSingleParagraphMode)
{
    bool setting;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(setting)
    ZEND_PARSE_PARAMETERS_END();

    pango_layout_set_single_paragraph_mode(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, setting);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

// /* {{{ Retrieves an array of logical attributes for each character in the layout. */
// PHP_METHOD(Pango_Layout, getLogAttrs)
// {
//     zval *layout;
//     pango_layout_object *layout_object;
//     PangoLogAttr *attrs;
//     int n_attrs;

//     ZEND_PARSE_PARAMETERS_NONE();

//     layout = ZEND_THIS;
//     layout_object = Z_PANGO_LAYOUT_P(layout);
//     pango_layout_get_log_attrs(layout_object->layout, &attrs, &n_attrs);
//     if (n_attrs <= 0) {
//         g_free(attrs);
//         RETURN_EMPTY_ARRAY();
//     }

//     array_init(return_value);
//     for (int i = 0; i < n_attrs; i++) {
//         zval logattr_zv;
//         object_init_ex(&logattr_zv, php_pango_get_logattr_ce());
//         pango_logattr_object *logattr_object = Z_PANGO_LOGATTR_P(&logattr_zv);
//         *logattr_object->logattr = attrs[i];
//         add_next_index_zval(return_value, &logattr_zv);
//     }
//     g_free(attrs);
// }
// /* }}} */

/* {{{ Retrieves an array of logical attributes for each character in the layout. */
PHP_METHOD(Pango_Layout, getLogAttrs)
{
    zval *layout_zv;
    pango_layout_object *layout_object;
    const char *text;
    const PangoLogAttr *attrs;
    int n_attrs;
    pango_logattr_list_object *logattr_list_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_zv = ZEND_THIS;
    layout_object = Z_PANGO_LAYOUT_P(layout_zv);
    text = pango_layout_get_text(layout_object->layout);
    attrs = pango_layout_get_log_attrs_readonly(layout_object->layout, &n_attrs);

    object_init_ex(return_value, php_pango_get_logattr_list_ce());
    zend_update_property_string(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "text", sizeof("text") - 1,
        text
    );

    logattr_list_obj = Z_PANGO_LOGATTR_LIST_P(return_value);
    // allocate the logattr array with the length of the text
    // plus one extra at the end of the text
    logattr_list_obj->logattr_arr_len = n_attrs;
    if (n_attrs > 0) {
        logattr_list_obj->logattr_arr = ecalloc(n_attrs, sizeof(PangoLogAttr));

        memcpy(
            logattr_list_obj->logattr_arr,
            attrs,
            n_attrs * sizeof(PangoLogAttr)
        );
    }

    // if (n_attrs <= 0) {
    //     RETURN_EMPTY_ARRAY();
    // }

    // array_init(return_value);
    // for (int i = 0; i < n_attrs; i++) {
    //     zval logattr_zv;
    //     object_init_ex(&logattr_zv, php_pango_get_logattr_ce());
    //     pango_logattr_object *logattr_object = Z_PANGO_LOGATTR_P(&logattr_zv);
    //     *logattr_object->logattr = attrs[i];
    //     add_next_index_zval(return_value, &logattr_zv);
    // }
}
/* }}} */

/* {{{ Returns the current serial number of layout */
PHP_METHOD(Pango_Layout, getSerial)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_get_serial(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout));
}
/* }}} */

/* {{{ Gets the attribute list for the layout, if any. */
PHP_METHOD(Pango_Layout, getAttributes)
{
    PangoAttrList *attr_list;

    ZEND_PARSE_PARAMETERS_NONE();

    attr_list = pango_layout_get_attributes(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout);

    if (!attr_list) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_attr_list_ce());
    pango_attr_list_object *attr_list_object = Z_PANGO_ATTR_LIST_P(return_value);
    attr_list_object->attr_list = pango_attr_list_copy(attr_list);
}
/* }}} */

/* {{{ Sets the text attributes for a layout object. */
PHP_METHOD(Pango_Layout, setAttributes)
{
    zval *attributes = NULL;
    PangoAttrList *attr_list = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(attributes, php_pango_get_attr_list_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (attributes) {
        attr_list = pango_attr_list_object_get_attr_list(attributes);
    }

    pango_layout_set_attributes(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, attr_list);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Gets the current TabStops used by this layout. */
PHP_METHOD(Pango_Layout, getTabStops)
{
    PangoTabArray *tab_array;
    pango_tabstops_object *tabstops_object;

    ZEND_PARSE_PARAMETERS_NONE();

    tab_array = pango_layout_get_tabs(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout);

    if (!tab_array) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_tabstops_ce());
    tabstops_object = Z_PANGO_TABSTOPS_P(return_value);
    tabstops_object->tab_array = pango_tab_array_copy(tab_array);
}
/* }}} */

/* {{{ Sets the tabs to use for layout, overriding the default tabs. */
PHP_METHOD(Pango_Layout, setTabStops)
{
    zval *tabstops_zv = NULL;
    PangoTabArray *tab_array = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(tabstops_zv, php_pango_get_tabstops_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (tabstops_zv) {
        tab_array = pango_tabstops_object_get_tab_array(tabstops_zv);
    }

    pango_layout_set_tabs(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout, tab_array);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Layout, getIter)
{
    pango_layout_iter_object *layout_iter_object;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, php_pango_get_layout_iter_ce());
    layout_iter_object = Z_PANGO_LAYOUT_ITER_P(return_value);
    layout_iter_object->layout_iter = pango_layout_get_iter(Z_PANGO_LAYOUT_P(ZEND_THIS)->layout);
    ZVAL_COPY(&layout_iter_object->layout_zv, ZEND_THIS);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Layout Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_layout_free_obj(zend_object *zobj)
{
    pango_layout_object *intern = pango_layout_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->layout) {
        g_object_unref(intern->layout);
    }

    zend_string_release_ex(intern->accel_char, 0);
    zval_ptr_dtor(&intern->pango_context_zv);
    zval_ptr_dtor(&intern->cairo_context_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_obj_ctor(zend_class_entry *ce, pango_layout_object **intern)
{
    pango_layout_object *object = ecalloc(1, sizeof(pango_layout_object) + zend_object_properties_size(ce));

    object->accel_char = ZSTR_EMPTY_ALLOC();
    GC_ADDREF(object->accel_char);
    ZVAL_UNDEF(&object->cairo_context_zv);
    ZVAL_UNDEF(&object->pango_context_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_layout_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_create_object(zend_class_entry *ce)
{
    pango_layout_object *intern = NULL;
    zend_object *return_value = pango_layout_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_clone_obj(zend_object *zobj)
{
    pango_layout_object *new_layout;
    pango_layout_object *old_layout = pango_layout_fetch_object(zobj);
    zend_object *return_value = pango_layout_obj_ctor(zobj->ce, &new_layout);

    if (old_layout->layout) {
        new_layout->layout = pango_layout_copy(old_layout->layout);
    }

    if (&old_layout->accel_char) {
        zend_string_release_ex(new_layout->accel_char, 0);
        new_layout->accel_char = zend_string_copy(old_layout->accel_char);
    }

    if (&old_layout->cairo_context_zv) {
        ZVAL_COPY(&new_layout->cairo_context_zv, &old_layout->cairo_context_zv);
    }

    if (&old_layout->pango_context_zv) {
        ZVAL_COPY(&new_layout->pango_context_zv, &old_layout->pango_context_zv);
    }

    zend_objects_clone_members(&new_layout->std, &old_layout->std);

    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_layout)
{
    memcpy(
        &pango_layout_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_layout_object_handlers.offset = offsetof(pango_layout_object, std);
    pango_layout_object_handlers.free_obj = pango_layout_free_obj;
    pango_layout_object_handlers.clone_obj = pango_layout_clone_obj;

    pango_ce_pango_layout = register_class_Pango_Layout();
    pango_ce_pango_layout->create_object = pango_layout_create_object;

    pango_ce_pango_alignment = register_class_Pango_Alignment();
    pango_ce_pango_wrap_mode = register_class_Pango_WrapMode();
    pango_ce_pango_ellipsize_mode = register_class_Pango_EllipsizeMode();

    return SUCCESS;
}
/* }}} */
