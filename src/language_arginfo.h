/* This is a generated file, edit language.stub.php instead.
 * Stub hash: a650055989407dca2c77c14af83465201f48785c */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Language___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, language, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Language_getDefault, 0, 0, Pango\\Language, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Language_getPreferred, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Language_getSampleString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Language_getScripts arginfo_class_Pango_Language_getPreferred

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Language_includesScript, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, script, Pango\\Script, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Language_matches, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, languageRange, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Language___toString arginfo_class_Pango_Language_getSampleString

ZEND_METHOD(Pango_Language, __construct);
ZEND_METHOD(Pango_Language, getDefault);
ZEND_METHOD(Pango_Language, getPreferred);
ZEND_METHOD(Pango_Language, getSampleString);
ZEND_METHOD(Pango_Language, getScripts);
ZEND_METHOD(Pango_Language, includesScript);
ZEND_METHOD(Pango_Language, matches);
ZEND_METHOD(Pango_Language, __toString);

static const zend_function_entry class_Pango_Language_methods[] = {
	ZEND_ME(Pango_Language, __construct, arginfo_class_Pango_Language___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Language, getDefault, arginfo_class_Pango_Language_getDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_Language, getPreferred, arginfo_class_Pango_Language_getPreferred, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Pango_Language, getSampleString, arginfo_class_Pango_Language_getSampleString, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Language, getScripts, arginfo_class_Pango_Language_getScripts, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Language, includesScript, arginfo_class_Pango_Language_includesScript, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Language, matches, arginfo_class_Pango_Language_matches, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Language, __toString, arginfo_class_Pango_Language___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Language(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Language", class_Pango_Language_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce->ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
