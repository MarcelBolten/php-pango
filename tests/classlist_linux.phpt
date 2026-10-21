--TEST--
Pango extension class listing
--EXTENSIONS--
pango
--SKIPIF--
<?php
if (strtolower(PHP_OS_FAMILY) !== 'linux') {
    die('skip - This test is for Linux only');
}
?>
--FILE--
<?php
$ext = new ReflectionExtension('pango');
var_dump($ext->getClassNames());
?>
--EXPECT--
array(107) {
  [0]=>
  string(23) "Pango\MarkupParseResult"
  [1]=>
  string(23) "Pango\ParagraphBoundary"
  [2]=>
  string(27) "Pango\QuantizedLineGeometry"
  [3]=>
  string(16) "Pango\ShapeFlags"
  [4]=>
  string(14) "Pango\Analysis"
  [5]=>
  string(33) "Pango\Attribute\AttributeIterator"
  [6]=>
  string(29) "Pango\Attribute\AttributeList"
  [7]=>
  string(11) "Pango\Color"
  [8]=>
  string(14) "Pango\Coverage"
  [9]=>
  string(19) "Pango\CoverageLevel"
  [10]=>
  string(15) "Pango\Exception"
  [11]=>
  string(21) "Pango\FontDescription"
  [12]=>
  string(11) "Pango\Style"
  [13]=>
  string(12) "Pango\Weight"
  [14]=>
  string(13) "Pango\Variant"
  [15]=>
  string(13) "Pango\Stretch"
  [16]=>
  string(14) "Pango\FontMask"
  [17]=>
  string(15) "Pango\FontColor"
  [18]=>
  string(11) "Pango\Width"
  [19]=>
  string(14) "Pango\FontFace"
  [20]=>
  string(16) "Pango\FontFamily"
  [21]=>
  string(17) "Pango\FontMetrics"
  [22]=>
  string(19) "Pango\GlyphGeometry"
  [23]=>
  string(15) "Pango\GlyphInfo"
  [24]=>
  string(15) "Pango\GlyphItem"
  [25]=>
  string(23) "Pango\GlyphItemIterator"
  [26]=>
  string(26) "Pango\GlyphItemIterInitLoc"
  [27]=>
  string(17) "Pango\GlyphString"
  [28]=>
  string(18) "Pango\GlyphVisAttr"
  [29]=>
  string(10) "Pango\Item"
  [30]=>
  string(14) "Pango\Language"
  [31]=>
  string(16) "Pango\LayoutIter"
  [32]=>
  string(13) "Pango\LogAttr"
  [33]=>
  string(17) "Pango\LogAttrList"
  [34]=>
  string(12) "Pango\Matrix"
  [35]=>
  string(15) "Pango\Rectangle"
  [36]=>
  string(18) "Pango\RoundingMode"
  [37]=>
  string(16) "Pango\ScriptIter"
  [38]=>
  string(12) "Pango\Script"
  [39]=>
  string(21) "Pango\ScriptIterRange"
  [40]=>
  string(13) "Pango\TabStop"
  [41]=>
  string(18) "Pango\TabStopPixel"
  [42]=>
  string(14) "Pango\TabAlign"
  [43]=>
  string(14) "Pango\TabStops"
  [44]=>
  string(25) "Pango\Attribute\Attribute"
  [45]=>
  string(15) "Pango\Underline"
  [46]=>
  string(14) "Pango\Overline"
  [47]=>
  string(19) "Pango\TextTransform"
  [48]=>
  string(19) "Pango\BaselineShift"
  [49]=>
  string(15) "Pango\FontScale"
  [50]=>
  string(29) "Pango\Attribute\AttributeType"
  [51]=>
  string(13) "Pango\Context"
  [52]=>
  string(13) "Pango\Gravity"
  [53]=>
  string(17) "Pango\GravityHint"
  [54]=>
  string(15) "Pango\Direction"
  [55]=>
  string(10) "Pango\Font"
  [56]=>
  string(13) "Pango\FontMap"
  [57]=>
  string(13) "Pango\FontSet"
  [58]=>
  string(16) "Pango\LayoutLine"
  [59]=>
  string(12) "Pango\Layout"
  [60]=>
  string(15) "Pango\Alignment"
  [61]=>
  string(14) "Pango\WrapMode"
  [62]=>
  string(19) "Pango\EllipsizeMode"
  [63]=>
  string(28) "Pango\Attribute\AbsoluteSizeAttribute"
  [64]=>
  string(27) "Pango\Attribute\AllowBreaksAttribute"
  [65]=>
  string(31) "Pango\Attribute\BackgroundAlphaAttribute"
  [66]=>
  string(26) "Pango\Attribute\BackgroundAttribute"
  [67]=>
  string(24) "Pango\Attribute\FallbackAttribute"
  [68]=>
  string(22) "Pango\Attribute\FamilyAttribute"
  [69]=>
  string(31) "Pango\Attribute\FontDescriptionAttribute"
  [70]=>
  string(28) "Pango\Attribute\FontFeaturesAttribute"
  [71]=>
  string(31) "Pango\Attribute\ForegroundAlphaAttribute"
  [72]=>
  string(26) "Pango\Attribute\ForegroundAttribute"
  [73]=>
  string(27) "Pango\Attribute\GravityHintAttribute"
  [74]=>
  string(23) "Pango\Attribute\GravityAttribute"
  [75]=>
  string(29) "Pango\Attribute\InsertHyphensAttribute"
  [76]=>
  string(24) "Pango\Attribute\LanguageAttribute"
  [77]=>
  string(29) "Pango\Attribute\LetterSpacingAttribute"
  [78]=>
  string(29) "Pango\Attribute\OverlineColorAttribute"
  [79]=>
  string(24) "Pango\Attribute\OverlineAttribute"
  [80]=>
  string(20) "Pango\Attribute\RiseAttribute"
  [81]=>
  string(21) "Pango\Attribute\ScaleAttribute"
  [82]=>
  string(20) "Pango\Attribute\ShowAttribute"
  [83]=>
  string(20) "Pango\Attribute\SizeAttribute"
  [84]=>
  string(23) "Pango\Attribute\StretchAttribute"
  [85]=>
  string(34) "Pango\Attribute\StrikethroughColorAttribute"
  [86]=>
  string(29) "Pango\Attribute\StrikethroughAttribute"
  [87]=>
  string(21) "Pango\Attribute\StyleAttribute"
  [88]=>
  string(30) "Pango\Attribute\UnderlineColorAttribute"
  [89]=>
  string(25) "Pango\Attribute\UnderlineAttribute"
  [90]=>
  string(23) "Pango\Attribute\VariantAttribute"
  [91]=>
  string(22) "Pango\Attribute\WeightAttribute"
  [92]=>
  string(34) "Pango\Attribute\AbsoluteLineHeightAttribute"
  [93]=>
  string(29) "Pango\Attribute\BaselineShiftAttribute"
  [94]=>
  string(25) "Pango\Attribute\FontScaleAttribute"
  [95]=>
  string(26) "Pango\Attribute\LineHeightAttribute"
  [96]=>
  string(24) "Pango\Attribute\SentenceAttribute"
  [97]=>
  string(29) "Pango\Attribute\TextTransformAttribute"
  [98]=>
  string(20) "Pango\Attribute\WordAttribute"
  [99]=>
  string(21) "Pango\Attribute\WidthAttribute"
  [100]=>
  string(18) "PangoCairo\Context"
  [101]=>
  string(18) "PangoCairo\FontMap"
  [102]=>
  string(21) "PangoCairo\LayoutLine"
  [103]=>
  string(17) "PangoCairo\Layout"
  [104]=>
  string(19) "Pango\FontSetSimple"
  [105]=>
  string(16) "Pango\Fc\FontMap"
  [106]=>
  string(17) "Pango\Ft2\FontMap"
}
