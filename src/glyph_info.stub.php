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
     * xOffset: Horizontal offset from nominal character position. \
     * yOffset: Vertical offset from nominal character position.
     *
     * @var array{width: int, xOffset: int, yOffset: int}
     */
    public array $geometry;

    /**
     * The visual attributes of the glyph.
     * @var array{isClusterStart: bool, isColor: bool}
     */
    public array $attributes;
}
