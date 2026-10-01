/* This is a generated file, edit font.stub.php instead.
 * Stub hash: 3afc02d796ef64ce284b4ee091eef6ea9e1ec9cc */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Font_describe, 0, 0, Pango\\FontDescription, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Font_describeAbsolute arginfo_class_Pango_Font_describe

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Font_getCoverage, 0, 1, Pango\\Coverage, 0)
	ZEND_ARG_OBJ_INFO(0, language, Pango\\Language, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Font_getFace, 0, 0, Pango\\FontFace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Font_getFeatures, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Font_getFontMap, 0, 0, Pango\\FontMap, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Font_getGlyphExtents arginfo_class_Pango_Font_getFeatures

#define arginfo_class_Pango_Font_getLanguages arginfo_class_Pango_Font_getFeatures

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Font_getMetrics, 0, 0, Pango\\FontMetrics, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, language, Pango\\Language, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Font_hasChar, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, char, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Font, describe);
ZEND_METHOD(Pango_Font, describeAbsolute);
ZEND_METHOD(Pango_Font, getCoverage);
ZEND_METHOD(Pango_Font, getFace);
ZEND_METHOD(Pango_Font, getFeatures);
ZEND_METHOD(Pango_Font, getFontMap);
ZEND_METHOD(Pango_Font, getGlyphExtents);
ZEND_METHOD(Pango_Font, getLanguages);
ZEND_METHOD(Pango_Font, getMetrics);
ZEND_METHOD(Pango_Font, hasChar);

static const zend_function_entry class_Pango_Font_methods[] = {
	ZEND_ME(Pango_Font, describe, arginfo_class_Pango_Font_describe, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, describeAbsolute, arginfo_class_Pango_Font_describeAbsolute, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getCoverage, arginfo_class_Pango_Font_getCoverage, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getFace, arginfo_class_Pango_Font_getFace, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getFeatures, arginfo_class_Pango_Font_getFeatures, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getFontMap, arginfo_class_Pango_Font_getFontMap, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getGlyphExtents, arginfo_class_Pango_Font_getGlyphExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getLanguages, arginfo_class_Pango_Font_getLanguages, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, getMetrics, arginfo_class_Pango_Font_getMetrics, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Font, hasChar, arginfo_class_Pango_Font_hasChar, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Font(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Font", class_Pango_Font_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}
