/* This is a generated file, edit layout_iter.stub.php instead.
 * Stub hash: 7b7353261a9acfd8e1132d4bacf51e3789ad2a57 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_LayoutIter___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutIter_atLastLine, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutIter_getBaseline, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LayoutIter_getCharExtents, 0, 0, Pango\\Rectangle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_LayoutIter_getClusterExtents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_LayoutIter_getIndex arginfo_class_Pango_LayoutIter_getBaseline

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LayoutIter_getLayout, 0, 0, Pango\\Layout, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_LayoutIter_getLayoutExtents arginfo_class_Pango_LayoutIter_getClusterExtents

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LayoutIter_getLine, 0, 0, Pango\\LayoutLine, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_LayoutIter_getLineExtents arginfo_class_Pango_LayoutIter_getClusterExtents

#define arginfo_class_Pango_LayoutIter_getLineYrange arginfo_class_Pango_LayoutIter_getClusterExtents

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_LayoutIter_getRun, 0, 0, Pango\\GlyphItem, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_LayoutIter_getRunBaseline arginfo_class_Pango_LayoutIter_getBaseline

#define arginfo_class_Pango_LayoutIter_getRunExtents arginfo_class_Pango_LayoutIter_getClusterExtents

#define arginfo_class_Pango_LayoutIter_nextChar arginfo_class_Pango_LayoutIter_atLastLine

#define arginfo_class_Pango_LayoutIter_nextCluster arginfo_class_Pango_LayoutIter_atLastLine

#define arginfo_class_Pango_LayoutIter_nextLine arginfo_class_Pango_LayoutIter_atLastLine

#define arginfo_class_Pango_LayoutIter_nextRun arginfo_class_Pango_LayoutIter_atLastLine

ZEND_METHOD(Pango_LayoutIter, __construct);
ZEND_METHOD(Pango_LayoutIter, atLastLine);
ZEND_METHOD(Pango_LayoutIter, getBaseline);
ZEND_METHOD(Pango_LayoutIter, getCharExtents);
ZEND_METHOD(Pango_LayoutIter, getClusterExtents);
ZEND_METHOD(Pango_LayoutIter, getIndex);
ZEND_METHOD(Pango_LayoutIter, getLayout);
ZEND_METHOD(Pango_LayoutIter, getLayoutExtents);
ZEND_METHOD(Pango_LayoutIter, getLine);
ZEND_METHOD(Pango_LayoutIter, getLineExtents);
ZEND_METHOD(Pango_LayoutIter, getLineYrange);
ZEND_METHOD(Pango_LayoutIter, getRun);
ZEND_METHOD(Pango_LayoutIter, getRunBaseline);
ZEND_METHOD(Pango_LayoutIter, getRunExtents);
ZEND_METHOD(Pango_LayoutIter, nextChar);
ZEND_METHOD(Pango_LayoutIter, nextCluster);
ZEND_METHOD(Pango_LayoutIter, nextLine);
ZEND_METHOD(Pango_LayoutIter, nextRun);

static const zend_function_entry class_Pango_LayoutIter_methods[] = {
	ZEND_ME(Pango_LayoutIter, __construct, arginfo_class_Pango_LayoutIter___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(Pango_LayoutIter, atLastLine, arginfo_class_Pango_LayoutIter_atLastLine, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getBaseline, arginfo_class_Pango_LayoutIter_getBaseline, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getCharExtents, arginfo_class_Pango_LayoutIter_getCharExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getClusterExtents, arginfo_class_Pango_LayoutIter_getClusterExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getIndex, arginfo_class_Pango_LayoutIter_getIndex, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getLayout, arginfo_class_Pango_LayoutIter_getLayout, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getLayoutExtents, arginfo_class_Pango_LayoutIter_getLayoutExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getLine, arginfo_class_Pango_LayoutIter_getLine, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getLineExtents, arginfo_class_Pango_LayoutIter_getLineExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getLineYrange, arginfo_class_Pango_LayoutIter_getLineYrange, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getRun, arginfo_class_Pango_LayoutIter_getRun, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getRunBaseline, arginfo_class_Pango_LayoutIter_getRunBaseline, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, getRunExtents, arginfo_class_Pango_LayoutIter_getRunExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, nextChar, arginfo_class_Pango_LayoutIter_nextChar, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, nextCluster, arginfo_class_Pango_LayoutIter_nextCluster, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, nextLine, arginfo_class_Pango_LayoutIter_nextLine, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_LayoutIter, nextRun, arginfo_class_Pango_LayoutIter_nextRun, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_LayoutIter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "LayoutIter", class_Pango_LayoutIter_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
