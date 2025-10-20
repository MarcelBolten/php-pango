--TEST--
Pango extension class listing
--SKIPIF--
<?php
include __DIR__ . '/skipif.php.inc';
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
array(30) {
  [0]=>
  string(11) "Pango\Pango"
  [1]=>
  string(15) "Pango\Exception"
  [2]=>
  string(13) "Pango\Context"
  [3]=>
  string(13) "Pango\Gravity"
  [4]=>
  string(17) "Pango\GravityHint"
  [5]=>
  string(15) "Pango\Direction"
  [6]=>
  string(12) "Pango\Layout"
  [7]=>
  string(15) "Pango\Alignment"
  [8]=>
  string(14) "Pango\WrapMode"
  [9]=>
  string(19) "Pango\EllipsizeMode"
  [10]=>
  string(21) "Pango\FontDescription"
  [11]=>
  string(11) "Pango\Style"
  [12]=>
  string(12) "Pango\Weight"
  [13]=>
  string(13) "Pango\Variant"
  [14]=>
  string(13) "Pango\Stretch"
  [15]=>
  string(14) "Pango\FontMask"
  [16]=>
  string(16) "Pango\LayoutLine"
  [17]=>
  string(15) "Pango\GlyphItem"
  [18]=>
  string(10) "Pango\Item"
  [19]=>
  string(17) "Pango\GlyphString"
  [20]=>
  string(15) "Pango\GlyphInfo"
  [21]=>
  string(12) "Pango\Matrix"
  [22]=>
  string(15) "Pango\Rectangle"
  [23]=>
  string(18) "Pango\RoundingMode"
  [24]=>
  string(13) "Pango\FontMap"
  [25]=>
  string(18) "PangoCairo\FontMap"
  [26]=>
  string(16) "Pango\FontFamily"
  [27]=>
  string(14) "Pango\FontFace"
  [28]=>
  string(17) "PangoCairo\Layout"
  [29]=>
  string(18) "PangoCairo\Context"
}
