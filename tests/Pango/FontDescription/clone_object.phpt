--TEST--
Pango\FontDescription clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
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
--EXPECT--
object(Pango\FontDescription)#1 (0) {
}
object(Pango\FontDescription)#2 (0) {
}
bool(true)
int(13312)
int(12288)
