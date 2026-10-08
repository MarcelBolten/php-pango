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

#include "../php_pango.h"
#include "attribute/attribute.h"
#include "font.h"
#include "font_set.h"
#include "font_description.h"
#include "font_family.h"
#include "font_map.h"
#include "font_metrics.h"
#include "item.h"
#include "language.h"
#include "matrix.h"
#include "context.h"
#include "context_arginfo.h"

zend_class_entry *pango_ce_pango_context;
zend_class_entry *pango_ce_pango_direction;
zend_class_entry *pango_ce_pango_gravity;
zend_class_entry *pango_ce_pango_gravity_hint;

PHP_PANGO_API zend_class_entry* php_pango_get_context_ce(void) {
    return pango_ce_pango_context;
}

PHP_PANGO_API zend_class_entry* php_pango_get_direction_ce(void) {
    return pango_ce_pango_direction;
}

PHP_PANGO_API zend_class_entry* php_pango_get_gravity_ce(void) {
    return pango_ce_pango_gravity;
}

PHP_PANGO_API zend_class_entry* php_pango_get_gravity_hint_ce(void) {
    return pango_ce_pango_gravity_hint;
}

static zend_object_handlers pango_context_object_handlers;

pango_context_object *pango_context_fetch_object(zend_object *object)
{
    return (pango_context_object *) ((char*)(object) - offsetof(pango_context_object, std));
}

/* {{{ */
PHP_PANGO_API PangoContext *pango_context_object_get_context(zval *zv)
{
    return (PangoContext *) Z_PANGO_CONTEXT_P(zv)->context;
}
/* }}} */

/* {{{ Creates a new PangoContext initialized to default values. */
PHP_METHOD(Pango_Context, __construct)
{
    pango_context_object *context_object;
    zval *font_map_zv = NULL;
    pango_font_map_object *font_map_object;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_map_zv, php_pango_get_font_map_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(ZEND_THIS);

    if (font_map_zv && Z_TYPE_P(font_map_zv) != IS_NULL) {
        font_map_object = Z_PANGO_FONT_MAP_P(font_map_zv);
        context_object->context = pango_font_map_create_context(font_map_object->font_map);

        // keep a reference of the font map zval in the pango context object
        ZVAL_COPY(&context_object->font_map_zv, font_map_zv);
        return;
    }

    context_object->context = pango_context_new();
}

/* {{{ */
PHP_METHOD(Pango_Context, getFontDescription)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(ZEND_THIS);

    if (Z_TYPE(context_object->font_description_zv) != IS_UNDEF) {
        RETURN_COPY(&context_object->font_description_zv);
    }

    RETURN_NULL();
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, setFontDescription)
{
    zval *font_desc_zv;
    pango_context_object *context_object;
    PangoFontDescription *font_description;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(ZEND_THIS);
    zval_ptr_dtor(&context_object->font_description_zv);

    ZVAL_COPY(&context_object->font_description_zv, font_desc_zv);
    font_description = Z_PANGO_FONT_DESC_P(font_desc_zv)->font_description;

    pango_context_set_font_description(context_object->context, font_description);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, getFontMap)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(ZEND_THIS);

    if (Z_TYPE(context_object->font_map_zv) != IS_UNDEF) {
        RETURN_COPY(&context_object->font_map_zv);
    }

    RETURN_NULL();
}
/* }}} */

// /* {{{ Sets the font map to be searched when fonts are looked-up in this context.
//        This is only for internal use by Pango backends, a PangoContext obtained
//        via one of the recommended methods should already have a suitable font map. */
// PHP_METHOD(Pango_Context, setFontMap)
// {
//     zval *font_map_zv = NULL;

//     ZEND_PARSE_PARAMETERS_START(0, 1)
//         Z_PARAM_OPTIONAL
//         Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_map_zv, php_pango_get_font_map_ce())
//     ZEND_PARSE_PARAMETERS_END();
//
//     RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
// }
// /* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, listFamilies)
{
    PangoFontFamily** families;
    int num_families;
    zval family_zv;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_context_list_families(Z_PANGO_CONTEXT_P(ZEND_THIS)->context, &families, &num_families);

    array_init(return_value);
    for (int i = 0; i < num_families; i++) {
        object_init_ex(&family_zv, php_pango_get_font_family_ce());
        font_family_object = Z_PANGO_FONT_FAMILY_P(&family_zv);
        font_family_object->font_family = g_object_ref(families[i]);
        add_next_index_zval(return_value, &family_zv);
    }

    g_free(families);
}
/* }}} */

/* {{{ Retrieves the base direction for the context. */
PHP_METHOD(Pango_Context, getBaseDir)
{
    zend_object *base_dir_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &base_dir_case, pango_ce_pango_direction,
        pango_context_get_base_dir(Z_PANGO_CONTEXT_P(ZEND_THIS)->context),
        NULL, false
    );

    RETURN_OBJ_COPY(base_dir_case);
}
/* }}} */

/* {{{ Gets the base gravity to be used to lay out the text. */
PHP_METHOD(Pango_Context, getBaseGravity)
{
    zend_object *base_gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &base_gravity_case, pango_ce_pango_gravity,
        pango_context_get_base_gravity(Z_PANGO_CONTEXT_P(ZEND_THIS)->context),
        NULL, false
    );

    RETURN_OBJ_COPY(base_gravity_case);
}
/* }}} */

/* {{{ Gets the gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravity)
{
    zend_object *gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &gravity_case, pango_ce_pango_gravity,
        pango_context_get_gravity(Z_PANGO_CONTEXT_P(ZEND_THIS)->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_case);
}
/* }}} */

/* {{{ Gets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravityHint)
{
    zend_object *gravity_hint_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &gravity_hint_case, pango_ce_pango_gravity_hint,
        pango_context_get_gravity_hint(Z_PANGO_CONTEXT_P(ZEND_THIS)->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_hint_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, getMatrix)
{
    const PangoMatrix *matrix_pango;
    PangoMatrix *matrix_php;

    ZEND_PARSE_PARAMETERS_NONE();

    matrix_pango = pango_context_get_matrix(Z_PANGO_CONTEXT_P(ZEND_THIS)->context);

    // start with a new identity matrix
    object_init_ex(return_value, php_pango_get_matrix_ce());

    // if the context has a matrix set, copy its values to the php matrix object
    if (matrix_pango != NULL) {
        matrix_php = pango_matrix_object_get_matrix(return_value);
        *matrix_php = *matrix_pango;
    }
}
/* }}} */

/* {{{ Returns whether font rendering with this context should round glyph positions and widths. */
PHP_METHOD(Pango_Context, getRoundGlyphPositions)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_context_get_round_glyph_positions(Z_PANGO_CONTEXT_P(ZEND_THIS)->context));
}
/* }}} */

/* {{{ Sets the base direction for the context. */
PHP_METHOD(Pango_Context, setBaseDir)
{
    zend_object *base_dir;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(base_dir, pango_ce_pango_direction)
    ZEND_PARSE_PARAMETERS_END();

    pango_context_set_base_dir(
        Z_PANGO_CONTEXT_P(ZEND_THIS)->context,
        Z_LVAL_P(zend_enum_fetch_case_value(base_dir))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the base gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, setBaseGravity)
{
    zend_object *base_gravity;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(base_gravity, pango_ce_pango_gravity)
    ZEND_PARSE_PARAMETERS_END();

    pango_context_set_base_gravity(
        Z_PANGO_CONTEXT_P(ZEND_THIS)->context,
        Z_LVAL_P(zend_enum_fetch_case_value(base_gravity))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, setGravityHint)
{
    zend_object *gravity_hint;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(gravity_hint, pango_ce_pango_gravity_hint)
    ZEND_PARSE_PARAMETERS_END();

    pango_context_set_gravity_hint(
        Z_PANGO_CONTEXT_P(ZEND_THIS)->context,
        Z_LVAL_P(zend_enum_fetch_case_value(gravity_hint))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, setMatrix)
{
    zval *matrix_zval;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(matrix_zval, php_pango_get_matrix_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_context_set_matrix(
        Z_PANGO_CONTEXT_P(ZEND_THIS)->context,
        pango_matrix_object_get_matrix(matrix_zval)
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the round glyph positions for the context. */
PHP_METHOD(Pango_Context, setRoundGlyphPositions)
{
    bool round;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(round)
    ZEND_PARSE_PARAMETERS_END();

    pango_context_set_round_glyph_positions(Z_PANGO_CONTEXT_P(ZEND_THIS)->context, round);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Sets the global language tag for the context. */
PHP_METHOD(Pango_Context, setLanguage)
{
    zval *language_zv = NULL;
    PangoLanguage *language = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (language_zv) {
        language = pango_language_object_get_language(language_zv);
    }

    pango_context_set_language(Z_PANGO_CONTEXT_P(ZEND_THIS)->context, language);

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{ Retrieves the global language tag for the context. */
PHP_METHOD(Pango_Context, getLanguage)
{
    PangoLanguage *language;
    pango_language_object *language_obj;

    ZEND_PARSE_PARAMETERS_NONE();

    language = pango_context_get_language(Z_PANGO_CONTEXT_P(ZEND_THIS)->context);

    if (!language) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_language_ce());
    language_obj = Z_PANGO_LANGUAGE_P(return_value);
    language_obj->language = language;
}
/* }}} */

/* {{{ Returns the current serial number of context */
PHP_METHOD(Pango_Context, getSerial)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_context_get_serial(Z_PANGO_CONTEXT_P(ZEND_THIS)->context));
}
/* }}} */

/* {{{ Get overall metric information for a particular font description. */
PHP_METHOD(Pango_Context, getMetrics)
{
    zval *font_desc_zv = NULL;
    zval *language_zv = NULL;
    PangoFontDescription* desc = NULL;
    PangoLanguage* language = NULL;
    pango_font_metrics_object *metrics_obj;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_desc_zv, php_pango_get_font_description_ce())
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (font_desc_zv) {
        desc = pango_font_description_object_get_font_description(font_desc_zv);
    }
    if (language_zv) {
        language = pango_language_object_get_language(language_zv);
    }

    object_init_ex(return_value, php_pango_get_font_metrics_ce());
    metrics_obj = Z_PANGO_FONT_METRICS_P(return_value);
    metrics_obj->font_metrics = pango_context_get_metrics(
        Z_PANGO_CONTEXT_P(ZEND_THIS)->context,
        desc,
        language
    );
}
/* }}} */

/* {{{ Loads the font in one of the fontmaps in the context that is the closest match for desc. */
PHP_METHOD(Pango_Context, loadFont)
{
    PangoContext *context;
    zval *font_desc_zv;
    PangoFontDescription* desc;
    pango_font_object *font_obj;
    PangoFont *font;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    context = pango_context_object_get_context(ZEND_THIS);
    desc = pango_font_description_object_get_font_description(font_desc_zv);
    font = pango_context_load_font(
        context,
        desc
    );

    if (!font) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_ce());
    font_obj = Z_PANGO_FONT_P(return_value);
    font_obj->font = font;
}
/* }}} */

/* {{{ Loads a set of fonts in the context that can be used to render a font matching desc. */
PHP_METHOD(Pango_Context, loadFontSet)
{
    PangoContext *context;
    zval *font_desc_zv;
    PangoFontDescription* desc;
    zval *language_zv;
    PangoLanguage* language;
    pango_font_set_object *font_set_obj;
    PangoFontset *font_set;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(font_desc_zv, php_pango_get_font_description_ce())
        Z_PARAM_OBJECT_OF_CLASS(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    context = pango_context_object_get_context(ZEND_THIS);
    desc = pango_font_description_object_get_font_description(font_desc_zv);
    language = pango_language_object_get_language(language_zv);
    font_set = pango_context_load_fontset(
        context,
        desc,
        language
    );

    if (!font_set) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_set_ce());
    font_set_obj = Z_PANGO_FONT_SET_P(return_value);
    font_set_obj->font_set = font_set;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, itemize)
{
    zend_string *text;
    zend_long start_byte_index;
    zend_long byte_length;
    zval *attr_list_zv;
    PangoAttrList *attr_list;
    PangoContext *context;
    zval *cached_iter_zv = NULL;
    zval *direction_zv = NULL;
    GList *items;
    PangoAttrIterator *cached_iter = NULL;
    zval item_zv;

    ZEND_PARSE_PARAMETERS_START(4, 6)
        Z_PARAM_STR(text)
        Z_PARAM_LONG(start_byte_index)
        Z_PARAM_LONG(byte_length)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, php_pango_get_attr_list_ce())
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cached_iter_zv, php_pango_get_attr_iter_ce())
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(direction_zv, php_pango_get_direction_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }
    if (start_byte_index < 0 || start_byte_index > ZSTR_LEN(text)) {
        zend_argument_value_error(2, "must be between 0 and the byte length of text (%zu)", ZSTR_LEN(text));
        RETURN_THROWS();
    }
    if (byte_length < 0 || start_byte_index + byte_length > ZSTR_LEN(text)) {
        zend_argument_value_error(3,
            "must be between 0 and the byte length of text minus startByteIndex (%ld)",
            ZSTR_LEN(text) - start_byte_index
        );
        RETURN_THROWS();
    }

    attr_list = Z_PANGO_ATTR_LIST_P(attr_list_zv)->attr_list;
    context = pango_context_object_get_context(ZEND_THIS);
    if (cached_iter_zv != NULL) {
        cached_iter = Z_PANGO_ATTR_ITER_P(cached_iter_zv)->attr_iter;
    }

    if (direction_zv) {
        items = pango_itemize_with_base_dir(
            context,
            Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(direction_zv))),
            ZSTR_VAL(text), start_byte_index, byte_length,
            attr_list, cached_iter
        );
    } else {
        items = pango_itemize(
            context,
            ZSTR_VAL(text), start_byte_index, byte_length,
            attr_list, cached_iter
        );
    }

    array_init(return_value);
    for (GList *item = items; item != NULL; item = item->next) {
        object_init_ex(&item_zv, php_pango_get_item_ce());
        Z_PANGO_ITEM_P(&item_zv)->item = pango_item_copy((PangoItem *) item->data);
        add_next_index_zval(return_value, &item_zv);
    }
    g_list_free_full(items, (GDestroyNotify) pango_item_free);
}
/* }}} */

// /* {{{ */
// PHP_METHOD(Pango_Direction, findBaseDir)
// {
//     zend_string *text;
//     size_t text_len;
//     PangoDirection base_dir;
//     zend_object *base_dir_case;

//     ZEND_PARSE_PARAMETERS_START(1, 1)
//         Z_PARAM_STR(text)
//     ZEND_PARSE_PARAMETERS_END();

//     if (zend_str_has_nul_byte(text)) {
//         zend_argument_value_error(1, "must not contain NUL bytes");
//         RETURN_THROWS();
//     }

//     base_dir = pango_find_base_dir(ZSTR_VAL(text), ZSTR_LEN(text));

//     zend_enum_get_case_by_value(
//         &base_dir_case, pango_ce_pango_direction,
//         base_dir,
//         NULL, false
//     );

//     RETURN_OBJ_COPY(base_dir_case);
// }
// /* }}} */

/* {{{ */
PHP_METHOD(Pango_Gravity, toRotation)
{
    PangoGravity gravity;

    ZEND_PARSE_PARAMETERS_NONE();

    gravity = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(ZEND_THIS)));

    // PANGO_GRAVITY_AUTO will result in a Pango-CRITICAL: assertion 'gravity != PANGO_GRAVITY_AUTO' failed
    // so we explicitly check for it and throw a ValueError
    if (gravity == PANGO_GRAVITY_AUTO) {
        zend_value_error("Pango\\Gravity::Auto cannot be converted to a rotation");
        RETURN_THROWS();
    }

    RETURN_DOUBLE(pango_gravity_to_rotation(gravity));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Context Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_context_free_obj(zend_object *zobj)
{
    pango_context_object *intern = pango_context_fetch_object(zobj);

    if (!intern) {
        return;
    }

    zval_ptr_dtor(&intern->font_map_zv);
    zval_ptr_dtor(&intern->font_options_zv);
    zval_ptr_dtor(&intern->font_description_zv);
    zval_ptr_dtor(&intern->cairo_context_zv);

    if (intern->context) {
        g_object_unref(intern->context);
    }

    zend_object_std_dtor(&intern->std);
}

/* {{{ */
static zend_object* pango_context_obj_ctor(zend_class_entry *ce, pango_context_object **intern)
{
    pango_context_object *object = ecalloc(1, sizeof(pango_context_object) + zend_object_properties_size(ce));

    object->context = NULL;

    ZVAL_UNDEF(&object->cairo_context_zv);
    ZVAL_UNDEF(&object->font_map_zv);
    ZVAL_UNDEF(&object->font_options_zv);
    ZVAL_UNDEF(&object->font_description_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_context_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_context_create_object(zend_class_entry *ce)
{
    pango_context_object *intern = NULL;
    zend_object *return_value = pango_context_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_context)
{
    memcpy(
        &pango_context_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_context_object_handlers.offset = offsetof(pango_context_object, std);
    pango_context_object_handlers.free_obj = pango_context_free_obj;

    pango_ce_pango_context = register_class_Pango_Context();
    pango_ce_pango_context->create_object = pango_context_create_object;

    pango_ce_pango_gravity = register_class_Pango_Gravity();
    pango_ce_pango_gravity_hint = register_class_Pango_GravityHint();
    pango_ce_pango_direction = register_class_Pango_Direction();

    return SUCCESS;
}
/* }}} */
