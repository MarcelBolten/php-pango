--TEST--
Pango\Attribute\GravityAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityAttribute;

$gravity = new GravityAttribute(Pango\Gravity::North);
var_dump($gravity);
print_r($gravity);
?>
--EXPECTF--
object(Pango\Attribute\GravityAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Gravity::North)
}
Pango\Attribute\GravityAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Gravity Enum:int
        (
            [name] => North
            [value] => 2
        )

)
