<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * GlyphInfo represents a single glyph with positioning information and visual attributes.
 */
final readonly class GlyphInfo
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
     */
    public GlyphGeometry $geometry;

    /**
     * The visual attributes of the glyph.
     */
    public GlyphVisAttr $attributes;
}
