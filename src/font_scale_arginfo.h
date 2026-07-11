/* This is a generated file, edit font_scale.stub.php instead.
 * Stub hash: 8b637c14a070edc7c9b544da7462c4d0bb242497 */

static zend_class_entry *register_class_Pango_FontScale(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\FontScale", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_FONT_SCALE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Superscript_value;
	ZVAL_LONG(&enum_case_Superscript_value, PANGO_FONT_SCALE_SUPERSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Superscript", &enum_case_Superscript_value);

	zval enum_case_Subscript_value;
	ZVAL_LONG(&enum_case_Subscript_value, PANGO_FONT_SCALE_SUBSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Subscript", &enum_case_Subscript_value);

	zval enum_case_SmallCaps_value;
	ZVAL_LONG(&enum_case_SmallCaps_value, PANGO_FONT_SCALE_SMALL_CAPS);
	zend_enum_add_case_cstr(class_entry, "SmallCaps", &enum_case_SmallCaps_value);

	return class_entry;
}
