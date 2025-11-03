--TEST--
Pango\LayoutLine::getExtents()
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

$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getExtents());

$layout->setText("Hello, Παν語!");
$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getExtents());

try {
    $line->getExtents(1);
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
object(Pango\LayoutLine)#%d (0) {
}
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(0)
    ["height"]=>
    int(0)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(0)
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
    int(-15360)
    ["width"]=>
    int(0)
    ["height"]=>
    int(19456)
    ["ascent"]=>
    int(15360)
    ["descent"]=>
    int(4096)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(0)
  }
}
object(Pango\LayoutLine)#%d (0) {
}
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(-13312)
    ["width"]=>
    int(111616)
    ["height"]=>
    int(16384)
    ["ascent"]=>
    int(13312)
    ["descent"]=>
    int(3072)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(111616)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(-19456)
    ["width"]=>
    int(112640)
    ["height"]=>
    int(24576)
    ["ascent"]=>
    int(19456)
    ["descent"]=>
    int(5120)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(112640)
  }
}
Pango\LayoutLine::getExtents() expects exactly 0 arguments, 1 given
