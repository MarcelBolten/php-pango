--TEST--
Pango\Matrix->getFontScaleFactor()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(yy: 1.25);
var_dump($matrix);

var_dump($matrix->getFontScaleFactor());

try {
    $matrix->getFontScaleFactor(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(1)
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
float(1.25)
Pango\Matrix::getFontScaleFactor() expects exactly 0 arguments, 1 given
