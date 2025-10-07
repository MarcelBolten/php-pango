<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * GlyphInfo structure represents a single glyph with positioning information and visual attributes.
 */
class GlyphInfo
{
    /**
     * The glyph itself, a numeric ID.
     *
     * Note that glyph IDs are font-specific: the same character can be represented by different glyph IDs in different fonts.
     * The mapping between characters and glyphs is in general neither 1-1 nor a map.
     */
    public int $glyph;

    /**
     * The positional information about the glyph.
     *
     * width: The logical width to use for the the character. \
     * x_offset: Horizontal offset from nominal character position. \
     * y_offset: Vertical offset from nominal character position.
     *
     * @var array{width: int, x_offset: int, y_offset: int}
     */
    public array $geometry;

    /**
     * The visual attributes of the glyph.
     * @var array{is_cluster_start: bool, is_color: bool}
     */
    public array $attributes;
}
