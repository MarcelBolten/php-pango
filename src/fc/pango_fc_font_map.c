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

#include <php.h>
#include <pango/pangofc-fontmap.h>

#include "../../php_pango.h"
#include "../font_map.h"
#include "pango_fc.h"
#include "pango_fc_font_map_arginfo.h"

zend_class_entry *pango_ce_pango_fc_font_map;

static zend_object_handlers pango_fc_font_map_object_handlers;

pango_font_map_object *pango_fc_font_map_fetch_object(zend_object *object)
{
    return (pango_font_map_object *) ((char*)(object) - offsetof(pango_font_map_object, std));
}

PHP_PANGO_API zend_class_entry* php_pango_fc_get_font_map_ce()
{
    return pango_ce_pango_fc_font_map;
}

PHP_PANGO_API PangoFontMap* pango_fc_font_map_object_get_font_map(zval *zv)
{
    return Z_PANGO_FC_FONT_MAP_P(zv)->font_map;
}

/* {{{ */
PHP_METHOD(Pango_Fc_FontMap, clearCache)
{
    ZEND_PARSE_PARAMETERS_NONE();

    pango_fc_font_map_cache_clear(
        (PangoFcFontMap *) pango_fc_font_map_object_get_font_map(ZEND_THIS)
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Fc_FontMap, configChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    pango_fc_font_map_config_changed(
        (PangoFcFontMap *) pango_fc_font_map_object_get_font_map(ZEND_THIS)
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Fc_FontMap, shutdown)
{
    ZEND_PARSE_PARAMETERS_NONE();

    pango_fc_font_map_shutdown(
        (PangoFcFontMap *) pango_fc_font_map_object_get_font_map(ZEND_THIS)
    );
}
/* }}} */

/* {{{ */
PHP_METHOD(Pango_Fc_FontMap, substituteChanged)
{
    ZEND_PARSE_PARAMETERS_NONE();

    pango_fc_font_map_substitute_changed(
        (PangoFcFontMap *) pango_fc_font_map_object_get_font_map(ZEND_THIS)
    );
}
/* }}} */

/* ----------------------------------------------------------------
    \PangoFc\FontMap Object management
------------------------------------------------------------------*/

// /* {{{ */
// static void pango_fc_font_map_free_obj(zend_object *zobj)
// {
//     pango_font_map_object *intern = pango_fc_font_map_fetch_object(zobj);

//     if (!intern) {
//         return;
//     }

//     if (intern->font_map && !intern->is_default) {
//         g_object_unref(intern->font_map);
//     }

//     zend_object_std_dtor(&intern->std);
// }
// /* }}} */

// /* {{{ */
// static zend_object* pango_fc_font_map_obj_ctor(zend_class_entry *ce, pango_font_map_object **intern)
// {
//     pango_font_map_object *object = ecalloc(1, sizeof(pango_font_map_object) + zend_object_properties_size(ce));

//     zend_object_std_init(&object->std, ce);

//     object->std.handlers = &pango_fc_font_map_object_handlers;
//     *intern = object;

//     return &object->std;
// }
// /* }}} */

// /* {{{ */
// static zend_object* pango_fc_font_map_create_object(zend_class_entry *ce)
// {
//     pango_font_map_object *intern = NULL;
//     zend_object *return_value = pango_fc_font_map_obj_ctor(ce, &intern);

//     object_properties_init(&intern->std, ce);
//     return return_value;
// }
// /* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango_fc_font_map)
{
    memcpy(
        &pango_fc_font_map_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    pango_fc_font_map_object_handlers.offset = offsetof(pango_font_map_object, std);
    // pango_fc_font_map_object_handlers.free_obj = pango_fc_font_map_free_obj;

    pango_ce_pango_fc_font_map = register_class_Pango_Fc_FontMap(php_pango_get_font_map_ce());
    // pango_ce_pango_fc_font_map->create_object = pango_fc_font_map_create_object;

    return SUCCESS;
}
/* }}} */
