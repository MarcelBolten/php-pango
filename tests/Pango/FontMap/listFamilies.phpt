--TEST--
Pango\FontMap::listFamilies()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$families = $fontMap->listFamilies();
var_dump(is_array($families));
var_dump($families[0]);

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
object(Pango\FontFamily)#%d (0) {
}
Pango\FontMap::listFamilies() expects exactly 0 arguments, 1 given
