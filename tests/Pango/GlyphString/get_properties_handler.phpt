--TEST--
Pango\GlyphString get_properties handler
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
$glyphString = $layout->getLineReadonly(0)->getRuns()[1]->glyphs;
var_dump($glyphString);
// foreach(get_object_vars($glyphString) as $propName => $propValue) {
//     echo $propName, ": ", get_debug_type($propValue), "\n";
// }
// numGlyphs: int
// glyphs: array
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\GlyphString)#%d (2) {
  ["numGlyphs"]=>
  int(3)
  ["glyphs"]=>
  array(3) {
    [0]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(%i)
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
    [1]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(%i)
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
    [2]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(%i)
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
  }
}
