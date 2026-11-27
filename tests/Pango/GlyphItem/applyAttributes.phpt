--TEST--
Pango\GlyphItem::applyAttributes()
--EXTENSIONS--
pango
--FILE--
<?php

use Pango\Attribute\{
  Attribute,
  AttributeList,
  SizeAttribute,
};
use function Pango\shape_item;

use Pango\Ft2\FontMap;
use Pango\Context;

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);

// The idea is that if you have attributes that don’t affect shaping, such as color or underline, to avoid affecting shaping, you filter them out (pango_attr_list_filter()), apply the shaping process and then reapply them to the result using this function.

$text = "Hello, Παν語!";
$attrList = new AttributeList(
    "0 7 absolute-size 14,"          // Hello,␣
  . "7 13 foreground red,"  // Παν
  . "13 16 absolute-size 18,"        // 語
  . "16 17 foreground blue" // !
);
var_dump($attrList);

$itemizeAttributes = $attrList->filter(
  fn (Attribute $attr): bool => $attr instanceof SizeAttribute
);
var_dump($itemizeAttributes);

$items = $context->itemize($text, 0, 17, $itemizeAttributes);
var_dump($items);

$glyphString = shape_item($text, $items[0]);
var_dump($glyphString);
$glyphItem = new Pango\GlyphItem($items[0], $glyphString);
var_dump($glyphItem);
var_dump($glyphItem->applyAttributes($attrList, $text));

try {
  $glyphItem->applyAttributes();
} catch (ArgumentCountError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $glyphItem->applyAttributes($attrList, $text, 1);
} catch (ArgumentCountError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $glyphItem->applyAttributes(array());
} catch (TypeError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $glyphItem->applyAttributes($attrList, array());
} catch (TypeError $e) {
  echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Attribute\AttributeList)#%d (1) {
  ["string-representation"]=>
  string(86) "0 7 size 14
7 13 foreground #ffff00000000
13 16 size 18
16 17 foreground #00000000ffff"
}
object(Pango\Attribute\AttributeList)#%d (1) {
  ["string-representation"]=>
  string(25) "0 7 size 14
13 16 size 18"
}
array(4) {
  [0]=>
  object(Pango\Item)#%d (4) {
    ["offset"]=>
    int(0)
    ["length"]=>
    int(7)
    ["numChars"]=>
    int(7)
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
      enum(Pango\Script::Latin)
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
  [1]=>
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
  [2]=>
  object(Pango\Item)#%d (4) {
    ["offset"]=>
    int(13)
    ["length"]=>
    int(3)
    ["numChars"]=>
    int(1)
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
      enum(Pango\Script::Han)
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
  [3]=>
  object(Pango\Item)#%d (4) {
    ["offset"]=>
    int(16)
    ["length"]=>
    int(1)
    ["numChars"]=>
    int(1)
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
      enum(Pango\Script::Han)
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
}
object(Pango\GlyphString)#%d (2) {
  ["numGlyphs"]=>
  int(7)
  ["glyphs"]=>
  array(7) {
    [0]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(43)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(12)
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
      int(72)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(8)
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
      int(79)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(4)
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
    [3]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(79)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(4)
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
    [4]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(82)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(8)
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
    [5]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(15)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(4)
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
    [6]=>
    object(Pango\GlyphInfo)#%d (3) {
      ["glyph"]=>
      int(3)
      ["geometry"]=>
      object(Pango\GlyphGeometry)#%d (3) {
        ["width"]=>
        int(4)
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
object(Pango\GlyphItem)#%d (5) {
  ["item"]=>
  object(Pango\Item)#%d (4) {
    ["offset"]=>
    int(0)
    ["length"]=>
    int(7)
    ["numChars"]=>
    int(7)
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
      enum(Pango\Script::Latin)
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
  object(Pango\GlyphString)#%d (2) {
    ["numGlyphs"]=>
    int(7)
    ["glyphs"]=>
    array(7) {
      [0]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(43)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(12)
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
        int(72)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(8)
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
        int(79)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(4)
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
      [3]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(79)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(4)
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
      [4]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(82)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(8)
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
      [5]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(15)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(4)
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
      [6]=>
      object(Pango\GlyphInfo)#%d (3) {
        ["glyph"]=>
        int(3)
        ["geometry"]=>
        object(Pango\GlyphGeometry)#%d (3) {
          ["width"]=>
          int(4)
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
array(1) {
  [0]=>
  object(Pango\GlyphItem)#%d (5) {
    ["item"]=>
    object(Pango\Item)#%d (4) {
      ["offset"]=>
      int(0)
      ["length"]=>
      int(7)
      ["numChars"]=>
      int(7)
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
        enum(Pango\Script::Latin)
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
    object(Pango\GlyphString)#%d (2) {
      ["numGlyphs"]=>
      int(7)
      ["glyphs"]=>
      array(7) {
        [0]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(43)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(12)
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
          int(72)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(8)
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
          int(79)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(4)
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
        [3]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(79)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(4)
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
        [4]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(82)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(8)
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
        [5]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(15)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(4)
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
        [6]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(3)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(4)
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
}
Pango\GlyphItem::applyAttributes() expects at least 1 argument, 0 given
Pango\GlyphItem::applyAttributes() expects at most 2 arguments, 3 given
Pango\GlyphItem::applyAttributes(): Argument #1 ($list) must be of type Pango\Attribute\AttributeList, array given
Pango\GlyphItem::applyAttributes(): Argument #2 ($text) must be of type ?string, array given
