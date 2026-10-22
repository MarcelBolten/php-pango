--TEST--
Pango\Attribute\ShapeAttribute get_properties handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShapeAttribute;
use Pango\Rectangle;

$rect = new Rectangle(0, 10, 100, 200);
$shape = new ShapeAttribute($rect, $rect);
var_dump($shape);
print_r($shape);
?>
--EXPECTF--
object(Pango\Attribute\ShapeAttribute)#%d (4) {
  ["startIndex"]=>
  int(0)
  ["endIndex"]=>
  int(4294967295)
  ["inkRect"]=>
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
  ["logicalRect"]=>
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
}
Pango\Attribute\ShapeAttribute Object
(
    [startIndex] => 0
    [endIndex] => 4294967295
    [inkRect] => Pango\Rectangle Object
        (
            [x] => 0
            [y] => 10
            [width] => 100
            [height] => 200
            [ascent] => -10
            [descent] => 210
            [leftBearing] => 0
            [rightBearing] => 100
        )

    [logicalRect] => Pango\Rectangle Object
        (
            [x] => 0
            [y] => 10
            [width] => 100
            [height] => 200
            [ascent] => -10
            [descent] => 210
            [leftBearing] => 0
            [rightBearing] => 100
        )

)