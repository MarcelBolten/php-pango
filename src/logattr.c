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

#include "../php_pango.h"
#include "php_pango_macros.h"
#include "logattr.h"
#include "logattr_arginfo.h"

zend_class_entry *ce_pango_logattr;

static zend_object_handlers pango_logattr_object_handlers;

pango_logattr_object *pango_logattr_fetch_object(zend_object *object)
{
    return (pango_logattr_object *) ((char*)(object) - offsetof(pango_logattr_object, std));
}

#define PANGO_ALLOC_LOGATTR(logattr_value) if (!logattr_value) \
    { logattr_value = ecalloc(1, sizeof(PangoLogAttr)); }

/* ----------------------------------------------------------------
    \Pango\LogAttr C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoLogAttr *pango_logattr_object_get_logattr(zval *zv)
{
    return Z_PANGO_LOGATTR_P(zv)->logattr;
}
/* }}} */

zend_class_entry* php_pango_get_logattr_ce(void)
{
    return ce_pango_logattr;
}

/* ----------------------------------------------------------------
    \Pango\LogAttr Class API
------------------------------------------------------------------*/

// /* {{{ Creates a new rectangle with the properties populated */
// PHP_METHOD(Pango_Rectangle, __construct)
// {
//     zend_long x;
//     zend_long y;
//     zend_long width;
//     zend_long height;
//     pango_rectangle_object *rectangle_object;

//     ZEND_PARSE_PARAMETERS_START(4, 4)
//         Z_PARAM_LONG(x)
//         Z_PARAM_LONG(y)
//         Z_PARAM_LONG(width)
//         Z_PARAM_LONG(height)
//     ZEND_PARSE_PARAMETERS_END();

//     rectangle_object = pango_rectangle_fetch_object(Z_OBJ_P(ZEND_THIS));
//     *rectangle_object->rect = (PangoRectangle){(int)x, (int)y, (int)width, (int)height};
// }
// /* }}} */

// /* {{{ Converts extents from Pango units to device units and rounds based on rounding mode. */
// PHP_METHOD(Pango_Rectangle, extentsToPixels)
// {
//     zval *rectangle_zv;
//     zend_object *rounding_mode_case = NULL;
//     // Default rounding mode is inclusive
//     bool use_inclusive = true;
//     PangoRectangle rect;

//     ZEND_PARSE_PARAMETERS_START(1, 2)
//         Z_PARAM_OBJECT_OF_CLASS(rectangle_zv, ce_pango_rectangle)
//         Z_PARAM_OPTIONAL
//         Z_PARAM_OBJ_OF_CLASS(rounding_mode_case, ce_pango_rounding_mode)
//     ZEND_PARSE_PARAMETERS_END();

//     if (rounding_mode_case) {
//         zend_string *name = Z_STR_P(zend_enum_fetch_case_name(rounding_mode_case));

//         if (zend_string_equals_literal(name, "Nearest")) {
//             use_inclusive = false;
//         }
//         // "Inclusive" is the default, so no need to check explicitly
//     }

//     rect = *pango_rectangle_object_get_rectangle(rectangle_zv);

//     // Call with inclusive rounding
//     if (use_inclusive) {
//         pango_extents_to_pixels(&rect, NULL);
//     }
//     // Call with nearest rounding
//     else {
//         pango_extents_to_pixels(NULL, &rect);
//     }

//     object_init_ex(return_value, ce_pango_rectangle);
//     *pango_rectangle_object_get_rectangle(return_value) = rect;
// }
// /* }}} */

/* ----------------------------------------------------------------
    \Pango\LogAttr Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_logattr_free_obj(zend_object *object)
{
    pango_logattr_object *intern = pango_logattr_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->logattr) {
        efree(intern->logattr);
        intern->logattr = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_obj_ctor(zend_class_entry *ce, pango_logattr_object **intern)
{
    pango_logattr_object *object = ecalloc(1, sizeof(pango_logattr_object) + zend_object_properties_size(ce));
    PANGO_ALLOC_LOGATTR(object->logattr);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_logattr_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_create_object(zend_class_entry *ce)
{
    pango_logattr_object *intern = NULL;
    zend_object *return_value = pango_logattr_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_logattr_clone_obj(zend_object *zobj)
{
    pango_logattr_object *new_logattr;
    pango_logattr_object *old_logattr = pango_logattr_fetch_object(zobj);
    zend_object *return_value = pango_logattr_obj_ctor(zobj->ce, &new_logattr);
    PANGO_ALLOC_LOGATTR(new_logattr->logattr);

    *new_logattr->logattr = *old_logattr->logattr;

    zend_objects_clone_members(&new_logattr->std, &old_logattr->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_logattr_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_logattr_object *logattr_object = pango_logattr_fetch_object(object);

    if (!logattr_object) {
        return rv;
    }

    PangoLogAttr *logattr = logattr_object->logattr;

    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_line_break, lineBreak);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_mandatory_break, mandatoryBreak);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_char_break, charBreak);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_white, white);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_cursor_position, cursorPosition);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_word_start, wordStart);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_word_end, wordEnd);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_sentence_boundary, sentenceBoundary);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_sentence_start, sentenceStart);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_sentence_end, sentenceEnd);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->backspace_deletes_character, backspaceDeletesCharacter);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_expandable_space, expandableSpace);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->is_word_boundary, wordBoundary);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->break_inserts_hyphen, breakInsertsHyphen);
    PANGO_BOOL_VALUE_FROM_STRUCT(logattr->break_removes_preceding, breakRemovesPreceding);
#endif

    return rv;
}
/* }}} */

/* {{{ */
static HashTable *pango_logattr_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_logattr_object *logattr_object = pango_logattr_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!logattr_object->logattr) {
        return props;
    }

    PangoLogAttr *logattr = logattr_object->logattr;

    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_line_break, lineBreak);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_mandatory_break, mandatoryBreak);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_char_break, charBreak);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_white, white);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_cursor_position, cursorPosition);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_word_start, wordStart);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_word_end, wordEnd);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_sentence_boundary, sentenceBoundary);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_sentence_start, sentenceStart);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_sentence_end, sentenceEnd);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->backspace_deletes_character, backspaceDeletesCharacter);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_expandable_space, expandableSpace);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->is_word_boundary, wordBoundary);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->break_inserts_hyphen, breakInsertsHyphen);
    PANGO_ADD_STRUCT_BOOL_VALUE(logattr->break_removes_preceding, breakRemovesPreceding);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\LogAttr Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_logattr)
{
    memcpy(
        &pango_logattr_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_logattr_object_handlers.offset = offsetof(pango_logattr_object, std);
    pango_logattr_object_handlers.free_obj = pango_logattr_free_obj;
    pango_logattr_object_handlers.clone_obj = pango_logattr_clone_obj;
    pango_logattr_object_handlers.read_property = pango_logattr_object_read_property;
    // pango_logattr_object_handlers.write_property = pango_logattr_object_write_property;
    pango_logattr_object_handlers.get_property_ptr_ptr = NULL;
    pango_logattr_object_handlers.get_properties_for = pango_logattr_object_get_properties_for;

    ce_pango_logattr = register_class_Pango_LogAttr();
    ce_pango_logattr->create_object = pango_logattr_create_object;

    return SUCCESS;
}
/* }}} */
