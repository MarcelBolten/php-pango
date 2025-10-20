/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a83551668f1da73a8a4be690385b20dcb2b79132 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_PangoCairo_Layout___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Layout_layoutPath, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoCairo_Layout_showLayout arginfo_class_PangoCairo_Layout_layoutPath

#define arginfo_class_PangoCairo_Layout_updateLayout arginfo_class_PangoCairo_Layout_layoutPath

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_Layout_getCairoContext, 0, 0, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(PangoCairo_Layout, __construct);
ZEND_METHOD(PangoCairo_Layout, layoutPath);
ZEND_METHOD(PangoCairo_Layout, showLayout);
ZEND_METHOD(PangoCairo_Layout, updateLayout);
ZEND_METHOD(PangoCairo_Layout, getCairoContext);

static const zend_function_entry class_PangoCairo_Layout_methods[] = {
	ZEND_ME(PangoCairo_Layout, __construct, arginfo_class_PangoCairo_Layout___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, layoutPath, arginfo_class_PangoCairo_Layout_layoutPath, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, showLayout, arginfo_class_PangoCairo_Layout_showLayout, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, updateLayout, arginfo_class_PangoCairo_Layout_updateLayout, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Layout, getCairoContext, arginfo_class_PangoCairo_Layout_getCairoContext, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_Layout(zend_class_entry *class_entry_Pango_Layout)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "Layout", class_PangoCairo_Layout_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Layout, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Layout);
#endif

	return class_entry;
}
