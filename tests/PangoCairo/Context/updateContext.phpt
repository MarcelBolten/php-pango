--TEST--
PangoCairo\Context::updateContext()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\Context;

$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = new Context($cairoContext);
var_dump($pangoContext);

$cairoContext->setMatrix((new Cairo\Matrix(2, 0, 0, 2, 0, 0)));
$pangoContext->updateContext();
var_dump($pangoContext->getMatrix());

try {
    $pangoContext->updateContext(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Context)#%d (0) {
}
object(Pango\Matrix)#%d (6) {
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
PangoCairo\Context::updateContext() expects exactly 0 arguments, 1 given
