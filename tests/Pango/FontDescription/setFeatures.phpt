--TEST--
Pango\FontDescription::setFeatures()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);

$fontDesc->setFeatures("cv01=1");
var_dump($fontDesc->getFeatures());

try {
    $fontDesc->setFeatures("cv01\0=1");
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setFeatures("cv01=1", 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setFeatures(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
string(6) "cv01=1"
Pango\FontDescription::setFeatures(): Argument #1 ($features) must not contain NUL bytes
Pango\FontDescription::setFeatures() expects at most 1 argument, 2 given
Pango\FontDescription::setFeatures(): Argument #1 ($features) must be of type ?string, array given
