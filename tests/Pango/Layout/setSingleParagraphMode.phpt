--TEST--
Pango\Layout::setSingleParagraphMode()
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

$layout->setSingleParagraphMode(true);
var_dump($layout->getSingleParagraphMode());

$layout->setSingleParagraphMode(false);
var_dump($layout->getSingleParagraphMode());

try {
    $layout->setSingleParagraphMode();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setSingleParagraphMode(true, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setSingleParagraphMode(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#1 (0) {
}
object(Pango\Layout)#4 (0) {
}
bool(true)
bool(false)
Pango\Layout::setSingleParagraphMode() expects exactly 1 argument, 0 given
Pango\Layout::setSingleParagraphMode() expects exactly 1 argument, 2 given
Pango\Layout::setSingleParagraphMode(): Argument #1 ($setting) must be of type bool, array given
