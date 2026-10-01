--TEST--
Pango\FontDescription::getVariations()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

var_dump($fontDesc->getVariations());

$fontDesc->setVariations("wght=500,wdth=125");
var_dump($fontDesc->getVariations());

$fontDesc->setVariations(null);
var_dump($fontDesc->getVariations());

try {
    $fontDesc->getVariations("fail");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#1 (0) {
}
string(0) ""
string(17) "wght=500,wdth=125"
string(0) ""
Pango\FontDescription::getVariations() expects exactly 0 arguments, 1 given
