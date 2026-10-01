<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * Coverage is a map from Unicode characters to CoverageLevel values.
 */
final class Coverage
{
    /**
     * Create a new Coverage object initialized to CoverageLevel::None.
     */
    public function __construct() {}

    /**
     * Determine whether a particular index is covered by coverage.
     */
    public function get(
        int $index,
    ): CoverageLevel {}

    /**
     * Modify a particular index within coverage.
     */
    public function set(
        int $index,
        CoverageLevel $level,
    ): Coverage {}

}

/**
 * CoverageLevel is used to indicate how well a font can represent a particular
 * Unicode character for a particular script.
 */
enum CoverageLevel: int
{
    /**
     * The character is not representable with the font.
     *
     *@cvalue PANGO_COVERAGE_NONE
    */
    case None = UNKNOWN;

    /**
     * The character is represented as the correct graphical form.
     *
     *@cvalue PANGO_COVERAGE_EXACT
     */
    case Exact = UNKNOWN;

    // Since 1.44, only PANGO_COVERAGE_NONE and PANGO_COVERAGE_EXACT will be returned.

    // /**
    //  * The character is represented in a way that may be comprehensible but is
    //  * not the correct graphical form.
    //  *
    //  *@cvalue PANGO_COVERAGE_FALLBACK
    //  */
    // case Fallback = UNKNOWN;

    // /**
    //  * The character is represented as basically the correct graphical form,
    //  * but with a stylistic variant inappropriate for the current script.
    //  *
    //  *@cvalue PANGO_COVERAGE_APPROXIMATE
    //  */
    // case Approximate = UNKNOWN;
}