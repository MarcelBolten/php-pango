<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace PangoCairo;

class Context extends \Pango\Context
{
    /**
     * Creates a context object set up to match the current transformation and target surface of the Cairo context.
     */
    public function __construct(
        \Cairo\Context $context
    ) {}

    /**
     * Gets the Cairo context associated with this PangoCairo\Context.
     */
    public function getCairoContext(): \Cairo\Context {}

    /**
     * Retrieves any font rendering options previously set with setFontOptions().
     */
    public function getFontOptions(): null|\Cairo\FontOptions {}

    /**
     * Sets the font options used when rendering text with this context.
     *
     * These options override any options that updateContext() derives from the target surface.
     *
     * @param null|\Cairo\FontOptions $options The font options to set, or null to clear any previously set options.
     */
    public function setFontOptions(
        null|\Cairo\FontOptions $options
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

    /**
     * Updates this context to match the current transformation and target
     * surface of the Cairo context used to create it.
     *
     * If any layouts have been created for the context, it’s necessary to call
     * PangoCairo\Layout::contextChanged() on those layouts.
     * Todo: should that be done automatically?
     */
    public function updateContext(): void {}
}
