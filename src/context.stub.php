<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Pango;

class Context
{
    // public function __construct(
    //     PangoFontMap $fontmap
    // ) {}

    // public function setFontDescription(
    //     FontDescription $desc
    // ): void {}

    // public function getFontDescription(): FontDescription {}

    /**
     * Sets the gravity to be used to lay out the text
     */
    public function setBaseGravity(
        Gravity $gravity
    ): void {}

    public function getBaseGravity(): Gravity {}

    public function getGravity(): Gravity {}

    public function setGravityHint(
        GravityHint $hint
    ): void {}

    public function getGravityHint(): GravityHint {}
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
    case Weak_LTR = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_WEAK_RTL */
    case Weak_RTL = UNKNOWN;

    /** @cvalue PANGO_DIRECTION_NEUTRAL */
    case Neutral = UNKNOWN;
}
