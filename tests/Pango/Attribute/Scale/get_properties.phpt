--TEST--
Pango\Attribute\ScaleAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ScaleAttribute;

$scale = new ScaleAttribute(5.2);
var_dump($scale);
print_r($scale);
?>
--EXPECTF--
object(Pango\Attribute\ScaleAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  float(5.2)
}
Pango\Attribute\ScaleAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5.2
)