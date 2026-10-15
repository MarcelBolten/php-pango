--TEST--
Pango\Attribute\Width get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(Pango\Width::Expanded);
var_dump($width);
print_r($width);
?>
--EXPECTF--
object(Pango\Attribute\Width)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Width::Expanded)
}
Pango\Attribute\Width Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Width Enum:int
        (
            [name] => Expanded
            [value] => 1250
        )

)