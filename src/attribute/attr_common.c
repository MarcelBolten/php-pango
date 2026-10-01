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

#include "../../php_pango.h"
#include "../php_pango_macros.h"
#include "attribute.h"

/* {{{ */
void pango_attr_free_obj(zend_object *object)
{
    pango_attribute_object *intern = pango_attribute_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->attribute) {
        pango_attribute_destroy(intern->attribute);
        intern->attribute = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
int pango_attr_object_compare(zval *op1, zval *op2)
{
    ZEND_COMPARE_OBJECTS_FALLBACK(op1, op2);

    PangoAttribute *attr1 = pango_attribute_object_get_attribute(op1);
    PangoAttribute *attr2 = pango_attribute_object_get_attribute(op2);

    return pango_attribute_equal(attr1, attr2) ? 0 : 1;
}
/* }}} */
