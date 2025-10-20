--TEST--
PangoCairo\Layout::updateLayout()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Cairo\Context;
use Cairo\Surface\{
    ImageFormat,
    Image
};

$cairoContext = new Context(new Image(ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->updateLayout();

try {
    $layout->updateLayout($cairoContext);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
PangoCairo\Layout::updateLayout() expects exactly 0 arguments, 1 given
