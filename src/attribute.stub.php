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
    public function toString(): string {}
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
 * Instantiate one of the concrete subclasses (e.g., StringAttribute, IntAttribute,
 * Color) to create a specific attribute.
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
 * StringAttribute is an Attribute that holds a string value.
 *
 * It is used for: Type::Family, Type::Language,
 * and (>= 1.38) Type::FontFeatures.
 */
final class StringAttribute extends Attribute
{
    /**
     * The string value of the attribute.
     */
    public string $value;

    /**
     * Create a new string attribute.
     *
     * @param Type $type The attribute type. Must be one of:
     *                   Type::Language, Type::Family,
     *                   or (>= 1.38) Type::FontFeatures.
     * @param string $value The string value.
     */
    public function __construct(Type $type, string $value) {}
}

/**
 * IntAttribute is an Attribute that holds an integer value.
 *
 * It is used for many attribute types including style, weight, underline, rise, etc.
 */
final class IntAttribute extends Attribute
{
    /**
     * The integer value of the attribute.
     */
    public int $value;

    /**
     * Create a new integer attribute.
     *
     * @param Type $type The attribute type. Must be one of the integer-valued
     *                   attribute types (e.g. Type::Style, Type::Weight,
     *                   Type::Underline, Type::Rise, etc.).
     * @param int $value The integer value.
     */
    public function __construct(Type $type, int $value) {}
}

/**
 * FloatAttribute is an Attribute that holds a floating-point value.
 *
 * It is used for: Type::Scale, and (>= 1.50) Type::LineHeight.
 */
final class FloatAttribute extends Attribute
{
    /**
     * The float value of the attribute.
     */
    public float $value;

    /**
     * Create a new float attribute.
     *
     * @param Type $type The attribute type. Must be one of:
     *                   Type::Scale, or (>= 1.50) Type::LineHeight.
     * @param float $value The float value.
     */
    public function __construct(Type $type, float $value) {}
}

/**
 * Color is an Attribute that holds a Color value.
 *
 * It is used for: Type::Foreground, Type::Background,
 * Type::UnderlineColor, Type::StrikethroughColor,
 * and (>= 1.46) Type::OverlineColor.
 */
final class Color extends Attribute
{
    /**
     * The color value of the attribute.
     */
    public \Pango\Color $color;

    /**
     * Create a new color attribute.
     *
     * @param Type $type The attribute type. Must be one of:
     *                   Type::Foreground, Type::Background,
     *                   Type::UnderlineColor, Type::StrikethroughColor,
     *                   or (>= 1.46) Type::OverlineColor.
     * @param int $red Red component, range 0-65535.
     * @param int $green Green component, range 0-65535.
     * @param int $blue Blue component, range 0-65535.
     */
    public function __construct(Type $type, int $red, int $green, int $blue) {}
}

/**
 * Size is an Attribute that holds a font size.
 *
 * It is used for: Type::Size and Type::AbsoluteSize.
 */
final class Size extends Attribute
{
    /**
     * The font size in Pango units.
     */
    public int $value;

    /**
     * Whether this is an absolute size (device units) rather than a scaled size.
     */
    public bool $absolute;

    /**
     * Create a new font-size attribute.
     *
     * @param int $value The font size in Pango units.
     * @param bool $absolute Whether to use absolute (device) units.
     *                       If false, the size is scaled relative to the font's normal size
     *                       (PANGO_ATTR_SIZE). If true, the size is in device units
     *                       (PANGO_ATTR_ABSOLUTE_SIZE).
     */
    public function __construct(int $value, bool $absolute = false) {}
}

/**
 * FontDescription is an Attribute that holds a FontDescription.
 *
 * It is used for: Type::FontDesc.
 */
final class FontDescription extends Attribute
{
    /**
     * The font description.
     */
    public \Pango\FontDescription $desc;

    /**
     * Create a new font-description attribute.
     *
     * This attribute allows setting all font properties in one step using a
     * FontDescription object.
     *
     * @param \Pango\FontDescription $desc The font description.
     */
    public function __construct(\Pango\FontDescription $desc) {}
}

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
