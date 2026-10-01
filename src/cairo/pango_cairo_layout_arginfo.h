/* This is a generated file, edit pango_cairo_layout.stub.php instead.
 * Stub hash: 5ba55ef6687e3ec148845891456533a39d675725 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_PangoCairo_Layout___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Layout_path, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_Layout_show arginfo_class_PangoCairo_Layout_path

#define arginfo_class_PangoCairo_Layout_update arginfo_class_PangoCairo_Layout_path

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_Layout_getCairoContext, 0, 0, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Layout_layoutPathForComponents, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, component, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Layout_getLines, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_Layout_getLinesReadonly arginfo_class_PangoCairo_Layout_getLines

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_Layout_getLine, 0, 1, PangoCairo\\LayoutLine, 1)
	ZEND_ARG_TYPE_INFO(0, lineIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_Layout_getLineReadonly arginfo_class_PangoCairo_Layout_getLine

ZEND_METHOD(PangoCairo_Layout, __construct);
ZEND_METHOD(PangoCairo_Layout, path);
ZEND_METHOD(PangoCairo_Layout, show);
ZEND_METHOD(PangoCairo_Layout, update);
ZEND_METHOD(PangoCairo_Layout, getCairoContext);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
ZEND_METHOD(PangoCairo_Layout, layoutPathForComponents);
#endif
ZEND_METHOD(PangoCairo_Layout, getLines);
ZEND_METHOD(PangoCairo_Layout, getLinesReadonly);
ZEND_METHOD(PangoCairo_Layout, getLine);
ZEND_METHOD(PangoCairo_Layout, getLineReadonly);

static const zend_function_entry class_PangoCairo_Layout_methods[] = {
	ZEND_ME(PangoCairo_Layout, __construct, arginfo_class_PangoCairo_Layout___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, path, arginfo_class_PangoCairo_Layout_path, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, show, arginfo_class_PangoCairo_Layout_show, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, update, arginfo_class_PangoCairo_Layout_update, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, getCairoContext, arginfo_class_PangoCairo_Layout_getCairoContext, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
	ZEND_ME(PangoCairo_Layout, layoutPathForComponents, arginfo_class_PangoCairo_Layout_layoutPathForComponents, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(PangoCairo_Layout, getLines, arginfo_class_PangoCairo_Layout_getLines, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, getLinesReadonly, arginfo_class_PangoCairo_Layout_getLinesReadonly, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, getLine, arginfo_class_PangoCairo_Layout_getLine, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, getLineReadonly, arginfo_class_PangoCairo_Layout_getLineReadonly, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_Layout(zend_class_entry *class_entry_Pango_Layout)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "Layout", class_PangoCairo_Layout_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Layout, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Layout);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
