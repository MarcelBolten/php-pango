/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5cad349e2628067a9d2e30a4b56435795c881dc3 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Matrix___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xx, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yx, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xy, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yy, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x0, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y0, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_rotate, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_scale, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_transformDistance, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, dx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_transformPixelRectangle, 0, 1, Pango\\Rectangle, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, Pango\\Rectangle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_transformPoint, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Matrix_transformRectangle arginfo_class_Pango_Matrix_transformPixelRectangle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_translate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Matrix, __construct);
ZEND_METHOD(Pango_Matrix, rotate);
ZEND_METHOD(Pango_Matrix, scale);
ZEND_METHOD(Pango_Matrix, transformDistance);
ZEND_METHOD(Pango_Matrix, transformPixelRectangle);
ZEND_METHOD(Pango_Matrix, transformPoint);
ZEND_METHOD(Pango_Matrix, transformRectangle);
ZEND_METHOD(Pango_Matrix, translate);

static const zend_function_entry class_Pango_Matrix_methods[] = {
	ZEND_ME(Pango_Matrix, __construct, arginfo_class_Pango_Matrix___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, rotate, arginfo_class_Pango_Matrix_rotate, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, scale, arginfo_class_Pango_Matrix_scale, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, transformDistance, arginfo_class_Pango_Matrix_transformDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, transformPixelRectangle, arginfo_class_Pango_Matrix_transformPixelRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, transformPoint, arginfo_class_Pango_Matrix_transformPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, transformRectangle, arginfo_class_Pango_Matrix_transformRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, translate, arginfo_class_Pango_Matrix_translate, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Matrix(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Matrix", class_Pango_Matrix_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	zval property_xx_default_value;
	ZVAL_DOUBLE(&property_xx_default_value, 1.0);
	zend_string *property_xx_name = zend_string_init("xx", sizeof("xx") - 1, 1);
	zend_declare_typed_property(class_entry, property_xx_name, &property_xx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_xx_name);

	zval property_yx_default_value;
	ZVAL_DOUBLE(&property_yx_default_value, 0.0);
	zend_string *property_yx_name = zend_string_init("yx", sizeof("yx") - 1, 1);
	zend_declare_typed_property(class_entry, property_yx_name, &property_yx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_yx_name);

	zval property_xy_default_value;
	ZVAL_DOUBLE(&property_xy_default_value, 0.0);
	zend_string *property_xy_name = zend_string_init("xy", sizeof("xy") - 1, 1);
	zend_declare_typed_property(class_entry, property_xy_name, &property_xy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_xy_name);

	zval property_yy_default_value;
	ZVAL_DOUBLE(&property_yy_default_value, 1.0);
	zend_string *property_yy_name = zend_string_init("yy", sizeof("yy") - 1, 1);
	zend_declare_typed_property(class_entry, property_yy_name, &property_yy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_yy_name);

	zval property_x0_default_value;
	ZVAL_DOUBLE(&property_x0_default_value, 0.0);
	zend_string *property_x0_name = zend_string_init("x0", sizeof("x0") - 1, 1);
	zend_declare_typed_property(class_entry, property_x0_name, &property_x0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x0_name);

	zval property_y0_default_value;
	ZVAL_DOUBLE(&property_y0_default_value, 0.0);
	zend_string *property_y0_name = zend_string_init("y0", sizeof("y0") - 1, 1);
	zend_declare_typed_property(class_entry, property_y0_name, &property_y0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y0_name);

	return class_entry;
}
