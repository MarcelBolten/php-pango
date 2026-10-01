<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * Matrix specifies a transformation between user-space and device coordinates.
 */
final class Matrix
{
    public readonly float $xx = 1.0;
    public readonly float $yx = 0.0;
    public readonly float $xy = 0.0;
    public readonly float $yy = 1.0;
    public readonly float $x0 = 0.0;
    public readonly float $y0 = 0.0;

    public function __construct(
        float $xx = 1.0,
        float $yx = 0.0,
        float $xy = 0.0,
        float $yy = 1.0,
        float $x0 = 0.0,
        float $y0 = 0.0,
    ) {}

    /**
     * Changes the transformation represented by this matrix to be the
     * transformation given by first applying the transformation given by
     * newMatrix and then applying the original transformation.
     */
    public function concat(
        Matrix $newMatrix
    ): void {}

    /**
     * Returns the scale factor of a matrix on the height of the font.
     */
    public function getFontScaleFactor(): float {}

    /**
     * Calculates the scale factor of a matrix on the width and height of the font.
     *
     * @return array{x: float, y: float} Scale factor in the x and y directions.
     */
    public function getFontScaleFactors(): array {}

    /**
     * Gets the slant ratio of a matrix.
     */
    public function getSlantRatio(): float {}

    /**
     * Finds the gravity that best matches the rotation component in this
     * matrix.
     *
     * @return Gravity The gravity that best matches the rotation component in
     *                 this matrix. It will never be Gravity::Auto.
     */
    public function getGravity(): Gravity {}

    /**
     * Changes the transformation represented by matrix to be the transformation
     * given by first rotating by degrees degrees counter-clockwise then
     * applying the original transformation.
     */
    public function rotate(
        float $degrees
    ): void {}

    /**
     * Changes the transformation represented by matrix to be the transformation
     * given by first scaling by sx in the X direction and sy in the Y direction
     * then applying the original transformation.
     */
    public function scale(
        float $sx,
        float $sy
    ): void {}

    /**
     * @return array{x: float, y: float}
     * // TODO: return Vector Class
     */
    public function transformDistance(
        float $dx,
        float $dy
    ): array {}

    /**
     * First transforms a rectangle using matrix, then calculates the bounding box of the transformed rectangle.
     *
     * For better accuracy, transformRectangle() should be used on the original rectangle in Pango units
     * and convert to pixels afterward using Rectangle::extentsToPixels().
     */
    public function transformPixelRectangle(
        Rectangle $rectangle
    ): Rectangle {}

    /**
     * @return array{x: float, y: float}
     * // TODO: return Point Class
     */
    public function transformPoint(
        float $x,
        float $y
    ): array {}

    /**
     * First transforms a rectangle using matrix, then calculates the bounding box of the transformed rectangle.
     *
     * If rectangle is in device units (pixels), use transformPixelRectangle().
     */
    public function transformRectangle(
        Rectangle $rectangle
    ): Rectangle {}

    public function translate(
        float $tx,
        float $ty
    ): void {}
}
