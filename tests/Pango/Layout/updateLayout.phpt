--TEST--
Pango\Layout::updateLayout()
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

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

$layout->updateLayout(new Context(new Image(ImageFormat::ARGB32, 2, 2)));

try {
    $layout->updateLayout();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->updateLayout($cairoContext, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->updateLayout(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
Pango\Layout::updateLayout() expects exactly 1 argument, 0 given
Pango\Layout::updateLayout() expects exactly 1 argument, 2 given
Pango\Layout::updateLayout(): Argument #1 ($context) must be of type Cairo\Context, array given
