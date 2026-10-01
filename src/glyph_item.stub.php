<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * GlyphItem is a pair of an Item and the glyphs resulting from shaping the
 * items text.
 */
final readonly class GlyphItem
{
    public Item $item;

    public GlyphString $glyphs;

    /**
     * Shift of the baseline, relative to the baseline of the containing line.
     * Positive values shift upwards.
     */
    public int $yOffset;

    /**
     * Horizontal displacement to apply before the glyph item.
     * Positive values shift right.
     */
    public int $startXOffset;

    /**
     * Horizontal displacement to apply after the glyph item.
     * Positive values shift right.
     */
    public int $endXOffset;

    /**
     * Determine the width corresponding to each character in this glyph item.
     *
     * When multiple characters compose a single cluster, the width of the
     * entire cluster is divided equally among the characters.
     *
     * @return int[] An array of character widths.
     */
    public function getLogicalWidths(): array {}

    /**
     * Splits a shaped item (GlyphItem) into multiple items based on an
     * attribute list.
     *
     * The idea is that if you have attributes that don’t affect shaping, such
     * as color or underline, to avoid affecting shaping, you filter them out
     * (Attribute\AttributeList::filter()), apply the shaping process and then
     * reapply them to the result using this function.
     *
     * All attributes that start or end inside a cluster are applied to that
     * cluster; for instance, if half of a cluster is underlined and the
     * other-half strikethrough, then the cluster will end up with both
     * underline and strikethrough attributes. In these cases, it may happen
     * that item->extra_attrs for some of the result items can have multiple
     * attributes of the same type.
     *
     * @return GlyphItem[] An array of resulting GlyphItem objects after
     *                     applying the attributes.
     */
    public function applyAttributes(Attribute\AttributeList $list): array {}

    /**
     * Adds spacing between the graphemes of glyphItem to give the effect of
     * typographic letter spacing.
     *
     * @param int $spacing Amount of letter spacing to add in Pango units.
     *                     May be negative, though too large negative values
     *                     will give ugly results.
     */
    public function letterSpace(int $spacing): void {}

    /**
     * Modifies this GlyphItem to cover only the text after splitByteIndex, and
     * returns a new GlyphItem that covers the text before splitByteIndex that
     * used to be in the original GlyphItem.
     *
     * You can think of splitByteIndex as the length of the returned item.
     * splitByteIndex may not be 0, and it may not be greater than or equal to
     * the length of this GlyphItem (that is, there must be at least one byte
     * assigned to each item, you can’t create a zero-length item).
     *
     * This function is similar in function to Item::split().
     *
     * @param int $splitByteIndex Byte index of position to split item,
     *                            relative to the start of the item.
     */
    public function split(int $splitByteIndex): ?GlyphItem {}

    /**
     * Get an iterator over the clusters in a GlyphItem.
     *
     * @param GlyphItemIterInitLoc $initialLocation The initial location of
     *                                              the iterator.
     *
     * @return GlyphItemIterator|null The iterator over the clusters, or null
     *                                if the GlyphItem has no clusters.
     */
    public function getGlyphItemIterator(
        GlyphItemIterInitLoc $initialLocation = GlyphItemIterInitLoc::Beginning
    ): ?GlyphItemIterator {}
}

/**
 * Defines the initial location of a GlyphItemIterator.
 */
enum GlyphItemIterInitLoc
{
    /**
     * Initializes a GlyphItemIterator at the first cluster in logical text
     * order of a glyph item.
     */
    case Beginning;

    /**
     * Initializes a GlyphItemIterator at the last cluster in logical text
     * order of a glyph item.
     */
    case End;
}

/**
 * A GlyphItemIter is an iterator over the clusters in a GlyphItem.
 *
 * It can only be obtained via GlyphItem::getGlyphItemIterator() and walked
 * over using any desired mixture of GlyphItemIterator::next() and
 * GlyphItemIterator::prev().
 *
 * The forward direction of the iterator is the logical direction of text. That
 * is, with increasing startIndex and startChar values. If glyphItem is
 * right-to-left (that is, if glyphItem->item->analysis->level is odd), then
 * startGlyph decreases as the iterator moves forward. Moreover, in
 * right-to-left cases, startGlyph is greater than endGlyph.
 *
 * Note that text is the start of the text for layout, which is then indexed by
 * glyphItem->item->offset to get to the text of glyphItem. The startByteIndex
 * and endByteIndex values can directly index into text. The startGlyph, endGlyph,
 * startChar, and endChar values however are zero-based for the glyphItem.
 * For each cluster, the item pointed at by the start variables is included in
 * the cluster while the one pointed at by end variables is not.
 */
final readonly class GlyphItemIterator {

    public GlyphItem $glyphItem;

    public string $text;

    public int $startGlyph;

    public int $startByteIndex;

    public int $startChar;

    public int $endGlyph;

    public int $endByteIndex;

    public int $endChar;

    /**
     * Advances the iterator to the next cluster in the glyph item.
     *
     * @return bool True if the iterator was advanced,
     *              False if it was already on the last cluster.
     */
    public function next(): bool {}

    /**
     * Moves the iterator to the preceding cluster in the glyph item.
     *
     * @return bool True if the iterator was moved,
     *              False if it was already on the first cluster.
     */
    public function prev(): bool {}
}
