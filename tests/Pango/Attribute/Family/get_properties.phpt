--TEST--
Pango\Attribute\Family get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Family;

$family = new Family("Noto Sans");
var_dump($family);
print_r($family);
?>
--EXPECTF--
object(Pango\Attribute\Family)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  string(9) "Noto Sans"
}
Pango\Attribute\Family Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Noto Sans
)