--TEST--
Pango\FontMap::listFamilies()
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
var_dump(is_array($fontMap->listFamilies()));

try {
    $fontMap->listFamilies(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
bool(true)
Pango\FontMap::listFamilies() expects exactly 0 arguments, 1 given
