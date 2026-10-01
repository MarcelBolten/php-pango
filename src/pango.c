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
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ini.h>
#include <ext/standard/info.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_enum.h>
#include <pango/pangofc-fontmap.h>
#include <pango/pangocairo.h>

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "analysis.h"
#include "context.h"
#include "glyph_string.h"
#include "logattr_list.h"
#include "item.h"
#include "pango.h"
#include "pango_arginfo.h"

zend_class_entry *pango_ce_markup_parse_result;
zend_class_entry *pango_ce_paragraph_boundary;
zend_class_entry *pango_ce_quantized_line_geometry;
zend_class_entry *pango_ce_shape_flags;

PHP_PANGO_API zend_class_entry *php_pango_get_markup_parse_result_ce()
{
    return pango_ce_markup_parse_result;
}

PHP_PANGO_API zend_class_entry *php_pango_get_paragraph_boundary_ce()
{
    return pango_ce_paragraph_boundary;
}

PHP_PANGO_API zend_class_entry *php_pango_get_quantized_line_geometry_ce()
{
    return pango_ce_quantized_line_geometry;
}

PHP_PANGO_API zend_class_entry *php_pango_get_shape_flags_ce()
{
    return pango_ce_shape_flags;
}

/* {{{ returns the Pango version */
ZEND_FUNCTION(Pango_version)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_version());
}
/* }}} */

/* {{{ returns the Pango version as a string */
ZEND_FUNCTION(Pango_version_string)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING((char *)pango_version_string());
}
/* }}} */

/* {{{ Checks that the Pango library in use is compatible with the given version */
ZEND_FUNCTION(Pango_version_check)
{
    zend_long major = PANGO_VERSION_MAJOR;
    zend_long minor = PANGO_VERSION_MINOR;
    zend_long micro = PANGO_VERSION_MICRO;
    const char *result = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 3)
        Z_PARAM_OPTIONAL
        Z_PARAM_LONG(major)
        Z_PARAM_LONG(minor)
        Z_PARAM_LONG(micro)
    ZEND_PARSE_PARAMETERS_END();

    result = pango_version_check(major, minor, micro);

    if (!result) {
        RETURN_EMPTY_STRING();
    };

    RETURN_STRING(result);
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_is_zero_width)
{
    zend_string *char_str;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(char_str)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(char_str)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (g_utf8_strlen(ZSTR_VAL(char_str), ZSTR_LEN(char_str)) > 1) {
        zend_argument_value_error(1, "must be a single UTF-8 character");
        RETURN_THROWS();
    }

    RETURN_BOOL(pango_is_zero_width(g_utf8_get_char(ZSTR_VAL(char_str))));
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_parse_markup)
{
    zend_string *markup;
    zend_string *accel_marker = NULL;
    gunichar accel_marker_char = 0;
    char *text;
    gunichar first_accel_codepoint = 0;
    char first_accel_char[6]; // Max UTF-8 char is 6 bytes
    int first_accel_char_len;
    PangoAttrList* attr_list;
    GError *error = NULL;
    gboolean parse_result;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_STR(markup)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(accel_marker)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(markup)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (accel_marker && zend_str_has_nul_byte(accel_marker)) {
        zend_argument_value_error(2, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (accel_marker && g_utf8_strlen(ZSTR_VAL(accel_marker), ZSTR_LEN(accel_marker)) > 1) {
        zend_argument_value_error(2, "must be a single UTF-8 character");
        RETURN_THROWS();
    }

    if (accel_marker && ZSTR_LEN(accel_marker) > 0) {
        accel_marker_char = g_utf8_get_char(ZSTR_VAL(accel_marker));
    }

    parse_result = pango_parse_markup(
        ZSTR_VAL(markup), ZSTR_LEN(markup), accel_marker_char, &attr_list,
        &text, &first_accel_codepoint, &error
    );

    if (!parse_result) {
        zend_argument_value_error(1, "Failed to parse markup: %s", error->message);
        g_error_free(error);
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_markup_parse_result_ce());

    zend_update_property_stringl(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "text", sizeof("text") - 1, text, strlen(text)
    );

    zval attr_list_zv;
    object_init_ex(&attr_list_zv, php_pango_get_attr_list_ce());
    Z_PANGO_ATTR_LIST_P(&attr_list_zv)->attr_list = attr_list;
    zend_update_property(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "attrList", sizeof("attrList") - 1, &attr_list_zv
    );
    zval_ptr_dtor(&attr_list_zv);

    if (first_accel_codepoint != 0) {
        first_accel_char_len = g_unichar_to_utf8(first_accel_codepoint, first_accel_char);
        zend_update_property_stringl(
            Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
            "accelChar", sizeof("accelChar") - 1, first_accel_char, first_accel_char_len
        );
    } else {
        zend_update_property_null(
            Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
            "accelChar", sizeof("accelChar") - 1
        );
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_MarkupParseResult, __construct)
{
    zval *attr_list_zv;
    zend_string *text;
    zend_string *accel_marker = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, php_pango_get_attr_list_ce())
        Z_PARAM_STR(text)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(accel_marker)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(2, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (accel_marker && zend_str_has_nul_byte(accel_marker)) {
        zend_argument_value_error(3, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (accel_marker && g_utf8_strlen(ZSTR_VAL(accel_marker), ZSTR_LEN(accel_marker)) > 1) {
        zend_argument_value_error(3, "must be a single UTF-8 character");
        RETURN_THROWS();
    }

    zend_update_property(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "attrList", sizeof("attrList") - 1, attr_list_zv
    );
    zend_update_property_stringl(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "text", sizeof("text") - 1, ZSTR_VAL(text), ZSTR_LEN(text)
    );
    if (accel_marker) {
        zend_update_property_stringl(
            Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
            "accelChar", sizeof("accelChar") - 1, ZSTR_VAL(accel_marker), ZSTR_LEN(accel_marker)
        );
    } else {
        zend_update_property_null(
            Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
            "accelChar", sizeof("accelChar") - 1
        );
    }
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_find_paragraph_boundary)
{
    zend_string *text;
    int paragraph_delimiter_index;
    int next_paragraph_start;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_find_paragraph_boundary(
        ZSTR_VAL(text), ZSTR_LEN(text),
        &paragraph_delimiter_index, &next_paragraph_start
    );

    object_init_ex(return_value, php_pango_get_paragraph_boundary_ce());
    zend_update_property_long(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "delimiterByteIndex", sizeof("delimiterByteIndex") - 1, paragraph_delimiter_index
    );
    zend_update_property_long(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value),
        "nextStart", sizeof("nextStart") - 1, next_paragraph_start
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_ParagraphBoundary, __construct)
{
    zend_long delimiter_byte_index;
    zend_long next_start;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(delimiter_byte_index)
        Z_PARAM_LONG(next_start)
    ZEND_PARSE_PARAMETERS_END();

    zend_update_property_long(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "delimiterByteIndex", sizeof("delimiterByteIndex") - 1, delimiter_byte_index
    );
    zend_update_property_long(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "nextStart", sizeof("nextStart") - 1, next_start
    );
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_log2vis_get_embedding_levels)
{
    zend_string *text;
    size_t text_len;
    zend_object *base_dir_obj;
    PangoDirection base_dir;
    guint8 *embedding_levels;
    unsigned int n_chars;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(text)
        Z_PARAM_OBJ_OF_CLASS(base_dir_obj, php_pango_get_direction_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    base_dir = (PangoDirection) Z_LVAL_P(zend_enum_fetch_case_value(base_dir_obj));

    embedding_levels = pango_log2vis_get_embedding_levels(
        ZSTR_VAL(text), ZSTR_LEN(text),
        &base_dir
    );

    n_chars = g_utf8_strlen(ZSTR_VAL(text), ZSTR_LEN(text));
    array_init(return_value);
    for (unsigned int i = 0; i < n_chars; i++) {
        add_next_index_long(return_value, embedding_levels[i]);
    }

    g_free(embedding_levels);
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_reorder_items)
{
    zval *items_in_zv;
    zval *tmp_item_in_zv;
    // are all array items Pango\Item objects?
    bool all_items = true;
    GList *items_log = NULL;
    GList *items_vis;
    zval tmp_item_zv;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(items_in_zv)
    ZEND_PARSE_PARAMETERS_END();

    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(items_in_zv), tmp_item_in_zv) {
        if (Z_TYPE_P(tmp_item_in_zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(tmp_item_in_zv), php_pango_get_item_ce())) {
            all_items = false;
            break;
        }
        PangoItem *item = Z_PANGO_ITEM_P(tmp_item_in_zv)->item;
        items_log = g_list_prepend(items_log, item);
    } ZEND_HASH_FOREACH_END();

    if (!all_items) {
        g_list_free(items_log);
        zend_argument_type_error(1, "must be an array of Pango\\Item objects");
        RETURN_THROWS();
    }

    items_vis = pango_reorder_items(g_list_reverse(items_log));

    array_init(return_value);
    for (GList *item = items_vis; item != NULL; item = item->next) {
        object_init_ex(&tmp_item_zv, php_pango_get_item_ce());
        Z_PANGO_ITEM_P(&tmp_item_zv)->item = pango_item_copy((PangoItem *)item->data);
        add_next_index_zval(return_value, &tmp_item_zv);
    }

    g_list_free(items_log);
    g_list_free(items_vis);
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_units_to_double)
{
    zend_long units;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(units)
    ZEND_PARSE_PARAMETERS_END();

    // guard units to be within the range of a 32-bit signed integer
    if (units < INT32_MIN || units > INT32_MAX) {
        zend_argument_value_error(1, "must be a between %d and %d", INT32_MIN, INT32_MAX);
        RETURN_THROWS();
    }

    RETURN_DOUBLE(pango_units_to_double((int) units));
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_units_from_double)
{
    double d;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(d)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_LONG(pango_units_from_double(d));
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_quantize_line_geometry)
{
    zend_long thickness;
    int quantized_thickness;
    zend_long position;
    int quantized_position;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(thickness)
        Z_PARAM_LONG(position)
    ZEND_PARSE_PARAMETERS_END();

    // guard thickness and position to be within the range of a 32-bit signed integer
    if (thickness < INT32_MIN || thickness > INT32_MAX) {
        zend_argument_value_error(1, "must be a between %d and %d", INT32_MIN, INT32_MAX);
        RETURN_THROWS();
    }
    if (position < INT32_MIN || position > INT32_MAX) {
        zend_argument_value_error(2, "must be a between %d and %d", INT32_MIN, INT32_MAX);
        RETURN_THROWS();
    }

    quantized_thickness = (int) thickness;
    quantized_position = (int) position;

    pango_quantize_line_geometry(&quantized_thickness, &quantized_position);

    object_init_ex(return_value, pango_ce_quantized_line_geometry);
    zend_update_property_long(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value), "thickness", sizeof("thickness") - 1,
        quantized_thickness
    );
    zend_update_property_long(
        Z_OBJCE_P(return_value), Z_OBJ_P(return_value), "position", sizeof("position") - 1,
        quantized_position
    );
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_shape)
{
    zend_string *text;
    zval *analysis_zv;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(text)
        Z_PARAM_OBJECT_OF_CLASS(analysis_zv, php_pango_get_analysis_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_glyph_string_ce());
    Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string = pango_glyph_string_new();

    pango_shape(
        ZSTR_VAL(text), ZSTR_LEN(text),
        pango_analysis_object_get_analysis(analysis_zv),
        Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string
    );
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_shape_full)
{
    zend_string *paragraph_text;
    zval *analysis_zv;
    zend_long offset;
    zend_long text_len;
    const char *text;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        // Z_PARAM_STR(text)
        Z_PARAM_STR(paragraph_text)
        Z_PARAM_LONG(offset)
        Z_PARAM_LONG(text_len)
        Z_PARAM_OBJECT_OF_CLASS(analysis_zv, php_pango_get_analysis_ce())
    ZEND_PARSE_PARAMETERS_END();

    // if (zend_str_has_nul_byte(text)) {
    //     zend_argument_value_error(1, "must not contain NUL bytes");
    //     RETURN_THROWS();
    // }
    if (paragraph_text && zend_str_has_nul_byte(paragraph_text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (offset < 0 || offset > ZSTR_LEN(paragraph_text)) {
        zend_argument_value_error(2, "must be between 0 and " ZEND_LONG_FMT, (zend_long) ZSTR_LEN(paragraph_text));
        RETURN_THROWS();
    }
    if (text_len < 0 || text_len > ZSTR_LEN(paragraph_text) - offset) {
        zend_argument_value_error(3, "must be between 0 and " ZEND_LONG_FMT, (zend_long) (ZSTR_LEN(paragraph_text) - offset));
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_glyph_string_ce());
    Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string = pango_glyph_string_new();

    text = ZSTR_VAL(paragraph_text) + offset;

    pango_shape_full(
        text, (int) text_len,
        (const char *) ZSTR_VAL(paragraph_text), (int) ZSTR_LEN(paragraph_text),
        pango_analysis_object_get_analysis(analysis_zv),
        Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string
    );
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_shape_with_flags)
{
    zend_string *paragraph_text;
    zend_long offset;
    zend_long text_len;
    zval *analysis_zv;
    zend_object *flags_obj = NULL;
    PangoShapeFlags flags;
    const char *text;

    ZEND_PARSE_PARAMETERS_START(4, 5)
        Z_PARAM_STR(paragraph_text)
        Z_PARAM_LONG(offset)
        Z_PARAM_LONG(text_len)
        // Z_PARAM_STR(text)
        Z_PARAM_OBJECT_OF_CLASS(analysis_zv, php_pango_get_analysis_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJ_OF_CLASS(flags_obj, php_pango_get_shape_flags_ce())
    ZEND_PARSE_PARAMETERS_END();

    // if (zend_str_has_nul_byte(text)) {
    //     zend_argument_value_error(1, "must not contain NUL bytes");
    //     RETURN_THROWS();
    // }
    if (zend_str_has_nul_byte(paragraph_text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (offset < 0 || offset > ZSTR_LEN(paragraph_text)) {
        zend_argument_value_error(2, "must be between 0 and " ZEND_LONG_FMT, (zend_long) ZSTR_LEN(paragraph_text));
        RETURN_THROWS();
    }
    if (text_len < 0 || text_len > ZSTR_LEN(paragraph_text) - offset) {
        zend_argument_value_error(3, "must be between 0 and " ZEND_LONG_FMT, (zend_long) (ZSTR_LEN(paragraph_text) - offset));
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_pango_get_glyph_string_ce());
    Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string = pango_glyph_string_new();

    text = ZSTR_VAL(paragraph_text) + offset;

    flags = flags_obj
        ? (PangoShapeFlags) Z_LVAL_P(zend_enum_fetch_case_value(flags_obj))
        : PANGO_SHAPE_NONE;

    pango_shape_with_flags(
        text, (int) text_len,
        ZSTR_VAL(paragraph_text), (int) ZSTR_LEN(paragraph_text),
        pango_analysis_object_get_analysis(analysis_zv),
        Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string,
        flags
    );
}
/* }}} */

/* {{{ */
ZEND_FUNCTION(Pango_shape_item)
{
    zend_string *paragraph_text;
    zval *item_zv;
    zval *logattr_list_zv = NULL;
    PangoLogAttr *log_attr_arr = NULL;
    zend_object *flags_obj = NULL;
    PangoShapeFlags flags;

    ZEND_PARSE_PARAMETERS_START(2, 4)
        Z_PARAM_STR(paragraph_text)
        Z_PARAM_OBJECT_OF_CLASS(item_zv, php_pango_get_item_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(logattr_list_zv, php_pango_get_logattr_list_ce())
        Z_PARAM_OBJ_OF_CLASS(flags_obj, php_pango_get_shape_flags_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(paragraph_text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (logattr_list_zv) {
        log_attr_arr = pango_logattr_list_object_get_logattr_arr(logattr_list_zv);
    }

    object_init_ex(return_value, php_pango_get_glyph_string_ce());
    Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string = pango_glyph_string_new();

    flags = flags_obj
        ? (PangoShapeFlags) Z_LVAL_P(zend_enum_fetch_case_value(flags_obj))
        : PANGO_SHAPE_NONE;

    pango_shape_item(
        Z_PANGO_ITEM_P(item_zv)->item,
        ZSTR_VAL(paragraph_text), ZSTR_LEN(paragraph_text),
        log_attr_arr,
        Z_PANGO_GLYPH_STRING_P(return_value)->glyph_string,
        flags
    );
}
/* }}} */

static const zend_module_dep pango_module_deps[] = {
    ZEND_MOD_REQUIRED("cairo")
    ZEND_MOD_END
};

/* {{{ pango_module_entry */
zend_module_entry pango_module_entry = {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    pango_module_deps,
    "pango",
    ext_functions,
    PHP_MINIT(pango),
    PHP_MSHUTDOWN(pango),
    NULL,
    NULL,
    PHP_MINFO(pango),
    PHP_PANGO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PANGO
ZEND_GET_MODULE(pango)
#endif

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango)
{
    pango_ce_markup_parse_result = register_class_Pango_MarkupParseResult();
    pango_ce_paragraph_boundary = register_class_Pango_ParagraphBoundary();
    pango_ce_quantized_line_geometry = register_class_Pango_QuantizedLineGeometry();
    pango_ce_shape_flags = register_class_Pango_ShapeFlags();

    register_pango_symbols(module_number);

    /* classes without inheritance */
    PHP_MINIT(pango_analysis)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_iter)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_list)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_color)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_coverage)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_exception)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_description)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_face)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_family)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_metrics)(INIT_FUNC_ARGS_PASSTHRU);
    // PHP_MINIT(pango_ft2_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_geometry)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_info)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_item)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_string)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_vis_attr)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_item)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_language)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_layout_iter)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_logattr)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_logattr_list)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_matrix)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_rectangle)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_script_iter)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_script_iter_range)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_tabstop)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_tabstops)(INIT_FUNC_ARGS_PASSTHRU);

    /* Base classes first */
    PHP_MINIT(pango_attribute)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_context)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_set)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_layout_line)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_layout)(INIT_FUNC_ARGS_PASSTHRU);

    /* subclasses thereafter */
    PHP_MINIT(pango_attr_absolute_size)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_allow_breaks)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_background_alpha)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_background)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_fallback)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_family)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_font_description)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_font_features)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_foreground_alpha)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_foreground)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_gravity_hint)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_gravity)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_insert_hyphens)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_language)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_letter_spacing)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_overline_color)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_overline)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_rise)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_scale)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_show)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_size)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_stretch)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_strikethrough_color)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_strikethrough)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_style)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_underline_color)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_underline)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_variant)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_weight)(INIT_FUNC_ARGS_PASSTHRU);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    PHP_MINIT(pango_attr_absolute_line_height)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_baseline_shift)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_font_scale)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_line_height)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_sentence)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_text_transform)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_attr_word)(INIT_FUNC_ARGS_PASSTHRU);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    PHP_MINIT(pango_attr_width)(INIT_FUNC_ARGS_PASSTHRU);
#endif
    PHP_MINIT(pango_cairo_context)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_layout_line)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_layout)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_set_simple)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_fc_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_ft2_font_map)(INIT_FUNC_ARGS_PASSTHRU);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(pango)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    // TODO: add lazy loading and store global reference to font map, only shutdown if we created it
    PangoFontMap *font_map = pango_cairo_font_map_get_default();
    if (PANGO_IS_FC_FONT_MAP(font_map)) {
        pango_fc_font_map_shutdown((PangoFcFontMap *)font_map);
    }

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pango)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Pango text rendering support", "enabled");
    php_info_print_table_row(2, "Compiled as",
#ifdef COMPILE_DL_PANGO
        "dynamic module"
#else
        "static module"
#endif
    );
    php_info_print_table_row(2, "Pango version",
#ifdef PANGO_VERSION_STRING
        PANGO_VERSION_STRING
#else
        "Unknown"
#endif
    );
    php_info_print_table_row(2, "Extension version", PHP_PANGO_VERSION);
    php_info_print_table_end();
}
/* }}} */
