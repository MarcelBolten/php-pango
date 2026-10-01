/* This is a generated file, edit glyph_item.stub.php instead.
 * Stub hash: dc530cfee756673e696702804f5a52084d539650 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphItem_getLogicalWidths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphItem_applyAttributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, list, Pango\\Attribute\\AttributeList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphItem_letterSpace, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_GlyphItem_split, 0, 1, Pango\\GlyphItem, 1)
	ZEND_ARG_TYPE_INFO(0, splitByteIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_GlyphItem_getGlyphItemIterator, 0, 0, Pango\\GlyphItemIterator, 1)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, initialLocation, Pango\\GlyphItemIterInitLoc, 0, "Pango\\GlyphItemIterInitLoc::Beginning")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_GlyphItemIterator_next, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_GlyphItemIterator_prev arginfo_class_Pango_GlyphItemIterator_next

ZEND_METHOD(Pango_GlyphItem, getLogicalWidths);
ZEND_METHOD(Pango_GlyphItem, applyAttributes);
ZEND_METHOD(Pango_GlyphItem, letterSpace);
ZEND_METHOD(Pango_GlyphItem, split);
ZEND_METHOD(Pango_GlyphItem, getGlyphItemIterator);
ZEND_METHOD(Pango_GlyphItemIterator, next);
ZEND_METHOD(Pango_GlyphItemIterator, prev);

static const zend_function_entry class_Pango_GlyphItem_methods[] = {
	ZEND_ME(Pango_GlyphItem, getLogicalWidths, arginfo_class_Pango_GlyphItem_getLogicalWidths, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphItem, applyAttributes, arginfo_class_Pango_GlyphItem_applyAttributes, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphItem, letterSpace, arginfo_class_Pango_GlyphItem_letterSpace, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphItem, split, arginfo_class_Pango_GlyphItem_split, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphItem, getGlyphItemIterator, arginfo_class_Pango_GlyphItem_getGlyphItemIterator, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_GlyphItemIterator_methods[] = {
	ZEND_ME(Pango_GlyphItemIterator, next, arginfo_class_Pango_GlyphItemIterator_next, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_GlyphItemIterator, prev, arginfo_class_Pango_GlyphItemIterator_prev, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_GlyphItem(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphItem", class_Pango_GlyphItem_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_item_default_value;
	ZVAL_UNDEF(&property_item_default_value);
	zend_string *property_item_name = zend_string_init("item", sizeof("item") - 1, true);
	zend_string *property_item_class_Pango_Item = zend_string_init("Pango\\Item", sizeof("Pango\\Item")-1, 1);
	zend_declare_typed_property(class_entry, property_item_name, &property_item_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_item_class_Pango_Item, 0, 0));
	zend_string_release_ex(property_item_name, true);

	zval property_glyphs_default_value;
	ZVAL_UNDEF(&property_glyphs_default_value);
	zend_string *property_glyphs_name = zend_string_init("glyphs", sizeof("glyphs") - 1, true);
	zend_string *property_glyphs_class_Pango_GlyphString = zend_string_init("Pango\\GlyphString", sizeof("Pango\\GlyphString")-1, 1);
	zend_declare_typed_property(class_entry, property_glyphs_name, &property_glyphs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_glyphs_class_Pango_GlyphString, 0, 0));
	zend_string_release_ex(property_glyphs_name, true);

	zval property_yOffset_default_value;
	ZVAL_UNDEF(&property_yOffset_default_value);
	zend_string *property_yOffset_name = zend_string_init("yOffset", sizeof("yOffset") - 1, true);
	zend_declare_typed_property(class_entry, property_yOffset_name, &property_yOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_yOffset_name, true);

	zval property_startXOffset_default_value;
	ZVAL_UNDEF(&property_startXOffset_default_value);
	zend_string *property_startXOffset_name = zend_string_init("startXOffset", sizeof("startXOffset") - 1, true);
	zend_declare_typed_property(class_entry, property_startXOffset_name, &property_startXOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_startXOffset_name, true);

	zval property_endXOffset_default_value;
	ZVAL_UNDEF(&property_endXOffset_default_value);
	zend_string *property_endXOffset_name = zend_string_init("endXOffset", sizeof("endXOffset") - 1, true);
	zend_declare_typed_property(class_entry, property_endXOffset_name, &property_endXOffset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_endXOffset_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_GlyphItemIterInitLoc(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\GlyphItemIterInitLoc", IS_UNDEF, NULL);

	zend_enum_add_case_cstr(class_entry, "Beginning", NULL);

	zend_enum_add_case_cstr(class_entry, "End", NULL);

	return class_entry;
}

static zend_class_entry *register_class_Pango_GlyphItemIterator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "GlyphItemIterator", class_Pango_GlyphItemIterator_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_glyphItem_default_value;
	ZVAL_UNDEF(&property_glyphItem_default_value);
	zend_string *property_glyphItem_name = zend_string_init("glyphItem", sizeof("glyphItem") - 1, true);
	zend_string *property_glyphItem_class_Pango_GlyphItem = zend_string_init("Pango\\GlyphItem", sizeof("Pango\\GlyphItem")-1, 1);
	zend_declare_typed_property(class_entry, property_glyphItem_name, &property_glyphItem_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_glyphItem_class_Pango_GlyphItem, 0, 0));
	zend_string_release_ex(property_glyphItem_name, true);

	zval property_text_default_value;
	ZVAL_UNDEF(&property_text_default_value);
	zend_string *property_text_name = zend_string_init("text", sizeof("text") - 1, true);
	zend_declare_typed_property(class_entry, property_text_name, &property_text_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release_ex(property_text_name, true);

	zval property_startGlyph_default_value;
	ZVAL_UNDEF(&property_startGlyph_default_value);
	zend_string *property_startGlyph_name = zend_string_init("startGlyph", sizeof("startGlyph") - 1, true);
	zend_declare_typed_property(class_entry, property_startGlyph_name, &property_startGlyph_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_startGlyph_name, true);

	zval property_startByteIndex_default_value;
	ZVAL_UNDEF(&property_startByteIndex_default_value);
	zend_string *property_startByteIndex_name = zend_string_init("startByteIndex", sizeof("startByteIndex") - 1, true);
	zend_declare_typed_property(class_entry, property_startByteIndex_name, &property_startByteIndex_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_startByteIndex_name, true);

	zval property_startChar_default_value;
	ZVAL_UNDEF(&property_startChar_default_value);
	zend_string *property_startChar_name = zend_string_init("startChar", sizeof("startChar") - 1, true);
	zend_declare_typed_property(class_entry, property_startChar_name, &property_startChar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_startChar_name, true);

	zval property_endGlyph_default_value;
	ZVAL_UNDEF(&property_endGlyph_default_value);
	zend_string *property_endGlyph_name = zend_string_init("endGlyph", sizeof("endGlyph") - 1, true);
	zend_declare_typed_property(class_entry, property_endGlyph_name, &property_endGlyph_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_endGlyph_name, true);

	zval property_endByteIndex_default_value;
	ZVAL_UNDEF(&property_endByteIndex_default_value);
	zend_string *property_endByteIndex_name = zend_string_init("endByteIndex", sizeof("endByteIndex") - 1, true);
	zend_declare_typed_property(class_entry, property_endByteIndex_name, &property_endByteIndex_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_endByteIndex_name, true);

	zval property_endChar_default_value;
	ZVAL_UNDEF(&property_endChar_default_value);
	zend_string *property_endChar_name = zend_string_init("endChar", sizeof("endChar") - 1, true);
	zend_declare_typed_property(class_entry, property_endChar_name, &property_endChar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_endChar_name, true);

	return class_entry;
}
