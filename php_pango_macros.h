#include "php.h"
#include "zend_API.h"
#include "zend_constants.h"

#include "php_pango.h"

#define REGISTER_PANGO_CLASS_LONG_CONST(pango_class, const_name, value) \
    zend_declare_class_constant_long(pango_class, const_name, \
        sizeof(const_name)-1, (long)value); \
    REGISTER_LONG_CONSTANT(#value, value, CONST_PERSISTENT);
