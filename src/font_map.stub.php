<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * FontMap represents the set of fonts available for a particular rendering system.
 */
abstract class FontMap
{
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,56,0)
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

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1,46,0)
    /**
     * Gets a font family by name.
     *
     * TODO: Return FontFamily object when available.
     */
    public function getFamily(
        string $name
    ): string {}
#endif

    /**
     * List all families for a font map.
     *
     * @return string[] An array of family names.
     */
    public function listFamilies(): array {}

    // public function loadFont(
    //     Context $context,
    //     FontDescription $desc
    // ): Font {}

    // public function loadFontSet(
    //     Context $context,
    //     FontDescription $desc,
    //     string $language
    // ): null|FontSet {}

    // public function reloadFont(
    //     Font $font,
    //     bool $scale,
    //     null|Context $context = null,
    //     null|string $variations = null
    // ): Font {}
}
