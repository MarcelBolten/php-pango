--TEST--
Pango\Item::split()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new PangoCairo\Layout($cairoContext);
var_dump($layout);

$layout->setText("Hello, Παν語!");
$item = $layout
  ->getLine(0) // only one line
  ->getRuns()[1] // the second run contains 3 Greek character
  ->item;

var_dump($item->offset);
var_dump($item->length);
var_dump($item->numChars);

$splitItem = $item->split(2, 1);

var_dump($splitItem->offset);
var_dump($splitItem->length);
var_dump($splitItem->numChars);

var_dump($item->offset);
var_dump($item->length);
var_dump($item->numChars);

try {
  $item->split(0, 1);
} catch (ValueError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $item->split(4, 1);
} catch (ValueError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $item->split(2, 0);
} catch (ValueError $e) {
  echo $e->getMessage(), "\n";
}

try {
  $item->split(2, 2);
} catch (ValueError $e) {
  echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Cairo\Context)#%d (0) {
}
object(PangoCairo\Layout)#%d (0) {
}
int(7)
int(6)
int(3)
int(7)
int(2)
int(1)
int(9)
int(4)
int(2)
Pango\Item::split(): Argument #1 ($byteIndex) must be greater than 0 and less than the items byte length (4) but 0 given
Pango\Item::split(): Argument #1 ($byteIndex) must be greater than 0 and less than the items byte length (4) but 4 given
Pango\Item::split(): Argument #2 ($charOffset) must be greater than 0 and less than the items character count (2) but 0 given
Pango\Item::split(): Argument #2 ($charOffset) must be greater than 0 and less than the items character count (2) but 2 given
