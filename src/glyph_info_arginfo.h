/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 085539282c0504a2d2eb142260c656dfeb689508 */

static zend_class_entry *register_class_Pango_GlyphInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphInfo", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	zval property_glyph_default_value;
	ZVAL_UNDEF(&property_glyph_default_value);
	zend_string *property_glyph_name = zend_string_init("glyph", sizeof("glyph") - 1, 1);
	zend_declare_typed_property(class_entry, property_glyph_name, &property_glyph_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_glyph_name);

	zval property_geometry_default_value;
	ZVAL_UNDEF(&property_geometry_default_value);
	zend_string *property_geometry_name = zend_string_init("geometry", sizeof("geometry") - 1, 1);
	zend_declare_typed_property(class_entry, property_geometry_name, &property_geometry_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_geometry_name);

	zval property_attributes_default_value;
	ZVAL_UNDEF(&property_attributes_default_value);
	zend_string *property_attributes_name = zend_string_init("attributes", sizeof("attributes") - 1, 1);
	zend_declare_typed_property(class_entry, property_attributes_name, &property_attributes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_attributes_name);

	return class_entry;
}
