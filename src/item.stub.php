<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Item stores information about a segment of text.
 */
final readonly class Item
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
     *
     * bidiLevel: The bidirectional level for this segment.
     * Even levels: Text flows left-to-right.
     * Odd levels: Text flows right-to-left. \
     * gravity: The glyph orientation for this segment. \
     * centeredBaseline: Whether the segment should be shifted to center around the baseline. \
     * isEllipsis: Whether this run holds ellipsized text. \
     * needHyphen: Whether to add a hyphen at the end of the run during shaping. \
     * script: The detected script for this segment as ISO 15924 code. \
     * language: The detected language for this segment.
     *
     * @var array{bidiLevel: int, gravity: Gravity, centeredBaseline: bool, isEllipsis: bool, needHyphen: bool, script: string, language: string}
     */
    public array $analysis;
}
