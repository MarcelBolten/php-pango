--TEST--
Pango\FontDescription::getFamily()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

var_dump($fontDesc->getFamily());

$fontDesc->setFamily("serif");
var_dump($fontDesc->getFamily());

$fontDesc->setFamily("");
var_dump($fontDesc->getFamily());

try {
    $fontDesc->getFamily("fail");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#1 (0) {
}
string(0) ""
string(5) "serif"
string(0) ""
Pango\FontDescription::getFamily() expects exactly 0 arguments, 1 given
