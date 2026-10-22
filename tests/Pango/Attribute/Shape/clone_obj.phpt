--TEST--
Pango\Attribute\ShapeAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShapeAttribute;
use Pango\Rectangle;

$rect = new Rectangle(0, 10, 100, 200);
$shape = new ShapeAttribute($rect, $rect);
var_dump($shape);

$copy = clone $shape;
var_dump($copy);
?>
--EXPECT--
object(Pango\Attribute\ShapeAttribute)#2 (4) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["inkRect"]=>
  object(Pango\Rectangle)#1 (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
  ["logicalRect"]=>
  object(Pango\Rectangle)#1 (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
}
object(Pango\Attribute\ShapeAttribute)#3 (4) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["inkRect"]=>
  object(Pango\Rectangle)#1 (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
  ["logicalRect"]=>
  object(Pango\Rectangle)#1 (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(10)
    ["width"]=>
    int(100)
    ["height"]=>
    int(200)
    ["ascent"]=>
    int(-10)
    ["descent"]=>
    int(210)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
}
