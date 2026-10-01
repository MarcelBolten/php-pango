<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * LayoutIter can be used to iterate over the visual extents of a Layout.
 *
 * It cannot be instantiated directly, but is returned by Pango\Layout::getIter() and can be used to iterate over the lines, runs, clusters, and characters of a layout.
 */
final class LayoutIter
{
    private function __construct() {}

    /**
     * Whether already on the last line of the layout.
     */
    public function atLastLine(): bool {}

    /**
     * Gets the Y position of the current line’s baseline, in layout coordinates.
     *
     * Layout coordinates have the origin at the top left of the entire layout.
     */
    public function getBaseline(): int {}

    /**
     * Gets the extents of the current character, in layout coordinates.
     *
     * Layout coordinates have the origin at the top left of the entire layout.
     *
     * Only logical extents can sensibly be obtained for characters; ink extents make sense only down to the level of clusters.
     */
    public function getCharExtents(): Rectangle {}

    /**
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getClusterExtents(): array {}

    /**
     * Gets the current byte index.
     *
     * Note that iterating forward by char moves in visual order, not logical
     * order, so indexes may not be sequential. Also, the index may be equal to
     * the length of the text in the layout, if on the NULL run
     * (see Pango\LayoutIter::getRun()).
     */
    public function getIndex(): int {}

    public function getLayout(): Layout {}

    /**
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getLayoutExtents(): array {}

    public function getLine(): LayoutLine {}

    /**
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getLineExtents(): array {}

    // public function getLineReadonly() {}

    /**
     * @return array{y0: int, y1: int}
     */
    public function getLineYrange(): array {}

    /**
     * Gets the current run.
     *
     * When iterating by run, at the end of each line, there’s a position with
     * a NULL run, so this function can return NULL. The NULL run at the end of
     * each line ensures that all lines have at least one run, even lines
     * consisting of only a newline.
     *
     * Use the faster Pango\LayoutIter::getRunReadonly() if you do not plan to
     * modify the contents of the run (glyphs, glyph widths, etc.).
     */
    public function getRun(): null|GlyphItem {}

    /**
     * Gets the Y position of the current run’s baseline, in layout
     * coordinates.
     *
     * Layout coordinates have the origin at the top left of the entire layout.
     *
     * The run baseline can be different from the line baseline, for example
     * due to superscript or subscript positioning.
     */
    public function getRunBaseline(): int {}

    /**
     * @return array{ink: Rectangle, logical: Rectangle}
     */
    public function getRunExtents(): array {}

    // public function getRunReadonly() {}

    /**
     * Moves forward to the next character in visual order.
     *
     * @return bool Whether motion was possible, false if already at the end of the layout.
     */
    public function nextChar(): bool {}

    /**
     * Moves forward to the next cluster in visual order.
     *
     * @return bool Whether motion was possible, false if already at the end of the layout.
     */
    public function nextCluster(): bool {}

    /**
     * Moves forward to the start of the next line.
     *
     * @return bool Whether motion was possible, false if already on the last line.
     */
    public function nextLine(): bool {}

    /**
     * Moves forward to the next run in visual order.
     *
     * @return bool Whether motion was possible, false if already at the end of the layout.
     */
    public function nextRun(): bool {}
}
