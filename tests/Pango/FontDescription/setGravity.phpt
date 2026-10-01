--TEST--
Pango\FontDescription::setGravity()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getGravity());

$fontDesc->setGravity(Pango\Gravity::North);
var_dump($fontDesc->getGravity());

try {
    $fontDesc->setGravity();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setGravity("North");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Gravity::South)
enum(Pango\Gravity::North)
Pango\FontDescription::setGravity() expects exactly 1 argument, 0 given
Pango\FontDescription::setGravity(): Argument #1 ($gravity) must be of type Pango\Gravity, string given
