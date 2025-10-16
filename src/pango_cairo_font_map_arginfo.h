/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: aec8d8a69ececc45b17b37428b3363b66bdbf7d8 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_PangoCairo_FontMap___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_FontMap_getDefault, 0, 0, PangoCairo\\FontMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_FontMap_newForFontType, 0, 1, PangoCairo\\FontMap, 0)
	ZEND_ARG_OBJ_INFO(0, type, Cairo\\FontType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_FontMap_getFontType, 0, 0, Cairo\\FontType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_FontMap_getResolution, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_FontMap_setDefault, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, fontMap, PangoCairo\\FontMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_FontMap_setResolution, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, factor, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(PangoCairo_FontMap, __construct);
ZEND_METHOD(PangoCairo_FontMap, getDefault);
ZEND_METHOD(PangoCairo_FontMap, newForFontType);
ZEND_METHOD(PangoCairo_FontMap, getFontType);
ZEND_METHOD(PangoCairo_FontMap, getResolution);
ZEND_METHOD(PangoCairo_FontMap, setDefault);
ZEND_METHOD(PangoCairo_FontMap, setResolution);

static const zend_function_entry class_PangoCairo_FontMap_methods[] = {
	ZEND_ME(PangoCairo_FontMap, __construct, arginfo_class_PangoCairo_FontMap___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_FontMap, getDefault, arginfo_class_PangoCairo_FontMap_getDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(PangoCairo_FontMap, newForFontType, arginfo_class_PangoCairo_FontMap_newForFontType, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(PangoCairo_FontMap, getFontType, arginfo_class_PangoCairo_FontMap_getFontType, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_FontMap, getResolution, arginfo_class_PangoCairo_FontMap_getResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_FontMap, setDefault, arginfo_class_PangoCairo_FontMap_setDefault, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_FontMap, setResolution, arginfo_class_PangoCairo_FontMap_setResolution, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_FontMap(zend_class_entry *class_entry_Pango_FontMap)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "FontMap", class_PangoCairo_FontMap_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_FontMap, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_FontMap);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
