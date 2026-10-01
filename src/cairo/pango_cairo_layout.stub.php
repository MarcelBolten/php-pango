<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace PangoCairo;

/**
 * Layout represents an entire paragraph of text.
 */
final class Layout extends \Pango\Layout
{
    /**
     * Create a new Layout object with attributes initialized to default values
     * for a given Cairo Context.
     *
     * If the transformation or target surface for the Cairo context changed,
     * update() has to be called.
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
    public function path(): void {}

    /**
     * Draws a LayoutLine in the specified cairo context.
     */

    public function show(): void {}

    /**
     * Updates the private Pango Context of this Layout to match the current
     * transformation and target surface of the Cairo context used to create
     * this Layout.
     */
    public function update(): void {}

    /**
     * Gets the Cairo context associated with this Layout.
     */
    public function getCairoContext(): \Cairo\Context {}

    // public function getLineReadonly(int $lineIndex): ?LayoutLine {}
    // public function getLine(int $lineIndex): ?LayoutLine {}

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    /**
     * Adds components of this Layout to the current path in the specified
     * cairo context.
     *
     * The top-left corner of the Layout will be at the current point of the
     * cairo context.
     *
     * @param int $component The component to add to the path.
     *                       See Pango::RENDER_COMPONENT_* constants.
     */
    public function layoutPathForComponents(int $component): void {}
#endif

    /**
     * Returns the lines of the layout.
     *
     * Use the faster method getLinesReadonly() if you do not plan to modify the contents of the lines.
     *
     * @return LayoutLine[] An array of LayoutLine objects.
     */
    public function getLines(): array {}

    /**
     * Returns the lines of the layout.
     *
     * This is a faster alternative to getLines(), but the user is not expected to modify the contents of the lines.
     *
     * @return LayoutLine[] An array of LayoutLine objects.
     */
    public function getLinesReadonly(): array {}

    /**
     * Retrieves a particular line from a Layout.
     *
     * Use the faster getLineReadonly() if you do not plan to modify the contents of the line.
     *
     * @param int $lineIndex The index of the line to retrieve, between 0 and getLineCount() - 1.
     *
     * @return null|LayoutLine The requested LayoutLine, or NULL if the index is out of range.
     */
    public function getLine(
        int $lineIndex
    ): null|LayoutLine {}

    /**
     * Retrieves a particular line from a Layout.
     *
     * This is a faster alternative to getLine(), but the user is not expected to modify the contents of the line.
     *
     * @return null|LayoutLine The requested LayoutLine, or NULL if the index is out of range.
     */
    public function getLineReadonly(
        int $lineIndex
    ): null|LayoutLine {}
}
