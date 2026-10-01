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

#include "../php_pango.h"
#include "script.h"
#include "script_iter_arginfo.h"

zend_class_entry *ce_pango_script_iter_range;

pango_script_iter_range_object *pango_script_iter_range_fetch_object(zend_object *object)
{
    return (pango_script_iter_range_object *) ((char*)(object) - offsetof(pango_script_iter_range_object, std));
}

/* ----------------------------------------------------------------
    \Pango\ScriptIterRange C API
------------------------------------------------------------------*/

zend_class_entry* php_pango_get_script_iter_range_ce()
{
    return ce_pango_script_iter_range;
}

/* ----------------------------------------------------------------
    \Pango\ScriptIterRange Class API
------------------------------------------------------------------*/
/* {{{  */
PHP_METHOD(Pango_ScriptIterRange, __construct)
{
    zend_string *text;
    size_t text_len;
    zend_long start;
    zend_long end;
    zval *script_zv;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_STR(text)
        Z_PARAM_LONG(start)
        Z_PARAM_LONG(end)
        Z_PARAM_OBJECT_OF_CLASS(script_zv, php_pango_get_script_ce())
    ZEND_PARSE_PARAMETERS_END();

    if (zend_str_has_nul_byte(text)) {
        zend_argument_value_error(1, "must not contain NUL bytes");
        RETURN_THROWS();
    }

    zend_update_property_str(Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "text", sizeof("text") - 1, text
    );
    zend_update_property_long(Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "byteStart", sizeof("byteStart") - 1, start
    );
    zend_update_property_long(Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "byteEnd", sizeof("byteEnd") - 1, end
    );
    zend_update_property(Z_OBJCE_P(ZEND_THIS), Z_OBJ_P(ZEND_THIS),
        "script", sizeof("script") - 1, script_zv
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \Pango\ScriptIterRange Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_script_iter_range)
{
    ce_pango_script_iter_range = register_class_Pango_ScriptIterRange();

    return SUCCESS;
}
/* }}} */
