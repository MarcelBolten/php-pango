/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9bd6618f0c9b4f8e9a64ffaea73ee3fafb154c8d */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutLine_getExtents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutLine_getHeight, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutLine_getLength, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Pango_LayoutLine_getPixelExtents arginfo_class_Pango_LayoutLine_getExtents

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutLine_showLayoutLine, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, context, Cairo\\Context, 1, "null")
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LayoutLine_getResolvedDirection, 0, 0, Pango\\Direction, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_LayoutLine_getStartIndex arginfo_class_Pango_LayoutLine_getLength

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutLine_isParagraphStart, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()
#endif

#define arginfo_class_Pango_LayoutLine_getRuns arginfo_class_Pango_LayoutLine_getExtents

ZEND_METHOD(Pango_LayoutLine, getExtents);
ZEND_METHOD(Pango_LayoutLine, getHeight);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_METHOD(Pango_LayoutLine, getLength);
#endif
ZEND_METHOD(Pango_LayoutLine, getPixelExtents);
ZEND_METHOD(Pango_LayoutLine, showLayoutLine);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
ZEND_METHOD(Pango_LayoutLine, getResolvedDirection);
ZEND_METHOD(Pango_LayoutLine, getStartIndex);
ZEND_METHOD(Pango_LayoutLine, isParagraphStart);
#endif
ZEND_METHOD(Pango_LayoutLine, getRuns);

static const zend_function_entry class_Pango_LayoutLine_methods[] = {
	ZEND_ME(Pango_LayoutLine, getExtents, arginfo_class_Pango_LayoutLine_getExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutLine, getHeight, arginfo_class_Pango_LayoutLine_getHeight, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	ZEND_ME(Pango_LayoutLine, getLength, arginfo_class_Pango_LayoutLine_getLength, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_LayoutLine, getPixelExtents, arginfo_class_Pango_LayoutLine_getPixelExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutLine, showLayoutLine, arginfo_class_Pango_LayoutLine_showLayoutLine, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
	ZEND_ME(Pango_LayoutLine, getResolvedDirection, arginfo_class_Pango_LayoutLine_getResolvedDirection, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutLine, getStartIndex, arginfo_class_Pango_LayoutLine_getStartIndex, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutLine, isParagraphStart, arginfo_class_Pango_LayoutLine_isParagraphStart, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_LayoutLine, getRuns, arginfo_class_Pango_LayoutLine_getRuns, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_LayoutLine(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "LayoutLine", class_Pango_LayoutLine_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
