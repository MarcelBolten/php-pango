/* This is a generated file, edit glyph_string.stub.php instead.
 * Stub hash: bdb96f168652f3084f786daca3b8f22036842c02 */

static zend_class_entry *register_class_Pango_GlyphString(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphString", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_numGlyphs_default_value;
	ZVAL_UNDEF(&property_numGlyphs_default_value);
	zend_string *property_numGlyphs_name = zend_string_init("numGlyphs", sizeof("numGlyphs") - 1, true);
	zend_declare_typed_property(class_entry, property_numGlyphs_name, &property_numGlyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_numGlyphs_name, true);

	zval property_glyphs_default_value;
	ZVAL_UNDEF(&property_glyphs_default_value);
	zend_string *property_glyphs_name = zend_string_init("glyphs", sizeof("glyphs") - 1, true);
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release_ex(property_glyphs_name, true);

	return class_entry;
}
