--TEST--
Pango\Attribute\Gravity get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Gravity;

$gravity = new Gravity(Pango\Gravity::North);
var_dump($gravity);
print_r($gravity);
?>
--EXPECTF--
object(Pango\Attribute\Gravity)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Gravity::North)
}
Pango\Attribute\Gravity Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Gravity Enum:int
        (
            [name] => North
            [value] => 2
        )

)
