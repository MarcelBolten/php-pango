<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Attribute;

/**
 * AttributeIterator is used to iterate through an AttributeList.
 *
 * This class is not instantiable directly. Use AttributeList::getIterator() to create an instance.
 */
final class AttributeIterator
{
    private function __construct() {}

    /**
     * Find the current attribute of a particular type at the iterator location.
     *
     * When multiple attributes of the same type overlap, the attribute whose
     * range starts closest to the current location is used.
     */
    public function get(AttributeType $type): ?Attribute {}

    /**
     * Gets a list of all attributes at the current position of the iterator.
     *
     * @return Attribute[] The list of attributes.
     */
    public function getAttributes(): array {}

    /**
     * Get the font description and other attributes at the current iterator position.
     *
     * @return array{fontDescription: \Pango\FontDescription, language: null|\Pango\Language, extraAttrs: Attribute[]}
     */
    public function getFont(): array {}

    /**
     * Get the range of the current segment.
     *
     * @return array{start: int, end: int} The start and end of the current attribute range.
     */
    public function getRange(): array {}

    /**
     * Advance the iterator until the next change of style.
     *
     * @return bool Whether the iterator was successfully advanced, false if it has reached the end.
     */
    public function next(): bool {}
}
