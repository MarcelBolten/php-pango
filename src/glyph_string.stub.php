<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * GlyphString is used to store strings of glyphs with geometry and visual attribute information.
 */
final readonly class GlyphString
{
    /**
     * Number of glyphs in this glyph string.
     */
    public int $numGlyphs;

    /**
     * Array of glyphs.
     * @var GlyphInfo[]
     */
    public array $glyphs;
}
