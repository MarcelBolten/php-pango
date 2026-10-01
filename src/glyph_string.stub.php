<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * GlyphString is used to store strings of glyphs with geometry and visual attribute information.
 */
readonly class GlyphString
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

    /**
     * Compute the logical and ink extents of a glyph string.
     *
     * @return array{ink: Rectangle, logical: Rectangle} Associative array containing the logical and ink extents of the glyph string.
     */
    public function getExtents(Font $font): array {}

    /**
     * Compute the logical and ink extents of a glyph string.
     *
     * The extents are relative to the start of the glyph string range (the
     * origin of their coordinate system is at the start of the range, not
     * at the start of the entire glyph string).
     *
     * @param int $start The starting index of the range to compute extents for, inclusive.
     * @param int $end The ending index of the range to compute extents for, exclusive.
     *
     * @return array{ink: Rectangle, logical: Rectangle} Associative array containing the logical and ink extents of the glyph string.
     */
    public function getExtentsRange(
        int $start,
        int $end,
        Font $font,
    ): array {}

    /**
     * Computes the logical width of the glyph string.
     */
    public function getWidth(): int {}

    /**
     * Determine the width corresponding to each character in the glyph string.
     *
     * @return int[] An array of widths corresponding to each character in this
     *               glyph string.  When multiple characters compose a single
     *               cluster, the width of the entire cluster is divided
     *               equally among the characters.
     */
    public function getLogicalWidths(): array {}
}
