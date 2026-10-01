/*
  +----------------------------------------------------------------------+
  | For PHP Version 8.2+                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2026 Marcel Bolten                                     |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  +----------------------------------------------------------------------+
  | Authors: Marcel Bolten <github@marcelbolten.de>                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "../../php_pango.h"
#include "attr_type_to_ce_table.h"
#include "attribute.h"

const attr_ce_getter_t attr_ce_table[] = {
    // PANGO_ATTR_INVALID
    [PANGO_ATTR_LANGUAGE]             = php_pango_get_attr_language_ce,
    [PANGO_ATTR_FAMILY]               = php_pango_get_attr_family_ce,
    [PANGO_ATTR_STYLE]                = php_pango_get_attr_style_ce,
    [PANGO_ATTR_WEIGHT]               = php_pango_get_attr_weight_ce,
    [PANGO_ATTR_VARIANT]              = php_pango_get_attr_variant_ce,
    [PANGO_ATTR_STRETCH]              = php_pango_get_attr_stretch_ce,
    [PANGO_ATTR_SIZE]                 = php_pango_get_attr_size_ce,
    [PANGO_ATTR_FONT_DESC]            = php_pango_get_attr_font_description_ce,
    [PANGO_ATTR_FOREGROUND]           = php_pango_get_attr_foreground_ce,
    [PANGO_ATTR_BACKGROUND]           = php_pango_get_attr_background_ce,
    [PANGO_ATTR_UNDERLINE]            = php_pango_get_attr_underline_ce,
    [PANGO_ATTR_STRIKETHROUGH]        = php_pango_get_attr_strikethrough_ce,
    [PANGO_ATTR_RISE]                 = php_pango_get_attr_rise_ce,
    // PANGO_ATTR_SHAPE is not implemented yet
    [PANGO_ATTR_SCALE]                = php_pango_get_attr_scale_ce,
    [PANGO_ATTR_FALLBACK]             = php_pango_get_attr_fallback_ce,
    [PANGO_ATTR_LETTER_SPACING]       = php_pango_get_attr_letter_spacing_ce,
    [PANGO_ATTR_UNDERLINE_COLOR]      = php_pango_get_attr_underline_color_ce,
    [PANGO_ATTR_STRIKETHROUGH_COLOR]  = php_pango_get_attr_strikethrough_color_ce,
    [PANGO_ATTR_ABSOLUTE_SIZE]        = php_pango_get_attr_absolute_size_ce,
    [PANGO_ATTR_GRAVITY]              = php_pango_get_attr_gravity_ce,
    [PANGO_ATTR_GRAVITY_HINT]         = php_pango_get_attr_gravity_hint_ce,
    [PANGO_ATTR_FONT_FEATURES]        = php_pango_get_attr_font_features_ce,
    [PANGO_ATTR_FOREGROUND_ALPHA]     = php_pango_get_attr_foreground_alpha_ce,
    [PANGO_ATTR_BACKGROUND_ALPHA]     = php_pango_get_attr_background_alpha_ce,
    [PANGO_ATTR_ALLOW_BREAKS]         = php_pango_get_attr_allow_breaks_ce,
    [PANGO_ATTR_SHOW]                 = php_pango_get_attr_show_ce,
    [PANGO_ATTR_INSERT_HYPHENS]       = php_pango_get_attr_insert_hyphens_ce,
    [PANGO_ATTR_OVERLINE]             = php_pango_get_attr_overline_ce,
    [PANGO_ATTR_OVERLINE_COLOR]       = php_pango_get_attr_overline_color_ce,

    #if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    [PANGO_ATTR_TEXT_TRANSFORM]       = php_pango_get_attr_text_transform_ce,
    [PANGO_ATTR_LINE_HEIGHT]          = php_pango_get_attr_line_height_ce,
    [PANGO_ATTR_ABSOLUTE_LINE_HEIGHT] = php_pango_get_attr_absolute_line_height_ce,
    [PANGO_ATTR_WORD]                 = php_pango_get_attr_word_ce,
    [PANGO_ATTR_SENTENCE]             = php_pango_get_attr_sentence_ce,
    [PANGO_ATTR_BASELINE_SHIFT]       = php_pango_get_attr_baseline_shift_ce,
    [PANGO_ATTR_FONT_SCALE]           = php_pango_get_attr_font_scale_ce,
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    [PANGO_ATTR_WIDTH]                = php_pango_get_attr_width_ce,
#endif
};

const size_t attr_ce_table_size = sizeof(attr_ce_table) / sizeof(attr_ce_table[0]);

zend_class_entry *php_pango_attr_ce_lookup(PangoAttrType type)
{
    if ((unsigned)type >= attr_ce_table_size) {
        return NULL;
    }
    attr_ce_getter_t getter = attr_ce_table[type];
    return getter ? getter() : NULL;
}
