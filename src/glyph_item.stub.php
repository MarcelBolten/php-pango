<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * GlyphItem is a pair of a Item and the glyphs resulting from shaping the items text.
 */
final readonly class GlyphItem
{
    public Item $item;

    public GlyphString $glyphs;

    /**
     * Shift of the baseline, relative to the baseline of the containing line. Positive values shift upwards.
     */
    public int $yOffset;

    /**
     * Horizontal displacement to apply before the glyph item. Positive values shift right.
     */
    public int $startXOffset;

    /**
     * Horizontal displacement to apply after th glyph item. Positive values shift right.
     */
    public int $endXOffset;
}
