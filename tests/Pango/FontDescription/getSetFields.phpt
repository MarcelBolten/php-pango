--TEST--
Pango\FontDescription::getSetFields()
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

$fontDesc->setFamily("sans-serif");
$fontDesc->setStyle(Style::Oblique);
$fontDesc->setVariant(Variant::TitleCaps);
$fontDesc->setWeight(Weight::Book);
$fontDesc->setStretch(Stretch::SemiExpanded);
$fontDesc->setSize(12.0 * SCALE);
$setFields = $fontDesc->getSetFields();
var_dump($setFields);

var_dump($setFields & FontMask::FAMILY);
var_dump($setFields & FontMask::STYLE);
var_dump($setFields & FontMask::VARIANT);
var_dump($setFields & FontMask::WEIGHT);
var_dump($setFields & FontMask::STRETCH);
var_dump($setFields & FontMask::SIZE);

try {
    $fontDesc->getSetFields("1");
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(0)
int(63)
int(1)
int(2)
int(4)
int(8)
int(16)
int(32)
Pango\FontDescription::getSetFields() expects exactly 0 arguments, 1 given
