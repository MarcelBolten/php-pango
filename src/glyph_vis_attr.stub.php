<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * GlyphVisAttr communicates information between the shaping and rendering phases.
 */
final readonly class GlyphVisAttr
{
    /**
     * Set for the first logical glyph in each cluster.
     */
    public bool $isClusterStart;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Set if the the font will render this glyph with color.
     */
    public bool $isColor;
#endif
}
