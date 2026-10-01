<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * A FontSet represents a set of Font to use when rendering text.
 *
 * A FontSet is the result of resolving a FontDescription against a particular
 * Context.  It has operations for finding the component font for a particular
 * Unicode character, and for finding a composite set of metrics for the entire
 * FontSet.
 */
readonly class FontSet
{
    /**
     * Iterates through all the fonts in a FontSet, calling
     * callback for each one.  If $callback returns TRUE,
     * that stops the iteration and returns the Font.
     *
     * @param callable $callback A callback function that takes a
     *                           Pango\Font as its only argument
     *                           and returns a boolean indicating whether the
     *                           font should be returned by the find method.
     */
    public function find(callable $callback): null|Font {}

    /**
     * Returns the font in the FontSet that contains the best glyph for a Unicode character.
     *
     * @param string $letter A Unicode character, a single code point.
     * @throws \ValueError if the string is not a single Unicode character.
     */
    public function getFont(string $letter): Font {}

    /**
     * Returns the font in the FontSet that contains the best glyph for a Unicode code point.
     *
     * @param int $codepoint A Unicode code point.
     */
    public function getFontForCodepoint(int $codepoint): Font {}

    /**
     * Get overall metric information for the fonts in the FontSet.
     */
    public function getMetrics(): FontMetrics {}
}
