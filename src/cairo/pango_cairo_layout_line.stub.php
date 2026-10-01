<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace PangoCairo;

/**
 * Represents one of the lines resulting from laying out a paragraph via Layout.
 */
final class LayoutLine extends \Pango\LayoutLine
{
    /**
     * Adds the text in this LayoutLine to the current path in the specified cairo
     * context.
     *
     * The origin of the glyphs (the left edge of the line) will be at the
     * current point of the cairo context.
     */
    public function path(): void {}

    /**
     * Draws this LayoutLine in the specified cairo context.
     *
     * The origin of the glyphs (the left edge of the line) will be drawn at
     * the current point of the cairo context.
     */
    public function show(): void {}

    /**
     * Returns the runs (glyph items) in the line, from left to right.
     *
     * @return GlyphItem[] An array of GlyphItem objects.
     */
    public function getRuns(): array {}
}
