--TEST--
Pango\FontDescription::setFamily()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$fontDesc->setFamily('sans-serif');

$variant = $fontDesc->getFamily();
var_dump($variant);

try {
    $fontDesc->setFamily();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setFamily(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
string(10) "sans-serif"
Pango\FontDescription::setFamily() expects exactly 1 argument, 0 given
Pango\FontDescription::setFamily(): Argument #1 ($family) must be of type string, array given
