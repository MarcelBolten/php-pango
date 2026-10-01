<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * FontSetSimple is a implementation of the abstract FontSet base class.
 */
final readonly class FontSetSimple extends FontSet
{
    public int $size;

    public function __construct(Language $language) {}

    /**
     * Adds a font to the FontSet.
     */
    public function append(Font $font): void {}
}
