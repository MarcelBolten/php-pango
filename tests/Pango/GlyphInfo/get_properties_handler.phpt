--TEST--
Pango\GlyphInfo get_properties handler
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
$glyph = $layout->getLineReadonly(0)->getRuns()[1]->glyphs->glyphs[1];
var_dump($glyph);
// foreach(get_object_vars($glyph) as $name => $value) {
//     echo $name, ": ", get_debug_type($value), "\n";
// }

// glyph: int
// geometry: Pango\GlyphGeometry
// attributes: Pango\GlyphVisAttr
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\GlyphInfo)#%d (3) {
  ["glyph"]=>
  int(%d)
  ["geometry"]=>
  object(Pango\GlyphGeometry)#%d (3) {
    ["width"]=>
    int(%i)
    ["xOffset"]=>
    int(%i)
    ["yOffset"]=>
    int(%i)
  }
  ["attributes"]=>
  object(Pango\GlyphVisAttr)#%d (2) {
    ["isClusterStart"]=>
    bool(true)
    ["isColor"]=>
    bool(false)
  }
}
