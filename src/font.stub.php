<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * A Font is used to represent a font in a rendering-system-independent manner.
 */
class Font
{
    /**
     * Returns a description of the font, with font size set in points.
     */
    public function describe(): FontDescription {}

    /**
     * Returns a description of the font, with absolute font size set in device units.
     */
    public function describeAbsolute(): FontDescription {}

    /**
     * Computes the coverage map for a given language tag.
     */
    public function getCoverage(Language $language): Coverage {}

    /**
     * Gets the FontFace to which this font belongs.
     */
    public function getFace(): FontFace {}

    /**
     * Obtain the OpenType features that are provided by the font.
     */
    public function getFeatures(): array {}

    /**
     * Gets the FontMap for which the font was created.
     */
    public function getFontMap(): FontMap {}

    /**
     * Gets the glyph extents for the font.
     *
     * @return array{glyph: int, ink: Rectangle, logical: Rectangle}
     */
    public function getGlyphExtents(): array {}

    // /**
    //  * Get a hb_font_t object backing this font.
    //  */
    // public function getHbFont(): HbFont {}

    /**
     * Returns the Languages that are supported by font.
     *
     * @return Language[] An array of Language objects.
     */
    public function getLanguages(): array {}

    /**
     * Gets overall metric information for a font.
     */
    public function getMetrics(?Language $language = null): FontMetrics {}

    /**
     * Returns whether the font provides a glyph for this character.
     */
    public function hasChar(string $char): bool {}

    // /**
    //  * Serializes the font in a way that can be uniquely identified.
    //  */
    // public function serialize(): string {}
}
