--TEST--
Pango\Matrix->getFontScaleFactors()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(2.5, yy: 1.25);
var_dump($matrix);

var_dump($matrix->getFontScaleFactors());

try {
    $matrix->getFontScaleFactors(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(2.5)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(1.25)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
array(2) {
  ["x"]=>
  float(2.5)
  ["y"]=>
  float(1.25)
}
Pango\Matrix::getFontScaleFactors() expects exactly 0 arguments, 1 given
