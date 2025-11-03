--TEST--
Pango\Layout::getExtents()
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

var_dump($layout->getExtents());

$layout->setWidth(100 * Pango\Pango::SCALE);
// Todo: The values are fluctuating, need to investigate why
// probably related to the unintialized pango values,
// compare to output of `run-tests.php -m`
// when $cairoContext->selectFontFace('Sans') and setWidth() is commented out
$layout->setText("Hello, Παν語! ");
var_dump($layout->getExtents());

try {
    $layout->getExtents('wrong');
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
    int(15360)
    ["width"]=>
    int(0)
    ["height"]=>
    int(0)
    ["ascent"]=>
    int(-15360)
    ["descent"]=>
    int(15360)
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
    int(19456)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(19456)
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
    int(2048)
    ["width"]=>
    int(89088)
    ["height"]=>
    int(38912)
    ["ascent"]=>
    int(-2048)
    ["descent"]=>
    int(40960)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(89088)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(90112)
    ["height"]=>
    int(44032)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(44032)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(90112)
  }
}
Pango\Layout::getExtents() expects exactly 0 arguments, 1 given
