<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80200
 */

namespace Pango\Attribute;

/**
 * The Type distinguishes between different types of attributes.
 *
 * Along with the predefined values, it is possible to allocate additional
 * values for custom attributes using pango_attr_type_register(). The
 * predefined values are given below. The type of structure used to store the
 * attribute is listed in parentheses after the description.
 */
enum Type: int
{
    /**
     * @cvalue PANGO_ATTR_INVALID
     */
    case Invalid = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_LANGUAGE
     */
    case Language = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FAMILY
     */
    case Family = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STYLE
     */
    case Style = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_WEIGHT
     */
    case Weight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_VARIANT
     */
    case Variant = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRETCH
     */
    case Stretch = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SIZE
     */
    case Size = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FONT_DESC
     */
    case FontDesc = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FOREGROUND
     */
    case Foreground = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BACKGROUND
     */
    case Background = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_UNDERLINE
     */
    case Underline = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRIKETHROUGH
     */
    case Strikethrough = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_RISE
     */
    case Rise = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SHAPE
     */
    case Shape = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SCALE
     */
    case Scale = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FALLBACK
     */
    case Fallback = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_LETTER_SPACING
     */
    case LetterSpacing = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_UNDERLINE_COLOR
     */
    case UnderlineColor = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_STRIKETHROUGH_COLOR
     */
    case StrikethroughColor = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_ABSOLUTE_SIZE
     */
    case AbsoluteSize = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_GRAVITY
     */
    case Gravity = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_GRAVITY_HINT
     */
    case GravityHint = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FONT_FEATURES
     */
    case FontFeatures = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FOREGROUND_ALPHA
     */
    case ForegroundAlpha = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BACKGROUND_ALPHA
     */
    case BackgroundAlpha = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_ALLOW_BREAKS
     */
    case AllowBreaks = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SHOW
     */
    case Show = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_INSERT_HYPHENS
     */
    case InsertHyphens = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_OVERLINE
     */
    case Overline = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_OVERLINE_COLOR
     */
    case OverlineColor = UNKNOWN;

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 50, 0)
    /**
     * @cvalue PANGO_ATTR_LINE_HEIGHT
     */
    case LineHeight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_ABSOLUTE_LINE_HEIGHT
     */
    case AbsoluteLineHeight = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_TEXT_TRANSFORM
     */
    case TextTransform = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_WORD
     */
    case Word = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_SENTENCE
     */
    case Sentence = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_BASELINE_SHIFT
     */
    case BaselineShift = UNKNOWN;

    /**
     * @cvalue PANGO_ATTR_FONT_SCALE
     */
    case FontScale = UNKNOWN;
#endif

#if PANGO_VERSION >= PANGO_VERSION_ENCODE(1, 58, 0)
    /**
     * @cvalue PANGO_ATTR_WIDTH
     */
    case Width = UNKNOWN;
#endif
}
