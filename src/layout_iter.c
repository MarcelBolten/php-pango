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
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "rectangle.h"
#include "layout_line.h"
#include "glyph_item.h"
#include "layout_iter.h"
#include "layout_iter_arginfo.h"

zend_class_entry *pango_ce_pango_layout_iter;

static zend_object_handlers pango_layout_iter_object_handlers;

PHP_PANGO_API zend_class_entry* php_pango_get_layout_iter_ce(void) {
    return pango_ce_pango_layout_iter;
}

pango_layout_iter_object *pango_layout_iter_fetch_object(zend_object *object)
{
    return (pango_layout_iter_object *) ((char*)(object) - offsetof(pango_layout_iter_object, std));
}

PHP_PANGO_API PangoLayoutIter *pango_layout_iter_object_get_layout_iter(zval *zv)
{
    return Z_PANGO_LAYOUT_ITER_P(zv)->layout_iter;
}

#define PANGO_LAYOUT_ITER_GET_EXTENTS(extents_getter) \
    PangoRectangle ink_rect; \
    zval ink_rect_zv; \
    PangoRectangle logical_rect; \
    zval logical_rect_zv; \
\
    ZEND_PARSE_PARAMETERS_NONE(); \
\
    extents_getter( \
        pango_layout_iter_object_get_layout_iter(ZEND_THIS), \
        &ink_rect, \
        &logical_rect \
    ); \
\
    object_init_ex(&ink_rect_zv, php_pango_get_rectangle_ce()); \
    *pango_rectangle_object_get_rectangle(&ink_rect_zv) = ink_rect; \
\
    object_init_ex(&logical_rect_zv, php_pango_get_rectangle_ce()); \
    *pango_rectangle_object_get_rectangle(&logical_rect_zv) = logical_rect; \
\
    array_init(return_value); \
    add_assoc_zval(return_value, "ink", &ink_rect_zv); \
    add_assoc_zval(return_value, "logical", &logical_rect_zv); \

/* {{{ */
PHP_METHOD(Pango_LayoutIter, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, atLastLine)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_iter_at_last_line(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getBaseline)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_iter_get_baseline(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getCharExtents)
{
    PangoRectangle logical_rect;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_iter_get_char_extents(
        pango_layout_iter_object_get_layout_iter(ZEND_THIS),
         &logical_rect
    );

    object_init_ex(return_value, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(return_value) = logical_rect;
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getIndex)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_iter_get_index(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getClusterExtents)
{
    PANGO_LAYOUT_ITER_GET_EXTENTS(pango_layout_iter_get_cluster_extents);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getLayout)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_OBJ_COPY(Z_OBJ(Z_PANGO_LAYOUT_ITER_P(ZEND_THIS)->layout_zv));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getLayoutExtents)
{
    PANGO_LAYOUT_ITER_GET_EXTENTS(pango_layout_iter_get_layout_extents);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getLine)
{
    pango_layout_line_object *layout_line_object;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, php_pango_get_layout_line_ce());
    layout_line_object = Z_PANGO_LAYOUT_LINE_P(return_value);
    layout_line_object->line = pango_layout_line_ref(
        pango_layout_iter_get_line(pango_layout_iter_object_get_layout_iter(ZEND_THIS))
    );

    ZVAL_COPY(&layout_line_object->layout_zval, &Z_PANGO_LAYOUT_ITER_P(ZEND_THIS)->layout_zv);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getLineExtents)
{
    PANGO_LAYOUT_ITER_GET_EXTENTS(pango_layout_iter_get_line_extents);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getLineYrange)
{
    int y0, y1;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_layout_iter_get_line_yrange (
        pango_layout_iter_object_get_layout_iter(ZEND_THIS),
        &y0,
        &y1
    );

    array_init(return_value);
    add_assoc_long(return_value, "y0", y0);
    add_assoc_long(return_value, "y1", y1);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getRun)
{
    pango_glyph_item_object *glyph_item_obj;
    PangoLayoutRun *run = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    run = pango_layout_iter_get_run(pango_layout_iter_object_get_layout_iter(ZEND_THIS));

    if (!run) {
        RETURN_NULL();
    }

    object_init_ex(return_value, php_pango_get_glyph_item_ce());
    glyph_item_obj = Z_PANGO_GLYPH_ITEM_P(return_value);
    glyph_item_obj->glyph_item = pango_glyph_item_copy(run);
    // TODO: might need to also copy glyph_item_obj->layout_line_zv
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getRunBaseline)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_layout_iter_get_run_baseline(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, getRunExtents)
{
    PANGO_LAYOUT_ITER_GET_EXTENTS(pango_layout_iter_get_run_extents);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, nextChar)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_iter_next_char(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, nextCluster)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_iter_next_cluster(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, nextLine)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_iter_next_line(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_LayoutIter, nextRun)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_BOOL(pango_layout_iter_next_run(pango_layout_iter_object_get_layout_iter(ZEND_THIS)));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Layout Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_layout_iter_free_obj(zend_object *zobj)
{
    pango_layout_iter_object *intern = pango_layout_iter_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->layout_iter) {
        pango_layout_iter_free(intern->layout_iter);
        intern->layout_iter = NULL;
    }

    zval_ptr_dtor(&intern->layout_zv);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_iter_obj_ctor(zend_class_entry *ce, pango_layout_iter_object **intern)
{
    pango_layout_iter_object *object = ecalloc(1, sizeof(pango_layout_iter_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->layout_zv);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_layout_iter_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_iter_create_object(zend_class_entry *ce)
{
    pango_layout_iter_object *intern = NULL;
    zend_object *return_value = pango_layout_iter_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_layout_iter_clone_obj(zend_object *zobj)
{
    pango_layout_iter_object *new_layout_iter;
    pango_layout_iter_object *layout_iter = pango_layout_iter_fetch_object(zobj);
    zend_object *return_value = pango_layout_iter_obj_ctor(zobj->ce, &new_layout_iter);

    if (layout_iter->layout_iter) {
        new_layout_iter->layout_iter = pango_layout_iter_copy(layout_iter->layout_iter);
    }

    if (&layout_iter->layout_zv) {
        ZVAL_COPY(&new_layout_iter->layout_zv, &layout_iter->layout_zv);
    }

    zend_objects_clone_members(&new_layout_iter->std, &layout_iter->std);

    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_layout_iter)
{
    memcpy(
        &pango_layout_iter_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_layout_iter_object_handlers.offset = offsetof(pango_layout_iter_object, std);
    pango_layout_iter_object_handlers.free_obj = pango_layout_iter_free_obj;
    pango_layout_iter_object_handlers.clone_obj = pango_layout_iter_clone_obj;

    pango_ce_pango_layout_iter = register_class_Pango_LayoutIter();
    pango_ce_pango_layout_iter->create_object = pango_layout_iter_create_object;

    return SUCCESS;
}
/* }}} */
