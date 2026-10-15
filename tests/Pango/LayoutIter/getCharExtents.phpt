--TEST--
Pango\LayoutIter::getCharExtents()
--EXTENSIONS--
pango
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
  int(%i)
  ["y"]=>
  int(%i)
  ["width"]=>
  int(%i)
  ["height"]=>
  int(%i)
  ["ascent"]=>
  int(%i)
  ["descent"]=>
  int(%i)
  ["leftBearing"]=>
  int(%i)
  ["rightBearing"]=>
  int(%i)
}
Pango\LayoutIter::getCharExtents() expects exactly 0 arguments, 1 given
