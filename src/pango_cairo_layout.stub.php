<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace PangoCairo;

/**
 * Layout represents an entire paragraph of text.
 */
class Layout extends \Pango\Layout
{
    /**
     * Create a new Layout object with attributes initialized to default values
     * for a given Cairo Context.
     *
     * If the transformation or target surface for the Cairo context changed,
     * updateLayout() has to be called.
     */
    public function __construct(
        \Cairo\Context $context
    ) {}

    /**
     * Adds the text in this Layout to the current path in the specified cairo
     * context.
     *
     * The top-left corner of the Layout will be at the current point of the
     * cairo context.
     */
    public function layoutPath(): void {}

    /**
     * Draws a LayoutLine in the specified cairo context.
     */

    public function showLayout(): void {}

    /**
     * Updates the private Pango Context of this Layout to match the current
     * transformation and target surface of the Cairo context used to create
     * this Layout.
     */
    public function updateLayout(
        \Cairo\Context $context
    ): void {}

    /**
     * Gets the Cairo context associated with this Layout.
     */
    public function getCairoContext(): \Cairo\Context {}
}
