<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Attribute {

/**
 * The Attribute class represents the common portions of all attributes.
 *
 * Particular types of attributes include this structure as their initial
 * portion.  The common portion of the attribute holds the range to which
 * the value in the type-specific part of the attribute applies.  By default,
 * an attribute will have an all-inclusive range of [0, INDEX_TO_TEXT_END].
 */
abstract readonly class Attribute
{
    /**
     * Value for startIndex that indicates the beginning of the text.
     *
     * @var int
     * @cvalue PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING
     */
    const INDEX_FROM_TEXT_BEGINNING = UNKNOWN;

    /**
     * Value for endIndex that indicates the end of the text.
     *
     * @var int
     * @cvalue PHP_PANGO_ATTR_INDEX_TO_TEXT_END
     */
    const INDEX_TO_TEXT_END = UNKNOWN;

    /**
     * The start index of the range (in bytes).
     */
    public int $startIndex;

    /**
     * End index of the range (in bytes). The character at this index is not included in the range.
     */
    public int $endIndex;

    /**
     * Compare this attribute with another attribute for equality of their values.
     *
     * This compares only the actual value of the two attributes if they are of
     * the same type, and not the ranges that the attributes apply to.
     *
     * @param Attribute $other The other attribute to compare with.
     */
    public function equalValue(Attribute $other): bool {}
}

/**
 * Language is an Attribute that holds a Pango language.
 *
 * It is used for: Type::Language.
 */
final readonly class Language extends Attribute
{
    /**
     * The language.
     */
    public \Pango\Language $value;

    /**
     * Create a new language attribute.
     *
     * @param \Pango\Language $value The language.
     */
    public function __construct(
        \Pango\Language $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Family is an Attribute that holds a font family or a comma-separated list of font families.
 *
 * It is used for: Type::Family.
 */
final readonly class Family extends Attribute
{
    /**
     * The family or comma-separated list of families.
     */
    public string $value;

    /**
     * Create a new font family attribute.
     *
     * @param string $value The family or comma-separated list of families.
     */
    public function __construct(
        string $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Style is an Attribute that holds a font style value.
 *
 * It is used for: Type::Style.
 */
final readonly class Style extends Attribute
{
    /**
     * The font style value.
     */
    public \Pango\Style $value;

    /**
     * Create a new font style attribute.
     *
     * @param \Pango\Style $value The font style value.
     */
    public function __construct(
        \Pango\Style $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Weight is an Attribute that holds a font weight value.
 *
 * It is used for: Type::Weight.
 */
final readonly class Weight extends Attribute
{
    /**
     * The font weight value.
     */
    public \Pango\Weight $value;

    /**
     * Create a new font weight attribute.
     *
     * @param \Pango\Weight $value The font weight value.
     */
    public function __construct(
        \Pango\Weight $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Variant is an Attribute that holds a font variant value.
 *
 * It is used for: Type::Variant.
 */
final readonly class Variant extends Attribute
{
    /**
     * The font variant value.
     */
    public \Pango\Variant $value;

    /**
     * Create a new font variant attribute.
     *
     * @param \Pango\Variant $value The font variant value.
     */
    public function __construct(
        \Pango\Variant $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Stretch is an Attribute that holds a font stretch value.
 *
 * It is used for: Type::Stretch.
 */
final readonly class Stretch extends Attribute
{
    /**
     * The font stretch value.
     */
    public \Pango\Stretch $value;

    /**
     * Create a new font stretch attribute.
     *
     * @param \Pango\Stretch $value The font stretch value.
     */
    public function __construct(
        \Pango\Stretch $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Size is an Attribute that holds a font size in Pango units.
 *
 * It is used for: Type::Size.
 */
final readonly class Size extends Attribute
{
    /**
     * The font size in Pango units (1/PANGO_SCALE points).
     */
    public int $value;

    /**
     * Create a new font size attribute.
     *
     * @param int $value The font size in Pango units.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * AbsoluteSize is an Attribute that holds a font size in device units.
 *
 * It is used for: Type::AbsoluteSize.
 */
final readonly class AbsoluteSize extends Attribute
{
    /**
     * The font size in device units (1/PANGO_SCALE pixels).
     */
    public int $value;

    /**
     * Create a new absolute font size attribute.
     *
     * @param int $value The font size in device units.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * FontDescription is an Attribute that holds a font description.
 *
 * It is used for: Type::FontDescription.
 */
final readonly class FontDescription extends Attribute
{
    /**
     * The font description.
     */
    public \Pango\FontDescription $desc;

    /**
     * Create a new font description attribute.
     *
     * This attribute allows setting all font properties in one step using a
     * FontDescription object.
     *
     * @param \Pango\FontDescription $desc The font description.
     */
    public function __construct(
        \Pango\FontDescription $desc,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Foreground is an Attribute that holds the foreground color.
 *
 * It is used for: Type::Foreground.
 */
final readonly class Foreground extends Attribute
{
    /**
     * The foreground color.
     */
    public \Pango\Color $color;

    /**
     * Create a new foreground color attribute.
     *
     * @param \Pango\Color $color The foreground color.
     */
    public function __construct(
        \Pango\Color $color,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Background is an Attribute that holds the background color.
 *
 * It is used for: Type::Background.
 */
final readonly class Background extends Attribute
{
    /**
     * The background color.
     */
    public \Pango\Color $color;

    /**
     * Create a new background color attribute.
     *
     * @param \Pango\Color $color The background color.
     */
    public function __construct(
        \Pango\Color $color,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Underline is an Attribute that holds an underline style.
 *
 * It is used for: Type::Underline.
 */
final readonly class Underline extends Attribute
{
    /**
     * The underline style value.
     */
    public \Pango\Underline $value;

    /**
     * Create a new underline attribute.
     *
     * @param \Pango\Underline $value The underline style value.
     */
    public function __construct(
        \Pango\Underline $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Strikethrough is an Attribute that holds a strikethrough flag.
 *
 * It is used for: Type::Strikethrough.
 */
final readonly class Strikethrough extends Attribute
{
    /**
     * Whether strikethrough is enabled.
     */
    public bool $value;

    /**
     * Create a new strikethrough attribute.
     *
     * @param bool $value True to enable strikethrough.
     */
    public function __construct(
        bool $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Rise is an Attribute that holds a baseline shift in Pango units.
 *
 * It is used for: Type::Rise.
 */
final readonly class Rise extends Attribute
{
    /**
     * The rise value in Pango units. Positive values shift the baseline up.
     */
    public int $value;

    /**
     * Create a new rise attribute.
     *
     * @param int $value The rise value in Pango units.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

// /**
//  * Shape is an Attribute that holds ink and logical rectangles for a custom glyph shape.
//  *
//  * It is used for: Type::Shape.
//  */
// final readonly class Shape extends Attribute
// {
//     /**
//      * The ink rectangle of the glyph.
//      */
//     public \Pango\Rectangle $inkRect;

//     /**
//      * The logical rectangle of the glyph.
//      */
//     public \Pango\Rectangle $logicalRect;

//     /**
//      * Create a new shape attribute.
//      *
//      * @param \Pango\Rectangle $inkRect The ink rectangle.
//      * @param \Pango\Rectangle $logicalRect The logical rectangle.
//      */
//     public function __construct(\Pango\Rectangle $inkRect, \Pango\Rectangle $logicalRect) {}
// }

/**
 * Scale is an Attribute that holds a font scale factor.
 *
 * It is used for: Type::Scale.
 */
final readonly class Scale extends Attribute
{
    /**
     * The scale factor.
     */
    public float $value;

    /**
     * Create a new scale attribute.
     *
     * @param float $value The scale factor.
     */
    public function __construct(
        float $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Fallback is an Attribute that holds a fallback flag.
 *
 * It is used for: Type::Fallback.
 */
final readonly class Fallback extends Attribute
{
    /**
     * Whether fallback to other fonts is enabled.
     */
    public bool $value;

    /**
     * Create a new fallback attribute.
     *
     * @param bool $value True to enable fallback to other fonts.
     */
    public function __construct(
        bool $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * LetterSpacing is an Attribute that holds extra spacing between graphemes in Pango units.
 *
 * It is used for: Type::LetterSpacing.
 */
final readonly class LetterSpacing extends Attribute
{
    /**
     * The extra letter spacing in Pango units.
     */
    public int $value;

    /**
     * Create a new letter spacing attribute.
     *
     * @param int $value The extra spacing in Pango units.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * UnderlineColor is an Attribute that holds the color of the underline decoration.
 *
 * It is used for: Type::UnderlineColor.
 */
final readonly class UnderlineColor extends Attribute
{
    /**
     * The underline color.
     */
    public \Pango\Color $color;

    /**
     * Create a new underline color attribute.
     *
     * @param \Pango\Color $color The underline color.
     */
    public function __construct(
        \Pango\Color $color,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * StrikethroughColor is an Attribute that holds the color of the strikethrough decoration.
 *
 * It is used for: Type::StrikethroughColor.
 */
final readonly class StrikethroughColor extends Attribute
{
    /**
     * The strikethrough color.
     */
    public \Pango\Color $color;

    /**
     * Create a new strikethrough color attribute.
     *
     * @param \Pango\Color $color The strikethrough color.
     */
    public function __construct(
        \Pango\Color $color,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Gravity is an Attribute that holds a glyph orientation.
 *
 * It is used for: Type::Gravity.
 */
final readonly class Gravity extends Attribute
{
    /**
     * The gravity value.
     */
    public \Pango\Gravity $value;

    /**
     * Create a new gravity attribute.
     *
     * @param \Pango\Gravity $value The gravity value.
     */
    public function __construct(
        \Pango\Gravity $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * GravityHint is an Attribute that holds a gravity hint.
 *
 * It is used for: Type::GravityHint.
 */
final readonly class GravityHint extends Attribute
{
    /**
     * The gravity hint value.
     */
    public \Pango\GravityHint $value;

    /**
     * Create a new gravity hint attribute.
     *
     * @param \Pango\GravityHint $value The gravity hint value.
     */
    public function __construct(
        \Pango\GravityHint $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * FontFeatures is an Attribute that holds OpenType font features.
 *
 * It is used for: Type::FontFeatures.
 */
final readonly class FontFeatures extends Attribute
{
    /**
     * The font features string in CSS format (e.g., "dlig=1, kern=0").
     */
    public string $value;

    /**
     * Create a new font features attribute.
     *
     * @param string $value The font features string.
     */
    public function __construct(
        string $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * ForegroundAlpha is an Attribute that holds the opacity of the foreground color.
 *
 * It is used for: Type::ForegroundAlpha.
 */
final readonly class ForegroundAlpha extends Attribute
{
    /**
     * The alpha value, range 1-65535.
     */
    public int $value;

    /**
     * Create a new foreground alpha attribute.
     *
     * @param int $value The alpha value (1 = nearly transparent, 65535 = opaque).
     * Smaller and larger values wrap around to the valid range.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * BackgroundAlpha is an Attribute that holds the opacity of the background color.
 *
 * It is used for: Type::BackgroundAlpha.
 */
final readonly class BackgroundAlpha extends Attribute
{
    /**
     * The alpha value, range 1-65535.
     */
    public int $value;

    /**
     * Create a new background alpha attribute.
     *
     * @param int $value The alpha value (1 = nearly transparent, 65535 = opaque).
     * Smaller and larger values wrap around to the valid range.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * AllowBreaks is an Attribute that controls whether line breaks are allowed.
 *
 * It is used for: Type::AllowBreaks.
 */
final readonly class AllowBreaks extends Attribute
{
    /**
     * Whether line breaks are allowed.
     */
    public bool $value;

    /**
     * Create a new allow-breaks attribute.
     *
     * @param bool $value True to allow line breaks.
     */
    public function __construct(
        bool $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Show is an Attribute that controls the display of invisible characters.
 *
 * It is used for: Type::Show.
 */
final readonly class Show extends Attribute
{
    /**
     * No special treatment for invisible characters.
     *
     * @var int
     * @cvalue PANGO_SHOW_NONE
     */
    public const NONE = UNKNOWN;

    /**
     * Render spaces, tabs and newlines visibly.
     *
     * @var int
     * @cvalue PANGO_SHOW_SPACES
     */
    public const SPACES = UNKNOWN;

    /**
     * Render line breaks visibly.
     *
     * @var int
     * @cvalue PANGO_SHOW_LINE_BREAKS
     */
    public const LINE_BREAKS = UNKNOWN;

    /**
     * Render default-ignorable Unicode characters visibly.
     *
     * @var int
     * @cvalue PANGO_SHOW_IGNORABLES
     */
    public const IGNORABLES = UNKNOWN;

    /**
     * A combination of Show class constants.
     */
    public int $value;

    /**
     * Create a new show attribute.
     *
     * @param int $value A combination of Show class constants.

     * @throws \ValueError If the value is not a valid combination of Show class constants.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * InsertHyphens is an Attribute that controls automatic hyphen insertion.
 *
 * It is used for: Type::InsertHyphens.
 */
final readonly class InsertHyphens extends Attribute
{
    /**
     * Whether automatic hyphen insertion is enabled.
     */
    public bool $value;

    /**
     * Create a new insert-hyphens attribute.
     *
     * @param bool $value True to enable automatic hyphen insertion.
     */
    public function __construct(
        bool $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Overline is an Attribute that holds an overline style.
 *
 * It is used for: Type::Overline.
 */
final readonly class Overline extends Attribute
{
    /**
     * The overline style value.
     */
    public \Pango\Overline $value;

    /**
     * Create a new overline attribute.
     *
     * @param \Pango\Overline $value The overline style value.
     */
    public function __construct(
        \Pango\Overline $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * OverlineColor is an Attribute that holds the color of the overline decoration.
 *
 * It is used for: Type::OverlineColor.
 */
final readonly class OverlineColor extends Attribute
{
    /**
     * The overline color.
     */
    public \Pango\Color $color;

    /**
     * Create a new overline color attribute.
     *
     * @param \Pango\Color $color The overline color.
     */
    public function __construct(
        \Pango\Color $color,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/**
 * LineHeight is an Attribute that holds a line height scale factor.
 *
 * It is used for: Type::LineHeight.
 */
final readonly class LineHeight extends Attribute
{
    /**
     * The line height scale factor.
     */
    public float $value;

    /**
     * Create a new line height attribute.
     *
     * @param float $value The line height scale factor.
     */
    public function __construct(
        float $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * AbsoluteLineHeight is an Attribute that holds an absolute line height in Pango units.
 *
 * It is used for: Type::AbsoluteLineHeight.
 */
final readonly class AbsoluteLineHeight extends Attribute
{
    /**
     * The absolute line height in Pango units.
     */
    public int $value;

    /**
     * Create a new absolute line height attribute.
     *
     * @param int $value The absolute line height in Pango units.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * TextTransform is an Attribute that holds a text transformation.
 *
 * It is used for: Type::TextTransform.
 */
final readonly class TextTransform extends Attribute
{
    /**
     * The text transform value.
     */
    public \Pango\TextTransform $value;

    /**
     * Create a new text transform attribute.
     *
     * @param \Pango\TextTransform $value The text transform value.
     */
    public function __construct(
        \Pango\TextTransform $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Word is an Attribute that marks word boundaries.
 *
 * It is used for: Type::Word.
 */
final readonly class Word extends Attribute
{
    /**
     * Create a new word boundary attribute.
     */
    public function __construct(
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * Sentence is an Attribute that marks sentence boundaries.
 *
 * It is used for: Type::Sentence.
 */
final readonly class Sentence extends Attribute
{
    /**
     * Create a new sentence boundary attribute.
     */
    public function __construct(
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * BaselineShift is an Attribute that holds a baseline shift.
 *
 * The effect of this attribute is to shift the baseline of a run, relative to the run of preceding run.
 *
 * It is used for: Type::BaselineShift.
 */
final readonly class BaselineShift extends Attribute
{
    /**
     * The baseline shift value.
     */
    public \Pango\BaselineShift|int $value;

    /**
     * Create a new baseline shift attribute.
     *
     * @param \Pango\BaselineShift|int $value Either a Pango\BaselineShift enum
     * value or an absolute value (> 1024) in Pango units, relative to the
     * baseline of the previous run.  Positive values displace the text upwards.
     */
    public function __construct(
        \Pango\BaselineShift|int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}

/**
 * FontScale is an Attribute that holds a font scale.
 *
 * It is used for: Type::FontScale.
 */
final readonly class FontScale extends Attribute
{
    /**
     * The font scale value.
     */
    public \Pango\FontScale $value;

    /**
     * Create a new font scale attribute.
     *
     * @param \Pango\FontScale $value The font scale value.
     */
    public function __construct(
        \Pango\FontScale $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
/**
 * Width is an Attribute that holds a font width.
 *
 * It is used for: Type::Width.
 */
final readonly class Width extends Attribute
{
    /**
     * The font width value.
     */
    public int $value;

    /**
     * Create a new font width attribute.
     *
     * @param int $value The font width value.
     */
    public function __construct(
        int $value,
        int $startIndex = \Pango\Attribute\Attribute::INDEX_FROM_TEXT_BEGINNING,
        int $endIndex = \Pango\Attribute\Attribute::INDEX_TO_TEXT_END
    ) {}
}
#endif

enum AttributeType: int
{
    /**
     *@cvalue PANGO_ATTR_INVALID
     */
     case Invalid = UNKNOWN;

    /**
     *@cvalue PANGO_ATTR_LANGUAGE
     */
    case Language = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FAMILY
     */
    case Family = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_STYLE
     */
    case Style = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_WEIGHT
     */
    case Weight = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_VARIANT
     */
    case Variant = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_STRETCH
     */
    case Stretch = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_SIZE
     */
    case Size = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FONT_DESC
     */
    case FontDesc = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FOREGROUND
     */
    case Foreground = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_BACKGROUND
     */
    case Background = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_UNDERLINE
     */
    case Underline = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_STRIKETHROUGH
     */
    case Strikethrough = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_RISE
     */
    case Rise = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_SHAPE
     */
    case Shape = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_SCALE
     */
    case Scale = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FALLBACK
     */
    case Fallback = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_LETTER_SPACING
     */
    case LetterSpacing = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_UNDERLINE_COLOR
     */
    case UnderlineColor = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_STRIKETHROUGH_COLOR
     */
    case StrikethroughColor = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_ABSOLUTE_SIZE
     */
    case AbsoluteSize = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_GRAVITY
     */
    case Gravity = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_GRAVITY_HINT
     */
    case GravityHint = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FONT_FEATURES
     */
    case FontFeatures = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FOREGROUND_ALPHA
     */
    case ForegroundAlpha = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_BACKGROUND_ALPHA
     */
    case BackgroundAlpha = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_ALLOW_BREAKS
     */
    case AllowBreaks = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_SHOW
     */
    case Show = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_INSERT_HYPHENS
     */
    case InsertHyphens = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_OVERLINE
     */
    case Overline = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_OVERLINE_COLOR
     */
    case OverlineColor = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     *@cvalue PANGO_ATTR_LINE_HEIGHT
    */
    case LineHeight = UNKNOWN;

    /**
     *@cvalue PANGO_ATTR_ABSOLUTE_LINE_HEIGHT
     */
    case AbsoluteLineHeight = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_TEXT_TRANSFORM
     */
    case TextTransform = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_WORD
     */
    case Word = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_SENTENCE
     */
    case Sentence = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_BASELINE_SHIFT
     */
    case BaselineShift = UNKNOWN;

     /**
     *@cvalue PANGO_ATTR_FONT_SCALE
     */
    case FontScale = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    /**
     *@cvalue PANGO_ATTR_WIDTH
     */
    case Width = UNKNOWN;
#endif
}
} // end namespace Pango\Attribute

namespace Pango {

/**
 * The Underline enum is used to specify whether text should be underlined,
 * and if so, the type of underlining.
 */
enum Underline: int
{
    /**
     * No underline should be drawn.
     *
     * @cvalue PANGO_UNDERLINE_NONE
     */
    case None = UNKNOWN;

    /**
     * A single underline should be drawn.
     *
     * @cvalue PANGO_UNDERLINE_SINGLE
     */
    case Single = UNKNOWN;

    /**
     * A double underline should be drawn.
     *
     * @cvalue PANGO_UNDERLINE_DOUBLE
     */
    case Double = UNKNOWN;

    /**
     * A single underline should be drawn at a position beneath the ink extents
     * of the text being underlined.  This should be used only for underlining
     * single characters, such as for keyboard accelerators.
     * Pango\Underline::Single should be used for extended portions of text.
     *
     * @cvalue PANGO_UNDERLINE_LOW
     */
    case Low = UNKNOWN;

    /**
     * An underline indicating an error should be drawn below.  The exact style
     * of rendering is up to the PangoRenderer in use, but typical styles
     * include wavy or dotted lines.  This underline is typically used to
     * indicate an error such as a possible mispelling; in some cases a
     * contrasting color may automatically be used.
     *
     * @cvalue PANGO_UNDERLINE_ERROR
     */
    case Error = UNKNOWN;

    /**
     * Like Pango\Underline::Single, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_SINGLE_LINE
     */
    case SingleLine = UNKNOWN;

    /**
     * Like Pango\Underline::Double, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_DOUBLE_LINE
     */
    case DoubleLine = UNKNOWN;

    /**
     * Like Pango\Underline::Error, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_ERROR_LINE
     */
    case ErrorLine = UNKNOWN;
}

/**
 * The Overline enumeration is used to specify whether text should be
 * overlined, and if so, the type of line.
 */
enum Overline: int
{
    /**
     * No overline should be drawn.
     *
     * @cvalue PANGO_OVERLINE_NONE
     */
    case None = UNKNOWN;

    /**
     * Draw a single line above the ink extents of the text being underlined.
     *
     * @cvalue PANGO_OVERLINE_SINGLE
     */
    case Single = UNKNOWN;
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/**
 * An enumeration that affects how Pango treats characters during shaping.
 */
enum TextTransform: int
{
    /**
     * Leave text unchanged.
     *
     * @cvalue PANGO_TEXT_TRANSFORM_NONE
     */
    case None = UNKNOWN;

    /**
     * Display letters and numbers as lowercase.
     *
     * @cvalue PANGO_TEXT_TRANSFORM_LOWERCASE
     */
    case Lowercase = UNKNOWN;

    /**
     * Display letters and numbers as uppercase.
     *
     * @cvalue PANGO_TEXT_TRANSFORM_UPPERCASE
     */
    case Uppercase = UNKNOWN;

    /**
     * Display the first character of a word in titlecase.
     *
     * @cvalue PANGO_TEXT_TRANSFORM_CAPITALIZE
     */
    case Capitalize = UNKNOWN;
}

/**
 * An enumeration that affects baseline shifts between runs.
 */
enum BaselineShift: int
{
    /**
     * Leave the baseline unchanged.
     *
     * @cvalue PANGO_BASELINE_SHIFT_NONE
     */
    case None = UNKNOWN;

    /**
     * Shift the baseline to the superscript position,
     * relative to the previous run.
     *
     * @cvalue PANGO_BASELINE_SHIFT_SUPERSCRIPT
     */
    case Superscript = UNKNOWN;

    /**
     * Shift the baseline to the subscript position,
     * relative to the previous run.
     *
     * @cvalue PANGO_BASELINE_SHIFT_SUBSCRIPT
     */
    case Subscript = UNKNOWN;
}

/**
 * An enumeration that affects font sizes for superscript and subscript positioning and for (emulated) Small Caps.
 */
enum FontScale: int
{
    /**
     * Leave the font size unchanged.
     *
     * @cvalue PANGO_FONT_SCALE_NONE
     */
    case None = UNKNOWN;

    /**
     * Change the font to a size suitable for superscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUPERSCRIPT
     */
    case Superscript = UNKNOWN;

    /**
     * Change the font to a size suitable for subscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUBSCRIPT
     */
    case Subscript = UNKNOWN;

    /**
     * Change the font to a size suitable for Small Caps.
     *
     * @cvalue PANGO_FONT_SCALE_SMALL_CAPS
     */
    case SmallCaps = UNKNOWN;
}
#endif
} // end namespace Pango
