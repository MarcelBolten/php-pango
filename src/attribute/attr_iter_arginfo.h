/* This is a generated file, edit attr_iter.stub.php instead.
 * Stub hash: 666da4e1f287d805357998eaa33fc125464214b1 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_AttributeIterator___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Attribute_AttributeIterator_get, 0, 1, Pango\\Attribute\\Attribute, 1)
	ZEND_ARG_OBJ_INFO(0, type, Pango\\Attribute\\AttributeType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeIterator_getAttributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_AttributeIterator_getFont arginfo_class_Pango_Attribute_AttributeIterator_getAttributes

#define arginfo_class_Pango_Attribute_AttributeIterator_getRange arginfo_class_Pango_Attribute_AttributeIterator_getAttributes

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_AttributeIterator_next, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Attribute_AttributeIterator, __construct);
ZEND_METHOD(Pango_Attribute_AttributeIterator, get);
ZEND_METHOD(Pango_Attribute_AttributeIterator, getAttributes);
ZEND_METHOD(Pango_Attribute_AttributeIterator, getFont);
ZEND_METHOD(Pango_Attribute_AttributeIterator, getRange);
ZEND_METHOD(Pango_Attribute_AttributeIterator, next);

static const zend_function_entry class_Pango_Attribute_AttributeIterator_methods[] = {
	ZEND_ME(Pango_Attribute_AttributeIterator, __construct, arginfo_class_Pango_Attribute_AttributeIterator___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(Pango_Attribute_AttributeIterator, get, arginfo_class_Pango_Attribute_AttributeIterator_get, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeIterator, getAttributes, arginfo_class_Pango_Attribute_AttributeIterator_getAttributes, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeIterator, getFont, arginfo_class_Pango_Attribute_AttributeIterator_getFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeIterator, getRange, arginfo_class_Pango_Attribute_AttributeIterator_getRange, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Attribute_AttributeIterator, next, arginfo_class_Pango_Attribute_AttributeIterator_next, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Attribute_AttributeIterator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "AttributeIterator", class_Pango_Attribute_AttributeIterator_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
