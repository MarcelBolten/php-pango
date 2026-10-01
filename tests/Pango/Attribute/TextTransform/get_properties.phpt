--TEST--
Pango\Attribute\TextTransform get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\TextTransform;

$textTransform = new TextTransform(Pango\TextTransform::Lowercase);
var_dump($textTransform);
print_r($textTransform);
?>
--EXPECTF--
object(Pango\Attribute\TextTransform)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\TextTransform::Lowercase)
}
Pango\Attribute\TextTransform Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\TextTransform Enum:int
        (
            [name] => Lowercase
            [value] => 1
        )

)
