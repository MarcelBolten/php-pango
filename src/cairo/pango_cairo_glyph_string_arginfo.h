/* This is a generated file, edit pango_cairo_glyph_string.stub.php instead.
 * Stub hash: 917c5d8dd3c29abb6a2b3a394de0e7ef8e0012bc */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_GlyphString_path, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, Pango\\Font, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_GlyphString_show arginfo_class_PangoCairo_GlyphString_path

ZEND_METHOD(PangoCairo_GlyphString, path);
ZEND_METHOD(PangoCairo_GlyphString, show);

static const zend_function_entry class_PangoCairo_GlyphString_methods[] = {
	ZEND_ME(PangoCairo_GlyphString, path, arginfo_class_PangoCairo_GlyphString_path, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_GlyphString, show, arginfo_class_PangoCairo_GlyphString_show, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_GlyphString(zend_class_entry *class_entry_Pango_GlyphString)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "GlyphString", class_PangoCairo_GlyphString_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_GlyphString, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_GlyphString);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	return class_entry;
}
