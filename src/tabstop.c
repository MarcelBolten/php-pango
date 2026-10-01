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
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "php_pango_macros.h"
#include "tabstops.h"
#include "tabstops_arginfo.h"

zend_class_entry *ce_pango_tabstop;
zend_class_entry *ce_pango_tabstop_pixel;
zend_class_entry *ce_pango_tab_align;

static zend_object_handlers pango_tabstop_object_handlers;
static zend_object_handlers pango_tabstop_pixel_object_handlers;

pango_tabstop_object *pango_tabstop_fetch_object(zend_object *object)
{
    return (pango_tabstop_object *) ((char*)(object) - offsetof(pango_tabstop_object, std));
}

/* ----------------------------------------------------------------
    \Pango\TabStop C API
------------------------------------------------------------------*/

zend_class_entry* php_pango_get_tabstop_ce()
{
    return ce_pango_tabstop;
}

zend_class_entry* php_pango_get_tabstop_pixel_ce()
{
    return ce_pango_tabstop_pixel;
}

zend_class_entry* php_pango_get_tab_align_ce()
{
    return ce_pango_tab_align;
}

/* ----------------------------------------------------------------
    \Pango\TabStop Class API
------------------------------------------------------------------*/

/* {{{  */
PHP_METHOD(Pango_TabStop, __construct)
{
    zval *alignment_zv;
    zend_long position;
    zend_string *decimalChar = NULL;
    zend_long alignment_value;

    ZEND_PARSE_PARAMETERS_START(2, 3)
        Z_PARAM_OBJECT_OF_CLASS(alignment_zv, ce_pango_tab_align)
        Z_PARAM_LONG(position)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(decimalChar)
    ZEND_PARSE_PARAMETERS_END();

    if (decimalChar && zend_str_has_nul_byte(decimalChar)) {
        zend_argument_value_error(3, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    // ensure that decimalChar is a single UTF-8 character/code point
    if (decimalChar && g_utf8_strlen(ZSTR_VAL(decimalChar), ZSTR_LEN(decimalChar)) > 1) {
        zend_argument_value_error(3, "must be a single UTF-8 character");
        RETURN_THROWS();
    }

    zend_update_property(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "alignment", sizeof("alignment") - 1, alignment_zv
    );
    zend_update_property_long(
        Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "position", sizeof("position") - 1, position
    );

    alignment_value = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(alignment_zv)));

    if (decimalChar && alignment_value == PANGO_TAB_DECIMAL) {
        zend_update_property_stringl(
            Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
            "decimalChar", sizeof("decimalChar") - 1, ZSTR_VAL(decimalChar), ZSTR_LEN(decimalChar)
        );
    } else {
        zend_update_property_null(
            Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
            "decimalChar", sizeof("decimalChar") - 1
        );
    }
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\TabStop Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_tabstop_free_obj(zend_object *object)
{
    pango_tabstop_object *intern = pango_tabstop_fetch_object(object);

    if (!intern) {
        return;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstop_obj_ctor(zend_class_entry *ce, pango_tabstop_object **intern)
{
    pango_tabstop_object *object = ecalloc(1, sizeof(pango_tabstop_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_tabstop_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstop_create_object(zend_class_entry *ce)
{
    pango_tabstop_object *intern = NULL;
    zend_object *return_value = pango_tabstop_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_tabstop_clone_obj(zend_object *zobj)
{
    pango_tabstop_object *new_tabstop;
    pango_tabstop_object *old_tabstop = pango_tabstop_fetch_object(zobj);
    zend_object *return_value = pango_tabstop_obj_ctor(zobj->ce, &new_tabstop);

    zend_objects_clone_members(&new_tabstop->std, &old_tabstop->std);

    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\TabStop Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_tabstop)
{
    memcpy(
        &pango_tabstop_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_tabstop_object_handlers.offset = offsetof(pango_tabstop_object, std);
    pango_tabstop_object_handlers.free_obj = pango_tabstop_free_obj;
    pango_tabstop_object_handlers.clone_obj = pango_tabstop_clone_obj;
    pango_tabstop_object_handlers.get_property_ptr_ptr = NULL;

    ce_pango_tabstop = register_class_Pango_TabStop();
    ce_pango_tabstop->create_object = pango_tabstop_create_object;

    memcpy(
        &pango_tabstop_pixel_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_tabstop_pixel_object_handlers.offset = offsetof(pango_tabstop_object, std);
    pango_tabstop_pixel_object_handlers.free_obj = pango_tabstop_free_obj;
    pango_tabstop_pixel_object_handlers.clone_obj = pango_tabstop_clone_obj;
    pango_tabstop_pixel_object_handlers.get_property_ptr_ptr = NULL;

    ce_pango_tabstop_pixel = register_class_Pango_TabStopPixel(ce_pango_tabstop);
    ce_pango_tabstop_pixel->create_object = pango_tabstop_create_object;

    ce_pango_tab_align = register_class_Pango_TabAlign();

    return SUCCESS;
}
/* }}} */
