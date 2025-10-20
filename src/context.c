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
#include "context_arginfo.h"

zend_class_entry *pango_ce_pango_context;
zend_class_entry *pango_ce_pango_direction;
zend_class_entry *pango_ce_pango_gravity;
zend_class_entry *pango_ce_pango_gravity_hint;

PHP_PANGO_API zend_class_entry* php_pango_get_context_ce() {
    return pango_ce_pango_context;
}

PHP_PANGO_API zend_class_entry* php_pango_get_direction_ce() {
    return pango_ce_pango_direction;
}

PHP_PANGO_API zend_class_entry* php_pango_get_gravity_ce() {
    return pango_ce_pango_gravity;
}

static zend_object_handlers pango_context_object_handlers;

pango_context_object *pango_context_fetch_object(zend_object *object)
{
    return (pango_context_object *) ((char*)(object) - XtOffsetOf(pango_context_object, std));
}

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

    context_object = Z_PANGO_CONTEXT_P(getThis());

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

    context_object = Z_PANGO_CONTEXT_P(getThis());

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
    PangoFontDescription *font_description = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_desc_zv, php_pango_get_font_description_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    zval_ptr_dtor(&context_object->font_description_zv);

    if (font_desc_zv && Z_TYPE_P(font_desc_zv) != IS_NULL) {
        ZVAL_COPY(&context_object->font_description_zv, font_desc_zv);
        font_description = Z_PANGO_FONT_DESC_P(font_desc_zv)->font_description;
    } else {
        ZVAL_NULL(&context_object->font_description_zv);
    }

    pango_context_set_font_description(context_object->context, font_description);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, getFontMap)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

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

//     ZEND_PARSE_PARAMETERS_START(0, 1);
//         Z_PARAM_OPTIONAL
//         Z_PARAM_OBJECT_OF_CLASS_OR_NULL(font_map_zv, php_pango_get_font_map_ce())
//     ZEND_PARSE_PARAMETERS_END();
// }
// /* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, listFamilies)
{
    pango_context_object *context_object;
    PangoFontFamily** families;
    int num_families;
    zval family_zv;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    pango_context_list_families(context_object->context, &families, &num_families);

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
    pango_context_object *context_object;
    zend_object *base_dir_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &base_dir_case, pango_ce_pango_direction,
        pango_context_get_base_dir(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(base_dir_case);
}
/* }}} */

/* {{{ Gets the base gravity to be used to lay out the text. */
PHP_METHOD(Pango_Context, getBaseGravity)
{
    pango_context_object *context_object;
    zend_object *base_gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &base_gravity_case, pango_ce_pango_gravity,
        pango_context_get_base_gravity(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(base_gravity_case);
}
/* }}} */

/* {{{ Gets the gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravity)
{
    pango_context_object *context_object;
    zend_object *gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &gravity_case, pango_ce_pango_gravity,
        pango_context_get_gravity(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_case);
}
/* }}} */

/* {{{ Gets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravityHint)
{
    pango_context_object *context_object;
    zend_object *gravity_hint_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &gravity_hint_case, pango_ce_pango_gravity_hint,
        pango_context_get_gravity_hint(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_hint_case);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, getMatrix)
{
    pango_context_object *context_object;
    const PangoMatrix *matrix_pango;
    PangoMatrix *matrix_php;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    matrix_pango = pango_context_get_matrix(context_object->context);

    // start with a new identity matrix
    object_init_ex(return_value, php_pango_get_matrix_ce());

    // if the context has a matrix set, copy its values to the php matrix object
    if (matrix_pango != NULL) {
        // TODO: check if a copy is wanted here, perhaps just assign the pointer?
        // but the returned matrix is const so probably a copy is better
        matrix_php = pango_matrix_object_get_matrix(return_value);
        *matrix_php = *matrix_pango;
    }
}
/* }}} */

/* {{{ Returns whether font rendering with this context should round glyph positions and widths. */
PHP_METHOD(Pango_Context, getRoundGlyphPositions)
{
    pango_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    RETURN_BOOL(pango_context_get_round_glyph_positions(context_object->context));
}
/* }}} */

/* {{{ Sets the base direction for the context. */
PHP_METHOD(Pango_Context, setBaseDir)
{
    pango_context_object *context_object;
    zend_object *base_dir;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(base_dir, pango_ce_pango_direction)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_base_dir(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(base_dir))
    );
}
/* }}} */

/* {{{ Sets the base gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, setBaseGravity)
{
    pango_context_object *context_object;
    zend_object *base_gravity;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(base_gravity, pango_ce_pango_gravity)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_base_gravity(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(base_gravity))
    );
}
/* }}} */

/* {{{ Sets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, setGravityHint)
{
    pango_context_object *context_object;
    zend_object *gravity_hint;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(gravity_hint, pango_ce_pango_gravity_hint)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_gravity_hint(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(gravity_hint))
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Context, setMatrix)
{
    pango_context_object *context_object;
    zval *matrix_zval;
    PangoMatrix *matrix;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS_OR_NULL(matrix_zval, php_pango_get_matrix_ce())
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    matrix = pango_matrix_object_get_matrix(matrix_zval);

    pango_context_set_matrix(context_object->context, matrix);
}
/* }}} */

/* {{{ Sets the round glyph positions for the context. */
PHP_METHOD(Pango_Context, setRoundGlyphPositions)
{
    pango_context_object *context_object;
    bool round;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(round)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_round_glyph_positions(context_object->context, round);
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

    pango_context_object_handlers.offset = XtOffsetOf(pango_context_object, std);
    pango_context_object_handlers.free_obj = pango_context_free_obj;

    pango_ce_pango_context = register_class_Pango_Context();
    pango_ce_pango_context->create_object = pango_context_create_object;

    pango_ce_pango_gravity = register_class_Pango_Gravity();
    pango_ce_pango_gravity_hint = register_class_Pango_GravityHint();
    pango_ce_pango_direction = register_class_Pango_Direction();

    return SUCCESS;
}
/* }}} */
