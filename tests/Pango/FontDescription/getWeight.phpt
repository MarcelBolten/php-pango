--TEST--
Pango\FontDescription::getWeight()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getWeight());

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc);
var_dump($fontDesc->getWeight());

try {
    $fontDesc->getWeight("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Weight::Normal)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Weight::Light)
Pango\FontDescription::getWeight() expects exactly 0 arguments, 1 given
