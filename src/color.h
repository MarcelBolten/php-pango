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

#ifndef PHP_PANGO_COLOR_H
#define PHP_PANGO_COLOR_H

#include <php.h>
#include <pango/pango.h>
#include "../php_pango.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_color_ce(void);

typedef struct _pango_color_object {
    PangoColor *color;
    zend_object std;
} pango_color_object;
extern pango_color_object *pango_color_fetch_object(zend_object *object);
#define Z_PANGO_COLOR_P(zv) pango_color_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoColor *pango_color_object_get_color(zval *zv);

#endif /* PHP_PANGO_COLOR_H */
