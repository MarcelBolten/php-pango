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
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "cairo/pango_cairo.h"
#include "php_pango_macros.h"
#include "coverage.h"
#include "language.h"
#include "rectangle.h"
#include "font_description.h"
#include "font_map.h"
#include "font_metrics.h"
#include "font_face.h"
#include "font.h"
#include "font_arginfo.h"

zend_class_entry *pango_ce_pango_font;

static zend_object_handlers pango_font_object_handlers;

pango_font_object *pango_font_fetch_object(zend_object *object)
{
    return (pango_font_object *) ((char*)(object) - offsetof(pango_font_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_ce()
{
    return pango_ce_pango_font;
}

PHP_PANGO_API PangoFont* pango_font_object_get_font(zval *zv)
{
    return Z_PANGO_FONT_P(zv)->font;
}

/* {{{ */
PHP_METHOD(Pango_Font, describe)
{
    PangoFont* font;
    pango_font_description_object *desc_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    object_init_ex(return_value, php_pango_get_font_description_ce());
    desc_obj = Z_PANGO_FONT_DESC_P(return_value);
    desc_obj->font_description = pango_font_describe(font);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, describeAbsolute)
{
    PangoFont* font;
    pango_font_description_object *desc_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    object_init_ex(return_value, php_pango_get_font_description_ce());
    desc_obj = Z_PANGO_FONT_DESC_P(return_value);
    desc_obj->font_description = pango_font_describe_with_absolute_size(font);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getCoverage)
{
    PangoFont* font;
    zval *language_zv;
    PangoLanguage* language;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    font = pango_font_object_get_font(ZEND_THIS);
    language = pango_language_object_get_language(language_zv);

    object_init_ex(return_value, php_pango_get_coverage_ce());
    pango_coverage_object *coverage_obj = Z_PANGO_COVERAGE_P(return_value);
    coverage_obj->coverage = pango_font_get_coverage(font, language);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getFace)
{
    PangoFont* font;
    pango_font_face_object *face_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    object_init_ex(return_value, php_pango_get_font_face_ce());
    face_obj = Z_PANGO_FONT_FACE_P(return_value);
    face_obj->font_face = pango_font_get_face(font);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getFeatures)
{
    #define NUM_FEATURES 32

    PangoFont* font;
    hb_feature_t features[NUM_FEATURES];
    guint num_features = 0;
    zval tmp_array_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    pango_font_get_features(font, features, NUM_FEATURES, &num_features);

    if (num_features == 0) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (int i = 0; i < num_features; i++) {
        array_init(&tmp_array_zv);
        add_assoc_long(&tmp_array_zv, "tag", features[i].tag);
        char tag_str[5];
        hb_tag_to_string(features[i].tag, tag_str);
        add_assoc_string(&tmp_array_zv, "tag-string", tag_str);
        add_assoc_long(&tmp_array_zv, "value", features[i].value);
        add_assoc_long(&tmp_array_zv, "start", features[i].start);
        add_assoc_long(&tmp_array_zv, "end", features[i].end);
        add_next_index_zval(return_value, &tmp_array_zv);
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getFontMap)
{
    PangoFont* font;
    pango_font_map_object *font_map_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    object_init_ex(return_value, php_pango_cairo_get_font_map_ce());
    font_map_obj = Z_PANGO_CAIRO_FONT_MAP_P(return_value);

    // The returned data is owned by the instance, so we don’t need to
    // g_object_ref() it. We also set is_default to true, so that the
    // destructor doesn’t unref it
    font_map_obj->font_map = pango_font_get_font_map(font);
    font_map_obj->is_default = true;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getGlyphExtents)
{
    PangoFont* font;
    PangoGlyph glyph;
    PangoRectangle ink_rect;
    PangoRectangle logical_rect;
    zval tmp_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);

    pango_font_get_glyph_extents(font, glyph, &ink_rect, &logical_rect);

    array_init(return_value);
    add_assoc_long(return_value, "glyph", glyph);

    object_init_ex(&tmp_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&tmp_zv) = ink_rect;
    add_assoc_zval(return_value, "ink", &tmp_zv);

    object_init_ex(&tmp_zv, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(&tmp_zv) = logical_rect;
    add_assoc_zval(return_value, "logical", &tmp_zv);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getLanguages)
{
    PangoFont* font;
    PangoLanguage** languages;
    zval tmp;
    pango_language_object *lang_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    font = pango_font_object_get_font(ZEND_THIS);
    languages = pango_font_get_languages(font);

    array_init(return_value);
    for (int i = 0; languages[i] != NULL; i++) {
        object_init_ex(&tmp, php_pango_get_language_ce());
        lang_obj = Z_PANGO_LANGUAGE_P(&tmp);
        lang_obj->language = languages[i];
        add_next_index_zval(return_value, &tmp);
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, getMetrics)
{
    PangoFont* font;
    zval *language_zv = NULL;
    pango_font_metrics_object *metrics_obj;
    PangoLanguage* lang = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    font = pango_font_object_get_font(ZEND_THIS);

    if (language_zv) {
        lang = pango_language_object_get_language(language_zv);
    }

    object_init_ex(return_value, php_pango_get_font_metrics_ce());
    metrics_obj = Z_PANGO_FONT_METRICS_P(return_value);
    metrics_obj->font_metrics = pango_font_get_metrics(font, lang);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Font, hasChar)
{
    zend_string *glyph;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(glyph)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(glyph)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    RETURN_BOOL(pango_font_has_char(
        pango_font_object_get_font(ZEND_THIS),
        g_utf8_get_char(ZSTR_VAL(glyph))
    ));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Font Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_free_obj(zend_object *zobj)
{
    pango_font_object *intern = pango_font_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font) {
        g_object_unref(intern->font);
        intern->font = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_obj_ctor(zend_class_entry *ce, pango_font_object **intern)
{
    pango_font_object *object = ecalloc(1, sizeof(pango_font_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_create_object(zend_class_entry *ce)
{
    pango_font_object *intern = NULL;
    zend_object *return_value = pango_font_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

static HashTable* pango_font_get_debug_info(zend_object *zobj, int *is_temp)
{
    pango_font_object *intern = pango_font_fetch_object(zobj);
    HashTable *debug_info = zend_std_get_properties(zobj);
    PangoFontDescription *font_desc = pango_font_describe(intern->font);
    zval font_str_zv;
    char *font_str = pango_font_description_to_string(font_desc);
    *is_temp = 0;

    ZVAL_STRING(&font_str_zv, font_str);
    g_free(font_str);
    pango_font_description_free(font_desc);

    zend_hash_str_update(debug_info, "string-representation", sizeof("string-representation") - 1, &font_str_zv);

    return debug_info;
}

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font)
{
    memcpy(
        &pango_font_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_object_handlers.offset = offsetof(pango_font_object, std);
    pango_font_object_handlers.free_obj = pango_font_free_obj;
    pango_font_object_handlers.get_debug_info = pango_font_get_debug_info;

    pango_ce_pango_font = register_class_Pango_Font();
    pango_ce_pango_font->create_object = pango_font_create_object;

    return SUCCESS;
}
/* }}} */
