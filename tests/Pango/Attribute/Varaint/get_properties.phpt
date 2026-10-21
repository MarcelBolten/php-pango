--TEST--
Pango\Attribute\VariantAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\VariantAttribute;

$variant = new Variant(Pango\Variant::SmallCaps);
var_dump($variant);
print_r($variant);
?>
--EXPECTF--
object(Pango\Attribute\VariantAttribute)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Variant::SmallCaps)
}
Pango\Attribute\VariantAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Variant Enum:int
        (
            [name] => SmallCaps
            [value] => 1
        )

)
