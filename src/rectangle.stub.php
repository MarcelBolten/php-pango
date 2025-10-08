<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Rectangle is frequently used to represent the logical or ink extents of a single glyph or section of text.
 *
 * The units of a rectangle usually are in 1/Pango\Pango::SCALE of a device unit but can also be in device units.
 */
final readonly class Rectangle
{
    /**
     * X coordinate of the left side of the rectangle.
     */
    public int $x;

    /**
     * Y coordinate of the the top side of the rectangle.
     */
    public int $y;

    /**
     * Width of the rectangle.
     */
    public int $width;

    /**
     * Height of the rectangle.
     */
    public int $height;

    /**
     * The ascent is the distance from the baseline to the highest point
     * of the character. This is positive if the glyph ascends above the baseline.
     */
    public int $ascent;

    /**
     * The descent is the distance from the baseline to the lowest point
     * of the character. This is positive if the glyph descends below the baseline.
     */
    public int $descent;

    /**
     * The left bearing is the distance from the horizontal origin
     * to the farthest left point of the character. This is positive
     * for characters drawn completely to the right of the glyph origin.
     */
    public int $leftBearing;

    /**
     * The right bearing is the distance from the horizontal origin
     * to the farthest right point of the character. This is positive
     * except for characters drawn completely to the left of the horizontal origin.
     */
    public int $rightBearing;

    /**
     * @param int $x X coordinate of the left side of the rectangle.
     * @param int $y Y coordinate of the the top side of the rectangle.
     * @param int $width Width of the rectangle.
     * @param int $height Height of the rectangle.
     */
    public function __construct(
        int $x,
        int $y,
        int $width,
        int $height
    ) {}

    /**
     * Converts extents from Pango units to device units.
     */
    public static function extentsToPixels(
        Rectangle $rectangle,
        RoundingMode $roundingMode = RoundingMode::Inclusive
    ): Rectangle {}
}

enum RoundingMode
{
    /**
     * The inclusive rectangle is converted by flooring the x/y coordinates and
     * extending width/height, such that the final rectangle completely
     * includes the original rectangle.
     */
    case Inclusive;

    /**
     * The nearest rectangle is converted by rounding the coordinates of the
     * rectangle to the nearest device unit (pixel).
     */
    case Nearest;
}
