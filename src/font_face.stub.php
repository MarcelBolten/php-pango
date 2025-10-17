<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * A FontFace is used to represent a group of fonts with the same family,
 * slant, weight, and width, but varying sizes.
 */
final class FontFace
{
    /**
     * Returns a font description that matches the face.
     *
     * The resulting font description will have the family, style, variant,
     * weight and stretch of the face, but its size field will be unset.
     */
    public function describe(): FontDescription {}

    /**
     * Gets a name representing the style of this face.
     *
     * Note that a font family may contain multiple faces with the same name
     * (e.g. a variable and a non-variable face for the same style).
     */
    public function getName(): string {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
    /**
     * Gets the FontFamily that face belongs to.
     */
    public function getFamily(): FontFamily {}
#endif

    /**
     * Returns whether a FontFace is synthesized.
     *
     * This will be the case if the underlying font rendering engine creates
     * this face from another face, by shearing, emboldening, lightening or
     * modifying it in some other way.
     */
    public function isSynthesized(): bool {}

    /**
     * List the available sizes for a font.
     *
     * This is only applicable to bitmap fonts.  The sizes returned are in
     * Pango units and are sorted in ascending order.
     *
     * @return int[] An array of font sizes for bitmap fonts, or an empty array for scalable fonts.
     */
    public function listSizes(): array {}
}
