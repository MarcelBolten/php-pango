--TEST--
Pango\GlyphItem::applyAttributes()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php

use Pango\Attribute\{
  Attribute,
  AttributeList,
  Size,
};
use function Pango\shape_item;

$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

// The idea is that if you have attributes that don’t affect shaping, such as color or underline, to avoid affecting shaping, you filter them out (pango_attr_list_filter()), apply the shaping process and then reapply them to the result using this function.

$text = "Hello, Παν語!";
$attrList = new AttributeList(
    "0 7 size 14,"          // Hello,␣
  . "7 13 foreground red,"  // Παν
  . "13 16 size 18,"        // 語
  . "16 17 foreground blue" // !
);
var_dump($attrList);

$itemizeAttributes = $attrList->filter(
  fn (Attribute $attr): bool => $attr instanceof Size
);
var_dump($itemizeAttributes->toString());

$items = new PangoCairo\Context($cairoContext)->itemize($text, 0, 17, $itemizeAttributes);
var_dump($items);
$glyphString = shape_item($text, $items[0]);
var_dump($glyphString);

$glyphString

// look at pango/tests/test-shape.c to implement test


foreach ($items as $item) {
  $item->applyAttributes($iter);
}
var_dump($items);

try {
  $items[0]->applyAttributes();
} catch (ArgumentCountError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $items[0]->applyAttributes($iter, 1);
} catch (ArgumentCountError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $items[0]->applyAttributes(array());
} catch (TypeError $e) {
  echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(Pango\Attribute\AttributeList)#%d (0) {
}
string(25) "0 7 size 14
13 16 size 18"
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
        string(18) "DejaVu Serif 0.014"
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
        string(1) "c"
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
        string(15) "DejaVu Serif 12"
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
        string(22) "Noto Sans CJK JP 0.018"
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
        string(1) "c"
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
        string(15) "DejaVu Serif 12"
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
        string(1) "c"
      }
      ["extraAttrs"]=>
      array(0) {
      }
    }
  }
}
object(Pango\Attribute\AttributeIterator)#%d (0) {
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
        string(18) "DejaVu Serif 0.014"
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
        string(1) "c"
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
        string(15) "DejaVu Serif 12"
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
      array(1) {
        [0]=>
        object(Pango\Attribute\Foreground)#%d (3) {
          ["startIndex"]=>
          int(7)
          ["endIndex"]=>
          int(13)
          ["color"]=>
          object(Pango\Color)#%d (3) {
            ["red"]=>
            int(65535)
            ["green"]=>
            int(0)
            ["blue"]=>
            int(0)
          }
        }
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
        string(22) "Noto Sans CJK JP 0.018"
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
        string(1) "c"
      }
      ["extraAttrs"]=>
      array(1) {
        [0]=>
        object(Pango\Attribute\Foreground)#%d (3) {
          ["startIndex"]=>
          int(7)
          ["endIndex"]=>
          int(13)
          ["color"]=>
          object(Pango\Color)#%d (3) {
            ["red"]=>
            int(65535)
            ["green"]=>
            int(0)
            ["blue"]=>
            int(0)
          }
        }
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
        string(15) "DejaVu Serif 12"
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
        string(1) "c"
      }
      ["extraAttrs"]=>
      array(1) {
        [0]=>
        object(Pango\Attribute\Foreground)#%d (3) {
          ["startIndex"]=>
          int(16)
          ["endIndex"]=>
          int(17)
          ["color"]=>
          object(Pango\Color)#%d (3) {
            ["red"]=>
            int(0)
            ["green"]=>
            int(0)
            ["blue"]=>
            int(65535)
          }
        }
      }
    }
  }
}
Pango\Item::applyAttributes() expects exactly 1 argument, 0 given
Pango\Item::applyAttributes() expects exactly 1 argument, 2 given
Pango\Item::applyAttributes(): Argument #1 ($iter) must be of type Pango\Attribute\AttributeIterator, array given
