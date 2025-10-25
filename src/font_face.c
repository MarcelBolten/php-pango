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
#include "font_face_arginfo.h"

#include <string.h>
#include "zend_exceptions.h"

zend_class_entry *pango_ce_pango_font_face;

static zend_object_handlers pango_font_face_object_handlers;

pango_font_face_object *pango_font_face_fetch_object(zend_object *object)
{
    return (pango_font_face_object *) ((char*)(object) - XtOffsetOf(pango_font_face_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_get_font_face_ce()
{
    return pango_ce_pango_font_face;
}

PHP_PANGO_API PangoFontFace* pango_font_face_object_get_font_face(zval *zv)
{
    pango_font_face_object *obj = Z_PANGO_FONT_FACE_P(zv);
    return obj->font_face;
}

/* {{{ */
PHP_METHOD(Pango_FontFace, describe)
{
    PangoFontDescription *font_desc;
    pango_font_description_object *font_description_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_desc = pango_font_face_describe(
        pango_font_face_object_get_font_face(getThis())
    );

    object_init_ex(return_value, php_pango_get_font_description_ce());
    font_description_object = Z_PANGO_FONT_DESC_P(return_value);
    font_description_object->font_description = font_desc;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontFace, getName)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING((char *)pango_font_face_get_face_name(
        pango_font_face_object_get_font_face(getThis())
    ));
}
/* }}} */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
/* {{{ */
PHP_METHOD(Pango_FontFace, getFamily)
{
    PangoFontFamily *font_family;
    pango_font_family_object *font_family_object;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, php_pango_get_font_family_ce());
    font_family_object = Z_PANGO_FONT_FAMILY_P(return_value);
    font_family_object->font_family = g_object_ref(pango_font_face_get_family(
        pango_font_face_object_get_font_face(getThis()))
    );
}
/* }}} */
#endif

/* {{{ */
PHP_METHOD(Pango_FontFace, isSynthesized)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_font_face_is_synthesized(
        pango_font_face_object_get_font_face(getThis())
    ));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_FontFace, listSizes)
{
    int* sizes;
    int num_sizes;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_font_face_list_sizes(
        pango_font_face_object_get_font_face(getThis()),
        &sizes,
        &num_sizes
    );

    array_init(return_value);
    for (int i = 0; i < num_sizes; i++) {
        add_next_index_long(return_value, sizes[i]);
    }

    g_free(sizes);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\FontFace Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_font_face_free_obj(zend_object *zobj)
{
    pango_font_face_object *intern = pango_font_face_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->font_face != NULL) {
        intern->font_face = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_font_face_obj_ctor(zend_class_entry *ce, pango_font_face_object **intern)
{
    pango_font_face_object *object = ecalloc(1, sizeof(pango_font_face_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_font_face_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_font_face_create_object(zend_class_entry *ce)
{
    pango_font_face_object *intern = NULL;
    zend_object *return_value = pango_font_face_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_font_face)
{
    memcpy(
        &pango_font_face_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_font_face_object_handlers.offset = XtOffsetOf(pango_font_face_object, std);
    pango_font_face_object_handlers.free_obj = pango_font_face_free_obj;

    pango_ce_pango_font_face = register_class_Pango_FontFace();
    pango_ce_pango_font_face->create_object = pango_font_face_create_object;

    return SUCCESS;
}
/* }}} */
