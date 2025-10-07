--TEST--
Pango\FontDescription::getVariant()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$variant = $fontDesc->getVariant();
var_dump($variant);

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc);

$variant = $fontDesc->getVariant();
var_dump($variant);

try {
    $fontDesc->getVariant("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Variant::Normal)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Variant::SmallCaps)
Pango\FontDescription::getVariant() expects exactly 0 arguments, 1 given