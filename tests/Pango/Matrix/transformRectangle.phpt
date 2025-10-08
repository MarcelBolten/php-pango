--TEST--
Pango\Matrix->transformRectangle()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;
use Pango\Rectangle;

$matrix = new Matrix();
$matrix->scale(2, 2);
var_dump($matrix);

$params = [2, 2, 10, 10];
array_walk($params, fn(&$v) => $v = $v * Pango\Pango::SCALE);
$rectangle_in = new Rectangle(...$params);
var_dump($rectangle_in);
$rectangle_out = $matrix->transformRectangle($rectangle_in);
var_dump($rectangle_out);

try {
    $matrix->transformRectangle();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $matrix->transformRectangle($rectangle_in, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $matrix->transformRectangle(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
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
  int(2048)
  ["y"]=>
  int(2048)
  ["width"]=>
  int(10240)
  ["height"]=>
  int(10240)
  ["ascent"]=>
  int(-2048)
  ["descent"]=>
  int(12288)
  ["leftBearing"]=>
  int(2048)
  ["rightBearing"]=>
  int(12288)
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(4096)
  ["y"]=>
  int(4096)
  ["width"]=>
  int(20480)
  ["height"]=>
  int(20480)
  ["ascent"]=>
  int(-4096)
  ["descent"]=>
  int(24576)
  ["leftBearing"]=>
  int(4096)
  ["rightBearing"]=>
  int(24576)
}
Pango\Matrix::transformRectangle() expects exactly 1 argument, 0 given
Pango\Matrix::transformRectangle() expects exactly 1 argument, 2 given
Pango\Matrix::transformRectangle(): Argument #1 ($rectangle) must be of type Pango\Rectangle, array given
