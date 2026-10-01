--TEST--
Pango\FontDescription::setWidth()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getWidth());

$fontDesc->setWidth(Pango\Width::Expanded);
var_dump($fontDesc->getWidth());

try {
    $fontDesc->setWidth();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setWidth("Expanded");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Width::Normal)
enum(Pango\Width::Expanded)
Pango\FontDescription::setWidth() expects exactly 1 argument, 0 given
Pango\FontDescription::setWidth(): Argument #1 ($width) must be of type Pango\Width, string given
