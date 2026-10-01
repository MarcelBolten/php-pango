--TEST--
Pango\Attribute\LineHeight get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\LineHeight;

$LineHeight = new LineHeight(5.2);
var_dump($LineHeight);
print_r($LineHeight);
?>
--EXPECTF--
object(Pango\Attribute\LineHeight)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  float(5.2)
}
Pango\Attribute\LineHeight Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5.2
)