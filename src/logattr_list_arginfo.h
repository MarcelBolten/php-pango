/* This is a generated file, edit logattr_list.stub.php instead.
 * Stub hash: 2862d07e984263afaefa0bcd456f19bd17bbd89c */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_LogAttrList___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, language, Pango\\Language, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, level, IS_LONG, 1, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LogAttrList_defaultBreak, 0, 1, Pango\\LogAttrList, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LogAttrList_tailorBreak, 0, 0, Pango\\LogAttrList, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, analysis, Pango\\Analysis, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, byteOffset, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LogAttrList_attrBreak, 0, 1, Pango\\LogAttrList, 0)
	ZEND_ARG_OBJ_INFO(0, attrList, Pango\\Attribute\\AttributeList, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, byteOffset, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LogAttrList_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LogAttrList_get, 0, 1, Pango\\LogAttr, 0)
	ZEND_ARG_TYPE_INFO(0, byteIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LogAttrList_getAttributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LogAttrList_getIterator, 0, 0, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_LogAttrList, __construct);
ZEND_METHOD(Pango_LogAttrList, defaultBreak);
ZEND_METHOD(Pango_LogAttrList, tailorBreak);
ZEND_METHOD(Pango_LogAttrList, attrBreak);
ZEND_METHOD(Pango_LogAttrList, count);
ZEND_METHOD(Pango_LogAttrList, get);
ZEND_METHOD(Pango_LogAttrList, getAttributes);
ZEND_METHOD(Pango_LogAttrList, getIterator);

static const zend_function_entry class_Pango_LogAttrList_methods[] = {
	ZEND_ME(Pango_LogAttrList, __construct, arginfo_class_Pango_LogAttrList___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, defaultBreak, arginfo_class_Pango_LogAttrList_defaultBreak, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_LogAttrList, tailorBreak, arginfo_class_Pango_LogAttrList_tailorBreak, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, attrBreak, arginfo_class_Pango_LogAttrList_attrBreak, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, count, arginfo_class_Pango_LogAttrList_count, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, get, arginfo_class_Pango_LogAttrList_get, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, getAttributes, arginfo_class_Pango_LogAttrList_getAttributes, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LogAttrList, getIterator, arginfo_class_Pango_LogAttrList_getIterator, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_LogAttrList(zend_class_entry *class_entry_Countable, zend_class_entry *class_entry_IteratorAggregate)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "LogAttrList", class_Pango_LogAttrList_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif
	zend_class_implements(class_entry, 2, class_entry_Countable, class_entry_IteratorAggregate);

	zval property_text_default_value;
	ZVAL_UNDEF(&property_text_default_value);
	zend_string *property_text_name = zend_string_init("text", sizeof("text") - 1, true);
	zend_declare_typed_property(class_entry, property_text_name, &property_text_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release_ex(property_text_name, true);

	return class_entry;
}
