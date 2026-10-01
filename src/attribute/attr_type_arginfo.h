/* This is a generated file, edit attr_type.stub.php instead.
 * Stub hash: 67b3f3ac7b7ca19743119129730fd9def3868ad2 */

static zend_class_entry *register_class_Pango_Attribute_Type(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Attribute\\Type", IS_LONG, NULL);

	zval enum_case_Invalid_value;
	ZVAL_LONG(&enum_case_Invalid_value, PANGO_ATTR_INVALID);
	zend_enum_add_case_cstr(class_entry, "Invalid", &enum_case_Invalid_value);

	zval enum_case_Language_value;
	ZVAL_LONG(&enum_case_Language_value, PANGO_ATTR_LANGUAGE);
	zend_enum_add_case_cstr(class_entry, "Language", &enum_case_Language_value);

	zval enum_case_Family_value;
	ZVAL_LONG(&enum_case_Family_value, PANGO_ATTR_FAMILY);
	zend_enum_add_case_cstr(class_entry, "Family", &enum_case_Family_value);

	zval enum_case_Style_value;
	ZVAL_LONG(&enum_case_Style_value, PANGO_ATTR_STYLE);
	zend_enum_add_case_cstr(class_entry, "Style", &enum_case_Style_value);

	zval enum_case_Weight_value;
	ZVAL_LONG(&enum_case_Weight_value, PANGO_ATTR_WEIGHT);
	zend_enum_add_case_cstr(class_entry, "Weight", &enum_case_Weight_value);

	zval enum_case_Variant_value;
	ZVAL_LONG(&enum_case_Variant_value, PANGO_ATTR_VARIANT);
	zend_enum_add_case_cstr(class_entry, "Variant", &enum_case_Variant_value);

	zval enum_case_Stretch_value;
	ZVAL_LONG(&enum_case_Stretch_value, PANGO_ATTR_STRETCH);
	zend_enum_add_case_cstr(class_entry, "Stretch", &enum_case_Stretch_value);

	zval enum_case_Size_value;
	ZVAL_LONG(&enum_case_Size_value, PANGO_ATTR_SIZE);
	zend_enum_add_case_cstr(class_entry, "Size", &enum_case_Size_value);

	zval enum_case_FontDesc_value;
	ZVAL_LONG(&enum_case_FontDesc_value, PANGO_ATTR_FONT_DESC);
	zend_enum_add_case_cstr(class_entry, "FontDesc", &enum_case_FontDesc_value);

	zval enum_case_Foreground_value;
	ZVAL_LONG(&enum_case_Foreground_value, PANGO_ATTR_FOREGROUND);
	zend_enum_add_case_cstr(class_entry, "Foreground", &enum_case_Foreground_value);

	zval enum_case_Background_value;
	ZVAL_LONG(&enum_case_Background_value, PANGO_ATTR_BACKGROUND);
	zend_enum_add_case_cstr(class_entry, "Background", &enum_case_Background_value);

	zval enum_case_Underline_value;
	ZVAL_LONG(&enum_case_Underline_value, PANGO_ATTR_UNDERLINE);
	zend_enum_add_case_cstr(class_entry, "Underline", &enum_case_Underline_value);

	zval enum_case_Strikethrough_value;
	ZVAL_LONG(&enum_case_Strikethrough_value, PANGO_ATTR_STRIKETHROUGH);
	zend_enum_add_case_cstr(class_entry, "Strikethrough", &enum_case_Strikethrough_value);

	zval enum_case_Rise_value;
	ZVAL_LONG(&enum_case_Rise_value, PANGO_ATTR_RISE);
	zend_enum_add_case_cstr(class_entry, "Rise", &enum_case_Rise_value);

	zval enum_case_Shape_value;
	ZVAL_LONG(&enum_case_Shape_value, PANGO_ATTR_SHAPE);
	zend_enum_add_case_cstr(class_entry, "Shape", &enum_case_Shape_value);

	zval enum_case_Scale_value;
	ZVAL_LONG(&enum_case_Scale_value, PANGO_ATTR_SCALE);
	zend_enum_add_case_cstr(class_entry, "Scale", &enum_case_Scale_value);

	zval enum_case_Fallback_value;
	ZVAL_LONG(&enum_case_Fallback_value, PANGO_ATTR_FALLBACK);
	zend_enum_add_case_cstr(class_entry, "Fallback", &enum_case_Fallback_value);

	zval enum_case_LetterSpacing_value;
	ZVAL_LONG(&enum_case_LetterSpacing_value, PANGO_ATTR_LETTER_SPACING);
	zend_enum_add_case_cstr(class_entry, "LetterSpacing", &enum_case_LetterSpacing_value);

	zval enum_case_UnderlineColor_value;
	ZVAL_LONG(&enum_case_UnderlineColor_value, PANGO_ATTR_UNDERLINE_COLOR);
	zend_enum_add_case_cstr(class_entry, "UnderlineColor", &enum_case_UnderlineColor_value);

	zval enum_case_StrikethroughColor_value;
	ZVAL_LONG(&enum_case_StrikethroughColor_value, PANGO_ATTR_STRIKETHROUGH_COLOR);
	zend_enum_add_case_cstr(class_entry, "StrikethroughColor", &enum_case_StrikethroughColor_value);

	zval enum_case_AbsoluteSize_value;
	ZVAL_LONG(&enum_case_AbsoluteSize_value, PANGO_ATTR_ABSOLUTE_SIZE);
	zend_enum_add_case_cstr(class_entry, "AbsoluteSize", &enum_case_AbsoluteSize_value);

	zval enum_case_Gravity_value;
	ZVAL_LONG(&enum_case_Gravity_value, PANGO_ATTR_GRAVITY);
	zend_enum_add_case_cstr(class_entry, "Gravity", &enum_case_Gravity_value);

	zval enum_case_GravityHint_value;
	ZVAL_LONG(&enum_case_GravityHint_value, PANGO_ATTR_GRAVITY_HINT);
	zend_enum_add_case_cstr(class_entry, "GravityHint", &enum_case_GravityHint_value);

	zval enum_case_FontFeatures_value;
	ZVAL_LONG(&enum_case_FontFeatures_value, PANGO_ATTR_FONT_FEATURES);
	zend_enum_add_case_cstr(class_entry, "FontFeatures", &enum_case_FontFeatures_value);

	zval enum_case_ForegroundAlpha_value;
	ZVAL_LONG(&enum_case_ForegroundAlpha_value, PANGO_ATTR_FOREGROUND_ALPHA);
	zend_enum_add_case_cstr(class_entry, "ForegroundAlpha", &enum_case_ForegroundAlpha_value);

	zval enum_case_BackgroundAlpha_value;
	ZVAL_LONG(&enum_case_BackgroundAlpha_value, PANGO_ATTR_BACKGROUND_ALPHA);
	zend_enum_add_case_cstr(class_entry, "BackgroundAlpha", &enum_case_BackgroundAlpha_value);

	zval enum_case_AllowBreaks_value;
	ZVAL_LONG(&enum_case_AllowBreaks_value, PANGO_ATTR_ALLOW_BREAKS);
	zend_enum_add_case_cstr(class_entry, "AllowBreaks", &enum_case_AllowBreaks_value);

	zval enum_case_Show_value;
	ZVAL_LONG(&enum_case_Show_value, PANGO_ATTR_SHOW);
	zend_enum_add_case_cstr(class_entry, "Show", &enum_case_Show_value);

	zval enum_case_InsertHyphens_value;
	ZVAL_LONG(&enum_case_InsertHyphens_value, PANGO_ATTR_INSERT_HYPHENS);
	zend_enum_add_case_cstr(class_entry, "InsertHyphens", &enum_case_InsertHyphens_value);

	zval enum_case_Overline_value;
	ZVAL_LONG(&enum_case_Overline_value, PANGO_ATTR_OVERLINE);
	zend_enum_add_case_cstr(class_entry, "Overline", &enum_case_Overline_value);

	zval enum_case_OverlineColor_value;
	ZVAL_LONG(&enum_case_OverlineColor_value, PANGO_ATTR_OVERLINE_COLOR);
	zend_enum_add_case_cstr(class_entry, "OverlineColor", &enum_case_OverlineColor_value);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_LineHeight_value;
	ZVAL_LONG(&enum_case_LineHeight_value, PANGO_ATTR_LINE_HEIGHT);
	zend_enum_add_case_cstr(class_entry, "LineHeight", &enum_case_LineHeight_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_AbsoluteLineHeight_value;
	ZVAL_LONG(&enum_case_AbsoluteLineHeight_value, PANGO_ATTR_ABSOLUTE_LINE_HEIGHT);
	zend_enum_add_case_cstr(class_entry, "AbsoluteLineHeight", &enum_case_AbsoluteLineHeight_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_TextTransform_value;
	ZVAL_LONG(&enum_case_TextTransform_value, PANGO_ATTR_TEXT_TRANSFORM);
	zend_enum_add_case_cstr(class_entry, "TextTransform", &enum_case_TextTransform_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Word_value;
	ZVAL_LONG(&enum_case_Word_value, PANGO_ATTR_WORD);
	zend_enum_add_case_cstr(class_entry, "Word", &enum_case_Word_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Sentence_value;
	ZVAL_LONG(&enum_case_Sentence_value, PANGO_ATTR_SENTENCE);
	zend_enum_add_case_cstr(class_entry, "Sentence", &enum_case_Sentence_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_BaselineShift_value;
	ZVAL_LONG(&enum_case_BaselineShift_value, PANGO_ATTR_BASELINE_SHIFT);
	zend_enum_add_case_cstr(class_entry, "BaselineShift", &enum_case_BaselineShift_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_FontScale_value;
	ZVAL_LONG(&enum_case_FontScale_value, PANGO_ATTR_FONT_SCALE);
	zend_enum_add_case_cstr(class_entry, "FontScale", &enum_case_FontScale_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_Width_value;
	ZVAL_LONG(&enum_case_Width_value, PANGO_ATTR_WIDTH);
	zend_enum_add_case_cstr(class_entry, "Width", &enum_case_Width_value);
#endif

	return class_entry;
}
