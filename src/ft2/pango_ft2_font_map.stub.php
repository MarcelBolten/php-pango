<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Ft2;

/**
 * The Pango\Ft2\FontMap is the PangoFontMap implementation for FreeType fonts.
 */
final class FontMap extends \Pango\Fc\FontMap
{
    /**
     * Create a new PangoFT2FontMap object.
     *
     * A fontmap is used to cache information about available fonts, and holds
     * certain global parameters such as the resolution and the default
     * substitute function (see pango_ft2_font_map_set_default_substitute()).
     */
    public function __construct() {}

    /**
     * Sets the horizontal and vertical resolutions for the fontmap.
     */
    public function setResolution(float $dpiX, float $dpiY): FontMap {}
}
