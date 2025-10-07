--TEST--
Pango\Layout::getHeight()
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

var_dump($layout->getHeight());

// Set in terms of lines (2 lines)
$layout->setHeight(-2);
var_dump($layout->getHeight());

// Set in terms of Pango units (10 * Pango::SCALE)
$layout->setHeight(10 * Pango\Pango::SCALE);
var_dump($layout->getHeight());

try {
    $layout->getHeight('wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#1 (0) {
}
object(Pango\Layout)#4 (0) {
}
int(-1)
int(-2)
int(10240)
Pango\Layout::getHeight() expects exactly 0 arguments, 1 given
