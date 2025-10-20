--TEST--
Pango\LayoutLine::getPixelExtents()
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

$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getPixelExtents());

$layout->setText("Hello, Παν語!");
$line = $layout->getLineReadonly(0);
var_dump($line);
var_dump($line->getPixelExtents());

try {
    $line->getPixelExtents(1);
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
    int(-15)
    ["width"]=>
    int(0)
    ["height"]=>
    int(19)
    ["ascent"]=>
    int(15)
    ["descent"]=>
    int(4)
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
    int(-13)
    ["width"]=>
    int(109)
    ["height"]=>
    int(16)
    ["ascent"]=>
    int(13)
    ["descent"]=>
    int(3)
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
    int(-19)
    ["width"]=>
    int(110)
    ["height"]=>
    int(24)
    ["ascent"]=>
    int(19)
    ["descent"]=>
    int(5)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(110)
  }
}
Pango\LayoutLine::getPixelExtents() expects exactly 0 arguments, 1 given
