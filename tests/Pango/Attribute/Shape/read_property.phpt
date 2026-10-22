--TEST--
Pango\Attribute\ShapeAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShapeAttribute;
use Pango\Rectangle;

$rect = new Rectangle(0, 10, 100, 200);
$shape = new ShapeAttribute($rect, $rect);

var_dump($shape->inkRect);
var_dump($shape->logicalRect);
var_dump($shape->startIndex);
var_dump($shape->endIndex);
?>
--EXPECTF--
object(Pango\Rectangle)#%d (8) {
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
object(Pango\Rectangle)#%d (8) {
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
int(0)
int(4294967295)
