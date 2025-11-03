--TEST--
Pango\FontMap::getDefault()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
var_dump($fontMap->createContext());

try {
    $fontMap->createContext(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
Pango\FontMap::createContext() expects exactly 0 arguments, 1 given
