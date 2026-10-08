/* This is a generated file, edit matrix.stub.php instead.
 * Stub hash: 4f1f4f6b35b20470690a0f4c09587abfa856e0a9 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Matrix___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xx, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yx, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xy, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yy, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x0, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y0, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_concat, 0, 1, Pango\\Matrix, 0)
	ZEND_ARG_OBJ_INFO(0, newMatrix, Pango\\Matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_getFontScaleFactor, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Matrix_getFontScaleFactors, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Matrix_getSlantRatio arginfo_class_Pango_Matrix_getFontScaleFactor

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_getGravity, 0, 0, Pango\\Gravity, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_rotate, 0, 1, Pango\\Matrix, 0)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_scale, 0, 2, Pango\\Matrix, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Matrix_translate, 0, 2, Pango\\Matrix, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Matrix, __construct);
ZEND_METHOD(Pango_Matrix, concat);
ZEND_METHOD(Pango_Matrix, getFontScaleFactor);
ZEND_METHOD(Pango_Matrix, getFontScaleFactors);
ZEND_METHOD(Pango_Matrix, getSlantRatio);
ZEND_METHOD(Pango_Matrix, getGravity);
ZEND_METHOD(Pango_Matrix, rotate);
ZEND_METHOD(Pango_Matrix, scale);
ZEND_METHOD(Pango_Matrix, transformDistance);
ZEND_METHOD(Pango_Matrix, transformPixelRectangle);
ZEND_METHOD(Pango_Matrix, transformPoint);
ZEND_METHOD(Pango_Matrix, transformRectangle);
ZEND_METHOD(Pango_Matrix, translate);

static const zend_function_entry class_Pango_Matrix_methods[] = {
	ZEND_ME(Pango_Matrix, __construct, arginfo_class_Pango_Matrix___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, concat, arginfo_class_Pango_Matrix_concat, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, getFontScaleFactor, arginfo_class_Pango_Matrix_getFontScaleFactor, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, getFontScaleFactors, arginfo_class_Pango_Matrix_getFontScaleFactors, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, getSlantRatio, arginfo_class_Pango_Matrix_getSlantRatio, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Matrix, getGravity, arginfo_class_Pango_Matrix_getGravity, ZEND_ACC_PUBLIC)
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
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_xx_default_value;
	ZVAL_UNDEF(&property_xx_default_value);
	zend_string *property_xx_name = zend_string_init("xx", sizeof("xx") - 1, true);
	zend_declare_typed_property(class_entry, property_xx_name, &property_xx_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_xx_name, true);

	zval property_yx_default_value;
	ZVAL_UNDEF(&property_yx_default_value);
	zend_string *property_yx_name = zend_string_init("yx", sizeof("yx") - 1, true);
	zend_declare_typed_property(class_entry, property_yx_name, &property_yx_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_yx_name, true);

	zval property_xy_default_value;
	ZVAL_UNDEF(&property_xy_default_value);
	zend_string *property_xy_name = zend_string_init("xy", sizeof("xy") - 1, true);
	zend_declare_typed_property(class_entry, property_xy_name, &property_xy_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_xy_name, true);

	zval property_yy_default_value;
	ZVAL_UNDEF(&property_yy_default_value);
	zend_string *property_yy_name = zend_string_init("yy", sizeof("yy") - 1, true);
	zend_declare_typed_property(class_entry, property_yy_name, &property_yy_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_yy_name, true);

	zval property_x0_default_value;
	ZVAL_UNDEF(&property_x0_default_value);
	zend_string *property_x0_name = zend_string_init("x0", sizeof("x0") - 1, true);
	zend_declare_typed_property(class_entry, property_x0_name, &property_x0_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_x0_name, true);

	zval property_y0_default_value;
	ZVAL_UNDEF(&property_y0_default_value);
	zend_string *property_y0_name = zend_string_init("y0", sizeof("y0") - 1, true);
	zend_declare_typed_property(class_entry, property_y0_name, &property_y0_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release_ex(property_y0_name, true);

	return class_entry;
}
