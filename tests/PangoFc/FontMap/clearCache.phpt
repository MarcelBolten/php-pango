--TEST--
Pango\Ft2\FontMap::clearCache()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
var_dump($fontMap);
$fontMap->clearCache();

try {
    $fontMap->clearCache(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
Pango\Fc\FontMap::clearCache() expects exactly 0 arguments, 1 given
