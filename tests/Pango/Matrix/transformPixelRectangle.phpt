--TEST--
Pango\Matrix->transformPixelRectangle()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Matrix;
use Pango\Rectangle;

$matrix = new Matrix();
$matrix->scale(2, 2);
var_dump($matrix);

$params = [2, 2, 10, 10];
$rectangle_in = new Rectangle(...$params);
var_dump($rectangle_in);
$rectangle_out = $matrix->transformPixelRectangle($rectangle_in);
var_dump($rectangle_out);

try {
    $matrix->transformPixelRectangle();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $matrix->transformPixelRectangle($rectangle_in, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $matrix->transformPixelRectangle(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(2)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(2)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(2)
  ["y"]=>
  int(2)
  ["width"]=>
  int(10)
  ["height"]=>
  int(10)
  ["ascent"]=>
  int(-2)
  ["descent"]=>
  int(12)
  ["leftBearing"]=>
  int(2)
  ["rightBearing"]=>
  int(12)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(4)
  ["y"]=>
  int(4)
  ["width"]=>
  int(20)
  ["height"]=>
  int(20)
  ["ascent"]=>
  int(-4)
  ["descent"]=>
  int(24)
  ["leftBearing"]=>
  int(4)
  ["rightBearing"]=>
  int(24)
}
Pango\Matrix::transformPixelRectangle() expects exactly 1 argument, 0 given
Pango\Matrix::transformPixelRectangle() expects exactly 1 argument, 2 given
Pango\Matrix::transformPixelRectangle(): Argument #1 ($rectangle) must be of type Pango\Rectangle, array given
