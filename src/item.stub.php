<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Item stores information about a segment of text.
 */
class Item
{
    /**
     * Byte offset of the start of this item in text.
     */
    public int $offset;

    /**
     * Length of this item in bytes.
     */
    public int $length;

    /**
     * Number of Unicode characters in the item.
     */
    public int $numChars;

    /**
     * Analysis results for the item.
     */
    // public int $analysis;
}
