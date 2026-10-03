--TEST--
Pango\GlyphItem get_properties handler
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
$run = $layout->getLine(0)->getRuns()[0];
var_dump($run);
// foreach(get_object_vars($run) as $name => $value) {
//     echo $name, ": ", get_debug_type($value), "\n";
// }

// item: Pango\Item
// glyphs: Pango\GlyphString
// yOffset: int
// startXOffset: int
// endXOffset: int
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
object(Pango\GlyphItem)#6 (5) {
  ["item"]=>
  object(Pango\Item)#9 (4) {
    ["offset"]=>
    int(0)
    ["length"]=>
    int(7)
    ["numChars"]=>
    int(7)
    ["analysis"]=>
    object(Pango\Analysis)#7 (7) {
      ["font"]=>
      object(Pango\Font)#10 (1) {
        ["string-representation"]=>
        string(15) "DejaVu Serif 12"
      }
      ["level"]=>
      int(0)
      ["gravity"]=>
      enum(Pango\Gravity::South)
      ["flags"]=>
      int(128)
      ["script"]=>
      enum(Pango\Script::Latin)
      ["language"]=>
      object(Pango\Language)#13 (1) {
        ["string-representation"]=>
        string(1) "c"
      }
      ["extraAttrs"]=>
      array(0) {
      }
    }
  }
  ["glyphs"]=>
  object(Pango\GlyphString)#8 (2) {
    ["numGlyphs"]=>
    int(7)
    ["glyphs"]=>
    array(7) {
      [0]=>
      object(Pango\GlyphInfo)#7 (3) {
        ["glyph"]=>
        int(43)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#18 (3) {
          ["width"]=>
          int(14336)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#19 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [1]=>
      object(Pango\GlyphInfo)#13 (3) {
        ["glyph"]=>
        int(72)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#19 (3) {
          ["width"]=>
          int(9216)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#18 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [2]=>
      object(Pango\GlyphInfo)#10 (3) {
        ["glyph"]=>
        int(79)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#18 (3) {
          ["width"]=>
          int(5120)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#19 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [3]=>
      object(Pango\GlyphInfo)#14 (3) {
        ["glyph"]=>
        int(79)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#19 (3) {
          ["width"]=>
          int(5120)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#18 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [4]=>
      object(Pango\GlyphInfo)#15 (3) {
        ["glyph"]=>
        int(82)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#18 (3) {
          ["width"]=>
          int(10240)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#19 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [5]=>
      object(Pango\GlyphInfo)#16 (3) {
        ["glyph"]=>
        int(15)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#19 (3) {
          ["width"]=>
          int(5120)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#18 (2) {
          ["isClusterStart"]=>
          bool(true)
          ["isColor"]=>
          bool(false)
        }
      }
      [6]=>
      object(Pango\GlyphInfo)#17 (3) {
        ["glyph"]=>
        int(3)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#18 (3) {
          ["width"]=>
          int(5120)
          ["xOffset"]=>
          int(0)
          ["yOffset"]=>
          int(0)
        }
        ["attributes"]=>
        object(Pango\GlyphVisAttr)#19 (2) {
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
