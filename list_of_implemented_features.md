# Pango Classes
## Context
- ✅ new
- changed
- ✅ get_base_dir
- ✅ get_base_gravity
- ✅ get_font_description
- ✅ get_font_map
- ✅ get_gravity
- ✅ get_gravity_hint
- ✅ get_language
- ✅ get_matrix
- ✅ get_metrics
- ✅ get_round_glyph_positions
- ✅ get_serial
- ✅ list_families
- ✅ load_font
- ✅ load_fontset
- ✅ set_base_dir
- ✅ set_base_gravity
- ✅ set_font_description
- set_font_map // might need this or need to remove new from constructor and only get the context from the fontmap
- ✅ set_gravity_hint
- ✅ set_language
- ✅ set_matrix
- ✅ set_round_glyph_positions

## Coverage
- ✅ new
- 🟪 from_bytes deprecated: 1.44
- ✅ copy
- ✅ get
- 🟪 max deprecated: 1.44
- 🟪 ref deprecated: 1.52 use g_object_ref
- ✅ set
- 🟪 to_byte deprecated: 1.44
- 🟪 unref deprecated: 1.52 use g_object_unref

## Font
- 🟪 pango_font_descriptions_free deprecated: 1.56
- pango_font_deserialize // not needed for now
- ✅ pango_font_describe
- ✅ pango_font_describe_with_absolute_size
- ✅ pango_font_get_coverage
- ✅ pango_font_get_face
- ✅ pango_font_get_features
- ✅ pango_font_get_font_map
- ✅ pango_font_get_glyph_extents
- pango_font_get_hb_font // not needed for now
- ✅ pango_font_get_languages
- ✅ pango_font_get_metrics
- ✅ pango_font_has_char
- pango_font_serialize // not needed for now

## FontFace (abstract)
- ✅ describe
- ✅ get_face_name
- ✅ get_family
- ✅ is_synthesized
- ✅ list_sizes

## FontFamily (abstract)
### Instance methods
- ✅ get_face
- ✅ get_name
- ✅ is_monospace
- ✅ is_variable
- ✅ list_faces
### Properties
- is-monospace
- is-variable
- item-type
- n-items
- name

## FontMap (abstract)
### Instance methods
- ✅ add_font_file
- changed
- ✅ create_context
- ✅ get_family
- get_serial
- ✅ list_families
- ✅ load_font
- ✅ load_fontset
- ✅ reload_font

## Fontset
### Instance methods
- ✅ foreach
- ✅ get_font
- ✅ get_metrics
### Virtual methods
- get_language

## FontsetSimple (extends Fontset)
- ✅ new
### Instance methods
- ✅ append
- ✅ size

## Layout
- ✅ new
- deserialize
- ✅ context_changed
- ✅ copy
- ✅ get_alignment
- ✅ get_attributes
- ✅ get_auto_dir
- ✅ get_baseline
- get_caret_pos // skip for now
- ✅ get_character_count
- ✅ get_context
- get_cursor_pos // skip for now
- ✅ get_direction
- ✅ get_ellipsize
- ✅ get_extents
- ✅ get_font_description
- ✅ get_height
- ✅ get_indent
- ✅ get_iter
- ✅ get_justify
- ✅ get_justify_last_line
- ✅ get_line
- ✅ get_line_count
- ✅ get_line_readonly
- ✅ get_line_spacing
- ✅ get_lines
- ✅ get_lines_readonly
- ✅ get_log_attrs
- ✅ get_log_attrs_readonly
- ✅ get_pixel_extents
- ✅ get_pixel_size
- ✅ get_serial
- ✅ get_single_paragraph_mode
- ✅ get_size
- ✅ get_spacing
- ✅ get_tabs
- ✅ get_text
- ✅ get_unknown_glyphs_count
- ✅ get_width
- ✅ get_wrap
- index_to_line_x // skip for now
- index_to_pos // skip for now
- ✅ is_ellipsized
- ✅ is_wrapped
- move_cursor_visually // skip for now
- ✅ serialize
- ✅ set_alignment
- ✅ set_attributes
- ✅ set_auto_dir
- ✅ set_ellipsize
- ✅ set_font_description
- ✅ set_height
- ✅ set_indent
- ✅ set_justify
- ✅ set_justify_last_line
- ✅ set_line_spacing
- ✅ set_markup
- ✅ set_markup_with_accel
- ✅ set_single_paragraph_mode
- ✅ set_spacing
- ✅ set_tabs
- ✅ set_text
- ✅ set_width
- ✅ set_wrap
- write_to_file // skip for now
- xy_to_index // skip for now

## Renderer (abstract)
For now there is no plan to implement this as I only want to get positional information
### Instance methods
- activate
- deactivate
- draw_error_underline
- draw_glyph
- draw_glyph_item
- draw_glyphs
- draw_layout
- draw_layout_line
- draw_rectangle
- draw_trapezoid
- get_alpha
- get_color
- get_components
- get_layout
- get_layout_line
- get_matrix
- part_changed
- set_alpha
- set_color
- set_components
- set_matrix
### Virtual methods
- begin
- draw_error_underline
- draw_glyph
- draw_glyph_item
- draw_glyphs
- draw_rectangle
- draw_shape
- draw_trapezoid
- end
- part_changed
- prepare_run

# Structs
- ✅ Analysis
- AttrClass // not exposed
- ✅ AttrColor
- AttrFloat // not directly exposed
- ✅ AttrFontDesc
- ✅ AttrFontFeatures
- ✅ Attribute
- AttrInt // not directly exposed
- ✅ AttrIterator
- ✅ AttrLanguage
- ✅ AttrList
- AttrShape
- ✅ AttrSize
- AttrString // not directly exposed
- ✅ Color
    - ✅ copy
    - ✅ free
    - ✅ parse
    - ✅ parse_with_alpha
    - ✅ to_string
- FontDescription
    - ✅ new
    - ✅ fromString
    - ✅ better_match
    - ✅ copy
    - copy_static // use copy
    - ✅ equal
    - ✅ free
    - ✅ get_color
    - ✅ get_family
    - ✅ get_features
    - ✅ get_gravity
    - ✅ get_set_fields
    - ✅ get_size
    - ✅ get_size_is_absolute
    - ✅ get_stretch
    - ✅ get_style
    - ✅ get_variant
    - ✅ get_variations
    - ✅ get_weight
    - ✅ get_width
    - hash
    - ✅ merge
    - merge_static // use merge
    - ✅ set_absolute_size
    - ✅ set_color
    - ✅ set_family
    - set_family_static // use set_family
    - ✅ set_features
    - set_features_static // use set_features
    - ✅ set_gravity
    - ✅ set_size
    - ✅ set_stretch
    - ✅ set_style
    - ✅ set_variant
    - ✅ set_variations
    - set_variations_static // use set_variations
    - ✅ set_weight
    - ✅ set_width
    - to_filename
    - ✅ to_string
    - ✅ unset_fields

- ✅ FontMetrics
    - ✅ get_approximate_char_width
    - ✅ get_approximate_digit_width
    - ✅ get_ascent
    - ✅ get_descent
    - ✅ get_height
    - ✅ get_strikethrough_position
    - ✅ get_strikethrough_thickness
    - ✅ get_underline_position
    - ✅ get_underline_thickness
    - ref
    - unref
- ✅ GlyphGeometry
- ✅ GlyphInfo
- 🟨 GlyphItem
    - Instance methods
        - apply_attrs
        - copy
        - ✅ free // internal
        - ✅ get_logical_widths
        - ✅ letter_space
        - ✅ split

- GlyphItemIter
    - Instance methods
        - copy
        - ✅ free // internal
        - ✅ init_end
        - ✅ init_start
        - ✅ next_cluster
        - ✅ prev_cluster

- 🟨 GlyphString
    - Constructors
        - new
    - Instance methods
        - copy // internal
        - ✅ extents
        - ✅ extents_range
        - ✅ free // internal
        - get_logical_widths
        - ✅ get_width
        - index_to_x // skip for now
        - index_to_x_full // skip for now
        - set_size // internal
        - x_to_index // skip for now
- ✅ GlyphVisAttr
- 🟨 Item
    - Constructors
        - new
    - Instance methods
        - ✅ apply_attrs
        - ✅ copy // internal
        - ✅ free // internal
        - ✅ get_char_offset
        - ✅ split
- ✅ Language
- LayoutIter
    - ✅ at_last_line
    - ✅ copy
    - ✅ free
    - ✅ get_baseline
    - ✅ get_char_extents
    - ✅ get_cluster_extents
    - ✅ get_index
    - ✅ get_layout
    - ✅ get_layout_extents
    - ✅ get_line
    - ✅ get_line_extents
    - get_line_readonly
    - ✅ get_line_yrange
    - ✅ get_run
    - ✅ get_run_baseline
    - ✅ get_run_extents
    - get_run_readonly
    - ✅ next_char
    - ✅ next_cluster
    - ✅ next_line
    - ✅ next_run

- ✅ LayoutLine
    - ✅ get_extents
    - ✅ get_height
    - ✅ get_length
    - ✅ get_pixel_extents
    - ✅ get_resolved_direction
    - ✅ get_start_index
    - ✅ get_x_ranges
    - index_to_x // skip for now
    - ✅ is_paragraph_start
    - ref
    - unref
    - x_to_index // skip for now

- ✅ LogAttr
- ✅ Matrix
    - ✅ concat
    - copy // internal
    - free // internal
    - ✅ get_font_scale_factor
    - ✅ get_font_scale_factors
    - ✅ get_slant_ratio
    - ✅ rotate
    - ✅ scale
    - ✅ transform_distance
    - ✅ transform_pixel_rectangle
    - ✅ transform_point
    - ✅ transform_rectangle
    - ✅ translate

- ✅ Rectangle
- ✅ ScriptIter
- ✅ TabArray
    - ✅ new
    - new_with_positions // skip this
    - ✅ from_string
    - ✅ copy // internal
    - ✅ free // internal
    - ✅ get_decimal_point // internal
    - ✅ get_positions_in_pixels
    - ✅ get_size
    - ✅ get_tab
    - ✅ get_tabs
    - ✅ resize // internal
    - ✅ set_decimal_point
    - ✅ set_positions_in_pixels
    - ✅ set_tab
    - ✅ sort // internal
    - ✅ to_string

# Enumerations
- ✅ Alignment
- ✅ AttrType
    - get_name // skip for now, no custom attributes
    - register // skip for now, no custom attributes
- ✅ BaselineShift
- 🟪 BidiType deprecated: 1.44
- ✅ CoverageLevel
- ✅ Direction
- ✅ EllipsizeMode
- ✅ FontColor
- ✅ FontScale
- ✅ Gravity
    - ✅ get_for_matrix
    - get_for_script // use get_for_script_and_width
    - ✅ get_for_script_and_width
    - ✅ to_rotation
- ✅ GravityHint
- ✅ Overline
- RenderPart
- ✅ Script // uses GUnicodeScript enumeration
    - 🟪 for_unichar deprecated: 1.44.
    - ✅ get_sample_language
- ✅ Stretch
- ✅ Style
- ✅ TabAlign
- ✅ TextTransform
- ✅ Underline
- ✅ Variant
- ✅ Weight
- ✅ Width
- ✅ WrapMode

# Bitfields
- ✅ PangoFontMask
- ✅ LayoutDeserializeFlags
- ✅ LayoutSerializeFlags
- ✅ RenderComponent
- ✅ ShapeFlags
- ✅ ShowFlags

# functions
- ✅ attr_allow_breaks_new
- ✅ attr_background_alpha_new
- ✅ attr_background_new
- ✅ attr_baseline_shift_new
- ✅ attr_break
- ✅ attr_fallback_new
- ✅ attr_family_new
- ✅ attr_font_scale_new
- ✅ attr_foreground_alpha_new
- ✅ attr_foreground_new
- ✅ attr_gravity_hint_new
- ✅ attr_gravity_new
- ✅ attr_insert_hyphens_new
- ✅ attr_letter_spacing_new
- ✅ attr_line_height_new
- ✅ attr_line_height_new_absolute
- ✅ attr_overline_color_new
- ✅ attr_overline_new
- ✅ attr_rise_new
- ✅ attr_scale_new
- ✅ attr_sentence_new
- ✅ attr_show_new
- ✅ attr_stretch_new
- ✅ attr_strikethrough_color_new
- ✅ attr_strikethrough_new
- ✅ attr_style_new
- ✅ attr_text_transform_new
- ✅ attr_underline_color_new
- ✅ attr_underline_new
- ✅ attr_variant_new
- ✅ attr_weight_new
- ✅ attr_width_new
- ✅ attr_word_new
- 🟪 break deprecated: 1.44
- ✅ default_break
- ✅ extents_to_pixels
- ✅ find_base_dir deprecated: 1.44
- ✅ find_paragraph_boundary
- ✅ get_log_attrs
- 🟪 get_mirror_char deprecated: 1.30
- ✅ is_zero_width
- ✅ itemize
- ✅ itemize_with_base_dir
- ✅ log2vis_get_embedding_levels
- markup_parser_finish // skip for now
- markup_parser_new // skip for now
- 🟪 parse_enum deprecated: 1.38
- ✅ parse_markup
- ✅ parse_stretch
- ✅ parse_style
- ✅ parse_variant
- ✅ parse_weight
- ✅ quantize_line_geometry
- 🟪 read_line deprecated: 1.38
- ✅ reorder_items
- 🟪 scan_int deprecated: 1.38
- 🟪 scan_string deprecated: 1.38
- 🟪 scan_word deprecated: 1.38
- ✅ shape
- ✅ shape_full
- ✅ shape_item
- ✅ shape_with_flags
- 🟪 skip_space deprecated: 1.38
- 🟪 split_file_list deprecated: 1.38
- ✅ tailor_break
- 🟪 trim_string deprecated: 1.38
- 🟪 unichar_direction deprecated: 1.44
- ✅ units_from_double
- ✅ units_to_double
- ✅ version
- ✅ version_check
- ✅ version_string

# PangoCairo Classes

## Interfaces
### Font (inherits from Pango.Font)
- get_scaled_font

### FontMap (inherits from Pango.FontMap)
#### Functions
- ✅ get_default
- ✅ new
- ✅ new_for_font_type
#### Instance methods
- 🟪 create_context deprecated: 1.22
- ✅ get_font_type
- ✅ get_resolution
- ✅ set_default
- ✅ set_resolution

### Functions
- error_underline_path // skip for now
- show_error_underline // skip for now
#### Context
- ✅ create_context
- ✅ context_get_font_options
- ✅ context_get_resolution
- ✅ context_set_font_options
- ✅ context_set_resolution
- ✅ update_context
- context_set_shape_renderer // skip for now
- context_get_shape_renderer // skip for now
#### Layout
- ✅ create_layout
- ✅ layout_path
- ✅ show_layout
- ✅ update_layout
- ✅ layout_path_for_components Available since: 1.58
#### LayoutLine
- ✅ layout_line_path
- ✅ show_layout_line
#### GlyphString
- ✅ glyph_string_path
- ✅ show_glyph_string
#### GlyphItem
- show_glyph_item ✅

# PangoFc
## Classes
### Decoder
#### Instance methods
    - pango_fc_decoder_get_charset
    - pango_fc_decoder_get_glyph
### Font
#### Properties
    - FcPattern* font_pattern,
    - PangoFontMap* fontmap,
    - gpointer priv,
    - PangoMatrix matrix,
    - PangoFontDescription* description,
    - gpointer metrics_by_lang,
    - guint is_hinted : 1,
    - guint is_transformed : 1
#### Instance methods
    - get_glyph
    - 🟪 get_languages // deprecated: 1.50
    - get_pattern // skip for now
    - get_unknown_glyph
    - 🟪 has_char // deprecated: 1.50
    - 🟪 kern_glyphs // deprecated: 1.50
    - 🟪 lock_face // deprecated: 1.50
    - 🟪 unlock_face // deprecated: 1.50
### FontMap
    - add_decoder_find_func
    - ✅ cache_clear
    - ✅ config_changed
    - 🟪 create_context // deprecated: 1.22
    - find_decoder
    - get_config
    - get_hb_face
    - set_config
    - set_default_substitute
    - ✅ shutdown
    - ✅ substitute_changed
## Callbacks
    - DecoderFindFunc
    - SubstituteFunc
## Constants
    - 🟪 FONT_FEATURES // deprecated: 1.56
    - 🟪 FONT_VARIATIONS // deprecated: 1.56
    - GRAVITY
    - PRGNAME // deprecated: 1.56
    - VERSION

# PangoFT2
## Classes
### FontMap, final class
    - ✅ pango_ft2_font_map_new
    - pango_ft2_font_map_for_display // deprecated
#### Instance methods
    - 🟪 create_context // deprecated: 1.22
    - 🟪 set_default_substitute // deprecated: 1.46
    - ✅ set_resolution
    - 🟪 substitute_changed // deprecated: 1.46
## Callbacks
    - SubstituteFunc // skip for now
## Functions
    - font_get_coverage // use pango/font_get_coverage
    - font_get_face // use pango/font_get_coverage
    - font_get_kerning
    - 🟪 get_context // deprecated: 1.22
    - get_unknown_glyph
    - render // skip for now
    - render_layout // skip for now
    - render_layout_line // skip for now
    - render_layout_line_subpixel // skip for now
    - render_layout_subpixel // skip for now
    - render_transformed // skip for now
    - shutdown_display
