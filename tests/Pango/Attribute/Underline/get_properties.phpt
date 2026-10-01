--TEST--
Pango\Attribute\Underline get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Underline;

$underline = new Underline(Pango\Underline::Double);
var_dump($underline);
print_r($underline);
?>
--EXPECTF--
object(Pango\Attribute\Underline)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Underline::Double)
}
Pango\Attribute\Underline Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Underline Enum:int
        (
            [name] => Double
            [value] => 2
        )

)
