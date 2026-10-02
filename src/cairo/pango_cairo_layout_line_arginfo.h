/* This is a generated file, edit pango_cairo_layout_line.stub.php instead.
 * Stub hash: b2e86061ab3ebffe9d545e1f845357279a8dd606 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_LayoutLine_path, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_LayoutLine_show arginfo_class_PangoCairo_LayoutLine_path

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_LayoutLine_getRuns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(PangoCairo_LayoutLine, path);
ZEND_METHOD(PangoCairo_LayoutLine, show);
ZEND_METHOD(PangoCairo_LayoutLine, getRuns);

static const zend_function_entry class_PangoCairo_LayoutLine_methods[] = {
	ZEND_ME(PangoCairo_LayoutLine, path, arginfo_class_PangoCairo_LayoutLine_path, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_LayoutLine, show, arginfo_class_PangoCairo_LayoutLine_show, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_LayoutLine, getRuns, arginfo_class_PangoCairo_LayoutLine_getRuns, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_LayoutLine(zend_class_entry *class_entry_Pango_LayoutLine)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "LayoutLine", class_PangoCairo_LayoutLine_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_LayoutLine, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_LayoutLine);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
