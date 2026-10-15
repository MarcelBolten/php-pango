--TEST--
Pango\Ft2\FontMap::configChanged()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
var_dump($fontMap);
$fontMap->configChanged();

try {
    $fontMap->configChanged(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
Pango\Fc\FontMap::configChanged() expects exactly 0 arguments, 1 given
