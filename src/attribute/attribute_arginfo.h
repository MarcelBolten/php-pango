/* This is a generated file, edit attribute.stub.php instead.
 * Stub hash: 2fb34bf110ebcff8d47e1a9098f6f7115d3a4507 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Attribute_Attribute_equalValue, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, other, Pango\\Attribute\\Attribute, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_LanguageAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Language, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_FamilyAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_StyleAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Style, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_WeightAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Weight, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_VariantAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Variant, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_StretchAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Stretch, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_SizeAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_AbsoluteSizeAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_FontDescriptionAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, desc, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_ForegroundAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, color, Pango\\Color, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_BackgroundAttribute___construct arginfo_class_Pango_Attribute_ForegroundAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_UnderlineAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\\125nderline, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_StrikethroughAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_RiseAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_ScaleAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_FallbackAttribute___construct arginfo_class_Pango_Attribute_StrikethroughAttribute___construct

#define arginfo_class_Pango_Attribute_LetterSpacingAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

#define arginfo_class_Pango_Attribute_UnderlineColorAttribute___construct arginfo_class_Pango_Attribute_ForegroundAttribute___construct

#define arginfo_class_Pango_Attribute_StrikethroughColorAttribute___construct arginfo_class_Pango_Attribute_ForegroundAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_GravityAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Gravity, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_GravityHintAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\GravityHint, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_FontFeaturesAttribute___construct arginfo_class_Pango_Attribute_FamilyAttribute___construct

#define arginfo_class_Pango_Attribute_ForegroundAlphaAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

#define arginfo_class_Pango_Attribute_BackgroundAlphaAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

#define arginfo_class_Pango_Attribute_AllowBreaksAttribute___construct arginfo_class_Pango_Attribute_StrikethroughAttribute___construct

#define arginfo_class_Pango_Attribute_ShowAttribute___construct arginfo_class_Pango_Attribute_SizeAttribute___construct

#define arginfo_class_Pango_Attribute_InsertHyphensAttribute___construct arginfo_class_Pango_Attribute_StrikethroughAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_OverlineAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Overline, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_OverlineColorAttribute___construct arginfo_class_Pango_Attribute_ForegroundAttribute___construct

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_LineHeightAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_AbsoluteLineHeightAttribute___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_TextTransformAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\TextTransform, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_WordAttribute___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Attribute_SentenceAttribute___construct arginfo_class_Pango_Attribute_WordAttribute___construct

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_BaselineShiftAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, value, Pango\\BaselineShift, MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_FontScaleAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\FontScale, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Attribute_WidthAttribute___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, value, Pango\\Width, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, startIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_FROM_TEXT_BEGINNING")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, endIndex, IS_LONG, 0, "Pango\\Attribute\\Attribute::INDEX_TO_TEXT_END")
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(Pango_Attribute_Attribute, equalValue);
ZEND_METHOD(Pango_Attribute_LanguageAttribute, __construct);
ZEND_METHOD(Pango_Attribute_FamilyAttribute, __construct);
ZEND_METHOD(Pango_Attribute_StyleAttribute, __construct);
ZEND_METHOD(Pango_Attribute_WeightAttribute, __construct);
ZEND_METHOD(Pango_Attribute_VariantAttribute, __construct);
ZEND_METHOD(Pango_Attribute_StretchAttribute, __construct);
ZEND_METHOD(Pango_Attribute_SizeAttribute, __construct);
ZEND_METHOD(Pango_Attribute_AbsoluteSizeAttribute, __construct);
ZEND_METHOD(Pango_Attribute_FontDescriptionAttribute, __construct);
ZEND_METHOD(Pango_Attribute_ForegroundAttribute, __construct);
ZEND_METHOD(Pango_Attribute_BackgroundAttribute, __construct);
ZEND_METHOD(Pango_Attribute_UnderlineAttribute, __construct);
ZEND_METHOD(Pango_Attribute_StrikethroughAttribute, __construct);
ZEND_METHOD(Pango_Attribute_RiseAttribute, __construct);
ZEND_METHOD(Pango_Attribute_ScaleAttribute, __construct);
ZEND_METHOD(Pango_Attribute_FallbackAttribute, __construct);
ZEND_METHOD(Pango_Attribute_LetterSpacingAttribute, __construct);
ZEND_METHOD(Pango_Attribute_UnderlineColorAttribute, __construct);
ZEND_METHOD(Pango_Attribute_StrikethroughColorAttribute, __construct);
ZEND_METHOD(Pango_Attribute_GravityAttribute, __construct);
ZEND_METHOD(Pango_Attribute_GravityHintAttribute, __construct);
ZEND_METHOD(Pango_Attribute_FontFeaturesAttribute, __construct);
ZEND_METHOD(Pango_Attribute_ForegroundAlphaAttribute, __construct);
ZEND_METHOD(Pango_Attribute_BackgroundAlphaAttribute, __construct);
ZEND_METHOD(Pango_Attribute_AllowBreaksAttribute, __construct);
ZEND_METHOD(Pango_Attribute_ShowAttribute, __construct);
ZEND_METHOD(Pango_Attribute_InsertHyphensAttribute, __construct);
ZEND_METHOD(Pango_Attribute_OverlineAttribute, __construct);
ZEND_METHOD(Pango_Attribute_OverlineColorAttribute, __construct);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_METHOD(Pango_Attribute_LineHeightAttribute, __construct);
ZEND_METHOD(Pango_Attribute_AbsoluteLineHeightAttribute, __construct);
ZEND_METHOD(Pango_Attribute_TextTransformAttribute, __construct);
ZEND_METHOD(Pango_Attribute_WordAttribute, __construct);
ZEND_METHOD(Pango_Attribute_SentenceAttribute, __construct);
ZEND_METHOD(Pango_Attribute_BaselineShiftAttribute, __construct);
ZEND_METHOD(Pango_Attribute_FontScaleAttribute, __construct);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_METHOD(Pango_Attribute_WidthAttribute, __construct);
#endif

static const zend_function_entry class_Pango_Attribute_Attribute_methods[] = {
	ZEND_ME(Pango_Attribute_Attribute, equalValue, arginfo_class_Pango_Attribute_Attribute_equalValue, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_LanguageAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_LanguageAttribute, __construct, arginfo_class_Pango_Attribute_LanguageAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_FamilyAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_FamilyAttribute, __construct, arginfo_class_Pango_Attribute_FamilyAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_StyleAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_StyleAttribute, __construct, arginfo_class_Pango_Attribute_StyleAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_WeightAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_WeightAttribute, __construct, arginfo_class_Pango_Attribute_WeightAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_VariantAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_VariantAttribute, __construct, arginfo_class_Pango_Attribute_VariantAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_StretchAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_StretchAttribute, __construct, arginfo_class_Pango_Attribute_StretchAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_SizeAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_SizeAttribute, __construct, arginfo_class_Pango_Attribute_SizeAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_AbsoluteSizeAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_AbsoluteSizeAttribute, __construct, arginfo_class_Pango_Attribute_AbsoluteSizeAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_FontDescriptionAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_FontDescriptionAttribute, __construct, arginfo_class_Pango_Attribute_FontDescriptionAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_ForegroundAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_ForegroundAttribute, __construct, arginfo_class_Pango_Attribute_ForegroundAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_BackgroundAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_BackgroundAttribute, __construct, arginfo_class_Pango_Attribute_BackgroundAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_UnderlineAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_UnderlineAttribute, __construct, arginfo_class_Pango_Attribute_UnderlineAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_StrikethroughAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_StrikethroughAttribute, __construct, arginfo_class_Pango_Attribute_StrikethroughAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_RiseAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_RiseAttribute, __construct, arginfo_class_Pango_Attribute_RiseAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_ScaleAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_ScaleAttribute, __construct, arginfo_class_Pango_Attribute_ScaleAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_FallbackAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_FallbackAttribute, __construct, arginfo_class_Pango_Attribute_FallbackAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_LetterSpacingAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_LetterSpacingAttribute, __construct, arginfo_class_Pango_Attribute_LetterSpacingAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_UnderlineColorAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_UnderlineColorAttribute, __construct, arginfo_class_Pango_Attribute_UnderlineColorAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_StrikethroughColorAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_StrikethroughColorAttribute, __construct, arginfo_class_Pango_Attribute_StrikethroughColorAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_GravityAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_GravityAttribute, __construct, arginfo_class_Pango_Attribute_GravityAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_GravityHintAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_GravityHintAttribute, __construct, arginfo_class_Pango_Attribute_GravityHintAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_FontFeaturesAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_FontFeaturesAttribute, __construct, arginfo_class_Pango_Attribute_FontFeaturesAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_ForegroundAlphaAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_ForegroundAlphaAttribute, __construct, arginfo_class_Pango_Attribute_ForegroundAlphaAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_BackgroundAlphaAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_BackgroundAlphaAttribute, __construct, arginfo_class_Pango_Attribute_BackgroundAlphaAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_AllowBreaksAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_AllowBreaksAttribute, __construct, arginfo_class_Pango_Attribute_AllowBreaksAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_ShowAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_ShowAttribute, __construct, arginfo_class_Pango_Attribute_ShowAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_InsertHyphensAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_InsertHyphensAttribute, __construct, arginfo_class_Pango_Attribute_InsertHyphensAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_OverlineAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_OverlineAttribute, __construct, arginfo_class_Pango_Attribute_OverlineAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Attribute_OverlineColorAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_OverlineColorAttribute, __construct, arginfo_class_Pango_Attribute_OverlineColorAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_LineHeightAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_LineHeightAttribute, __construct, arginfo_class_Pango_Attribute_LineHeightAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_AbsoluteLineHeightAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_AbsoluteLineHeightAttribute, __construct, arginfo_class_Pango_Attribute_AbsoluteLineHeightAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_TextTransformAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_TextTransformAttribute, __construct, arginfo_class_Pango_Attribute_TextTransformAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_WordAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_WordAttribute, __construct, arginfo_class_Pango_Attribute_WordAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_SentenceAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_SentenceAttribute, __construct, arginfo_class_Pango_Attribute_SentenceAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_BaselineShiftAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_BaselineShiftAttribute, __construct, arginfo_class_Pango_Attribute_BaselineShiftAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static const zend_function_entry class_Pango_Attribute_FontScaleAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_FontScaleAttribute, __construct, arginfo_class_Pango_Attribute_FontScaleAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
static const zend_function_entry class_Pango_Attribute_WidthAttribute_methods[] = {
	ZEND_ME(Pango_Attribute_WidthAttribute, __construct, arginfo_class_Pango_Attribute_WidthAttribute___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

static zend_class_entry *register_class_Pango_Attribute_Attribute(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "Attribute", class_Pango_Attribute_Attribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_ABSTRACT|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT|ZEND_ACC_READONLY_CLASS;
#endif

	zval const_INDEX_FROM_TEXT_BEGINNING_value;
	ZVAL_LONG(&const_INDEX_FROM_TEXT_BEGINNING_value, PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING);
	zend_string *const_INDEX_FROM_TEXT_BEGINNING_name = zend_string_init_interned("INDEX_FROM_TEXT_BEGINNING", sizeof("INDEX_FROM_TEXT_BEGINNING") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_INDEX_FROM_TEXT_BEGINNING_name, &const_INDEX_FROM_TEXT_BEGINNING_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_INDEX_FROM_TEXT_BEGINNING_name, true);

	zval const_INDEX_TO_TEXT_END_value;
	ZVAL_LONG(&const_INDEX_TO_TEXT_END_value, PHP_PANGO_ATTR_INDEX_TO_TEXT_END);
	zend_string *const_INDEX_TO_TEXT_END_name = zend_string_init_interned("INDEX_TO_TEXT_END", sizeof("INDEX_TO_TEXT_END") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_INDEX_TO_TEXT_END_name, &const_INDEX_TO_TEXT_END_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_INDEX_TO_TEXT_END_name, true);

	zval property_startIndex_default_value;
	ZVAL_UNDEF(&property_startIndex_default_value);
	zend_string *property_startIndex_name = zend_string_init("startIndex", sizeof("startIndex") - 1, true);
	zend_declare_typed_property(class_entry, property_startIndex_name, &property_startIndex_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_startIndex_name, true);

	zval property_endIndex_default_value;
	ZVAL_UNDEF(&property_endIndex_default_value);
	zend_string *property_endIndex_name = zend_string_init("endIndex", sizeof("endIndex") - 1, true);
	zend_declare_typed_property(class_entry, property_endIndex_name, &property_endIndex_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release_ex(property_endIndex_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_LanguageAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "LanguageAttribute", class_Pango_Attribute_LanguageAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Language = zend_string_init("Pango\\Language", sizeof("Pango\\Language")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Language, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_FamilyAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "FamilyAttribute", class_Pango_Attribute_FamilyAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_StyleAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "StyleAttribute", class_Pango_Attribute_StyleAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Style = zend_string_init("Pango\\Style", sizeof("Pango\\Style")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Style, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_WeightAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "WeightAttribute", class_Pango_Attribute_WeightAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Weight = zend_string_init("Pango\\Weight", sizeof("Pango\\Weight")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Weight, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_VariantAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "VariantAttribute", class_Pango_Attribute_VariantAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Variant = zend_string_init("Pango\\Variant", sizeof("Pango\\Variant")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Variant, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_StretchAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "StretchAttribute", class_Pango_Attribute_StretchAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Stretch = zend_string_init("Pango\\Stretch", sizeof("Pango\\Stretch")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Stretch, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_SizeAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "SizeAttribute", class_Pango_Attribute_SizeAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_AbsoluteSizeAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "AbsoluteSizeAttribute", class_Pango_Attribute_AbsoluteSizeAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_FontDescriptionAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "FontDescriptionAttribute", class_Pango_Attribute_FontDescriptionAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_desc_default_value;
	ZVAL_UNDEF(&property_desc_default_value);
	zend_string *property_desc_name = zend_string_init("desc", sizeof("desc") - 1, true);
	zend_string *property_desc_class_Pango_FontDescription = zend_string_init("Pango\\FontDescription", sizeof("Pango\\FontDescription")-1, 1);
	zend_declare_typed_property(class_entry, property_desc_name, &property_desc_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_desc_class_Pango_FontDescription, 0, 0));
	zend_string_release_ex(property_desc_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_ForegroundAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "ForegroundAttribute", class_Pango_Attribute_ForegroundAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_color_default_value;
	ZVAL_UNDEF(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, true);
	zend_string *property_color_class_Pango_Color = zend_string_init("Pango\\Color", sizeof("Pango\\Color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_Pango_Color, 0, 0));
	zend_string_release_ex(property_color_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_BackgroundAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "BackgroundAttribute", class_Pango_Attribute_BackgroundAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_color_default_value;
	ZVAL_UNDEF(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, true);
	zend_string *property_color_class_Pango_Color = zend_string_init("Pango\\Color", sizeof("Pango\\Color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_Pango_Color, 0, 0));
	zend_string_release_ex(property_color_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_UnderlineAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "UnderlineAttribute", class_Pango_Attribute_UnderlineAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Underline = zend_string_init("Pango\\\125nderline", sizeof("Pango\\\125nderline")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Underline, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_StrikethroughAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "StrikethroughAttribute", class_Pango_Attribute_StrikethroughAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_RiseAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "RiseAttribute", class_Pango_Attribute_RiseAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_ScaleAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "ScaleAttribute", class_Pango_Attribute_ScaleAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_FallbackAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "FallbackAttribute", class_Pango_Attribute_FallbackAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_LetterSpacingAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "LetterSpacingAttribute", class_Pango_Attribute_LetterSpacingAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_UnderlineColorAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "UnderlineColorAttribute", class_Pango_Attribute_UnderlineColorAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_color_default_value;
	ZVAL_UNDEF(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, true);
	zend_string *property_color_class_Pango_Color = zend_string_init("Pango\\Color", sizeof("Pango\\Color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_Pango_Color, 0, 0));
	zend_string_release_ex(property_color_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_StrikethroughColorAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "StrikethroughColorAttribute", class_Pango_Attribute_StrikethroughColorAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_color_default_value;
	ZVAL_UNDEF(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, true);
	zend_string *property_color_class_Pango_Color = zend_string_init("Pango\\Color", sizeof("Pango\\Color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_Pango_Color, 0, 0));
	zend_string_release_ex(property_color_name, true);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_GravityAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "GravityAttribute", class_Pango_Attribute_GravityAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Gravity = zend_string_init("Pango\\Gravity", sizeof("Pango\\Gravity")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Gravity, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_GravityHintAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "GravityHintAttribute", class_Pango_Attribute_GravityHintAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_GravityHint = zend_string_init("Pango\\GravityHint", sizeof("Pango\\GravityHint")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_GravityHint, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_FontFeaturesAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "FontFeaturesAttribute", class_Pango_Attribute_FontFeaturesAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_ForegroundAlphaAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "ForegroundAlphaAttribute", class_Pango_Attribute_ForegroundAlphaAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_BackgroundAlphaAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "BackgroundAlphaAttribute", class_Pango_Attribute_BackgroundAlphaAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_AllowBreaksAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "AllowBreaksAttribute", class_Pango_Attribute_AllowBreaksAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_ShowAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "ShowAttribute", class_Pango_Attribute_ShowAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval const_NONE_value;
	ZVAL_LONG(&const_NONE_value, PANGO_SHOW_NONE);
	zend_string *const_NONE_name = zend_string_init_interned("NONE", sizeof("NONE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_NONE_name, &const_NONE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_NONE_name, true);

	zval const_SPACES_value;
	ZVAL_LONG(&const_SPACES_value, PANGO_SHOW_SPACES);
	zend_string *const_SPACES_name = zend_string_init_interned("SPACES", sizeof("SPACES") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SPACES_name, &const_SPACES_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SPACES_name, true);

	zval const_LINE_BREAKS_value;
	ZVAL_LONG(&const_LINE_BREAKS_value, PANGO_SHOW_LINE_BREAKS);
	zend_string *const_LINE_BREAKS_name = zend_string_init_interned("LINE_BREAKS", sizeof("LINE_BREAKS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_LINE_BREAKS_name, &const_LINE_BREAKS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_LINE_BREAKS_name, true);

	zval const_IGNORABLES_value;
	ZVAL_LONG(&const_IGNORABLES_value, PANGO_SHOW_IGNORABLES);
	zend_string *const_IGNORABLES_name = zend_string_init_interned("IGNORABLES", sizeof("IGNORABLES") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_IGNORABLES_name, &const_IGNORABLES_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_IGNORABLES_name, true);

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_InsertHyphensAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "InsertHyphensAttribute", class_Pango_Attribute_InsertHyphensAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_OverlineAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "OverlineAttribute", class_Pango_Attribute_OverlineAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Overline = zend_string_init("Pango\\Overline", sizeof("Pango\\Overline")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Overline, 0, 0));

	return class_entry;
}

static zend_class_entry *register_class_Pango_Attribute_OverlineColorAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "OverlineColorAttribute", class_Pango_Attribute_OverlineColorAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_color_default_value;
	ZVAL_UNDEF(&property_color_default_value);
	zend_string *property_color_name = zend_string_init("color", sizeof("color") - 1, true);
	zend_string *property_color_class_Pango_Color = zend_string_init("Pango\\Color", sizeof("Pango\\Color")-1, 1);
	zend_declare_typed_property(class_entry, property_color_name, &property_color_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_color_class_Pango_Color, 0, 0));
	zend_string_release_ex(property_color_name, true);

	return class_entry;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_LineHeightAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "LineHeightAttribute", class_Pango_Attribute_LineHeightAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_AbsoluteLineHeightAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "AbsoluteLineHeightAttribute", class_Pango_Attribute_AbsoluteLineHeightAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_TextTransformAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "TextTransformAttribute", class_Pango_Attribute_TextTransformAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_TextTransform = zend_string_init("Pango\\TextTransform", sizeof("Pango\\TextTransform")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_TextTransform, 0, 0));

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_WordAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "WordAttribute", class_Pango_Attribute_WordAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_SentenceAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "SentenceAttribute", class_Pango_Attribute_SentenceAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_BaselineShiftAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "BaselineShiftAttribute", class_Pango_Attribute_BaselineShiftAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_BaselineShift = zend_string_init("Pango\\BaselineShift", sizeof("Pango\\BaselineShift")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_BaselineShift, 0, MAY_BE_LONG));

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_Attribute_FontScaleAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "FontScaleAttribute", class_Pango_Attribute_FontScaleAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_FontScale = zend_string_init("Pango\\FontScale", sizeof("Pango\\FontScale")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_FontScale, 0, 0));

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
static zend_class_entry *register_class_Pango_Attribute_WidthAttribute(zend_class_entry *class_entry_Pango_Attribute_Attribute)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Attribute", "WidthAttribute", class_Pango_Attribute_WidthAttribute_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Attribute_Attribute, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce.ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Attribute_Attribute);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_class_Pango_Width = zend_string_init("Pango\\Width", sizeof("Pango\\Width")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_VALUE), &property_value_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_value_class_Pango_Width, 0, 0));

	return class_entry;
}
#endif

static zend_class_entry *register_class_Pango_Attribute_AttributeType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Attribute\\AttributeType", IS_LONG, NULL);

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

static zend_class_entry *register_class_Pango_Underline(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Underline", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_UNDERLINE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Single_value;
	ZVAL_LONG(&enum_case_Single_value, PANGO_UNDERLINE_SINGLE);
	zend_enum_add_case_cstr(class_entry, "Single", &enum_case_Single_value);

	zval enum_case_Double_value;
	ZVAL_LONG(&enum_case_Double_value, PANGO_UNDERLINE_DOUBLE);
	zend_enum_add_case_cstr(class_entry, "Double", &enum_case_Double_value);

	zval enum_case_Low_value;
	ZVAL_LONG(&enum_case_Low_value, PANGO_UNDERLINE_LOW);
	zend_enum_add_case_cstr(class_entry, "Low", &enum_case_Low_value);

	zval enum_case_Error_value;
	ZVAL_LONG(&enum_case_Error_value, PANGO_UNDERLINE_ERROR);
	zend_enum_add_case_cstr(class_entry, "Error", &enum_case_Error_value);

	zval enum_case_SingleLine_value;
	ZVAL_LONG(&enum_case_SingleLine_value, PANGO_UNDERLINE_SINGLE_LINE);
	zend_enum_add_case_cstr(class_entry, "SingleLine", &enum_case_SingleLine_value);

	zval enum_case_DoubleLine_value;
	ZVAL_LONG(&enum_case_DoubleLine_value, PANGO_UNDERLINE_DOUBLE_LINE);
	zend_enum_add_case_cstr(class_entry, "DoubleLine", &enum_case_DoubleLine_value);

	zval enum_case_ErrorLine_value;
	ZVAL_LONG(&enum_case_ErrorLine_value, PANGO_UNDERLINE_ERROR_LINE);
	zend_enum_add_case_cstr(class_entry, "ErrorLine", &enum_case_ErrorLine_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Overline(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Overline", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_OVERLINE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Single_value;
	ZVAL_LONG(&enum_case_Single_value, PANGO_OVERLINE_SINGLE);
	zend_enum_add_case_cstr(class_entry, "Single", &enum_case_Single_value);

	return class_entry;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_TextTransform(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\TextTransform", IS_LONG, NULL);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_TEXT_TRANSFORM_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Lowercase_value;
	ZVAL_LONG(&enum_case_Lowercase_value, PANGO_TEXT_TRANSFORM_LOWERCASE);
	zend_enum_add_case_cstr(class_entry, "Lowercase", &enum_case_Lowercase_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Uppercase_value;
	ZVAL_LONG(&enum_case_Uppercase_value, PANGO_TEXT_TRANSFORM_UPPERCASE);
	zend_enum_add_case_cstr(class_entry, "Uppercase", &enum_case_Uppercase_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Capitalize_value;
	ZVAL_LONG(&enum_case_Capitalize_value, PANGO_TEXT_TRANSFORM_CAPITALIZE);
	zend_enum_add_case_cstr(class_entry, "Capitalize", &enum_case_Capitalize_value);
#endif

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_BaselineShift(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\BaselineShift", IS_LONG, NULL);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_BASELINE_SHIFT_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Superscript_value;
	ZVAL_LONG(&enum_case_Superscript_value, PANGO_BASELINE_SHIFT_SUPERSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Superscript", &enum_case_Superscript_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Subscript_value;
	ZVAL_LONG(&enum_case_Subscript_value, PANGO_BASELINE_SHIFT_SUBSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Subscript", &enum_case_Subscript_value);
#endif

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
static zend_class_entry *register_class_Pango_FontScale(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\FontScale", IS_LONG, NULL);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_FONT_SCALE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Superscript_value;
	ZVAL_LONG(&enum_case_Superscript_value, PANGO_FONT_SCALE_SUPERSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Superscript", &enum_case_Superscript_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Subscript_value;
	ZVAL_LONG(&enum_case_Subscript_value, PANGO_FONT_SCALE_SUBSCRIPT);
	zend_enum_add_case_cstr(class_entry, "Subscript", &enum_case_Subscript_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_SmallCaps_value;
	ZVAL_LONG(&enum_case_SmallCaps_value, PANGO_FONT_SCALE_SMALL_CAPS);
	zend_enum_add_case_cstr(class_entry, "SmallCaps", &enum_case_SmallCaps_value);
#endif

	return class_entry;
}
#endif
