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
#include <pango/pango.h>

typedef zend_class_entry *(*attr_ce_getter_t)(void);

extern const attr_ce_getter_t attr_ce_table[];
extern const size_t attr_ce_table_size;

zend_class_entry *php_pango_attr_ce_lookup(PangoAttrType type);
