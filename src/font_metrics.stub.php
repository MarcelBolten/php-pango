<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * FontMetrics holds the overall metric information for a font.
 *
 * The information in FontMetrics may be restricted to a script. The fields of
 * this structure are private to implementations of a font backend. See the
 * documentation of the corresponding getters for documentation of their meaning.
 */
final class FontMetrics
{
    /**
     * Gets the approximate character width.
     *
     * This is merely a representative value useful, for example, for
     * determining the initial size for a window. Actual characters in text
     * will be wider and narrower than this.
     *
     * @return int The approximate character width in Pango units.
     */
    public function getApproximateCharWidth(): int {}

    /**
     * Gets the approximate digit width.
     *
     * This is merely a representative value useful, for example, for
     * determining the initial size for a window.  Actual digits in text will
     * be wider and narrower than this, though this value is generally somewhat
     * more accurate than the result of FontMetrics::getApproximateCharWidth()
     * for digits.
     *
     * @return int The approximate digit width in Pango units.
     */
    public function getApproximateDigitWidth(): int {}

    /**
     * Gets the ascent.
     *
     * The ascent is the distance from the baseline to the logical top of a
     * line of text.  (The logical top may be above or below the top of the
     * actual drawn ink.  It is necessary to lay out the text to figure where
     * the ink will be.).
     *
     * @return int The ascent in Pango units.
     */
    public function getAscent(): int {}

    /**
     * Gets the descent.
     *
     * The descent is the distance from the baseline to the logical bottom of a
     * line of text.  (The logical bottom may be above or below the bottom of
     * the actual drawn ink.  It is necessary to lay out the text to figure
     * where the ink will be.).
     *
     * @return int The descent in Pango units.
     */
    public function getDescent(): int {}

    /**
     * Gets the line height.
     *
     * The line height is the recommended distance between successive baselines
     * in wrapped text using this font.
     *
     * If the line height is not available, 0 is returned.
     *
     * @return int The line height in Pango units.
     */
    public function getHeight(): int {}

    /**
     * Gets the suggested position to draw the strikethrough.
     *
     * The value returned is the distance above the baseline
     * of the top of the strikethrough.
     *
     * @return int The strikethrough position in Pango units.
     */
    public function getStrikethroughPosition(): int {}

    /**
     * Gets the suggested thickness to draw for the strikethrough.
     *
     * @return int The strikethrough thickness in Pango units.
     */
    public function getStrikethroughThickness(): int {}

    /**
     * Gets the suggested position to draw the underline.
     *
     * The value returned is the distance above the baseline of the top of the
     * underline. Since most fonts have underline positions beneath the
     * baseline, this value is typically negative.
     *
     * @return int The underline position in Pango units.
     */
    public function getUnderlinePosition(): int {}

    /**
     * Gets the suggested thickness to draw for the underline.
     *
     * @return int The underline thickness in Pango units.
     */
    public function getUnderlineThickness(): int {}
}
