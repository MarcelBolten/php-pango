--TEST--
Pango\Matrix->translate()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(5, 5);
var_dump($matrix);

$matrix->translate(2, 2);
var_dump($matrix);

/* Wrong number args */
try {
    $matrix->translate();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 2 */
try {
    $matrix->translate(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Too many args */
try {
    $matrix->translate(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Bad arg type */
try {
    $matrix->translate(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

/* Bad arg type 2*/
try {
    $matrix->translate(1, array());
} catch (TypeError $e) {
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
  float(10)
  ["y0"]=>
  float(12)
}
Pango\Matrix::translate() expects exactly 2 arguments, 0 given
Pango\Matrix::translate() expects exactly 2 arguments, 1 given
Pango\Matrix::translate() expects exactly 2 arguments, 3 given
Pango\Matrix::translate(): Argument #1 ($tx) must be of type float, array given
Pango\Matrix::translate(): Argument #2 ($ty) must be of type float, array given
