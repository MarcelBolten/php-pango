/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: cd22c1fbf33b39d0fa0f2112870f49abb1198b2a */

static zend_class_entry *register_class_Pango_GlyphString(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphString", NULL);
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

	zval property_numGlyphs_default_value;
	ZVAL_UNDEF(&property_numGlyphs_default_value);
	zend_string *property_numGlyphs_name = zend_string_init("numGlyphs", sizeof("numGlyphs") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_numGlyphs_name, &property_numGlyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_numGlyphs_name, &property_numGlyphs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_numGlyphs_name);

	zval property_glyphs_default_value;
	ZVAL_UNDEF(&property_glyphs_default_value);
	zend_string *property_glyphs_name = zend_string_init("glyphs", sizeof("glyphs") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
#endif
	zend_string_release(property_glyphs_name);

	return class_entry;
}
