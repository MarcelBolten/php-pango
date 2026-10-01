--TEST--
Pango\Attribute\Width get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(10240);
var_dump($width);
print_r($width);
?>
--EXPECTF--
object(Pango\Attribute\Width)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(10240)
}
Pango\Attribute\Width Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 10240
)