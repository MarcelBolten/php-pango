--TEST--
Pango\Layout::getSingleParagraphMode()
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

var_dump($layout->getSingleParagraphMode());

try {
    $layout->getSingleParagraphMode(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#1 (0) {
}
object(Pango\Layout)#4 (0) {
}
bool(false)
Pango\Layout::getSingleParagraphMode() expects exactly 0 arguments, 1 given