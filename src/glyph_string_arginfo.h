/* This is a generated file, edit glyph_string.stub.php instead.
 * Stub hash: 45a2b3f04c2373c6a91798074dcfa51b01378bf3 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphString_getExtents, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, font, Pango\\Font, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphString_getExtentsRange, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, start, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, end, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, Pango\\Font, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphString_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphString_getLogicalWidths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_GlyphString, getExtents);
ZEND_METHOD(Pango_GlyphString, getExtentsRange);
ZEND_METHOD(Pango_GlyphString, getWidth);
ZEND_METHOD(Pango_GlyphString, getLogicalWidths);

static const zend_function_entry class_Pango_GlyphString_methods[] = {
	ZEND_ME(Pango_GlyphString, getExtents, arginfo_class_Pango_GlyphString_getExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphString, getExtentsRange, arginfo_class_Pango_GlyphString_getExtentsRange, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphString, getWidth, arginfo_class_Pango_GlyphString_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphString, getLogicalWidths, arginfo_class_Pango_GlyphString_getLogicalWidths, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_GlyphString(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphString", class_Pango_GlyphString_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_READONLY_CLASS);
#else
	ce->ce_flags |= ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_READONLY_CLASS;
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
