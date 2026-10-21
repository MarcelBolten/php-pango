--TEST--
Pango\Attribute\TextTransformAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\TextTransformAttribute;

$textTransform = new TextTransformAttribute(Pango\TextTransform::Lowercase);
var_dump($textTransform);
print_r($textTransform);
?>
--EXPECTF--
object(Pango\Attribute\TextTransformAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\TextTransform::Lowercase)
}
Pango\Attribute\TextTransformAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\TextTransform Enum:int
        (
            [name] => Lowercase
            [value] => 1
        )

)
