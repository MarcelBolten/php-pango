--TEST--
Pango\FontDescription::setVariations()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$fontDesc->setVariations("wght=500,wdth=125");
var_dump($fontDesc->getVariations());

try {
    $fontDesc->setVariations("wght=500\0,wdth=125");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setVariations("wght=500", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setVariations(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
string(17) "wght=500,wdth=125"
Pango\FontDescription::setVariations(): Argument #1 ($variations) must not contain NUL bytes
Pango\FontDescription::setVariations() expects at most 1 argument, 2 given
Pango\FontDescription::setVariations(): Argument #1 ($variations) must be of type ?string, array given
