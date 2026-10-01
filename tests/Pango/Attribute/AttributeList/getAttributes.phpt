--TEST--
Pango\Attribute\AttributeList::getAttributes()
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;

$attributeList = new AttributeList();
var_dump($attributeList);
var_dump($attributeList->getAttributes());

/**
 * @TODO: the different attribute types are not available in all versions of Pango, so this test may fail on some systems.
 *        The test should be updated to check for the availability of the attribute types before testing them
 */
$attributeList2 = new AttributeList(<<<'EOD'
     0  1 size 42
     1  2 absolute-size 43
     2  3 rise 44
     3  4 letter-spacing 45
     4  5 absolute-line-height 46
     5  6 foreground-alpha 47
     6  7 background-alpha 48
     7  8 show 4
     8  9 line-height 50
     9 10 scale 51
    10 11 strikethrough 1
    11 12 fallback 1
    12 13 allow-breaks 1
    13 14 insert-hyphens 1
    14 15 word 1
    15 16 sentence 1
    16 17 family "Arial"
    17 18 font-features "kern=0, liga=0"
    18 19 style italic
    19 20 style 2
    20 21 weight bold
    21 22 weight 700
    22 23 variant small-caps
    23 24 variant 1
    24 25 stretch ultra-condensed
    25 26 stretch 1
    26 27 gravity south
    27 28 gravity 2
    28 29 gravity-hint natural
    29 30 gravity-hint 1
    30 31 overline single
    31 32 overline 1
    32 33 underline double
    33 34 underline 2
    34 35 text-transform uppercase
    35 36 text-transform 1
    36 37 baseline-shift subscript
    37 38 baseline-shift 1
    38 39 width 1024
    39 40 foreground #ffff88881111
    40 41 background firebrick
    41 42 underline-color #ffff88881111
    42 43 strikethrough-color #ffff88881111
    43 44 overline-color #ffff88881111
    44 45 font-scale superscript
    45 46 font-desc "Sans Italic 12"
    46 47 language en
EOD);
var_dump($attributeList2);
// var_dump($attributeList2->getAttributes());
var_dump(count($attributeList2->getAttributes()));

try {
    $attributeList->getAttributes(123);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Attribute\AttributeList)#%d (0) {
}
array(0) {
}
object(Pango\Attribute\AttributeList)#%d (0) {
}
int(47)
Pango\Attribute\AttributeList::getAttributes() expects exactly 0 arguments, 1 given
