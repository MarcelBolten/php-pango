--TEST--
Pango\LayoutIter::getCharExtents()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

$layout->setWidth(100 * Pango\SCALE);
$layout->setText("Lorem ipsum dolor sit amet");

$layoutIter = $layout->getIter();
var_dump($layoutIter);
var_dump($layoutIter->getCharExtents());

try {
    $layoutIter->getCharExtents(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\LayoutIter)#%d (0) {
}
object(Pango\Rectangle)#%d (8) {
  ["x"]=>
  int(0)
  ["y"]=>
  int(0)
  ["width"]=>
  int(11264)
  ["height"]=>
  int(19456)
  ["ascent"]=>
  int(0)
  ["descent"]=>
  int(19456)
  ["leftBearing"]=>
  int(0)
  ["rightBearing"]=>
  int(11264)
}
Pango\LayoutIter::getCharExtents() expects exactly 0 arguments, 1 given
