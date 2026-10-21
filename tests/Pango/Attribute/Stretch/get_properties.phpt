--TEST--
Pango\Attribute\StretchAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StretchAttribute;

$stretch = new StretchAttribute(Pango\Stretch::Expanded);
var_dump($stretch);
print_r($stretch);
?>
--EXPECTF--
object(Pango\Attribute\StretchAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Stretch::Expanded)
}
Pango\Attribute\StretchAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Stretch Enum:int
        (
            [name] => Expanded
            [value] => 6
        )

)
