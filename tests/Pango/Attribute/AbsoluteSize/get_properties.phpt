--TEST--
Pango\Attribute\AbsoluteSize get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AbsoluteSize;

$absoluteSize = new AbsoluteSize(5);
var_dump($absoluteSize);
print_r($absoluteSize);
?>
--EXPECTF--
object(Pango\Attribute\AbsoluteSize)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\AbsoluteSize Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)