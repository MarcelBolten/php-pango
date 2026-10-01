/* This is a generated file, edit attr_list.stub.php instead.
 * Stub hash: 63be4696b649495ffe7181648345799b406012f4 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_AttributeList___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, string, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_getAttributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_change, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, attr, Pango\\Attribute\\Attribute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_filter, 0, 1, Pango\\Attribute\\AttributeList, 1)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_getIterator, 0, 0, Pango\\Attribute\\AttributeIterator, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_AttributeList_insert arginfo_class_Pango_Attribute_AttributeList_change

#define arginfo_class_Pango_Attribute_AttributeList_push arginfo_class_Pango_Attribute_AttributeList_change

#define arginfo_class_Pango_Attribute_AttributeList_insertBefore arginfo_class_Pango_Attribute_AttributeList_change

#define arginfo_class_Pango_Attribute_AttributeList_unshift arginfo_class_Pango_Attribute_AttributeList_change

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_splice, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, other, Pango\\Attribute\\AttributeList, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_merge, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, other, Pango\\Attribute\\AttributeList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_AttributeList_serialize arginfo_class_Pango_Attribute_AttributeList_toString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeList_update, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, remove, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, add, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Attribute_AttributeList, __construct);
ZEND_METHOD(Pango_Attribute_AttributeList, getAttributes);
ZEND_METHOD(Pango_Attribute_AttributeList, change);
ZEND_METHOD(Pango_Attribute_AttributeList, filter);
ZEND_METHOD(Pango_Attribute_AttributeList, getIterator);
ZEND_METHOD(Pango_Attribute_AttributeList, insert);
ZEND_METHOD(Pango_Attribute_AttributeList, insertBefore);
ZEND_METHOD(Pango_Attribute_AttributeList, splice);
ZEND_METHOD(Pango_Attribute_AttributeList, merge);
ZEND_METHOD(Pango_Attribute_AttributeList, toString);
ZEND_METHOD(Pango_Attribute_AttributeList, update);

static const zend_function_entry class_Pango_Attribute_AttributeList_methods[] = {
	ZEND_ME(Pango_Attribute_AttributeList, __construct, arginfo_class_Pango_Attribute_AttributeList___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, getAttributes, arginfo_class_Pango_Attribute_AttributeList_getAttributes, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, change, arginfo_class_Pango_Attribute_AttributeList_change, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, filter, arginfo_class_Pango_Attribute_AttributeList_filter, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, getIterator, arginfo_class_Pango_Attribute_AttributeList_getIterator, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, insert, arginfo_class_Pango_Attribute_AttributeList_insert, ZEND_ACC_PUBLIC)
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY("push", zim_Pango_Attribute_AttributeList_insert, arginfo_class_Pango_Attribute_AttributeList_push, ZEND_ACC_PUBLIC, NULL, NULL)
#else
	ZEND_RAW_FENTRY("push", zim_Pango_Attribute_AttributeList_insert, arginfo_class_Pango_Attribute_AttributeList_push, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Attribute_AttributeList, insertBefore, arginfo_class_Pango_Attribute_AttributeList_insertBefore, ZEND_ACC_PUBLIC)
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY("unshift", zim_Pango_Attribute_AttributeList_insertBefore, arginfo_class_Pango_Attribute_AttributeList_unshift, ZEND_ACC_PUBLIC, NULL, NULL)
#else
	ZEND_RAW_FENTRY("unshift", zim_Pango_Attribute_AttributeList_insertBefore, arginfo_class_Pango_Attribute_AttributeList_unshift, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Attribute_AttributeList, splice, arginfo_class_Pango_Attribute_AttributeList_splice, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, merge, arginfo_class_Pango_Attribute_AttributeList_merge, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeList, toString, arginfo_class_Pango_Attribute_AttributeList_toString, ZEND_ACC_PUBLIC)
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY("serialize", zim_Pango_Attribute_AttributeList_toString, arginfo_class_Pango_Attribute_AttributeList_serialize, ZEND_ACC_PUBLIC, NULL, NULL)
#else
	ZEND_RAW_FENTRY("serialize", zim_Pango_Attribute_AttributeList_toString, arginfo_class_Pango_Attribute_AttributeList_serialize, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Attribute_AttributeList, update, arginfo_class_Pango_Attribute_AttributeList_update, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Attribute_AttributeList(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "AttributeList", class_Pango_Attribute_AttributeList_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
