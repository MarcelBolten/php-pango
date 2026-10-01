/* This is a generated file, edit script.stub.php instead.
 * Stub hash: e5672298e3f65696a5a0dabec01a7c8b3eb83b49 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Script_getSampleLanguage, 0, 0, Pango\\Language, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Script_getGravity, 0, 0, Pango\\Gravity, 1)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, baseGravity, Pango\\Gravity, 0, "Pango\\Gravity::Auto")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, hint, Pango\\GravityHint, 0, "Pango\\GravityHint::Natural")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, wide, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Script, getSampleLanguage);
ZEND_METHOD(Pango_Script, getGravity);

static const zend_function_entry class_Pango_Script_methods[] = {
	ZEND_ME(Pango_Script, getSampleLanguage, arginfo_class_Pango_Script_getSampleLanguage, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Script, getGravity, arginfo_class_Pango_Script_getGravity, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Script(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Script", IS_LONG, class_Pango_Script_methods);

	zval enum_case_UnknownNewScript_value;
	ZVAL_LONG(&enum_case_UnknownNewScript_value, -9999);
	zend_enum_add_case_cstr(class_entry, "UnknownNewScript", &enum_case_UnknownNewScript_value);

	zval enum_case_InvalidCode_value;
	ZVAL_LONG(&enum_case_InvalidCode_value, G_UNICODE_SCRIPT_INVALID_CODE);
	zend_enum_add_case_cstr(class_entry, "InvalidCode", &enum_case_InvalidCode_value);

	zval enum_case_Common_value;
	ZVAL_LONG(&enum_case_Common_value, G_UNICODE_SCRIPT_COMMON);
	zend_enum_add_case_cstr(class_entry, "Common", &enum_case_Common_value);

	zval enum_case_Inherited_value;
	ZVAL_LONG(&enum_case_Inherited_value, G_UNICODE_SCRIPT_INHERITED);
	zend_enum_add_case_cstr(class_entry, "Inherited", &enum_case_Inherited_value);

	zval enum_case_Arabic_value;
	ZVAL_LONG(&enum_case_Arabic_value, G_UNICODE_SCRIPT_ARABIC);
	zend_enum_add_case_cstr(class_entry, "Arabic", &enum_case_Arabic_value);

	zval enum_case_Armenian_value;
	ZVAL_LONG(&enum_case_Armenian_value, G_UNICODE_SCRIPT_ARMENIAN);
	zend_enum_add_case_cstr(class_entry, "Armenian", &enum_case_Armenian_value);

	zval enum_case_Bengali_value;
	ZVAL_LONG(&enum_case_Bengali_value, G_UNICODE_SCRIPT_BENGALI);
	zend_enum_add_case_cstr(class_entry, "Bengali", &enum_case_Bengali_value);

	zval enum_case_Bopomofo_value;
	ZVAL_LONG(&enum_case_Bopomofo_value, G_UNICODE_SCRIPT_BOPOMOFO);
	zend_enum_add_case_cstr(class_entry, "Bopomofo", &enum_case_Bopomofo_value);

	zval enum_case_Cherokee_value;
	ZVAL_LONG(&enum_case_Cherokee_value, G_UNICODE_SCRIPT_CHEROKEE);
	zend_enum_add_case_cstr(class_entry, "Cherokee", &enum_case_Cherokee_value);

	zval enum_case_Coptic_value;
	ZVAL_LONG(&enum_case_Coptic_value, G_UNICODE_SCRIPT_COPTIC);
	zend_enum_add_case_cstr(class_entry, "Coptic", &enum_case_Coptic_value);

	zval enum_case_Cyrillic_value;
	ZVAL_LONG(&enum_case_Cyrillic_value, G_UNICODE_SCRIPT_CYRILLIC);
	zend_enum_add_case_cstr(class_entry, "Cyrillic", &enum_case_Cyrillic_value);

	zval enum_case_Deseret_value;
	ZVAL_LONG(&enum_case_Deseret_value, G_UNICODE_SCRIPT_DESERET);
	zend_enum_add_case_cstr(class_entry, "Deseret", &enum_case_Deseret_value);

	zval enum_case_Devanagari_value;
	ZVAL_LONG(&enum_case_Devanagari_value, G_UNICODE_SCRIPT_DEVANAGARI);
	zend_enum_add_case_cstr(class_entry, "Devanagari", &enum_case_Devanagari_value);

	zval enum_case_Ethiopic_value;
	ZVAL_LONG(&enum_case_Ethiopic_value, G_UNICODE_SCRIPT_ETHIOPIC);
	zend_enum_add_case_cstr(class_entry, "Ethiopic", &enum_case_Ethiopic_value);

	zval enum_case_Georgian_value;
	ZVAL_LONG(&enum_case_Georgian_value, G_UNICODE_SCRIPT_GEORGIAN);
	zend_enum_add_case_cstr(class_entry, "Georgian", &enum_case_Georgian_value);

	zval enum_case_Gothic_value;
	ZVAL_LONG(&enum_case_Gothic_value, G_UNICODE_SCRIPT_GOTHIC);
	zend_enum_add_case_cstr(class_entry, "Gothic", &enum_case_Gothic_value);

	zval enum_case_Greek_value;
	ZVAL_LONG(&enum_case_Greek_value, G_UNICODE_SCRIPT_GREEK);
	zend_enum_add_case_cstr(class_entry, "Greek", &enum_case_Greek_value);

	zval enum_case_Gujarati_value;
	ZVAL_LONG(&enum_case_Gujarati_value, G_UNICODE_SCRIPT_GUJARATI);
	zend_enum_add_case_cstr(class_entry, "Gujarati", &enum_case_Gujarati_value);

	zval enum_case_Gurmukhi_value;
	ZVAL_LONG(&enum_case_Gurmukhi_value, G_UNICODE_SCRIPT_GURMUKHI);
	zend_enum_add_case_cstr(class_entry, "Gurmukhi", &enum_case_Gurmukhi_value);

	zval enum_case_Han_value;
	ZVAL_LONG(&enum_case_Han_value, G_UNICODE_SCRIPT_HAN);
	zend_enum_add_case_cstr(class_entry, "Han", &enum_case_Han_value);

	zval enum_case_Hangul_value;
	ZVAL_LONG(&enum_case_Hangul_value, G_UNICODE_SCRIPT_HANGUL);
	zend_enum_add_case_cstr(class_entry, "Hangul", &enum_case_Hangul_value);

	zval enum_case_Hebrew_value;
	ZVAL_LONG(&enum_case_Hebrew_value, G_UNICODE_SCRIPT_HEBREW);
	zend_enum_add_case_cstr(class_entry, "Hebrew", &enum_case_Hebrew_value);

	zval enum_case_Hiragana_value;
	ZVAL_LONG(&enum_case_Hiragana_value, G_UNICODE_SCRIPT_HIRAGANA);
	zend_enum_add_case_cstr(class_entry, "Hiragana", &enum_case_Hiragana_value);

	zval enum_case_Kannada_value;
	ZVAL_LONG(&enum_case_Kannada_value, G_UNICODE_SCRIPT_KANNADA);
	zend_enum_add_case_cstr(class_entry, "Kannada", &enum_case_Kannada_value);

	zval enum_case_Katakana_value;
	ZVAL_LONG(&enum_case_Katakana_value, G_UNICODE_SCRIPT_KATAKANA);
	zend_enum_add_case_cstr(class_entry, "Katakana", &enum_case_Katakana_value);

	zval enum_case_Khmer_value;
	ZVAL_LONG(&enum_case_Khmer_value, G_UNICODE_SCRIPT_KHMER);
	zend_enum_add_case_cstr(class_entry, "Khmer", &enum_case_Khmer_value);

	zval enum_case_Lao_value;
	ZVAL_LONG(&enum_case_Lao_value, G_UNICODE_SCRIPT_LAO);
	zend_enum_add_case_cstr(class_entry, "Lao", &enum_case_Lao_value);

	zval enum_case_Latin_value;
	ZVAL_LONG(&enum_case_Latin_value, G_UNICODE_SCRIPT_LATIN);
	zend_enum_add_case_cstr(class_entry, "Latin", &enum_case_Latin_value);

	zval enum_case_Malayalam_value;
	ZVAL_LONG(&enum_case_Malayalam_value, G_UNICODE_SCRIPT_MALAYALAM);
	zend_enum_add_case_cstr(class_entry, "Malayalam", &enum_case_Malayalam_value);

	zval enum_case_Mongolian_value;
	ZVAL_LONG(&enum_case_Mongolian_value, G_UNICODE_SCRIPT_MONGOLIAN);
	zend_enum_add_case_cstr(class_entry, "Mongolian", &enum_case_Mongolian_value);

	zval enum_case_Myanmar_value;
	ZVAL_LONG(&enum_case_Myanmar_value, G_UNICODE_SCRIPT_MYANMAR);
	zend_enum_add_case_cstr(class_entry, "Myanmar", &enum_case_Myanmar_value);

	zval enum_case_Ogham_value;
	ZVAL_LONG(&enum_case_Ogham_value, G_UNICODE_SCRIPT_OGHAM);
	zend_enum_add_case_cstr(class_entry, "Ogham", &enum_case_Ogham_value);

	zval enum_case_Old_Italic_value;
	ZVAL_LONG(&enum_case_Old_Italic_value, G_UNICODE_SCRIPT_OLD_ITALIC);
	zend_enum_add_case_cstr(class_entry, "Old_Italic", &enum_case_Old_Italic_value);

	zval enum_case_Oriya_value;
	ZVAL_LONG(&enum_case_Oriya_value, G_UNICODE_SCRIPT_ORIYA);
	zend_enum_add_case_cstr(class_entry, "Oriya", &enum_case_Oriya_value);

	zval enum_case_Runic_value;
	ZVAL_LONG(&enum_case_Runic_value, G_UNICODE_SCRIPT_RUNIC);
	zend_enum_add_case_cstr(class_entry, "Runic", &enum_case_Runic_value);

	zval enum_case_Sinhala_value;
	ZVAL_LONG(&enum_case_Sinhala_value, G_UNICODE_SCRIPT_SINHALA);
	zend_enum_add_case_cstr(class_entry, "Sinhala", &enum_case_Sinhala_value);

	zval enum_case_Syriac_value;
	ZVAL_LONG(&enum_case_Syriac_value, G_UNICODE_SCRIPT_SYRIAC);
	zend_enum_add_case_cstr(class_entry, "Syriac", &enum_case_Syriac_value);

	zval enum_case_Tamil_value;
	ZVAL_LONG(&enum_case_Tamil_value, G_UNICODE_SCRIPT_TAMIL);
	zend_enum_add_case_cstr(class_entry, "Tamil", &enum_case_Tamil_value);

	zval enum_case_Telugu_value;
	ZVAL_LONG(&enum_case_Telugu_value, G_UNICODE_SCRIPT_TELUGU);
	zend_enum_add_case_cstr(class_entry, "Telugu", &enum_case_Telugu_value);

	zval enum_case_Thaana_value;
	ZVAL_LONG(&enum_case_Thaana_value, G_UNICODE_SCRIPT_THAANA);
	zend_enum_add_case_cstr(class_entry, "Thaana", &enum_case_Thaana_value);

	zval enum_case_Thai_value;
	ZVAL_LONG(&enum_case_Thai_value, G_UNICODE_SCRIPT_THAI);
	zend_enum_add_case_cstr(class_entry, "Thai", &enum_case_Thai_value);

	zval enum_case_Tibetan_value;
	ZVAL_LONG(&enum_case_Tibetan_value, G_UNICODE_SCRIPT_TIBETAN);
	zend_enum_add_case_cstr(class_entry, "Tibetan", &enum_case_Tibetan_value);

	zval enum_case_CanadianAboriginal_value;
	ZVAL_LONG(&enum_case_CanadianAboriginal_value, G_UNICODE_SCRIPT_CANADIAN_ABORIGINAL);
	zend_enum_add_case_cstr(class_entry, "CanadianAboriginal", &enum_case_CanadianAboriginal_value);

	zval enum_case_Yi_value;
	ZVAL_LONG(&enum_case_Yi_value, G_UNICODE_SCRIPT_YI);
	zend_enum_add_case_cstr(class_entry, "Yi", &enum_case_Yi_value);

	zval enum_case_Tagalog_value;
	ZVAL_LONG(&enum_case_Tagalog_value, G_UNICODE_SCRIPT_TAGALOG);
	zend_enum_add_case_cstr(class_entry, "Tagalog", &enum_case_Tagalog_value);

	zval enum_case_Hanunoo_value;
	ZVAL_LONG(&enum_case_Hanunoo_value, G_UNICODE_SCRIPT_HANUNOO);
	zend_enum_add_case_cstr(class_entry, "Hanunoo", &enum_case_Hanunoo_value);

	zval enum_case_Buhid_value;
	ZVAL_LONG(&enum_case_Buhid_value, G_UNICODE_SCRIPT_BUHID);
	zend_enum_add_case_cstr(class_entry, "Buhid", &enum_case_Buhid_value);

	zval enum_case_Tagbanwa_value;
	ZVAL_LONG(&enum_case_Tagbanwa_value, G_UNICODE_SCRIPT_TAGBANWA);
	zend_enum_add_case_cstr(class_entry, "Tagbanwa", &enum_case_Tagbanwa_value);

	zval enum_case_Braille_value;
	ZVAL_LONG(&enum_case_Braille_value, G_UNICODE_SCRIPT_BRAILLE);
	zend_enum_add_case_cstr(class_entry, "Braille", &enum_case_Braille_value);

	zval enum_case_Cypriot_value;
	ZVAL_LONG(&enum_case_Cypriot_value, G_UNICODE_SCRIPT_CYPRIOT);
	zend_enum_add_case_cstr(class_entry, "Cypriot", &enum_case_Cypriot_value);

	zval enum_case_Limbu_value;
	ZVAL_LONG(&enum_case_Limbu_value, G_UNICODE_SCRIPT_LIMBU);
	zend_enum_add_case_cstr(class_entry, "Limbu", &enum_case_Limbu_value);

	zval enum_case_Osmanya_value;
	ZVAL_LONG(&enum_case_Osmanya_value, G_UNICODE_SCRIPT_OSMANYA);
	zend_enum_add_case_cstr(class_entry, "Osmanya", &enum_case_Osmanya_value);

	zval enum_case_Shavian_value;
	ZVAL_LONG(&enum_case_Shavian_value, G_UNICODE_SCRIPT_SHAVIAN);
	zend_enum_add_case_cstr(class_entry, "Shavian", &enum_case_Shavian_value);

	zval enum_case_LinearB_value;
	ZVAL_LONG(&enum_case_LinearB_value, G_UNICODE_SCRIPT_LINEAR_B);
	zend_enum_add_case_cstr(class_entry, "LinearB", &enum_case_LinearB_value);

	zval enum_case_TaiLe_value;
	ZVAL_LONG(&enum_case_TaiLe_value, G_UNICODE_SCRIPT_TAI_LE);
	zend_enum_add_case_cstr(class_entry, "TaiLe", &enum_case_TaiLe_value);

	zval enum_case_Ugaritic_value;
	ZVAL_LONG(&enum_case_Ugaritic_value, G_UNICODE_SCRIPT_UGARITIC);
	zend_enum_add_case_cstr(class_entry, "Ugaritic", &enum_case_Ugaritic_value);

	zval enum_case_NewTaiLue_value;
	ZVAL_LONG(&enum_case_NewTaiLue_value, G_UNICODE_SCRIPT_NEW_TAI_LUE);
	zend_enum_add_case_cstr(class_entry, "NewTaiLue", &enum_case_NewTaiLue_value);

	zval enum_case_Buginese_value;
	ZVAL_LONG(&enum_case_Buginese_value, G_UNICODE_SCRIPT_BUGINESE);
	zend_enum_add_case_cstr(class_entry, "Buginese", &enum_case_Buginese_value);

	zval enum_case_Glagolitic_value;
	ZVAL_LONG(&enum_case_Glagolitic_value, G_UNICODE_SCRIPT_GLAGOLITIC);
	zend_enum_add_case_cstr(class_entry, "Glagolitic", &enum_case_Glagolitic_value);

	zval enum_case_Tifinagh_value;
	ZVAL_LONG(&enum_case_Tifinagh_value, G_UNICODE_SCRIPT_TIFINAGH);
	zend_enum_add_case_cstr(class_entry, "Tifinagh", &enum_case_Tifinagh_value);

	zval enum_case_SylotiNagri_value;
	ZVAL_LONG(&enum_case_SylotiNagri_value, G_UNICODE_SCRIPT_SYLOTI_NAGRI);
	zend_enum_add_case_cstr(class_entry, "SylotiNagri", &enum_case_SylotiNagri_value);

	zval enum_case_OldPersian_value;
	ZVAL_LONG(&enum_case_OldPersian_value, G_UNICODE_SCRIPT_OLD_PERSIAN);
	zend_enum_add_case_cstr(class_entry, "OldPersian", &enum_case_OldPersian_value);

	zval enum_case_Kharoshthi_value;
	ZVAL_LONG(&enum_case_Kharoshthi_value, G_UNICODE_SCRIPT_KHAROSHTHI);
	zend_enum_add_case_cstr(class_entry, "Kharoshthi", &enum_case_Kharoshthi_value);

	zval enum_case_Unknown_value;
	ZVAL_LONG(&enum_case_Unknown_value, G_UNICODE_SCRIPT_UNKNOWN);
	zend_enum_add_case_cstr(class_entry, "Unknown", &enum_case_Unknown_value);

	zval enum_case_Balinese_value;
	ZVAL_LONG(&enum_case_Balinese_value, G_UNICODE_SCRIPT_BALINESE);
	zend_enum_add_case_cstr(class_entry, "Balinese", &enum_case_Balinese_value);

	zval enum_case_Cuneiform_value;
	ZVAL_LONG(&enum_case_Cuneiform_value, G_UNICODE_SCRIPT_CUNEIFORM);
	zend_enum_add_case_cstr(class_entry, "Cuneiform", &enum_case_Cuneiform_value);

	zval enum_case_Phoenician_value;
	ZVAL_LONG(&enum_case_Phoenician_value, G_UNICODE_SCRIPT_PHOENICIAN);
	zend_enum_add_case_cstr(class_entry, "Phoenician", &enum_case_Phoenician_value);

	zval enum_case_PhagsPa_value;
	ZVAL_LONG(&enum_case_PhagsPa_value, G_UNICODE_SCRIPT_PHAGS_PA);
	zend_enum_add_case_cstr(class_entry, "PhagsPa", &enum_case_PhagsPa_value);

	zval enum_case_Nko_value;
	ZVAL_LONG(&enum_case_Nko_value, G_UNICODE_SCRIPT_NKO);
	zend_enum_add_case_cstr(class_entry, "Nko", &enum_case_Nko_value);

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_KayahLi_value;
	ZVAL_LONG(&enum_case_KayahLi_value, G_UNICODE_SCRIPT_KAYAH_LI);
	zend_enum_add_case_cstr(class_entry, "KayahLi", &enum_case_KayahLi_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Lepcha_value;
	ZVAL_LONG(&enum_case_Lepcha_value, G_UNICODE_SCRIPT_LEPCHA);
	zend_enum_add_case_cstr(class_entry, "Lepcha", &enum_case_Lepcha_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Rejang_value;
	ZVAL_LONG(&enum_case_Rejang_value, G_UNICODE_SCRIPT_REJANG);
	zend_enum_add_case_cstr(class_entry, "Rejang", &enum_case_Rejang_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Sundanese_value;
	ZVAL_LONG(&enum_case_Sundanese_value, G_UNICODE_SCRIPT_SUNDANESE);
	zend_enum_add_case_cstr(class_entry, "Sundanese", &enum_case_Sundanese_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Saurashtra_value;
	ZVAL_LONG(&enum_case_Saurashtra_value, G_UNICODE_SCRIPT_SAURASHTRA);
	zend_enum_add_case_cstr(class_entry, "Saurashtra", &enum_case_Saurashtra_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Cham_value;
	ZVAL_LONG(&enum_case_Cham_value, G_UNICODE_SCRIPT_CHAM);
	zend_enum_add_case_cstr(class_entry, "Cham", &enum_case_Cham_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_OlChiki_value;
	ZVAL_LONG(&enum_case_OlChiki_value, G_UNICODE_SCRIPT_OL_CHIKI);
	zend_enum_add_case_cstr(class_entry, "OlChiki", &enum_case_OlChiki_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Vai_value;
	ZVAL_LONG(&enum_case_Vai_value, G_UNICODE_SCRIPT_VAI);
	zend_enum_add_case_cstr(class_entry, "Vai", &enum_case_Vai_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Carian_value;
	ZVAL_LONG(&enum_case_Carian_value, G_UNICODE_SCRIPT_CARIAN);
	zend_enum_add_case_cstr(class_entry, "Carian", &enum_case_Carian_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Lycian_value;
	ZVAL_LONG(&enum_case_Lycian_value, G_UNICODE_SCRIPT_LYCIAN);
	zend_enum_add_case_cstr(class_entry, "Lycian", &enum_case_Lycian_value);
#endif

#if GLIB_CHECK_VERSION(2, 16, 3)
	zval enum_case_Lydian_value;
	ZVAL_LONG(&enum_case_Lydian_value, G_UNICODE_SCRIPT_LYDIAN);
	zend_enum_add_case_cstr(class_entry, "Lydian", &enum_case_Lydian_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Avestan_value;
	ZVAL_LONG(&enum_case_Avestan_value, G_UNICODE_SCRIPT_AVESTAN);
	zend_enum_add_case_cstr(class_entry, "Avestan", &enum_case_Avestan_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Bamum_value;
	ZVAL_LONG(&enum_case_Bamum_value, G_UNICODE_SCRIPT_BAMUM);
	zend_enum_add_case_cstr(class_entry, "Bamum", &enum_case_Bamum_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_EgyptianHieroglyphs_value;
	ZVAL_LONG(&enum_case_EgyptianHieroglyphs_value, G_UNICODE_SCRIPT_EGYPTIAN_HIEROGLYPHS);
	zend_enum_add_case_cstr(class_entry, "EgyptianHieroglyphs", &enum_case_EgyptianHieroglyphs_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_ImperialAramaic_value;
	ZVAL_LONG(&enum_case_ImperialAramaic_value, G_UNICODE_SCRIPT_IMPERIAL_ARAMAIC);
	zend_enum_add_case_cstr(class_entry, "ImperialAramaic", &enum_case_ImperialAramaic_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_InscriptionalPahlavi_value;
	ZVAL_LONG(&enum_case_InscriptionalPahlavi_value, G_UNICODE_SCRIPT_INSCRIPTIONAL_PAHLAVI);
	zend_enum_add_case_cstr(class_entry, "InscriptionalPahlavi", &enum_case_InscriptionalPahlavi_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_InscriptionalParthian_value;
	ZVAL_LONG(&enum_case_InscriptionalParthian_value, G_UNICODE_SCRIPT_INSCRIPTIONAL_PARTHIAN);
	zend_enum_add_case_cstr(class_entry, "InscriptionalParthian", &enum_case_InscriptionalParthian_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Javanese_value;
	ZVAL_LONG(&enum_case_Javanese_value, G_UNICODE_SCRIPT_JAVANESE);
	zend_enum_add_case_cstr(class_entry, "Javanese", &enum_case_Javanese_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Kaithi_value;
	ZVAL_LONG(&enum_case_Kaithi_value, G_UNICODE_SCRIPT_KAITHI);
	zend_enum_add_case_cstr(class_entry, "Kaithi", &enum_case_Kaithi_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Lisu_value;
	ZVAL_LONG(&enum_case_Lisu_value, G_UNICODE_SCRIPT_LISU);
	zend_enum_add_case_cstr(class_entry, "Lisu", &enum_case_Lisu_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_MeeteiMayek_value;
	ZVAL_LONG(&enum_case_MeeteiMayek_value, G_UNICODE_SCRIPT_MEETEI_MAYEK);
	zend_enum_add_case_cstr(class_entry, "MeeteiMayek", &enum_case_MeeteiMayek_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_OldSouthArabian_value;
	ZVAL_LONG(&enum_case_OldSouthArabian_value, G_UNICODE_SCRIPT_OLD_SOUTH_ARABIAN);
	zend_enum_add_case_cstr(class_entry, "OldSouthArabian", &enum_case_OldSouthArabian_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_Samaritan_value;
	ZVAL_LONG(&enum_case_Samaritan_value, G_UNICODE_SCRIPT_SAMARITAN);
	zend_enum_add_case_cstr(class_entry, "Samaritan", &enum_case_Samaritan_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_TaiTham_value;
	ZVAL_LONG(&enum_case_TaiTham_value, G_UNICODE_SCRIPT_TAI_THAM);
	zend_enum_add_case_cstr(class_entry, "TaiTham", &enum_case_TaiTham_value);
#endif

#if GLIB_CHECK_VERSION(2, 26, 0)
	zval enum_case_TaiViet_value;
	ZVAL_LONG(&enum_case_TaiViet_value, G_UNICODE_SCRIPT_TAI_VIET);
	zend_enum_add_case_cstr(class_entry, "TaiViet", &enum_case_TaiViet_value);
#endif

#if GLIB_CHECK_VERSION(2, 28, 0)
	zval enum_case_OldTurkic_value;
	ZVAL_LONG(&enum_case_OldTurkic_value, G_UNICODE_SCRIPT_OLD_TURKIC);
	zend_enum_add_case_cstr(class_entry, "OldTurkic", &enum_case_OldTurkic_value);
#endif

#if GLIB_CHECK_VERSION(2, 28, 0)
	zval enum_case_Batak_value;
	ZVAL_LONG(&enum_case_Batak_value, G_UNICODE_SCRIPT_BATAK);
	zend_enum_add_case_cstr(class_entry, "Batak", &enum_case_Batak_value);
#endif

#if GLIB_CHECK_VERSION(2, 28, 0)
	zval enum_case_Brahmi_value;
	ZVAL_LONG(&enum_case_Brahmi_value, G_UNICODE_SCRIPT_BRAHMI);
	zend_enum_add_case_cstr(class_entry, "Brahmi", &enum_case_Brahmi_value);
#endif

#if GLIB_CHECK_VERSION(2, 28, 0)
	zval enum_case_Mandaic_value;
	ZVAL_LONG(&enum_case_Mandaic_value, G_UNICODE_SCRIPT_MANDAIC);
	zend_enum_add_case_cstr(class_entry, "Mandaic", &enum_case_Mandaic_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_Chakma_value;
	ZVAL_LONG(&enum_case_Chakma_value, G_UNICODE_SCRIPT_CHAKMA);
	zend_enum_add_case_cstr(class_entry, "Chakma", &enum_case_Chakma_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_MeroiticCursive_value;
	ZVAL_LONG(&enum_case_MeroiticCursive_value, G_UNICODE_SCRIPT_MEROITIC_CURSIVE);
	zend_enum_add_case_cstr(class_entry, "MeroiticCursive", &enum_case_MeroiticCursive_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_MeroiticHieroglyphs_value;
	ZVAL_LONG(&enum_case_MeroiticHieroglyphs_value, G_UNICODE_SCRIPT_MEROITIC_HIEROGLYPHS);
	zend_enum_add_case_cstr(class_entry, "MeroiticHieroglyphs", &enum_case_MeroiticHieroglyphs_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_Miao_value;
	ZVAL_LONG(&enum_case_Miao_value, G_UNICODE_SCRIPT_MIAO);
	zend_enum_add_case_cstr(class_entry, "Miao", &enum_case_Miao_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_Sharada_value;
	ZVAL_LONG(&enum_case_Sharada_value, G_UNICODE_SCRIPT_SHARADA);
	zend_enum_add_case_cstr(class_entry, "Sharada", &enum_case_Sharada_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_SoraSompeng_value;
	ZVAL_LONG(&enum_case_SoraSompeng_value, G_UNICODE_SCRIPT_SORA_SOMPENG);
	zend_enum_add_case_cstr(class_entry, "SoraSompeng", &enum_case_SoraSompeng_value);
#endif

#if GLIB_CHECK_VERSION(2, 32, 0)
	zval enum_case_Takri_value;
	ZVAL_LONG(&enum_case_Takri_value, G_UNICODE_SCRIPT_TAKRI);
	zend_enum_add_case_cstr(class_entry, "Takri", &enum_case_Takri_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_BassaVah_value;
	ZVAL_LONG(&enum_case_BassaVah_value, G_UNICODE_SCRIPT_BASSA_VAH);
	zend_enum_add_case_cstr(class_entry, "BassaVah", &enum_case_BassaVah_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_CaucasianAlbanian_value;
	ZVAL_LONG(&enum_case_CaucasianAlbanian_value, G_UNICODE_SCRIPT_CAUCASIAN_ALBANIAN);
	zend_enum_add_case_cstr(class_entry, "CaucasianAlbanian", &enum_case_CaucasianAlbanian_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Duployan_value;
	ZVAL_LONG(&enum_case_Duployan_value, G_UNICODE_SCRIPT_DUPLOYAN);
	zend_enum_add_case_cstr(class_entry, "Duployan", &enum_case_Duployan_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Elbasan_value;
	ZVAL_LONG(&enum_case_Elbasan_value, G_UNICODE_SCRIPT_ELBASAN);
	zend_enum_add_case_cstr(class_entry, "Elbasan", &enum_case_Elbasan_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Grantha_value;
	ZVAL_LONG(&enum_case_Grantha_value, G_UNICODE_SCRIPT_GRANTHA);
	zend_enum_add_case_cstr(class_entry, "Grantha", &enum_case_Grantha_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Khojki_value;
	ZVAL_LONG(&enum_case_Khojki_value, G_UNICODE_SCRIPT_KHOJKI);
	zend_enum_add_case_cstr(class_entry, "Khojki", &enum_case_Khojki_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Khudawadi_value;
	ZVAL_LONG(&enum_case_Khudawadi_value, G_UNICODE_SCRIPT_KHUDAWADI);
	zend_enum_add_case_cstr(class_entry, "Khudawadi", &enum_case_Khudawadi_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_LinearA_value;
	ZVAL_LONG(&enum_case_LinearA_value, G_UNICODE_SCRIPT_LINEAR_A);
	zend_enum_add_case_cstr(class_entry, "LinearA", &enum_case_LinearA_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Mahajani_value;
	ZVAL_LONG(&enum_case_Mahajani_value, G_UNICODE_SCRIPT_MAHAJANI);
	zend_enum_add_case_cstr(class_entry, "Mahajani", &enum_case_Mahajani_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Manichaean_value;
	ZVAL_LONG(&enum_case_Manichaean_value, G_UNICODE_SCRIPT_MANICHAEAN);
	zend_enum_add_case_cstr(class_entry, "Manichaean", &enum_case_Manichaean_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_MendeKikakui_value;
	ZVAL_LONG(&enum_case_MendeKikakui_value, G_UNICODE_SCRIPT_MENDE_KIKAKUI);
	zend_enum_add_case_cstr(class_entry, "MendeKikakui", &enum_case_MendeKikakui_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Modi_value;
	ZVAL_LONG(&enum_case_Modi_value, G_UNICODE_SCRIPT_MODI);
	zend_enum_add_case_cstr(class_entry, "Modi", &enum_case_Modi_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Mro_value;
	ZVAL_LONG(&enum_case_Mro_value, G_UNICODE_SCRIPT_MRO);
	zend_enum_add_case_cstr(class_entry, "Mro", &enum_case_Mro_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Nabataean_value;
	ZVAL_LONG(&enum_case_Nabataean_value, G_UNICODE_SCRIPT_NABATAEAN);
	zend_enum_add_case_cstr(class_entry, "Nabataean", &enum_case_Nabataean_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_OldNorthArabian_value;
	ZVAL_LONG(&enum_case_OldNorthArabian_value, G_UNICODE_SCRIPT_OLD_NORTH_ARABIAN);
	zend_enum_add_case_cstr(class_entry, "OldNorthArabian", &enum_case_OldNorthArabian_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_OldPermic_value;
	ZVAL_LONG(&enum_case_OldPermic_value, G_UNICODE_SCRIPT_OLD_PERMIC);
	zend_enum_add_case_cstr(class_entry, "OldPermic", &enum_case_OldPermic_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_PahawhHmong_value;
	ZVAL_LONG(&enum_case_PahawhHmong_value, G_UNICODE_SCRIPT_PAHAWH_HMONG);
	zend_enum_add_case_cstr(class_entry, "PahawhHmong", &enum_case_PahawhHmong_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Palmyrene_value;
	ZVAL_LONG(&enum_case_Palmyrene_value, G_UNICODE_SCRIPT_PALMYRENE);
	zend_enum_add_case_cstr(class_entry, "Palmyrene", &enum_case_Palmyrene_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_PauCinHau_value;
	ZVAL_LONG(&enum_case_PauCinHau_value, G_UNICODE_SCRIPT_PAU_CIN_HAU);
	zend_enum_add_case_cstr(class_entry, "PauCinHau", &enum_case_PauCinHau_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_PsalterPahlavi_value;
	ZVAL_LONG(&enum_case_PsalterPahlavi_value, G_UNICODE_SCRIPT_PSALTER_PAHLAVI);
	zend_enum_add_case_cstr(class_entry, "PsalterPahlavi", &enum_case_PsalterPahlavi_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Siddham_value;
	ZVAL_LONG(&enum_case_Siddham_value, G_UNICODE_SCRIPT_SIDDHAM);
	zend_enum_add_case_cstr(class_entry, "Siddham", &enum_case_Siddham_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_Tirhuta_value;
	ZVAL_LONG(&enum_case_Tirhuta_value, G_UNICODE_SCRIPT_TIRHUTA);
	zend_enum_add_case_cstr(class_entry, "Tirhuta", &enum_case_Tirhuta_value);
#endif

#if GLIB_CHECK_VERSION(2, 42, 0)
	zval enum_case_WarangCiti_value;
	ZVAL_LONG(&enum_case_WarangCiti_value, G_UNICODE_SCRIPT_WARANG_CITI);
	zend_enum_add_case_cstr(class_entry, "WarangCiti", &enum_case_WarangCiti_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_Ahom_value;
	ZVAL_LONG(&enum_case_Ahom_value, G_UNICODE_SCRIPT_AHOM);
	zend_enum_add_case_cstr(class_entry, "Ahom", &enum_case_Ahom_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_AnatolianHieroglyphs_value;
	ZVAL_LONG(&enum_case_AnatolianHieroglyphs_value, G_UNICODE_SCRIPT_ANATOLIAN_HIEROGLYPHS);
	zend_enum_add_case_cstr(class_entry, "AnatolianHieroglyphs", &enum_case_AnatolianHieroglyphs_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_Hatran_value;
	ZVAL_LONG(&enum_case_Hatran_value, G_UNICODE_SCRIPT_HATRAN);
	zend_enum_add_case_cstr(class_entry, "Hatran", &enum_case_Hatran_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_Multani_value;
	ZVAL_LONG(&enum_case_Multani_value, G_UNICODE_SCRIPT_MULTANI);
	zend_enum_add_case_cstr(class_entry, "Multani", &enum_case_Multani_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_OldHungarian_value;
	ZVAL_LONG(&enum_case_OldHungarian_value, G_UNICODE_SCRIPT_OLD_HUNGARIAN);
	zend_enum_add_case_cstr(class_entry, "OldHungarian", &enum_case_OldHungarian_value);
#endif

#if GLIB_CHECK_VERSION(2, 48, 0)
	zval enum_case_Signwriting_value;
	ZVAL_LONG(&enum_case_Signwriting_value, G_UNICODE_SCRIPT_SIGNWRITING);
	zend_enum_add_case_cstr(class_entry, "Signwriting", &enum_case_Signwriting_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Adlam_value;
	ZVAL_LONG(&enum_case_Adlam_value, G_UNICODE_SCRIPT_ADLAM);
	zend_enum_add_case_cstr(class_entry, "Adlam", &enum_case_Adlam_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Bhaiksuki_value;
	ZVAL_LONG(&enum_case_Bhaiksuki_value, G_UNICODE_SCRIPT_BHAIKSUKI);
	zend_enum_add_case_cstr(class_entry, "Bhaiksuki", &enum_case_Bhaiksuki_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Marchen_value;
	ZVAL_LONG(&enum_case_Marchen_value, G_UNICODE_SCRIPT_MARCHEN);
	zend_enum_add_case_cstr(class_entry, "Marchen", &enum_case_Marchen_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Newa_value;
	ZVAL_LONG(&enum_case_Newa_value, G_UNICODE_SCRIPT_NEWA);
	zend_enum_add_case_cstr(class_entry, "Newa", &enum_case_Newa_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Osage_value;
	ZVAL_LONG(&enum_case_Osage_value, G_UNICODE_SCRIPT_OSAGE);
	zend_enum_add_case_cstr(class_entry, "Osage", &enum_case_Osage_value);
#endif

#if GLIB_CHECK_VERSION(2, 50, 0)
	zval enum_case_Tangut_value;
	ZVAL_LONG(&enum_case_Tangut_value, G_UNICODE_SCRIPT_TANGUT);
	zend_enum_add_case_cstr(class_entry, "Tangut", &enum_case_Tangut_value);
#endif

#if GLIB_CHECK_VERSION(2, 54, 0)
	zval enum_case_MasaramGondi_value;
	ZVAL_LONG(&enum_case_MasaramGondi_value, G_UNICODE_SCRIPT_MASARAM_GONDI);
	zend_enum_add_case_cstr(class_entry, "MasaramGondi", &enum_case_MasaramGondi_value);
#endif

#if GLIB_CHECK_VERSION(2, 54, 0)
	zval enum_case_Nushu_value;
	ZVAL_LONG(&enum_case_Nushu_value, G_UNICODE_SCRIPT_NUSHU);
	zend_enum_add_case_cstr(class_entry, "Nushu", &enum_case_Nushu_value);
#endif

#if GLIB_CHECK_VERSION(2, 54, 0)
	zval enum_case_Soyombo_value;
	ZVAL_LONG(&enum_case_Soyombo_value, G_UNICODE_SCRIPT_SOYOMBO);
	zend_enum_add_case_cstr(class_entry, "Soyombo", &enum_case_Soyombo_value);
#endif

#if GLIB_CHECK_VERSION(2, 54, 0)
	zval enum_case_ZanabazarSquare_value;
	ZVAL_LONG(&enum_case_ZanabazarSquare_value, G_UNICODE_SCRIPT_ZANABAZAR_SQUARE);
	zend_enum_add_case_cstr(class_entry, "ZanabazarSquare", &enum_case_ZanabazarSquare_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_Dogra_value;
	ZVAL_LONG(&enum_case_Dogra_value, G_UNICODE_SCRIPT_DOGRA);
	zend_enum_add_case_cstr(class_entry, "Dogra", &enum_case_Dogra_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_GunjalaGondi_value;
	ZVAL_LONG(&enum_case_GunjalaGondi_value, G_UNICODE_SCRIPT_GUNJALA_GONDI);
	zend_enum_add_case_cstr(class_entry, "GunjalaGondi", &enum_case_GunjalaGondi_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_HanifiRohingya_value;
	ZVAL_LONG(&enum_case_HanifiRohingya_value, G_UNICODE_SCRIPT_HANIFI_ROHINGYA);
	zend_enum_add_case_cstr(class_entry, "HanifiRohingya", &enum_case_HanifiRohingya_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_Makasar_value;
	ZVAL_LONG(&enum_case_Makasar_value, G_UNICODE_SCRIPT_MAKASAR);
	zend_enum_add_case_cstr(class_entry, "Makasar", &enum_case_Makasar_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_Medefaidrin_value;
	ZVAL_LONG(&enum_case_Medefaidrin_value, G_UNICODE_SCRIPT_MEDEFAIDRIN);
	zend_enum_add_case_cstr(class_entry, "Medefaidrin", &enum_case_Medefaidrin_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_OldSogdian_value;
	ZVAL_LONG(&enum_case_OldSogdian_value, G_UNICODE_SCRIPT_OLD_SOGDIAN);
	zend_enum_add_case_cstr(class_entry, "OldSogdian", &enum_case_OldSogdian_value);
#endif

#if GLIB_CHECK_VERSION(2, 58, 0)
	zval enum_case_Sogdian_value;
	ZVAL_LONG(&enum_case_Sogdian_value, G_UNICODE_SCRIPT_SOGDIAN);
	zend_enum_add_case_cstr(class_entry, "Sogdian", &enum_case_Sogdian_value);
#endif

#if GLIB_CHECK_VERSION(2, 62, 0)
	zval enum_case_Elymaic_value;
	ZVAL_LONG(&enum_case_Elymaic_value, G_UNICODE_SCRIPT_ELYMAIC);
	zend_enum_add_case_cstr(class_entry, "Elymaic", &enum_case_Elymaic_value);
#endif

#if GLIB_CHECK_VERSION(2, 62, 0)
	zval enum_case_Nandinagari_value;
	ZVAL_LONG(&enum_case_Nandinagari_value, G_UNICODE_SCRIPT_NANDINAGARI);
	zend_enum_add_case_cstr(class_entry, "Nandinagari", &enum_case_Nandinagari_value);
#endif

#if GLIB_CHECK_VERSION(2, 62, 0)
	zval enum_case_NyiaKengPuachueHmong_value;
	ZVAL_LONG(&enum_case_NyiaKengPuachueHmong_value, G_UNICODE_SCRIPT_NYIAKENG_PUACHUE_HMONG);
	zend_enum_add_case_cstr(class_entry, "NyiaKengPuachueHmong", &enum_case_NyiaKengPuachueHmong_value);
#endif

#if GLIB_CHECK_VERSION(2, 62, 0)
	zval enum_case_Wancho_value;
	ZVAL_LONG(&enum_case_Wancho_value, G_UNICODE_SCRIPT_WANCHO);
	zend_enum_add_case_cstr(class_entry, "Wancho", &enum_case_Wancho_value);
#endif

#if GLIB_CHECK_VERSION(2, 66, 0)
	zval enum_case_Chorasmian_value;
	ZVAL_LONG(&enum_case_Chorasmian_value, G_UNICODE_SCRIPT_CHORASMIAN);
	zend_enum_add_case_cstr(class_entry, "Chorasmian", &enum_case_Chorasmian_value);
#endif

#if GLIB_CHECK_VERSION(2, 66, 0)
	zval enum_case_DivesAkuru_value;
	ZVAL_LONG(&enum_case_DivesAkuru_value, G_UNICODE_SCRIPT_DIVES_AKURU);
	zend_enum_add_case_cstr(class_entry, "DivesAkuru", &enum_case_DivesAkuru_value);
#endif

#if GLIB_CHECK_VERSION(2, 66, 0)
	zval enum_case_KhitanSmallScript_value;
	ZVAL_LONG(&enum_case_KhitanSmallScript_value, G_UNICODE_SCRIPT_KHITAN_SMALL_SCRIPT);
	zend_enum_add_case_cstr(class_entry, "KhitanSmallScript", &enum_case_KhitanSmallScript_value);
#endif

#if GLIB_CHECK_VERSION(2, 66, 0)
	zval enum_case_Yezidi_value;
	ZVAL_LONG(&enum_case_Yezidi_value, G_UNICODE_SCRIPT_YEZIDI);
	zend_enum_add_case_cstr(class_entry, "Yezidi", &enum_case_Yezidi_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_CyproMinoan_value;
	ZVAL_LONG(&enum_case_CyproMinoan_value, G_UNICODE_SCRIPT_CYPRO_MINOAN);
	zend_enum_add_case_cstr(class_entry, "CyproMinoan", &enum_case_CyproMinoan_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_OldUyghur_value;
	ZVAL_LONG(&enum_case_OldUyghur_value, G_UNICODE_SCRIPT_OLD_UYGHUR);
	zend_enum_add_case_cstr(class_entry, "OldUyghur", &enum_case_OldUyghur_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_Tangsa_value;
	ZVAL_LONG(&enum_case_Tangsa_value, G_UNICODE_SCRIPT_TANGSA);
	zend_enum_add_case_cstr(class_entry, "Tangsa", &enum_case_Tangsa_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_Toto_value;
	ZVAL_LONG(&enum_case_Toto_value, G_UNICODE_SCRIPT_TOTO);
	zend_enum_add_case_cstr(class_entry, "Toto", &enum_case_Toto_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_Vithkuqi_value;
	ZVAL_LONG(&enum_case_Vithkuqi_value, G_UNICODE_SCRIPT_VITHKUQI);
	zend_enum_add_case_cstr(class_entry, "Vithkuqi", &enum_case_Vithkuqi_value);
#endif

#if GLIB_CHECK_VERSION(2, 72, 0)
	zval enum_case_Math_value;
	ZVAL_LONG(&enum_case_Math_value, G_UNICODE_SCRIPT_MATH);
	zend_enum_add_case_cstr(class_entry, "Math", &enum_case_Math_value);
#endif

#if GLIB_CHECK_VERSION(2, 74, 0)
	zval enum_case_Kawi_value;
	ZVAL_LONG(&enum_case_Kawi_value, G_UNICODE_SCRIPT_KAWI);
	zend_enum_add_case_cstr(class_entry, "Kawi", &enum_case_Kawi_value);
#endif

#if GLIB_CHECK_VERSION(2, 74, 0)
	zval enum_case_NagMundari_value;
	ZVAL_LONG(&enum_case_NagMundari_value, G_UNICODE_SCRIPT_NAG_MUNDARI);
	zend_enum_add_case_cstr(class_entry, "NagMundari", &enum_case_NagMundari_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_Todhri_value;
	ZVAL_LONG(&enum_case_Todhri_value, G_UNICODE_SCRIPT_TODHRI);
	zend_enum_add_case_cstr(class_entry, "Todhri", &enum_case_Todhri_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_Garay_value;
	ZVAL_LONG(&enum_case_Garay_value, G_UNICODE_SCRIPT_GARAY);
	zend_enum_add_case_cstr(class_entry, "Garay", &enum_case_Garay_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_TuluTigalari_value;
	ZVAL_LONG(&enum_case_TuluTigalari_value, G_UNICODE_SCRIPT_TULU_TIGALARI);
	zend_enum_add_case_cstr(class_entry, "TuluTigalari", &enum_case_TuluTigalari_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_Sunuwar_value;
	ZVAL_LONG(&enum_case_Sunuwar_value, G_UNICODE_SCRIPT_SUNUWAR);
	zend_enum_add_case_cstr(class_entry, "Sunuwar", &enum_case_Sunuwar_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_GurungKhema_value;
	ZVAL_LONG(&enum_case_GurungKhema_value, G_UNICODE_SCRIPT_GURUNG_KHEMA);
	zend_enum_add_case_cstr(class_entry, "GurungKhema", &enum_case_GurungKhema_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_KiratRai_value;
	ZVAL_LONG(&enum_case_KiratRai_value, G_UNICODE_SCRIPT_KIRAT_RAI);
	zend_enum_add_case_cstr(class_entry, "KiratRai", &enum_case_KiratRai_value);
#endif

#if GLIB_CHECK_VERSION(2, 84, 0)
	zval enum_case_OlOnal_value;
	ZVAL_LONG(&enum_case_OlOnal_value, G_UNICODE_SCRIPT_OL_ONAL);
	zend_enum_add_case_cstr(class_entry, "OlOnal", &enum_case_OlOnal_value);
#endif

#if GLIB_CHECK_VERSION(2, 88, 0)
	zval enum_case_Sidetic_value;
	ZVAL_LONG(&enum_case_Sidetic_value, G_UNICODE_SCRIPT_SIDETIC);
	zend_enum_add_case_cstr(class_entry, "Sidetic", &enum_case_Sidetic_value);
#endif

#if GLIB_CHECK_VERSION(2, 88, 0)
	zval enum_case_TolongSiki_value;
	ZVAL_LONG(&enum_case_TolongSiki_value, G_UNICODE_SCRIPT_TOLONG_SIKI);
	zend_enum_add_case_cstr(class_entry, "TolongSiki", &enum_case_TolongSiki_value);
#endif

#if GLIB_CHECK_VERSION(2, 88, 0)
	zval enum_case_TaiYo_value;
	ZVAL_LONG(&enum_case_TaiYo_value, G_UNICODE_SCRIPT_TAI_YO);
	zend_enum_add_case_cstr(class_entry, "TaiYo", &enum_case_TaiYo_value);
#endif

#if GLIB_CHECK_VERSION(2, 88, 0)
	zval enum_case_BeriaErfe_value;
	ZVAL_LONG(&enum_case_BeriaErfe_value, G_UNICODE_SCRIPT_BERIA_ERFE);
	zend_enum_add_case_cstr(class_entry, "BeriaErfe", &enum_case_BeriaErfe_value);
#endif

	return class_entry;
}
