--TEST--
Pango\Ft2\FontMap::substituteChanged()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
var_dump($fontMap);
$fontMap->substituteChanged();

try {
    $fontMap->substituteChanged(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
Pango\Fc\FontMap::substituteChanged() expects exactly 0 arguments, 1 given
