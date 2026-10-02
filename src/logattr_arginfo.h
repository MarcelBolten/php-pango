/* This is a generated file, edit logattr.stub.php instead.
 * Stub hash: 97f353843eaf2d31781df593a60b79a5293b5bad */

static zend_class_entry *register_class_Pango_LogAttr(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "LogAttr", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS);
#else
	ce->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_READONLY_CLASS;
#endif

	zval property_lineBreak_default_value;
	ZVAL_UNDEF(&property_lineBreak_default_value);
	zend_string *property_lineBreak_name = zend_string_init("lineBreak", sizeof("lineBreak") - 1, true);
	zend_declare_typed_property(class_entry, property_lineBreak_name, &property_lineBreak_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_lineBreak_name, true);

	zval property_mandatoryBreak_default_value;
	ZVAL_UNDEF(&property_mandatoryBreak_default_value);
	zend_string *property_mandatoryBreak_name = zend_string_init("mandatoryBreak", sizeof("mandatoryBreak") - 1, true);
	zend_declare_typed_property(class_entry, property_mandatoryBreak_name, &property_mandatoryBreak_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_mandatoryBreak_name, true);

	zval property_charBreak_default_value;
	ZVAL_UNDEF(&property_charBreak_default_value);
	zend_string *property_charBreak_name = zend_string_init("charBreak", sizeof("charBreak") - 1, true);
	zend_declare_typed_property(class_entry, property_charBreak_name, &property_charBreak_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_charBreak_name, true);

	zval property_white_default_value;
	ZVAL_UNDEF(&property_white_default_value);
	zend_string *property_white_name = zend_string_init("white", sizeof("white") - 1, true);
	zend_declare_typed_property(class_entry, property_white_name, &property_white_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_white_name, true);

	zval property_cursorPosition_default_value;
	ZVAL_UNDEF(&property_cursorPosition_default_value);
	zend_string *property_cursorPosition_name = zend_string_init("cursorPosition", sizeof("cursorPosition") - 1, true);
	zend_declare_typed_property(class_entry, property_cursorPosition_name, &property_cursorPosition_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_cursorPosition_name, true);

	zval property_wordStart_default_value;
	ZVAL_UNDEF(&property_wordStart_default_value);
	zend_string *property_wordStart_name = zend_string_init("wordStart", sizeof("wordStart") - 1, true);
	zend_declare_typed_property(class_entry, property_wordStart_name, &property_wordStart_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_wordStart_name, true);

	zval property_wordEnd_default_value;
	ZVAL_UNDEF(&property_wordEnd_default_value);
	zend_string *property_wordEnd_name = zend_string_init("wordEnd", sizeof("wordEnd") - 1, true);
	zend_declare_typed_property(class_entry, property_wordEnd_name, &property_wordEnd_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_wordEnd_name, true);

	zval property_sentenceBoundary_default_value;
	ZVAL_UNDEF(&property_sentenceBoundary_default_value);
	zend_string *property_sentenceBoundary_name = zend_string_init("sentenceBoundary", sizeof("sentenceBoundary") - 1, true);
	zend_declare_typed_property(class_entry, property_sentenceBoundary_name, &property_sentenceBoundary_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_sentenceBoundary_name, true);

	zval property_sentenceStart_default_value;
	ZVAL_UNDEF(&property_sentenceStart_default_value);
	zend_string *property_sentenceStart_name = zend_string_init("sentenceStart", sizeof("sentenceStart") - 1, true);
	zend_declare_typed_property(class_entry, property_sentenceStart_name, &property_sentenceStart_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_sentenceStart_name, true);

	zval property_sentenceEnd_default_value;
	ZVAL_UNDEF(&property_sentenceEnd_default_value);
	zend_string *property_sentenceEnd_name = zend_string_init("sentenceEnd", sizeof("sentenceEnd") - 1, true);
	zend_declare_typed_property(class_entry, property_sentenceEnd_name, &property_sentenceEnd_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_sentenceEnd_name, true);

	zval property_backspaceDeletesCharacter_default_value;
	ZVAL_UNDEF(&property_backspaceDeletesCharacter_default_value);
	zend_string *property_backspaceDeletesCharacter_name = zend_string_init("backspaceDeletesCharacter", sizeof("backspaceDeletesCharacter") - 1, true);
	zend_declare_typed_property(class_entry, property_backspaceDeletesCharacter_name, &property_backspaceDeletesCharacter_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_backspaceDeletesCharacter_name, true);

	zval property_expandableSpace_default_value;
	ZVAL_UNDEF(&property_expandableSpace_default_value);
	zend_string *property_expandableSpace_name = zend_string_init("expandableSpace", sizeof("expandableSpace") - 1, true);
	zend_declare_typed_property(class_entry, property_expandableSpace_name, &property_expandableSpace_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_expandableSpace_name, true);

	zval property_wordBoundary_default_value;
	ZVAL_UNDEF(&property_wordBoundary_default_value);
	zend_string *property_wordBoundary_name = zend_string_init("wordBoundary", sizeof("wordBoundary") - 1, true);
	zend_declare_typed_property(class_entry, property_wordBoundary_name, &property_wordBoundary_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_wordBoundary_name, true);

	zval property_breakInsertsHyphen_default_value;
	ZVAL_UNDEF(&property_breakInsertsHyphen_default_value);
	zend_string *property_breakInsertsHyphen_name = zend_string_init("breakInsertsHyphen", sizeof("breakInsertsHyphen") - 1, true);
	zend_declare_typed_property(class_entry, property_breakInsertsHyphen_name, &property_breakInsertsHyphen_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_breakInsertsHyphen_name, true);

	zval property_breakRemovesPreceding_default_value;
	ZVAL_UNDEF(&property_breakRemovesPreceding_default_value);
	zend_string *property_breakRemovesPreceding_name = zend_string_init("breakRemovesPreceding", sizeof("breakRemovesPreceding") - 1, true);
	zend_declare_typed_property(class_entry, property_breakRemovesPreceding_name, &property_breakRemovesPreceding_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release_ex(property_breakRemovesPreceding_name, true);

	return class_entry;
}
