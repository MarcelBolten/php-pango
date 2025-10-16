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

#include "php.h"
#include "php_pango.h"

#include "zend_exceptions.h"
#include "font_description_arginfo.h"

zend_class_entry *pango_ce_pango_font_description;
zend_class_entry *pango_ce_pango_style;
zend_class_entry *pango_ce_pango_weight;
zend_class_entry *pango_ce_pango_variant;
zend_class_entry *pango_ce_pango_stretch;
zend_class_entry *pango_ce_pango_font_mask;

static zend_object_handlers pango_font_description_object_handlers;

pango_font_description_object *pango_font_description_fetch_object(zend_object *object)
{
    return (pango_font_description_object *) ((char*)(object) - XtOffsetOf(pango_font_description_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_description_ce()
{
    return pango_ce_pango_font_description;
}

/* {{{ Creates a new font description object. */
PHP_METHOD(Pango_FontDescription, __construct)
{
    pango_font_description_object *font_description_object = NULL;
    char *text = NULL;
    size_t text_len = 0;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());

    if (text && text_len > 0) {
        font_description_object->font_description = pango_font_description_from_string(text);
    } else {
        font_description_object->font_description = pango_font_description_new();
    }

    if (!font_description_object->font_description) {
        zend_throw_exception(
            pango_ce_pango_exception,
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
    pango_font_description_object *font_description_object;
    zend_object *variant_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());

    zend_enum_get_case_by_value(
        &variant_case, pango_ce_pango_variant,
        pango_font_description_get_variant(font_description_object->font_description),
        NULL, false
    );

    RETURN_OBJ_COPY(variant_case);
}
/* }}} */

/* {{{ Sets the variant of the layout. */
PHP_METHOD(Pango_FontDescription, setVariant)
{
    pango_font_description_object *font_description_object;
    zend_object *variant;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(variant, pango_ce_pango_variant)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    pango_font_description_set_variant(
        font_description_object->font_description,
        Z_LVAL_P(zend_enum_fetch_case_value(variant))
    );
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

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
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
    pango_font_description_object *font_description_object;
    char *family;
    size_t family_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(family, family_len)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    pango_font_description_set_family(font_description_object->font_description, family);
}
/* }}} */

/* {{{ Gets the family name field of a font description. */
PHP_METHOD(Pango_FontDescription, getFamily)
{
    pango_font_description_object *font_description_object;
    const char *family;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    if ((family = pango_font_description_get_family(font_description_object->font_description))) {
        RETURN_STRING((char *)family);
    }

    // return empty string if family is not set
    RETURN_EMPTY_STRING();
}
/* }}} */

/* {{{ Sets the size field of a font description. */
PHP_METHOD(Pango_FontDescription, setSize)
{
    pango_font_description_object *font_description_object;
    zend_long size;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(size)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    // Should size automatically be scaled by Pango::SCALE?
    pango_font_description_set_size(font_description_object->font_description, size);
}
/* }}} */

/* {{{ Gets the size field of a font description. */
PHP_METHOD(Pango_FontDescription, getSize)
{
    pango_font_description_object *font_description_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    RETURN_LONG(pango_font_description_get_size(font_description_object->font_description));
}
/* }}} */

/* {{{ Gets the style of the font description. */
PHP_METHOD(Pango_FontDescription, getStyle)
{
    pango_font_description_object *font_description_object;
    zend_object *style_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    zend_enum_get_case_by_value(
        &style_case, pango_ce_pango_style,
        pango_font_description_get_style(font_description_object->font_description),
        NULL, false
    );

    RETURN_OBJ_COPY(style_case);
}
/* }}} */

/* {{{ Sets the style of the layout. */
PHP_METHOD(Pango_FontDescription, setStyle)
{
    pango_font_description_object *font_description_object;
    zend_object *style;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(style, pango_ce_pango_style)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    pango_font_description_set_style(
        font_description_object->font_description,
        Z_LVAL_P(zend_enum_fetch_case_value(style))
    );
}
/* }}} */

/* {{{ Gets the weight of the font description. */
PHP_METHOD(Pango_FontDescription, getWeight)
{
    pango_font_description_object *font_description_object;
    zend_object *weight_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    zend_enum_get_case_by_value(
        &weight_case, pango_ce_pango_weight,
        pango_font_description_get_weight(font_description_object->font_description),
        NULL, false
    );

    RETURN_OBJ_COPY(weight_case);
}
/* }}} */

/* {{{ Sets the weight of the layout. */
PHP_METHOD(Pango_FontDescription, setWeight)
{
    pango_font_description_object *font_description_object;
    zend_object *weight;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(weight, pango_ce_pango_weight)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    pango_font_description_set_weight(
        font_description_object->font_description,
        Z_LVAL_P(zend_enum_fetch_case_value(weight))
    );
}
/* }}} */

/* {{{ Gets the stretch of the font description. */
PHP_METHOD(Pango_FontDescription, getStretch)
{
    pango_font_description_object *font_description_object;
    zend_object *stretch_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    zend_enum_get_case_by_value(
        &stretch_case, pango_ce_pango_stretch,
        pango_font_description_get_stretch(font_description_object->font_description),
        NULL, false
    );

    RETURN_OBJ_COPY(stretch_case);
}
/* }}} */

/* {{{ Sets the stretch of the layout. */
PHP_METHOD(Pango_FontDescription, setStretch)
{
    pango_font_description_object *font_description_object;
    zend_object *stretch;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(stretch, pango_ce_pango_stretch)
    ZEND_PARSE_PARAMETERS_END();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    pango_font_description_set_stretch(
        font_description_object->font_description,
        Z_LVAL_P(zend_enum_fetch_case_value(stretch))
    );
}
/* }}} */

/* {{{ Creates a string representation of a font description. */
PHP_METHOD(Pango_FontDescription, toString)
{
    pango_font_description_object *font_description_object;
    char *result;

    ZEND_PARSE_PARAMETERS_NONE();

    font_description_object = Z_PANGO_FONT_DESC_P(getThis());
    if (result = pango_font_description_to_string(font_description_object->font_description)) {
        RETVAL_STRING((const char *)result);
        g_free(result);
        return;
    }
    RETURN_EMPTY_STRING();
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

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_description)
{
    memcpy(
        &pango_font_description_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_description_object_handlers.offset = XtOffsetOf(pango_font_description_object, std);
    pango_font_description_object_handlers.free_obj = pango_font_description_free_obj;

    pango_ce_pango_font_description = register_class_Pango_FontDescription();
    pango_ce_pango_font_description->create_object = pango_font_description_create_object;

    pango_ce_pango_style = register_class_Pango_Style();
    pango_ce_pango_weight = register_class_Pango_Weight();
    pango_ce_pango_variant = register_class_Pango_Variant();
    pango_ce_pango_stretch = register_class_Pango_Stretch();
    pango_ce_pango_font_mask = register_class_Pango_FontMask();
    pango_ce_pango_font_mask->ce_flags |= ZEND_ACC_EXPLICIT_ABSTRACT_CLASS | ZEND_ACC_FINAL;

    return SUCCESS;
}
/* }}} */
