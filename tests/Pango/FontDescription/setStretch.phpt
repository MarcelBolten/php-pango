--TEST--
Pango\FontDescription::setStretch()
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getStretch());

$fontDesc->setStretch(Pango\Stretch::Expanded);
var_dump($fontDesc->getStretch());

try {
    $fontDesc->setStretch();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setStretch("Expanded");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Stretch::Normal)
enum(Pango\Stretch::Expanded)
Pango\FontDescription::setStretch() expects exactly 1 argument, 0 given
Pango\FontDescription::setStretch(): Argument #1 ($stretch) must be of type Pango\Stretch, string given
