<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * The Analysis class holds information about the properties of a segment of text.
 */
final readonly class Analysis
{
    /**
     * Whether this run holds ellipsized text.
     *
     * @var int
     * @cvalue PANGO_ANALYSIS_FLAG_IS_ELLIPSIS
     */
    public const FLAG_IS_ELLIPSIS = UNKNOWN;

    /**
     * Whether to add a hyphen at the end of the run during shaping.
     *
     * @var int
     * @cvalue PANGO_ANALYSIS_FLAG_NEED_HYPHEN
     */
    public const FLAG_NEED_HYPHEN = UNKNOWN;

    /**
     * Whether the segment should be shifted to center around the baseline.
     * This is mainly used in vertical writing directions.
     *
     * @var int
     * @cvalue PANGO_ANALYSIS_FLAG_CENTERED_BASELINE
     */
    public const FLAG_CENTERED_BASELINE = UNKNOWN;

    /**
     * The font for this segment.
     */
    public Font $font;

    /**
     * The bidirectional level for this segment.
     */
    public int $level;

    /**
     * The glyph orientation for this segment (A Gravity).
     */
    public Gravity $gravity;

    /**
     * Boolean flags for this segment.
     *
     * @var int $flags A combination of Analysis::FLAG_IS_ELLIPSIS,
     * Analysis::FLAG_NEED_HYPHEN, and Analysis::FLAG_CENTERED_BASELINE
     * constants.
     *
     * The value may contain additional bits that are not part of Pango’s
     * public API. In particular, Pango internally uses bit 7 (0x80) to
     * indicate that the analysis is associated with an internal
     * PangoItemPrivate representation. This bit is an implementation
     * detail and should not be interpreted by applications.
     */
    public int $flags;

    /**
     * The detected script for this segment.
     */
    public Script $script;

    /**
     * The detected language for this segment.
     */
    public Language $language;

    /**
     * Extra attributes for this segment.
     *
     * @var Attribute\Attribute[] $extraAttrs
     */
    public array $extraAttrs;
}
