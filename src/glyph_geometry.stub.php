<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * GlyphGeometry structure contains width and positioning information for a single glyph.
 */
final readonly class GlyphGeometry
{
    /**
     * The logical width to use for the the character.
     */
    public int $width;

    /**
     * Horizontal offset from nominal character position.
     */
    public int $xOffset;

    /**
     * Vertical offset from nominal character position.
     */
    public int $yOffset;
}
