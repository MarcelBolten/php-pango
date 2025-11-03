--TEST--
Pango\FontDescription::getStyle()
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription();
var_dump($fontDesc);
var_dump($fontDesc->getStyle());

$fontDesc = new Pango\FontDescription("Cantarell Italic Small-Caps Light Expanded 15");
var_dump($fontDesc);
var_dump($fontDesc->getStyle());

try {
    $fontDesc->getStyle("1");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Style::Normal)
object(Pango\FontDescription)#%d (0) {
}
enum(Pango\Style::Italic)
Pango\FontDescription::getStyle() expects exactly 0 arguments, 1 given
