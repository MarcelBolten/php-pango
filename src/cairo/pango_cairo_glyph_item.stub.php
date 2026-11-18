<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace PangoCairo;

/**
 * GlyphItem is a pair of an Item and the glyphs resulting from shaping the
 * items text.
 *
 * @property-read GlyphString $glyphs
 */
final readonly class GlyphItem extends \Pango\GlyphItem
{
    public \Pango\Item $item;

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
     * Horizontal displacement to apply after th glyph item.
     * Positive values shift right.
     */
    public int $endXOffset;

    /**
     * Draws the glyphs in this GlyphItem in the specified cairo context,
     *
     * embedding the text associated with the glyphs in the output if the
     * output format supports it (PDF for example), otherwise it acts similar
     * to PangoCairo\GlyphString::show().
     *
     * The origin of the glyphs (the left edge of the baseline) will be drawn
     * at the current point of the cairo context.
     *
     * Note that text is the start of the text for layout, which is then
     * indexed by glyph_item->item->offset.
     */
    public function show(
        string $text,
    ): void {}

    /**
     * @return GlyphItem[] An array of resulting GlyphItem objects after
     *                     applying the attributes.
     */
    public function applyAttributes(\Pango\Attribute\AttributeList $list): array {}

    public function split(int $splitByteIndex): ?GlyphItem {}
}
