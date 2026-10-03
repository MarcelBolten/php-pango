/* This is a generated file, edit glyph_info.stub.php instead.
 * Stub hash: 372161b8961780210e26dbad4aa8d36397203599 */

static zend_class_entry *register_class_Pango_GlyphInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphInfo", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_glyph_default_value;
	ZVAL_UNDEF(&property_glyph_default_value);
	zend_string *property_glyph_name = zend_string_init("glyph", sizeof("glyph") - 1, true);
	zend_declare_typed_property(class_entry, property_glyph_name, &property_glyph_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_glyph_name, true);

	zval property_geometry_default_value;
	ZVAL_UNDEF(&property_geometry_default_value);
	zend_string *property_geometry_name = zend_string_init("geometry", sizeof("geometry") - 1, true);
	zend_string *property_geometry_class_Pango_GlyphGeometry = zend_string_init("Pango\\GlyphGeometry", sizeof("Pango\\GlyphGeometry")-1, 1);
	zend_declare_typed_property(class_entry, property_geometry_name, &property_geometry_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_geometry_class_Pango_GlyphGeometry, 0, 0));
	zend_string_release_ex(property_geometry_name, true);

	zval property_attributes_default_value;
	ZVAL_UNDEF(&property_attributes_default_value);
	zend_string *property_attributes_name = zend_string_init("attributes", sizeof("attributes") - 1, true);
	zend_string *property_attributes_class_Pango_GlyphVisAttr = zend_string_init("Pango\\GlyphVisAttr", sizeof("Pango\\GlyphVisAttr")-1, 1);
	zend_declare_typed_property(class_entry, property_attributes_name, &property_attributes_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_attributes_class_Pango_GlyphVisAttr, 0, 0));
	zend_string_release_ex(property_attributes_name, true);

	return class_entry;
}
