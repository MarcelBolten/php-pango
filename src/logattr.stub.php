<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * The LogAttr class stores information about the logical attributes
 * of a single character.
 */
final readonly class LogAttr
{
    /**
     * Whether a line break can occur in front of this character.
     */
    public bool $lineBreak;

    /**
     * Whether a line must break in front of this character.
     */
    public bool $mandatoryBreak;

    /**
     * Whether a break can occur here when doing character wrapping
     */
    public bool $charBreak;

    /**
     * Whether this character is a whitespace character.
     */
    public bool $white;

    /**
     * Whether a cursor can appear in front of this character. i.e. this is a
     * grapheme boundary, or the first character in the text. This flag
     * implements Unicode’s Grapheme Cluster Boundaries semantics.
     */
    public bool $cursorPosition;

    /**
     * Whether this character is the first character in a word.
     */
    public bool $wordStart;

    /**
     * Whether this character is the first non-word char after a word.
     *
     * In degenerate cases one could have both $wordStart and $wordEnd
     * set for some character.
     */
    public bool $wordEnd;

    /**
     * Whether this character is a sentence boundary.
     *
     * There are two ways to divide sentences.  The first assigns all
     * inter-sentence whitespace/control/format chars to some sentence, so all
     * chars are in some sentence; $sentenceBoundary denotes the boundaries
     * there.  The second way doesn’t assign between-sentence spaces, etc. to
     * any sentence, so $sentenceStart/$sentenceEnd mark the boundaries of
     * those sentences.
     */
    public bool $sentenceBoundary;

    /**
     * Whether this character is the first character in a sentence.
     */
    public bool $sentenceStart;

    /**
     * Whether this is the first char after a sentence.
     *
     * In degenerate cases, one could have both $sentenceStart and $sentenceEnd
     * set for some character.  (e.g. no space after a period, so the next
     * sentence starts right away).
     */
    public bool $sentenceEnd;

    /**
     * Whether a backspace deletes one character
     * rather than the entire grapheme cluster.
     *
     * This field is only meaningful on grapheme boundaries (where
     * $cursorPosition is true).  In some languages, the full grapheme
     * (e.g. letter + diacritics) is considered a unit, while in others, each
     * decomposed character in the grapheme is a unit.
     */
    //  In the default implementation of pango_break(), this bit is set on all grapheme boundaries except those following Latin, Cyrillic or Greek base characters.
    public bool $backspaceDeletesCharacter;

    /**
     * Whether this character is a whitespace character that can possibly be
     * expanded for justification purposes.
     */
    public bool $expandableSpace;

    /**
     * Whether this character is a word boundary, as defined by UAX#29.
     *
     * More specifically, means that this is not a position in the middle of a
     * word.  For example, both sides of a punctuation mark are considered
     * word boundaries.  This flag is particularly useful when selecting text
     * word-by-word.  This flag implements Unicode’s Word Boundaries semantics.
     */
    public bool $wordBoundary;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Whether to insert a hyphen when breaking lines before this char.
     */
    public bool $breakInsertsHyphen;

    /**
     * Whether to remove the preceding char when breaking lines before this char.
     */
    public bool $breakRemovesPreceding;
#endif
}
