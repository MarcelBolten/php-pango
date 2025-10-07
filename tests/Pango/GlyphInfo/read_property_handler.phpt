--TEST--
Pango\GlyphInfo read property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
var_dump($layout);

$layout->setText("Hello, Παν語!");
foreach ($layout->getLinesReadonly() as $line) {
    $glyphs = $line->getRuns()[1]->glyphs->glyphs[0];
    var_dump($glyphs->glyph);
    var_dump($glyphs->geometry);
    var_dump($glyphs->attributes);
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
int(272)
array(3) {
  ["width"]=>
  int(12288)
  ["xOffset"]=>
  int(0)
  ["yOffset"]=>
  int(0)
}
array(2) {
  ["isClusterStart"]=>
  int(1)
  ["isColor"]=>
  int(0)
}
