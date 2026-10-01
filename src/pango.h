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

#ifndef PHP_PANGO_INTERNALS_H
#define PHP_PANGO_INTERNALS_H

#include <php.h>
#include "../php_pango.h"

PHP_PANGO_API extern zend_class_entry *php_pango_get_markup_parse_result_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_paragraph_boundary_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_quantized_line_geometry_ce();
PHP_PANGO_API extern zend_class_entry *php_pango_get_shape_flags_ce();

PHP_MINIT_FUNCTION(pango_analysis);
PHP_MINIT_FUNCTION(pango_color);
PHP_MINIT_FUNCTION(pango_context);
PHP_MINIT_FUNCTION(pango_coverage);
PHP_MINIT_FUNCTION(pango_exception);
PHP_MINIT_FUNCTION(pango_font_description);
PHP_MINIT_FUNCTION(pango_font_face);
PHP_MINIT_FUNCTION(pango_font_family);
PHP_MINIT_FUNCTION(pango_font_map);
PHP_MINIT_FUNCTION(pango_font_metrics);
PHP_MINIT_FUNCTION(pango_font_set_simple);
PHP_MINIT_FUNCTION(pango_font_set);
PHP_MINIT_FUNCTION(pango_font);
PHP_MINIT_FUNCTION(pango_glyph_geometry);
PHP_MINIT_FUNCTION(pango_glyph_info);
PHP_MINIT_FUNCTION(pango_glyph_item);
PHP_MINIT_FUNCTION(pango_glyph_string);
PHP_MINIT_FUNCTION(pango_glyph_vis_attr);
PHP_MINIT_FUNCTION(pango_item);
PHP_MINIT_FUNCTION(pango_language);
PHP_MINIT_FUNCTION(pango_layout_iter);
PHP_MINIT_FUNCTION(pango_layout);
PHP_MINIT_FUNCTION(pango_layout_line);
PHP_MINIT_FUNCTION(pango_logattr_list);
PHP_MINIT_FUNCTION(pango_logattr);
PHP_MINIT_FUNCTION(pango_matrix);
PHP_MINIT_FUNCTION(pango_rectangle);
PHP_MINIT_FUNCTION(pango_script_iter);
PHP_MINIT_FUNCTION(pango_script_iter_range);
PHP_MINIT_FUNCTION(pango_tabstop);
PHP_MINIT_FUNCTION(pango_tabstops);
PHP_MINIT_FUNCTION(pango_attr_absolute_line_height);
PHP_MINIT_FUNCTION(pango_attr_absolute_size);
PHP_MINIT_FUNCTION(pango_attr_allow_breaks);
PHP_MINIT_FUNCTION(pango_attr_background_alpha);
PHP_MINIT_FUNCTION(pango_attr_background);
PHP_MINIT_FUNCTION(pango_attr_baseline_shift);
PHP_MINIT_FUNCTION(pango_attr_fallback);
PHP_MINIT_FUNCTION(pango_attr_family);
PHP_MINIT_FUNCTION(pango_attr_font_description);
PHP_MINIT_FUNCTION(pango_attr_font_features);
PHP_MINIT_FUNCTION(pango_attr_font_scale);
PHP_MINIT_FUNCTION(pango_attr_foreground_alpha);
PHP_MINIT_FUNCTION(pango_attr_foreground);
PHP_MINIT_FUNCTION(pango_attr_gravity_hint);
PHP_MINIT_FUNCTION(pango_attr_gravity);
PHP_MINIT_FUNCTION(pango_attr_insert_hyphens);
PHP_MINIT_FUNCTION(pango_attr_iter);
PHP_MINIT_FUNCTION(pango_attr_language);
PHP_MINIT_FUNCTION(pango_attr_letter_spacing);
PHP_MINIT_FUNCTION(pango_attr_line_height);
PHP_MINIT_FUNCTION(pango_attr_list);
PHP_MINIT_FUNCTION(pango_attr_overline_color);
PHP_MINIT_FUNCTION(pango_attr_overline);
PHP_MINIT_FUNCTION(pango_attr_rise);
PHP_MINIT_FUNCTION(pango_attr_scale);
PHP_MINIT_FUNCTION(pango_attr_sentence);
PHP_MINIT_FUNCTION(pango_attr_show);
PHP_MINIT_FUNCTION(pango_attr_size);
PHP_MINIT_FUNCTION(pango_attr_stretch);
PHP_MINIT_FUNCTION(pango_attr_strikethrough_color);
PHP_MINIT_FUNCTION(pango_attr_strikethrough);
PHP_MINIT_FUNCTION(pango_attr_style);
PHP_MINIT_FUNCTION(pango_attr_text_transform);
PHP_MINIT_FUNCTION(pango_attr_underline_color);
PHP_MINIT_FUNCTION(pango_attr_underline);
PHP_MINIT_FUNCTION(pango_attr_variant);
PHP_MINIT_FUNCTION(pango_attr_weight);
PHP_MINIT_FUNCTION(pango_attr_width);
PHP_MINIT_FUNCTION(pango_attr_word);
PHP_MINIT_FUNCTION(pango_attribute);
PHP_MINIT_FUNCTION(pango_cairo_context);
PHP_MINIT_FUNCTION(pango_cairo_font_map);
PHP_MINIT_FUNCTION(pango_cairo_layout);
PHP_MINIT_FUNCTION(pango_cairo_layout_line);
PHP_MINIT_FUNCTION(pango_fc_font_map);
PHP_MINIT_FUNCTION(pango_ft2_font_map);

#endif /* PHP_PANGO_INTERNALS_H */
