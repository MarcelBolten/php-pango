<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * LogAttrList contains one LogAttr for each character in a given text,
 * plus one extra at the end of the text.
 *
 * Use either the high-level paragraph analysis, default constructor,
 * or the lower-level explicit breaking pipeline
 * LogAttrList::defaultBreak()->tailorBreak()->attrBreak().
 */
final readonly class LogAttrList implements \Countable, \IteratorAggregate
{
    public string $text;

    /**
     * Wraps defaultBreak(), and tailorBreak() in one call.
     *
     * Text should be an entire paragraph; logical attributes can’t be computed
     * without context (for example you need to see spaces on either side of a
     * word to know the word is a word).
     *
     * @param string $text The text to analyze.
     *
     * @param Language|null $language The language of the text, or null to use
     *                                the default language.
     *
     * @param int|null $level The embedding level, a numerical value assigned
     *                        to each character that determines its layout
     *                        direction under the Unicode Bidirectional
     *                        Algorithm (UBA), of the text, or -1 if unknown.
     */
    public function __construct(
        string $text,
        ?Language $language = null,
        ?int $level = -1,
    ) {}

    /**
     * This is the default break algorithm.
     *
     * It applies rules from the Unicode Line Breaking Algorithm without
     * language-specific tailoring.
     *
     * Use tailorBreak() consecutively for language-specific breaks.
     * Use attrBreak() consecutively for attribute-based customization.
     */
    public static function defaultBreak(string $text): LogAttrList {}

    /**
     * Apply language-specific tailoring to the breaks.
     *
     * The line breaks are assumed to have been produced by defaultBreak().
     *
     * If offset is not -1, it is used to apply attributes from analysis that are
     * relevant to line breaking.
     *
     * Note that it is better to pass -1 for offset and use attrBreak() to
     * apply attributes to the whole paragraph.
     *
     * @param int $byteOffset Byte offset of text from the beginning of the
     *                        paragraph, or -1 to ignore attributes from analysis.
     */
    public function tailorBreak(
        null|Analysis $analysis = null,
        int $byteOffset = -1,
    ): LogAttrList {}

    /**
     * Apply customization from attributes to the breaks.
     *
     * The line breaks are assumed to have been produced by defaultBreak() and tailorBreak().
     */
    public function attrBreak(
        Attribute\AttributeList $attrList,
        int $byteOffset = 0,
    ): LogAttrList {}

    public function count(): int {}

    public function get(int $byteIndex): LogAttr {}

    /**
     * Returns all the attributes in the list.
    *
    * @return LogAttr[]
    */
    public function getAttributes(): array {}

    public function getIterator(): \Traversable {}
}
