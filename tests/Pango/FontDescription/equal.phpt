--TEST--
Pango\FontDescription::equal()
--EXTENSIONS--
pango
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);

$fontDesc->setFamily("sans-serif");
$fontDesc->setStyle(Style::Oblique);
$fontDesc->setVariant(Variant::TitleCaps);
$fontDesc->setWeight(Weight::Book);
$fontDesc->setStretch(Stretch::SemiExpanded);
$fontDesc->setSize(12.0 * Pango::SCALE);
var_dump($fontDesc->toString());
var_dump($fontDesc->equal($fontDesc));

$fontDesc2 = new FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc2);
var_dump($fontDesc2->toString());

var_dump($fontDesc->equal($fontDesc2));

try {
    $fontDesc->equal();
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->equal($fontDesc, $fontDesc);
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->equal(array());
} catch (\TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
string(51) "sans-serif Book Oblique Semi-Expanded Title-Caps 12"
bool(true)
object(Pango\FontDescription)#%d (0) {
}
string(45) "Cantarell Light Italic Expanded Small-Caps 15"
bool(false)
Pango\FontDescription::equal() expects exactly 1 argument, 0 given
Pango\FontDescription::equal() expects exactly 1 argument, 2 given
Pango\FontDescription::equal(): Argument #1 ($fontdesc2) must be of type Pango\FontDescription, array given