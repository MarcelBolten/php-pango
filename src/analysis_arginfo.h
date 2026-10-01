/* This is a generated file, edit analysis.stub.php instead.
 * Stub hash: 63b3a7a018d41fa1cd0355f5fe7e2101397703d6 */

static zend_class_entry *register_class_Pango_Analysis(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Analysis", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval const_FLAG_IS_ELLIPSIS_value;
	ZVAL_LONG(&const_FLAG_IS_ELLIPSIS_value, PANGO_ANALYSIS_FLAG_IS_ELLIPSIS);
	zend_string *const_FLAG_IS_ELLIPSIS_name = zend_string_init_interned("FLAG_IS_ELLIPSIS", sizeof("FLAG_IS_ELLIPSIS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_FLAG_IS_ELLIPSIS_name, &const_FLAG_IS_ELLIPSIS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_FLAG_IS_ELLIPSIS_name, true);

	zval const_FLAG_NEED_HYPHEN_value;
	ZVAL_LONG(&const_FLAG_NEED_HYPHEN_value, PANGO_ANALYSIS_FLAG_NEED_HYPHEN);
	zend_string *const_FLAG_NEED_HYPHEN_name = zend_string_init_interned("FLAG_NEED_HYPHEN", sizeof("FLAG_NEED_HYPHEN") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_FLAG_NEED_HYPHEN_name, &const_FLAG_NEED_HYPHEN_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_FLAG_NEED_HYPHEN_name, true);

	zval const_FLAG_CENTERED_BASELINE_value;
	ZVAL_LONG(&const_FLAG_CENTERED_BASELINE_value, PANGO_ANALYSIS_FLAG_CENTERED_BASELINE);
	zend_string *const_FLAG_CENTERED_BASELINE_name = zend_string_init_interned("FLAG_CENTERED_BASELINE", sizeof("FLAG_CENTERED_BASELINE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_FLAG_CENTERED_BASELINE_name, &const_FLAG_CENTERED_BASELINE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_FLAG_CENTERED_BASELINE_name, true);

	zval property_font_default_value;
	ZVAL_UNDEF(&property_font_default_value);
	zend_string *property_font_name = zend_string_init("font", sizeof("font") - 1, true);
	zend_string *property_font_class_Pango_Font = zend_string_init("Pango\\Font", sizeof("Pango\\Font")-1, 1);
	zend_declare_typed_property(class_entry, property_font_name, &property_font_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_font_class_Pango_Font, 0, 0));
	zend_string_release_ex(property_font_name, true);

	zval property_level_default_value;
	ZVAL_UNDEF(&property_level_default_value);
	zend_string *property_level_name = zend_string_init("level", sizeof("level") - 1, true);
	zend_declare_typed_property(class_entry, property_level_name, &property_level_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_level_name, true);

	zval property_gravity_default_value;
	ZVAL_UNDEF(&property_gravity_default_value);
	zend_string *property_gravity_name = zend_string_init("gravity", sizeof("gravity") - 1, true);
	zend_string *property_gravity_class_Pango_Gravity = zend_string_init("Pango\\Gravity", sizeof("Pango\\Gravity")-1, 1);
	zend_declare_typed_property(class_entry, property_gravity_name, &property_gravity_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_gravity_class_Pango_Gravity, 0, 0));
	zend_string_release_ex(property_gravity_name, true);

	zval property_flags_default_value;
	ZVAL_UNDEF(&property_flags_default_value);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, true);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_flags_name, true);

	zval property_script_default_value;
	ZVAL_UNDEF(&property_script_default_value);
	zend_string *property_script_name = zend_string_init("script", sizeof("script") - 1, true);
	zend_string *property_script_class_Pango_Script = zend_string_init("Pango\\Script", sizeof("Pango\\Script")-1, 1);
	zend_declare_typed_property(class_entry, property_script_name, &property_script_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_script_class_Pango_Script, 0, 0));
	zend_string_release_ex(property_script_name, true);

	zval property_language_default_value;
	ZVAL_UNDEF(&property_language_default_value);
	zend_string *property_language_name = zend_string_init("language", sizeof("language") - 1, true);
	zend_string *property_language_class_Pango_Language = zend_string_init("Pango\\Language", sizeof("Pango\\Language")-1, 1);
	zend_declare_typed_property(class_entry, property_language_name, &property_language_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_language_class_Pango_Language, 0, 0));
	zend_string_release_ex(property_language_name, true);

	zval property_extraAttrs_default_value;
	ZVAL_UNDEF(&property_extraAttrs_default_value);
	zend_string *property_extraAttrs_name = zend_string_init("extraAttrs", sizeof("extraAttrs") - 1, true);
	zend_declare_typed_property(class_entry, property_extraAttrs_name, &property_extraAttrs_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release_ex(property_extraAttrs_name, true);

	return class_entry;
}
