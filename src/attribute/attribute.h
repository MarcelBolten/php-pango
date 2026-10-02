/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Michael Maclean <mgdm@php.net>                              |
  |          David Marín <davefx@gmail.com>                              |
  |          Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_PANGO_ATTRIBUTE_H
#define PHP_PANGO_ATTRIBUTE_H

#include <php.h>
#include <pango/pango.h>
#include "../../php_pango.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_absolute_line_height_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_absolute_size_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_allow_breaks_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_background_alpha_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_background_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_baseline_shift_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_fallback_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_family_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_font_description_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_font_features_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_font_scale_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_foreground_alpha_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_foreground_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_gravity_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_gravity_hint_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_insert_hyphens_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_iter_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_language_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_letter_spacing_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_line_height_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_list_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_overline_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_overline_color_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_rise_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_scale_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_sentence_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_show_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_size_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_stretch_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_strikethrough_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_strikethrough_color_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_style_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_text_transform_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_underline_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_underline_color_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_variant_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_weight_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_width_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attr_word_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attribute_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_attribute_type_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_baseline_shift_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_font_scale_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_overline_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_text_transform_ce(void);
PHP_PANGO_API extern zend_class_entry *php_pango_get_underline_ce(void);

typedef struct _pango_attr_list_object {
    PangoAttrList *attr_list;
    zend_object std;
} pango_attr_list_object;
extern pango_attr_list_object *pango_attr_list_fetch_object(zend_object *object);
#define Z_PANGO_ATTR_LIST_P(zv) pango_attr_list_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoAttrList *pango_attr_list_object_get_attr_list(zval *zv);

typedef struct _pango_attribute_object {
    PangoAttribute *attribute;
    zend_object std;
} pango_attribute_object;
extern pango_attribute_object *pango_attribute_fetch_object(zend_object *object);
#define Z_PANGO_ATTRIBUTE_P(zv) pango_attribute_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoAttribute *pango_attribute_object_get_attribute(zval *zv);

PHP_PANGO_API extern PangoAttrSize *pango_attr_size_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_rise_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_letter_spacing_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_absolute_line_height_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_foreground_alpha_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_background_alpha_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_show_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrFloat *pango_attr_line_height_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrFloat *pango_attr_scale_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_strikethrough_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_fallback_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_allow_breaks_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_insert_hyphens_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_word_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_sentence_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrString *pango_attr_family_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrFontFeatures *pango_attr_font_features_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_style_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_weight_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_variant_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_stretch_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_gravity_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_gravity_hint_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_overline_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_underline_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_text_transform_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_baseline_shift_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_width_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrColor *pango_attr_foreground_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrColor *pango_attr_background_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrColor *pango_attr_underline_color_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrColor *pango_attr_strikethrough_color_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrColor *pango_attr_overline_color_object_get_attr(zval *zv);
PHP_PANGO_API extern PangoAttrInt *pango_attr_font_scale_object_get_attr(zval *zv);

typedef struct _pango_attr_language_object {
    PangoAttribute *attribute;
    zval language_zv;
    zend_object std;
} pango_attr_language_object;
extern pango_attr_language_object *pango_attr_language_fetch_object(zend_object *object);
#define Z_PANGO_ATTR_LANGUAGE_P(zv) pango_attr_language_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoAttribute *pango_attr_language_object_get_attribute(zval *zv);

typedef struct _pango_attr_font_description_object {
    PangoAttribute *attribute;
    zval font_description_zv;
    zend_object std;
} pango_attr_font_description_object;
extern pango_attr_font_description_object *pango_attr_font_description_fetch_object(zend_object *object);
#define Z_PANGO_ATTR_FONT_DESCRIPTION_P(zv) pango_attr_font_description_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoAttribute *pango_attr_font_description_object_get_attribute(zval *zv);

typedef struct _pango_attr_iter_object {
    PangoAttrIterator *attr_iter;
    PangoAttrList* attr_list;
    zend_object std;
} pango_attr_iter_object;
extern pango_attr_iter_object *pango_attr_iter_fetch_object(zend_object *object);
#define Z_PANGO_ATTR_ITER_P(zv) pango_attr_iter_fetch_object(Z_OBJ_P(zv))
PHP_PANGO_API extern PangoAttrIterator *pango_attr_iter_object_get_attr_iter(zval *zv);
PHP_PANGO_API extern PangoAttrList *pango_attr_iter_object_get_attr_list(zval *zv);

extern void pango_attr_free_obj(zend_object *object);
extern int pango_attr_object_compare(zval *op1, zval *op2);

#endif /* PHP_PANGO_ATTRIBUTE_H */
