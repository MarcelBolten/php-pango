--TEST--
Pango\Layout::getPixelExtents()
--EXTENSIONS--
pango
cairo
--FILE--
<?php
use PangoCairo\FontMap;

$fontMap = FontMap::getDefault();
var_dump($fontMap);

$pangoContext = new Pango\Context($fontMap);
var_dump($pangoContext);

$layout = new Pango\Layout($pangoContext);
var_dump($layout);

var_dump($layout->getPixelExtents());

// Todo: The values are fluctuating, need to investigate why
// probably related to the unintialized pango values, compare to output of `run-tests.php -m`
$layout->setText("Hello, Παν語!");
var_dump($layout->getPixelExtents());

try {
    $layout->getPixelExtents('wrong');
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
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(15)
    ["width"]=>
    int(0)
    ["height"]=>
    int(0)
    ["ascent"]=>
    int(-15)
    ["descent"]=>
    int(15)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(0)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(0)
    ["height"]=>
    int(19)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(19)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(0)
  }
}
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(6)
    ["width"]=>
    int(109)
    ["height"]=>
    int(16)
    ["ascent"]=>
    int(-6)
    ["descent"]=>
    int(22)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(109)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(110)
    ["height"]=>
    int(24)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(24)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(110)
  }
}
Pango\Layout::getPixelExtents() expects exactly 0 arguments, 1 given
