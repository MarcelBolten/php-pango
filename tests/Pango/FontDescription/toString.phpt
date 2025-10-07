--TEST--
Pango\FontDescription::toString()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
namespace Pango;

$fontDesc = new FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->toString());

$fontDesc->setFamily("sans-serif");
$fontDesc->setStyle(Style::Oblique);
$fontDesc->setVariant(Variant::TitleCaps);
$fontDesc->setWeight(Weight::Book);
$fontDesc->setStretch(Stretch::SemiExpanded);
$fontDesc->setSize(12.0 * Pango::SCALE);
var_dump($fontDesc->toString());

$fontDesc = new FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc);
var_dump($fontDesc->toString());

$fontDesc = new FontDescription("");
var_dump($fontDesc->toString());

try {
    $fontDesc->toString("1");
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
string(6) "Normal"
string(51) "sans-serif Book Oblique Semi-Expanded Title-Caps 12"
object(Pango\FontDescription)#%d (0) {
}
string(45) "Cantarell Light Italic Expanded Small-Caps 15"
string(6) "Normal"
Pango\FontDescription::toString() expects exactly 0 arguments, 1 given
