<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
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
    public function getFontDescription(): FontDescription {}

    /**
     * Gets the FontMap used to look up fonts for this context.
     */
    public function getFontMap(): FontMap {}

    public function getGravity(): Gravity {}

    public function getGravityHint(): GravityHint {}

    // Todo: implement Language class
    // public function getLanguage(): Language {}

    public function getMatrix(): Matrix {}

    // Todo: implement Language class
    // public function getMetrics(
    //     FontDescription $desc,
    //     Language $language
    // ): FontMetrics {}

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

    // /**
    //  * Loads the font in one of the fontmaps in the context that is the closest match for desc.
    //  */
    // Todo: implement Font class
    // public function loadFont(
    //     FontDescription $fontDesc
    // ): Font {}

    // /**
    //  * Load a set of fonts in the context that can be used to render a font matching $fontDesc.
    //  */
    // Todo: implement Fontset class
    // public function loadFontset(
    //     FontDescription $fontDesc,
    //     Language $language
    // ): Fontset {}

    /**
     * Sets the base direction for the context.
     */
    public function setBaseDir(
        Direction $direction
    ): void {}

    /**
     * Sets the gravity to be used to lay out the text
     */
    public function setBaseGravity(
        Gravity $gravity
    ): void {}

    /**
     * Set the default font description for the context.
     */
    public function setFontDescription(
        null|FontDescription $desc
    ): void {}

    /**
     * Sets the font map to be searched when fonts are looked-up in this context.
     */
    public function setFontMap(
        null|FontMap $fontmap
    ): void {}

    /**
     * Sets the gravity hint for the context.
     */
    public function setGravityHint(
        GravityHint $hint
    ): void {}

    // /**
    //  * Sets the global language tag for the context.
    //  */
    // public function setLanguage(
    //     null|Language $language
    // ): void {}

    /**
     * Sets the transformation matrix that will be applied when rendering with this context.
     *
     * @param Matrix|null $matrix A Pango\Matrix, or null to unset (set to identity matrix) any existing matrix.
     */
    public function setMatrix(
        null|Matrix $matrix
    ): void {}

    /**
     * Sets whether font rendering with this context should round glyph positions
     * and widths to integral positions, in device units.
     */
    public function setRoundGlyphPositions(
        bool $round
    ): void {}

    /**
     * Gets the resolution for the context.
     *
     * The resolution in “dots per inch”. A negative value will be returned if no resolution has previously been set.
     */
    public function getResolution(): float {}

    /**
     * Sets the resolution for the context.
     *
     * This is a scale factor between points specified in a FontDescription and
     * Cairo units. The default value is 96, meaning that a 10 point font will
     * be 13 units high. (10 * 96. / 72. = 13.3).
     *
     * @param float $dpi The resolution in “dots per inch”.
     *
     * (Physical inches aren’t actually involved; the terminology is conventional.)
     * A 0 or negative value means to use the resolution from the font map.
     */
    public function setResolution(
        float $dpi
    ): void {}
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
 * PangoDirection is only retained because it is used in some public apis.
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
}
