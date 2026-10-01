<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
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
     */
    public Analysis $analysis;

    /**
     * Add attributes to this Item.
     *
     * The idea is that you have attributes that don’t affect itemization, such
     * as font features, so you filter them out using
     * Pango\Attribute\AttributeList::filter(), itemize your text, then reapply
     * the attributes to the resulting items using this function.
     *
     * The iter should be positioned before the range of the item, and will be
     * advanced past it. This method is meant to be called in a loop over the
     * items resulting from itemization, while passing the iter to each call.
     */
    public function applyAttributes(
        Attribute\AttributeIterator $iter
    ): void {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 54, 0)
    /**
     * Returns the character offset of the item from the beginning of the itemized text.
     *
     * If the item has not been obtained from Pango’s itemization machinery,
     * then the character offset is not available. In that case, this function
     * returns -1.
     */
    public function getCharOffset(): int {}
#endif

    /**
     * Modifies this item to cover only the text after byteIndex, and
     * returns a new item that covers the text before byteIndex that
     * used to be in this item.
     *
     * One can think of byteIndex as the length of the returned item.
     * byteIndex may not be 0, and it may not be greater than or equal to
     * the length of this item (that is, there must be at least one byte
     * assigned to each item, you can’t create a zero-length item).
     * charOffset is the length of the returned item in chars, and must be
     * provided because the text used to generate the item isn’t available, so
     * Item::split() can’t count the char length of the returned item itself.
     *
     * @param int $byteIndex Byte index of position to split item,
     *                       relative to the start of the item.
     * @param int $charOffset Number of chars between start of this Item and
     *                        byteIndex.
     *
     * @return Item New item representing text before byteIndex.
     */
    public function split(
        int $byteIndex,
        int $charOffset,
    ): Item {}
}
