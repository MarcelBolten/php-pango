--TEST--
Pango\Context::setMatrix()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$matrix = $context->getMatrix();
var_dump($matrix);

$matrix->scale(2.0, 2.0);
$context->setMatrix($matrix);
var_dump($context->getMatrix());

try {
    $context->setMatrix();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setMatrix($matrix, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $context->setMatrix(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
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
object(Pango\Matrix)#4 (6) {
  ["xx"]=>
  float(2)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(0)
  ["yy"]=>
  float(2)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
Pango\Context::setMatrix() expects exactly 1 argument, 0 given
Pango\Context::setMatrix() expects exactly 1 argument, 2 given
Pango\Context::setMatrix(): Argument #1 ($matrix) must be of type ?Pango\Matrix, array given
