<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * A FontFamily is used to represent a family of related font faces.
 * The font faces in a family share a common design, but differ in slant,
 * weight, width or other aspects.
 */
final class FontFamily
{
    /**
     * Gets the FontFace of family with the given name.
     *
     * @param null|string $name The name of the FontFace to get, or null to get the default face.
     *
     * @return null|FontFace The FontFace with the given name, or null if no such face exists.
     */
    public function getFace(
        null|string $name = null
    ): null|FontFace {}

    /**
     * Gets the name of the family.
     *
     * The name is unique among all fonts for the font backend and can be used
     * in a FontDescription to specify that a face from this family is desired.
     */
    public function getName(): string {}

    /**
     * A monospace font is a font designed for text display where the the characters form a regular grid.
     */
    public function isMonospace(): bool {}

    /**
     * A variable font is a font which has axes that can be modified to produce different faces.
     */
    public function isVariable(): bool {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Lists the different font faces that make up family.
     *
     * @return FontFace[] An array of FontFace objects.
     */
    public function listFaces(): array {}
#endif
}
