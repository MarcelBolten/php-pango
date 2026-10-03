/* This is a generated file, edit font_metrics.stub.php instead.
 * Stub hash: 981f84b6b0006c142b19d0b1829df92b5b2ddf5d */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_FontMetrics_getApproximateCharWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_FontMetrics_getApproximateDigitWidth arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getAscent arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getDescent arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getHeight arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getStrikethroughPosition arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getStrikethroughThickness arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getUnderlinePosition arginfo_class_Pango_FontMetrics_getApproximateCharWidth

#define arginfo_class_Pango_FontMetrics_getUnderlineThickness arginfo_class_Pango_FontMetrics_getApproximateCharWidth

ZEND_METHOD(Pango_FontMetrics, getApproximateCharWidth);
ZEND_METHOD(Pango_FontMetrics, getApproximateDigitWidth);
ZEND_METHOD(Pango_FontMetrics, getAscent);
ZEND_METHOD(Pango_FontMetrics, getDescent);
ZEND_METHOD(Pango_FontMetrics, getHeight);
ZEND_METHOD(Pango_FontMetrics, getStrikethroughPosition);
ZEND_METHOD(Pango_FontMetrics, getStrikethroughThickness);
ZEND_METHOD(Pango_FontMetrics, getUnderlinePosition);
ZEND_METHOD(Pango_FontMetrics, getUnderlineThickness);

static const zend_function_entry class_Pango_FontMetrics_methods[] = {
	ZEND_ME(Pango_FontMetrics, getApproximateCharWidth, arginfo_class_Pango_FontMetrics_getApproximateCharWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getApproximateDigitWidth, arginfo_class_Pango_FontMetrics_getApproximateDigitWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getAscent, arginfo_class_Pango_FontMetrics_getAscent, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getDescent, arginfo_class_Pango_FontMetrics_getDescent, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getHeight, arginfo_class_Pango_FontMetrics_getHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getStrikethroughPosition, arginfo_class_Pango_FontMetrics_getStrikethroughPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getStrikethroughThickness, arginfo_class_Pango_FontMetrics_getStrikethroughThickness, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getUnderlinePosition, arginfo_class_Pango_FontMetrics_getUnderlinePosition, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_FontMetrics, getUnderlineThickness, arginfo_class_Pango_FontMetrics_getUnderlineThickness, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_FontMetrics(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "FontMetrics", class_Pango_FontMetrics_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	ce.ce_flags |= ZEND_ACC_FINAL;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	return class_entry;
}
