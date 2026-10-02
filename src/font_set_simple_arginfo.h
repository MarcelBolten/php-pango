/* This is a generated file, edit font_set_simple.stub.php instead.
 * Stub hash: cbe901a136be23b6b976159472bb8d7851a3508a */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_FontSetSimple___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, language, Pango\\Language, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontSetSimple_append, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, Pango\\Font, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_FontSetSimple, __construct);
ZEND_METHOD(Pango_FontSetSimple, append);

static const zend_function_entry class_Pango_FontSetSimple_methods[] = {
	ZEND_ME(Pango_FontSetSimple, __construct, arginfo_class_Pango_FontSetSimple___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontSetSimple, append, arginfo_class_Pango_FontSetSimple_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontSetSimple(zend_class_entry *class_entry_Pango_FontSet)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontSetSimple", class_Pango_FontSetSimple_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_FontSet, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_FontSet);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_size_default_value;
	ZVAL_UNDEF(&property_size_default_value);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, true);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_size_name, true);

	return class_entry;
}
