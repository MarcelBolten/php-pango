<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Fc;

/**
 * Pango\Fc\FontMap is a base class for font map implementations using
 * the Fontconfig and FreeType libraries.
 */
abstract class FontMap extends \Pango\FontMap
{
    /**
     * Clear all cached information and fontsets for this font map.
     *
     * This should be called whenever there is a change in the output of the
     * defaultSubstitute() virtual function of the font map, or if fontconfig
     * has been reinitialized to new configuration.
     */
    public function clearCache(): void {}

    /**
     * Informs font map that the fontconfig configuration
     * (i.e., the FcConfig object) used by this font map has changed.
     *
     * This currently calls clearCache() which ensures that
     * list of fonts, etc will be regenerated using the updated configuration.
     */
    public function configChanged(): void {}

    // public function findDecoder(FcPattern $pattern): Decoder {}

    // public function getConfig(): FcConfig {}

    // public function getHbFace(): HbFaceT {}

    // public function setConfig(FcConfig $config): FontMap {}

    // public function setDefaultSubstitute(SubstituteFunc $func): FontMap {}

    /**
     * Clears all cached information for this fontmap and marks all fonts open
     * for the fontmap as dead.
     *
     * See the shutdown() virtual function of PangoFcFont.
     *
     * This function might be used by a backend when the underlying windowing
     * system for the font map exits. This function is only intended to be
     * called only for backend implementations deriving from PangoFcFontMap.
     */
    public function shutdown(): void {}

    /**
     * Call this function any time the results of the default substitution
     * function set with pango_fc_font_map_set_default_substitute() change.
     *
     * That is, if your substitution function will return different results for
     * the same input pattern, you must call this function.
     */
    public function substituteChanged(): void {}
}
