--TEST--
Pango\Attribute\AttributeIterator::getFont()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attrList = new AttributeList(<<<'EOD'
     0  1 size 42
     0  2 absolute-size 43
     0  3 rise 44
     0  4 letter-spacing 45
     0  5 absolute-line-height 46
     0  6 foreground-alpha 47
     0  7 background-alpha 48
     0  8 show 4
     0  9 line-height 50
     0 10 scale 51
     0 11 strikethrough 1
     0 12 fallback 1
    0 13 allow-breaks 1
    0 14 insert-hyphens 1
    0 15 word 1
    0 16 sentence 1
    0 17 family "Arial"
    0 18 font-features "kern=0, liga=0"
    0 19 style italic
    0 20 style 2
    0 21 weight bold
    0 22 weight 700
    0 23 variant small-caps
    0 24 variant 1
    0 25 stretch ultra-condensed
    0 26 stretch 1
    0 27 gravity south
    0 28 gravity 2
    0 29 gravity-hint natural
    0 30 gravity-hint 1
    0 31 overline single
    0 32 overline 1
    0 33 underline double
    0 34 underline 2
    0 35 text-transform uppercase
    0 36 text-transform 1
    0 37 baseline-shift subscript
    0 38 baseline-shift 1
    0 39 width 1024
    0 40 foreground #ffff88881111
    0 41 background firebrick
    0 42 underline-color #ffff88881111
    0 43 strikethrough-color #ffff88881111
    0 44 overline-color #ffff88881111
    0 45 font-scale superscript
    0 46 font-desc "Sans Italic 12"
    0 47 language en
EOD
);
var_dump($attrList);
$attrIter = $attrList->getIterator();
var_dump($attrIter);
$getFontArr = $attrIter->getFont();
var_dump(array_keys($getFontArr));
var_dump($getFontArr['fontDescription']);
var_dump($getFontArr['language']);
var_dump(count($getFontArr['extraAttrs']));

try {
    $attrIter->getFont(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
}
array(3) {
  [0]=>
  string(15) "fontDescription"
  [1]=>
  string(8) "language"
  [2]=>
  string(10) "extraAttrs"
}
object(Pango\FontDescription)#%d (0) {
}
object(Pango\Language)#%d (1) {
  ["string-representation"]=>
  string(2) "en"
}
int(27)
Pango\Attribute\AttributeIterator::getFont() expects exactly 0 arguments, 1 given
