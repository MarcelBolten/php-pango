--TEST--
Pango\Context::getMatrix()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Context;
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
var_dump($context->getMatrix());

try {
    $context->getMatrix(array());
} catch (ArgumentCountError $e) {
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
Pango\Context::getMatrix() expects exactly 0 arguments, 1 given
