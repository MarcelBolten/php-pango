--TEST--
Pango\Attribute\FontDescription read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontDescription as AttrFontDescription;
use Pango\FontDescription;

$attrFontDescription = new AttrFontDescription(new FontDescription("Sans 12"));

var_dump($attrFontDescription->desc);
var_dump($attrFontDescription->startIndex);
var_dump($attrFontDescription->endIndex);
?>
--EXPECTF--
object(Pango\FontDescription)#%d (0) {
}
int(0)
int(4294967295)
