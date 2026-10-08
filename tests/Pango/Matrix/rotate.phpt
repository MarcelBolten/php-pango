--TEST--
Pango\Matrix::rotate()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(1.0, 0, 0, 1.0);
var_dump($matrix);

$R = $matrix->rotate(90.0);
var_dump($R);

/* Wrong number args */
try {
    $matrix->rotate();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 2 */
try {
    $matrix->rotate(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong arg type */
try {
    $matrix->rotate(array());
} catch (TypeError $e) {
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
  float(1)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
object(Pango\Matrix)#2 (6) {
  ["xx"]=>
  float(6.123233995736766E-17)
  ["yx"]=>
  float(-1)
  ["xy"]=>
  float(1)
  ["yy"]=>
  float(6.123233995736766E-17)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
Pango\Matrix::rotate() expects exactly 1 argument, 0 given
Pango\Matrix::rotate() expects exactly 1 argument, 2 given
Pango\Matrix::rotate(): Argument #1 ($degrees) must be of type float, array given
