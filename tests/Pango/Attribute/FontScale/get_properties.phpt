--TEST--
Pango\Attribute\FontScale get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\FontScale;

$fontScale = new FontScale(Pango\FontScale::SmallCaps);
var_dump($fontScale);
print_r($fontScale);
?>
--EXPECTF--
object(Pango\Attribute\FontScale)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\FontScale::SmallCaps)
}
Pango\Attribute\FontScale Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\FontScale Enum:int
        (
            [name] => SmallCaps
            [value] => 3
        )

)
