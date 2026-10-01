--TEST--
Pango\Matrix->getSlantRatio()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(5, 5);
var_dump($matrix);

var_dump($matrix->getSlantRatio());

try {
    $matrix->getSlantRatio(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(5)
  ["yx"]=>
  float(5)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(1)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
float(5)
Pango\Matrix::getSlantRatio() expects exactly 0 arguments, 1 given
