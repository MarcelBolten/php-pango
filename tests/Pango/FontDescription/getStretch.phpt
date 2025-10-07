--TEST--
Pango\FontDescription::getStretch()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getStretch());

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc);
var_dump($fontDesc->getStretch());

try {
    $fontDesc->getStretch("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Stretch::Normal)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Stretch::Expanded)
Pango\FontDescription::getStretch() expects exactly 0 arguments, 1 given
