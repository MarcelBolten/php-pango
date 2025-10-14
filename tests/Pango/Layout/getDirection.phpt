--TEST--
Pango\Layout::getDirection()
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

var_dump($layout->getDirection(0));

try {
    $layout->getDirection();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getDirection(0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->getDirection(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#1 (0) {
}
object(Pango\Layout)#4 (0) {
}
enum(Pango\Direction::LTR)
Pango\Layout::getDirection() expects exactly 1 argument, 0 given
Pango\Layout::getDirection() expects exactly 1 argument, 2 given
Pango\Layout::getDirection(): Argument #1 ($byteIndex) must be of type int, array given
