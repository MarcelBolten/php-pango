--TEST--
Pango\Attribute\SizeAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SizeAttribute;

$size = new SizeAttribute(5);
var_dump($size);
print_r($size);
?>
--EXPECTF--
object(Pango\Attribute\SizeAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\SizeAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)