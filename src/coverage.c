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
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>

#include "../php_pango.h"
#include "coverage.h"
#include "php_pango_macros.h"
#include "coverage_arginfo.h"

zend_class_entry *ce_pango_coverage;
zend_class_entry *ce_pango_coverage_level;

static zend_object_handlers pango_coverage_object_handlers;

pango_coverage_object *pango_coverage_fetch_object(zend_object *object)
{
    return (pango_coverage_object *) ((char*)(object) - offsetof(pango_coverage_object, std));
}

/* ----------------------------------------------------------------
    \Pango\Coverage C API
------------------------------------------------------------------*/

/* {{{ */
PHP_PANGO_API PangoCoverage *pango_coverage_object_get_coverage(zval *zv)
{
    pango_coverage_object *coverage_object = Z_PANGO_COVERAGE_P(zv);

    return (PangoCoverage *) coverage_object->coverage;
}
/* }}} */

zend_class_entry* php_pango_get_coverage_ce()
{
    return ce_pango_coverage;
}

zend_class_entry* php_pango_get_coverage_level_ce()
{
    return ce_pango_coverage_level;
}

/* ----------------------------------------------------------------
    \Pango\Coverage Class API
------------------------------------------------------------------*/

/* {{{ Create a new Coverage object initialized to CoverageLevel::None. */
PHP_METHOD(Pango_Coverage, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();

    Z_PANGO_COVERAGE_P(ZEND_THIS)->coverage = pango_coverage_new();
}
/* }}} */

/* {{{ Determine whether a particular index is covered by coverage. */
PHP_METHOD(Pango_Coverage, get)
{
    zend_long index;
    zend_object *coverage_level_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    zend_enum_get_case_by_value(
        &coverage_level_case, ce_pango_coverage_level,
        pango_coverage_get(Z_PANGO_COVERAGE_P(ZEND_THIS)->coverage, index),
        NULL, false
    );

    RETURN_OBJ_COPY(coverage_level_case);
}
/* }}} */

/* {{{ Modify a particular index within coverage. */
PHP_METHOD(Pango_Coverage, set)
{
    zend_long index;
    zend_object *coverage_level_case;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(index)
        Z_PARAM_OBJ_OF_CLASS(coverage_level_case, ce_pango_coverage_level)
    ZEND_PARSE_PARAMETERS_END();

    pango_coverage_set(
        pango_coverage_object_get_coverage(ZEND_THIS),
        index,
        Z_LVAL_P(zend_enum_fetch_case_value(coverage_level_case))
    );

    RETURN_OBJ_COPY(Z_OBJ_P(ZEND_THIS));
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Coverage Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_coverage_free_obj(zend_object *object)
{
    pango_coverage_object *intern = pango_coverage_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->coverage) {
        g_object_unref(intern->coverage);
        intern->coverage = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* pango_coverage_obj_ctor(zend_class_entry *ce, pango_coverage_object **intern)
{
    pango_coverage_object *object = ecalloc(1, sizeof(pango_coverage_object) + zend_object_properties_size(ce));

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_coverage_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_coverage_create_object(zend_class_entry *ce)
{
    pango_coverage_object *intern = NULL;
    zend_object *return_value = pango_coverage_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* pango_coverage_clone_obj(zend_object *zobj)
{
    pango_coverage_object *new_coverage;
    pango_coverage_object *old_coverage = pango_coverage_fetch_object(zobj);
    zend_object *return_value = pango_coverage_obj_ctor(zobj->ce, &new_coverage);

    if (old_coverage->coverage) {
        new_coverage->coverage = pango_coverage_copy(old_coverage->coverage);
    }

    zend_objects_clone_members(&new_coverage->std, &old_coverage->std);

    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Coverage Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_coverage)
{
    memcpy(
        &pango_coverage_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_coverage_object_handlers.offset = offsetof(pango_coverage_object, std);
    pango_coverage_object_handlers.free_obj = pango_coverage_free_obj;
    pango_coverage_object_handlers.clone_obj = pango_coverage_clone_obj;
    pango_coverage_object_handlers.get_property_ptr_ptr = NULL;

    ce_pango_coverage = register_class_Pango_Coverage();
    ce_pango_coverage->create_object = pango_coverage_create_object;

    ce_pango_coverage_level = register_class_Pango_CoverageLevel();

    return SUCCESS;
}
/* }}} */
