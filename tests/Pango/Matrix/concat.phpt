--TEST--
Pango\Matrix->concat()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$A = new Matrix(2);
var_dump($A);
$B = new Matrix(yy: 5);
var_dump($B);

$C = $A->concat($B);
var_dump($C);

try {
    $A->concat();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $A->concat($B, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $A->concat(array());
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
  float(1)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(1)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(5)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(2)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(5)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
Pango\Matrix::concat() expects exactly 1 argument, 0 given
Pango\Matrix::concat() expects exactly 1 argument, 2 given
Pango\Matrix::concat(): Argument #1 ($newMatrix) must be of type Pango\Matrix, array given
