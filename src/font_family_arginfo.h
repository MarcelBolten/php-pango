/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4b90b2dace5e414ec2fa2135f0a4b9bc62368886 */

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontFamily_getFace, 0, 0, Pango\\FontFace, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFamily_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFamily_isMonospace, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFamily_isVariable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFamily_listFaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
ZEND_METHOD(Pango_FontFamily, getFace);
#endif
ZEND_METHOD(Pango_FontFamily, getName);
ZEND_METHOD(Pango_FontFamily, isMonospace);
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
ZEND_METHOD(Pango_FontFamily, isVariable);
#endif
ZEND_METHOD(Pango_FontFamily, listFaces);

static const zend_function_entry class_Pango_FontFamily_methods[] = {
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
	ZEND_ME(Pango_FontFamily, getFace, arginfo_class_Pango_FontFamily_getFace, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontFamily, getName, arginfo_class_Pango_FontFamily_getName, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontFamily, isMonospace, arginfo_class_Pango_FontFamily_isMonospace, ZEND_ACC_PUBLIC)
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
	ZEND_ME(Pango_FontFamily, isVariable, arginfo_class_Pango_FontFamily_isVariable, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Pango_FontFamily, listFaces, arginfo_class_Pango_FontFamily_listFaces, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontFamily(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontFamily", class_Pango_FontFamily_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
