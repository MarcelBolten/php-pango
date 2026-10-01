<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango;

final class Language
{
    /**
     * Creates a new Language object from a language tag.
     *
     * The language tag must be in a RFC-3066 format.
     *
     * This function first canonicalizes the string by converting it to
     * lowercase, mapping ‘_’ to ‘-‘, and stripping all characters other than
     * letters and ‘-‘.
     */
    public function __construct(string $language) {}

    /**
     * Returns the Language for the current locale of the process.
     *
     * Your application should call setlocale(LC_ALL, "") for the user settings
     * to take effect.
     */
    public static function getDefault(): Language {}

    /**
     * Returns the list of languages that the user prefers.
     *
     * The list is specified by the PANGO_LANGUAGE or LANGUAGE environment
     * variables, in order of preference.  Note that this list does not
     * necessarily include the language returned by Language::getDefault().
     *
     * @return Language[]
     */
    public static function getPreferred(): array {}

    /**
     * Get a string that is representative of the characters needed to render a
     * particular language.
     */
    public function getSampleString(): string {}

    /**
     * Determines the Scripts used to write the language.
     *
     * If nothing is known about the language tag language then an empty array
     * is returned. The list of scripts returned starts with the script that
     * the language uses most and continues to the one it uses least.
     *
     * @return Script[]
     */
    public function getScripts(): array {}

    /**
     * Determines if script is one of the scripts used to write language.
     *
     * The returned value is conservative; if nothing is known about the
     * language tag language, TRUE will be returned, since, as far as Pango
     * knows, script might be used to write language.
     */
    public function includesScript(Script $script): bool {}

    /**
     * Checks if a language tag matches one of the elements in a list of
     * language ranges.
     *
     * A language tag is considered to match a range in the list if the range
     * is ‘*’, the range is exactly the tag, or the range is a prefix of the
     * tag, and the character after it in the tag is ‘-‘.
     *
     * @param string $languageRange A list of language ranges, separated by
     * ‘;’, ‘:’, ‘,’, or space characters. Each element must either be ‘*’, or
     * a RFC 3066 language range canonicalized as by Language::__construct().
     */
    public function matches(string $languageRange): bool {}

    /**
     * Gets the RFC-3066 format string representing the given language tag.
     */
    public function __toString(): string {}
}
