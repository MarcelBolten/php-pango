--TEST--
Pango\Attribute\FontScaleAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontScaleAttribute;

$fontScale = new FontScaleAttribute(Pango\FontScale::SmallCaps);
var_dump($fontScale);
print_r($fontScale);
?>
--EXPECTF--
object(Pango\Attribute\FontScaleAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\FontScale::SmallCaps)
}
Pango\Attribute\FontScaleAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\FontScale Enum:int
        (
            [name] => SmallCaps
            [value] => 3
        )

)
