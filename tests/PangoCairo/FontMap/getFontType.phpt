--TEST--
PangoCairo\FontMap::getFontType()
--EXTENSIONS--
pango
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
var_dump($fontMap->getFontType());

try {
    $fontMap->getFontType(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
enum(Cairo\FontType::FT)
PangoCairo\FontMap::getFontType() expects exactly 0 arguments, 1 given
