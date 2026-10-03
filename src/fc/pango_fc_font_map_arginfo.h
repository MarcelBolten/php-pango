/* This is a generated file, edit pango_fc_font_map.stub.php instead.
 * Stub hash: 489d39c21254da6ea0dc9f987502fd573c5241c7 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Fc_FontMap_clearCache, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Fc_FontMap_configChanged arginfo_class_Pango_Fc_FontMap_clearCache

#define arginfo_class_Pango_Fc_FontMap_shutdown arginfo_class_Pango_Fc_FontMap_clearCache

#define arginfo_class_Pango_Fc_FontMap_substituteChanged arginfo_class_Pango_Fc_FontMap_clearCache

ZEND_METHOD(Pango_Fc_FontMap, clearCache);
ZEND_METHOD(Pango_Fc_FontMap, configChanged);
ZEND_METHOD(Pango_Fc_FontMap, shutdown);
ZEND_METHOD(Pango_Fc_FontMap, substituteChanged);

static const zend_function_entry class_Pango_Fc_FontMap_methods[] = {
	ZEND_ME(Pango_Fc_FontMap, clearCache, arginfo_class_Pango_Fc_FontMap_clearCache, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Fc_FontMap, configChanged, arginfo_class_Pango_Fc_FontMap_configChanged, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Fc_FontMap, shutdown, arginfo_class_Pango_Fc_FontMap_shutdown, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Fc_FontMap, substituteChanged, arginfo_class_Pango_Fc_FontMap_substituteChanged, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Fc_FontMap(zend_class_entry *class_entry_Pango_FontMap)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Fc", "FontMap", class_Pango_Fc_FontMap_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_FontMap, ZEND_ACC_ABSTRACT);
#else
	ce.ce_flags |= ZEND_ACC_ABSTRACT;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_FontMap);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}
