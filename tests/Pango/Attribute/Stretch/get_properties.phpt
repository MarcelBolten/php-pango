--TEST--
Pango\Attribute\Stretch get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Stretch;

$stretch = new Stretch(Pango\Stretch::Expanded);
var_dump($stretch);
print_r($stretch);
?>
--EXPECTF--
object(Pango\Attribute\Stretch)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Stretch::Expanded)
}
Pango\Attribute\Stretch Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Stretch Enum:int
        (
            [name] => Expanded
            [value] => 6
        )

)
