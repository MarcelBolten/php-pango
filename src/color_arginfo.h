/* This is a generated file, edit color.stub.php instead.
 * Stub hash: 6a3361e1163e005aa737ffb6d7a73bff72aec4a9 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Color___construct, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, red, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Color_fromString, 0, 1, Pango\\Color, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Color___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Color, __construct);
ZEND_METHOD(Pango_Color, fromString);
ZEND_METHOD(Pango_Color, __toString);

static const zend_function_entry class_Pango_Color_methods[] = {
	ZEND_ME(Pango_Color, __construct, arginfo_class_Pango_Color___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Color, fromString, arginfo_class_Pango_Color_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_Color, __toString, arginfo_class_Pango_Color___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Color(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Color", class_Pango_Color_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_red_default_value;
	ZVAL_UNDEF(&property_red_default_value);
	zend_string *property_red_name = zend_string_init("red", sizeof("red") - 1, true);
	zend_declare_typed_property(class_entry, property_red_name, &property_red_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_red_name, true);

	zval property_green_default_value;
	ZVAL_UNDEF(&property_green_default_value);
	zend_string *property_green_name = zend_string_init("green", sizeof("green") - 1, true);
	zend_declare_typed_property(class_entry, property_green_name, &property_green_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_green_name, true);

	zval property_blue_default_value;
	ZVAL_UNDEF(&property_blue_default_value);
	zend_string *property_blue_name = zend_string_init("blue", sizeof("blue") - 1, true);
	zend_declare_typed_property(class_entry, property_blue_name, &property_blue_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_blue_name, true);

	return class_entry;
}
