--TEST--
PangoCairo\FontMap::setDefault()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$fontMap2 = new FontMap();
var_dump($fontMap2);

$fontMap2->setDefault($fontMap);

try {
    $fontMap->setDefault();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $fontMap->setDefault($fontMap, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $fontMap->setDefault(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(PangoCairo\FontMap)#%d (0) {
}
PangoCairo\FontMap::setDefault() expects exactly 1 argument, 0 given
PangoCairo\FontMap::setDefault() expects exactly 1 argument, 2 given
PangoCairo\FontMap::setDefault(): Argument #1 ($fontMap) must be of type PangoCairo\FontMap, array given
