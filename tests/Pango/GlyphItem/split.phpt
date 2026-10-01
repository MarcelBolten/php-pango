--TEST--
Pango\GlyphItem::split()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
function getOffsetAndLength(Pango\GlyphItem $glyphItem) {
    return [
        'offset' => $glyphItem->item->offset,
        'length' => $glyphItem->item->length,
    ];
}

$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext)
    ->setText("Hello, Παν語!");
var_dump($layout);

$runs = $layout->getLine(0)->getRuns();
$glyphItem = $runs[0];
var_dump(getOffsetAndLength($glyphItem));

try {
    $glyphItem->split(0);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->split(8);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

$newGlyphItem = $glyphItem->split(3);
var_dump(getOffsetAndLength($newGlyphItem));
var_dump(getOffsetAndLength($glyphItem));

try {
    $glyphItem->split();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->split(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $glyphItem->split(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
array(2) {
  ["offset"]=>
  int(0)
  ["length"]=>
  int(7)
}
Pango\GlyphItem::split(): Argument #1 ($splitByteIndex) must be greater than 0 and less than the items byte length (7) but 0 given
Pango\GlyphItem::split(): Argument #1 ($splitByteIndex) must be greater than 0 and less than the items byte length (7) but 8 given
array(2) {
  ["offset"]=>
  int(0)
  ["length"]=>
  int(3)
}
array(2) {
  ["offset"]=>
  int(3)
  ["length"]=>
  int(4)
}
Pango\GlyphItem::split() expects exactly 1 argument, 0 given
Pango\GlyphItem::split() expects exactly 1 argument, 2 given
Pango\GlyphItem::split(): Argument #1 ($splitByteIndex) must be of type int, array given
