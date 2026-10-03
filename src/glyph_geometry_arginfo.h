/* This is a generated file, edit glyph_geometry.stub.php instead.
 * Stub hash: b888f82a4fa2e65fc656397582ee876088805f8b */

static zend_class_entry *register_class_Pango_GlyphGeometry(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphGeometry", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, true);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_width_name, true);

	zval property_xOffset_default_value;
	ZVAL_UNDEF(&property_xOffset_default_value);
	zend_string *property_xOffset_name = zend_string_init("xOffset", sizeof("xOffset") - 1, true);
	zend_declare_typed_property(class_entry, property_xOffset_name, &property_xOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_xOffset_name, true);

	zval property_yOffset_default_value;
	ZVAL_UNDEF(&property_yOffset_default_value);
	zend_string *property_yOffset_name = zend_string_init("yOffset", sizeof("yOffset") - 1, true);
	zend_declare_typed_property(class_entry, property_yOffset_name, &property_yOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_yOffset_name, true);

	return class_entry;
}
