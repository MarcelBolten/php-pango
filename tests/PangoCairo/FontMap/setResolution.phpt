--TEST--
PangoCairo\FontMap::setResolution()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$fontMap->setResolution(120.5);
var_dump($fontMap->getResolution());

try {
    $fontMap->setResolution();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $fontMap->setResolution(96, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $fontMap->setResolution(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
float(120.5)
PangoCairo\FontMap::setResolution() expects exactly 1 argument, 0 given
PangoCairo\FontMap::setResolution() expects exactly 1 argument, 2 given
PangoCairo\FontMap::setResolution(): Argument #1 ($factor) must be of type float, array given