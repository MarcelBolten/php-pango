--TEST--
Pango\Layout::setJustifyLastLine()
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

$layout->setJustifyLastLine(true);
var_dump($layout->getJustifyLastLine());
$layout->setJustifyLastLine(false);
var_dump($layout->getJustifyLastLine());

try {
    $layout->setJustifyLastLine();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setJustifyLastLine(true, false);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setJustifyLastLine(array());
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
Pango\Layout::setJustifyLastLine() expects exactly 1 argument, 0 given
Pango\Layout::setJustifyLastLine() expects exactly 1 argument, 2 given
Pango\Layout::setJustifyLastLine(): Argument #1 ($justifyLastLine) must be of type bool, array given
