--TEST--
Pango\Attribute\OverlineAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\OverlineAttribute;

$overline = new OverlineAttribute(Pango\Overline::Single);
var_dump($overline);
print_r($overline);
?>
--EXPECTF--
object(Pango\Attribute\OverlineAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Overline::Single)
}
Pango\Attribute\OverlineAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Overline Enum:int
        (
            [name] => Single
            [value] => 1
        )

)
