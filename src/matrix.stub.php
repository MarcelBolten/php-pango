<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Matrix specifies a transformation between user-space and device coordinates.
 */
final class Matrix
{
    public float $xx = 1.0;
    public float $yx = 0.0;
    public float $xy = 0.0;
    public float $yy = 1.0;
    public float $x0 = 0.0;
    public float $y0 = 0.0;

    public function __construct(
        float $xx = 1.0,
        float $yx = 0.0,
        float $xy = 0.0,
        float $yy = 1.0,
        float $x0 = 0.0,
        float $y0 = 0.0,
    ) {}

    /**
     * Returns the scale factor of a matrix on the height of the font.
     */
    // public function getFontScaleFactor(): float {}

    /**
     * Calculates the scale factor of a matrix on the width and height of the font.
     */
    // public function getFontScaleFactors(): float {}

    // /**
    //  * Gets the slant ratio of a matrix.
    //  */
    // public function getSlantRatio(): float {}

    public function rotate(
        float $radians
    ): void {}

    public function scale(
        float $sx,
        float $sy
    ): void {}

    /**
     * @return array{"x": float, "y": float}
     * // TODO: return Vector Class
     */
    public function transformDistance(
        float $dx,
        float $dy
    ): array {}

    // public function transformPixelRectangle(
    //     Rectangle $rectangle
    // ): Rectangle {}

    /**
     * @return array{"x": float, "y": float}
     * // TODO: return Point Class
     */
    public function transformPoint(
        float $x,
        float $y
    ): array {}

    // public function transformRectangle(
    //     Rectangle $rectangle
    // ): Rectangle {}

    public function translate(
        float $tx,
        float $ty
    ): void {}
}
