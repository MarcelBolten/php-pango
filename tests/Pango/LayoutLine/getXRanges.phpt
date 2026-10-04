--TEST--
Pango\LayoutLine::getXRanges()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use Pango\Ft2\FontMap;

$fontMap = new FontMap();
var_dump($fontMap);
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/dejavu-sans-ttf-2.37/ttf/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSerifJP/SubsetOTF/JP/NotoSerifJP-Regular.otf");

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$line = $layout->getLineReadonly(0);
var_dump($line->getXRanges());

$counts = array();
$text = "Hello,\nΠαν語!";
$layout->setText($text);
foreach ($layout->getLinesReadonly() as $id => $line) {
    var_dump($line->getRuns());
    $xRanges = $line->getXRanges();
    var_dump($xRanges);
    $counts[$id] = count($xRanges);
}

/*
 * Set a fixed width for the layout.
 * Now there should be 1 more xRange for each line,
 * because the last xRange ends at the end of the line,
 * which is not the end of the text
 */
$layout->setWidth(100_000);
$lenPlusOne = strlen($text) + 1;
foreach ($layout->getLinesReadonly() as $id => $line) {
    $xRanges = $line->getXRanges(byteEnd: $lenPlusOne);
    // assert(count($xRanges) === $counts[$id] + 1);
}

try {
    $line->getXRanges(2, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(-1, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(2147483647 + 1, 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(0, -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(0, 2147483647 + 1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(array(), 2);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $line->getXRanges(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\Ft2\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(0) {
}
array(1) {
  [0]=>
  object(Pango\GlyphItem)#%d (5) {
    ["item"]=>
    object(Pango\Item)#%d (4) {
      ["offset"]=>
      int(0)
      ["length"]=>
      int(6)
      ["numChars"]=>
      int(6)
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
    ["glyphs"]=>
    object(Pango\GlyphString)#%d (2) {
      ["numGlyphs"]=>
      int(6)
      ["glyphs"]=>
      array(6) {
        [0]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(43)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(10240)
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
            int(7168)
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
            int(4096)
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
            int(4096)
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
            int(7168)
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
            int(4096)
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
array(1) {
  [0]=>
  array(3) {
    ["start"]=>
    int(0)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
}
array(3) {
  [0]=>
  object(Pango\GlyphItem)#%d (5) {
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
    ["glyphs"]=>
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
            int(10240)
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
            int(8192)
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
            int(7168)
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
  [1]=>
  object(Pango\GlyphItem)#%d (5) {
    ["item"]=>
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
          string(16) "Noto Serif JP 12"
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
    ["glyphs"]=>
    object(Pango\GlyphString)#%d (2) {
      ["numGlyphs"]=>
      int(1)
      ["glyphs"]=>
      array(1) {
        [0]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(12189)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(12288)
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
  [2]=>
  object(Pango\GlyphItem)#%d (5) {
    ["item"]=>
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
    ["glyphs"]=>
    object(Pango\GlyphString)#%d (2) {
      ["numGlyphs"]=>
      int(1)
      ["glyphs"]=>
      array(1) {
        [0]=>
        object(Pango\GlyphInfo)#%d (3) {
          ["glyph"]=>
          int(4)
          ["geometry"]=>
          object(Pango\GlyphGeometry)#%d (3) {
            ["width"]=>
            int(5120)
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
array(3) {
  [0]=>
  array(3) {
    ["start"]=>
    int(0)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
  [1]=>
  array(3) {
    ["start"]=>
    int(%d)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
  [2]=>
  array(3) {
    ["start"]=>
    int(%d)
    ["end"]=>
    int(%d)
    ["width"]=>
    int(%d)
  }
}
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be be greater than argument #1 ($byteStart) 2 but 1 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be between 0 and 2147483647 but -1 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be between 0 and 2147483647 but 2147483648 given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be between 0 and 2147483647 but -1 given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be between 0 and 2147483647 but 2147483648 given
Pango\LayoutLine::getXRanges() expects at most 2 arguments, 3 given
Pango\LayoutLine::getXRanges(): Argument #1 ($byteStart) must be of type ?int, array given
Pango\LayoutLine::getXRanges(): Argument #2 ($byteEnd) must be of type ?int, array given
