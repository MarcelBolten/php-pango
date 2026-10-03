<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * A TabStops object contains a list of tab stops
 * either in Pango units or in pixels.
 *
 * TabStops can be used to set tab stops in a Layout. Each tab stop has an
 * alignment, a position, and optionally a character to use as decimal point.
 * The tabs are stored in increasing order of position and resorted when a new
 * tab stop is added. A TabStops instance can only contain tab stops in either
 * Pango units (Pango\TabStop) or pixels (Pango\TabStopPixel), not both.
 */
final class TabStops
{
    /**
     * @param TabStop[] $tabStops
     */
    public function __construct(array $tabStops) {}

    /**
     * Serializes a Pango\TabStops object to a string.
     *
     * Individual tabs are serialized to a string of the form:\
     * [ALIGNMENT:]POSITION[:DECIMAL_POINT] \
     * Where ALIGNMENT is one of left, right, center or decimal, and POSITION
     * is the position of the tab, optionally followed by the unit px. If
     * ALIGNMENT is omitted, it defaults to left. If ALIGNMENT is decimal, the
     * DECIMAL_POINT character may be specified as a Unicode codepoint.
     */
    public function __toString(): string {}

    /**
     * This is the counterpart to Pango\TabArray::toString().
     * See that method for details about the format.
     * @throws \ValueError if the string cannot be parsed
     */
    public static function fromString(string $str): TabStops {}

    public function add(TabStop $tabStop): void {}

    /**
     * @throws \ValueError if $index is out of bounds
     */
    public function remove(int $index): void {}

    /**
     * Sets/updates the tab stop at the given index.
     *
     * Only existing tab stops can be updated.
     * To add a new tab stop, use the add() method.
     *
     * @throws \ValueError if $index is out of bounds
     */
    public function set(
        int $index,
        TabStop $tabStop,
    ): TabStops {}

    /**
     * @throws \ValueError if $index is out of bounds
     */
    public function getTab(int $index): ?TabStop {}

    /**
     * @return TabStop[]
     */
    public function getTabs(): array {}

    /**
     * Returns the number of tab stops in the list.
     */
    public function getSize(): int {}

    /**
     * Whether the tab stops are in pixels or Pango units.
     */
    public function arePositionsInPixels(): bool {}
}

readonly class TabStop
{
    public TabAlign $alignment;
    public int $position;
    public ?string $decimalChar;

    public function __construct(
        TabAlign $alignment,
        int $position,
        ?string $decimalChar = null,
    ) {}
}

final readonly class TabStopPixel extends TabStop
{
}

/**
 * TabAlign specifies where the text appears
 * relative to the tab stop position.
 */
enum TabAlign: int
{
    /**
     * The text appears to the right of the tab stop position.
     *
     * @cvalue PANGO_TAB_LEFT
     */
    case Left = UNKNOWN;

    /**
     * The text appears to the left of the tab stop position until
     * the available space is filled.
     *
     * @cvalue PANGO_TAB_RIGHT
     */
    case Right = UNKNOWN;

    /**
     * The text is centered at the tab stop position until
     * the available space is filled.
     *
     * @cvalue PANGO_TAB_CENTER
     */
    case Center = UNKNOWN;

    /**
     * Text before the first occurrence of the decimal point character appears
     * to the left of the tab stop position (until the available space is
     * filled), the rest to the right.
     *
     * @cvalue PANGO_TAB_DECIMAL
     */
    case Decimal = UNKNOWN;
}
