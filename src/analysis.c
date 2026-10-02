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
#include "analysis.h"
#include "attribute/attribute.h"
#include "font.h"
#include "context.h"
#include "script.h"
#include "language.h"
#include "attribute/attr_type_to_ce_table.h"
#include "php_pango_macros.h"
#include "analysis_arginfo.h"

zend_class_entry *ce_pango_analysis;

static zend_object_handlers pango_analysis_object_handlers;

pango_analysis_object *pango_analysis_fetch_object(zend_object *object)
{
    return (pango_analysis_object *) ((char*)(object) - offsetof(pango_analysis_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Analysis C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAnalysis *pango_analysis_object_get_analysis(zval *zv)
{
    return Z_PANGO_ANALYSIS_P(zv)->analysis;
}
/* }}} */

zend_class_entry* php_pango_get_analysis_ce(void)
{
    return ce_pango_analysis;
}

/* ----------------------------------------------------------------
    \Pango\Analysis Class API
------------------------------------------------------------------*/

// /* {{{ */
// PHP_METHOD(Pango_Analysis, __construct)
// {
// }
// /* }}} */

/* ----------------------------------------------------------------
    \Pango\Analysis Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_analysis_free_obj(zend_object *object)
{
    pango_analysis_object *intern = pango_analysis_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->analysis) {
        intern->analysis = NULL;
    }

    zval_ptr_dtor(&intern->item_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_analysis_obj_ctor(zend_class_entry *ce, pango_analysis_object **intern)
{
    pango_analysis_object *object = ecalloc(1, sizeof(pango_analysis_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->item_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_analysis_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_analysis_create_object(zend_class_entry *ce)
{
    pango_analysis_object *intern = NULL;
    zend_object *return_value = pango_analysis_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_analysis_clone_obj(zend_object *zobj)
{
    pango_analysis_object *new_analysis;
    pango_analysis_object *old_analysis = pango_analysis_fetch_object(zobj);
    zend_object *return_value = pango_analysis_obj_ctor(zobj->ce, &new_analysis);

    new_analysis->analysis = old_analysis->analysis;

    ZVAL_COPY(&new_analysis->item_zv, &old_analysis->item_zv);

    zend_objects_clone_members(&new_analysis->std, &old_analysis->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_analysis_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_analysis_object *analysis_object = pango_analysis_fetch_object(object);

    if (!analysis_object || !analysis_object->analysis) {
        return zend_std_read_property(object, member, type, cache_slot, rv);
    }

    PangoAnalysis *analysis = analysis_object->analysis;

    if (strcmp(ZSTR_VAL(member), "font") == 0) {
        object_init_ex(rv, php_pango_get_font_ce());
        Z_PANGO_FONT_P(rv)->font = g_object_ref(analysis->font);
        return rv;
    }

    PANGO_LONG_VALUE_FROM_STRUCT(analysis->level, level);
    PANGO_ENUM_VALUE_FROM_STRUCT(analysis->gravity, gravity, php_pango_get_gravity_ce());
    PANGO_LONG_VALUE_FROM_STRUCT(analysis->flags, flags);
    PANGO_ENUM_VALUE_FROM_STRUCT(analysis->script, script, php_pango_get_script_ce());

    if (strcmp(ZSTR_VAL(member), "language") == 0) {
        object_init_ex(rv, php_pango_get_language_ce());
        Z_PANGO_LANGUAGE_P(rv)->language = analysis->language;
        return rv;
    }

    if (strcmp(ZSTR_VAL(member), "extraAttrs") == 0) {
        array_init(rv);
        for (GSList *iter = analysis->extra_attrs; iter != NULL; iter = iter->next) {
            PangoAttribute *attr = (PangoAttribute *)iter->data;
            PangoAttrType attr_type = attr->klass->type;

            zend_class_entry *attr_ce = php_pango_attr_ce_lookup(attr_type);
            if (!attr_ce) {
                continue; // Skip unsupported attribute types
                // zend_throw_exception_ex(
                //     php_pango_get_pango_exception_ce(),
                //     0,
                //     "Unsupported Pango attribute type %d", attr_type
                // );
                // RETURN_THROWS();
            }

            // PANGO_ATTR_LANGUAGE and PANGO_ATTR_FONT_DESC are never added to the
            // extra_attrs list by pango, so we can skip them here as well
            if (attr_type == PANGO_ATTR_LANGUAGE || attr_type == PANGO_ATTR_FONT_DESC) {
                continue;
            }

            zval attr_zv;
            object_init_ex(&attr_zv, attr_ce);
            pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(&attr_zv);
            attr_object->attribute = pango_attribute_copy(attr);

            add_next_index_zval(rv, &attr_zv);
        }
        return rv;
    }

    return zend_std_read_property(object, member, type, cache_slot, rv);
;
}
/* }}} */

/* {{{ */
static HashTable *pango_analysis_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_analysis_object *analysis_object = pango_analysis_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!analysis_object->analysis) {
        return props;
    }

    PangoAnalysis *analysis = analysis_object->analysis;

    // Add the font property
    object_init_ex(&tmp, php_pango_get_font_ce());
    Z_PANGO_FONT_P(&tmp)->font = g_object_ref(analysis->font);
    zend_hash_str_update(props, "font", sizeof("font")-1, &tmp);

    PANGO_ADD_STRUCT_LONG_VALUE(analysis->level, level);
    PANGO_ADD_STRUCT_ENUM_VALUE(analysis->gravity, gravity, php_pango_get_gravity_ce());
    PANGO_ADD_STRUCT_LONG_VALUE(analysis->flags, flags);
    PANGO_ADD_STRUCT_ENUM_VALUE(analysis->script, script, php_pango_get_script_ce());

    // Add the language property
    object_init_ex(&tmp, php_pango_get_language_ce());
    Z_PANGO_LANGUAGE_P(&tmp)->language = analysis->language;
    zend_hash_str_update(props, "language", sizeof("language")-1, &tmp);

    // Add the extraAttrs property
    array_init(&tmp);
    for (GSList *iter = analysis->extra_attrs; iter != NULL; iter = iter->next) {
        zend_class_entry *attr_ce;
        zval attr_zv;
        PangoAttribute *attr = (PangoAttribute *)iter->data;
        PangoAttrType attr_type = attr->klass->type;

        // PANGO_ATTR_LANGUAGE and PANGO_ATTR_FONT_DESC are never added to the
        // extra_attrs list by pango, so we can skip them here as well
        // compare to pango-attributes.c pango_attr_iterator_get_font
        if (attr_type == PANGO_ATTR_LANGUAGE || attr_type == PANGO_ATTR_FONT_DESC) {
            continue;
        }

        attr_ce = php_pango_attr_ce_lookup(attr_type);
        if (!attr_ce) {
            continue;
        }

        object_init_ex(&attr_zv, attr_ce);
        pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(&attr_zv);
        attr_object->attribute = pango_attribute_copy(attr);

        add_next_index_zval(&tmp, &attr_zv);
    }
    zend_hash_str_update(props, "extraAttrs", sizeof("extraAttrs")-1, &tmp);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Analysis Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_analysis)
{
    memcpy(
        &pango_analysis_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_analysis_object_handlers.offset = offsetof(pango_analysis_object, std);
    pango_analysis_object_handlers.free_obj = pango_analysis_free_obj;
    pango_analysis_object_handlers.clone_obj = pango_analysis_clone_obj;
    pango_analysis_object_handlers.read_property = pango_analysis_object_read_property;
    // pango_analysis_object_handlers.write_property = pango_analysis_object_write_property;
    pango_analysis_object_handlers.get_property_ptr_ptr = NULL;
    pango_analysis_object_handlers.get_properties_for = pango_analysis_object_get_properties_for;

    ce_pango_analysis = register_class_Pango_Analysis();
    ce_pango_analysis->create_object = pango_analysis_create_object;

    return SUCCESS;
}
/* }}} */
