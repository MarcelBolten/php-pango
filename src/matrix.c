/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Elizabeth M Smith                                 |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  +----------------------------------------------------------------------+
  | Authors: Elizabeth M Smith <auroraeosrose@gmail.com>                 |
  |          Swen Zanon <swen.zanon@geoglis.de>                          |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_gc.h>

#include "../php_pango.h"
#include "php_pango_macros.h"
#include "context.h"
#include "rectangle.h"
#include "matrix.h"
#include "matrix_arginfo.h"

zend_class_entry *ce_pango_matrix;
static zend_object_handlers pango_matrix_object_handlers;

pango_matrix_object *pango_matrix_fetch_object(zend_object *object)
{
    return (pango_matrix_object *) ((char*)(object) - offsetof(pango_matrix_object, std));
}

static inline void pango_matrix_update_properties(zval *zv) {
    PangoMatrix *matrix = Z_PANGO_MATRIX_P(zv)->matrix;

    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "xx", sizeof("xx")-1, matrix->xx);
    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "yx", sizeof("yx")-1, matrix->yx);
    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "xy", sizeof("xy")-1, matrix->xy);
    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "yy", sizeof("yy")-1, matrix->yy);
    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "x0", sizeof("x0")-1, matrix->x0);
    zend_update_property_double(ce_pango_matrix, Z_OBJ_P(zv), "y0", sizeof("y0")-1, matrix->y0);
}

#define PANGO_ALLOC_MATRIX(matrix_value) \
    if (!matrix_value) { \
        matrix_value = ecalloc(1, sizeof(PangoMatrix)); \
    }

#define PANGO_VALUE_FROM_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        value = matrix_object->matrix->n; \
        break; \
    }

#define PANGO_ADD_STRUCT_VALUE(n) \
    ZVAL_DOUBLE(&tmp, matrix_object->matrix->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp);

/* ----------------------------------------------------------------
    Pango\Matrix C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoMatrix *pango_matrix_object_get_matrix(zval *zv)
{
    return Z_PANGO_MATRIX_P(zv)->matrix;
}
/* }}} */

zend_class_entry* php_pango_get_matrix_ce(void)
{
    return ce_pango_matrix;
}

/* ----------------------------------------------------------------
    Pango\Matrix Class API
------------------------------------------------------------------*/

/* {{{ Matrix specifies a transformation between user-space and device coordinates */
PHP_METHOD(Pango_Matrix, __construct)
{
    double xx = 1.0;
    double yx = 0.0;
    double xy = 0.0;
    double yy = 1.0;
    double x0 = 0.0;
    double y0 = 0.0;
    PangoMatrix *pango_matrix;

    ZEND_PARSE_PARAMETERS_START(0, 6)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(xx)
        Z_PARAM_DOUBLE(yx)
        Z_PARAM_DOUBLE(xy)
        Z_PARAM_DOUBLE(yy)
        Z_PARAM_DOUBLE(x0)
        Z_PARAM_DOUBLE(y0)
    ZEND_PARSE_PARAMETERS_END();

    pango_matrix = Z_PANGO_MATRIX_P(ZEND_THIS)->matrix;

    pango_matrix->xx = xx;
    pango_matrix->yx = yx;
    pango_matrix->xy = xy;
    pango_matrix->yy = yy;
    pango_matrix->x0 = x0;
    pango_matrix->y0 = y0;

    pango_matrix_update_properties(ZEND_THIS);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, concat)
{
    zval *newMatrix;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(newMatrix, ce_pango_matrix)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_pango_matrix);
    *Z_PANGO_MATRIX_P(return_value)->matrix = *Z_PANGO_MATRIX_P(ZEND_THIS)->matrix;

    pango_matrix_concat(Z_PANGO_MATRIX_P(return_value)->matrix, Z_PANGO_MATRIX_P(newMatrix)->matrix);
    pango_matrix_update_properties(return_value);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, getFontScaleFactor)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_DOUBLE(pango_matrix_get_font_scale_factor(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, getFontScaleFactors)
{
    double x, y;

    ZEND_PARSE_PARAMETERS_NONE();

    pango_matrix_get_font_scale_factors(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix, &x, &y);

    array_init_size(return_value, 2);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, getSlantRatio)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_DOUBLE(pango_matrix_get_slant_ratio(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix));
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, getGravity)
{
    zend_object *gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    zend_enum_get_case_by_value(
        &gravity_case, php_pango_get_gravity_ce(),
        pango_gravity_get_for_matrix(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_case);
}
/* }}} */


/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first translating by (tx, ty) then applying the original transformation. */
PHP_METHOD(Pango_Matrix, translate)
{
    double tx = 0.0, ty = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(tx)
        Z_PARAM_DOUBLE(ty)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_pango_matrix);
    *Z_PANGO_MATRIX_P(return_value)->matrix = *Z_PANGO_MATRIX_P(ZEND_THIS)->matrix;

    pango_matrix_translate(Z_PANGO_MATRIX_P(return_value)->matrix, tx, ty);
    pango_matrix_update_properties(return_value);
}
/* }}} */

/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first scaling by sx in the X direction and sy in the Y direction
       then applying the original transformation. */
PHP_METHOD(Pango_Matrix, scale)
{
    double sx = 0.0, sy = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(sx)
        Z_PARAM_DOUBLE(sy)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_pango_matrix);
    *Z_PANGO_MATRIX_P(return_value)->matrix = *Z_PANGO_MATRIX_P(ZEND_THIS)->matrix;

    pango_matrix_scale(Z_PANGO_MATRIX_P(return_value)->matrix, sx, sy);
    pango_matrix_update_properties(return_value);
}
/* }}} */

/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first rotating by degrees degrees counter-clockwise
       then applying the original transformation. */
PHP_METHOD(Pango_Matrix, rotate)
{
    double degrees = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degrees)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_pango_matrix);
    *Z_PANGO_MATRIX_P(return_value)->matrix = *Z_PANGO_MATRIX_P(ZEND_THIS)->matrix;

    pango_matrix_rotate(Z_PANGO_MATRIX_P(return_value)->matrix, degrees);
    pango_matrix_update_properties(return_value);
}
/* }}} */

/* {{{ Transforms the distance vector (dx,dy) by matrix.
       This is similar to pango_matrix_transform_point(), except that
       the translation components of the transformation are ignored. */
PHP_METHOD(Pango_Matrix, transformDistance)
{
    double dx = 0.0, dy = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(dx)
        Z_PARAM_DOUBLE(dy)
    ZEND_PARSE_PARAMETERS_END();

    pango_matrix_transform_distance(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix, &dx, &dy);

    array_init(return_value);
    add_assoc_double(return_value, "x", dx);
    add_assoc_double(return_value, "y", dy);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, transformPixelRectangle)
{
    zval *rectangle_zv;
    PangoRectangle rect;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(rectangle_zv, php_pango_get_rectangle_ce())
    ZEND_PARSE_PARAMETERS_END();

    rect = *pango_rectangle_object_get_rectangle(rectangle_zv);

    pango_matrix_transform_pixel_rectangle(
        pango_matrix_object_get_matrix(ZEND_THIS),
        &rect
    );

    object_init_ex(return_value, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(return_value) = rect;
}
/* }}} */

/* {{{ Transforms the point (x, y) by matrix. */
PHP_METHOD(Pango_Matrix, transformPoint)
{
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    pango_matrix_transform_point(Z_PANGO_MATRIX_P(ZEND_THIS)->matrix, &x, &y);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Matrix, transformRectangle)
{
    zval *rectangle_zv;
    PangoRectangle rect;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(rectangle_zv, php_pango_get_rectangle_ce())
    ZEND_PARSE_PARAMETERS_END();

    rect = *pango_rectangle_object_get_rectangle(rectangle_zv);

    pango_matrix_transform_rectangle(
        pango_matrix_object_get_matrix(ZEND_THIS),
        &rect
    );

    object_init_ex(return_value, php_pango_get_rectangle_ce());
    *pango_rectangle_object_get_rectangle(return_value) = rect;
}
/* }}} */

/* ----------------------------------------------------------------
    Pango\Matrix Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_matrix_free_obj(zend_object *object)
{
    pango_matrix_object *intern = pango_matrix_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->matrix) {
        efree(intern->matrix);
        intern->matrix = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_matrix_obj_ctor(zend_class_entry *ce, pango_matrix_object **intern)
{
    pango_matrix_object *object = ecalloc(1, sizeof(pango_matrix_object) + zend_object_properties_size(ce));
    PANGO_ALLOC_MATRIX(object->matrix);

    *object->matrix = (PangoMatrix){1.0, 0.0, 0.0, 1.0, 0.0, 0.0};

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &pango_matrix_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_matrix_create_object(zend_class_entry *ce)
{
    pango_matrix_object *intern = NULL;
    zend_object *return_value = pango_matrix_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_matrix_clone_obj(zend_object *zobj)
{
    pango_matrix_object *new_matrix;
    pango_matrix_object *old_matrix = pango_matrix_fetch_object(zobj);
    zend_object *return_value = pango_matrix_obj_ctor(zobj->ce, &new_matrix);
    PANGO_ALLOC_MATRIX(new_matrix->matrix);

    // init new matrix values from old matrix
    *new_matrix->matrix = *old_matrix->matrix;

    zend_objects_clone_members(&new_matrix->std, &old_matrix->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *pango_matrix_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zval *retval;
    double value;
    pango_matrix_object *matrix_object = pango_matrix_fetch_object(object);

    if (!matrix_object) {
        return rv;
    }

    do {
        PANGO_VALUE_FROM_STRUCT(xx);
        PANGO_VALUE_FROM_STRUCT(yx);
        PANGO_VALUE_FROM_STRUCT(xy);
        PANGO_VALUE_FROM_STRUCT(yy);
        PANGO_VALUE_FROM_STRUCT(x0);
        PANGO_VALUE_FROM_STRUCT(y0);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->read_property(object, member, type, cache_slot, rv);

        return retval;
    } while(0);

    retval = rv;
    ZVAL_DOUBLE(retval, value);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *pango_matrix_object_get_properties_for(zend_object *object, zend_prop_purpose purpose)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_matrix_object *matrix_object = pango_matrix_fetch_object(object);

    props = zend_array_dup(zend_std_get_properties(object));

    if (!matrix_object->matrix) {
        return props;
    }

    PANGO_ADD_STRUCT_VALUE(xx);
    PANGO_ADD_STRUCT_VALUE(yx);
    PANGO_ADD_STRUCT_VALUE(xy);
    PANGO_ADD_STRUCT_VALUE(yy);
    PANGO_ADD_STRUCT_VALUE(x0);
    PANGO_ADD_STRUCT_VALUE(y0);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    Pango\Matrix Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_matrix)
{
    memcpy(
        &pango_matrix_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_matrix_object_handlers.offset = offsetof(pango_matrix_object, std);
    pango_matrix_object_handlers.free_obj = pango_matrix_free_obj;
    pango_matrix_object_handlers.clone_obj = pango_matrix_clone_obj;
    pango_matrix_object_handlers.read_property = pango_matrix_object_read_property;
    pango_matrix_object_handlers.get_property_ptr_ptr = NULL;
    pango_matrix_object_handlers.get_properties_for = pango_matrix_object_get_properties_for;

    ce_pango_matrix = register_class_Pango_Matrix();
    ce_pango_matrix->create_object = pango_matrix_create_object;

    return SUCCESS;
}
/* }}} */
