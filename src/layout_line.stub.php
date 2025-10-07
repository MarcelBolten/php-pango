<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Represents one of the lines resulting from laying out a paragraph via Layout.
 */
// make it readonly
final class LayoutLine
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

    /**
     * Draws a LayoutLine in a cairo context.
     *
     * If no context is specified, it uses the cached one from when the LayoutLine (the corresponding Layout) was created.
     */
    public function showLayoutLine(
        \Cairo\Context|null $context = null
    ): void {}

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
}
