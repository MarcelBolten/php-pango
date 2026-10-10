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
#include <Zend/zend_exceptions.h>

#include "../../php_pango.h"
#include "../font_description.h"
#include "../exception.h"
#include "../language.h"
#include "attr_type_to_ce_table.h"
#include "attr_list_arginfo.h"
#include "attribute.h"

zend_class_entry *ce_pango_attr_list;

static zend_object_handlers pango_attr_list_object_handlers;

pango_attr_list_object *pango_attr_list_fetch_object(zend_object *object)
{
    return (pango_attr_list_object *) ((char*)(object) - offsetof(pango_attr_list_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Attribute\AttributeList C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttrList *pango_attr_list_object_get_attr_list(zval *zv)
{
    return Z_PANGO_ATTR_LIST_P(zv)->attr_list;
}
/* }}} */

zend_class_entry* php_pango_get_attr_list_ce(void)
{
    return ce_pango_attr_list;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\AttributeList Class API
------------------------------------------------------------------*/

/* {{{ Creates a new attribute list from a string representation or an empty attribute list. */
PHP_METHOD(Pango_Attribute_AttributeList, __construct)
{
    zend_string *string_rep = NULL;
    pango_attr_list_object *attr_list_object;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STR_OR_NULL(string_rep)
    ZEND_PARSE_PARAMETERS_END();

    attr_list_object = Z_PANGO_ATTR_LIST_P(ZEND_THIS);
    if (!string_rep) {
        attr_list_object->attr_list = pango_attr_list_new();
        return;
    }

    if (zend_str_has_nul_byte(string_rep)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    attr_list_object->attr_list = pango_attr_list_from_string(ZSTR_VAL(string_rep));
    if (!attr_list_object->attr_list) {
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Failed to create Pango\\Attribute\\AttributeList from string",
            0
        );
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ Returns the list of attributes in AttributeList. */
PHP_METHOD(Pango_Attribute_AttributeList, getAttributes)
{
    GSList *attrs;
    zval attr_zv;

    ZEND_PARSE_PARAMETERS_NONE();

    if (!(attrs = pango_attr_list_get_attributes(Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list))) {
        RETURN_EMPTY_ARRAY();
    }

    array_init(return_value);
    for (GSList *iter = attrs; iter != NULL; iter = iter->next) {
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
        object_init_ex(&attr_zv, attr_ce);
        if (attr_type == PANGO_ATTR_FONT_DESC) {
            pango_attr_font_description_object *attr_font_description_object = Z_PANGO_ATTR_FONT_DESCRIPTION_P(&attr_zv);
            attr_font_description_object->attribute = pango_attribute_copy(attr);

            zval font_description_zv;
            object_init_ex(&font_description_zv, php_pango_get_font_description_ce());
            Z_PANGO_FONT_DESC_P(&font_description_zv)->font_description = pango_font_description_copy(
                ((PangoAttrFontDesc *)attr_font_description_object->attribute)->desc
            );

            // hand-over the font description zval to the attribute object without incrementing the refcount
            ZVAL_COPY_VALUE(&attr_font_description_object->font_description_zv, &font_description_zv);
        } else if (attr_type == PANGO_ATTR_LANGUAGE) {
            pango_attr_language_object *attr_language_object = Z_PANGO_ATTR_LANGUAGE_P(&attr_zv);
            attr_language_object->attribute = pango_attribute_copy(attr);

            zval language_zv;
            object_init_ex(&language_zv, php_pango_get_language_ce());
            Z_PANGO_LANGUAGE_P(&language_zv)->language = ((PangoAttrLanguage *)attr_language_object->attribute)->value;

            // hand-over the language zval to the attribute object without incrementing the refcount
            ZVAL_COPY_VALUE(&attr_language_object->language_zv, &language_zv);
        } else {
            Z_PANGO_ATTRIBUTE_P(&attr_zv)->attribute = pango_attribute_copy(attr);
        }

        add_next_index_zval(return_value, &attr_zv);
    }
}
/* }}} */

/* {{{ Insert the given attribute into the AttributeList. */
PHP_METHOD(Pango_Attribute_AttributeList, change)
{
    zval *attr_zv = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_zv, php_pango_get_attribute_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_change(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        pango_attribute_copy(Z_PANGO_ATTRIBUTE_P(attr_zv)->attribute)
    );
}
/* }}} */

typedef struct _php_pango_filter_ctx {
    zend_fcall_info *fci;
    zend_fcall_info_cache *fci_cache;
    bool failed;
} php_pango_filter_ctx;

static gboolean pango_attr_list_filter_callback(PangoAttribute *attribute, gpointer user_data)
{
    php_pango_filter_ctx *ctx = (php_pango_filter_ctx *)user_data;
    zval retval;
    zval arg;
    gboolean result = FALSE;

    // Once something has gone wrong, don't run any more callback code,
    // just let pango finish its loop with everything left untouched.
    if (ctx->failed) {
        return FALSE;
    }

    ZVAL_UNDEF(&retval);

    PangoAttrType attr_type = attribute->klass->type;

    zend_class_entry *attr_ce = php_pango_attr_ce_lookup(attr_type);
     // Skip unsupported attribute types
    if (!attr_ce) {
        return FALSE;
    }

    object_init_ex(&arg, attr_ce);
    if (attr_type == PANGO_ATTR_FONT_DESC) {
        pango_attr_font_description_object *attr_font_description_object = Z_PANGO_ATTR_FONT_DESCRIPTION_P(&arg);
        attr_font_description_object->attribute = pango_attribute_copy(attribute);

        zval font_description_zv;
        object_init_ex(&font_description_zv, php_pango_get_font_description_ce());
        Z_PANGO_FONT_DESC_P(&font_description_zv)->font_description = pango_font_description_copy(
            ((PangoAttrFontDesc *)attr_font_description_object->attribute)->desc
        );

        // hand-over the font description zval to the attribute object without incrementing the refcount
        ZVAL_COPY_VALUE(&attr_font_description_object->font_description_zv, &font_description_zv);
    } else if (attr_type == PANGO_ATTR_LANGUAGE) {
        pango_attr_language_object *attr_language_object = Z_PANGO_ATTR_LANGUAGE_P(&arg);
        attr_language_object->attribute = pango_attribute_copy(attribute);

        zval language_zv;
        object_init_ex(&language_zv, php_pango_get_language_ce());
        Z_PANGO_LANGUAGE_P(&language_zv)->language = ((PangoAttrLanguage *)attr_language_object->attribute)->value;

        // hand-over the language zval to the attribute object without incrementing the refcount
        ZVAL_COPY_VALUE(&attr_language_object->language_zv, &language_zv);
    } else {
        Z_PANGO_ATTRIBUTE_P(&arg)->attribute = pango_attribute_copy(attribute);
    }

    ctx->fci->params = &arg;
    ctx->fci->param_count = 1;
    ctx->fci->retval = &retval;

    if (zend_call_function(ctx->fci, ctx->fci_cache) == FAILURE) {
        ctx->failed = true;
        zend_throw_exception(
            php_pango_get_pango_exception_ce(),
            "Failed to invoke filter callback",
            0
        );
        goto cleanup;
    }

    /* The PHP callback itself may have thrown, don't try to interpret
     * garbage/undef retval as a bool, and don't stack a second exception
     * on top of it. */
    if (EG(exception)) {
        ctx->failed = true;
        goto cleanup;
    }

    if (Z_TYPE(retval) != IS_TRUE
        && Z_TYPE(retval) != IS_FALSE
    ) {
        ctx->failed = true;
        zend_throw_exception(
            zend_ce_type_error,
            "Pango\\Attribute\\AttributeList::filter(): Argument #1 ($callback) must return a boolean value",
            0
        );
        goto cleanup;
    }

    result = (Z_TYPE(retval) == IS_TRUE);

cleanup:
    zval_ptr_dtor(&retval);
    zval_ptr_dtor(&arg);

    return result;
}

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, filter)
{
    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fci_cache = empty_fcall_info_cache;
    php_pango_filter_ctx ctx;
    PangoAttrList *original;
    PangoAttrList *working;
    PangoAttrList* filter_res = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_FUNC(fci, fci_cache)
    ZEND_PARSE_PARAMETERS_END();

    ctx.fci = &fci;
    ctx.fci_cache = &fci_cache;
    ctx.failed = false;

    original = Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list;
    working = pango_attr_list_copy(original);

    filter_res = pango_attr_list_filter(
        working,
        pango_attr_list_filter_callback,
        &ctx
    );

    /* If the PHP callback (or our own type-check) threw, propagate it
     * rather than returning a bogus AttrList/null. */
    if (EG(exception)) {
        if (filter_res) {
            pango_attr_list_unref(filter_res);
        }
        pango_attr_list_unref(working);
        RETURN_THROWS();
    }

    pango_attr_list_unref(original);
    Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list = working;

    if (!filter_res) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_attr_list_ce());
    Z_PANGO_ATTR_LIST_P(return_value)->attr_list = filter_res;
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, getIterator)
{
    pango_attr_iter_object *attr_iter_obj;
    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, php_pango_get_attr_iter_ce());
    attr_iter_obj = Z_PANGO_ATTR_ITER_P(return_value);

    // Copy the attribute list to ensure that the iterator has its own list
    // that will not be modified until the iterator is freed
    attr_iter_obj->attr_list = pango_attr_list_copy(pango_attr_list_object_get_attr_list(ZEND_THIS));
    attr_iter_obj->attr_iter = pango_attr_list_get_iterator(attr_iter_obj->attr_list);
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, insert)
{
    zval *attr_zv = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_zv, php_pango_get_attribute_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_insert(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        pango_attribute_copy(Z_PANGO_ATTRIBUTE_P(attr_zv)->attribute)
    );
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, insertBefore)
{
    zval *attr_zv = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_zv, php_pango_get_attribute_ce())
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_insert_before(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        pango_attribute_copy(Z_PANGO_ATTRIBUTE_P(attr_zv)->attribute)
    );
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, splice)
{
    zval *attr_list_zv = NULL;
    zend_long pos;
    zend_long length;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, ce_pango_attr_list)
        Z_PARAM_LONG(pos)
        Z_PARAM_LONG(length)
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_splice(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        Z_PANGO_ATTR_LIST_P(attr_list_zv)->attr_list,
        pos, length
    );
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, merge)
{
    zval *attr_list_zv = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(attr_list_zv, ce_pango_attr_list)
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_splice(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        Z_PANGO_ATTR_LIST_P(attr_list_zv)->attr_list,
        0, 0
    );
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, toString)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING(pango_attr_list_to_string(Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list));
}
/* }}} */

/* {{{  */
PHP_METHOD(Pango_Attribute_AttributeList, update)
{
    zend_long pos;
    zend_long remove;
    zend_long add;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(pos)
        Z_PARAM_LONG(remove)
        Z_PARAM_LONG(add)
    ZEND_PARSE_PARAMETERS_END();

    pango_attr_list_update(
        Z_PANGO_ATTR_LIST_P(ZEND_THIS)->attr_list,
        pos, remove, add
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\AttributeList Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_attr_list_free_obj(zend_object *object)
{
    pango_attr_list_object *intern = pango_attr_list_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->attr_list) {
        pango_attr_list_unref(intern->attr_list);
        intern->attr_list = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_list_obj_ctor(zend_class_entry *ce, pango_attr_list_object **intern)
{
    pango_attr_list_object *object = ecalloc(1, sizeof(pango_attr_list_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_attr_list_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_list_create_object(zend_class_entry *ce)
{
    pango_attr_list_object *intern = NULL;
    zend_object *return_value = pango_attr_list_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_list_clone_obj(zend_object *zobj)
{
    pango_attr_list_object *new_attr_list;
    pango_attr_list_object *old_attr_list = pango_attr_list_fetch_object(zobj);
    zend_object *return_value = pango_attr_list_obj_ctor(zobj->ce, &new_attr_list);

    new_attr_list->attr_list = pango_attr_list_copy(old_attr_list->attr_list);

    zend_objects_clone_members(&new_attr_list->std, &old_attr_list->std);

    return return_value;
}
/* }}} */

/* {{{ */
// static zval *pango_attr_list_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
// {
//     pango_attr_list_object *attr_list_object = pango_attr_list_fetch_object(object);

//     if (!attr_list_object) {
//         return rv;
//     }

//     return rv;
// }
/* }}} */

/* {{{ */
// static HashTable *pango_attr_list_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
// {
//     HashTable *props;
//     // used in macros below
//     zval tmp;
//     pango_attr_list_object *attr_list_object = pango_attr_list_fetch_object(object);

//     props = zend_std_get_properties(object);

//     if (!attr_list_object->attr_list) {
//         return props;
//     }

//     return props;
// }
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\AttributeList Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_list)
{
    memcpy(
        &pango_attr_list_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_list_object_handlers.offset = offsetof(pango_attr_list_object, std);
    pango_attr_list_object_handlers.free_obj = pango_attr_list_free_obj;
    pango_attr_list_object_handlers.clone_obj = pango_attr_list_clone_obj;
    // pango_attr_list_object_handlers.read_property = pango_attr_list_object_read_property;
    // pango_attr_list_object_handlers.write_property = pango_attr_list_object_write_property;
    pango_attr_list_object_handlers.get_property_ptr_ptr = NULL;
    // pango_attr_list_object_handlers.get_properties_for = pango_attr_list_object_get_properties_for;
    pango_attr_list_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_list = register_class_Pango_Attribute_AttributeList();
    ce_pango_attr_list->create_object = pango_attr_list_create_object;

    return SUCCESS;
}
/* }}} */
