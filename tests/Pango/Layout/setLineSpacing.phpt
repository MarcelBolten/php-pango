--TEST--
Pango\Layout::setLineSpacing()
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

$layout->setLineSpacing(1.5);
var_dump($layout->getLineSpacing());

try {
    $layout->setLineSpacing();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setLineSpacing(1.5, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $layout->setLineSpacing(array());
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
float(1.5)
Pango\Layout::setLineSpacing() expects exactly 1 argument, 0 given
Pango\Layout::setLineSpacing() expects exactly 1 argument, 2 given
Pango\Layout::setLineSpacing(): Argument #1 ($factor) must be of type float, array given
