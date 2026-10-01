--TEST--
Pango\Ft2\FontMap::setResolution()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
var_dump($fontMap);
var_dump($fontMap->setResolution(300, 300));

try {
    $fontMap->setResolution();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->setResolution(72);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->setResolution(72, 72, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->setResolution(array(), 72);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontMap->setResolution(72, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Ft2\FontMap)#%d (0) {
}
Pango\Ft2\FontMap::setResolution() expects exactly 2 arguments, 0 given
Pango\Ft2\FontMap::setResolution() expects exactly 2 arguments, 1 given
Pango\Ft2\FontMap::setResolution() expects exactly 2 arguments, 3 given
Pango\Ft2\FontMap::setResolution(): Argument #1 ($dpiX) must be of type float, array given
Pango\Ft2\FontMap::setResolution(): Argument #2 ($dpiY) must be of type float, array given