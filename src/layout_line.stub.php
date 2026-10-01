<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * Represents one of the lines resulting from laying out a paragraph via Layout.
 */
class LayoutLine
{
    /**
     * Computes the logical and ink extents of a layout line.
     *
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getExtents(): array {}

    /**
     * Computes the height of the line, as the maximum of the heights of fonts used in this line.
     */
    public function getHeight(): int {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Returns the length of the line, in bytes.
     */
    public function getLength(): int {}
#endif

    /**
     * Computes the logical and ink extents of LayoutLine in device units.
     *
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getPixelExtents(): array {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Returns the resolved direction of the line.
     */
    public function getResolvedDirection(): Direction {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Returns the start index of the line, as byte index into the text of the layout.
     */
    public function getStartIndex(): int {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Returns whether this is the first line of the paragraph.
     */
    public function isParagraphStart(): bool {}
#endif

    /**
     * Returns the runs (glyph items) in the line, from left to right.
     *
     * @return GlyphItem[] An array of GlyphItem objects.
     */
    public function getRuns(): array {}

    /**
     * Gets a list of visual ranges corresponding to a given logical range.
     *
     * This list is not necessarily minimal - there may be consecutive ranges
     * which are adjacent. The ranges will be sorted from left to right. The
     * ranges are with respect to the left edge of the entire layout, not
     * with respect to the line.
     *
     * @param null|int $byteStart Start byte index of the layout’s logical range. Defaults to the start index of the line. If this
     *                       value is less than the start index for the line,
     *                       then the first range will extend all the way to
     *                       the leading edge of the layout. Otherwise, it
     *                       will start at the leading edge of the first
     *                       character.
     * @param null|int $byteEnd Ending byte index of the layout’s logical range. Defaults to the end index of the line. If this
     *                     value is greater than the end index for the line,
     *                     then the last range will extend all the way to the
     *                     trailing edge of the layout. Otherwise, it will
     *                     end at the trailing edge of the last character.
     *
     * @return array<int, array{start: int, end: int, width: int}> The coordinates
     *                       are relative to the layout and are in Pango units.
     */
    public function getXRanges(
        null|int $byteStart = null,
        null|int $byteEnd = null,
    ): array {}
}
