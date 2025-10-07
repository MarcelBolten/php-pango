/*
  +----------------------------------------------------------------------+
  | PHP Version 8                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2008 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:  Michael Maclean <mgdm@php.net>                              |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_pango.h"
#include "context_arginfo.h"

zend_class_entry *pango_ce_pango_context;
zend_class_entry *pango_ce_pango_direction;
zend_class_entry *pango_ce_pango_gravity;
zend_class_entry *pango_ce_pango_gravity_hint;

PHP_PANGO_API zend_class_entry* php_pango_get_context_ce() {
    return pango_ce_pango_context;
}

PHP_PANGO_API zend_class_entry* php_pango_get_direction_ce() {
    return pango_ce_pango_direction;
}

static zend_object_handlers pango_context_object_handlers;

pango_context_object *pango_context_fetch_object(zend_object *object)
{
    return (pango_context_object *) ((char*)(object) - XtOffsetOf(pango_context_object, std));
}


/* {{{ Sets the base gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, setBaseGravity)
{
    pango_context_object *context_object;
    zend_object *base_gravity;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(base_gravity, pango_ce_pango_gravity)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_base_gravity(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(base_gravity))
    );
}
/* }}} */

/* {{{ Gets the base gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, getBaseGravity)
{
    pango_context_object *context_object;
    zend_object *base_gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &base_gravity_case, pango_ce_pango_gravity,
        pango_context_get_base_gravity(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(base_gravity_case);
}
/* }}} */

/* {{{ Gets the gravity to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravity)
{
    pango_context_object *context_object;
    zend_object *gravity_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &gravity_case, pango_ce_pango_gravity,
        pango_context_get_gravity(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_case);
}
/* }}} */

/* {{{ Sets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, setGravityHint)
{
    pango_context_object *context_object;
    zend_object *gravity_hint;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(gravity_hint, pango_ce_pango_gravity_hint)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_PANGO_CONTEXT_P(getThis());
    pango_context_set_gravity_hint(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(gravity_hint))
    );
}
/* }}} */

/* {{{ Gets the gravity hint to be used to lay out the text */
PHP_METHOD(Pango_Context, getGravityHint)
{
    pango_context_object *context_object;
    zend_object *gravity_hint_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = Z_PANGO_CONTEXT_P(getThis());

    zend_enum_get_case_by_value(
        &gravity_hint_case, pango_ce_pango_gravity_hint,
        pango_context_get_gravity_hint(context_object->context),
        NULL, false
    );

    RETURN_OBJ_COPY(gravity_hint_case);
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\Context Object management
------------------------------------------------------------------*/

/* {{{ */
static void pango_context_free_obj(zend_object *zobj)
{
    pango_context_object *intern = pango_context_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->context) {
        g_object_unref(intern->context);
    }

    zend_object_std_dtor(&intern->std);
}

/* {{{ */
static zend_object* pango_context_obj_ctor(zend_class_entry *ce, pango_context_object **intern)
{
    pango_context_object *object = ecalloc(1, sizeof(pango_context_object) + zend_object_properties_size(ce));

    object->context = NULL;

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &pango_context_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* pango_context_create_object(zend_class_entry *ce)
{
    pango_context_object *intern = NULL;
    zend_object *return_value = pango_context_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_context)
{
    memcpy(
        &pango_context_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_context_object_handlers.offset = XtOffsetOf(pango_context_object, std);
    pango_context_object_handlers.free_obj = pango_context_free_obj;

    pango_ce_pango_context = register_class_Pango_Context();
    pango_ce_pango_context->create_object = pango_context_create_object;

    pango_ce_pango_gravity = register_class_Pango_Gravity();
    pango_ce_pango_gravity_hint = register_class_Pango_GravityHint();
    pango_ce_pango_direction = register_class_Pango_Direction();

    return SUCCESS;
}
/* }}} */
