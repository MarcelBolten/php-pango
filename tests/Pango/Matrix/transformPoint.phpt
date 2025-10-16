--TEST--
Pango\Matrix::transformPoint()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(1, 0, 0, 1);
var_dump($matrix);

var_dump($matrix->transformPoint(1.0, 1.0));

/* Wrong number args */
try {
    $matrix->transformPoint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 2 */
try {
    $matrix->transformPoint(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 3 */
try {
    $matrix->transformPoint(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong arg type 1 */
try {
    $matrix->transformPoint([], 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong arg type 2 */
try {
    $matrix->transformPoint(1, []);
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
array(2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
Pango\Matrix::transformPoint() expects exactly 2 arguments, 0 given
Pango\Matrix::transformPoint() expects exactly 2 arguments, 1 given
Pango\Matrix::transformPoint() expects exactly 2 arguments, 3 given
Pango\Matrix::transformPoint(): Argument #1 ($x) must be of type float, array given
Pango\Matrix::transformPoint(): Argument #2 ($y) must be of type float, array given
