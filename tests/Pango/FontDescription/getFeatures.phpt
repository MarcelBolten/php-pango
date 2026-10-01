--TEST--
Pango\FontDescription::getFeatures()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

var_dump($fontDesc->getFeatures());

$fontDesc->setFeatures("cv01=1");
var_dump($fontDesc->getFeatures());

$fontDesc->setFeatures(null);
var_dump($fontDesc->getFeatures());

try {
    $fontDesc->getFeatures("fail");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#1 (0) {
}
string(0) ""
string(6) "cv01=1"
string(0) ""
Pango\FontDescription::getFeatures() expects exactly 0 arguments, 1 given
