/* This is a generated file, edit glyph_vis_attr.stub.php instead.
 * Stub hash: 0d077b2956b425caae1a9807efc829d4860fce59 */

static zend_class_entry *register_class_Pango_GlyphVisAttr(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphVisAttr", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_isClusterStart_default_value;
	ZVAL_UNDEF(&property_isClusterStart_default_value);
	zend_string *property_isClusterStart_name = zend_string_init("isClusterStart", sizeof("isClusterStart") - 1, true);
	zend_declare_typed_property(class_entry, property_isClusterStart_name, &property_isClusterStart_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_isClusterStart_name, true);

	zval property_isColor_default_value;
	ZVAL_UNDEF(&property_isColor_default_value);
	zend_string *property_isColor_name = zend_string_init("isColor", sizeof("isColor") - 1, true);
	zend_declare_typed_property(class_entry, property_isColor_name, &property_isColor_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_isColor_name, true);

	return class_entry;
}
