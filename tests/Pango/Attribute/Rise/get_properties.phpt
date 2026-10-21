--TEST--
Pango\Attribute\RiseAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\RiseAttribute;

$rise = new RiseAttribute(5);
var_dump($rise);
print_r($rise);
?>
--EXPECTF--
object(Pango\Attribute\RiseAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  int(5)
}
Pango\Attribute\RiseAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => 5
)