<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace PangoCairo;

/**
 * FontMap is used to cache information about available fonts, and holds certain global parameters such as the resolution.
 */
final class FontMap extends \Pango\FontMap
{
    public function __construct() {}

    /**
     * Gets a default PangoCairo\FontMap to use with Cairo.
     */
    public static function getDefault(): FontMap {}

    /**
     * Creates a new PangoCairo\FontMap object of the type suitable to be used with cairo font backend of type \Cairo\FontType.
     *
     * \Cairo\FontType::Toy is not a real font backend and will not work.
     */
    public static function newForFontType(
        \Cairo\FontType $type
    ): FontMap {}

    /**
     * Gets the type of Cairo font backend that font map uses.
     */
    public function getFontType(): \Cairo\FontType {}

    /**
     * Gets the resolution for the font map in “dots per inch”.
     */
    public function getResolution(): float {}

    /**
     * Sets a default PangoCairo\FontMap to use with Cairo.
     */
    public function setDefault(
        FontMap $fontMap
    ): void {}

    /**
     * Sets the resolution for the font map.
     *
     * This is a scale factor between points specified in Pango\FontDescription
     * and Cairo units. The default value is 96, meaning that a 10 point font
     * will be 13 units high. (10 * 96. / 72. = 13.3).
     *
     * The resolution in “dots per inch”.
     * (Physical inches aren’t actually involved; the terminology is conventional.)
     */
    public function setResolution(
        float $factor
    ): void {}
}
