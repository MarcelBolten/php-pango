--TEST--
Pango\Attribute\FontDescription clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontDescription as AttrFontDescription;
use Pango\FontDescription;

$attrFontDescription = new AttrFontDescription(new FontDescription("Sans 12"));
var_dump($attrFontDescription->desc);

$copy = clone $attrFontDescription;
var_dump($attrFontDescription !== $copy);
?>
--EXPECTF--
object(Pango\FontDescription)#2 (0) {
}
bool(true)
