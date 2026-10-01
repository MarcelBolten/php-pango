--TEST--
Pango\Attribute\Rise get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Rise;

$rise = new Rise(5);
var_dump($rise);
print_r($rise);
?>
--EXPECTF--
object(Pango\Attribute\Rise)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\Rise Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)