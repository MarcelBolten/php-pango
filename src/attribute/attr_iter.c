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
  | Authors: Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>

#include "../../php_pango.h"
#include "../font_description.h"
#include "../language.h"
#include "attr_type_to_ce_table.h"
#include "attribute.h"
#include "attr_iter_arginfo.h"

zend_class_entry *pango_ce_pango_attr_iter;

static zend_object_handlers pango_attr_iter_object_handlers;

PHP_PANGO_API zend_class_entry* php_pango_get_attr_iter_ce() {
    return pango_ce_pango_attr_iter;
}

pango_attr_iter_object *pango_attr_iter_fetch_object(zend_object *object)
{
    return (pango_attr_iter_object *) ((char*)(object) - offsetof(pango_attr_iter_object, std));
}

PHP_PANGO_API PangoAttrIterator *pango_attr_iter_object_get_attr_iter(zval *zv)
{
    return Z_PANGO_ATTR_ITER_P(zv)->attr_iter;
}

PHP_PANGO_API PangoAttrList *pango_attr_iter_object_get_attr_list(zval *zv)
{
    return Z_PANGO_ATTR_ITER_P(zv)->attr_list;
}

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, get)
{
    zend_object *attr_type_case;
    PangoAttribute* attr = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(attr_type_case, php_pango_get_attribute_type_ce())
    ZEND_PARSE_PARAMETERS_END();

    attr = pango_attr_iterator_get(
        pango_attr_iter_object_get_attr_iter(ZEND_THIS),
        Z_LVAL_P(zend_enum_fetch_case_value(attr_type_case))
    );

    if (!attr) {
        RETURN_NULL();
    }

    PangoAttrType attr_type = attr->klass->type;
    zend_class_entry *attr_ce = php_pango_attr_ce_lookup(attr_type);
    // Unsupported attribute types
    if (!attr_ce) {
        RETURN_NULL();
        // zend_throw_exception_ex(
        //     php_pango_get_pango_exception_ce(),
        //     0,
        //     "Unsupported Pango attribute type %d", attr_type
        // );
        // RETURN_THROWS();
    }

    object_init_ex(return_value, attr_ce);
    if (attr_type == PANGO_ATTR_FONT_DESC) {
        pango_attr_font_description_object *attr_font_description_object = Z_PANGO_ATTR_FONT_DESCRIPTION_P(return_value);
        attr_font_description_object->attribute = pango_attribute_copy(attr);

        zval font_description_zv;
        object_init_ex(&font_description_zv, php_pango_get_font_description_ce());
        Z_PANGO_FONT_DESC_P(&font_description_zv)->font_description = pango_font_description_copy(
            ((PangoAttrFontDesc *)attr_font_description_object->attribute)->desc
        );

        // hand-over the font description zval to the attribute object without incrementing the refcount
        ZVAL_COPY_VALUE(&attr_font_description_object->font_description_zv, &font_description_zv);
    } else if (attr_type == PANGO_ATTR_LANGUAGE) {
        pango_attr_language_object *attr_language_object = Z_PANGO_ATTR_LANGUAGE_P(return_value);
        attr_language_object->attribute = pango_attribute_copy(attr);

        zval language_zv;
        object_init_ex(&language_zv, php_pango_get_language_ce());
        Z_PANGO_LANGUAGE_P(&language_zv)->language = ((PangoAttrLanguage *)attr_language_object->attribute)->value;

        // hand-over the language zval to the attribute object without incrementing the refcount
        ZVAL_COPY_VALUE(&attr_language_object->language_zv, &language_zv);
    } else {
        pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(return_value);
        attr_object->attribute = pango_attribute_copy(attr);
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, getAttributes)
{
    GSList *attributes;
    ZEND_PARSE_PARAMETERS_NONE();

    attributes = pango_attr_iterator_get_attrs(pango_attr_iter_object_get_attr_iter(ZEND_THIS));

    array_init(return_value);
    for (GSList *iter = attributes; iter != NULL; iter = iter->next) {
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
        zval attr_zv;
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
            pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(&attr_zv);
            attr_object->attribute = pango_attribute_copy(attr);
        }

        add_next_index_zval(return_value, &attr_zv);
    }
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, getFont)
{
    PangoFontDescription* font_desc = pango_font_description_new();
    PangoLanguage* language;
    GSList* extra_attrs;
    zval tmp;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_attr_iterator_get_font(
        pango_attr_iter_object_get_attr_iter(ZEND_THIS),
        font_desc,
        &language,
        &extra_attrs
    );

    array_init(return_value);

    object_init_ex(&tmp, php_pango_get_font_description_ce());
    Z_PANGO_FONT_DESC_P(&tmp)->font_description = font_desc;
    pango_font_description_set_family(
        Z_PANGO_FONT_DESC_P(&tmp)->font_description,
        pango_font_description_get_family(Z_PANGO_FONT_DESC_P(&tmp)->font_description));
    add_assoc_zval(return_value, "fontDescription", &tmp);

    object_init_ex(&tmp, php_pango_get_language_ce());
    Z_PANGO_LANGUAGE_P(&tmp)->language = language;
    add_assoc_zval(return_value, "language", &tmp);

    array_init(&tmp);
    for (GSList *iter = extra_attrs; iter != NULL; iter = iter->next) {
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
        zval attr_zv;
        object_init_ex(&attr_zv, attr_ce);

        // PANGO_ATTR_LANGUAGE and PANGO_ATTR_FONT_DESC are never added to the
        // extra_attrs list by pango, so we can skip them here as well
        if (attr_type == PANGO_ATTR_LANGUAGE || attr_type == PANGO_ATTR_FONT_DESC) {
            continue;
        } else {
            pango_attribute_object *attr_object = Z_PANGO_ATTRIBUTE_P(&attr_zv);
            attr_object->attribute = pango_attribute_copy(attr);
        }

        add_next_index_zval(&tmp, &attr_zv);
    }
    add_assoc_zval(return_value, "extraAttrs", &tmp);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, getRange)
{
    int start, end;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_attr_iterator_range(
        pango_attr_iter_object_get_attr_iter(ZEND_THIS),
        &start,
        &end
    );

    array_init(return_value);
    add_assoc_long(return_value, "start", start);
    add_assoc_long(return_value, "end", end);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Attribute_AttributeIterator, next)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_attr_iterator_next(pango_attr_iter_object_get_attr_iter(ZEND_THIS)));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Attr Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_attr_iter_free_obj(zend_object *zobj)
{
    pango_attr_iter_object *intern = pango_attr_iter_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->attr_iter) {
        pango_attr_iterator_destroy(intern->attr_iter);
        intern->attr_iter = NULL;
    }

    if (intern->attr_list) {
        pango_attr_list_unref(intern->attr_list);
        intern->attr_list = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_iter_obj_ctor(zend_class_entry *ce, pango_attr_iter_object **intern)
{
    pango_attr_iter_object *object = ecalloc(1, sizeof(pango_attr_iter_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_attr_iter_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_iter_create_object(zend_class_entry *ce)
{
    pango_attr_iter_object *intern = NULL;
    zend_object *return_value = pango_attr_iter_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_attr_iter_clone_obj(zend_object *zobj)
{
    pango_attr_iter_object *new_attr_iter;
    pango_attr_iter_object *attr_iter = pango_attr_iter_fetch_object(zobj);
    zend_object *return_value = pango_attr_iter_obj_ctor(zobj->ce, &new_attr_iter);

    if (attr_iter->attr_iter) {
        new_attr_iter->attr_iter = pango_attr_iterator_copy(attr_iter->attr_iter);
    }

    if (attr_iter->attr_list) {
        new_attr_iter->attr_list = pango_attr_list_copy(attr_iter->attr_list);
    }

    zend_objects_clone_members(&new_attr_iter->std, &attr_iter->std);

    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_attr_iter)
{
    memcpy(
        &pango_attr_iter_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_attr_iter_object_handlers.offset = offsetof(pango_attr_iter_object, std);
    pango_attr_iter_object_handlers.free_obj = pango_attr_iter_free_obj;
    pango_attr_iter_object_handlers.clone_obj = pango_attr_iter_clone_obj;

    pango_ce_pango_attr_iter = register_class_Pango_Attribute_AttributeIterator();
    pango_ce_pango_attr_iter->create_object = pango_attr_iter_create_object;

    return SUCCESS;
}
/* }}} */
