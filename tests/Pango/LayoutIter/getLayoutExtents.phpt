--TEST--
Pango\LayoutIter::getLayoutExtents()
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
var_dump($layoutIter->getLayoutExtents());

try {
    $layoutIter->getLayoutExtents(1);
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
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(3072)
    ["width"]=>
    int(98304)
    ["height"]=>
    int(51200)
    ["ascent"]=>
    int(-3072)
    ["descent"]=>
    int(54272)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(98304)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(98304)
    ["height"]=>
    int(58368)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(58368)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(98304)
  }
}
Pango\LayoutIter::getLayoutExtents() expects exactly 0 arguments, 1 given
