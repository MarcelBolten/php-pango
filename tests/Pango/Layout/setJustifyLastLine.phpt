--TEST--
Pango\Layout::setJustifyLastLine()
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
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
bool(true)
bool(false)
Pango\Layout::setJustifyLastLine() expects exactly 1 argument, 0 given
Pango\Layout::setJustifyLastLine() expects exactly 1 argument, 2 given
Pango\Layout::setJustifyLastLine(): Argument #1 ($justifyLastLine) must be of type bool, array given
