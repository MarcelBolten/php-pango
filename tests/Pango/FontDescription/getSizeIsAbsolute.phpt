--TEST--
Pango\FontDescription::getAbsoluteSize()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);

$fontDesc->setAbsoluteSize(1);
var_dump($fontDesc->getSizeIsAbsolute());

$fontDesc->setSize(1);
var_dump($fontDesc->getSizeIsAbsolute());

try {
    $fontDesc->getSizeIsAbsolute(1);
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
bool(true)
bool(false)
Pango\FontDescription::getSizeIsAbsolute() expects exactly 0 arguments, 1 given
