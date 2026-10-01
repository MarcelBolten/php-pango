<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * @var int
 * @cvalue PANGO_SCALE
 */
const SCALE = UNKNOWN;

/**
 * @var int
 * @cvalue PANGO_VERSION_MAJOR
 */
const VERSION_MAJOR = UNKNOWN;

/**
 * @var int
 * @cvalue PANGO_VERSION_MINOR
 */
const VERSION_MINOR = UNKNOWN;

/**
 * @var int
 * @cvalue PANGO_VERSION_MICRO
 */
const VERSION_MICRO = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
/**
 * No components.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_NONE
 */
const RENDER_COMPONENT_NONE = UNKNOWN;

/**
 * The plain glyphs of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_PLAIN_GLYPH
 */
const RENDER_COMPONENT_PLAIN_GLYPH = UNKNOWN;

/**
 * The color glyphs of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_COLOR_GLYPH
 */
const RENDER_COMPONENT_COLOR_GLYPH = UNKNOWN;

/**
 * Background of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_BACKGROUND
 */
const RENDER_COMPONENT_BACKGROUND = UNKNOWN;

/**
 * Underlines of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_UNDERLINE
 */
const RENDER_COMPONENT_UNDERLINE = UNKNOWN;

/**
 * Strikethrough lines of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_STRIKETHROUGH
 */
const RENDER_COMPONENT_STRIKETHROUGH = UNKNOWN;

/**
 * Overlines of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_OVERLINE
 */
const RENDER_COMPONENT_OVERLINE = UNKNOWN;

/**
 * All components of the layout.
 *
 * @var int
 * @cvalue PANGO_RENDER_COMPONENT_ALL
 */
const RENDER_COMPONENT_ALL = UNKNOWN;
#endif

/**
 * Locates a paragraph boundary in text.
 *
 * A boundary is caused by delimiter characters, such as a newline, carriage
 * return, carriage return-newline pair, or Unicode paragraph separator
 * character.
 *
 * If no delimiters are found, ParagraphBoundary reports the length of text (an
 * index one off the end).
 */
function find_paragraph_boundary(string $text): ParagraphBoundary {}

final readonly class ParagraphBoundary {
    /**
     * The byte index of the run of delimiters.
     */
    public int $delimiterByteIndex;

    /**
     * The byte index of the start of the next paragraph (index after all delimiters).
     */
    public int $nextStart;

    public function __construct(
        int $delimiterByteIndex,
        int $nextStart,
    ) {}
}

/**
 * Returns the encoded version of Pango available at run-time.
 */
function version(): int {}

/**
 * Returns the version of Pango available at run-time.
 */
function version_string(): string {}

/**
 * Checks that the Pango library in use is compatible with the given version.
 *
 * Generally you would pass in the constants Pango\VERSION_MAJOR,
 * Pango\VERSION_MINOR, Pango\VERSION_MICRO as the three arguments to this
 * function; that produces a check that the library in use at run-time is
 * compatible with the version of Pango the application or module was compiled
 * against.
 *
 * Compatibility is defined by two things:
 * - First the version of the running library is newer than the version
 *   required_major.required_minor.required_micro.
 * - Second the running library must be binary compatible with the version
 *   required_major.required_minor.required_micro (same major version.)
 *
 * @return string An empty string if the Pango library is compatible with the
 *                given version, or a string describing the version mismatch.
 */
function version_check(
    int $major = VERSION_MAJOR,
    int $minor = VERSION_MINOR,
    int $micro = VERSION_MICRO,
): string {}

/**
 * Parses marked-up text to create a plain-text string and an attribute list.
 *
 * @param null|string $accelMarker A single-character string used to indicate the accelerator character in the markup.
 */
function parse_markup(
    string $markup,
    ?string $accelMarker = null,
): MarkupParseResult {}

/**
 * Represents the result of Pango\parse_markup().
 */
final readonly class MarkupParseResult {

    public Attribute\AttributeList $attrList;

    public string $text;

    public ?string $accelChar;

    public function __construct(
        Attribute\AttributeList $attrList,
        string $text,
        ?string $accelChar = null,
    ) {}
}

/**
 * Checks if a character should not be normally rendered.
 *
 * This includes all Unicode characters with “ZERO WIDTH” in their name, as
 * well as bidi formatting characters, and a few other ones.
 */
function is_zero_width(string $char): bool {}

/**
 * Return the bidirectional embedding levels of the input paragraph.
 *
 * The bidirectional embedding levels are defined by the Unicode Bidirectional Algorithm.
 *
 * @return int[] An array of embedding levels, one for each character (not byte) in the input text.
 */
function log2vis_get_embedding_levels(
    string $text,
    Direction $baseDirection,
): array {}

/**
 * Reorder items from logical order to visual order.
 *
 * The visual order is determined from the associated directional levels of the items. The original list is unmodified.
 *
 * @param Item[] $items An array of items in logical order.
 *
 * @return Item[] An array of items in visual order.
 */
function reorder_items(array $items): array {}

/**
 * Converts a number in Pango units to floating-point.
 *
 * The conversion is done by dividing units by Pango::SCALE.
 */
function units_to_double(int $units): float {}

/**
 * Converts a floating-point number to Pango units.
 *
 * The conversion is done by multiplying d by Pango::SCALE and rounding the result to nearest integer.
 */
function units_from_double(float $d): int {}

/**
 * Quantizes the thickness and position of a line to whole device pixels.
 *
 * This is typically used for underline or strikethrough. The purpose of
 * this function is to avoid such lines looking blurry.
 *
 * Care is taken to make sure thickness is at least one pixel when this
 * function returns, but returned position may become zero as a result
 * of rounding.
 *
 * @param int $thickness The thickness of the line in Pango units.
 * @param int $position The corresponding position.
 */
function quantize_line_geometry(
    int $thickness,
    int $position,
): QuantizedLineGeometry {}

/**
 * Represents the result of Pango\quantize_line_geometry().
 *
 * Thickness is at least one pixel, but returned position may be zero as a
 * result of rounding.
 */
final readonly class QuantizedLineGeometry
{
    /**
     * The thickness of the line in Pango units.
     */
    public int $thickness;

    /**
     * The position of the line in Pango units.
     */
    public int $position;
}

/**
 * Convert the characters in text into glyphs.
 *
 * Given a segment of text and the corresponding Analysis contained in the Item
 * returned from Context::itemize(), convert the characters into glyphs. One
 * may also pass in only a substring of the item from Context::itemize().
 *
 * It is recommended that you use shape_full() instead, since that API allows
 * for shaping interaction happening across text item boundaries.
 *
 * Some aspects of hyphen insertion and text transformation (in particular,
 * capitalization) require log attrs, and thus can only be handled by
 * shape_item().
 *
 * Note that the extra attributes in the analysis that is returned from
 * Context::itemize() have indices that are relative to the entire paragraph,
 * so one needs to subtract the item offset from their indices before calling
 * shape().
 */
function shape(
    string $text,
    Analysis $analysis,
): GlyphString {}

/**
 * Convert a substring in a paragraph of text into glyphs.
 *
 * Given a paragraph of text, an offset, and a length corresponding to the
 * Analysis contained in an Item returned from Context::itemize(), convert
 * the characters into glyphs.
 *
 * This is similar to shape(), except it will additionally take into account
 * the surrounding text to perform certain cross-item shaping interactions.
 *
 * Some aspects of hyphen insertion and text transformation (in particular,
 * capitalization) require log attrs, and thus can only be handled by
 * shape_item().
 */
function shape_full(
    string $paragraph_text,
    int $offset,
    int $length,
    Analysis $analysis,
): GlyphString {}

/**
 * Convert the characters represented by the item into glyphs.
 *
 * This is similar to shape_with_flags(), except it takes an Item instead of
 * an offset, length, and analysis arguments.
 *
 * It also takes logAttrs, which are needed for implementing some aspects of
 * hyphen insertion and text transforms (in particular, capitalization).
 */
function shape_item(
    string $paragraph_text,
    Item $item,
    ?LogAttrList $logAttrs = null,
    ShapeFlags $flags = ShapeFlags::None,
): GlyphString {}

/**
 * Convert a substring in a paragraph of text into glyphs.
 *
 * Given a paragraph of text, an offset, and a length corresponding to the
 * Analysis contained in an Item returned from Context::itemize(), convert
 * the characters into glyphs.
 *
 * This is similar to shape_full(), except it also takes flags that can
 * influence the shaping process.
 *
 * Some aspects of hyphen insertion and text transformation (in particular,
 * capitalization) require log attrs, and thus can only be handled by
 * shape_item().
 */
function shape_with_flags(
    string $paragraph_text,
    int $offset,
    int $length,
    Analysis $analysis,
    ShapeFlags $flags = ShapeFlags::None,
): GlyphString {}

/**
 * Flags influencing the shaping process.
 *
 * To be used with Pango\shape_with_flags().
 */
enum ShapeFlags: int
{
    /**
     * @cvalue PANGO_SHAPE_NONE
     */
    case None = UNKNOWN;

    /**
     * Round glyph positions and widths to whole device units.
     *
     * This option should be set if the target renderer can’t do subpixel
     * positioning of glyphs.
     *
     * @cvalue PANGO_SHAPE_ROUND_POSITIONS
     */
    case RoundPositions = UNKNOWN;
}
