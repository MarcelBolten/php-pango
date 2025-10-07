--TEST--
Pango\Layout::setIndent()
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

var_dump($layout->getIndent());

$layout->setIndent(10 * Pango\Pango::SCALE);
var_dump($layout->getIndent());

$layout->setIndent(-10 * Pango\Pango::SCALE);
var_dump($layout->getIndent());

try {
    $layout->setIndent();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent(10, 'wrong');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setIndent(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(0)
int(10240)
int(-10240)
Pango\Layout::setIndent() expects exactly 1 argument, 0 given
Pango\Layout::setIndent() expects exactly 1 argument, 2 given
Pango\Layout::setIndent(): Argument #1 ($indent) must be of type int, array given
