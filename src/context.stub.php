<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

class Context
{
    public function __construct(
        null|FontMap $fontmap = null
    ) {}

    /**
     * Retrieves the base direction for the context.
     */
    public function getBaseDir(): Direction {}

    public function getBaseGravity(): Gravity {}

    /**
     * Retrieve the default FontDescription for the context.
     */
    public function getFontDescription(): null|FontDescription {}

    /**
     * Gets the FontMap used to look up fonts for this context.
     */
    public function getFontMap(): null|FontMap {}

    public function getGravity(): Gravity {}

    public function getGravityHint(): GravityHint {}

    public function getLanguage(): null|Language {}

    public function getMatrix(): Matrix {}

    /**
     * Get overall metric information for a particular font description.
     *
     * @param FontDescription|null $desc A PangoFontDescription structure. NULL means that the font description from the context will be used.
     * @param Language|null $language Language tag used to determine which script to get the metrics for. NULL means that the language tag from the context will be used. If no language tag is set on the context, metrics for the default language (as determined by Pango\Language::getDefault()) will be returned.
     */
    public function getMetrics(
        null|FontDescription $desc = null,
        null|Language $language = null,
    ): FontMetrics {}

    /**
     * Returns whether font rendering with this context
     * should round glyph positions and widths.
     */
    public function getRoundGlyphPositions(): bool {}

    /**
     * List all families for a context.
     *
     * @return FontFamily[] An array of FontFamily objects
     */
    public function listFamilies(): array {}

    /**
     * Loads the font in one of the FontMaps in the context that is the closest match for desc.
     *
     * @return null|Font The loaded Font, or null if no font matched.
     */
    public function loadFont(
        FontDescription $fontDesc
    ): null|Font {}

    /**
     * Load a set of fonts in the context that can be used to render a font matching $fontDesc.
     *
     * @return null|FontSet The loaded FontSet, or null if no font matched.
     */
    public function loadFontSet(
        FontDescription $fontDesc,
        Language $language
    ): null|FontSet {}

    /**
     * Sets the base direction for the context.
     */
    public function setBaseDir(
        Direction $direction
    ): Context {}

    /**
     * Sets the gravity to be used to lay out the text
     */
    public function setBaseGravity(
        Gravity $gravity
    ): Context {}

    /**
     * Set the default font description for the context.
     */
    public function setFontDescription(
        FontDescription $desc
    ): Context {}

    // /**
    //  * Sets the font map to be searched when fonts are looked-up in this context.
    //  */
    // public function setFontMap(
    //     null|FontMap $fontmap
    // ): void {}

    /**
     * Sets the gravity hint for the context.
     */
    public function setGravityHint(
        GravityHint $hint
    ): Context {}

    /**
     * Sets the global language tag for the context.
     */
    public function setLanguage(
        null|Language $language
    ): Context {}

    /**
     * Sets the transformation matrix that will be applied when rendering with this context.
     *
     * @param Matrix|null $matrix A Pango\Matrix, or null to unset (set to identity matrix) any existing matrix.
     */
    public function setMatrix(
        null|Matrix $matrix
    ): Context {}

    /**
     * Sets whether font rendering with this context should round glyph positions
     * and widths to integral positions, in device units.
     */
    public function setRoundGlyphPositions(
        bool $round
    ): Context {}

    /**
     * Returns the current serial number of Context.
     */
    public function getSerial(): int {}

    /**
     * Breaks a piece of text into segments with consistent directional level
     * and font.
     *
     * Each byte of text will be contained in exactly one of the items in the
     * returned array; the generated array of items will be in logical order
     * (the start offsets of the items are ascending).
     *
     * @return Item[]
     */
    public function itemize(
        string $text,
        int $startByteIndex,
        int $byteLength,
        Attribute\AttributeList $attrs,
        ?Attribute\AttributeIterator $cachedIter = null,
        ?Direction $baseDir = null,
    ): array {}
}

enum Gravity: int
{
    /**
     * Glyphs stand upright (default).
     *
     * @cvalue PANGO_GRAVITY_SOUTH
     */
    case South = UNKNOWN;

    /**
     * Glyphs are rotated 90 degrees counter-clockwise.
     *
     * @cvalue PANGO_GRAVITY_EAST
     */
    case East = UNKNOWN;

    /**
     * Glyphs are upside-down.
     *
     * @cvalue PANGO_GRAVITY_NORTH
     */
    case North = UNKNOWN;

    /**
     * Glyphs are rotated 90 degrees clockwise.
     *
     * @cvalue PANGO_GRAVITY_WEST
     */
    case West = UNKNOWN;

    /**
     * Gravity is resolved from the context matrix.
     *
     * @cvalue PANGO_GRAVITY_AUTO
     */
    case Auto = UNKNOWN;

    /**
     * Converts a Gravity value to its natural rotation in radians.
     *
     * @throws \ValueError If called for Gravity::Auto.
     */
    public function toRotation(): float {}
}

/**
 * GravityHint defines how horizontal scripts should behave in a vertical context.
 */
enum GravityHint: int
{
    /**
     * Scripts will take their natural gravity based on the base gravity and the script. This is the default.
     *
     * @cvalue PANGO_GRAVITY_HINT_NATURAL
     */
    case Natural = UNKNOWN;

    /**
     * Always use the base gravity set, regardless of the script.
     *
     * @cvalue PANGO_GRAVITY_HINT_STRONG
     */
    case Strong = UNKNOWN;

    /**
     * For scripts not in their natural direction (eg. Latin in East gravity),
     * choose per-script gravity such that every script respects the line progression.
     * This means, Latin and Arabic will take opposite gravities and both flow top-to-bottom for example.
     *
     * @cvalue PANGO_GRAVITY_HINT_LINE
     */
    case Line = UNKNOWN;
}

/**
 * PangoDirection represents a direction in the Unicode bidirectional algorithm.
 *
 * If you are interested in text direction, you should really use fribidi directly.
 * Pango\Direction is only retained because it is used in some public apis.
 */
enum Direction: int
{
    /** @cvalue PANGO_DIRECTION_LTR */
    case LTR = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_RTL */
    case RTL = UNKNOWN;

    // no longer used in pango
    // /** @cvalue PANGO_DIRECTION_TTB_LTR */
    // case TTB_LTR = UNKNOWN;

    // no longer used in pango
    // /** @cvalue PANGO_DIRECTION_TTB_RTL */
    // case TTB_RTL = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_WEAK_LTR */
    case WeakLTR = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_WEAK_RTL */
    case WeakRTL = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_NEUTRAL */
    case Neutral = UNKNOWN;

    // seems to be deprecated
    // public static function findBaseDir(string $text): Direction {}
}
