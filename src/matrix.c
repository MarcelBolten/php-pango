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

#include "php.h"
#include <zend_exceptions.h>
#include <zend_gc.h>

#include "php_pango.h"
#include "matrix_arginfo.h"

zend_class_entry *ce_pango_matrix;
static zend_object_handlers pango_matrix_object_handlers;

pango_matrix_object *pango_matrix_fetch_object(zend_object *object)
{
    return (pango_matrix_object *) ((char*)(object) - XtOffsetOf(pango_matrix_object, std));
}

static inline double pango_matrix_get_property_default(zend_class_entry *ce, char * name) {
    zend_property_info *property_info;
    double value = 0.0;
    zend_string *key = zend_string_init(name, strlen(name), 0);

    property_info = zend_get_property_info(ce, key, 1);
    if (property_info) {
        zval *val = (zval*)((char*)ce->default_properties_table + property_info->offset - OBJ_PROP_TO_OFFSET(0));
        if (val) {
            value = zval_get_double(val);
        }
    }
    zend_string_release(key);
    return value;
}

static inline double pango_matrix_get_property_value(zend_object *object, char *name) {
    zval *prop, rv;

    prop = zend_read_property(object->ce, object, name, strlen(name), 1, &rv);
    return zval_get_double(prop);
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

#define PANGO_VALUE_TO_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        matrix_object->matrix->n = zval_get_double(value); \
        break; \
    }

#define PANGO_ADD_STRUCT_VALUE(n) \
    ZVAL_DOUBLE(&tmp, matrix_object->matrix->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp);

/* ----------------------------------------------------------------
    Pango\Matrix C API
------------------------------------------------------------------*/

/* {{{ */
PangoMatrix *pango_matrix_object_get_matrix(zval *zv)
{
    pango_matrix_object *matrix_object = Z_PANGO_MATRIX_P(zv);

    return matrix_object->matrix;
}
/* }}} */

zend_class_entry* php_pango_get_matrix_ce()
{
    return ce_pango_matrix;
}

/* ----------------------------------------------------------------
    Pango\Matrix Class API
------------------------------------------------------------------*/

/* {{{ Matrix specifies a transformation between user-space and device coordinates */
PHP_METHOD(Pango_Matrix, __construct)
{
    pango_matrix_object *matrix_object;
    zend_object *object = Z_OBJ_P(getThis());

    /* read defaults from object */
    double xx = pango_matrix_get_property_value(object, "xx");
    double yx = pango_matrix_get_property_value(object, "yx");
    double xy = pango_matrix_get_property_value(object, "xy");
    double yy = pango_matrix_get_property_value(object, "yy");
    double x0 = pango_matrix_get_property_value(object, "x0");
    double y0 = pango_matrix_get_property_value(object, "y0");

    ZEND_PARSE_PARAMETERS_START(0, 6)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(xx)
        Z_PARAM_DOUBLE(yx)
        Z_PARAM_DOUBLE(xy)
        Z_PARAM_DOUBLE(yy)
        Z_PARAM_DOUBLE(x0)
        Z_PARAM_DOUBLE(y0)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = pango_matrix_fetch_object(object);

    matrix_object->matrix->xx = xx;
    matrix_object->matrix->yx = yx;
    matrix_object->matrix->xy = xy;
    matrix_object->matrix->yy = yy;
    matrix_object->matrix->x0 = x0;
    matrix_object->matrix->y0 = y0;
}
/* }}} */

/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first translating by (tx, ty) then applying the original transformation. */
PHP_METHOD(Pango_Matrix, translate)
{
    double tx = 0.0, ty = 0.0;
    pango_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(tx)
        Z_PARAM_DOUBLE(ty)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = Z_PANGO_MATRIX_P(getThis());

    pango_matrix_translate(matrix_object->matrix, tx, ty);
}
/* }}} */

/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first scaling by sx in the X direction and sy in the Y direction
       then applying the original transformation. */
PHP_METHOD(Pango_Matrix, scale)
{
    double sx = 0.0, sy = 0.0;
    pango_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(sx)
        Z_PARAM_DOUBLE(sy)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = Z_PANGO_MATRIX_P(getThis());

    pango_matrix_scale(matrix_object->matrix, sx, sy);
}
/* }}} */

/* {{{ Changes the transformation represented by matrix to be the transformation
       given by first rotating by degrees degrees counter-clockwise
       then applying the original transformation. */
PHP_METHOD(Pango_Matrix, rotate)
{
    double degrees = 0.0;
    pango_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degrees)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = Z_PANGO_MATRIX_P(getThis());

    pango_matrix_rotate(matrix_object->matrix, degrees);
}
/* }}} */


/* {{{ Transforms the distance vector (dx,dy) by matrix.
       This is similar to pango_matrix_transform_point(), except that
       the translation components of the transformation are ignored. */
PHP_METHOD(Pango_Matrix, transformDistance)
{
    double dx = 0.0, dy = 0.0;
    pango_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(dx)
        Z_PARAM_DOUBLE(dy)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = Z_PANGO_MATRIX_P(getThis());

    pango_matrix_transform_distance(matrix_object->matrix, &dx, &dy);

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
        pango_matrix_object_get_matrix(getThis()),
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
    pango_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = Z_PANGO_MATRIX_P(getThis());

    pango_matrix_transform_point(matrix_object->matrix, &x, &y);

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
        pango_matrix_object_get_matrix(getThis()),
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

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &pango_matrix_object_handlers;
    *intern = object;

    /* We need to read in any default values and set them if applicable
       xx, yx, xy, yy, x0, y0
     */
    if (ce->default_properties_count) {
        object->matrix->xx = pango_matrix_get_property_default(ce, "xx");
        object->matrix->yx = pango_matrix_get_property_default(ce, "yx");
        object->matrix->xy = pango_matrix_get_property_default(ce, "xy");
        object->matrix->yy = pango_matrix_get_property_default(ce, "yy");
        object->matrix->x0 = pango_matrix_get_property_default(ce, "x0");
        object->matrix->y0 = pango_matrix_get_property_default(ce, "y0");
    }

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
    new_matrix->matrix->xx = old_matrix->matrix->xx;
    new_matrix->matrix->yx = old_matrix->matrix->yx;
    new_matrix->matrix->xy = old_matrix->matrix->xy;
    new_matrix->matrix->yy = old_matrix->matrix->yy;
    new_matrix->matrix->x0 = old_matrix->matrix->x0;
    new_matrix->matrix->y0 = old_matrix->matrix->y0;

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
static zval *pango_matrix_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    pango_matrix_object *matrix_object = pango_matrix_fetch_object(object);
    zval *retval = NULL;

    if (!matrix_object) {
        return retval;
    }

    do {
        PANGO_VALUE_TO_STRUCT(xx);
        PANGO_VALUE_TO_STRUCT(yx);
        PANGO_VALUE_TO_STRUCT(xy);
        PANGO_VALUE_TO_STRUCT(yy);
        PANGO_VALUE_TO_STRUCT(x0);
        PANGO_VALUE_TO_STRUCT(y0);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);
    } while(0);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *pango_matrix_object_get_properties(zend_object *object)
{
    HashTable *props;
    // used in PANGO_ADD_STRUCT_VALUE below
    zval tmp;
    pango_matrix_object *matrix_object = pango_matrix_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!matrix_object->matrix) {
        return props;
    }

    /* Don't add struct values when destructor calls get_properties handler */
    if (props && GC_REFCOUNT(props) > 0) {
        PANGO_ADD_STRUCT_VALUE(xx);
        PANGO_ADD_STRUCT_VALUE(yx);
        PANGO_ADD_STRUCT_VALUE(xy);
        PANGO_ADD_STRUCT_VALUE(yy);
        PANGO_ADD_STRUCT_VALUE(x0);
        PANGO_ADD_STRUCT_VALUE(y0);
    }

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

    pango_matrix_object_handlers.offset = XtOffsetOf(pango_matrix_object, std);
    pango_matrix_object_handlers.free_obj = pango_matrix_free_obj;
    pango_matrix_object_handlers.clone_obj = pango_matrix_clone_obj;
    pango_matrix_object_handlers.read_property = pango_matrix_object_read_property;
    pango_matrix_object_handlers.write_property = pango_matrix_object_write_property;
    pango_matrix_object_handlers.get_property_ptr_ptr = NULL;
    pango_matrix_object_handlers.get_properties = pango_matrix_object_get_properties;

    ce_pango_matrix = register_class_Pango_Matrix();
    ce_pango_matrix->create_object = pango_matrix_create_object;

    return SUCCESS;
}
/* }}} */
