/* This is a generated file, edit font_set.stub.php instead.
 * Stub hash: 081b7d15cfc262c112b3cec8e7ae27e97e299b2c */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontSet_find, 0, 1, Pango\\Font, 1)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontSet_getFont, 0, 1, Pango\\Font, 0)
	ZEND_ARG_TYPE_INFO(0, letter, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontSet_getFontForCodepoint, 0, 1, Pango\\Font, 0)
	ZEND_ARG_TYPE_INFO(0, codepoint, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontSet_getMetrics, 0, 0, Pango\\FontMetrics, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_FontSet, find);
ZEND_METHOD(Pango_FontSet, getFont);
ZEND_METHOD(Pango_FontSet, getFontForCodepoint);
ZEND_METHOD(Pango_FontSet, getMetrics);

static const zend_function_entry class_Pango_FontSet_methods[] = {
	ZEND_ME(Pango_FontSet, find, arginfo_class_Pango_FontSet_find, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontSet, getFont, arginfo_class_Pango_FontSet_getFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontSet, getFontForCodepoint, arginfo_class_Pango_FontSet_getFontForCodepoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontSet, getMetrics, arginfo_class_Pango_FontSet_getMetrics, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontSet(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontSet", class_Pango_FontSet_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_READONLY_CLASS;
#endif

	return class_entry;
}
