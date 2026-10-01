--TEST--
Pango\FontDescription::unsetFields()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getSetFields());

$fontDesc->setFamily("sans-serif")
    ->setStyle(Style::Oblique)
    ->setVariant(Variant::TitleCaps)
    ->setWeight(Weight::Book)
    ->setStretch(Stretch::SemiExpanded)
    ->setSize(12.0 * SCALE);
var_dump($fontDesc->getSetFields());

$fontDesc->unsetFields(FontMask::STYLE | FontMask::VARIANT | FontMask::WEIGHT | FontMask::STRETCH | FontMask::SIZE);

var_dump($fontDesc->getSetFields());

try {
    $fontDesc->unsetFields();
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->unsetFields(1, 1);
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->unsetFields(array());
} catch (\TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(0)
int(63)
int(1)
Pango\FontDescription::unsetFields() expects exactly 1 argument, 0 given
Pango\FontDescription::unsetFields() expects exactly 1 argument, 2 given
Pango\FontDescription::unsetFields(): Argument #1 ($fontMask) must be of type int, array given
