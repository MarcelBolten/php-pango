--TEST--
Pango\GlyphInfo read property handler
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
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
object(PangoCairo\Layout)#%d (0) {
}
int(794)
array(3) {
  ["width"]=>
  int(14336)
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
