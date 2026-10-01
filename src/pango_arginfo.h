/* This is a generated file, edit pango.stub.php instead.
 * Stub hash: 51d8b95bf7eee1dcce493bb8bfac6b239f18718a */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_find_paragraph_boundary, 0, 1, Pango\\ParagraphBoundary, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_version_string, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_version_check, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, major, IS_LONG, 0, "VERSION_MAJOR")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, minor, IS_LONG, 0, "VERSION_MINOR")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, micro, IS_LONG, 0, "VERSION_MICRO")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_parse_markup, 0, 1, Pango\\MarkupParseResult, 0)
	ZEND_ARG_TYPE_INFO(0, markup, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, accelMarker, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_is_zero_width, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, char, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_log2vis_get_embedding_levels, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, baseDirection, Pango\\Direction, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_reorder_items, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, items, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_units_to_double, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, units, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Pango_units_from_double, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, d, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_quantize_line_geometry, 0, 2, Pango\\QuantizedLineGeometry, 0)
	ZEND_ARG_TYPE_INFO(0, thickness, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_shape, 0, 2, Pango\\GlyphString, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, analysis, Pango\\Analysis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_shape_full, 0, 4, Pango\\GlyphString, 0)
	ZEND_ARG_TYPE_INFO(0, paragraph_text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, analysis, Pango\\Analysis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_shape_item, 0, 2, Pango\\GlyphString, 0)
	ZEND_ARG_TYPE_INFO(0, paragraph_text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Pango\\Item, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, logAttrs, Pango\\LogAttrList, 1, "null")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, flags, Pango\\ShapeFlags, 0, "Pango\\ShapeFlags::None")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Pango_shape_with_flags, 0, 4, Pango\\GlyphString, 0)
	ZEND_ARG_TYPE_INFO(0, paragraph_text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, analysis, Pango\\Analysis, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, flags, Pango\\ShapeFlags, 0, "Pango\\ShapeFlags::None")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_ParagraphBoundary___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, delimiterByteIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nextStart, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_MarkupParseResult___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, attrList, Pango\\Attribute\\AttributeList, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, accelChar, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_FUNCTION(Pango_find_paragraph_boundary);
ZEND_FUNCTION(Pango_version);
ZEND_FUNCTION(Pango_version_string);
ZEND_FUNCTION(Pango_version_check);
ZEND_FUNCTION(Pango_parse_markup);
ZEND_FUNCTION(Pango_is_zero_width);
ZEND_FUNCTION(Pango_log2vis_get_embedding_levels);
ZEND_FUNCTION(Pango_reorder_items);
ZEND_FUNCTION(Pango_units_to_double);
ZEND_FUNCTION(Pango_units_from_double);
ZEND_FUNCTION(Pango_quantize_line_geometry);
ZEND_FUNCTION(Pango_shape);
ZEND_FUNCTION(Pango_shape_full);
ZEND_FUNCTION(Pango_shape_item);
ZEND_FUNCTION(Pango_shape_with_flags);
ZEND_METHOD(Pango_ParagraphBoundary, __construct);
ZEND_METHOD(Pango_MarkupParseResult, __construct);

static const zend_function_entry ext_functions[] = {
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "find_paragraph_boundary"), zif_Pango_find_paragraph_boundary, arginfo_Pango_find_paragraph_boundary, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "find_paragraph_boundary"), zif_Pango_find_paragraph_boundary, arginfo_Pango_find_paragraph_boundary, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version"), zif_Pango_version, arginfo_Pango_version, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version"), zif_Pango_version, arginfo_Pango_version, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version_string"), zif_Pango_version_string, arginfo_Pango_version_string, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version_string"), zif_Pango_version_string, arginfo_Pango_version_string, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version_check"), zif_Pango_version_check, arginfo_Pango_version_check, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "version_check"), zif_Pango_version_check, arginfo_Pango_version_check, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "parse_markup"), zif_Pango_parse_markup, arginfo_Pango_parse_markup, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "parse_markup"), zif_Pango_parse_markup, arginfo_Pango_parse_markup, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "is_zero_width"), zif_Pango_is_zero_width, arginfo_Pango_is_zero_width, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "is_zero_width"), zif_Pango_is_zero_width, arginfo_Pango_is_zero_width, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "log2vis_get_embedding_levels"), zif_Pango_log2vis_get_embedding_levels, arginfo_Pango_log2vis_get_embedding_levels, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "log2vis_get_embedding_levels"), zif_Pango_log2vis_get_embedding_levels, arginfo_Pango_log2vis_get_embedding_levels, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "reorder_items"), zif_Pango_reorder_items, arginfo_Pango_reorder_items, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "reorder_items"), zif_Pango_reorder_items, arginfo_Pango_reorder_items, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "units_to_double"), zif_Pango_units_to_double, arginfo_Pango_units_to_double, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "units_to_double"), zif_Pango_units_to_double, arginfo_Pango_units_to_double, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "units_from_double"), zif_Pango_units_from_double, arginfo_Pango_units_from_double, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "units_from_double"), zif_Pango_units_from_double, arginfo_Pango_units_from_double, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "quantize_line_geometry"), zif_Pango_quantize_line_geometry, arginfo_Pango_quantize_line_geometry, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "quantize_line_geometry"), zif_Pango_quantize_line_geometry, arginfo_Pango_quantize_line_geometry, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape"), zif_Pango_shape, arginfo_Pango_shape, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape"), zif_Pango_shape, arginfo_Pango_shape, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_full"), zif_Pango_shape_full, arginfo_Pango_shape_full, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_full"), zif_Pango_shape_full, arginfo_Pango_shape_full, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_item"), zif_Pango_shape_item, arginfo_Pango_shape_item, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_item"), zif_Pango_shape_item, arginfo_Pango_shape_item, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_with_flags"), zif_Pango_shape_with_flags, arginfo_Pango_shape_with_flags, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Pango", "shape_with_flags"), zif_Pango_shape_with_flags, arginfo_Pango_shape_with_flags, 0)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_Pango_ParagraphBoundary_methods[] = {
	ZEND_ME(Pango_ParagraphBoundary, __construct, arginfo_class_Pango_ParagraphBoundary___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_MarkupParseResult_methods[] = {
	ZEND_ME(Pango_MarkupParseResult, __construct, arginfo_class_Pango_MarkupParseResult___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_pango_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("Pango\\SCALE", PANGO_SCALE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\VERSION_MAJOR", PANGO_VERSION_MAJOR, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\VERSION_MINOR", PANGO_VERSION_MINOR, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\VERSION_MICRO", PANGO_VERSION_MICRO, CONST_PERSISTENT);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_NONE", PANGO_RENDER_COMPONENT_NONE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_PLAIN_GLYPH", PANGO_RENDER_COMPONENT_PLAIN_GLYPH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_COLOR_GLYPH", PANGO_RENDER_COMPONENT_COLOR_GLYPH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_BACKGROUND", PANGO_RENDER_COMPONENT_BACKGROUND, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_UNDERLINE", PANGO_RENDER_COMPONENT_UNDERLINE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_STRIKETHROUGH", PANGO_RENDER_COMPONENT_STRIKETHROUGH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_OVERLINE", PANGO_RENDER_COMPONENT_OVERLINE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("Pango\\RENDER_COMPONENT_ALL", PANGO_RENDER_COMPONENT_ALL, CONST_PERSISTENT);
#endif
}

static zend_class_entry *register_class_Pango_ParagraphBoundary(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "ParagraphBoundary", class_Pango_ParagraphBoundary_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_delimiterByteIndex_default_value;
	ZVAL_UNDEF(&property_delimiterByteIndex_default_value);
	zend_string *property_delimiterByteIndex_name = zend_string_init("delimiterByteIndex", sizeof("delimiterByteIndex") - 1, true);
	zend_declare_typed_property(class_entry, property_delimiterByteIndex_name, &property_delimiterByteIndex_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_delimiterByteIndex_name, true);

	zval property_nextStart_default_value;
	ZVAL_UNDEF(&property_nextStart_default_value);
	zend_string *property_nextStart_name = zend_string_init("nextStart", sizeof("nextStart") - 1, true);
	zend_declare_typed_property(class_entry, property_nextStart_name, &property_nextStart_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_nextStart_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_MarkupParseResult(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "MarkupParseResult", class_Pango_MarkupParseResult_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_attrList_default_value;
	ZVAL_UNDEF(&property_attrList_default_value);
	zend_string *property_attrList_name = zend_string_init("attrList", sizeof("attrList") - 1, true);
	zend_string *property_attrList_class_Pango_Attribute_AttributeList = zend_string_init("Pango\\Attribute\\AttributeList", sizeof("Pango\\Attribute\\AttributeList")-1, 1);
	zend_declare_typed_property(class_entry, property_attrList_name, &property_attrList_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_attrList_class_Pango_Attribute_AttributeList, 0, 0));
	zend_string_release_ex(property_attrList_name, true);

	zval property_text_default_value;
	ZVAL_UNDEF(&property_text_default_value);
	zend_string *property_text_name = zend_string_init("text", sizeof("text") - 1, true);
	zend_declare_typed_property(class_entry, property_text_name, &property_text_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release_ex(property_text_name, true);

	zval property_accelChar_default_value;
	ZVAL_UNDEF(&property_accelChar_default_value);
	zend_string *property_accelChar_name = zend_string_init("accelChar", sizeof("accelChar") - 1, true);
	zend_declare_typed_property(class_entry, property_accelChar_name, &property_accelChar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release_ex(property_accelChar_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_QuantizedLineGeometry(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "QuantizedLineGeometry", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_thickness_default_value;
	ZVAL_UNDEF(&property_thickness_default_value);
	zend_string *property_thickness_name = zend_string_init("thickness", sizeof("thickness") - 1, true);
	zend_declare_typed_property(class_entry, property_thickness_name, &property_thickness_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_thickness_name, true);

	zval property_position_default_value;
	ZVAL_UNDEF(&property_position_default_value);
	zend_string *property_position_name = zend_string_init("position", sizeof("position") - 1, true);
	zend_declare_typed_property(class_entry, property_position_name, &property_position_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_position_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_ShapeFlags(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\ShapeFlags", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_SHAPE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_RoundPositions_value;
	ZVAL_LONG(&enum_case_RoundPositions_value, PANGO_SHAPE_ROUND_POSITIONS);
	zend_enum_add_case_cstr(class_entry, "RoundPositions", &enum_case_RoundPositions_value);

	return class_entry;
}
