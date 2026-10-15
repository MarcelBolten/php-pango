--TEST--
Pango\FontDescription::getSize()
--EXTENSIONS--
pango
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getSize());

$fontDesc = new FontDescription("Cantarell Italic Small-Caps Light Expanded 10");
var_dump($fontDesc->getSize());

try {
    $fontDesc->getSize('invalid');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(0)
int(10240)
Pango\FontDescription::getSize() expects exactly 0 arguments, 1 given
