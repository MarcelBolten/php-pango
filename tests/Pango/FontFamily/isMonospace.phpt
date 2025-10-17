--TEST--
Pango\FontFamily::isMonospace()
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
var_dump($family->isMonospace());

try {
    $family->isMonospace(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
bool(%s)
Pango\FontFamily::isMonospace() expects exactly 0 arguments, 1 given
