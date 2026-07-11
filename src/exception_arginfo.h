/* This is a generated file, edit exception.stub.php instead.
 * Stub hash: bdbbee11128049b82c7d110d3f211ff2c09889c0 */

static zend_class_entry *register_class_Pango_Exception(zend_class_entry *class_entry_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Exception", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Exception, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Exception);
#endif

	return class_entry;
}
