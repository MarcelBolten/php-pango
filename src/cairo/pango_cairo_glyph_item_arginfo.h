/* This is a generated file, edit pango_cairo_glyph_item.stub.php instead.
 * Stub hash: 5736abe524cb3df61ff8536f61d1ae0b88bc35ec */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_GlyphItem_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_GlyphItem_applyAttributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, list, Pango\\Attribute\\AttributeList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_GlyphItem_split, 0, 1, PangoCairo\\GlyphItem, 1)
	ZEND_ARG_TYPE_INFO(0, splitByteIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(PangoCairo_GlyphItem, show);
ZEND_METHOD(PangoCairo_GlyphItem, applyAttributes);
ZEND_METHOD(PangoCairo_GlyphItem, split);

static const zend_function_entry class_PangoCairo_GlyphItem_methods[] = {
	ZEND_ME(PangoCairo_GlyphItem, show, arginfo_class_PangoCairo_GlyphItem_show, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_GlyphItem, applyAttributes, arginfo_class_PangoCairo_GlyphItem_applyAttributes, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_GlyphItem, split, arginfo_class_PangoCairo_GlyphItem_split, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_GlyphItem(zend_class_entry *class_entry_Pango_GlyphItem)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "GlyphItem", class_PangoCairo_GlyphItem_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_GlyphItem, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_GlyphItem);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_item_default_value;
	ZVAL_UNDEF(&property_item_default_value);
	zend_string *property_item_name = zend_string_init("item", sizeof("item") - 1, true);
	zend_string *property_item_class_Pango_Item = zend_string_init("Pango\\Item", sizeof("Pango\\Item")-1, 1);
	zend_declare_typed_property(class_entry, property_item_name, &property_item_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_item_class_Pango_Item, 0, 0));
	zend_string_release_ex(property_item_name, true);

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
