/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2026 Marcel Bolten                                     |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  +----------------------------------------------------------------------+
  | Authors: Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "Zend/zend_enum.h"
#include "Zend/zend_exceptions.h"

#include "../php_pango.h"
#include "php_pango_macros.h"
#include "tabstops.h"
#include "tabstops_arginfo.h"

zend_class_entry *ce_pango_tabstops;

static zend_object_handlers pango_tabstops_object_handlers;

pango_tabstops_object *pango_tabstops_fetch_object(zend_object *object)
{
    return (pango_tabstops_object *) ((char*)(object) - offsetof(pango_tabstops_object, std));
}

/* ----------------------------------------------------------------
    \Pango\TabStops C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoTabArray *pango_tabstops_object_get_tab_array(zval *zv)
{
    return Z_PANGO_TABSTOPS_P(zv)->tab_array;
}
/* }}} */

zend_class_entry* php_pango_get_tabstops_ce(void)
{
    return ce_pango_tabstops;
}

static zend_always_inline zend_result php_pango_tabstops_check_index(PangoTabArray *tab_array, gint index, zval *return_value)
{
    gint size = pango_tab_array_get_size(tab_array);
    if (UNEXPECTED(index < 0 || index >= size)) {
        zend_argument_value_error(1, "must be between 0 and size - 1 (%d) but %d was given", size - 1, index);
        return FAILURE;
    }
    return SUCCESS;
}

static zend_result php_pango_tabstops_set_tab(PangoTabArray *tab_array, gint index, zval *tabstop, zval *return_value, int tabstop_param_index, bool sort)
{
    zend_object *tabstop_obj;
    gboolean in_pixels;
    zval *alignment_zv;
    PangoTabAlign alignment;
    zval *location_zv;
    gint location;
    zval *decimalChar_zv;

    in_pixels = pango_tab_array_get_positions_in_pixels(tab_array);
    tabstop_obj = Z_OBJ_P(tabstop);

    if (UNEXPECTED(tabstop_obj->ce == php_pango_get_tabstop_pixel_ce() && !in_pixels
        || tabstop_obj->ce == php_pango_get_tabstop_ce() && in_pixels)
    ) {
        zend_argument_value_error(tabstop_param_index, "must be of type %s for this TabStops instance, but %s was given",
            ZSTR_VAL(in_pixels ? php_pango_get_tabstop_pixel_ce()->name : php_pango_get_tabstop_ce()->name),
            ZSTR_VAL(tabstop_obj->ce->name)
        );
        return FAILURE;
    }

    location_zv = zend_read_property(
        php_pango_get_tabstop_ce(), tabstop_obj,
        "position", sizeof("position") - 1,
        true,
        NULL
    );
    location = Z_LVAL_P(location_zv);

    alignment_zv = zend_read_property(
        php_pango_get_tabstop_ce(), tabstop_obj,
        "alignment", sizeof("alignment") - 1,
        true,
        NULL
    );
    alignment = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(alignment_zv)));

    pango_tab_array_set_tab(tab_array, index, alignment, location);

    if (alignment == PANGO_TAB_DECIMAL) {
        decimalChar_zv = zend_read_property(
            php_pango_get_tabstop_ce(), tabstop_obj,
            "decimalChar", sizeof("decimalChar") - 1,
            true,
            NULL
        );
        pango_tab_array_set_decimal_point(tab_array, index, g_utf8_get_char(Z_STRVAL_P(decimalChar_zv)));
    }

    if (sort) {
        pango_tab_array_sort(tab_array);
    }

    return SUCCESS;
}

/* ----------------------------------------------------------------
    \Pango\TabStops Class API
------------------------------------------------------------------*/

/* {{{  */
PHP_METHOD(Pango_TabStops, __construct)
{
    zval *tabstops_array;
    int tabstops_array_size;
    pango_tabstops_object *tabstops_object;
    zval *tabstop;
    int tabstop_index = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(tabstops_array)
    ZEND_PARSE_PARAMETERS_END();

    tabstops_array_size = zend_hash_num_elements(Z_ARRVAL_P(tabstops_array));

    tabstops_object = Z_PANGO_TABSTOPS_P(ZEND_THIS);

    tabstops_object->tab_array = pango_tab_array_new(tabstops_array_size, false);

    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(tabstops_array), tabstop) {
        if (Z_TYPE_P(tabstop) != IS_OBJECT
            || !instanceof_function(Z_OBJCE_P(tabstop), php_pango_get_tabstop_ce())
        ) {
            zend_argument_type_error(1, "must be an array of Pango\\TabStop objects");
            RETURN_THROWS();
        }

        if (tabstop_index == 0
            && Z_OBJ_P(tabstop)->ce == php_pango_get_tabstop_pixel_ce()
        ) {
            pango_tab_array_set_positions_in_pixels(
                tabstops_object->tab_array,
                true
            );
        }

        if (php_pango_tabstops_set_tab(tabstops_object->tab_array, tabstop_index, tabstop, return_value, 1, false) == FAILURE) {
            RETURN_THROWS();
        }
        tabstop_index++;
    } ZEND_HASH_FOREACH_END();

    pango_tab_array_sort(tabstops_object->tab_array);
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, __toString)
{
    PangoTabArray *tab_array;
    char* str;

    ZEND_PARSE_PARAMETERS_NONE();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);

    RETURN_STRING(pango_tab_array_to_string(tab_array));
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, fromString)
{
    zend_string *string;
    pango_tabstops_object *tabstops_obj;
    PangoTabArray *tab_array;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(string)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    tab_array = pango_tab_array_from_string(ZSTR_VAL(string));
    if (!tab_array) {
        zend_argument_value_error(1, "must be a valid Pango tab array string, but \"%s\" was given", ZSTR_VAL(string));
        RETURN_THROWS();
    }

    object_init_ex(return_value, ce_pango_tabstops);
    tabstops_obj = Z_PANGO_TABSTOPS_P(return_value);
    tabstops_obj->tab_array = tab_array;
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, add)
{
    zval *tabstop;
    PangoTabArray *tab_array;
    gint size;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(tabstop, php_pango_get_tabstop_ce())
    ZEND_PARSE_PARAMETERS_END();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);
    size = pango_tab_array_get_size(tab_array);
    pango_tab_array_resize(tab_array, size + 1);

    if (php_pango_tabstops_set_tab(tab_array, size, tabstop, return_value, 1, true) == FAILURE) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, remove)
{
    zend_long index;
    pango_tabstops_object *tabstops_obj;
    PangoTabArray *tab_array;
    gint size;
    PangoTabArray *new_tab_array;
    PangoTabAlign *alignments;
    gint *locations;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    tabstops_obj = Z_PANGO_TABSTOPS_P(ZEND_THIS);
    tab_array = tabstops_obj->tab_array;

    if (php_pango_tabstops_check_index(tab_array, index, return_value) == FAILURE) {
        RETURN_THROWS();
    }

    size = pango_tab_array_get_size(tab_array);
    new_tab_array = pango_tab_array_new(
        size - 1,
        pango_tab_array_get_positions_in_pixels(tab_array)
    );

    pango_tab_array_get_tabs(tab_array, &alignments, &locations);

    for (int i = 0; i < size; i++) {
        if (i == index) {
            continue;
        }

        int new_index = i < index ? i : i - 1;
        pango_tab_array_set_tab(
            new_tab_array, new_index, alignments[i], locations[i]
        );

        if (alignments[i] == PANGO_TAB_DECIMAL) {
            pango_tab_array_set_decimal_point(
                new_tab_array, new_index,
                pango_tab_array_get_decimal_point(tab_array, i)
            );
        }
    }

    pango_tab_array_free(tab_array);
    tabstops_obj->tab_array = new_tab_array;
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, set)
{
    zend_long index;
    zval *tabstop;
    PangoTabArray *tab_array;
    gint size;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_OBJECT_OF_CLASS(tabstop, php_pango_get_tabstop_ce())
    ZEND_PARSE_PARAMETERS_END();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);
    size = pango_tab_array_get_size(tab_array);
    if (php_pango_tabstops_check_index(tab_array, index, return_value) == FAILURE) {
        RETURN_THROWS();
    }

    if (php_pango_tabstops_set_tab(tab_array, index, tabstop, return_value, 2, true) == FAILURE) {
        RETURN_THROWS();
    }

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, getTab)
{
    zend_long index;
    PangoTabArray *tab_array;
    gint size;
    gboolean in_pixels;
    zend_class_entry *ce;
    PangoTabAlign alignment;
    gint location;
    zend_object *align_obj;
    zval align_zv;
    gunichar decimal_point;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);
    size = pango_tab_array_get_size(tab_array);

    if (size == 0) {
        RETURN_NULL();
    }

    if (php_pango_tabstops_check_index(tab_array, index, return_value) == FAILURE) {
        RETURN_THROWS();
    }

    in_pixels = pango_tab_array_get_positions_in_pixels(tab_array);
    ce = in_pixels
        ? php_pango_get_tabstop_pixel_ce()
        : php_pango_get_tabstop_ce();

    pango_tab_array_get_tab(
        tab_array,
        index,
        &alignment,
        &location
    );

    object_init_ex(return_value, ce);

    // position
    zend_update_property_long(
        php_pango_get_tabstop_ce(), Z_OBJ_P(return_value),
        "position", sizeof("position") - 1,
        location
    );

    // alignment
    zend_enum_get_case_by_value(
        &align_obj, php_pango_get_tab_align_ce(),
        alignment,
        NULL, false
    );
    ZVAL_OBJ(&align_zv, align_obj);
    zend_update_property(
        php_pango_get_tabstop_ce(), Z_OBJ_P(return_value),
        "alignment", sizeof("alignment") - 1,
        &align_zv
    );

    // decimalChar
    if (alignment == PANGO_TAB_DECIMAL) {
        decimal_point = pango_tab_array_get_decimal_point(tab_array, index);

        char decimal_point_str[5] = {0};
        g_unichar_to_utf8(decimal_point, decimal_point_str);

        zend_update_property_string(
            php_pango_get_tabstop_ce(), Z_OBJ_P(return_value),
            "decimalChar", sizeof("decimalChar") - 1,
            decimal_point_str
        );
    } else {
        zend_update_property_null(
            php_pango_get_tabstop_ce(), Z_OBJ_P(return_value),
            "decimalChar", sizeof("decimalChar") - 1
        );
    }
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, getTabs)
{
    PangoTabArray *tab_array;
    int size;
    gboolean in_pixels;
    PangoTabAlign *alignments;
    gint *locations;
    zend_class_entry *ce;
    zval tabstop_zv;
    zend_object *tabstop_obj;
    zend_object *align_obj;
    zval align_zv;
    gunichar decimal_point;

    ZEND_PARSE_PARAMETERS_NONE();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);

    size = pango_tab_array_get_size(tab_array);

    if (size == 0) {
        RETURN_EMPTY_ARRAY();
    }

    in_pixels = pango_tab_array_get_positions_in_pixels(tab_array);
    ce = in_pixels
        ? php_pango_get_tabstop_pixel_ce()
        : php_pango_get_tabstop_ce();

    pango_tab_array_get_tabs(
        tab_array,
        &alignments,
        &locations
    );

    array_init(return_value);
    for (int i = 0; i < size; i++) {
        object_init_ex(&tabstop_zv, ce);

        // position
        zend_update_property_long(
            php_pango_get_tabstop_ce(), Z_OBJ_P(&tabstop_zv),
            "position", sizeof("position") - 1,
            locations[i]
        );

        // alignment
        zend_enum_get_case_by_value(
            &align_obj, php_pango_get_tab_align_ce(),
            alignments[i],
            NULL, false
        );
        ZVAL_OBJ(&align_zv, align_obj);
        zend_update_property(
            php_pango_get_tabstop_ce(), Z_OBJ_P(&tabstop_zv),
            "alignment", sizeof("alignment") - 1,
            &align_zv
        );

        // decimalChar
        if (alignments[i] == PANGO_TAB_DECIMAL) {
            decimal_point = pango_tab_array_get_decimal_point(tab_array, i);

            char decimal_point_str[5] = {0};
            g_unichar_to_utf8(decimal_point, decimal_point_str);

            zend_update_property_string(
                php_pango_get_tabstop_ce(), Z_OBJ_P(&tabstop_zv),
                "decimalChar", sizeof("decimalChar") - 1,
                decimal_point_str
            );
        } else {
            zend_update_property_null(
                php_pango_get_tabstop_ce(), Z_OBJ_P(&tabstop_zv),
                "decimalChar", sizeof("decimalChar") - 1
            );
        }

        add_next_index_zval(return_value, &tabstop_zv);
    }
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, getSize)
{
    PangoTabArray *tab_array;

    ZEND_PARSE_PARAMETERS_NONE();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);

    RETURN_LONG(pango_tab_array_get_size(tab_array));
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_TabStops, arePositionsInPixels)
{
    PangoTabArray *tab_array;

    ZEND_PARSE_PARAMETERS_NONE();

    tab_array = pango_tabstops_object_get_tab_array(ZEND_THIS);

    RETURN_BOOL(pango_tab_array_get_positions_in_pixels(tab_array));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\TabStops Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_tabstops_free_obj(zend_object *object)
{
    pango_tabstops_object *intern = pango_tabstops_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->tab_array) {
        pango_tab_array_free(intern->tab_array);
        intern->tab_array = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstops_obj_ctor(zend_class_entry *ce, pango_tabstops_object **intern)
{
    pango_tabstops_object *object = ecalloc(1, sizeof(pango_tabstops_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_tabstops_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstops_create_object(zend_class_entry *ce)
{
    pango_tabstops_object *intern = NULL;
    zend_object *return_value = pango_tabstops_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstops_clone_obj(zend_object *zobj)
{
    pango_tabstops_object *new_tabstops;
    pango_tabstops_object *old_tabstops = pango_tabstops_fetch_object(zobj);
    zend_object *return_value = pango_tabstops_obj_ctor(zobj->ce, &new_tabstops);

    new_tabstops->tab_array = pango_tab_array_copy(old_tabstops->tab_array);

    zend_objects_clone_members(&new_tabstops->std, &old_tabstops->std);

    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\TabStops Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_tabstops)
{
    memcpy(
        &pango_tabstops_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_tabstops_object_handlers.offset = offsetof(pango_tabstops_object, std);
    pango_tabstops_object_handlers.free_obj = pango_tabstops_free_obj;
    pango_tabstops_object_handlers.clone_obj = pango_tabstops_clone_obj;
    pango_tabstops_object_handlers.get_property_ptr_ptr = NULL;

    ce_pango_tabstops = register_class_Pango_TabStops();
    ce_pango_tabstops->create_object = pango_tabstops_create_object;

    return SUCCESS;
}
/* }}} */
