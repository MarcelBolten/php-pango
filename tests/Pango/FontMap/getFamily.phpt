--TEST--
Pango\FontMap::getFamily()
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
var_dump($fontMap->getFamily("Sans"));

try {
    $fontMap->getFamily("This family does not exist");
} catch (Pango\Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->getFamily();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->getFamily("Sans", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->getFamily(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
Font family 'This family does not exist' not found.
Pango\FontMap::getFamily() expects exactly 1 argument, 0 given
Pango\FontMap::getFamily() expects exactly 1 argument, 2 given
Pango\FontMap::getFamily(): Argument #1 ($name) must be of type string, array given
