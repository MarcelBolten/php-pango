--TEST--
Pango\Layout::setHeight()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$layout->setHeight(10 * Pango\Pango::SCALE);
var_dump($layout->getHeight());

$layout->setHeight(-2);
var_dump($layout->getHeight());

$layout->setHeight(0);
var_dump($layout->getHeight());


try {
    $layout->setHeight();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setHeight(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setHeight(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(10240)
int(-2)
int(0)
Pango\Layout::setHeight() expects exactly 1 argument, 0 given
Pango\Layout::setHeight() expects exactly 1 argument, 2 given
Pango\Layout::setHeight(): Argument #1 ($height) must be of type int, array given