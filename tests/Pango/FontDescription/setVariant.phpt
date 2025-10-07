--TEST--
Pango\FontDescription::setVariant()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$fontDesc->setVariant(Pango\Variant::SmallCaps);

$variant = $fontDesc->getVariant();
var_dump($variant);

try {
    $fontDesc->setVariant();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setVariant("Small-Caps");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#1 (0) {
}
enum(Pango\Variant::SmallCaps)
Pango\FontDescription::setVariant() expects exactly 1 argument, 0 given
Pango\FontDescription::setVariant(): Argument #1 ($variant) must be of type Pango\Variant, string given
