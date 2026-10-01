--TEST--
Pango\Attribute\Overline get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\Overline;

$overline = new Overline(Pango\Overline::Single);
var_dump($overline);
print_r($overline);
?>
--EXPECTF--
object(Pango\Attribute\Overline)#%d (3) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["value"]=>
  enum(Pango\Overline::Single)
}
Pango\Attribute\Overline Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [value] => Pango\Overline Enum:int
        (
            [name] => Single
            [value] => 1
        )

)
