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
#include "font_family_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_font_family;

static zend_object_handlers pango_font_family_object_handlers;

pango_font_family_object *pango_font_family_fetch_object(zend_object *object)
{
    return (pango_font_family_object *) ((char*)(object) - XtOffsetOf(pango_font_family_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_family_ce()
{
    return pango_ce_pango_font_family;
}

PHP_PANGO_API PangoFontFamily* pango_font_family_object_get_font_family(zval *zv)
{
    pango_font_family_object *obj = Z_PANGO_FONT_FAMILY_P(zv);
    return obj->font_family;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
/* {{{ */
PHP_METHOD(Pango_FontFamily, getFace)
{
    char *name = NULL;
    size_t name_len = 0;
    PangoFontFamily *font_family;
    PangoFontFace *font_face;
    pango_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_STRING_OR_NULL(name, name_len);
    ZEND_PARSE_PARAMETERS_END();

    font_family = pango_font_family_object_get_font_family(getThis());
    font_face = pango_font_family_get_face(font_family, (const char*)name);
    if(!font_face) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_font_face_ce());
    font_face_object = Z_PANGO_FONT_FACE_P(return_value);
    font_face_object->font_face = g_object_ref(font_face);
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_FontFamily, getName)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING((char *)pango_font_family_get_name(
        pango_font_family_object_get_font_family(getThis())
    ));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontFamily, isMonospace)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_font_family_is_monospace(
        pango_font_family_object_get_font_family(getThis())
    ));
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
/* {{{ */
PHP_METHOD(Pango_FontFamily, isVariable)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_font_family_is_variable(
        pango_font_family_object_get_font_family(getThis())
    ));
}
/* }}} */
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/* {{{ */
PHP_METHOD(Pango_FontFamily, listFaces)
{
    PangoFontFace** faces;
    int num_faces;
    zval font_face_zv;
    pango_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_font_family_list_faces(
        pango_font_family_object_get_font_family(getThis()),
        &faces,
        &num_faces
    );

    array_init(return_value);
    for (int i = 0; i < num_faces; i++) {
        object_init_ex(&font_face_zv, php_pango_get_font_face_ce());
        font_face_object = Z_PANGO_FONT_FACE_P(&font_face_zv);
        font_face_object->font_face = g_object_ref(faces[i]);
        add_next_index_zval(return_value, &font_face_zv);
    }

    g_free(faces);
}
/* }}} */
#endif

/* ----------------------------------------------------------------
    \Pango\FontFamily Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_family_free_obj(zend_object *zobj)
{
    pango_font_family_object *intern = pango_font_family_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_family != NULL) {
        g_object_unref(intern->font_family);
        intern->font_family = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_family_obj_ctor(zend_class_entry *ce, pango_font_family_object **intern)
{
    pango_font_family_object *object = ecalloc(1, sizeof(pango_font_family_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_family_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_family_create_object(zend_class_entry *ce)
{
    pango_font_family_object *intern = NULL;
    zend_object *return_value = pango_font_family_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_family)
{
    memcpy(
        &pango_font_family_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_family_object_handlers.offset = XtOffsetOf(pango_font_family_object, std);
    pango_font_family_object_handlers.free_obj = pango_font_family_free_obj;

    pango_ce_pango_font_family = register_class_Pango_FontFamily();
    pango_ce_pango_font_family->create_object = pango_font_family_create_object;

    return SUCCESS;
}
/* }}} */
