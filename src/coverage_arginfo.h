/* This is a generated file, edit coverage.stub.php instead.
 * Stub hash: 32dc028581ec03f7cbaf5bc6f775b834df31f44e */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Coverage___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Coverage_get, 0, 1, Pango\\CoverageLevel, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Coverage_set, 0, 2, Pango\\Coverage, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, level, Pango\\CoverageLevel, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Coverage, __construct);
ZEND_METHOD(Pango_Coverage, get);
ZEND_METHOD(Pango_Coverage, set);

static const zend_function_entry class_Pango_Coverage_methods[] = {
	ZEND_ME(Pango_Coverage, __construct, arginfo_class_Pango_Coverage___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Coverage, get, arginfo_class_Pango_Coverage_get, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Coverage, set, arginfo_class_Pango_Coverage_set, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Coverage(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Coverage", class_Pango_Coverage_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce.ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_CoverageLevel(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\CoverageLevel", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_COVERAGE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Exact_value;
	ZVAL_LONG(&enum_case_Exact_value, PANGO_COVERAGE_EXACT);
	zend_enum_add_case_cstr(class_entry, "Exact", &enum_case_Exact_value);

	return class_entry;
}
