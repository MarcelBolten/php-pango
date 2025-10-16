--TEST--
PangoCairo\FontMap::getFontType()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();

var_dump($fontMap->getFontType());

try {
    $fontMap->getFontType(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
enum(Cairo\FontType::FT)
PangoCairo\FontMap::getFontType() expects exactly 0 arguments, 1 given
