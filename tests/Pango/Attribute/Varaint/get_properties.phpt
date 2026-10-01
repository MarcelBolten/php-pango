--TEST--
Pango\Attribute\Variant get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Variant;

$variant = new Variant(Pango\Variant::SmallCaps);
var_dump($variant);
print_r($variant);
?>
--EXPECTF--
object(Pango\Attribute\Variant)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Variant::SmallCaps)
}
Pango\Attribute\Variant Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Variant Enum:int
        (
            [name] => SmallCaps
            [value] => 1
        )

)
