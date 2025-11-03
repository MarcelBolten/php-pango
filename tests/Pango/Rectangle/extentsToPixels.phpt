--TEST--
Pango\Rectangle::extentsToPixels
--EXTENSIONS--
pango
--FILE--
<?php
namespace Pango;

$params = [2, 5, 132, 44];
array_walk($params, fn(&$v) => $v = $v * Pango::SCALE);
$rectangle = new Rectangle(...$params);

$matrix = new Matrix();
$matrix->rotate(45);


$rectangle = $matrix->transformRectangle($rectangle);
var_dump($rectangle);

var_dump(Rectangle::extentsToPixels(
    $rectangle,
));

var_dump(Rectangle::extentsToPixels(
    $rectangle,
    RoundingMode::Inclusive
));

var_dump(Rectangle::extentsToPixels(
    $rectangle,
    RoundingMode::Nearest
));

try {
    Rectangle::extentsToPixels();
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Rectangle::extentsToPixels($rectangle, RoundingMode::Inclusive, 1);
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Rectangle::extentsToPixels(array(), RoundingMode::Inclusive);
} catch (\TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Rectangle::extentsToPixels($rectangle, array());
} catch (\TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(5069)
  ["y"]=>
  int(-93406)
  ["width"]=>
  int(127437)
  ["height"]=>
  int(127438)
  ["ascent"]=>
  int(93406)
  ["descent"]=>
  int(34032)
  ["leftBearing"]=>
  int(5069)
  ["rightBearing"]=>
  int(132506)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(4)
  ["y"]=>
  int(-92)
  ["width"]=>
  int(126)
  ["height"]=>
  int(126)
  ["ascent"]=>
  int(92)
  ["descent"]=>
  int(34)
  ["leftBearing"]=>
  int(4)
  ["rightBearing"]=>
  int(130)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(4)
  ["y"]=>
  int(-92)
  ["width"]=>
  int(126)
  ["height"]=>
  int(126)
  ["ascent"]=>
  int(92)
  ["descent"]=>
  int(34)
  ["leftBearing"]=>
  int(4)
  ["rightBearing"]=>
  int(130)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(5)
  ["y"]=>
  int(-91)
  ["width"]=>
  int(124)
  ["height"]=>
  int(124)
  ["ascent"]=>
  int(91)
  ["descent"]=>
  int(33)
  ["leftBearing"]=>
  int(5)
  ["rightBearing"]=>
  int(129)
}
Pango\Rectangle::extentsToPixels() expects at least 1 argument, 0 given
Pango\Rectangle::extentsToPixels() expects at most 2 arguments, 3 given
Pango\Rectangle::extentsToPixels(): Argument #1 ($rectangle) must be of type Pango\Rectangle, array given
Pango\Rectangle::extentsToPixels(): Argument #2 ($roundingMode) must be of type Pango\RoundingMode, array given
