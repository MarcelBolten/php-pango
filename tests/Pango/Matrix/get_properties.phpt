--TEST--
Pango\Matrix get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(6, 5, 4, 3, 2, 1);
var_dump($matrix);
print_r($matrix);
?>
--EXPECTF--
object(Pango\Matrix)#%d (6) {
  ["xx"]=>
  float(6)
  ["yx"]=>
  float(5)
  ["xy"]=>
  float(4)
  ["yy"]=>
  float(3)
  ["x0"]=>
  float(2)
  ["y0"]=>
  float(1)
}
Pango\Matrix Object
(
    [xx] => 6
    [yx] => 5
    [xy] => 4
    [yy] => 3
    [x0] => 2
    [y0] => 1
)
