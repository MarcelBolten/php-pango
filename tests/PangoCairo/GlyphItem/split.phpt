--TEST--
PangoCairo\GlyphItem::split()
--EXTENSIONS--
pango
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

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->setText("Hello, Παν語!");
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
PangoCairo\GlyphItem::split(): Argument #1 ($splitByteIndex) must be greater than 0 and less than the items byte length (7) but 0 given
PangoCairo\GlyphItem::split(): Argument #1 ($splitByteIndex) must be greater than 0 and less than the items byte length (7) but 8 given
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
PangoCairo\GlyphItem::split() expects exactly 1 argument, 0 given
PangoCairo\GlyphItem::split() expects exactly 1 argument, 2 given
PangoCairo\GlyphItem::split(): Argument #1 ($splitByteIndex) must be of type int, array given
