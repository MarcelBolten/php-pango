--TEST--
Pango\Attribute\BaselineShift get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\BaselineShift;

$baselineShift = new BaselineShift(Pango\BaselineShift::Superscript);
var_dump($baselineShift);
print_r($baselineShift);
?>
--EXPECTF--
object(Pango\Attribute\BaselineShift)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\BaselineShift::Superscript)
}
Pango\Attribute\BaselineShift Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\BaselineShift Enum:int
        (
            [name] => Superscript
            [value] => 1
        )

)
