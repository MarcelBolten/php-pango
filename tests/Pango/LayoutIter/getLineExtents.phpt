--TEST--
Pango\LayoutIter::getLineExtents()
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
var_dump($layoutIter->getLineExtents());

try {
    $layoutIter->getLineExtents(1);
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
  ["logical"]=>
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
}
Pango\LayoutIter::getLineExtents() expects exactly 0 arguments, 1 given
