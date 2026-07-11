/* This is a generated file, edit item.stub.php instead.
 * Stub hash: 3038a60f6ecb8dd20da2d53a958af6422e28ae67 */

static zend_class_entry *register_class_Pango_Item(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Item", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_offset_default_value;
	ZVAL_UNDEF(&property_offset_default_value);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, true);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_offset_name, true);

	zval property_length_default_value;
	ZVAL_UNDEF(&property_length_default_value);
	zend_string *property_length_name = zend_string_init("length", sizeof("length") - 1, true);
	zend_declare_typed_property(class_entry, property_length_name, &property_length_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_length_name, true);

	zval property_numChars_default_value;
	ZVAL_UNDEF(&property_numChars_default_value);
	zend_string *property_numChars_name = zend_string_init("numChars", sizeof("numChars") - 1, true);
	zend_declare_typed_property(class_entry, property_numChars_name, &property_numChars_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_numChars_name, true);

	zval property_analysis_default_value;
	ZVAL_UNDEF(&property_analysis_default_value);
	zend_string *property_analysis_name = zend_string_init("analysis", sizeof("analysis") - 1, true);
	zend_declare_typed_property(class_entry, property_analysis_name, &property_analysis_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release_ex(property_analysis_name, true);

	return class_entry;
}
