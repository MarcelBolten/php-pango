--TEST--
Pango\FontDescription clone handler
--EXTENSIONS--
pango
--FILE--
<?php
$fontDesc = new Pango\FontDescription("Sans 12");
var_dump($fontDesc);

$clonedFontDesc = clone $fontDesc;
var_dump($clonedFontDesc);
var_dump($fontDesc->equal($clonedFontDesc));

$clonedFontDesc->setSize(13 * Pango\SCALE);
var_dump($clonedFontDesc->getSize());

var_dump($fontDesc->getSize());

?>
--EXPECTF--
object(Pango\FontDescription)#1 (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
object(Pango\FontDescription)#2 (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
bool(true)
int(13312)
int(12288)
