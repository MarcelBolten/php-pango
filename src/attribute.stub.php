<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango {

/**
 * Color represents a color in 16-bit RGB format.
 *
 * Each component value ranges from 0 to 65535.
 */
final readonly class Color
{
    /**
     * Red component, range 0-65535.
     */
    public int $red;

    /**
     * Green component, range 0-65535.
     */
    public int $green;

    /**
     * Blue component, range 0-65535.
     */
    public int $blue;

    /**
     * Create a new color from 16-bit RGB components.
     *
     * @param int $red Red component, range 0-65535.
     * @param int $green Green component, range 0-65535.
     * @param int $blue Blue component, range 0-65535.
     */
    public function __construct(
        int $red,
        int $green,
        int $blue,
    ) {}

    /**
     * Fill in the fields of a color from a string specification.
     *
     * The string can be either one of a large set of standard names (taken from the CSS Color
     * specification), or it can be a hexadecimal value in the form '#rgb', '#rrggbb',
     * '#rrrgggbbb' or '#rrrrggggbbbb', where 'r', 'g' and 'b' are hex digits of the red,
     * green and blue components of the color, respectively.
     *
     * @throws Exception On parse error.
     */
    public static function parse(string $spec): Color {}

    /**
     * Return a textual specification of the color.
     *
     * The string is in the hexadecimal form #rrrrggggbbbb, where r, g and b are hex digits
     * representing the red, green, and blue components respectively.
     */
    public function __toString(): string {}
}

/**
 * Underline describes the type of underline used for decorating text.
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
     * of the text being underlined.
     *
     * This should be used only for underlining single characters, such as for
     * keyboard accelerators. Pango::UNDERLINE_SINGLE should be used for extended
     * portions of text.
     *
     * @cvalue PANGO_UNDERLINE_LOW
     */
    case Low = UNKNOWN;

    /**
     * An underline indicating an error should be drawn below.
     *
     * The exact style of rendering is platform-dependent but it typically looks
     * like a wavy line. It is designed to indicate a misspelling.
     *
     * @cvalue PANGO_UNDERLINE_ERROR
     */
    case Error = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Like Single, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_SINGLE_LINE
     */
    case SingleLine = UNKNOWN;

    /**
     * Like Double, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_DOUBLE_LINE
     */
    case DoubleLine = UNKNOWN;

    /**
     * Like Error, but drawn continuously across multiple runs.
     *
     * @cvalue PANGO_UNDERLINE_ERROR_LINE
     */
    case ErrorLine = UNKNOWN;
#endif
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
/**
 * Overline describes the type of overline used for decorating text.
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
     * Draw a single overline above the ink extents of the text being overlined.
     *
     * @cvalue PANGO_OVERLINE_SINGLE
     */
    case Single = UNKNOWN;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
/**
 * ShowFlags affects how Pango renders characters that are usually invisible in the output.
 *
 * This class is not instantiable.
 */
abstract class ShowFlags
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
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/**
 * BaselineShift describes how the baseline of the text should be shifted.
 */
enum BaselineShift: int
{
    /**
     * Leave the baseline in place.
     *
     * @cvalue PANGO_BASELINE_SHIFT_NONE
     */
    case None = UNKNOWN;

    /**
     * Shift the baseline to the superscript position, relative to the default baseline.
     *
     * @cvalue PANGO_BASELINE_SHIFT_SUPERSCRIPT
     */
    case Superscript = UNKNOWN;

    /**
     * Shift the baseline to the subscript position, relative to the default baseline.
     *
     * @cvalue PANGO_BASELINE_SHIFT_SUBSCRIPT
     */
    case Subscript = UNKNOWN;
}

/**
 * FontScale describes how the scale of the font should be changed relative to the inherited
 * font size.
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
     * Change the font to the size used for superscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUPERSCRIPT
     */
    case Superscript = UNKNOWN;

    /**
     * Change the font to the size used for subscripts.
     *
     * @cvalue PANGO_FONT_SCALE_SUBSCRIPT
     */
    case Subscript = UNKNOWN;

    /**
     * Change the font to the size used for Small Caps.
     *
     * @cvalue PANGO_FONT_SCALE_SMALL_CAPS
     */
    case SmallCaps = UNKNOWN;
}

/**
 * TextTransform describes how text should be transformed during rendering.
 */
enum TextTransform: int
{
    /**
     * No transformation.
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
     * Display the first character of each word in titlecase.
     *
     * @cvalue PANGO_TEXT_TRANSFORM_CAPITALIZE
     */
    case Capitalize = UNKNOWN;
}
#endif

} // namespace Pango

namespace Pango\Attributes {

/**
 * Type distinguishes between different types of Pango text attributes.
 */
enum Type: int
{
    /**
     * @cvalue PANGO_ATTR_INVALID
     */
    case Invalid = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_LANGUAGE
     */
    case Language = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FAMILY
     */
    case Family = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STYLE
     */
    case Style = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_WEIGHT
     */
    case Weight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_VARIANT
     */
    case Variant = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRETCH
     */
    case Stretch = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SIZE
     */
    case Size = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FONT_DESC
     */
    case FontDesc = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FOREGROUND
     */
    case Foreground = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BACKGROUND
     */
    case Background = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_UNDERLINE
     */
    case Underline = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRIKETHROUGH
     */
    case Strikethrough = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_RISE
     */
    case Rise = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SHAPE
     */
    case Shape = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SCALE
     */
    case Scale = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FALLBACK
     */
    case Fallback = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_LETTER_SPACING
     */
    case LetterSpacing = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_UNDERLINE_COLOR
     */
    case UnderlineColor = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRIKETHROUGH_COLOR
     */
    case StrikethroughColor = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_ABSOLUTE_SIZE
     */
    case AbsoluteSize = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_GRAVITY
     */
    case Gravity = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_GRAVITY_HINT
     */
    case GravityHint = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 38, 0)
    /**
     * @cvalue PANGO_ATTR_FONT_FEATURES
     */
    case FontFeatures = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FOREGROUND_ALPHA
     */
    case ForegroundAlpha = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BACKGROUND_ALPHA
     */
    case BackgroundAlpha = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
    /**
     * @cvalue PANGO_ATTR_ALLOW_BREAKS
     */
    case AllowBreaks = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SHOW
     */
    case Show = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_INSERT_HYPHENS
     */
    case InsertHyphens = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
    /**
     * @cvalue PANGO_ATTR_OVERLINE
     */
    case Overline = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_OVERLINE_COLOR
     */
    case OverlineColor = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * @cvalue PANGO_ATTR_LINE_HEIGHT
     */
    case LineHeight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_ABSOLUTE_LINE_HEIGHT
     */
    case AbsoluteLineHeight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_TEXT_TRANSFORM
     */
    case TextTransform = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_WORD
     */
    case Word = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SENTENCE
     */
    case Sentence = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BASELINE_SHIFT
     */
    case BaselineShift = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FONT_SCALE
     */
    case FontScale = UNKNOWN;
#endif
}

/**
 * Attribute is the base class for all Pango text attributes.
 *
 * Attributes are used to modify the rendering of text in a Pango layout.
 * Each attribute applies to a byte range in the text defined by
 * startIndex and endIndex.
 *
 * Instantiate one of the concrete subclasses (e.g., Language, Style,
 * Foreground) to create a specific attribute.
 */
abstract class Attribute
{
    /**
     * The start byte index of the range.
     *
     * 0 is the beginning of the text (PANGO_ATTR_INDEX_FROM_TEXT_BEGINNING).
     */
    public int $startIndex;

    /**
     * The end byte index of the range (exclusive).
     *
     * PHP_INT_MAX means the attribute applies to the end of the text
     * (PANGO_ATTR_INDEX_TO_TEXT_END).
     */
    public int $endIndex;

    /**
     * Returns the type of this attribute.
     */
    public function getType(): Type {}
}

/**
 * Language is an Attribute that holds a Pango language.
 *
 * It is used for: Type::Language.
 */
final class Language extends Attribute
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
    public function __construct(\Pango\Language $value) {}
}

/**
 * Family is an Attribute that holds a font family name.
 *
 * It is used for: Type::Family.
 */
final class Family extends Attribute
{
    /**
     * The font family name.
     */
    public string $value;

    /**
     * Create a new font family attribute.
     *
     * @param string $value The font family name.
     */
    public function __construct(string $value) {}
}

/**
 * Style is an Attribute that holds a font style value.
 *
 * It is used for: Type::Style.
 */
final class Style extends Attribute
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
    public function __construct(\Pango\Style $value) {}
}

/**
 * Weight is an Attribute that holds a font weight value.
 *
 * It is used for: Type::Weight.
 */
final class Weight extends Attribute
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
    public function __construct(\Pango\Weight $value) {}
}

/**
 * Variant is an Attribute that holds a font variant value.
 *
 * It is used for: Type::Variant.
 */
final class Variant extends Attribute
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
    public function __construct(\Pango\Variant $value) {}
}

/**
 * Stretch is an Attribute that holds a font stretch value.
 *
 * It is used for: Type::Stretch.
 */
final class Stretch extends Attribute
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
    public function __construct(\Pango\Stretch $value) {}
}

/**
 * Size is an Attribute that holds a font size in Pango units.
 *
 * It is used for: Type::Size.
 */
final class Size extends Attribute
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
    public function __construct(int $value) {}
}

/**
 * AbsoluteSize is an Attribute that holds a font size in device units.
 *
 * It is used for: Type::AbsoluteSize.
 */
final class AbsoluteSize extends Attribute
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
    public function __construct(int $value) {}
}

/**
 * FontDesc is an Attribute that holds a font description.
 *
 * It is used for: Type::FontDesc.
 */
final class FontDesc extends Attribute
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
    public function __construct(\Pango\FontDescription $desc) {}
}

/**
 * Foreground is an Attribute that holds the foreground color.
 *
 * It is used for: Type::Foreground.
 */
final class Foreground extends Attribute
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
    public function __construct(\Pango\Color $color) {}
}

/**
 * Background is an Attribute that holds the background color.
 *
 * It is used for: Type::Background.
 */
final class Background extends Attribute
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
    public function __construct(\Pango\Color $color) {}
}

/**
 * Underline is an Attribute that holds an underline style.
 *
 * It is used for: Type::Underline.
 */
final class Underline extends Attribute
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
    public function __construct(\Pango\Underline $value) {}
}

/**
 * Strikethrough is an Attribute that holds a strikethrough flag.
 *
 * It is used for: Type::Strikethrough.
 */
final class Strikethrough extends Attribute
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
    public function __construct(bool $value) {}
}

/**
 * Rise is an Attribute that holds a baseline shift in Pango units.
 *
 * It is used for: Type::Rise.
 */
final class Rise extends Attribute
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
    public function __construct(int $value) {}
}

/**
 * Shape is an Attribute that holds ink and logical rectangles for a custom glyph shape.
 *
 * It is used for: Type::Shape.
 */
final class Shape extends Attribute
{
    /**
     * The ink rectangle of the glyph.
     */
    public \Pango\Rectangle $inkRect;

    /**
     * The logical rectangle of the glyph.
     */
    public \Pango\Rectangle $logicalRect;

    /**
     * Create a new shape attribute.
     *
     * @param \Pango\Rectangle $inkRect The ink rectangle.
     * @param \Pango\Rectangle $logicalRect The logical rectangle.
     */
    public function __construct(\Pango\Rectangle $inkRect, \Pango\Rectangle $logicalRect) {}
}

/**
 * Scale is an Attribute that holds a font scale factor.
 *
 * It is used for: Type::Scale.
 */
final class Scale extends Attribute
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
    public function __construct(float $value) {}
}

/**
 * Fallback is an Attribute that holds a fallback flag.
 *
 * It is used for: Type::Fallback.
 */
final class Fallback extends Attribute
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
    public function __construct(bool $value) {}
}

/**
 * LetterSpacing is an Attribute that holds extra spacing between graphemes in Pango units.
 *
 * It is used for: Type::LetterSpacing.
 */
final class LetterSpacing extends Attribute
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
    public function __construct(int $value) {}
}

/**
 * UnderlineColor is an Attribute that holds the color of the underline decoration.
 *
 * It is used for: Type::UnderlineColor.
 */
final class UnderlineColor extends Attribute
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
    public function __construct(\Pango\Color $color) {}
}

/**
 * StrikethroughColor is an Attribute that holds the color of the strikethrough decoration.
 *
 * It is used for: Type::StrikethroughColor.
 */
final class StrikethroughColor extends Attribute
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
    public function __construct(\Pango\Color $color) {}
}

/**
 * Gravity is an Attribute that holds a glyph orientation.
 *
 * It is used for: Type::Gravity.
 */
final class Gravity extends Attribute
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
    public function __construct(\Pango\Gravity $value) {}
}

/**
 * GravityHint is an Attribute that holds a gravity hint.
 *
 * It is used for: Type::GravityHint.
 */
final class GravityHint extends Attribute
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
    public function __construct(\Pango\GravityHint $value) {}
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 38, 0)
/**
 * FontFeatures is an Attribute that holds OpenType font features.
 *
 * It is used for: Type::FontFeatures.
 */
final class FontFeatures extends Attribute
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
    public function __construct(string $value) {}
}

/**
 * ForegroundAlpha is an Attribute that holds the opacity of the foreground color.
 *
 * It is used for: Type::ForegroundAlpha.
 */
final class ForegroundAlpha extends Attribute
{
    /**
     * The alpha value, range 1-65535.
     */
    public int $value;

    /**
     * Create a new foreground alpha attribute.
     *
     * @param int $value The alpha value (1 = nearly transparent, 65535 = opaque).
     */
    public function __construct(int $value) {}
}

/**
 * BackgroundAlpha is an Attribute that holds the opacity of the background color.
 *
 * It is used for: Type::BackgroundAlpha.
 */
final class BackgroundAlpha extends Attribute
{
    /**
     * The alpha value, range 1-65535.
     */
    public int $value;

    /**
     * Create a new background alpha attribute.
     *
     * @param int $value The alpha value (1 = nearly transparent, 65535 = opaque).
     */
    public function __construct(int $value) {}
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
/**
 * AllowBreaks is an Attribute that controls whether line breaks are allowed.
 *
 * It is used for: Type::AllowBreaks.
 */
final class AllowBreaks extends Attribute
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
    public function __construct(bool $value) {}
}

/**
 * Show is an Attribute that controls the display of invisible characters.
 *
 * It is used for: Type::Show.
 */
final class Show extends Attribute
{
    /**
     * A combination of ShowFlags constants.
     */
    public int $value;

    /**
     * Create a new show attribute.
     *
     * @param int $value A combination of ShowFlags constants.
     */
    public function __construct(int $value) {}
}

/**
 * InsertHyphens is an Attribute that controls automatic hyphen insertion.
 *
 * It is used for: Type::InsertHyphens.
 */
final class InsertHyphens extends Attribute
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
    public function __construct(bool $value) {}
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 46, 0)
/**
 * Overline is an Attribute that holds an overline style.
 *
 * It is used for: Type::Overline.
 */
final class Overline extends Attribute
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
    public function __construct(\Pango\Overline $value) {}
}

/**
 * OverlineColor is an Attribute that holds the color of the overline decoration.
 *
 * It is used for: Type::OverlineColor.
 */
final class OverlineColor extends Attribute
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
    public function __construct(\Pango\Color $color) {}
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
/**
 * LineHeight is an Attribute that holds a line height scale factor.
 *
 * It is used for: Type::LineHeight.
 */
final class LineHeight extends Attribute
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
    public function __construct(float $value) {}
}

/**
 * AbsoluteLineHeight is an Attribute that holds an absolute line height in Pango units.
 *
 * It is used for: Type::AbsoluteLineHeight.
 */
final class AbsoluteLineHeight extends Attribute
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
    public function __construct(int $value) {}
}

/**
 * TextTransform is an Attribute that holds a text transformation.
 *
 * It is used for: Type::TextTransform.
 */
final class TextTransform extends Attribute
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
    public function __construct(\Pango\TextTransform $value) {}
}

/**
 * Word is an Attribute that marks word boundaries.
 *
 * It is used for: Type::Word.
 */
final class Word extends Attribute
{
    /**
     * Create a new word boundary attribute.
     */
    public function __construct() {}
}

/**
 * Sentence is an Attribute that marks sentence boundaries.
 *
 * It is used for: Type::Sentence.
 */
final class Sentence extends Attribute
{
    /**
     * Create a new sentence boundary attribute.
     */
    public function __construct() {}
}

/**
 * BaselineShift is an Attribute that holds a baseline shift.
 *
 * It is used for: Type::BaselineShift.
 */
final class BaselineShift extends Attribute
{
    /**
     * The baseline shift value.
     */
    public \Pango\BaselineShift $value;

    /**
     * Create a new baseline shift attribute.
     *
     * @param \Pango\BaselineShift $value The baseline shift value.
     */
    public function __construct(\Pango\BaselineShift $value) {}
}

/**
 * FontScale is an Attribute that holds a font scale.
 *
 * It is used for: Type::FontScale.
 */
final class FontScale extends Attribute
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
    public function __construct(\Pango\FontScale $value) {}
}
#endif

/**
 * AttributeList represents a list of attributes (PangoAttrList) that apply to a section of text.
 *
 * The attributes in an AttributeList are of the type Attribute. The list is meant to be used
 * with the Layout class.
 */
class AttributeList
{
    /**
     * Create a new empty attribute list.
     */
    public function __construct() {}

    /**
     * Insert the given attribute into the AttributeList.
     *
     * It will be inserted after all other attributes with a matching startIndex.
     *
     * @param Attribute $attr The attribute to insert.
     */
    public function insert(Attribute $attr): void {}

    /**
     * Insert the given attribute into the AttributeList.
     *
     * It will be inserted before all other attributes with a matching startIndex.
     *
     * @param Attribute $attr The attribute to insert.
     */
    public function insertBefore(Attribute $attr): void {}

    /**
     * Insert the given attribute into the AttributeList.
     *
     * It will replace any attributes of the same type on that segment and be merged
     * with any adjoining attributes that are identical.
     *
     * This function is slower than insert() for creating an attribute list in order
     * (potentially much slower for large lists). However, insertBefore() and insert()
     * don't perform the equivalent of this function.
     *
     * @param Attribute $attr The attribute to insert.
     */
    public function change(Attribute $attr): void {}

    /**
     * Gets a list of all attributes in the AttributeList.
     *
     * @return Attribute[] An array of Attribute objects.
     */
    public function getAttributes(): array {}

    /**
     * Checks whether this list and $other contain the same attributes and whether
     * those attributes apply to the same ranges.
     *
     * Beware that this will return wrong values if any list contains duplicates.
     */
    public function equal(AttributeList $other): bool {}

    /**
     * Splice the given attributes from $other into this list.
     *
     * The splice point is specified by $pos and $len. Attributes in $other are
     * adjusted to apply to the new range. Attributes in this list that overlap
     * the range [$pos, $pos + $len) are adjusted accordingly.
     *
     * @param AttributeList $other The AttributeList to splice into this list.
     * @param int $pos The position in this list at which to insert other.
     * @param int $len The length of the spliced segment. This may be different from the
     *                 length of other in most cases.
     */
    public function splice(AttributeList $other, int $pos, int $len): void {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 44, 0)
    /**
     * Update indices of attributes in this list for a change in the text they refer to.
     *
     * The change that this function applies is removing $remove characters starting at
     * $pos and inserting $add characters instead.
     *
     * Attributes that fall entirely in the ($pos, $pos + $remove) range are removed.
     * Attributes that start or end inside the ($pos, $pos + $remove) range are shortened
     * to reflect the removal. Attributes start and end positions are updated if they are
     * behind $pos + $remove.
     *
     * @param int $pos The start of the change.
     * @param int $remove The number of removed characters.
     * @param int $add The number of added characters.
     */
    public function update(int $pos, int $remove, int $add): void {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * Serialize this list to a string.
     *
     * No guarantees are made about the format of the resulting string; it may change
     * between Pango versions.
     *
     * The output format is the one that is used by fromString() and by the Pango text
     * attribute language for attributes in Pango markup.
     */
    public function toString(): string {}

    /**
     * Deserialize an AttributeList from a string.
     *
     * The format is the one that is used by toString() and the Pango text attribute
     * language for attributes in Pango markup.
     *
     * @return AttributeList|null The deserialized AttributeList, or NULL if parsing failed.
     */
    public static function fromString(string $text): null|AttributeList {}
#endif
}

} // namespace Pango\Attributes
