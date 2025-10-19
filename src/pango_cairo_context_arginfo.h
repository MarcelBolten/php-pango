/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: ccb7e74aac3f047d736ac284d6488d9522b2b6c3 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_PangoCairo_Context___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_Context_getCairoContext, 0, 0, Cairo\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoCairo_Context_getFontOptions, 0, 0, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Context_setFontOptions, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, options, Cairo\\FontOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Context_getResolution, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Context_setResolution, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, dpi, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoCairo_Context_updateContext, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(PangoCairo_Context, __construct);
ZEND_METHOD(PangoCairo_Context, getCairoContext);
ZEND_METHOD(PangoCairo_Context, getFontOptions);
ZEND_METHOD(PangoCairo_Context, setFontOptions);
ZEND_METHOD(PangoCairo_Context, getResolution);
ZEND_METHOD(PangoCairo_Context, setResolution);
ZEND_METHOD(PangoCairo_Context, updateContext);

static const zend_function_entry class_PangoCairo_Context_methods[] = {
	ZEND_ME(PangoCairo_Context, __construct, arginfo_class_PangoCairo_Context___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, getCairoContext, arginfo_class_PangoCairo_Context_getCairoContext, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, getFontOptions, arginfo_class_PangoCairo_Context_getFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, setFontOptions, arginfo_class_PangoCairo_Context_setFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, getResolution, arginfo_class_PangoCairo_Context_getResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, setResolution, arginfo_class_PangoCairo_Context_setResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoCairo_Context, updateContext, arginfo_class_PangoCairo_Context_updateContext, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoCairo_Context(zend_class_entry *class_entry_Pango_Context)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "PangoCairo", "Context", class_PangoCairo_Context_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Pango_Context, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Pango_Context);
#endif

	return class_entry;
}
