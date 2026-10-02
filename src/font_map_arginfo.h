/* This is a generated file, edit font_map.stub.php instead.
 * Stub hash: 6dcfc1bd59e9ce8e39e1568fde05aba44113937b */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMap_addFontFile, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_createContext, 0, 0, Pango\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_getFamily, 0, 1, Pango\\FontFamily, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMap_listFamilies, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_loadFont, 0, 2, Pango\\Font, 1)
	ZEND_ARG_OBJ_INFO(0, context, Pango\\Context, 0)
	ZEND_ARG_OBJ_INFO(0, desc, Pango\\FontDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_loadFontSet, 0, 3, Pango\\FontSet, 1)
	ZEND_ARG_OBJ_INFO(0, context, Pango\\Context, 0)
	ZEND_ARG_OBJ_INFO(0, desc, Pango\\FontDescription, 0)
	ZEND_ARG_OBJ_INFO(0, language, Pango\\Language, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 52, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_reloadFont, 0, 2, Pango\\Font, 0)
	ZEND_ARG_OBJ_INFO(0, font, Pango\\Font, 0)
	ZEND_ARG_TYPE_INFO(0, scale, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, context, Pango\\Context, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, variations, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
ZEND_METHOD(Pango_FontMap, addFontFile);
#endif
ZEND_METHOD(Pango_FontMap, createContext);
ZEND_METHOD(Pango_FontMap, getFamily);
ZEND_METHOD(Pango_FontMap, listFamilies);
ZEND_METHOD(Pango_FontMap, loadFont);
ZEND_METHOD(Pango_FontMap, loadFontSet);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 52, 0)
ZEND_METHOD(Pango_FontMap, reloadFont);
#endif

static const zend_function_entry class_Pango_FontMap_methods[] = {
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
	ZEND_ME(Pango_FontMap, addFontFile, arginfo_class_Pango_FontMap_addFontFile, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontMap, createContext, arginfo_class_Pango_FontMap_createContext, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMap, getFamily, arginfo_class_Pango_FontMap_getFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMap, listFamilies, arginfo_class_Pango_FontMap_listFamilies, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMap, loadFont, arginfo_class_Pango_FontMap_loadFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMap, loadFontSet, arginfo_class_Pango_FontMap_loadFontSet, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 52, 0)
	ZEND_ME(Pango_FontMap, reloadFont, arginfo_class_Pango_FontMap_reloadFont, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontMap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontMap", class_Pango_FontMap_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	ce->ce_flags |= ZEND_ACC_ABSTRACT;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}
