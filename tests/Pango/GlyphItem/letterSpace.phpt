--TEST--
Pango\GlyphItem::letterSpace()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Ft2\FontMap;
use Pango\Context;
use Pango\Layout;

function getXOffsetAndWidth(Pango\GlyphItem $glyphItem) {
    return array_map(fn(Pango\GlyphInfo $glyph) => [
            'xOffset' => $glyph->geometry->xOffset,
            'width' => $glyph->geometry->width,
    ], $glyphItem->glyphs->glyphs);
}

$fontMap = new FontMap();
$pathToFonts = dirname(__FILE__, 3) . "/assets/fonts";
$fontMap->addFontFile($pathToFonts . "/DejaVuSans.ttf");
$fontMap->addFontFile($pathToFonts . "/NotoSansJP-Regular.otf");
$fontMap->addFontFile($pathToFonts . "/NotoSans-Regular.ttf");
var_dump($fontMap);
$context = new Context($fontMap);
var_dump($context);
$layout = new Layout($context);
var_dump($layout);

$layout->setText("Hello, Παν語!");
$runs = $layout->getLine(0)->getRuns();
$glyphItem = $runs[1];
var_dump(getXOffsetAndWidth($glyphItem));

$glyphItem->letterSpace(30);
var_dump(getXOffsetAndWidth($glyphItem));

try {
    $glyphItem->letterSpace(1 << 31);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->letterSpace(-(1 << 31) -1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->letterSpace();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->letterSpace(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->letterSpace(array());
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
array(3) {
  [0]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
  [1]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
  [2]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
}
array(3) {
  [0]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
  [1]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
  [2]=>
  array(2) {
    ["xOffset"]=>
    int(%i)
    ["width"]=>
    int(%i)
  }
}
Pango\GlyphItem::letterSpace(): Argument #1 ($spacing) must be greater than or equal to -2147483648 and less than or equal to 2147483647
Pango\GlyphItem::letterSpace(): Argument #1 ($spacing) must be greater than or equal to -2147483648 and less than or equal to 2147483647
Pango\GlyphItem::letterSpace() expects exactly 1 argument, 0 given
Pango\GlyphItem::letterSpace() expects exactly 1 argument, 2 given
Pango\GlyphItem::letterSpace(): Argument #1 ($spacing) must be of type int, array given
