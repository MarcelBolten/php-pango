--TEST--
Pango\Attribute\WidthAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WidthAttribute;

$width = new WidthAttribute(Pango\Width::Expanded);
var_dump($width);
print_r($width);
?>
--EXPECTF--
object(Pango\Attribute\WidthAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Width::Expanded)
}
Pango\Attribute\WidthAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Width Enum:int
        (
            [name] => Expanded
            [value] => 1250
        )

)