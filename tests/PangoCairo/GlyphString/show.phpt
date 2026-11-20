--TEST--
PangoCairo\GlyphString::show()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$font = $layout->getContext()->loadFont(new Pango\FontDescription('Sans 12'));
var_dump($font);

$layout->setText("Hello, Παν語!");
$line = $layout->getLine(0); // there is only one line
// var_dump($line);
$run = $line->getRuns()[1]; // the second run contains 3 Greek characters
// var_dump($run);
$glyphString = $run->glyphs;
var_dump($glyphString);
$glyphString->show($font);
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\Font)#%d (1) {
  ["string-representation"]=>
  string(%d) "%s"
}
object(PangoCairo\GlyphString)#%d (2) {
  ["numGlyphs"]=>
  int(3)
  ["glyphs"]=>
  array(3) {
    [0]=>
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
    [1]=>
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
    [2]=>
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
  }
}
