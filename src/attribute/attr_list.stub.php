<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Attribute;

/**
 * An AttributeList represents a list of attributes that apply to a section of text.
 */
final class AttributeList
{
    /**
     * Creates a new attribute list from a string representation or an empty attribute list.
     *
     * @param string|null $string The string representation of the attribute list as
     * created by AttributeList::toString(), or NULL for an empty attribute list.
     * @throws \Pango\Exception if the string representation is invalid.
     */
    public function __construct(?string $string = null) {}

    /**
     * @return Attribute[] The list of attributes.
     */
    public function getAttributes(): array {}

    /**
     * Insert the given attribute into the AttributeList.
     *
     * It will replace any attributes of the same type on that segment and be
     * merged with any adjoining attributes that are identical.
     */
    public function change(Attribute $attr): void {}

    /**
     * Removes any elements of list for which callback returns TRUE and inserts
     * them into a new list.
     *
     * @param callable $callback A callback function that takes a
     *                           Pango\Attribute\Attribute as its only argument
     *                           and returns a boolean indicating whether the
     *                           attribute should be removed from the original
     *                           list and added to the new list.
     *
     * @return null|AttributeList The new AttributeList or NULL if no
     *                            attributes of the given types were found.
     */
    public function filter(callable $callback): ?AttributeList {}

    /**
     * Creates an iterator initialized to the beginning of the list.
     */
    public function getIterator(): AttributeIterator {}

    /**
     * Insert the given attribute into this AttributeList after all other attributes
     * with a matching startIndex.
     */
    public function insert(Attribute $attr): void {}

    /**
     * @alias Pango\Attribute\AttributeList::insert
     */
    public function push(Attribute $attr): void {}

    /**
     * Insert the given attribute into this AttributeList before all other attributes
     * with a matching startIndex.
     */
    public function insertBefore(Attribute $attr): void {}

    /** @alias Pango\Attribute\AttributeList::insertBefore */
    public function unshift(Attribute $attr): void {}

    /**
     * This function opens up a hole in this AttributeList, fills it in with attributes
     * from left, and then merges *$other* on top of the hole.
     *
     * This operation is equivalent to stretching every attribute that applies
     * at position *$pos* in this AttributeList by an amount *$length*, and then calling
     * *pango_attr_list_change()* with a copy of each attribute in *$other* in
     * sequence (offset in position by *$pos*, and limited in length to *$length*).
     *
     * This operation proves useful for, for instance, inserting a pre-edit
     * string in the middle of an edit buffer.
     *
     * For backwards compatibility, the function behaves differently when
     * *$length* is 0. In this case, the attributes from *$other* are not
     * limited to *$length*, and are just overlaid on top of this AttributeList.
     *
     * This mode is useful for merging two lists of attributes together.
     */
    public function splice(
        AttributeList $other,
        int $pos,
        int $length,
    ): void {}

    /**
     * Merges the attributes from *$other* into this AttributeList.
     *
     * This operation is equivalent to calling *Pango\AttributeList::splice()* with
     * *$pos* set to 0 and *$length* set to 0.
     */
    public function merge(AttributeList $other): void {}

    /**
     * Serializes this AttributeList to a string.
     *
     * Note that the shape attributes can not be serialized.
     *
     * @since 1.50
     */
    public function toString(): string {}

    /** @alias Pango\Attribute\AttributeList::toString */
    public function serialize(): string {}

    /**
     * Update indices of this AttributeList for a change in the text they refer to.
     *
     * The change that this function applies is removing *$remove* bytes at
     * position *$pos* and inserting *$add* bytes instead.
     */
    public function update(
        int $pos,
        int $remove,
        int $add,
    ): void {}
}
