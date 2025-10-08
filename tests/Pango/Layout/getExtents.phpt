--TEST--
Pango\Layout::getExtents()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$cairoContext = new Cairo\Context(new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 1, 1));
$cairoContext->selectFontFace('Noto Sans');
var_dump($cairoContext);

$layout = new Pango\Layout($cairoContext);
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
    int(19456)
    ["width"]=>
    int(0)
    ["height"]=>
    int(0)
    ["ascent"]=>
    int(-19456)
    ["descent"]=>
    int(19456)
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
    int(24576)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(24576)
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
    int(6144)
    ["width"]=>
    int(81920)
    ["height"]=>
    int(39936)
    ["ascent"]=>
    int(-6144)
    ["descent"]=>
    int(46080)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(81920)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(0)
    ["width"]=>
    int(80896)
    ["height"]=>
    int(49152)
    ["ascent"]=>
    int(0)
    ["descent"]=>
    int(49152)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(80896)
  }
}
Pango\Layout::getExtents() expects exactly 0 arguments, 1 given
