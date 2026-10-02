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
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "context.h"
#include "color.h"
#include "exception.h"
#include "font_description.h"
#include "font_description_arginfo.h"

zend_class_entry *pango_ce_pango_font_description;
zend_class_entry *pango_ce_pango_style;
zend_class_entry *pango_ce_pango_weight;
zend_class_entry *pango_ce_pango_variant;
zend_class_entry *pango_ce_pango_stretch;
zend_class_entry *pango_ce_pango_font_mask;
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
zend_class_entry *pango_ce_pango_font_color;
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
zend_class_entry *pango_ce_pango_width;
#endif

static zend_object_handlers pango_font_description_object_handlers;

pango_font_description_object *pango_font_description_fetch_object(zend_object *object)
{
    return (pango_font_description_object *) ((char*)(object) - offsetof(pango_font_description_object, std));
}

PHP_PANGO_API PangoFontDescription *pango_font_description_object_get_font_description(zval *zv)
{
    return (PangoFontDescription *) Z_PANGO_FONT_DESC_P(zv)->font_description;
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_description_ce(void)
{
    return pango_ce_pango_font_description;
}

PHP_PANGO_API zend_class_entry* php_pango_get_style_ce(void)
{
    return pango_ce_pango_style;
}

PHP_PANGO_API zend_class_entry* php_pango_get_weight_ce(void)
{
    return pango_ce_pango_weight;
}

PHP_PANGO_API zend_class_entry* php_pango_get_variant_ce(void)
{
    return pango_ce_pango_variant;
}

PHP_PANGO_API zend_class_entry* php_pango_get_stretch_ce(void)
{
    return pango_ce_pango_stretch;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
PHP_PANGO_API zend_class_entry* php_pango_get_font_color_ce(void)
{
    return pango_ce_pango_font_color;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
PHP_PANGO_API zend_class_entry* php_pango_get_width_ce(void)
{
    return pango_ce_pango_width;
}
#endif

#define PANGO_FONT_DESCRIPTION_ENUM_GETTER(_enum_ce, _pango_getter) \
    pango_font_description_object *font_description_object; \
    zend_object *enum_case; \
\
    ZEND_PARSE_PARAMETERS_NONE(); \
\
    zend_enum_get_case_by_value( \
        &enum_case, _enum_ce, \
        _pango_getter(pango_font_description_object_get_font_description(ZEND_THIS)), \
        NULL, false \
    ); \
\
    RETURN_OBJ_COPY(enum_case);

#define PANGO_FONT_DESCRIPTION_ENUM_SETTER(_enum_ce, _pango_setter) \
    pango_font_description_object *font_description_object; \
    zend_object *enum_case; \
\
    ZEND_PARSE_PARAMETERS_START(1, 1) \
        Z_PARAM_OBJ_OF_CLASS(enum_case, _enum_ce) \
    ZEND_PARSE_PARAMETERS_END(); \
\
    _pango_setter( \
        pango_font_description_object_get_font_description(ZEND_THIS), \
        Z_LVAL_P(zend_enum_fetch_case_value(enum_case)) \
    );\
\
    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));

/* {{{ Creates a new font description object. */
PHP_METHOD(Pango_FontDescription, __construct)
{
    pango_font_description_object *font_description_object = NULL;
    zend_string *text = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(text)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(ZEND_THIS);

    if (text && ZSTR_LEN(text) > 0) {
        if (zend_str_has_nul_byte(text)) {
            zend_argument_value_error(1, "must not contain NUL bytes");
            RETURN_THROWS();
        }
        font_description_object->font_description = pango_font_description_from_string(ZSTR_VAL(text));
    } else {
        font_description_object->font_description = pango_font_description_new();
    }

    if (!font_description_object->font_description) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Could not instantiate Pango\\FontDescription",
            0
        );
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ Gets the variant of the font description. */
PHP_METHOD(Pango_FontDescription, getVariant)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_variant, pango_font_description_get_variant);
}
/* }}} */

/* {{{ Sets the variant of the layout. */
PHP_METHOD(Pango_FontDescription, setVariant)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_variant, pango_font_description_set_variant);
}
/* }}} */

/* {{{ Compares two font description objects for equality. */
PHP_METHOD(Pango_FontDescription, equal)
{
    zval *font_description_2_zval = NULL;
    pango_font_description_object *font_description_object;
    pango_font_description_object *font_description_2_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_description_2_zval, pango_ce_pango_font_description)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(ZEND_THIS);
    font_description_2_object = Z_PANGO_FONT_DESC_P(font_description_2_zval);

    RETURN_BOOL(pango_font_description_equal(
        font_description_object->font_description,
        font_description_2_object->font_description
    ));
}
/* }}} */

/* {{{ Sets the family name field of a font description. */
PHP_METHOD(Pango_FontDescription, setFamily)
{
    zend_string *family;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(family)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(family)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_font_description_set_family(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description, ZSTR_VAL(family));

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Gets the family name field of a font description. */
PHP_METHOD(Pango_FontDescription, getFamily)
{
    const char *family;

    ZEND_PARSE_PARAMETERS_NONE();

    family = pango_font_description_get_family(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description);

    if (family) {
        RETURN_STRING((char *)family);
    }

    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ Sets the size field in fractional points of a font description. */
PHP_METHOD(Pango_FontDescription, setSize)
{
    zend_long size;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(size)
    ZEND_PARSE_PARAMETERS_END();

    pango_font_description_set_size(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description, size);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the size field in absolute (device) units of a font description. */
PHP_METHOD(Pango_FontDescription, setAbsoluteSize)
{
    double size;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(size)
    ZEND_PARSE_PARAMETERS_END();

    pango_font_description_set_absolute_size(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description, size);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Gets the size field of a font description. */
PHP_METHOD(Pango_FontDescription, getSize)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_font_description_get_size(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description));
}
/* }}} */

/* {{{ Determines whether the size of the font is in points (not absolute) or device units (absolute) */
PHP_METHOD(Pango_FontDescription, getSizeIsAbsolute)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_font_description_get_size_is_absolute(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description));
}
/* }}} */

/* {{{ Gets the style of the font description. */
PHP_METHOD(Pango_FontDescription, getStyle)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_style, pango_font_description_get_style);
}
/* }}} */

/* {{{ Sets the style of the layout. */
PHP_METHOD(Pango_FontDescription, setStyle)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_style, pango_font_description_set_style);
}
/* }}} */

/* {{{ Gets the weight of the font description. */
PHP_METHOD(Pango_FontDescription, getWeight)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_weight, pango_font_description_get_weight);
}
/* }}} */

/* {{{ Sets the weight of the layout. */
PHP_METHOD(Pango_FontDescription, setWeight)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_weight, pango_font_description_set_weight);
}
/* }}} */

/* {{{ Gets the stretch of the font description. */
PHP_METHOD(Pango_FontDescription, getStretch)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_stretch, pango_font_description_get_stretch);
}
/* }}} */

/* {{{ Sets the stretch of the layout. */
PHP_METHOD(Pango_FontDescription, setStretch)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_stretch, pango_font_description_set_stretch);
}
/* }}} */

/* {{{ Creates a string representation of a font description. */
PHP_METHOD(Pango_FontDescription, toString)
{
    char *result;

    ZEND_PARSE_PARAMETERS_NONE();

    if (result = pango_font_description_to_string(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description)) {
        RETVAL_STRING((const char *) result);
        g_free(result);
        return;
    }

    RETURN_EMPTY_STRING();
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
/* {{{ */
PHP_METHOD(Pango_FontDescription, getFeatures)
{
    const char *result;

    ZEND_PARSE_PARAMETERS_NONE();

    if (result = pango_font_description_get_features(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description)) {
        RETURN_STRING(result);
    }

    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, setFeatures)
{
    zend_string *features = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(features)
    ZEND_PARSE_PARAMETERS_END();

    if (features && ZSTR_LEN(features) == 0) {
        features = NULL;
    }

    if (features && zend_str_has_nul_byte(features)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_font_description_set_features(
        Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description,
        features
            ? ZSTR_VAL(features)
            : NULL
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_FontDescription, getGravity)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(php_pango_get_gravity_ce(), pango_font_description_get_gravity);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, setGravity)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(php_pango_get_gravity_ce(), pango_font_description_set_gravity);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, getVariations)
{
    const char *result;

    ZEND_PARSE_PARAMETERS_NONE();

    result = pango_font_description_get_variations(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description);

    if (result) {
        RETURN_STRING(result);
    }

    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, setVariations)
{
    zend_string *variations = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(variations)
    ZEND_PARSE_PARAMETERS_END();

    if (variations && ZSTR_LEN(variations) == 0) {
        variations = NULL;
    }

    if (variations && zend_str_has_nul_byte(variations)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    pango_font_description_set_variations(
        Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description,
        variations
            ? ZSTR_VAL(variations)
            : NULL
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, getSetFields)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_font_description_get_set_fields(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, unsetFields)
{
    zend_long bitmask;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(bitmask)
    ZEND_PARSE_PARAMETERS_END();

    pango_font_description_unset_fields(Z_PANGO_FONT_DESC_P(ZEND_THIS)->font_description, bitmask);
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
/* {{{ */
PHP_METHOD(Pango_FontDescription, getColor)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_font_color, pango_font_description_get_color);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, setColor)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_font_color, pango_font_description_set_color);
}
/* }}} */
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
/* {{{ */
PHP_METHOD(Pango_FontDescription, getWidth)
{
    PANGO_FONT_DESCRIPTION_ENUM_GETTER(pango_ce_pango_width, pango_font_description_get_width);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, setWidth)
{
    PANGO_FONT_DESCRIPTION_ENUM_SETTER(pango_ce_pango_width, pango_font_description_set_width);
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_FontDescription, betterMatch)
{
    zval *candidate_zval = NULL;
    zval *current_best_zval = NULL;
    bool result;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS(candidate_zval, pango_ce_pango_font_description)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(current_best_zval, pango_ce_pango_font_description)
    ZEND_PARSE_PARAMETERS_END();

    result = pango_font_description_better_match(
        pango_font_description_object_get_font_description(ZEND_THIS),
        current_best_zval ? pango_font_description_object_get_font_description(current_best_zval) : NULL,
        pango_font_description_object_get_font_description(candidate_zval)
    );

    RETURN_BOOL(result);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontDescription, merge)
{
    zval *other_zval = NULL;
    bool replace_existing = false;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(other_zval, pango_ce_pango_font_description)
        Z_PARAM_OPTIONAL
        Z_PARAM_BOOL(replace_existing)
    ZEND_PARSE_PARAMETERS_END();

    pango_font_description_merge(
        pango_font_description_object_get_font_description(ZEND_THIS),
        other_zval ? pango_font_description_object_get_font_description(other_zval) : NULL,
        replace_existing
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Style, parse)
{
    zend_string *string;
    PangoStyle style;
    zend_object *style_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(string)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (!(pango_parse_style(ZSTR_VAL(string), &style, FALSE))) {
        zend_argument_value_error(1, "is not a valid Pango style");
        RETURN_THROWS();
    }

    zend_enum_get_case_by_value(
        &style_case, pango_ce_pango_style,
        style, NULL, false
    );

    RETURN_OBJ_COPY(style_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Variant, parse)
{
    zend_string *string;
    PangoVariant variant;
    zend_object *variant_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(string)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (!(pango_parse_variant(ZSTR_VAL(string), &variant, FALSE))) {
        zend_argument_value_error(1, "is not a valid Pango variant");
        RETURN_THROWS();
    }

    zend_enum_get_case_by_value(
        &variant_case, pango_ce_pango_variant,
        variant, NULL, false
    );

    RETURN_OBJ_COPY(variant_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Weight, parse)
{
    zend_string *string;
    PangoWeight weight;
    zend_object *weight_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(string)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (!(pango_parse_weight(ZSTR_VAL(string), &weight, FALSE))) {
        zend_argument_value_error(1, "is not a valid Pango weight");
        RETURN_THROWS();
    }

    zend_enum_get_case_by_value(
        &weight_case, pango_ce_pango_weight,
        weight, NULL, false
    );

    RETURN_OBJ_COPY(weight_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Stretch, parse)
{
    zend_string *string;
    PangoStretch stretch;
    zend_object *stretch_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(string)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    if (!(pango_parse_stretch(ZSTR_VAL(string), &stretch, FALSE))) {
        zend_argument_value_error(1, "is not a valid Pango stretch");
        RETURN_THROWS();
    }

    zend_enum_get_case_by_value(
        &stretch_case, pango_ce_pango_stretch,
        stretch, NULL, false
    );

    RETURN_OBJ_COPY(stretch_case);
}
/* }}} */

/**
 * \Pango\FontDescription Object management
 */

/* {{{ */
static void pango_font_description_free_obj(zend_object *zobj)
{
    pango_font_description_object *intern = pango_font_description_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_description) {
        pango_font_description_free(intern->font_description);
        intern->font_description = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_description_obj_ctor(zend_class_entry *ce, pango_font_description_object **intern)
{
    pango_font_description_object *object = ecalloc(1, sizeof(pango_font_description_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_description_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_description_create_object(zend_class_entry *ce)
{
    pango_font_description_object *intern = NULL;
    zend_object *return_value = pango_font_description_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_description_clone_obj(zend_object *zobj)
{
    pango_font_description_object *new_font_description;
    pango_font_description_object *old_font_description = pango_font_description_fetch_object(zobj);
    zend_object *return_value = pango_font_description_obj_ctor(zobj->ce, &new_font_description);

    if (old_font_description->font_description) {
        new_font_description->font_description = pango_font_description_copy(old_font_description->font_description);
    }

    zend_objects_clone_members(&new_font_description->std, &old_font_description->std);

    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_description)
{
    memcpy(
        &pango_font_description_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_description_object_handlers.offset = offsetof(pango_font_description_object, std);
    pango_font_description_object_handlers.free_obj = pango_font_description_free_obj;
    pango_font_description_object_handlers.clone_obj = pango_font_description_clone_obj;

    pango_ce_pango_font_description = register_class_Pango_FontDescription();
    pango_ce_pango_font_description->create_object = pango_font_description_create_object;

    pango_ce_pango_style = register_class_Pango_Style();
    pango_ce_pango_weight = register_class_Pango_Weight();
    pango_ce_pango_variant = register_class_Pango_Variant();
    pango_ce_pango_stretch = register_class_Pango_Stretch();
    pango_ce_pango_font_mask = register_class_Pango_FontMask();
    pango_ce_pango_font_mask->ce_flags |= ZEND_ACC_EXPLICIT_ABSTRACT_CLASS | ZEND_ACC_FINAL;
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
    pango_ce_pango_font_color = register_class_Pango_FontColor();
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    pango_ce_pango_width = register_class_Pango_Width();
#endif

    return SUCCESS;
}
/* }}} */
