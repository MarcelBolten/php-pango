--TEST--
Pango\FontDescription::setStyle()
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getStyle());

$fontDesc->setStyle(Pango\Style::Italic);
var_dump($fontDesc->getStyle());

try {
    $fontDesc->setStyle();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $fontDesc->setStyle("Italic");
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#1 (0) {
}
enum(Pango\Style::Normal)
enum(Pango\Style::Italic)
Pango\FontDescription::setStyle() expects exactly 1 argument, 0 given
Pango\FontDescription::setStyle(): Argument #1 ($style) must be of type Pango\Style, string given
