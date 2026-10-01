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

#include "../../php_pango.h"
#include "../php_pango_macros.h"
#include "../language.h"
#include "attr_macros.h"
#include "attribute.h"
#include "attribute_arginfo.h"

zend_class_entry *ce_pango_attr_language;

static zend_object_handlers pango_attr_language_object_handlers;

pango_attr_language_object *pango_attr_language_fetch_object(zend_object *object)
{
    return (pango_attr_language_object *) ((char*)(object) - offsetof(pango_attr_language_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Language C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoAttribute *pango_attr_language_object_get_attribute(zval *zv)
{
    pango_attr_language_object *attr_object = Z_PANGO_ATTR_LANGUAGE_P(zv);

    return (PangoAttribute *) attr_object->attribute;
}
/* }}} */

zend_class_entry* php_pango_get_attr_language_ce()
{
    return ce_pango_attr_language;
}

/* ----------------------------------------------------------------
    \Pango\Attribute\Language Class API
------------------------------------------------------------------*/

/* {{{ Creates a new language attribute */
PHP_METHOD(Pango_Attribute_Language, __construct)
{
    zval *language_zv;
    pango_attr_language_object *attr_object;
    PangoLanguage *language;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(language_zv, php_pango_get_language_ce())
    ZEND_PARSE_PARAMETERS_END();

    attr_object = Z_PANGO_ATTR_LANGUAGE_P(ZEND_THIS);

    zval_ptr_dtor(&attr_object->language_zv);
    ZVAL_COPY(&attr_object->language_zv, language_zv);

    language = Z_PANGO_LANGUAGE_P(language_zv)->language;
    attr_object->attribute = pango_attr_language_new(language);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Language Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_attr_language_free_obj(zend_object *object)
{
    pango_attr_language_object *intern = pango_attr_language_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->attribute) {
        pango_attribute_destroy(intern->attribute);
        intern->attribute = NULL;
    }

    zval_ptr_dtor(&intern->language_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_language_obj_ctor(zend_class_entry *ce, pango_attr_language_object **intern)
{
    pango_attr_language_object *object = ecalloc(1, sizeof(pango_attr_language_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->language_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_attr_language_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_language_create_object(zend_class_entry *ce)
{
    pango_attr_language_object *intern = NULL;
    zend_object *return_value = pango_attr_language_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_language_clone_obj(zend_object *zobj)
{
    pango_attr_language_object *new_attr;
    pango_attr_language_object *old_attr = pango_attr_language_fetch_object(zobj);
    zend_object *return_value = pango_attr_language_obj_ctor(zobj->ce, &new_attr);

    if (old_attr->attribute) {
        new_attr->attribute = pango_attribute_copy(old_attr->attribute);
    }

    zval_ptr_dtor(&new_attr->language_zv);
    ZVAL_COPY(&new_attr->language_zv, &old_attr->language_zv);

    zend_objects_clone_members(&new_attr->std, &old_attr->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_attr_language_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    pango_attr_language_object *attr_object = pango_attr_language_fetch_object(object);

    if (!attr_object) {
        return rv;
    }

    if (strcmp(member->val, "value") == 0) {
        ZVAL_COPY(rv, &attr_object->language_zv);
        return rv;
    }

    PangoAttrLanguage *attr = (PangoAttrLanguage *)attr_object->attribute;

    PANGO_ATTR_RANGE_READ_PROPERTY(&attr->attr);

    return rv;
}
/* }}} */

/* {{{ */
static zval *pango_attr_language_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    pango_attr_language_object *attr_object = pango_attr_language_fetch_object(object);
    zval *retval = NULL;

    if (!attr_object) {
        return retval;
    }

    do {
        PangoAttrLanguage *attr = (PangoAttrLanguage *)attr_object->attribute;

        if (strcmp(member->val, "value") == 0) {
            if (Z_TYPE_P(value) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(value), php_pango_get_language_ce())) {
                zend_type_error(
                    "Cannot assign %s to property %s::$%s of type %s",
                    zend_zval_type_name(value),
                    ZSTR_VAL(object->ce->name),
                    "value",
                    ZSTR_VAL(php_pango_get_language_ce()->name)
                );
                break;
            }

            zval_ptr_dtor(&attr_object->language_zv);
            ZVAL_COPY(&attr_object->language_zv, value);

            PangoLanguage *language = Z_PANGO_LANGUAGE_P(value)->language;
            attr->value = language;

            break;
        }

        PANGO_ATTR_RANGE_WRITE_PROPERTY(&attr->attr);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);
    } while(0);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *pango_attr_language_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in macros below
    zval tmp;
    pango_attr_language_object *attr_object = pango_attr_language_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!attr_object->attribute) {
        return props;
    }

    PangoAttrLanguage *attr = (PangoAttrLanguage *)attr_object->attribute;
    PANGO_ATTR_ADD_RANGE_PROPERTIES(&attr->attr);

    ZVAL_COPY(&tmp, &attr_object->language_zv);
    zend_hash_str_update(props, "value", sizeof("value")-1, &tmp);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attribute\Language Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_language)
{
    memcpy(
        &pango_attr_language_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_language_object_handlers.offset = offsetof(pango_attr_language_object, std);
    pango_attr_language_object_handlers.free_obj = pango_attr_language_free_obj;
    pango_attr_language_object_handlers.clone_obj = pango_attr_language_clone_obj;
    pango_attr_language_object_handlers.read_property = pango_attr_language_object_read_property;
    pango_attr_language_object_handlers.write_property = pango_attr_language_object_write_property;
    pango_attr_language_object_handlers.get_property_ptr_ptr = NULL;
    pango_attr_language_object_handlers.get_properties_for = pango_attr_language_object_get_properties_for;
    pango_attr_language_object_handlers.compare = pango_attr_object_compare;

    ce_pango_attr_language = register_class_Pango_Attribute_Language(php_pango_get_attribute_ce());
    ce_pango_attr_language->create_object = pango_attr_language_create_object;

    return SUCCESS;
}
/* }}} */
