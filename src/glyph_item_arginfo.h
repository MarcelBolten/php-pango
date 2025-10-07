/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4d63f9d52ea792d957b176f3d1cc03765e3ca750 */

static zend_class_entry *register_class_Pango_GlyphItem(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphItem", NULL);
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

	zval property_item_default_value;
	ZVAL_UNDEF(&property_item_default_value);
	zend_string *property_item_name = zend_string_init("item", sizeof("item") - 1, 1);
	zend_string *property_item_class_Pango_Item = zend_string_init("Pango\\Item", sizeof("Pango\\Item")-1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_item_name, &property_item_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_item_class_Pango_Item, 0, 0));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_item_name, &property_item_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_item_class_Pango_Item, 0, 0));
#endif
	zend_string_release(property_item_name);

	zval property_glyphs_default_value;
	ZVAL_UNDEF(&property_glyphs_default_value);
	zend_string *property_glyphs_name = zend_string_init("glyphs", sizeof("glyphs") - 1, 1);
	zend_string *property_glyphs_class_Pango_GlyphString = zend_string_init("Pango\\GlyphString", sizeof("Pango\\GlyphString")-1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_glyphs_class_Pango_GlyphString, 0, 0));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_glyphs_class_Pango_GlyphString, 0, 0));
#endif
	zend_string_release(property_glyphs_name);

	zval property_yOffset_default_value;
	ZVAL_UNDEF(&property_yOffset_default_value);
	zend_string *property_yOffset_name = zend_string_init("yOffset", sizeof("yOffset") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_yOffset_name, &property_yOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_yOffset_name, &property_yOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_yOffset_name);

	zval property_startXOffset_default_value;
	ZVAL_UNDEF(&property_startXOffset_default_value);
	zend_string *property_startXOffset_name = zend_string_init("startXOffset", sizeof("startXOffset") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_startXOffset_name, &property_startXOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_startXOffset_name, &property_startXOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_startXOffset_name);

	zval property_endXOffset_default_value;
	ZVAL_UNDEF(&property_endXOffset_default_value);
	zend_string *property_endXOffset_name = zend_string_init("endXOffset", sizeof("endXOffset") - 1, 1);
#if (PHP_VERSION_ID >= 80200)
	zend_declare_typed_property(class_entry, property_endXOffset_name, &property_endXOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#elif (PHP_VERSION_ID >= 80100)
	zend_declare_typed_property(class_entry, property_endXOffset_name, &property_endXOffset_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
#endif
	zend_string_release(property_endXOffset_name);

	return class_entry;
}
