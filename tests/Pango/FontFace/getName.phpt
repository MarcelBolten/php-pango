--TEST--
Pango\FontFace::getName()
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

$family = $fontMap->listFamilies()[0];
var_dump($family);

$defaultFace = $family->getFace(null);
var_dump($defaultFace);
var_dump($defaultFace->getName());

try {
    $defaultFace->getName(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
object(Pango\FontFace)#%d (0) {
}
string(7) "Regular"
Pango\FontFace::getName() expects exactly 0 arguments, 1 given
