--TEST--
Pango\Context::shape()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
include __DIR__ . '/../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Context;
use PangoCairo\FontMap;
use function Pango\shape;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$attrList = new AttributeList("0 7 size 16, 7 13 size 12, 13 16 size 14, 16 17 size 18");

$text = "Hello, Παν語!";
$item = $context->itemize($text, 7, 6, $attrList)[0];
var_dump($item);
var_dump(shape(substr($text, $item->offset, $item->length), $item->analysis));

try {
    shape("\0", $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape("", $item->analysis, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape(array(), $item->analysis);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape("", array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Item)#4 (4) {
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
      string(18) "DejaVu Serif 0.012"
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
      string(1) "c"
    }
    ["extraAttrs"]=>
    array(0) {
    }
  }
}
object(Pango\GlyphString)#%d (2) {
  ["numGlyphs"]=>
  int(3)
  ["glyphs"]=>
  array(3) {
    [0]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(794)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(14)
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
      int(810)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(11)
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
      int(822)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(10)
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
Pango\shape(): Argument #1 ($text) must not contain NUL bytes
Pango\shape() expects exactly 2 arguments, 0 given
Pango\shape() expects exactly 2 arguments, 3 given
Pango\shape(): Argument #1 ($text) must be of type string, array given
Pango\shape(): Argument #2 ($analysis) must be of type Pango\Analysis, array given
