--TEST--
Pango\Matrix::__construct()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix();
var_dump($matrix);

/* Wrong number args - can only have too many, any number between 0 and 6 is fine */
try {
    new Matrix(1, 1, 1, 1, 1, 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    new Matrix(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    new Matrix(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 3 */
try {
    new Matrix(1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 4 */
try {
    new Matrix(1, 1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 5 */
try {
    new Matrix(1, 1, 1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 6 */
try {
    new Matrix(1, 1, 1, 1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
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
Pango\Matrix::__construct() expects at most 6 arguments, 7 given
Pango\Matrix::__construct(): Argument #1 ($xx) must be of type float, array given
Pango\Matrix::__construct(): Argument #2 ($yx) must be of type float, array given
Pango\Matrix::__construct(): Argument #3 ($xy) must be of type float, array given
Pango\Matrix::__construct(): Argument #4 ($yy) must be of type float, array given
Pango\Matrix::__construct(): Argument #5 ($x0) must be of type float, array given
Pango\Matrix::__construct(): Argument #6 ($y0) must be of type float, array given
