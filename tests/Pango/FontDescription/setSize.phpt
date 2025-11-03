--TEST--
Pango\FontDescription::setSize()
--EXTENSIONS--
pango
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);

$fontDesc->setSize(10 * Pango::SCALE);
var_dump($fontDesc->getSize());


$fontDesc->setSize(0);
var_dump($fontDesc->getSize());

try {
    $fontDesc->setSize();
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setSize(1, 2);
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setSize(array());
} catch (\TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(10240)
int(0)
Pango\FontDescription::setSize() expects exactly 1 argument, 0 given
Pango\FontDescription::setSize() expects exactly 1 argument, 2 given
Pango\FontDescription::setSize(): Argument #1 ($size) must be of type int, array given
