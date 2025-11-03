--TEST--
Pango\Rectangle clone handler
--EXTENSIONS--
pango
--FILE--
<?php
$rectangle = new Pango\Rectangle(1, 2, 3, 4);
var_dump($rectangle);
var_dump(clone $rectangle);
?>
--EXPECT--
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
object(Pango\Rectangle)#2 (8) {
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
