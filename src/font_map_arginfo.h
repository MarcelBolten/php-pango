/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: bc03c16f333ec887e24ec71aae85df6312a64588 */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,56,0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMap_addFontFile, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontMap_createContext, 0, 0, Pango\\Context, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,46,0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMap_getFamily, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMap_listFamilies, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,56,0)
ZEND_METHOD(Pango_FontMap, addFontFile);
#endif
ZEND_METHOD(Pango_FontMap, createContext);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,46,0)
ZEND_METHOD(Pango_FontMap, getFamily);
#endif
ZEND_METHOD(Pango_FontMap, listFamilies);

static const zend_function_entry class_Pango_FontMap_methods[] = {
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,56,0)
	ZEND_ME(Pango_FontMap, addFontFile, arginfo_class_Pango_FontMap_addFontFile, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontMap, createContext, arginfo_class_Pango_FontMap_createContext, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,46,0)
	ZEND_ME(Pango_FontMap, getFamily, arginfo_class_Pango_FontMap_getFamily, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontMap, listFamilies, arginfo_class_Pango_FontMap_listFamilies, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontMap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontMap", class_Pango_FontMap_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}
