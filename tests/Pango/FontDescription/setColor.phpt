--TEST--
Pango\FontDescription::setColor()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getColor());

$fontDesc->setColor(Pango\FontColor::Required);
var_dump($fontDesc->getColor());

try {
    $fontDesc->setColor();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setColor("North");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\FontColor::DontCare)
enum(Pango\FontColor::Required)
Pango\FontDescription::setColor() expects exactly 1 argument, 0 given
Pango\FontDescription::setColor(): Argument #1 ($color) must be of type Pango\FontColor, string given
