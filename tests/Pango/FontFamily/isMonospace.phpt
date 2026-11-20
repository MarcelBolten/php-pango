--TEST--
Pango\FontFamily::isMonospace()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
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
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\FontFamily)#%d (0) {
}
bool(%s)
Pango\FontFamily::isMonospace() expects exactly 0 arguments, 1 given
