--TEST--
Pango\Layout::getPixelExtents()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
array(2) {
  ["ink"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(19)
    ["width"]=>
    int(0)
    ["height"]=>
    int(0)
    ["ascent"]=>
    int(-19)
    ["descent"]=>
    int(19)
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
    int(24)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(24)
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
    int(1)
    ["y"]=>
    int(6)
    ["width"]=>
    int(98)
    ["height"]=>
    int(17)
    ["ascent"]=>
    int(-6)
    ["descent"]=>
    int(23)
    ["leftBearing"]=>
    int(1)
    ["rightBearing"]=>
    int(99)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(100)
    ["height"]=>
    int(24)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(24)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(100)
  }
}
Pango\Layout::getPixelExtents() expects exactly 0 arguments, 1 given
