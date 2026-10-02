/* This is a generated file, edit pango_ft2_font_map.stub.php instead.
 * Stub hash: 7236b7bf88a07fafde27f37331ed1bf1083bc84a */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Ft2_FontMap___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Ft2_FontMap_setResolution, 0, 2, Pango\\Ft2\\FontMap, 0)
	ZEND_ARG_TYPE_INFO(0, dpiX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dpiY, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Ft2_FontMap, __construct);
ZEND_METHOD(Pango_Ft2_FontMap, setResolution);

static const zend_function_entry class_Pango_Ft2_FontMap_methods[] = {
	ZEND_ME(Pango_Ft2_FontMap, __construct, arginfo_class_Pango_Ft2_FontMap___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Ft2_FontMap, setResolution, arginfo_class_Pango_Ft2_FontMap_setResolution, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Ft2_FontMap(zend_class_entry *class_entry_Pango_Fc_FontMap)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango\\Ft2", "FontMap", class_Pango_Ft2_FontMap_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Fc_FontMap, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Fc_FontMap);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
