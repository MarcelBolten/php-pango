--TEST--
Pango\Attribute\AbsoluteLineHeight get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeight;

$absoluteLineHeight = new AbsoluteLineHeight(5);
var_dump($absoluteLineHeight);
print_r($absoluteLineHeight);
?>
--EXPECTF--
object(Pango\Attribute\AbsoluteLineHeight)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\AbsoluteLineHeight Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)