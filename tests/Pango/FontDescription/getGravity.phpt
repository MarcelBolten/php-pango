--TEST--
Pango\FontDescription::getGravity()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getGravity());

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded North 15");
var_dump($fontDesc);
var_dump($fontDesc->getGravity());

try {
    $fontDesc->getGravity("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Gravity::South)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Gravity::North)
Pango\FontDescription::getGravity() expects exactly 0 arguments, 1 given
