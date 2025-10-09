--TEST--
Pango\Context::createFromCairoContext()
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

try {
    Pango\Context::createFromCairoContext();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Pango\Context::createFromCairoContext($cairoContext, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    Pango\Context::createFromCairoContext(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\Context::createFromCairoContext() expects exactly 1 argument, 0 given
Pango\Context::createFromCairoContext() expects exactly 1 argument, 2 given
Pango\Context::createFromCairoContext(): Argument #1 ($context) must be of type Cairo\Context, array given