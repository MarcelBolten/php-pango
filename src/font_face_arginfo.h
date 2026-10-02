/* This is a generated file, edit font_face.stub.php instead.
 * Stub hash: 8eb22e269cbcea3706f1d3dd971e4db85023b895 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontFace_describe, 0, 0, Pango\\FontDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFace_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_FontFace_getFamily, 0, 0, Pango\\FontFamily, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFace_isSynthesized, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontFace_listSizes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_FontFace, describe);
ZEND_METHOD(Pango_FontFace, getName);
ZEND_METHOD(Pango_FontFace, getFamily);
ZEND_METHOD(Pango_FontFace, isSynthesized);
ZEND_METHOD(Pango_FontFace, listSizes);

static const zend_function_entry class_Pango_FontFace_methods[] = {
	ZEND_ME(Pango_FontFace, describe, arginfo_class_Pango_FontFace_describe, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontFace, getName, arginfo_class_Pango_FontFace_getName, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontFace, getFamily, arginfo_class_Pango_FontFace_getFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontFace, isSynthesized, arginfo_class_Pango_FontFace_isSynthesized, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontFace, listSizes, arginfo_class_Pango_FontFace_listSizes, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontFace(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontFace", class_Pango_FontFace_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
