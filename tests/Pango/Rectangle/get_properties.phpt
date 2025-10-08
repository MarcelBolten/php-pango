--TEST--
Pango\Rectangle get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$rectangle = new Pango\Rectangle(1, 2, 3, 4);
var_dump($rectangle);
print_r($rectangle);
?>
--EXPECTF--
object(Pango\Rectangle)#1 (8) {
  ["x"]=>
  int(1)
  ["y"]=>
  int(2)
  ["width"]=>
  int(3)
  ["height"]=>
  int(4)
  ["ascent"]=>
  int(-2)
  ["descent"]=>
  int(6)
  ["leftBearing"]=>
  int(1)
  ["rightBearing"]=>
  int(4)
}
Pango\Rectangle Object
(
    [x] => 1
    [y] => 2
    [width] => 3
    [height] => 4
    [ascent] => -2
    [descent] => 6
    [leftBearing] => 1
    [rightBearing] => 4
)
