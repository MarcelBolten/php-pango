--TEST--
Pango\Attribute\Family get_properties handler
--EXTENSIONS--
pango
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
  string(%d) "%s"
}
Pango\Attribute\Family Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Noto Sans
)