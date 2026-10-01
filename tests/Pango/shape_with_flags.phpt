--TEST--
Pango\Context::shape_with_flags()
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
use Pango\ShapeFlags;
use function Pango\shape_with_flags;

$fontMap = FontMap::getDefault();
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$attrList = new AttributeList("0 7 size 16, 7 13 size 12, 13 16 size 14, 16 17 size 18");

$text = "Hello, Παν語!";
$item = $context->itemize($text, 7, 6, $attrList)[0];
var_dump($item->analysis);
shape_with_flags($text, $item->offset, $item->length, $item->analysis);
var_dump(shape_with_flags($text, $item->offset, $item->length, $item->analysis, ShapeFlags::None));
shape_with_flags($text, $item->offset, $item->length, $item->analysis, ShapeFlags::RoundPositions);

try {
    shape_with_flags("\0", $item->offset, $item->length, $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, -1, $item->length, $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, strlen($text) + 1, $item->length, $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, offset: 10, length: -1, analysis: $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, offset: 10, length: strlen($text) + 1, analysis: $item->analysis);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset, $item->length);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset, $item->length, $item->analysis, ShapeFlags::RoundPositions, 'extra');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags(array(), $item->offset, $item->length, $item->analysis);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, array(), $item->length, $item->analysis);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset, array(), $item->analysis);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset, $item->length, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    shape_with_flags($text, $item->offset, $item->length, $item->analysis, array());
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
Pango\shape_with_flags(): Argument #1 ($paragraph_text) must not contain NUL bytes
Pango\shape_with_flags(): Argument #2 ($offset) must be between 0 and 17
Pango\shape_with_flags(): Argument #2 ($offset) must be between 0 and 17
Pango\shape_with_flags(): Argument #3 ($length) must be between 0 and 7
Pango\shape_with_flags(): Argument #3 ($length) must be between 0 and 7
Pango\shape_with_flags() expects at least 4 arguments, 0 given
Pango\shape_with_flags() expects at least 4 arguments, 1 given
Pango\shape_with_flags() expects at least 4 arguments, 2 given
Pango\shape_with_flags() expects at least 4 arguments, 3 given
Pango\shape_with_flags() expects at most 5 arguments, 6 given
Pango\shape_with_flags(): Argument #1 ($paragraph_text) must be of type string, array given
Pango\shape_with_flags(): Argument #2 ($offset) must be of type int, array given
Pango\shape_with_flags(): Argument #3 ($length) must be of type int, array given
Pango\shape_with_flags(): Argument #4 ($analysis) must be of type Pango\Analysis, array given
Pango\shape_with_flags(): Argument #5 ($flags) must be of type Pango\ShapeFlags, array given
