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
  |          David Marín <davefx@gmail.com>                              |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_PANGO_H
#define PHP_PANGO_H

#define PHP_PANGO_VERSION "0.2.0-dev"

extern zend_module_entry pango_module_entry;
#define phpext_pango_ptr &pango_module_entry

#ifdef PHP_WIN32
#    define PHP_PANGO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#    define PHP_PANGO_API __attribute__ ((visibility("default")))
#else
#    define PHP_PANGO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(pango);
PHP_MSHUTDOWN_FUNCTION(pango);
PHP_MINFO_FUNCTION(pango);

#ifdef ZTS
#define PANGO_G(v) TSRMG(pango_globals_id, zend_pango_globals *, v)
#else
#define PANGO_G(v) (pango_globals.v)
#endif

#endif /* PHP_PANGO_H */
