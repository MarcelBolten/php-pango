--TEST--
Pango\GlyphItem::letterSpace()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
function getXOffsetAndWidth(Pango\GlyphItem $glyphItem) {
    return array_map(fn(Pango\GlyphInfo $glyph) => [
            'xOffset' => $glyph->geometry->xOffset,
            'width' => $glyph->geometry->width,
    ], $glyphItem->glyphs->glyphs);
}

$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = (new PangoCairo\Layout($cairoContext))
    ->setText("Hello, Παν語!");
var_dump($layout);

$runs = $layout->getLine(0)->getRuns();
$glyphItem = $runs[1];
var_dump(getXOffsetAndWidth($glyphItem));

$glyphItem->letterSpace(30);
var_dump(getXOffsetAndWidth($glyphItem));

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
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
array(3) {
  [0]=>
  array(2) {
    ["xOffset"]=>
    int(0)
    ["width"]=>
    int(14336)
  }
  [1]=>
  array(2) {
    ["xOffset"]=>
    int(0)
    ["width"]=>
    int(11264)
  }
  [2]=>
  array(2) {
    ["xOffset"]=>
    int(0)
    ["width"]=>
    int(10240)
  }
}
array(3) {
  [0]=>
  array(2) {
    ["xOffset"]=>
    int(0)
    ["width"]=>
    int(14351)
  }
  [1]=>
  array(2) {
    ["xOffset"]=>
    int(15)
    ["width"]=>
    int(11294)
  }
  [2]=>
  array(2) {
    ["xOffset"]=>
    int(15)
    ["width"]=>
    int(10255)
  }
}
Pango\GlyphItem::letterSpace() expects exactly 1 argument, 0 given
Pango\GlyphItem::letterSpace() expects exactly 1 argument, 2 given
Pango\GlyphItem::letterSpace(): Argument #1 ($spacing) must be of type int, array given
