<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * Color is used to represent a color in an uncalibrated RGB color-space.
 */
final readonly class Color
{
    public int $red;

    public int $green;

    public int $blue;

    /**
     * @param int $red   0 - 65535
     * @param int $green 0 - 65535
     * @param int $blue  0 - 65535
     */
    public function __construct(
        int $red,
        int $green,
        int $blue,
    ) {}

    /**
     * Creates a new Color object from a string representation of a color.
     *
     * @param string $string It can either be one of a large set of standard names
     * (Taken from the [CSS Color specification](https://www.w3.org/TR/css-color-4/#named-colors)) or it can be a value in the
     * form #rgb, #rrggbb, #rrrgggbbb or #rrrrggggbbbb, where r, g and b are
     * hex digits of the red, green, and blue components of the color,
     * respectively.  (White in the four forms is #fff, #ffffff, #fffffffff
     * and #ffffffffffff).
     *
     * @throws Pango\Exception if the string cannot be parsed into a color.
     */
    public static function fromString(
        string $string
    ): Color {}

    /**
     * Returns a textual specification of color.
     *
     * The string is in the hexadecimal form #rrrrggggbbbb, where r, g and b are
     * hex digits representing the red, green, and blue components respectively.
     */
    public function __toString(): string {}
}
