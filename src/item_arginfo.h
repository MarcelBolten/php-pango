/* This is a generated file, edit item.stub.php instead.
 * Stub hash: c53f25b5c02c6afb3c75f61b2e4a838a44163bde */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Item_applyAttributes, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, iter, Pango\\Attribute\\AttributeIterator, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 54, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Item_getCharOffset, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Item_split, 0, 2, Pango\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, byteIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, charOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Item, applyAttributes);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 54, 0)
ZEND_METHOD(Pango_Item, getCharOffset);
#endif
ZEND_METHOD(Pango_Item, split);

static const zend_function_entry class_Pango_Item_methods[] = {
	ZEND_ME(Pango_Item, applyAttributes, arginfo_class_Pango_Item_applyAttributes, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 54, 0)
	ZEND_ME(Pango_Item, getCharOffset, arginfo_class_Pango_Item_getCharOffset, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Item, split, arginfo_class_Pango_Item_split, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Item(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Item", class_Pango_Item_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_offset_default_value;
	ZVAL_UNDEF(&property_offset_default_value);
	zend_string *property_offset_name = zend_string_init("offset", sizeof("offset") - 1, true);
	zend_declare_typed_property(class_entry, property_offset_name, &property_offset_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_offset_name, true);

	zval property_length_default_value;
	ZVAL_UNDEF(&property_length_default_value);
	zend_string *property_length_name = zend_string_init("length", sizeof("length") - 1, true);
	zend_declare_typed_property(class_entry, property_length_name, &property_length_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_length_name, true);

	zval property_numChars_default_value;
	ZVAL_UNDEF(&property_numChars_default_value);
	zend_string *property_numChars_name = zend_string_init("numChars", sizeof("numChars") - 1, true);
	zend_declare_typed_property(class_entry, property_numChars_name, &property_numChars_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_numChars_name, true);

	zval property_analysis_default_value;
	ZVAL_UNDEF(&property_analysis_default_value);
	zend_string *property_analysis_name = zend_string_init("analysis", sizeof("analysis") - 1, true);
	zend_string *property_analysis_class_Pango_Analysis = zend_string_init("Pango\\Analysis", sizeof("Pango\\Analysis")-1, 1);
	zend_declare_typed_property(class_entry, property_analysis_name, &property_analysis_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_analysis_class_Pango_Analysis, 0, 0));
	zend_string_release_ex(property_analysis_name, true);

	return class_entry;
}
