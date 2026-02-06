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
  | Authors: Michael Maclean <mgdm@php.net>                              |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "php_pango.h"
#include "pango_arginfo.h"

zend_class_entry *pango_ce_pango;
zend_object_handlers pango_std_object_handlers;

/* {{{ returns the Pango version */
ZEND_METHOD(Pango_Pango, version)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(pango_version());
}
/* }}} */

/* {{{ returns the Pango version as a string */
ZEND_METHOD(Pango_Pango, versionString)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING((char *)pango_version_string());
}
/* }}} */

static const zend_module_dep pango_module_deps[] = {
    ZEND_MOD_REQUIRED("cairo")
    ZEND_MOD_END
};

/* {{{ pango_module_entry */
zend_module_entry pango_module_entry = {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    pango_module_deps,
    "pango",
    NULL,
    PHP_MINIT(pango),
    PHP_MSHUTDOWN(pango),
    NULL,
    NULL,
    PHP_MINFO(pango),
    PHP_PANGO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PANGO
ZEND_GET_MODULE(pango)
#endif

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pango)
{
    memcpy(
        &pango_std_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );
    pango_std_object_handlers.clone_obj = NULL;

    pango_ce_pango = register_class_Pango_Pango();
    // Make abstract so no-one can instantiate it
    pango_ce_pango->ce_flags |= ZEND_ACC_EXPLICIT_ABSTRACT_CLASS;

    PHP_MINIT(pango_exception)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_context)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_layout)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_description)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_layout_line)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_item)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_item)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_string)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_glyph_info)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_matrix)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_rectangle)(INIT_FUNC_ARGS_PASSTHRU);
    // PHP_MINIT(pango_ft2_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_font_map)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_family)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_font_face)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_layout)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(pango_cairo_context)(INIT_FUNC_ARGS_PASSTHRU);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(pango)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    // TODO: add lazy loading and store global reference to font map, only shutdown if we created it
    PangoFontMap *font_map = pango_cairo_font_map_get_default();
    if (PANGO_IS_FC_FONT_MAP(font_map)) {
        pango_fc_font_map_shutdown((PangoFcFontMap *)font_map);
    }

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pango)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Pango text rendering support", "enabled");
    php_info_print_table_row(2, "Compiled as",
#ifdef COMPILE_DL_PANGO
        "dynamic module"
#else
        "static module"
#endif
    );
    php_info_print_table_row(2, "Pango version",
#ifdef PANGO_VERSION_STRING
        PANGO_VERSION_STRING
#else
        "Unknown"
#endif
    );
    php_info_print_table_row(2, "Extension version", PHP_PANGO_VERSION);
    php_info_print_table_end();
}
/* }}} */
