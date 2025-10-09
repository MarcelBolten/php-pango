--TEST--
Pango\Context::setResolution()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$pangoContext = Pango\Context::createFromCairoContext($cairoContext);
var_dump($pangoContext);
$pangoContext->setResolution(300);

try {
    $pangoContext->getResolution(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\Context::getResolution() expects exactly 0 arguments, 1 given
