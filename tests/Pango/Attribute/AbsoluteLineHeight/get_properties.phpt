--TEST--
Pango\Attribute\AbsoluteLineHeightAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeightAttribute;

$absoluteLineHeight = new AbsoluteLineHeightAttribute(5);
var_dump($absoluteLineHeight);
print_r($absoluteLineHeight);
?>
--EXPECTF--
object(Pango\Attribute\AbsoluteLineHeightAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\AbsoluteLineHeightAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)