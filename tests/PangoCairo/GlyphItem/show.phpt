--TEST--
PangoCairo\GlyphItem::show()
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
$line = $layout->getLine(0); // there is only one line
// var_dump($line);
$run = $line->getRuns()[1]; // the second run contains 3 Greek characters
var_dump($run);
$run->show();
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(PangoCairo\GlyphItem)#%d (5) {
  ["item"]=>
  object(Pango\Item)#%d (4) {
    ["offset"]=>
    int(7)
    ["length"]=>
    int(6)
    ["numChars"]=>
    int(3)
    ["analysis"]=>
    object(Pango\Analysis)#%d (7) {
      ["font"]=>
      object(Pango\Font)#%d (1) {
        ["string-representation"]=>
        string(%d) "%s"
      }
      ["level"]=>
      int(0)
      ["gravity"]=>
      enum(Pango\Gravity::South)
      ["flags"]=>
      int(128)
      ["script"]=>
      enum(Pango\Script::Greek)
      ["language"]=>
      object(Pango\Language)#%d (1) {
        ["string-representation"]=>
        string(%d) "%s"
      }
      ["extraAttrs"]=>
      array(0) {
      }
    }
  }
  ["glyphs"]=>
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
      [1]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(%d)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(%i)
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
      [2]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(%d)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(%i)
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
    }
  }
  ["yOffset"]=>
  int(0)
  ["startXOffset"]=>
  int(0)
  ["endXOffset"]=>
  int(0)
}
