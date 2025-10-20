/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 51ed52b32bd5aaf9af17231142d965c85267fc34 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pango_Context___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, fontmap, Pango\\FontMap, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getBaseDir, 0, 0, Pango\\Direction, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getBaseGravity, 0, 0, Pango\\Gravity, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getFontDescription, 0, 0, Pango\\FontDescription, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getFontMap, 0, 0, Pango\\FontMap, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_Pango_Context_getGravity arginfo_class_Pango_Context_getBaseGravity

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getGravityHint, 0, 0, Pango\\GravityHint, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pango_Context_getMatrix, 0, 0, Pango\\Matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_getRoundGlyphPositions, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_listFamilies, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setBaseDir, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, direction, Pango\\Direction, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setBaseGravity, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gravity, Pango\\Gravity, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setFontDescription, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, desc, Pango\\FontDescription, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setGravityHint, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, hint, Pango\\GravityHint, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setMatrix, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, Pango\\Matrix, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pango_Context_setRoundGlyphPositions, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, round, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Pango_Context, __construct);
ZEND_METHOD(Pango_Context, getBaseDir);
ZEND_METHOD(Pango_Context, getBaseGravity);
ZEND_METHOD(Pango_Context, getFontDescription);
ZEND_METHOD(Pango_Context, getFontMap);
ZEND_METHOD(Pango_Context, getGravity);
ZEND_METHOD(Pango_Context, getGravityHint);
ZEND_METHOD(Pango_Context, getMatrix);
ZEND_METHOD(Pango_Context, getRoundGlyphPositions);
ZEND_METHOD(Pango_Context, listFamilies);
ZEND_METHOD(Pango_Context, setBaseDir);
ZEND_METHOD(Pango_Context, setBaseGravity);
ZEND_METHOD(Pango_Context, setFontDescription);
ZEND_METHOD(Pango_Context, setGravityHint);
ZEND_METHOD(Pango_Context, setMatrix);
ZEND_METHOD(Pango_Context, setRoundGlyphPositions);

static const zend_function_entry class_Pango_Context_methods[] = {
	ZEND_ME(Pango_Context, __construct, arginfo_class_Pango_Context___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getBaseDir, arginfo_class_Pango_Context_getBaseDir, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getBaseGravity, arginfo_class_Pango_Context_getBaseGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getFontDescription, arginfo_class_Pango_Context_getFontDescription, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getFontMap, arginfo_class_Pango_Context_getFontMap, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getGravity, arginfo_class_Pango_Context_getGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getGravityHint, arginfo_class_Pango_Context_getGravityHint, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getMatrix, arginfo_class_Pango_Context_getMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, getRoundGlyphPositions, arginfo_class_Pango_Context_getRoundGlyphPositions, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, listFamilies, arginfo_class_Pango_Context_listFamilies, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setBaseDir, arginfo_class_Pango_Context_setBaseDir, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setBaseGravity, arginfo_class_Pango_Context_setBaseGravity, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setFontDescription, arginfo_class_Pango_Context_setFontDescription, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setGravityHint, arginfo_class_Pango_Context_setGravityHint, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setMatrix, arginfo_class_Pango_Context_setMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Pango_Context, setRoundGlyphPositions, arginfo_class_Pango_Context_setRoundGlyphPositions, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pango_Context(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pango", "Context", class_Pango_Context_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Pango_Gravity(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Gravity", IS_LONG, NULL);

	zval enum_case_South_value;
	ZVAL_LONG(&enum_case_South_value, PANGO_GRAVITY_SOUTH);
	zend_enum_add_case_cstr(class_entry, "South", &enum_case_South_value);

	zval enum_case_East_value;
	ZVAL_LONG(&enum_case_East_value, PANGO_GRAVITY_EAST);
	zend_enum_add_case_cstr(class_entry, "East", &enum_case_East_value);

	zval enum_case_North_value;
	ZVAL_LONG(&enum_case_North_value, PANGO_GRAVITY_NORTH);
	zend_enum_add_case_cstr(class_entry, "North", &enum_case_North_value);

	zval enum_case_West_value;
	ZVAL_LONG(&enum_case_West_value, PANGO_GRAVITY_WEST);
	zend_enum_add_case_cstr(class_entry, "West", &enum_case_West_value);

	zval enum_case_Auto_value;
	ZVAL_LONG(&enum_case_Auto_value, PANGO_GRAVITY_AUTO);
	zend_enum_add_case_cstr(class_entry, "Auto", &enum_case_Auto_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_GravityHint(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\GravityHint", IS_LONG, NULL);

	zval enum_case_Natural_value;
	ZVAL_LONG(&enum_case_Natural_value, PANGO_GRAVITY_HINT_NATURAL);
	zend_enum_add_case_cstr(class_entry, "Natural", &enum_case_Natural_value);

	zval enum_case_Strong_value;
	ZVAL_LONG(&enum_case_Strong_value, PANGO_GRAVITY_HINT_STRONG);
	zend_enum_add_case_cstr(class_entry, "Strong", &enum_case_Strong_value);

	zval enum_case_Line_value;
	ZVAL_LONG(&enum_case_Line_value, PANGO_GRAVITY_HINT_LINE);
	zend_enum_add_case_cstr(class_entry, "Line", &enum_case_Line_value);

	return class_entry;
}

static zend_class_entry *register_class_Pango_Direction(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Pango\\Direction", IS_LONG, NULL);

	zval enum_case_LTR_value;
	ZVAL_LONG(&enum_case_LTR_value, PANGO_DIRECTION_LTR);
	zend_enum_add_case_cstr(class_entry, "LTR", &enum_case_LTR_value);

	zval enum_case_RTL_value;
	ZVAL_LONG(&enum_case_RTL_value, PANGO_DIRECTION_RTL);
	zend_enum_add_case_cstr(class_entry, "RTL", &enum_case_RTL_value);

	zval enum_case_WeakLTR_value;
	ZVAL_LONG(&enum_case_WeakLTR_value, PANGO_DIRECTION_WEAK_LTR);
	zend_enum_add_case_cstr(class_entry, "WeakLTR", &enum_case_WeakLTR_value);

	zval enum_case_WeakRTL_value;
	ZVAL_LONG(&enum_case_WeakRTL_value, PANGO_DIRECTION_WEAK_RTL);
	zend_enum_add_case_cstr(class_entry, "WeakRTL", &enum_case_WeakRTL_value);

	zval enum_case_Neutral_value;
	ZVAL_LONG(&enum_case_Neutral_value, PANGO_DIRECTION_NEUTRAL);
	zend_enum_add_case_cstr(class_entry, "Neutral", &enum_case_Neutral_value);

	return class_entry;
}
