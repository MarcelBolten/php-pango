--TEST--
Pango\Attribute\Size get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Size;

$size = new Size(5);
var_dump($size);
print_r($size);
?>
--EXPECTF--
object(Pango\Attribute\Size)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\Size Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)