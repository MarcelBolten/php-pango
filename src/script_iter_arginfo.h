/* This is a generated file, edit script_iter.stub.php instead.
 * Stub hash: df2249593105dc66a77b297929836065545ce129 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_ScriptIter___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_ScriptIter_getRange, 0, 0, Pango\\ScriptIterRange, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_ScriptIter_next, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_ScriptIterRange___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, byteStart, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, byteEnd, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, script, Pango\\Script, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_ScriptIter, __construct);
ZEND_METHOD(Pango_ScriptIter, getRange);
ZEND_METHOD(Pango_ScriptIter, next);
ZEND_METHOD(Pango_ScriptIterRange, __construct);

static const zend_function_entry class_Pango_ScriptIter_methods[] = {
	ZEND_ME(Pango_ScriptIter, __construct, arginfo_class_Pango_ScriptIter___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_ScriptIter, getRange, arginfo_class_Pango_ScriptIter_getRange, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_ScriptIter, next, arginfo_class_Pango_ScriptIter_next, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_ScriptIterRange_methods[] = {
	ZEND_ME(Pango_ScriptIterRange, __construct, arginfo_class_Pango_ScriptIterRange___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_ScriptIter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "ScriptIter", class_Pango_ScriptIter_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_ScriptIterRange(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "ScriptIterRange", class_Pango_ScriptIterRange_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_text_default_value;
	ZVAL_UNDEF(&property_text_default_value);
	zend_string *property_text_name = zend_string_init("text", sizeof("text") - 1, true);
	zend_declare_typed_property(class_entry, property_text_name, &property_text_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release_ex(property_text_name, true);

	zval property_byteStart_default_value;
	ZVAL_UNDEF(&property_byteStart_default_value);
	zend_string *property_byteStart_name = zend_string_init("byteStart", sizeof("byteStart") - 1, true);
	zend_declare_typed_property(class_entry, property_byteStart_name, &property_byteStart_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_byteStart_name, true);

	zval property_byteEnd_default_value;
	ZVAL_UNDEF(&property_byteEnd_default_value);
	zend_string *property_byteEnd_name = zend_string_init("byteEnd", sizeof("byteEnd") - 1, true);
	zend_declare_typed_property(class_entry, property_byteEnd_name, &property_byteEnd_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_byteEnd_name, true);

	zval property_script_default_value;
	ZVAL_UNDEF(&property_script_default_value);
	zend_string *property_script_name = zend_string_init("script", sizeof("script") - 1, true);
	zend_string *property_script_class_Pango_Script = zend_string_init("Pango\\Script", sizeof("Pango\\Script")-1, 1);
	zend_declare_typed_property(class_entry, property_script_name, &property_script_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_script_class_Pango_Script, 0, 0));
	zend_string_release_ex(property_script_name, true);

	return class_entry;
}
