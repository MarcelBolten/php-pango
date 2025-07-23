#include "php.h"
#include "zend_API.h"
#include "zend_constants.h"

#include "php_pango.h"

#define REGISTER_PANGO_CLASS_LONG_CONST(pango_class, const_name, value) \
    zend_declare_class_constant_long(pango_class, const_name, \
        sizeof(const_name)-1, (long)value); \
    REGISTER_LONG_CONSTANT(#value, value, CONST_PERSISTENT);

#define Z_CAIRO_CONTEXT_P(zv)    ((cairo_context_object *)    Z_OBJ_P(zv))
#define Z_PANGO_CONTEXT_P(zv)    ((pango_context_object *)    Z_OBJ_P(zv))
#define Z_PANGO_FONTDESC_P(zv)   ((pango_fontdesc_object *)   Z_OBJ_P(zv))
#define Z_PANGO_LAYOUT_P(zv)     ((pango_layout_object *)     Z_OBJ_P(zv))
#define Z_PANGO_LAYOUTLINE_P(zv) ((pango_layoutline_object *) Z_OBJ_P(zv))
