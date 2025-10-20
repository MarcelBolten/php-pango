/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 98981dedc49a07f1d97bf0d5cdae42f51659b9d2 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Layout___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Pango\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getContext, 0, 0, Pango\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getSize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getPixelSize arginfo_class_Pango_Layout_getSize

#define arginfo_class_Pango_Layout_getExtents arginfo_class_Pango_Layout_getSize

#define arginfo_class_Pango_Layout_getPixelExtents arginfo_class_Pango_Layout_getSize

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setWidth, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getHeight arginfo_class_Pango_Layout_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setHeight, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setMarkup, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, markup, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setMarkupWithAccel, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, markup, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, accelMarker, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setFontDescription, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, desc, Pango\\FontDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getFontDescription, 0, 0, Pango\\FontDescription, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setAlignment, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, alignment, Pango\\Alignment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getAlignment, 0, 0, Pango\\Alignment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setJustify, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, justify, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getJustify, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setWrap, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, wrap, Pango\\WrapMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getWrap, 0, 0, Pango\\WrapMode, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_isWrapped arginfo_class_Pango_Layout_getJustify

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setIndent, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, indent, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getIndent arginfo_class_Pango_Layout_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setSpacing, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getSpacing arginfo_class_Pango_Layout_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setEllipsize, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, Pango\\EllipsizeMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getEllipsize, 0, 0, Pango\\EllipsizeMode, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_isEllipsized arginfo_class_Pango_Layout_getJustify

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_contextChanged, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getLines arginfo_class_Pango_Layout_getSize

#define arginfo_class_Pango_Layout_getLinesReadonly arginfo_class_Pango_Layout_getSize

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getLine, 0, 1, Pango\\LayoutLine, 1)
	ZEND_ARG_TYPE_INFO(0, lineIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getLineReadonly arginfo_class_Pango_Layout_getLine

#define arginfo_class_Pango_Layout_getLineCount arginfo_class_Pango_Layout_getWidth

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_serialize, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "Pango\\Pango\\Layout::SERIALIZE_DEFAULT")
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Pango_Layout_getBaseline arginfo_class_Pango_Layout_getWidth

#define arginfo_class_Pango_Layout_getAutoDir arginfo_class_Pango_Layout_getJustify

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setAutoDir, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autoDir, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Layout_getCharacterCount arginfo_class_Pango_Layout_getWidth

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Layout_getDirection, 0, 1, Pango\\Direction, 0)
	ZEND_ARG_TYPE_INFO(0, byteIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getJustifyLastLine, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setJustifyLastLine, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, justifyLastLine, _IS_BOOL, 0)
ZEND_END_ARG_INFO()
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_getLineSpacing, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setLineSpacing, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, factor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Pango_Layout_getUnknownGlyphsCount arginfo_class_Pango_Layout_getWidth

#define arginfo_class_Pango_Layout_getSingleParagraphMode arginfo_class_Pango_Layout_getJustify

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Layout_setSingleParagraphMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Layout, __construct);
ZEND_METHOD(Pango_Layout, getContext);
ZEND_METHOD(Pango_Layout, setText);
ZEND_METHOD(Pango_Layout, getText);
ZEND_METHOD(Pango_Layout, getWidth);
ZEND_METHOD(Pango_Layout, getSize);
ZEND_METHOD(Pango_Layout, getPixelSize);
ZEND_METHOD(Pango_Layout, getExtents);
ZEND_METHOD(Pango_Layout, getPixelExtents);
ZEND_METHOD(Pango_Layout, setWidth);
ZEND_METHOD(Pango_Layout, getHeight);
ZEND_METHOD(Pango_Layout, setHeight);
ZEND_METHOD(Pango_Layout, setMarkup);
ZEND_METHOD(Pango_Layout, setMarkupWithAccel);
ZEND_METHOD(Pango_Layout, setFontDescription);
ZEND_METHOD(Pango_Layout, getFontDescription);
ZEND_METHOD(Pango_Layout, setAlignment);
ZEND_METHOD(Pango_Layout, getAlignment);
ZEND_METHOD(Pango_Layout, setJustify);
ZEND_METHOD(Pango_Layout, getJustify);
ZEND_METHOD(Pango_Layout, setWrap);
ZEND_METHOD(Pango_Layout, getWrap);
ZEND_METHOD(Pango_Layout, isWrapped);
ZEND_METHOD(Pango_Layout, setIndent);
ZEND_METHOD(Pango_Layout, getIndent);
ZEND_METHOD(Pango_Layout, setSpacing);
ZEND_METHOD(Pango_Layout, getSpacing);
ZEND_METHOD(Pango_Layout, setEllipsize);
ZEND_METHOD(Pango_Layout, getEllipsize);
ZEND_METHOD(Pango_Layout, isEllipsized);
ZEND_METHOD(Pango_Layout, contextChanged);
ZEND_METHOD(Pango_Layout, getLines);
ZEND_METHOD(Pango_Layout, getLinesReadonly);
ZEND_METHOD(Pango_Layout, getLine);
ZEND_METHOD(Pango_Layout, getLineReadonly);
ZEND_METHOD(Pango_Layout, getLineCount);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_METHOD(Pango_Layout, serialize);
#endif
ZEND_METHOD(Pango_Layout, getBaseline);
ZEND_METHOD(Pango_Layout, getAutoDir);
ZEND_METHOD(Pango_Layout, setAutoDir);
ZEND_METHOD(Pango_Layout, getCharacterCount);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
ZEND_METHOD(Pango_Layout, getDirection);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_METHOD(Pango_Layout, getJustifyLastLine);
ZEND_METHOD(Pango_Layout, setJustifyLastLine);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
ZEND_METHOD(Pango_Layout, getLineSpacing);
ZEND_METHOD(Pango_Layout, setLineSpacing);
#endif
ZEND_METHOD(Pango_Layout, getUnknownGlyphsCount);
ZEND_METHOD(Pango_Layout, getSingleParagraphMode);
ZEND_METHOD(Pango_Layout, setSingleParagraphMode);

static const zend_function_entry class_Pango_Layout_methods[] = {
	ZEND_ME(Pango_Layout, __construct, arginfo_class_Pango_Layout___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getContext, arginfo_class_Pango_Layout_getContext, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setText, arginfo_class_Pango_Layout_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getText, arginfo_class_Pango_Layout_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getWidth, arginfo_class_Pango_Layout_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getSize, arginfo_class_Pango_Layout_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getPixelSize, arginfo_class_Pango_Layout_getPixelSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getExtents, arginfo_class_Pango_Layout_getExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getPixelExtents, arginfo_class_Pango_Layout_getPixelExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setWidth, arginfo_class_Pango_Layout_setWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getHeight, arginfo_class_Pango_Layout_getHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setHeight, arginfo_class_Pango_Layout_setHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setMarkup, arginfo_class_Pango_Layout_setMarkup, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setMarkupWithAccel, arginfo_class_Pango_Layout_setMarkupWithAccel, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setFontDescription, arginfo_class_Pango_Layout_setFontDescription, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getFontDescription, arginfo_class_Pango_Layout_getFontDescription, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setAlignment, arginfo_class_Pango_Layout_setAlignment, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getAlignment, arginfo_class_Pango_Layout_getAlignment, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setJustify, arginfo_class_Pango_Layout_setJustify, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getJustify, arginfo_class_Pango_Layout_getJustify, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setWrap, arginfo_class_Pango_Layout_setWrap, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getWrap, arginfo_class_Pango_Layout_getWrap, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, isWrapped, arginfo_class_Pango_Layout_isWrapped, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setIndent, arginfo_class_Pango_Layout_setIndent, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getIndent, arginfo_class_Pango_Layout_getIndent, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setSpacing, arginfo_class_Pango_Layout_setSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getSpacing, arginfo_class_Pango_Layout_getSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setEllipsize, arginfo_class_Pango_Layout_setEllipsize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getEllipsize, arginfo_class_Pango_Layout_getEllipsize, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, isEllipsized, arginfo_class_Pango_Layout_isEllipsized, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, contextChanged, arginfo_class_Pango_Layout_contextChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getLines, arginfo_class_Pango_Layout_getLines, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getLinesReadonly, arginfo_class_Pango_Layout_getLinesReadonly, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getLine, arginfo_class_Pango_Layout_getLine, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getLineReadonly, arginfo_class_Pango_Layout_getLineReadonly, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getLineCount, arginfo_class_Pango_Layout_getLineCount, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	ZEND_ME(Pango_Layout, serialize, arginfo_class_Pango_Layout_serialize, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Layout, getBaseline, arginfo_class_Pango_Layout_getBaseline, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getAutoDir, arginfo_class_Pango_Layout_getAutoDir, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setAutoDir, arginfo_class_Pango_Layout_setAutoDir, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getCharacterCount, arginfo_class_Pango_Layout_getCharacterCount, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
	ZEND_ME(Pango_Layout, getDirection, arginfo_class_Pango_Layout_getDirection, ZEND_ACC_PUBLIC)
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	ZEND_ME(Pango_Layout, getJustifyLastLine, arginfo_class_Pango_Layout_getJustifyLastLine, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setJustifyLastLine, arginfo_class_Pango_Layout_setJustifyLastLine, ZEND_ACC_PUBLIC)
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
	ZEND_ME(Pango_Layout, getLineSpacing, arginfo_class_Pango_Layout_getLineSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setLineSpacing, arginfo_class_Pango_Layout_setLineSpacing, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_Layout, getUnknownGlyphsCount, arginfo_class_Pango_Layout_getUnknownGlyphsCount, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, getSingleParagraphMode, arginfo_class_Pango_Layout_getSingleParagraphMode, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Layout, setSingleParagraphMode, arginfo_class_Pango_Layout_setSingleParagraphMode, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Layout(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Layout", class_Pango_Layout_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)

	zval const_SERIALIZE_DEFAULT_value;
	ZVAL_LONG(&const_SERIALIZE_DEFAULT_value, PANGO_LAYOUT_SERIALIZE_DEFAULT);
	zend_string *const_SERIALIZE_DEFAULT_name = zend_string_init_interned("SERIALIZE_DEFAULT", sizeof("SERIALIZE_DEFAULT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SERIALIZE_DEFAULT_name, &const_SERIALIZE_DEFAULT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SERIALIZE_DEFAULT_name);

	zval const_SERIALIZE_CONTEXT_value;
	ZVAL_LONG(&const_SERIALIZE_CONTEXT_value, PANGO_LAYOUT_SERIALIZE_CONTEXT);
	zend_string *const_SERIALIZE_CONTEXT_name = zend_string_init_interned("SERIALIZE_CONTEXT", sizeof("SERIALIZE_CONTEXT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SERIALIZE_CONTEXT_name, &const_SERIALIZE_CONTEXT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SERIALIZE_CONTEXT_name);

	zval const_SERIALIZE_OUTPUT_value;
	ZVAL_LONG(&const_SERIALIZE_OUTPUT_value, PANGO_LAYOUT_SERIALIZE_OUTPUT);
	zend_string *const_SERIALIZE_OUTPUT_name = zend_string_init_interned("SERIALIZE_OUTPUT", sizeof("SERIALIZE_OUTPUT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SERIALIZE_OUTPUT_name, &const_SERIALIZE_OUTPUT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SERIALIZE_OUTPUT_name);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_Alignment(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Alignment", IS_LONG, NULL);

	zval enum_case_Left_value;
	ZVAL_LONG(&enum_case_Left_value, PANGO_ALIGN_LEFT);
	zend_enum_add_case_cstr(class_entry, "Left", &enum_case_Left_value);

	zval enum_case_Center_value;
	ZVAL_LONG(&enum_case_Center_value, PANGO_ALIGN_CENTER);
	zend_enum_add_case_cstr(class_entry, "Center", &enum_case_Center_value);

	zval enum_case_Right_value;
	ZVAL_LONG(&enum_case_Right_value, PANGO_ALIGN_RIGHT);
	zend_enum_add_case_cstr(class_entry, "Right", &enum_case_Right_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_WrapMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\WrapMode", IS_LONG, NULL);

	zval enum_case_Word_value;
	ZVAL_LONG(&enum_case_Word_value, PANGO_WRAP_WORD);
	zend_enum_add_case_cstr(class_entry, "Word", &enum_case_Word_value);

	zval enum_case_Char_value;
	ZVAL_LONG(&enum_case_Char_value, PANGO_WRAP_CHAR);
	zend_enum_add_case_cstr(class_entry, "Char", &enum_case_Char_value);

	zval enum_case_WordChar_value;
	ZVAL_LONG(&enum_case_WordChar_value, PANGO_WRAP_WORD_CHAR);
	zend_enum_add_case_cstr(class_entry, "WordChar", &enum_case_WordChar_value);

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_WRAP_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_EllipsizeMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\EllipsizeMode", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, PANGO_ELLIPSIZE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Start_value;
	ZVAL_LONG(&enum_case_Start_value, PANGO_ELLIPSIZE_START);
	zend_enum_add_case_cstr(class_entry, "Start", &enum_case_Start_value);

	zval enum_case_Middle_value;
	ZVAL_LONG(&enum_case_Middle_value, PANGO_ELLIPSIZE_MIDDLE);
	zend_enum_add_case_cstr(class_entry, "Middle", &enum_case_Middle_value);

	zval enum_case_End_value;
	ZVAL_LONG(&enum_case_End_value, PANGO_ELLIPSIZE_END);
	zend_enum_add_case_cstr(class_entry, "End", &enum_case_End_value);

	return class_entry;
}
