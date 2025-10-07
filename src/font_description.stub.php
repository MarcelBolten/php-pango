<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
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
    ): void {}

    public function equal(
        FontDescription $fontdesc2
    ): bool {}

    public function setFamily(
        string $family
    ): void {}

    /**
     * Returns the font family name, or an empty string if not set.
     */
    public function getFamily(): string {}

    public function setSize(
        float $size
    ): void {}

    public function getSize(): int {}

    public function getStyle(): Style {}

    public function setStyle(
        Style $style
    ): void {}

    public function getWeight(): Weight {}

    public function setWeight(
        Weight $weight
    ): void {}

    public function getStretch(): Stretch {}

    public function setStretch(
        Stretch $stretch
    ): void {}

    public function toString(): string {}
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
}

enum Style: int
{
    /** @cvalue PANGO_STYLE_NORMAL */
    case Normal = UNKNOWN;

    /** @cvalue PANGO_STYLE_OBLIQUE */
    case Oblique = UNKNOWN;

    /** @cvalue PANGO_STYLE_ITALIC */
    case Italic = UNKNOWN;
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

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 42, 0)
    /**
     * @var int
     * @cvalue PANGO_FONT_MASK_VARIATIONS
     */
    public const VARIATIONS = UNKNOWN;
#endif

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
