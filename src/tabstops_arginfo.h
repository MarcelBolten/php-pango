/* This is a generated file, edit tabstops.stub.php instead.
 * Stub hash: 2cab8704d17355c6e92b26aacbefe14cc6b09844 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_TabStops___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, tabStops, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_TabStops_fromString, 0, 1, Pango\\TabStops, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops_add, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tabStop, Pango\\TabStop, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops_remove, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_TabStops_set, 0, 2, Pango\\TabStops, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, tabStop, Pango\\TabStop, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_TabStops_getTab, 0, 1, Pango\\TabStop, 1)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops_getTabs, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops_getSize, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_TabStops_arePositionsInPixels, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_TabStop___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, alignment, Pango\\TabAlign, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, decimalChar, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_TabStops, __construct);
ZEND_METHOD(Pango_TabStops, __toString);
ZEND_METHOD(Pango_TabStops, fromString);
ZEND_METHOD(Pango_TabStops, add);
ZEND_METHOD(Pango_TabStops, remove);
ZEND_METHOD(Pango_TabStops, set);
ZEND_METHOD(Pango_TabStops, getTab);
ZEND_METHOD(Pango_TabStops, getTabs);
ZEND_METHOD(Pango_TabStops, getSize);
ZEND_METHOD(Pango_TabStops, arePositionsInPixels);
ZEND_METHOD(Pango_TabStop, __construct);

static const zend_function_entry class_Pango_TabStops_methods[] = {
	ZEND_ME(Pango_TabStops, __construct, arginfo_class_Pango_TabStops___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, __toString, arginfo_class_Pango_TabStops___toString, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, fromString, arginfo_class_Pango_TabStops_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_TabStops, add, arginfo_class_Pango_TabStops_add, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, remove, arginfo_class_Pango_TabStops_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, set, arginfo_class_Pango_TabStops_set, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, getTab, arginfo_class_Pango_TabStops_getTab, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, getTabs, arginfo_class_Pango_TabStops_getTabs, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, getSize, arginfo_class_Pango_TabStops_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_TabStops, arePositionsInPixels, arginfo_class_Pango_TabStops_arePositionsInPixels, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_TabStop_methods[] = {
	ZEND_ME(Pango_TabStop, __construct, arginfo_class_Pango_TabStop___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_TabStops(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "TabStops", class_Pango_TabStops_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce.ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_TabStop(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "TabStop", class_Pango_TabStop_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	zval property_alignment_default_value;
	ZVAL_UNDEF(&property_alignment_default_value);
	zend_string *property_alignment_name = zend_string_init("alignment", sizeof("alignment") - 1, true);
	zend_string *property_alignment_class_Pango_TabAlign = zend_string_init("Pango\\TabAlign", sizeof("Pango\\TabAlign")-1, 1);
	zend_declare_typed_property(class_entry, property_alignment_name, &property_alignment_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_alignment_class_Pango_TabAlign, 0, 0));
	zend_string_release_ex(property_alignment_name, true);

	zval property_position_default_value;
	ZVAL_UNDEF(&property_position_default_value);
	zend_string *property_position_name = zend_string_init("position", sizeof("position") - 1, true);
	zend_declare_typed_property(class_entry, property_position_name, &property_position_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_position_name, true);

	zval property_decimalChar_default_value;
	ZVAL_UNDEF(&property_decimalChar_default_value);
	zend_string *property_decimalChar_name = zend_string_init("decimalChar", sizeof("decimalChar") - 1, true);
	zend_declare_typed_property(class_entry, property_decimalChar_name, &property_decimalChar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release_ex(property_decimalChar_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_TabStopPixel(zend_class_entry *class_entry_Pango_TabStop)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "TabStopPixel", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_TabStop, ZEND_ACC_FINAL);
#else
	ce.ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_TabStop);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_TabAlign(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\TabAlign", IS_LONG, NULL);

	zval enum_case_Left_value;
	ZVAL_LONG(&enum_case_Left_value, PANGO_TAB_LEFT);
	zend_enum_add_case_cstr(class_entry, "Left", &enum_case_Left_value);

	zval enum_case_Right_value;
	ZVAL_LONG(&enum_case_Right_value, PANGO_TAB_RIGHT);
	zend_enum_add_case_cstr(class_entry, "Right", &enum_case_Right_value);

	zval enum_case_Center_value;
	ZVAL_LONG(&enum_case_Center_value, PANGO_TAB_CENTER);
	zend_enum_add_case_cstr(class_entry, "Center", &enum_case_Center_value);

	zval enum_case_Decimal_value;
	ZVAL_LONG(&enum_case_Decimal_value, PANGO_TAB_DECIMAL);
	zend_enum_add_case_cstr(class_entry, "Decimal", &enum_case_Decimal_value);

	return class_entry;
}
