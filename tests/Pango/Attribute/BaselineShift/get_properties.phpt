--TEST--
Pango\Attribute\BaselineShiftAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BaselineShiftAttribute;

$baselineShift = new BaselineShiftAttribute(Pango\BaselineShift::Superscript);
var_dump($baselineShift);
print_r($baselineShift);
?>
--EXPECTF--
object(Pango\Attribute\BaselineShiftAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\BaselineShift::Superscript)
}
Pango\Attribute\BaselineShiftAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\BaselineShift Enum:int
        (
            [name] => Superscript
            [value] => 1
        )

)
