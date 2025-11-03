--TEST--
Pango\Layout::setWidth()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
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
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
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
