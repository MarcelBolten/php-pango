--TEST--
Pango\FontDescription::getWidth()
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getWidth());

try {
    $fontDesc->getWidth("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Width::Normal)
Pango\FontDescription::getWidth() expects exactly 0 arguments, 1 given
