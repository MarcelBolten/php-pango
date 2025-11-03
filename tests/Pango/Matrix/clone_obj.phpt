--TEST--
Pango\Matrix clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Matrix;

$matrix = new Matrix(5);
$copy = clone $matrix;
$copy->xx = 9;

var_dump($matrix->xx);
var_dump($copy->xx);
?>
--EXPECT--
float(5)
float(9)
