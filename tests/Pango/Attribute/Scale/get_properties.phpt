--TEST--
Pango\Attribute\Scale get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Scale;

$scale = new Scale(5.2);
var_dump($scale);
print_r($scale);
?>
--EXPECTF--
object(Pango\Attribute\Scale)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  float(5.2)
}
Pango\Attribute\Scale Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5.2
)