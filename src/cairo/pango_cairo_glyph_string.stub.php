<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace PangoCairo;

/**
 * GlyphString is used to store strings of glyphs with geometry and visual attribute information.
 */
final readonly class GlyphString extends \Pango\GlyphString
{
    /**
     * Adds the glyphs in this GlyphString to the current path in the specified
     * cairo context.
     *
     * The origin of the glyphs (the left edge of the baseline) will be at the
     * current point of the cairo context.
     */
    public function path(\Pango\Font $font): void {}

    /**
     * Draws the glyphs in this GlyphString in the specified cairo context.
     *
     * The origin of the glyphs (the left edge of the baseline) will be drawn
     * at the current point of the cairo context.
     *
     * @param \Pango\Font $font A Font from a PangoCairo\FontMap.
     */
    public function show(\Pango\Font $font): void {}
}
