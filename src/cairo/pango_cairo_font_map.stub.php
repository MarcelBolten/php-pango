<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
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
    public static function getDefault(): static {}

    /**
     * Creates a new PangoCairo\FontMap object of the type suitable to be used with cairo font backend of type \Cairo\FontType.
     *
     * \Cairo\FontType::Toy is not a real font backend and will not work.
     */
    public static function newForFontType(
        \Cairo\FontType $type,
    ): static {}

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
        FontMap $fontMap,
    ): static {}

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
        float $factor,
    ): static {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 52, 0)
    /**
     * Returns a new font that is like font, except that it is scaled by scale,
     * its backend-dependent configuration (e.g. cairo font options) is
     * replaced by the one in context, and its variations are replaced by
     * variations.
     *
     * Note that the scaling here is meant to be linear, so this scaling can be
     * used to render a font on a hi-dpi display without changing its optical
     * size.
     *
     * @param \Pango\Font $font The font in this FontMap to reload.
     * @param float $scale The scale factor to apply.
     * @param null|\Pango\Context $context The context to use, or NULL to use the default context.
     * @param null|string $variations The font variations to apply, or NULL to keep the existing variations.
     *
     * @return \Pango\Font The modified font.
     */
    public function reloadFont(
        \Pango\Font $font,
        float $scale,
        null|\Pango\Context $context = null,
        null|string $variations = null,
    ): \Pango\Font {}
#endif
}
