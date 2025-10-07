/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 314a7cb7ae41ca852595c88b36d7e7d4ad26c0d8 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Pango_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Pango_versionString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Pango, version);
ZEND_METHOD(Pango_Pango, versionString);

static const zend_function_entry class_Pango_Pango_methods[] = {
	ZEND_ME(Pango_Pango, version, arginfo_class_Pango_Pango_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_Pango, versionString, arginfo_class_Pango_Pango_versionString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Pango(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Pango", class_Pango_Pango_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	zval const_SCALE_value;
	ZVAL_LONG(&const_SCALE_value, PANGO_SCALE);
	zend_string *const_SCALE_name = zend_string_init_interned("SCALE", sizeof("SCALE") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SCALE_name, &const_SCALE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SCALE_name);

	return class_entry;
}
