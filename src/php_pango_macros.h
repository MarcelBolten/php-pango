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

#include <php.h>
#include <Zend/zend_enum.h>

#define PANGO_LONG_VALUE_FROM_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        ZVAL_LONG(rv, n); \
        return rv; \
    }

#define PANGO_LONG_VALUE_TO_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        n = zval_get_long(value); \
        break; \
    }

#define PANGO_ADD_STRUCT_LONG_VALUE(n, m) \
    ZVAL_LONG(&tmp, n); \
    zend_hash_str_update(props, #m, sizeof(#m)-1, &tmp)

#define PANGO_BOOL_VALUE_FROM_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        ZVAL_BOOL(rv, n); \
        return rv; \
    }

#define PANGO_BOOL_VALUE_TO_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        n = zend_is_true(value); \
        break; \
    }

#define PANGO_ADD_STRUCT_BOOL_VALUE(n, m) \
    ZVAL_BOOL(&tmp, n); \
    zend_hash_str_update(props, #m, sizeof(#m)-1, &tmp)

#define PANGO_DOUBLE_VALUE_FROM_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        ZVAL_DOUBLE(rv, n); \
        return rv; \
    }

#define PANGO_DOUBLE_VALUE_TO_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        n = zval_get_double(value); \
        break; \
    }

#define PANGO_ADD_STRUCT_DOUBLE_VALUE(n, m) \
    ZVAL_DOUBLE(&tmp, n); \
    zend_hash_str_update(props, #m, sizeof(#m)-1, &tmp)

#define PANGO_STRING_VALUE_FROM_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        ZVAL_STRING(rv, n); \
        return rv; \
    }

#define PANGO_STRING_VALUE_TO_STRUCT(n, m) \
    if (strcmp(member->val, #m) == 0) { \
        zend_string *tmp_str; \
        zend_string *zstr = zval_get_tmp_string(value, &tmp_str); \
        gchar *new_val = g_strdup(ZSTR_VAL(zstr)); \
        zend_tmp_string_release(tmp_str); \
        g_free(n); \
        n = new_val; \
        break; \
    }

#define PANGO_ADD_STRUCT_STRING_VALUE(n, m) \
    ZVAL_STRING(&tmp, n); \
    zend_hash_str_update(props, #m, sizeof(#m)-1, &tmp)

#define PANGO_ENUM_VALUE_FROM_STRUCT(n, m, _ce) \
    if (strcmp(member->val, #m) == 0) { \
        zend_object *case_obj = NULL; \
        zend_enum_get_case_by_value( \
            &case_obj, _ce, \
            n, \
            NULL, false \
        ); \
        ZVAL_OBJ_COPY(rv, case_obj); \
        return rv; \
    }

#define PANGO_ENUM_VALUE_TO_STRUCT(n, m, _ce) \
    if (strcmp(member->val, #m) == 0) { \
        if (Z_TYPE_P(value) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(value), _ce)) { \
            zend_type_error( \
                "Cannot assign %s to property %s::$%s of type %s", \
                zend_zval_type_name(value), \
                ZSTR_VAL(object->ce->name), \
                #m, \
                ZSTR_VAL(_ce->name) \
            ); \
            break; \
        } \
        n = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(value))); \
        break; \
    }

#define PANGO_ADD_STRUCT_ENUM_VALUE(n, m, _ce) \
    do { \
        zend_object *case_obj = NULL; \
        zend_enum_get_case_by_value( \
            &case_obj, _ce, \
            n, \
            NULL, false \
        ); \
        ZVAL_OBJ_COPY(&tmp, case_obj); \
    } while (0); \
    zend_hash_str_update(props, #m, sizeof(#m)-1, &tmp)

#define PANGO_COLOR_VALUE_FROM_STRUCT \
    if (strcmp(member->val, "color") == 0) { \
        object_init_ex(rv, php_pango_get_color_ce()); \
        pango_color_object *color_object = Z_PANGO_COLOR_P(rv); \
        *color_object->color = attr->color; \
        return rv; \
    }

#define PANGO_COLOR_VALUE_TO_STRUCT \
    if (strcmp(member->val, "color") == 0) { \
        if (Z_TYPE_P(value) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(value), php_pango_get_color_ce())) { \
            zend_type_error( \
                "Cannot assign %s to property %s::$%s of type %s", \
                zend_zval_type_name(value), \
                ZSTR_VAL(object->ce->name), \
                "color", \
                ZSTR_VAL(php_pango_get_color_ce()->name) \
            ); \
            break; \
        } \
        pango_color_object *color_object = Z_PANGO_COLOR_P(value); \
        attr->color = *color_object->color; \
        break; \
    }

#define PANGO_ADD_STRUCT_COLOR_VALUE \
    object_init_ex(&tmp, php_pango_get_color_ce()); \
    pango_color_object *color_object = Z_PANGO_COLOR_P(&tmp); \
    *color_object->color = attr->color; \
    zend_hash_str_update(props, "color", sizeof("color")-1, &tmp);
