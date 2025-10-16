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

#include "php.h"
#include "php_pango.h"
#include "item_arginfo.h"

#include <string.h>
#include <glib.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_item;

static zend_object_handlers pango_item_object_handlers;

pango_item_object *pango_item_fetch_object(zend_object *object)
{
    return (pango_item_object *) ((char*)(object) - XtOffsetOf(pango_item_object, std));
}

#define PANGO_VALUE_FROM_STRUCT(php_name, c_name) \
    if (strcmp(ZSTR_VAL(member), #php_name) == 0) { \
        zend_long value = 0; \
        value = item_object->item->c_name; \
        ZVAL_LONG(rv, value); \
        return rv; \
    }

#define PANGO_ADD_STRUCT_VALUE(php_name, c_name) \
    ZVAL_LONG(&tmp, item_object->item->c_name); \
    zend_hash_str_update(props, #php_name, sizeof(#php_name)-1, &tmp);


PHP_PANGO_API zend_class_entry* php_pango_get_item_ce()
{
    return pango_ce_pango_item;
}

/* ----------------------------------------------------------------
    \Pango\Item Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_item_free_obj(zend_object *zobj)
{
    pango_item_object *intern = pango_item_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->item != NULL) {
        pango_item_free(intern->item);
        intern->item = NULL;
    }

    zval_ptr_dtor(&intern->glyph_item_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_item_obj_ctor(zend_class_entry *ce, pango_item_object **intern)
{
    pango_item_object *object = ecalloc(1, sizeof(pango_item_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->glyph_item_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_item_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_item_create_object(zend_class_entry *ce)
{
    pango_item_object *intern = NULL;
    zend_object *return_value = pango_item_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_item_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_item_object *item_object = pango_item_fetch_object(zobj);

    if (strcmp(ZSTR_VAL(member), "analysis") == 0) {
        array_init(rv);
        add_assoc_long(rv, "bidiLevel", item_object->item->analysis.level);

        zend_object *gravity_case;
        zend_enum_get_case_by_value(
            &gravity_case, php_pango_get_gravity_ce(),
            item_object->item->analysis.gravity,
            NULL, false
        );
        add_assoc_object(rv, "gravity", gravity_case);

        // add_assoc_long(rv, "flags", item_object->item->analysis.flags);
        add_assoc_bool(rv, "centeredBaseline", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_CENTERED_BASELINE) != 0);
        add_assoc_bool(rv, "isEllipsis", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_IS_ELLIPSIS) != 0);
        add_assoc_bool(rv, "needsHyphen", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_NEED_HYPHEN) != 0);

        guint32 script_code = GUINT32_TO_BE(g_unicode_script_to_iso15924((GUnicodeScript)item_object->item->analysis.script));
        char script_str[5] = {0};
        memcpy(script_str, &script_code, 4);
        script_str[4] = '\0';
        add_assoc_string(rv, "script", script_str);

        if (item_object->item->analysis.language != NULL) {
            const char* lang_str = pango_language_to_string(item_object->item->analysis.language);
            add_assoc_string(rv, "language", lang_str);
        } else {
            add_assoc_null(rv, "language");
        }
        return rv;
    }

    PANGO_VALUE_FROM_STRUCT(offset, offset);
    PANGO_VALUE_FROM_STRUCT(length, length);
    PANGO_VALUE_FROM_STRUCT(numChars, num_chars);
}
/* }}} */

/* {{{ */
static HashTable *pango_item_get_properties(zend_object *object)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_item_object *item_object = pango_item_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!item_object->item) {
        return props;
    }

    array_init(&tmp);
    add_assoc_long(&tmp, "bidiLevel", item_object->item->analysis.level);

    zend_object *gravity_case;
    zend_enum_get_case_by_value(
        &gravity_case, php_pango_get_gravity_ce(),
        item_object->item->analysis.gravity,
        NULL, false
    );
    add_assoc_object(&tmp, "gravity", gravity_case);

    // add_assoc_long(&tmp, "flags", item_object->item->analysis.flags);
    add_assoc_bool(&tmp, "centeredBaseline", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_CENTERED_BASELINE) != 0);
    add_assoc_bool(&tmp, "isEllipsis", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_IS_ELLIPSIS) != 0);
    add_assoc_bool(&tmp, "needsHyphen", (item_object->item->analysis.flags & PANGO_ANALYSIS_FLAG_NEED_HYPHEN) != 0);

    guint32 script_code = GUINT32_TO_BE(g_unicode_script_to_iso15924((GUnicodeScript)item_object->item->analysis.script));
    char script_str[5] = {0};
    memcpy(script_str, &script_code, 4);
    script_str[4] = '\0';
    add_assoc_string(&tmp, "script", script_str);

    if (item_object->item->analysis.language != NULL) {
        const char* lang_str = pango_language_to_string(item_object->item->analysis.language);
        add_assoc_string(&tmp, "language", lang_str);
    } else {
        add_assoc_null(&tmp, "language");
    }
    zend_hash_str_update(props, "analysis", sizeof("analysis")-1, &tmp);


    PANGO_ADD_STRUCT_VALUE(offset, offset);
    PANGO_ADD_STRUCT_VALUE(length, length);
    PANGO_ADD_STRUCT_VALUE(numChars, num_chars);

    return props;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_item)
{
    memcpy(
        &pango_item_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_item_object_handlers.offset = XtOffsetOf(pango_item_object, std);
    pango_item_object_handlers.free_obj = pango_item_free_obj;
    pango_item_object_handlers.read_property = pango_item_read_property;
    pango_item_object_handlers.get_property_ptr_ptr = NULL;
    pango_item_object_handlers.get_properties = pango_item_get_properties;

    pango_ce_pango_item = register_class_Pango_Item();
    pango_ce_pango_item->create_object = pango_item_create_object;

    return SUCCESS;
}
/* }}} */
