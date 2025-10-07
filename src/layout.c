/*
  +----------------------------------------------------------------------+
  | PHP Version 8                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors:  Michael Maclean <mgdm@php.net>                             |
  |           David Marín <davefx@gmail.com>                             |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_pango.h"
#include "layout_arginfo.h"

#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_layout;
zend_class_entry *pango_ce_pango_alignment;
zend_class_entry *pango_ce_pango_wrap_mode;
zend_class_entry *pango_ce_pango_ellipsize_mode;

PHP_PANGO_API zend_class_entry* php_pango_get_layout_ce() {
    return pango_ce_pango_layout;
}

static zend_object_handlers pango_layout_object_handlers;

pango_layout_object *pango_layout_fetch_object(zend_object *object)
{
    return (pango_layout_object *) ((char*)(object) - XtOffsetOf(pango_layout_object, std));
}

/* {{{ Creates a PangoLayout based on the Cairo or Pango Context object */
PHP_METHOD(Pango_Layout, __construct)
{
    zval *context_zval = NULL;
    zend_class_entry *cairo_ce_cairo_context = php_cairo_get_context_ce();
    cairo_context_object *context_object;
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(context_zval, cairo_ce_cairo_context)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_CAIRO_CONTEXT_P(context_zval);

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    layout_object->layout = pango_cairo_create_layout(context_object->context);

    if (layout_object->layout == NULL) {
        zend_throw_exception(
            pango_ce_pango_exception,
            "Could not create the Pango layout",
            0
        );
        RETURN_THROWS();
    }

    ZVAL_COPY(&layout_object->cairo_context_zv, context_zval);
}
/* }}} */

/* {{{ Return the PangoContext for the current layout */
PHP_METHOD(Pango_Layout, getContext)
{
    pango_layout_object *layout_object;
    pango_context_object *context_object;
    PangoContext *context;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    if (Z_TYPE(layout_object->pango_context_zv) != IS_UNDEF) {
        ZVAL_COPY(return_value, &layout_object->pango_context_zv);
    } else {
        object_init_ex(return_value, php_pango_get_context_ce());
    }

    /* Get the context_object */
    context_object = Z_PANGO_CONTEXT_P(return_value);
    /* Destroy an existing pango context cause we're getting a new one */
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
    pango_layout_object *layout_object;
    char *text;
    size_t text_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    // The text will also be truncated on encountering a nul-termination even when length is positive.
    // That is problematic as php allows embedded nuls in strings.
    // check if text contains a null byte and warn the user
    if (memchr(text, '\0', text_len) != NULL) {
        zend_error(E_NOTICE, "Text contains null byte and will be truncated.");
    }
    pango_layout_set_text(layout_object->layout, text, text_len);
}
/* }}} */

/* {{{ Gets the text currently in the layout */
PHP_METHOD(Pango_Layout, getText)
{
    pango_layout_object *layout_object;
    const char *text;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    if (text = pango_layout_get_text(layout_object->layout)) {
        RETURN_STRING((char *)text);
    }
    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ Sets the markup of the layout. */
PHP_METHOD(Pango_Layout, setMarkup)
{
    zval *layout_zval = NULL;
    pango_layout_object *layout_object;
    char *markup;
    size_t markup_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(markup, markup_len)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    // The text may be truncated on encountering a null byte even when length is positive.
    // That is problematic as php allows embedded nuls in strings.
    // Check if markup contains a null byte and warn the user
    if (memchr(markup, '\0', markup_len) != NULL) {
        zend_error(E_NOTICE, "Pango\\Pango::setMarkup(): Markup contains null byte. "
            "This may cause the underlying pango markup parser to fail, "
            "the text may be truncated, or not be set."
        );
    }

    pango_layout_set_markup(layout_object->layout, markup, markup_len);
}
/* }}} */

/* {{{ Updates the private PangoContext of a PangoLayout to match the current transformation
       and target surface of a Cairo context.
       PARAMS ARE REVERSED FROM NATIVE PANGO */
PHP_METHOD(Pango_Layout, contextChanged)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_context_changed(layout_object->layout);
}
/* }}} */

/* {{{ Sets the markup of the layout with accelerator markers. */
PHP_METHOD(Pango_Layout, setMarkupWithAccel)
{
    pango_layout_object *layout_object;
    char *markup;
    size_t markup_len = 0;
    char *accel_marker;
    size_t accel_marker_len = 0;
    gunichar first_accel_codepoint = 0;
    gunichar accel_marker_char = 0;
    char first_accel_char[6];  // Max UTF-8 char is 6 bytes
    int first_accel_char_len;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(markup, markup_len)
        Z_PARAM_STRING(accel_marker, accel_marker_len)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    if (memchr(markup, '\0', markup_len) != NULL) {
        zend_error(E_NOTICE, "Pango\\Pango::setMarkupWithAccel(): Markup contains null byte. "
            "This may cause the underlying pango markup parser to fail, "
            "the text may be truncated, or not be set."
        );
    }

    // Convert UTF-8 string to gunichar
    if (accel_marker_len > 0) {
        accel_marker_char = g_utf8_get_char(accel_marker);
    }

    pango_layout_set_markup_with_accel(
        layout_object->layout,
        markup,
        markup_len,
        accel_marker_char,
        &first_accel_codepoint
    );

    if (first_accel_codepoint == 0) {
        RETURN_EMPTY_STRING();
    }

    first_accel_char_len = g_unichar_to_utf8(first_accel_codepoint, first_accel_char);
    RETURN_STRINGL(first_accel_char, first_accel_char_len);
}
/* }}} */

/* {{{ Updates the private PangoContext of a PangoLayout to match the current transformation
       and target surface of a Cairo context. */
PHP_METHOD(Pango_Layout, updateLayout)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_update_layout(context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Draws a PangoLayoutLine in the specified cairo context. */
PHP_METHOD(Pango_Layout, showLayout)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_show_layout(context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Adds the specified text to the current path in the specified cairo context. */
PHP_METHOD(Pango_Layout, layoutPath)
{
    pango_layout_object *layout_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    context_object = Z_CAIRO_CONTEXT_P(&layout_object->cairo_context_zv);
    pango_cairo_layout_path(context_object->context, layout_object->layout);
}
/* }}} */

/* {{{ Gets the width of the layout. */
PHP_METHOD(Pango_Layout, getWidth)
{
    pango_layout_object *layout_object;
    long width;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    width = pango_layout_get_width(layout_object->layout);
    RETURN_LONG(width);
}
/* }}} */

/* {{{ Gets the height of the layout. */
PHP_METHOD(Pango_Layout, getHeight)
{
    pango_layout_object *layout_object;
    long height;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    height = pango_layout_get_height(layout_object->layout);
    RETURN_LONG((zend_long) height);
}
/* }}} */

/* {{{ Gets the size of the layout. */
PHP_METHOD(Pango_Layout, getSize)
{
    pango_layout_object *layout_object;
    int height = 0, width = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    if (!layout_object->layout) {
        RETURN_NULL();
    }
    pango_layout_get_size(layout_object->layout, &width, &height);

    // TODO: don't return an array but an object with properties
    array_init(return_value);
    add_assoc_long(return_value, "width", (zend_long) width);
    add_assoc_long(return_value, "height", (zend_long) height);
}
/* }}} */

/* {{{ Gets the size of layout in pixels */
PHP_METHOD(Pango_Layout, getPixelSize)
{
    zval *layout_zval = NULL;
    pango_layout_object *layout_object;
    int height = 0, width = 0;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_get_pixel_size(layout_object->layout, &width, &height);

    // TODO: don't return an array but an object with properties
    array_init(return_value);
    add_assoc_long(return_value, "width", width);
    add_assoc_long(return_value, "height", height);
}
/* }}} */

/* {{{ Gets the extents of layout in */
PHP_METHOD(Pango_Layout, getExtents)
{
    pango_layout_object *layout_object;
    PangoRectangle ink = {0};
    PangoRectangle logical = {0};
    zval ink_array;
    zval logical_array;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_get_extents(layout_object->layout, &ink, &logical);

    // TODO: don't return an array but rectangle objects
    array_init(return_value);
    array_init(&ink_array);
    add_assoc_long(&ink_array, "x", (zend_long) ink.x);
    add_assoc_long(&ink_array, "y", (zend_long) ink.y);
    add_assoc_long(&ink_array, "width", (zend_long) ink.width);
    add_assoc_long(&ink_array, "height", (zend_long) ink.height);
    add_assoc_zval(return_value, "ink", &ink_array);

    array_init(&logical_array);
    add_assoc_long(&logical_array, "x", (zend_long) logical.x);
    add_assoc_long(&logical_array, "y", (zend_long) logical.y);
    add_assoc_long(&logical_array, "width", (zend_long) logical.width);
    add_assoc_long(&logical_array, "height", (zend_long) logical.height);
    add_assoc_zval(return_value, "logical", &logical_array);
}
/* }}} */

/* {{{ Gets the extents of layout in pixels */
PHP_METHOD(Pango_Layout, getPixelExtents)
{
    pango_layout_object *layout_object;
    PangoRectangle ink;
    PangoRectangle logical;
    zval ink_array;
    zval logical_array;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_get_pixel_extents(layout_object->layout, &ink, &logical);

    // TODO: don't return an array but rectangle objects
    array_init(return_value);
    array_init(&ink_array);
    add_assoc_long(&ink_array, "x", ink.x);
    add_assoc_long(&ink_array, "y", ink.y);
    add_assoc_long(&ink_array, "width", ink.width);
    add_assoc_long(&ink_array, "height", ink.height);
    add_assoc_zval(return_value, "ink", &ink_array);
    array_init(&logical_array);
    add_assoc_long(&logical_array, "x", logical.x);
    add_assoc_long(&logical_array, "y", logical.y);
    add_assoc_long(&logical_array, "width", logical.width);
    add_assoc_long(&logical_array, "height", logical.height);
    add_assoc_zval(return_value, "logical", &logical_array);
}
/* }}} */

/* {{{ Sets the width of the layout. */
PHP_METHOD(Pango_Layout, setWidth)
{
    pango_layout_object *layout_object;
    zend_long width;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(width)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_width(layout_object->layout, width);
}
/* }}} */

/* {{{ Sets the height of the layout. */
PHP_METHOD(Pango_Layout, setHeight)
{
    pango_layout_object *layout_object;
    zend_long height;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_height(layout_object->layout, height);
}
/* }}} */

/* {{{ Sets the font_description of the layout. */
PHP_METHOD(Pango_Layout, setFontDescription)
{
    zval *font_desc_zv = NULL;
    pango_layout_object *layout_object;
    pango_font_description_object *font_description_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    font_description_object = Z_PANGO_FONT_DESC_P(font_desc_zv);
    pango_layout_set_font_description(layout_object->layout, font_description_object->font_description);
}
/* }}} */

/* {{{ Gets the font_description of the layout. */
PHP_METHOD(Pango_Layout, getFontDescription)
{
    pango_layout_object *layout_object;
    pango_font_description_object *font_description_object = NULL;
    const PangoFontDescription *font_description = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    // font_description can be NULL, in that case the font description is from the context and not set on the layout
    if (!(font_description = pango_layout_get_font_description(layout_object->layout))) {
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
    pango_layout_object *layout_object;
    zend_bool justify;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(justify)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_justify(layout_object->layout, justify);
}
/* }}} */

/* {{{ Returns whether text will be justified or not in the current layout */
PHP_METHOD(Pango_Layout, getJustify)
{    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_BOOL(pango_layout_get_justify(layout_object->layout));
}
/* }}} */

/* {{{ Sets whether each line should be justified. */
PHP_METHOD(Pango_Layout, setAlignment)
{
    pango_layout_object *layout_object;
    zend_object *alignment;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(alignment, pango_ce_pango_alignment)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_alignment(
        layout_object->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(alignment))
    );
}
/* }}} */

/* {{{ Returns whether text will be justified or not in the current layout */
PHP_METHOD(Pango_Layout, getAlignment)
{
    pango_layout_object *layout_object;
    zend_object *alignment_case;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());

    zend_enum_get_case_by_value(
        &alignment_case, pango_ce_pango_alignment,
        pango_layout_get_alignment(layout_object->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(alignment_case);
}
/* }}} */

/* {{{ Sets how each line should be wrapped. */
PHP_METHOD(Pango_Layout, setWrap)
{
    pango_layout_object *layout_object;
    zend_object *wrap;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(wrap, pango_ce_pango_wrap_mode)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_wrap(
        layout_object->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(wrap))
    );
}
/* }}} */

/* {{{ Returns how text will be wrapped or not in the current layout. */
PHP_METHOD(Pango_Layout, getWrap)
{
    pango_layout_object *layout_object;
    zend_object *wrap_case;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    zend_enum_get_case_by_value(
        &wrap_case, pango_ce_pango_wrap_mode,
        pango_layout_get_wrap(layout_object->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(wrap_case);
}
/* }}} */

/* {{{ Queries whether the layout had to wrap any paragraphs. */
PHP_METHOD(Pango_Layout, isWrapped)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_BOOL(pango_layout_is_wrapped(layout_object->layout));
}
/* }}} */

/* {{{ Sets how far each paragraph should be indented. */
PHP_METHOD(Pango_Layout, setIndent)
{
    pango_layout_object *layout_object;
    long indent;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(indent)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_indent(layout_object->layout, indent);
}
/* }}} */

/* {{{ Returns how text will be indentped or not in the current layout */
PHP_METHOD(Pango_Layout, getIndent)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_LONG(pango_layout_get_indent(layout_object->layout));
}
/* }}} */

/* {{{ Sets the line spacing for the paragraph */
PHP_METHOD(Pango_Layout, setSpacing)
{
    pango_layout_object *layout_object;
    long spacing;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(spacing)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_spacing(layout_object->layout, spacing);
}
/* }}} */

/* {{{ Returns the spacing for the current layout */
PHP_METHOD(Pango_Layout, getSpacing)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_LONG(pango_layout_get_spacing(layout_object->layout));
}
/* }}} */

/* {{{ Sets the ellipsize mode for the layout */
PHP_METHOD(Pango_Layout, setEllipsize)
{
    pango_layout_object *layout_object;
    zend_object *ellipsize;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(ellipsize, pango_ce_pango_ellipsize_mode)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    pango_layout_set_ellipsize(
        layout_object->layout,
        Z_LVAL_P(zend_enum_fetch_case_value(ellipsize))
    );
}
/* }}} */

/* {{{ Returns the ellipsize for the current layout */
PHP_METHOD(Pango_Layout, getEllipsize)
{
    pango_layout_object *layout_object;
    zend_object *ellipsize_case;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    zend_enum_get_case_by_value(
        &ellipsize_case, pango_ce_pango_ellipsize_mode,
        pango_layout_get_ellipsize(layout_object->layout),
        NULL, false
    );

    RETURN_OBJ_COPY(ellipsize_case);
}
/* }}} */

/* {{{ Queries whether the layout had to ellipsize any paragraphs */
PHP_METHOD(Pango_Layout, isEllipsized)
{
    pango_layout_object *layout_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_BOOL(pango_layout_is_ellipsized(layout_object->layout));
}
/* }}} */

/* {{{ Returns an array of LayoutLines representing each line of the layout */
PHP_METHOD(Pango_Layout, getLines)
{
    zval *layout;
    pango_layout_object *layout_object;
    GSList *lines;
    GSList *iter;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = getThis();
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (iter = lines; iter != NULL; iter = iter->next) {
        object_init_ex(&line_zv, php_pango_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)iter->data);
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
    GSList *iter;
    zval line_zv;
    pango_layout_line_object *line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout = getThis();
    layout_object = Z_PANGO_LAYOUT_P(layout);
    // Todo: Check if there is always be at least one line, even for empty text
    if (!(lines = pango_layout_get_lines_readonly(layout_object->layout))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (iter = lines; iter != NULL; iter = iter->next) {
        object_init_ex(&line_zv, php_pango_get_layout_line_ce());
        line_object = Z_PANGO_LAYOUT_LINE_P(&line_zv);
        line_object->line = pango_layout_line_ref((PangoLayoutLine *)iter->data);
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
    PangoLayoutLine *layout_line;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(line_number)
    ZEND_PARSE_PARAMETERS_END();

    layout = getThis();
    layout_object = Z_PANGO_LAYOUT_P(layout);

    if (!(layout_line = pango_layout_get_line(layout_object->layout, (int) line_number))) {
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

    layout = getThis();
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
    zval *elem = NULL;
    pango_layout_object *layout_object;
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
    RETURN_LONG(pango_layout_get_line_count(layout_object->layout));
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

    ZEND_PARSE_PARAMETERS_START(0, 1);
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(flags)
    ZEND_PARSE_PARAMETERS_END();

    layout_object = Z_PANGO_LAYOUT_P(getThis());
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

    zval_ptr_dtor(&intern->cairo_context_zv);
    zval_ptr_dtor(&intern->pango_context_zv);

    if (intern->layout) {
        g_object_unref(intern->layout);
        intern->layout = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_obj_ctor(zend_class_entry *ce, pango_layout_object **intern)
{
    pango_layout_object *object = ecalloc(1, sizeof(pango_layout_object) + zend_object_properties_size(ce));

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

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_layout)
{
    memcpy(
        &pango_layout_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_layout_object_handlers.offset = XtOffsetOf(pango_layout_object, std);
    pango_layout_object_handlers.free_obj = pango_layout_free_obj;

    pango_ce_pango_layout = register_class_Pango_Layout();
    pango_ce_pango_layout->create_object = pango_layout_create_object;

    pango_ce_pango_alignment = register_class_Pango_Alignment();
    pango_ce_pango_wrap_mode = register_class_Pango_WrapMode();
    pango_ce_pango_ellipsize_mode = register_class_Pango_EllipsizeMode();

    return SUCCESS;
}
/* }}} */
