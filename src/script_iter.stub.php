<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

/**
 * ScriptIter is used to iterate through a string and identify ranges in different scripts.
 *
 * @throws \Error When cloned. Instances of Pango\ScriptIter cannot be
 *                cloned because the underlying C PangoScriptIter cannot be
 *                safely duplicated; construct a new instance instead.
 */
final class ScriptIter
{
    /**
     * Create a new ScriptIter, used to break a string of Unicode text into runs by Unicode script.
     */
    public function __construct(
        string $text,
    ) {}

    /**
     * Gets information about the range to which ScriptIter currently points.
     *
     * The range is the set of locations p where start <= p < end.
     * (That is, it doesn’t include the character stored at end)
     */
    public function getRange(): ScriptIterRange {}

    /**
     * Advances a ScriptIter to the next range.
     *
     * @return bool Whether motion was possible, false if already at the last range.
     */
    public function next(): bool {}
}

/**
 * The range is the set of locations p where start <= p < end.
 * (That is, it doesn’t include the character stored at end)
 */
final readonly class ScriptIterRange
{
    /**
     * The text of the range.
     */
    public string $text;

    /**
     * The start byte of the range.
     */
    public int $byteStart;

    /**
     * The end byte of the range, exclusive.
     */
    public int $byteEnd;

    /**
     * The script of the range.
     */
    public Script $script;

    /**
     * @param string $text The text of the range.
     * @param int $byteStart The start byte of the range.
     * @param int $byteEnd The end byte of the range, exclusive.
     * @param Script $script The script of the range.
     */
    public function __construct(
        string $text,
        int $byteStart,
        int $byteEnd,
        Script $script,
    ) {}
}
