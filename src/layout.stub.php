<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

/**
 * Layout represents an entire paragraph of text.
 */
class Layout
{
#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Pango's default serialization behavior.
     *
     * @var int
     * @cvalue PANGO_LAYOUT_SERIALIZE_DEFAULT
     */
    public const SERIALIZE_DEFAULT = UNKNOWN;

    /**
     * Include context information.
     *
     * @var int
     * @cvalue PANGO_LAYOUT_SERIALIZE_CONTEXT
     */
    public const SERIALIZE_CONTEXT = UNKNOWN;

    /**
     * Include information about the formatted output.
     *
     * @var int
     * @cvalue PANGO_LAYOUT_SERIALIZE_OUTPUT
     */
    public const SERIALIZE_OUTPUT = UNKNOWN;
#endif

    /**
     * Create a new Layout object with attributes initialized to default values for a given Pango Context.
     */
    public function __construct(
        Context $context
    ) {}

    /**
     * Retrieves the PangoContext used for this layout.
     */
    public function getContext(): Context {}

    /**
     * Sets the text of the layout.
     *
     * This function validates text and renders invalid UTF-8 with a placeholder glyph.
     * Text will be truncated on encountering a null byte.
     */
    public function setText(
        string $text
    ): void {}

    /**
     * Gets the text in the layout.
     *
     * This function returns the text in the layout, or an empty string if the layout is empty.
     */
    public function getText(): string {}

    /**
     * Gets the width to which the lines of the Layout should wrap.
     *
     * @return int The width in Pango units, or -1 if no width set.
     */
    public function getWidth(): int {}

    /**
     * Determines the logical width and height of this Layout in Pango units.
     *
     * This is a convenience method around getExtents().
     *
     * @return array{width: int, height: int} An array with the width and height in Pango units.
     */
    public function getSize(): array {}

    /**
     * Determines the logical width and height of this Layout in device units.
     *
     * This is a convenience method around getPixelExtents().
     *
     * @return array{width: int, height: int} An array with the width and height in Pango units.
     */
    public function getPixelSize(): array {}

    /**
     * Computes the logical and ink extents of this layout.
     *
     * The extents are given in layout coordinates and in Pango units; layout coordinates begin at the top left corner of the layout.
     *
     * @return array{ink: Rectangle, logical: Rectangle} An array with two Rectangle objects, one being the ink extents, the other being the logical extents.
     */
    public function getExtents(): array {}

    /**
     * Computes the logical and ink extents of this layout in device units.
     *
     * This is a convenience method around `getExtents()` which additionally rounds the `Rectangle`s such that the rounded rectangles fully contain the unrounded one. That is, flooring the x/y coordinates and extending width/height.
     *
     * @return array{ink: Rectangle, logical: Rectangle} An array with two Rectangle objects, one being the ink extents, the other being the logical extents.
     */
    public function getPixelExtents(): array {}

    /**
     * Sets the width to which the lines of this Layout should wrap or get ellipsized.
     *
     * @param int $width The desired width in Pango units, or -1 to indicate that no wrapping or ellipsization should be performed.
     */
    public function setWidth(
        int $width
    ): void {}

    /**
     * Gets the height of this Layout used for ellipsization.
     *
     * @return int The height in Pango units if positive, or number of lines if negative. Returns -1 if no height is set.
     */
    public function getHeight(): int {}

    /**
     * Sets the height to which this Layout should be ellipsized at.
     *
     * @param int $height The desired height of this Layout in Pango units if positive, or desired number of lines if negative.
     */
    public function setHeight(
        int $height
    ): void {}

    /**
     * Sets the layout text and attribute list from marked-up text.
     *
     * Visit https://docs.gtk.org/Pango/pango_markup.html#pango-markup for details of the markup format.
     * Replaces the current text and attribute list.
     *
     * Unlike setText, setMarkup does not necessarily truncate the markup on encountering a null byte.
     * However, depending on the location of the null byte the underlying pango markup parser will fail
     * or the text will be truncated.
     */
    public function setMarkup(
        string $markup
    ): void {}

    /**
     * Sets the layout text and attribute list from marked-up text with accelerator markers.
     *
     * Visit https://docs.gtk.org/Pango/pango_markup.html#pango-markup for details of the markup format.
     * Replaces the current text and attribute list.
     *
     * Unlike setText, setMarkupWithAccel does not necessarily truncate the markup on encountering a null byte.
     * However, depending on the location of the null byte the underlying pango markup parser will fail
     * or the text will be truncated.
     *
     * @param string $accelMarker A single-character string used to indicate the accelerator character in the markup.
     *
     * @return string The first character marked by the accelerator character, or an empty string if no accelerator was found.
     */
    public function setMarkupWithAccel(
        string $markup,
        string $accelMarker
    ): string {}

    /**
     * Sets the default FontDescription for this Layout.
     */
    public function setFontDescription(
        FontDescription $desc
    ): void {}

    /**
     * Gets the font description for this Layout, if any.
     *
     * @return null|FontDescription The FontDescription set on this Layout, or NULL if the FontDescription is inherited from the context.
     */
    public function getFontDescription(): null|FontDescription {}

    /**
     * Sets the alignment for the layout: how partial lines are positioned within the horizontal space available.
     */
    public function setAlignment(
        Alignment $alignment
    ): void {}

    /**
     * Gets the alignment for the layout: how partial lines are positioned within the horizontal space available.
     */
    public function getAlignment(): Alignment {}

    /**
     * Sets whether each complete line should be stretched to fill the entire width of the layout.
     */
    public function setJustify(
        bool $justify
    ): void {}

    /**
     * Gets whether each complete line should be stretched to fill the entire width of the layout.
     */
    public function getJustify(): bool {}

    /**
     * Sets the wrap mode.
     *
     * The wrap mode only has effect if a width is set on the layout with setWidth().
     * To turn off wrapping, set the width to -1.
     */
    public function setWrap(
        WrapMode $wrap
    ): void {}

    /**
     * Gets the wrap mode for the layout.
     *
     * Use isWrapped() to query whether any paragraphs were actually wrapped.
     */
    public function getWrap(): WrapMode {}

    /**
     * Queries whether the layout had to wrap any paragraphs.
     */
    public function isWrapped(): bool {}

    /**
     * Sets the width in Pango units to indent each paragraph.
     *
     * A negative value of indent will produce a hanging indentation.
     * That is, the first line will have the full width,
     * and subsequent lines will be indented by the absolute value of indent.
     *
     * The indent setting is ignored if layout alignment is set to Alignment::Center.
     */
    public function setIndent(
        int $indent
    ): void {}

    /**
     * Gets the paragraph indent width in Pango units.
     *
     * A negative value indicates a hanging indentation.
     */
    public function getIndent(): int {}

    /**
     * Sets the amount of spacing in Pango units between the lines of the layout.
     */
    public function setSpacing(
        int $spacing
    ): void {}

    /**
     * Gets the amount of spacing between the lines of the layout in Pango units.
     */
    public function getSpacing(): int {}

    /**
     * Sets the type of ellipsization being performed for Layout.
     */
    public function setEllipsize(
        EllipsizeMode $mode
    ): void {}

    /**
     * Gets the type of ellipsization being performed for layout.
     *
     * Use isEllipsized() to query whether any paragraphs were actually ellipsized.
     */
    public function getEllipsize(): EllipsizeMode {}

    /**
     * Queries whether the layout had to ellipsize any paragraphs.
     */
    public function isEllipsized(): bool {}

    /**
     * Forces recomputation of any state in the Layout that might depend on the layout’s context.
     *
     * This function should be called if changes are made to the context subsequent to creating the layout.
     */
    public function contextChanged(): void {}

    /**
     * Returns the lines of the layout.
     *
     * Use the faster method getLinesReadonly() if you do not plan to modify the contents of the lines.
     *
     * @return LayoutLine[] An array of LayoutLine objects.
     */
    public function getLines(): array {}

    /**
     * Returns the lines of the layout.
     *
     * This is a faster alternative to getLines(), but the user is not expected to modify the contents of the lines.
     *
     * @return LayoutLine[] An array of LayoutLine objects.
     */
    public function getLinesReadonly(): array {}

    /**
     * Retrieves a particular line from a Layout.
     *
     * Use the faster getLineReadonly() if you do not plan to modify the contents of the line.
     *
     * @param int $lineIndex The index of the line to retrieve, between 0 and getLineCount() - 1.
     *
     * @return null|LayoutLine The requested LayoutLine, or NULL if the index is out of range.
     */
    public function getLine(
        int $lineIndex
    ): null|LayoutLine {}

    /**
     * Retrieves a particular line from a Layout.
     *
     * This is a faster alternative to getLine(), but the user is not expected to modify the contents of the line.
     *
     * @return null|LayoutLine The requested LayoutLine, or NULL if the index is out of range.
     */
    public function getLineReadonly(
        int $lineIndex
    ): null|LayoutLine {}

    /**
     * Retrieves the count of lines for the layout.
     */
    public function getLineCount(): int {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Serializes the layout and its attributes to a string. Use only for debugging purposes.
     *
     * @param int $flags A bitwise OR of Pango\Layout::SERIALIZE constants.
     */
    public function serialize(
        int $flags = Pango\Layout::SERIALIZE_DEFAULT
    ): string {}
#endif

    /**
     * Gets the Y position of baseline of the first line in layout.
     *
     * @return int Baseline of first line, from top of layout.
     */
    public function getBaseline(): int {}

    /**
     * Gets whether to calculate the base direction for the layout according to
     * its contents.
     *
     * @return bool True if the bidirectional base direction is computed from
     * the layout’s contents, false otherwise.
     */
    public function getAutoDir(): bool {}

    /**
     * Sets whether to calculate the base direction for the layout according to
     * its contents.
     *
     * When the auto-computed direction of a paragraph differs from the base
     * direction of the context, the interpretation of Pango\Alignment::Left and Pango\Alignment::Right are swapped.
     *
     * @param bool $autoDir If TRUE, compute the bidirectional base direction from the layout’s contents.
     */
    public function setAutoDir(
        bool $autoDir
    ): void {}

    /**
     * Returns the number of Unicode characters in the the text of layout.
     */
    public function getCharacterCount(): int {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
    /**
     * Gets the text direction at the given character position in layout.
     *
     * @param int $byteIndex The byte index of the char.
     */
    public function getDirection(
        int $byteIndex
    ): Direction {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Gets whether the last line should be stretched to fill the entire width of the layout.
     */
    public function getJustifyLastLine(): bool {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Sets whether the last line should be stretched to fill the entire width of the layout.
     *
     * This only has an effect if pango_layout_set_justify() has been called as well.
     *
     * @param bool $justifyLastLine Whether the last line in the layout should be justified.
     */
    public function setJustifyLastLine(
        bool $justifyLastLine
    ): void {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
    /**
     * Gets the line spacing factor of layout.
     */
    public function getLineSpacing(): float {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
    /**
     * Sets a factor for line spacing.
     *
     * If $factor is non-zero, lines are placed so that
     * baseline2 = baseline1 + $factor * height2
     * where height2 is the line height of the second line (as determined by the font(s)).
     * In this case, the spacing set with setSpacing() is ignored.
     *
     * If $factor is zero (the default), spacing is applied as before.
     */
    public function setLineSpacing(
        float $factor
    ): void {}
#endif

    /**
     * Counts the number of unknown glyphs.
     */
    public function getUnknownGlyphsCount(): int {}

    /**
     * Obtains whether layout is in single paragraph mode.
     */
    public function getSingleParagraphMode(): bool {}

    /**
     * Sets the single paragraph mode.
     *
     * If setting is true, do not treat newlines and similar characters as
     * paragraph separators; instead, keep all text in a single paragraph, and
     * display a glyph for paragraph separator characters. Used when you want
     * to allow editing of newlines on a single text line.
     */
    public function setSingleParagraphMode(
        bool $setting
    ): void {}
}

/**
 * Describes how to align the lines of a Layout within the available space.
 *
 * If a Layout is set to justify the alignment only affects partial lines.
 */
enum Alignment: int
{
    /** @cvalue PANGO_ALIGN_LEFT */
    case Left = UNKNOWN;

    /** @cvalue PANGO_ALIGN_CENTER */
    case Center = UNKNOWN;

    /** @cvalue PANGO_ALIGN_RIGHT */
    case Right = UNKNOWN;
}

/**
 * Describes how to wrap the lines of a Layout to the desired width.
 *
 * For Word, Pango uses break opportunities that are determined by the Unicode line breaking algorithm.
 * For Char, Pango allows breaking at grapheme boundaries that are determined by the Unicode text segmentation algorithm.
 */
enum WrapMode: int
{
    /**
     * Wrap lines at word boundaries.
     *
     * @cvalue PANGO_WRAP_WORD
     */
    case Word = UNKNOWN;

    /**
     * Wrap lines at character boundaries.
     *
     * @cvalue PANGO_WRAP_CHAR
     */
    case Char = UNKNOWN;

    /**
     * Wrap lines at word boundaries, but fall back to character boundaries if there is not enough space for a full word.
     *
     * @cvalue PANGO_WRAP_WORD_CHAR
     */
    case WordChar = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
    /**
     * Do not wrap.
     *
     * @cvalue PANGO_WRAP_NONE
     *
     * @since 1.56
     */
    case None = UNKNOWN;
#endif
}

/**
 * Describes what sort of ellipsization should be applied to text.
 *
 * In the ellipsization process characters are removed from the text
 * in order to make it fit to a given width and replaced with an ellipsis.
 */
enum EllipsizeMode: int
{
    /**
     * No ellipsization.
     *
     * @cvalue PANGO_ELLIPSIZE_NONE
     */
    case None = UNKNOWN;

    /**
     * Omit characters at the start of the text.
     *
     * @cvalue PANGO_ELLIPSIZE_START
     */
    case Start = UNKNOWN;

    /**
     * Omit characters in the middle of the text.
     *
     * @cvalue PANGO_ELLIPSIZE_MIDDLE
     */
    case Middle = UNKNOWN;

    /**
     * Omit characters at the end of the text.
     *
     * @cvalue PANGO_ELLIPSIZE_END
     */
    case End = UNKNOWN;
}
