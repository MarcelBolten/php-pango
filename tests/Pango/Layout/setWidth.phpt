--TEST--
Pango\Layout::setWidth()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

var_dump($layout->getWidth());

$layout->setWidth(10 * Pango\Pango::SCALE);
var_dump($layout->getWidth());

$layout->setWidth(0);
var_dump($layout->getWidth());

$layout->setWidth(-1);
var_dump($layout->getWidth());

try {
    $layout->setWidth();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setWidth(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(-1)
int(10240)
int(0)
int(-1)
Pango\Layout::setWidth() expects exactly 1 argument, 0 given
Pango\Layout::setWidth() expects exactly 1 argument, 2 given
Pango\Layout::setWidth(): Argument #1 ($width) must be of type int, array given
