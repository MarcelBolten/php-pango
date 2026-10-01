/* This is a generated file, edit font_description.stub.php instead.
 * Stub hash: 3dfbc49e94166c0c0ff876d0eedfae4e86e359b7 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_FontDescription___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, description, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getVariant, 0, 0, Pango\\Variant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setVariant, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, variant, Pango\\Variant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_equal, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, fontdesc2, Pango\\FontDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setFamily, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_getFamily, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setSize, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setAbsoluteSize, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_getSize, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_getSizeIsAbsolute, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getStyle, 0, 0, Pango\\Style, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setStyle, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, style, Pango\\Style, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getWeight, 0, 0, Pango\\Weight, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setWeight, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, weight, Pango\\Weight, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getStretch, 0, 0, Pango\\Stretch, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setStretch, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, stretch, Pango\\Stretch, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_FontDescription_toString arginfo_class_Pango_FontDescription_getFamily

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_getFeatures, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setFeatures, 0, 0, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, features, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getGravity, 0, 0, Pango\\Gravity, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setGravity, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, gravity, Pango\\Gravity, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_FontDescription_getVariations arginfo_class_Pango_FontDescription_getFamily

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setVariations, 0, 0, Pango\\FontDescription, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, variations, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_FontDescription_getSetFields arginfo_class_Pango_FontDescription_getSize

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_unsetFields, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, fontMask, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getColor, 0, 0, Pango\\FontColor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setColor, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, color, Pango\\FontColor, 0)
ZEND_END_ARG_INFO()
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_getWidth, 0, 0, Pango\\Width, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_setWidth, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, width, Pango\\Width, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontDescription_betterMatch, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, candidate, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, currentBest, Pango\\FontDescription, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontDescription_merge, 0, 1, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, other, Pango\\FontDescription, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, replaceExisting, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Variant_parse, 0, 1, Pango\\Variant, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Style_parse, 0, 1, Pango\\Style, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Weight_parse, 0, 1, Pango\\Weight, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Stretch_parse, 0, 1, Pango\\Stretch, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_FontDescription, __construct);
ZEND_METHOD(Pango_FontDescription, getVariant);
ZEND_METHOD(Pango_FontDescription, setVariant);
ZEND_METHOD(Pango_FontDescription, equal);
ZEND_METHOD(Pango_FontDescription, setFamily);
ZEND_METHOD(Pango_FontDescription, getFamily);
ZEND_METHOD(Pango_FontDescription, setSize);
ZEND_METHOD(Pango_FontDescription, setAbsoluteSize);
ZEND_METHOD(Pango_FontDescription, getSize);
ZEND_METHOD(Pango_FontDescription, getSizeIsAbsolute);
ZEND_METHOD(Pango_FontDescription, getStyle);
ZEND_METHOD(Pango_FontDescription, setStyle);
ZEND_METHOD(Pango_FontDescription, getWeight);
ZEND_METHOD(Pango_FontDescription, setWeight);
ZEND_METHOD(Pango_FontDescription, getStretch);
ZEND_METHOD(Pango_FontDescription, setStretch);
ZEND_METHOD(Pango_FontDescription, toString);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
ZEND_METHOD(Pango_FontDescription, getFeatures);
ZEND_METHOD(Pango_FontDescription, setFeatures);
#endif
ZEND_METHOD(Pango_FontDescription, getGravity);
ZEND_METHOD(Pango_FontDescription, setGravity);
ZEND_METHOD(Pango_FontDescription, getVariations);
ZEND_METHOD(Pango_FontDescription, setVariations);
ZEND_METHOD(Pango_FontDescription, getSetFields);
ZEND_METHOD(Pango_FontDescription, unsetFields);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
ZEND_METHOD(Pango_FontDescription, getColor);
ZEND_METHOD(Pango_FontDescription, setColor);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_METHOD(Pango_FontDescription, getWidth);
ZEND_METHOD(Pango_FontDescription, setWidth);
#endif
ZEND_METHOD(Pango_FontDescription, betterMatch);
ZEND_METHOD(Pango_FontDescription, merge);
ZEND_METHOD(Pango_Variant, parse);
ZEND_METHOD(Pango_Style, parse);
ZEND_METHOD(Pango_Weight, parse);
ZEND_METHOD(Pango_Stretch, parse);

static const zend_function_entry class_Pango_FontDescription_methods[] = {
	ZEND_ME(Pango_FontDescription, __construct, arginfo_class_Pango_FontDescription___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getVariant, arginfo_class_Pango_FontDescription_getVariant, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setVariant, arginfo_class_Pango_FontDescription_setVariant, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, equal, arginfo_class_Pango_FontDescription_equal, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setFamily, arginfo_class_Pango_FontDescription_setFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getFamily, arginfo_class_Pango_FontDescription_getFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setSize, arginfo_class_Pango_FontDescription_setSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setAbsoluteSize, arginfo_class_Pango_FontDescription_setAbsoluteSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getSize, arginfo_class_Pango_FontDescription_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getSizeIsAbsolute, arginfo_class_Pango_FontDescription_getSizeIsAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getStyle, arginfo_class_Pango_FontDescription_getStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setStyle, arginfo_class_Pango_FontDescription_setStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getWeight, arginfo_class_Pango_FontDescription_getWeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setWeight, arginfo_class_Pango_FontDescription_setWeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getStretch, arginfo_class_Pango_FontDescription_getStretch, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setStretch, arginfo_class_Pango_FontDescription_setStretch, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, toString, arginfo_class_Pango_FontDescription_toString, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
	ZEND_ME(Pango_FontDescription, getFeatures, arginfo_class_Pango_FontDescription_getFeatures, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setFeatures, arginfo_class_Pango_FontDescription_setFeatures, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontDescription, getGravity, arginfo_class_Pango_FontDescription_getGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setGravity, arginfo_class_Pango_FontDescription_setGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getVariations, arginfo_class_Pango_FontDescription_getVariations, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setVariations, arginfo_class_Pango_FontDescription_setVariations, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, getSetFields, arginfo_class_Pango_FontDescription_getSetFields, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, unsetFields, arginfo_class_Pango_FontDescription_unsetFields, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
	ZEND_ME(Pango_FontDescription, getColor, arginfo_class_Pango_FontDescription_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setColor, arginfo_class_Pango_FontDescription_setColor, ZEND_ACC_PUBLIC)
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	ZEND_ME(Pango_FontDescription, getWidth, arginfo_class_Pango_FontDescription_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, setWidth, arginfo_class_Pango_FontDescription_setWidth, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontDescription, betterMatch, arginfo_class_Pango_FontDescription_betterMatch, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontDescription, merge, arginfo_class_Pango_FontDescription_merge, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Variant_methods[] = {
	ZEND_ME(Pango_Variant, parse, arginfo_class_Pango_Variant_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Style_methods[] = {
	ZEND_ME(Pango_Style, parse, arginfo_class_Pango_Style_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Weight_methods[] = {
	ZEND_ME(Pango_Weight, parse, arginfo_class_Pango_Weight_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_Pango_Stretch_methods[] = {
	ZEND_ME(Pango_Stretch, parse, arginfo_class_Pango_Stretch_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontDescription", class_Pango_FontDescription_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_Variant(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Variant", IS_LONG, class_Pango_Variant_methods);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, PANGO_VARIANT_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_SmallCaps_value;
	ZVAL_LONG(&enum_case_SmallCaps_value, PANGO_VARIANT_SMALL_CAPS);
	zend_enum_add_case_cstr(class_entry, "SmallCaps", &enum_case_SmallCaps_value);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_AllSmallCaps_value;
	ZVAL_LONG(&enum_case_AllSmallCaps_value, PANGO_VARIANT_ALL_SMALL_CAPS);
	zend_enum_add_case_cstr(class_entry, "AllSmallCaps", &enum_case_AllSmallCaps_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_PetiteCaps_value;
	ZVAL_LONG(&enum_case_PetiteCaps_value, PANGO_VARIANT_PETITE_CAPS);
	zend_enum_add_case_cstr(class_entry, "PetiteCaps", &enum_case_PetiteCaps_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_AllPetiteCaps_value;
	ZVAL_LONG(&enum_case_AllPetiteCaps_value, PANGO_VARIANT_ALL_PETITE_CAPS);
	zend_enum_add_case_cstr(class_entry, "AllPetiteCaps", &enum_case_AllPetiteCaps_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_Unicase_value;
	ZVAL_LONG(&enum_case_Unicase_value, PANGO_VARIANT_UNICASE);
	zend_enum_add_case_cstr(class_entry, "Unicase", &enum_case_Unicase_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	zval enum_case_TitleCaps_value;
	ZVAL_LONG(&enum_case_TitleCaps_value, PANGO_VARIANT_TITLE_CAPS);
	zend_enum_add_case_cstr(class_entry, "TitleCaps", &enum_case_TitleCaps_value);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_Style(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Style", IS_LONG, class_Pango_Style_methods);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, PANGO_STYLE_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_Oblique_value;
	ZVAL_LONG(&enum_case_Oblique_value, PANGO_STYLE_OBLIQUE);
	zend_enum_add_case_cstr(class_entry, "Oblique", &enum_case_Oblique_value);

	zval enum_case_Italic_value;
	ZVAL_LONG(&enum_case_Italic_value, PANGO_STYLE_ITALIC);
	zend_enum_add_case_cstr(class_entry, "Italic", &enum_case_Italic_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Weight(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Weight", IS_LONG, class_Pango_Weight_methods);

	zval enum_case_Thin_value;
	ZVAL_LONG(&enum_case_Thin_value, PANGO_WEIGHT_THIN);
	zend_enum_add_case_cstr(class_entry, "Thin", &enum_case_Thin_value);

	zval enum_case_UltraLight_value;
	ZVAL_LONG(&enum_case_UltraLight_value, PANGO_WEIGHT_ULTRALIGHT);
	zend_enum_add_case_cstr(class_entry, "UltraLight", &enum_case_UltraLight_value);

	zval enum_case_Light_value;
	ZVAL_LONG(&enum_case_Light_value, PANGO_WEIGHT_LIGHT);
	zend_enum_add_case_cstr(class_entry, "Light", &enum_case_Light_value);

	zval enum_case_SemiLight_value;
	ZVAL_LONG(&enum_case_SemiLight_value, PANGO_WEIGHT_SEMILIGHT);
	zend_enum_add_case_cstr(class_entry, "SemiLight", &enum_case_SemiLight_value);

	zval enum_case_Book_value;
	ZVAL_LONG(&enum_case_Book_value, PANGO_WEIGHT_BOOK);
	zend_enum_add_case_cstr(class_entry, "Book", &enum_case_Book_value);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, PANGO_WEIGHT_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_Medium_value;
	ZVAL_LONG(&enum_case_Medium_value, PANGO_WEIGHT_MEDIUM);
	zend_enum_add_case_cstr(class_entry, "Medium", &enum_case_Medium_value);

	zval enum_case_SemiBold_value;
	ZVAL_LONG(&enum_case_SemiBold_value, PANGO_WEIGHT_SEMIBOLD);
	zend_enum_add_case_cstr(class_entry, "SemiBold", &enum_case_SemiBold_value);

	zval enum_case_Bold_value;
	ZVAL_LONG(&enum_case_Bold_value, PANGO_WEIGHT_BOLD);
	zend_enum_add_case_cstr(class_entry, "Bold", &enum_case_Bold_value);

	zval enum_case_UltraBold_value;
	ZVAL_LONG(&enum_case_UltraBold_value, PANGO_WEIGHT_ULTRABOLD);
	zend_enum_add_case_cstr(class_entry, "UltraBold", &enum_case_UltraBold_value);

	zval enum_case_Heavy_value;
	ZVAL_LONG(&enum_case_Heavy_value, PANGO_WEIGHT_HEAVY);
	zend_enum_add_case_cstr(class_entry, "Heavy", &enum_case_Heavy_value);

	zval enum_case_UltraHeavy_value;
	ZVAL_LONG(&enum_case_UltraHeavy_value, PANGO_WEIGHT_ULTRAHEAVY);
	zend_enum_add_case_cstr(class_entry, "UltraHeavy", &enum_case_UltraHeavy_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Stretch(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Stretch", IS_LONG, class_Pango_Stretch_methods);

	zval enum_case_UltraCondensed_value;
	ZVAL_LONG(&enum_case_UltraCondensed_value, PANGO_STRETCH_ULTRA_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "UltraCondensed", &enum_case_UltraCondensed_value);

	zval enum_case_ExtraCondensed_value;
	ZVAL_LONG(&enum_case_ExtraCondensed_value, PANGO_STRETCH_EXTRA_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "ExtraCondensed", &enum_case_ExtraCondensed_value);

	zval enum_case_Condensed_value;
	ZVAL_LONG(&enum_case_Condensed_value, PANGO_STRETCH_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "Condensed", &enum_case_Condensed_value);

	zval enum_case_SemiCondensed_value;
	ZVAL_LONG(&enum_case_SemiCondensed_value, PANGO_STRETCH_SEMI_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "SemiCondensed", &enum_case_SemiCondensed_value);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, PANGO_STRETCH_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_SemiExpanded_value;
	ZVAL_LONG(&enum_case_SemiExpanded_value, PANGO_STRETCH_SEMI_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "SemiExpanded", &enum_case_SemiExpanded_value);

	zval enum_case_Expanded_value;
	ZVAL_LONG(&enum_case_Expanded_value, PANGO_STRETCH_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "Expanded", &enum_case_Expanded_value);

	zval enum_case_ExtraExpanded_value;
	ZVAL_LONG(&enum_case_ExtraExpanded_value, PANGO_STRETCH_EXTRA_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "ExtraExpanded", &enum_case_ExtraExpanded_value);

	zval enum_case_UltraExpanded_value;
	ZVAL_LONG(&enum_case_UltraExpanded_value, PANGO_STRETCH_ULTRA_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "UltraExpanded", &enum_case_UltraExpanded_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_FontMask(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontMask", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	zval const_FAMILY_value;
	ZVAL_LONG(&const_FAMILY_value, PANGO_FONT_MASK_FAMILY);
	zend_string *const_FAMILY_name = zend_string_init_interned("FAMILY", sizeof("FAMILY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_FAMILY_name, &const_FAMILY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_FAMILY_name, true);

	zval const_STYLE_value;
	ZVAL_LONG(&const_STYLE_value, PANGO_FONT_MASK_STYLE);
	zend_string *const_STYLE_name = zend_string_init_interned("STYLE", sizeof("STYLE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_STYLE_name, &const_STYLE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_STYLE_name, true);

	zval const_VARIANT_value;
	ZVAL_LONG(&const_VARIANT_value, PANGO_FONT_MASK_VARIANT);
	zend_string *const_VARIANT_name = zend_string_init_interned("VARIANT", sizeof("VARIANT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_VARIANT_name, &const_VARIANT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_VARIANT_name, true);

	zval const_WEIGHT_value;
	ZVAL_LONG(&const_WEIGHT_value, PANGO_FONT_MASK_WEIGHT);
	zend_string *const_WEIGHT_name = zend_string_init_interned("WEIGHT", sizeof("WEIGHT") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_WEIGHT_name, &const_WEIGHT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_WEIGHT_name, true);

	zval const_STRETCH_value;
	ZVAL_LONG(&const_STRETCH_value, PANGO_FONT_MASK_STRETCH);
	zend_string *const_STRETCH_name = zend_string_init_interned("STRETCH", sizeof("STRETCH") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_STRETCH_name, &const_STRETCH_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_STRETCH_name, true);

	zval const_SIZE_value;
	ZVAL_LONG(&const_SIZE_value, PANGO_FONT_MASK_SIZE);
	zend_string *const_SIZE_name = zend_string_init_interned("SIZE", sizeof("SIZE") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_SIZE_name, &const_SIZE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_SIZE_name, true);

	zval const_GRAVITY_value;
	ZVAL_LONG(&const_GRAVITY_value, PANGO_FONT_MASK_GRAVITY);
	zend_string *const_GRAVITY_name = zend_string_init_interned("GRAVITY", sizeof("GRAVITY") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_GRAVITY_name, &const_GRAVITY_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_GRAVITY_name, true);

	zval const_VARIATIONS_value;
	ZVAL_LONG(&const_VARIATIONS_value, PANGO_FONT_MASK_VARIATIONS);
	zend_string *const_VARIATIONS_name = zend_string_init_interned("VARIATIONS", sizeof("VARIATIONS") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_VARIATIONS_name, &const_VARIATIONS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_VARIATIONS_name, true);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)

	zval const_FEATURES_value;
	ZVAL_LONG(&const_FEATURES_value, PANGO_FONT_MASK_FEATURES);
	zend_string *const_FEATURES_name = zend_string_init_interned("FEATURES", sizeof("FEATURES") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_FEATURES_name, &const_FEATURES_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_FEATURES_name, true);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)

	zval const_COLOR_value;
	ZVAL_LONG(&const_COLOR_value, PANGO_FONT_MASK_COLOR);
	zend_string *const_COLOR_name = zend_string_init_interned("COLOR", sizeof("COLOR") - 1, true);
	zend_declare_class_constant_ex(class_entry, const_COLOR_name, &const_COLOR_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release_ex(const_COLOR_name, true);
#endif

	return class_entry;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
static zend_class_entry *register_class_Pango_FontColor(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\FontColor", IS_LONG, NULL);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
	zval enum_case_Forbidden_value;
	ZVAL_LONG(&enum_case_Forbidden_value, PANGO_FONT_COLOR_FORBIDDEN);
	zend_enum_add_case_cstr(class_entry, "Forbidden", &enum_case_Forbidden_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
	zval enum_case_Required_value;
	ZVAL_LONG(&enum_case_Required_value, PANGO_FONT_COLOR_REQUIRED);
	zend_enum_add_case_cstr(class_entry, "Required", &enum_case_Required_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
	zval enum_case_DontCare_value;
	ZVAL_LONG(&enum_case_DontCare_value, PANGO_FONT_COLOR_DONT_CARE);
	zend_enum_add_case_cstr(class_entry, "DontCare", &enum_case_DontCare_value);
#endif

	return class_entry;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
static zend_class_entry *register_class_Pango_Width(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Width", IS_LONG, NULL);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_UltraCondensed_value;
	ZVAL_LONG(&enum_case_UltraCondensed_value, PANGO_WIDTH_ULTRA_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "UltraCondensed", &enum_case_UltraCondensed_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_ExtraCondensed_value;
	ZVAL_LONG(&enum_case_ExtraCondensed_value, PANGO_WIDTH_EXTRA_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "ExtraCondensed", &enum_case_ExtraCondensed_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_Condensed_value;
	ZVAL_LONG(&enum_case_Condensed_value, PANGO_WIDTH_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "Condensed", &enum_case_Condensed_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_SemiCondensed_value;
	ZVAL_LONG(&enum_case_SemiCondensed_value, PANGO_WIDTH_SEMI_CONDENSED);
	zend_enum_add_case_cstr(class_entry, "SemiCondensed", &enum_case_SemiCondensed_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, PANGO_WIDTH_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_SemiExpanded_value;
	ZVAL_LONG(&enum_case_SemiExpanded_value, PANGO_WIDTH_SEMI_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "SemiExpanded", &enum_case_SemiExpanded_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_Expanded_value;
	ZVAL_LONG(&enum_case_Expanded_value, PANGO_WIDTH_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "Expanded", &enum_case_Expanded_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_ExtraExpanded_value;
	ZVAL_LONG(&enum_case_ExtraExpanded_value, PANGO_WIDTH_EXTRA_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "ExtraExpanded", &enum_case_ExtraExpanded_value);
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	zval enum_case_UltraExpanded_value;
	ZVAL_LONG(&enum_case_UltraExpanded_value, PANGO_WIDTH_ULTRA_EXPANDED);
	zend_enum_add_case_cstr(class_entry, "UltraExpanded", &enum_case_UltraExpanded_value);
#endif

	return class_entry;
}
#endif
