/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: f0c0c796e440ddbb2db435f517d1758078466aa8 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Rectangle___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Rectangle_extentsToPixels, 0, 1, Pango\\Rectangle, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, Pango\\Rectangle, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, roundingMode, Pango\\RoundingMode, 0, "Pango\\RoundingMode::Inclusive")
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Rectangle, __construct);
ZEND_METHOD(Pango_Rectangle, extentsToPixels);

static const zend_function_entry class_Pango_Rectangle_methods[] = {
	ZEND_ME(Pango_Rectangle, __construct, arginfo_class_Pango_Rectangle___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Rectangle, extentsToPixels, arginfo_class_Pango_Rectangle_extentsToPixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Rectangle(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Rectangle", class_Pango_Rectangle_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#if (PHP_VERSION_ID >= 80200)
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#elif (PHP_VERSION_ID >= 80100)
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif
#endif

	zval property_x_default_value;
	ZVAL_UNDEF(&property_x_default_value);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_UNDEF(&property_y_default_value);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_y_name);

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_height_name);

	zval property_ascent_default_value;
	ZVAL_UNDEF(&property_ascent_default_value);
	zend_string *property_ascent_name = zend_string_init("ascent", sizeof("ascent") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_ascent_name, &property_ascent_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_ascent_name, &property_ascent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_ascent_name);

	zval property_descent_default_value;
	ZVAL_UNDEF(&property_descent_default_value);
	zend_string *property_descent_name = zend_string_init("descent", sizeof("descent") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_descent_name, &property_descent_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_descent_name, &property_descent_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_descent_name);

	zval property_leftBearing_default_value;
	ZVAL_UNDEF(&property_leftBearing_default_value);
	zend_string *property_leftBearing_name = zend_string_init("leftBearing", sizeof("leftBearing") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_leftBearing_name, &property_leftBearing_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_leftBearing_name, &property_leftBearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_leftBearing_name);

	zval property_rightBearing_default_value;
	ZVAL_UNDEF(&property_rightBearing_default_value);
	zend_string *property_rightBearing_name = zend_string_init("rightBearing", sizeof("rightBearing") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_rightBearing_name, &property_rightBearing_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_rightBearing_name, &property_rightBearing_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_rightBearing_name);

	return class_entry;
}

static zend_class_entry *register_class_Pango_RoundingMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\RoundingMode", IS_UNDEF, NULL);

	zend_enum_add_case_cstr(class_entry, "Inclusive", NULL);

	zend_enum_add_case_cstr(class_entry, "Nearest", NULL);

	return class_entry;
}
