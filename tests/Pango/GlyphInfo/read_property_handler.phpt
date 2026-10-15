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
int(%d)
object(Pango\GlyphGeometry)#%d (3) {
  ["width"]=>
  int(%i)
  ["xOffset"]=>
  int(%i)
  ["yOffset"]=>
  int(%i)
}
object(Pango\GlyphVisAttr)#%d (2) {
  ["isClusterStart"]=>
  bool(true)
  ["isColor"]=>
  bool(false)
}
