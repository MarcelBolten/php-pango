--TEST--
PangoCairo\Layout::getCairoContext()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$savedCairoContext = $layout->getCairoContext();
var_dump($savedCairoContext);
var_dump($cairoContext === $savedCairoContext);

try {
    $layout->getCairoContext(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
bool(true)
PangoCairo\Layout::getCairoContext() expects exactly 0 arguments, 1 given
