--TEST--
Pango\Matrix::transformDistance()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(1, 2, 3, 1);
var_dump($matrix);

var_dump($matrix->transformDistance(1.0, 1.0));

/* Wrong number args */
try {
    $matrix->transformDistance();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 2 */
try {
    $matrix->transformDistance(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong number args 3 */
try {
    $matrix->transformDistance(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong arg type 1 */
try {
    $matrix->transformDistance(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

/* Wrong arg type 2 */
try {
    $matrix->transformDistance(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(1)
  ["yx"]=>
  float(2)
  ["xy"]=>
  float(3)
  ["yy"]=>
  float(1)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
array(2) {
  ["x"]=>
  float(4)
  ["y"]=>
  float(3)
}
Pango\Matrix::transformDistance() expects exactly 2 arguments, 0 given
Pango\Matrix::transformDistance() expects exactly 2 arguments, 1 given
Pango\Matrix::transformDistance() expects exactly 2 arguments, 3 given
Pango\Matrix::transformDistance(): Argument #1 ($dx) must be of type float, array given
Pango\Matrix::transformDistance(): Argument #2 ($dy) must be of type float, array given
