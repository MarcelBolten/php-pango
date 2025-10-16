--TEST--
PangoCairo\FontMap::getResolution()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
var_dump($fontMap->getResolution());

try {
    $fontMap->getResolution(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
float(96)
PangoCairo\FontMap::getResolution() expects exactly 0 arguments, 1 given
