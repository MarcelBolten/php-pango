<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

class FontDescription
{
    /**
     * Creates a new font description
     * optionally from a string representation.
     *
     * The string must have the form
     * [FAMILY-LIST] [STYLE-OPTIONS] [SIZE] [VARIATIONS] [FEATURES]
     * compare to https://docs.gtk.org/Pango/type_func.FontDescription.from_string.html#description
     */
    public function __construct(
        null|string $description = null
    ) {}

    public function getVariant(): Variant {}

    public function setVariant(
        Variant $variant
    ): FontDescription {}

    public function equal(
        FontDescription $fontdesc2
    ): bool {}

    public function setFamily(
        string $family
    ): FontDescription {}

    /**
     * Returns the font family name, or an empty string if not set.
     */
    public function getFamily(): string {}

    public function setSize(
        int $size
    ): FontDescription {}

    public function setAbsoluteSize(
        float $size
    ): FontDescription {}

    public function getSize(): int {}

    /**
     * Determines whether the size of the font is in points (not absolute) or
     * device units (absolute)
     */
    public function getSizeIsAbsolute(): bool {}

    public function getStyle(): Style {}

    public function setStyle(
        Style $style
    ): FontDescription {}

    public function getWeight(): Weight {}

    public function setWeight(
        Weight $weight
    ): FontDescription {}

    public function getStretch(): Stretch {}

    public function setStretch(
        Stretch $stretch
    ): FontDescription {}

    public function toString(): string {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
    public function getFeatures(): string {}

    public function setFeatures(
        null|string $features = null
    ): FontDescription {}
#endif

    public function getGravity(): Gravity {}

    public function setGravity(
        Gravity $gravity
    ): FontDescription {}

    public function getVariations(): string {}

    public function setVariations(
        null|string $variations = null
    ): FontDescription {}

    /**
     * Returns a bitmask of the fields that are set in the font description.
     * The bitmask is a combination of the Pango\FontMask constants.
     */
    public function getSetFields(): int {}

    /**
     * Unsets the fields specified by the given font mask.
     *
     * @param int $fontMask A bitmask of the fields to unset, which is a
     * combination of the Pango\FontMask constants.
     */
    public function unsetFields(int $fontMask): void {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
    public function getColor(): FontColor {}

    public function setColor(
        FontColor $color,
    ): FontDescription {}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    public function getWidth(): Width {}

    public function setWidth(
        Width $width,
    ): FontDescription {}
#endif

    /**
     * Determines if the style attributes of candidate are a closer match for
     * this font description than those of currentBest are,
     * or if currentBest is NULL, determines if candidate is a match at all.
     *
     * Approximate matching is done for weight, width and style; other style
     * attributes must match exactly. Style attributes are all attributes other
     * than family and size-related attributes. Approximate matching for style
     * considers Style::Oblique and Style::Italic as matches, but not
     * as good a match as when the styles are equal.
     *
     * Note that currentBest must match this font description.
     *
     * @param FontDescription $candidate The candidate font description to
     *                                   compare.
     * @param FontDescription|null $currentBest The old font description to
     *                                          compare.
     *
     * @return bool True if candidate is a better match than currentBest,
     *              false otherwise.
     */
    public function betterMatch(
        FontDescription $candidate,
        ?FontDescription $currentBest = null,
    ): bool {}

    /**
     * Merges the fields that are set in other into the fields
     * in this font description.
     *
     * If replaceExisting is FALSE (default), only fields in this
     * font description that are not already set are affected.
     * If TRUE, then fields that are already set will be replaced as well.
     *
     * If other is NULL, this function performs nothing.
     */
    public function merge(
        ?FontDescription $other,
        bool $replaceExisting = false
    ): FontDescription {}
}

enum Variant: int
{
    /** @cvalue PANGO_VARIANT_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_VARIANT_SMALL_CAPS */
    case SmallCaps = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /** @cvalue PANGO_VARIANT_ALL_SMALL_CAPS */
    case AllSmallCaps = UNKNOWN;

    /** @cvalue PANGO_VARIANT_PETITE_CAPS */
    case PetiteCaps = UNKNOWN;

    /** @cvalue PANGO_VARIANT_ALL_PETITE_CAPS */
    case AllPetiteCaps = UNKNOWN;

    /** @cvalue PANGO_VARIANT_UNICASE */
    case Unicase = UNKNOWN;

    /** @cvalue PANGO_VARIANT_TITLE_CAPS */
    case TitleCaps = UNKNOWN;
#endif

    /**
     * Parses a font variant.
     *
     * The allowed values are "normal", "small-caps", "all-small-caps",
     * "petite-caps", "all-petite-caps", "unicase" and "title-caps", case
     * variations being ignored.
     */
    public static function parse(string $string): Variant {}
}

enum Style: int
{
    /** @cvalue PANGO_STYLE_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_STYLE_OBLIQUE */
    case Oblique = UNKNOWN;

    /** @cvalue PANGO_STYLE_ITALIC */
    case Italic = UNKNOWN;

    /**
     * Parses a font style.
     *
     * The allowed values are "normal", "italic" and "oblique", case variations
     * being ignored.
     */
    public static function parse(string $string): Style {}
}

enum Weight: int
{
    /** @cvalue PANGO_WEIGHT_THIN */
    case Thin = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_ULTRALIGHT */
    case UltraLight = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_LIGHT */
    case Light = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_SEMILIGHT */
    case SemiLight = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_BOOK */
    case Book = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_MEDIUM */
    case Medium = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_SEMIBOLD */
    case SemiBold = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_BOLD */
    case Bold = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_ULTRABOLD */
    case UltraBold = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_HEAVY */
    case Heavy = UNKNOWN;

    /** @cvalue PANGO_WEIGHT_ULTRAHEAVY */
    case UltraHeavy = UNKNOWN;

    /**
     * Parses a font weight.
     *
     * The allowed values are "thin", "ultra-light", "extra-light", "light",
     * "semi-light", "demi-light", "book", "normal", "regular", "medium",
     * "semi-bold", "demi-bold", "bold", "ultra-bold", "extra-bold", "heavy",
     * "black", "ultra-heavy", "extra-heavy", "ultra-black", and "extra-black",
     * case variations being ignored.
     */
    public static function parse(string $string): Weight {}
}

enum Stretch: int
{
    /** @cvalue PANGO_STRETCH_ULTRA_CONDENSED */
    case UltraCondensed = UNKNOWN;

    /** @cvalue PANGO_STRETCH_EXTRA_CONDENSED */
    case ExtraCondensed = UNKNOWN;

    /** @cvalue PANGO_STRETCH_CONDENSED */
    case Condensed = UNKNOWN;

    /** @cvalue PANGO_STRETCH_SEMI_CONDENSED */
    case SemiCondensed = UNKNOWN;

    /** @cvalue PANGO_STRETCH_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_STRETCH_SEMI_EXPANDED */
    case SemiExpanded = UNKNOWN;

    /** @cvalue PANGO_STRETCH_EXPANDED */
    case Expanded = UNKNOWN;

    /** @cvalue PANGO_STRETCH_EXTRA_EXPANDED */
    case ExtraExpanded = UNKNOWN;

    /** @cvalue PANGO_STRETCH_ULTRA_EXPANDED */
    case UltraExpanded = UNKNOWN;

    /**
     * Parses a font stretch.
     *
     * The allowed values are "ultra-condensed", "extra-condensed",
     * "condensed", "semi-condensed", "normal", "semi-expanded",
     * "expanded", "extra-expanded", and "ultra-expanded", case variations
     * being ignored.
     */
    public static function parse(string $string): Stretch {}
}

/**
 * FontMask is just a collection of constants
 * and it neither can be instantiated nor extended.
 */
abstract class FontMask
{
    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_FAMILY
     */
    public const FAMILY = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_STYLE
     */
    public const STYLE = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_VARIANT
     */
    public const VARIANT = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_WEIGHT
     */
    public const WEIGHT = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_STRETCH
     */
    public const STRETCH = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_SIZE
     */
    public const SIZE = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_GRAVITY
     */
    public const GRAVITY = UNKNOWN;

    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_VARIATIONS
     */
    public const VARIATIONS = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 56, 0)
    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_FEATURES
     */
    public const FEATURES = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_COLOR
     */
    public const COLOR = UNKNOWN;
#endif
}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 57, 0)
enum FontColor: int
{
    /**
     * The font should not have color glyphs.
     *
     * @cvalue PANGO_FONT_COLOR_FORBIDDEN
     */
    case Forbidden = UNKNOWN;

    /**
     * The font should have color glyphs.
     *
     * @cvalue PANGO_FONT_COLOR_REQUIRED
     */
    case Required = UNKNOWN;

    /**
     * The font may or may not use color.
     *
     * @cvalue PANGO_FONT_COLOR_DONT_CARE
     */
    case DontCare = UNKNOWN;
}
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
/**
 * Specifies the width of the font relative to other designs within a family.
 *
 * The enumeration values match Pango\Stretch, but the numeric values are
 * expanded to allow intermediate values.
 */
enum Width: int
{
    /** @cvalue PANGO_WIDTH_ULTRA_CONDENSED */
    case UltraCondensed = UNKNOWN;

    /** @cvalue PANGO_WIDTH_EXTRA_CONDENSED */
    case ExtraCondensed = UNKNOWN;

    /** @cvalue PANGO_WIDTH_CONDENSED */
    case Condensed = UNKNOWN;

    /** @cvalue PANGO_WIDTH_SEMI_CONDENSED */
    case SemiCondensed = UNKNOWN;

    /** @cvalue PANGO_WIDTH_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_WIDTH_SEMI_EXPANDED */
    case SemiExpanded = UNKNOWN;

    /** @cvalue PANGO_WIDTH_EXPANDED */
    case Expanded = UNKNOWN;

    /** @cvalue PANGO_WIDTH_EXTRA_EXPANDED */
    case ExtraExpanded = UNKNOWN;

    /** @cvalue PANGO_WIDTH_ULTRA_EXPANDED */
    case UltraExpanded = UNKNOWN;
}
#endif
