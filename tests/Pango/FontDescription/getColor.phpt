--TEST--
Pango\FontDescription::getColor()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getColor());

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded North With-Color 15");
var_dump($fontDesc);
var_dump($fontDesc->getColor());

try {
    $fontDesc->getColor("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\FontColor::DontCare)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\FontColor::Required)
Pango\FontDescription::getColor() expects exactly 0 arguments, 1 given
