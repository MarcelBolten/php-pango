<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * FontMap represents the set of fonts available for a particular rendering system.
 */
abstract class FontMap
{
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
    /**
     * Loads a font file with one or more fonts into the FontMap.
     *
     * @param string $file The absolute path to the font file to load.
     * @throws Exception If the font file could not be loaded.
     */
    public function addFontFile(
        string $file
    ): bool {}
#endif

    /**
     * Creates a context connected to font map.
     */
    public function createContext(): Context {}

    /**
     * Gets a font family by name.
     */
    public function getFamily(
        string $name
    ): ?FontFamily {}

    /**
     * List all families for a font map.
     *
     * @return FontFamily[] An array of FontFamily objects.
     */
    public function listFamilies(): array {}

    /**
     * Load the font of this FontMap that is the closest match for desc.
     *
     * @param Context $context The Context the font will be used with.
     * @param FontDescription $desc A FontDescription describing the font to load.
     *
     * @return Font|null The loaded Font, or NULL if no font matched.
     */
    public function loadFont(
        Context $context,
        FontDescription $desc
    ): null|Font {}

    /**
     * Load a set of fonts in this FontMap that can be used to render a font matching desc.
     *
     * @param Context $context The Context the font will be used with.
     * @param FontDescription $desc A FontDescription describing the font to load.
     * @param Language $language The language to use when loading the font set.
     *
     * @return FontSet|null The loaded FontSet, or NULL if no font set matched.
     */
    public function loadFontSet(
        Context $context,
        FontDescription $desc,
        Language $language
    ): null|FontSet {}

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
     * @param Font $font The font in this FontMap to reload.
     * @param float $scale The scale factor to apply.
     * @param null|Context $context The context to use, or NULL to use the default context.
     * @param null|string $variations The font variations to apply, or NULL to keep the existing variations.
     *
     * @return Font The modified font.
     */
    public function reloadFont(
        Font $font,
        float $scale,
        null|Context $context = null,
        null|string $variations = null
    ): Font {}
#endif
}
