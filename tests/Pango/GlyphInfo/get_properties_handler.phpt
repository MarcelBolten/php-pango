--TEST--
Pango\GlyphInfo get_properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
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
  int(810)
  ["geometry"]=>
  object(Pango\GlyphGeometry)#%d (3) {
    ["width"]=>
    int(11264)
    ["xOffset"]=>
    int(0)
    ["yOffset"]=>
    int(0)
  }
  ["attributes"]=>
  object(Pango\GlyphVisAttr)#%d (2) {
    ["isClusterStart"]=>
    bool(true)
    ["isColor"]=>
    bool(false)
  }
}
