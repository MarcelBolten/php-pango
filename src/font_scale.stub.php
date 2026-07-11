<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * An enumeration that affects font sizes for superscript and subscript positioning and for (emulated) Small Caps.
 */
enum FontScale: int
{
    /**
     * Leave the font size unchanged.
     *
     * @cvalue PANGO_FONT_SCALE_NONE
     */
    case None = UNKNOWN;

    /**
     * Change the font to a size suitable for superscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUPERSCRIPT
     */
    case Superscript = UNKNOWN;

    /**
     * Change the font to a size suitable for subscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUBSCRIPT
     */
    case Subscript = UNKNOWN;

    /**
     * Change the font to a size suitable for Small Caps.
     *
     * @cvalue PANGO_FONT_SCALE_SMALL_CAPS
     */
    case SmallCaps = UNKNOWN;
}
