--TEST--
Pango\FontDescription::setWeight()
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getWeight());

$fontDesc->setWeight(Pango\Weight::Bold);
var_dump($fontDesc->getWeight());

try {
    $fontDesc->setWeight();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setWeight("bold");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Weight::Normal)
enum(Pango\Weight::Bold)
Pango\FontDescription::setWeight() expects exactly 1 argument, 0 given
Pango\FontDescription::setWeight(): Argument #1 ($weight) must be of type Pango\Weight, string given
