--TEST--
Pango\Context::shape_item()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
include __DIR__ . '/../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\AttributeList;
use Pango\Context;
use Pango\LogAttrList;
use Pango\ShapeFlags;
use PangoCairo\FontMap;
use function Pango\shape_item;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$attrList = new AttributeList("0 7 size 16, 7 13 size 12, 13 16 size 14, 16 17 size 18");

$text = "Hello, Παν語!";
$logAttrList = new LogAttrList($text);
$item = $context->itemize($text, 7, 6, $attrList)[0];
var_dump($item->analysis);
shape_item($text, $item);
var_dump(shape_item($text, $item, $logAttrList));
shape_item($text, $item, $logAttrList, ShapeFlags::RoundPositions);

try {
    shape_item("\0", $item);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item($text);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item($text, $item, $logAttrList, ShapeFlags::RoundPositions, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item(array(), $item, $logAttrList);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item($text, array(), $logAttrList);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item($text, $item, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_item($text, $item, $logAttrList, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
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
Pango\shape_item(): Argument #1 ($paragraph_text) must not contain NUL bytes
Pango\shape_item() expects at least 2 arguments, 0 given
Pango\shape_item() expects at least 2 arguments, 1 given
Pango\shape_item() expects at most 4 arguments, 5 given
Pango\shape_item(): Argument #1 ($paragraph_text) must be of type string, array given
Pango\shape_item(): Argument #2 ($item) must be of type Pango\Item, array given
Pango\shape_item(): Argument #3 ($logAttrs) must be of type ?Pango\LogAttrList, array given
Pango\shape_item(): Argument #4 ($flags) must be of type Pango\ShapeFlags, array given
