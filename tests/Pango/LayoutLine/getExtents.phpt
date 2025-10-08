--TEST--
Pango\LayoutLine::getExtents()
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
object(Cairo\Context)#%d (0) {
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
    int(-19456)
    ["width"]=>
    int(0)
    ["height"]=>
    int(24576)
    ["ascent"]=>
    int(19456)
    ["descent"]=>
    int(5120)
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
    int(1024)
    ["y"]=>
    int(-13312)
    ["width"]=>
    int(100352)
    ["height"]=>
    int(17408)
    ["ascent"]=>
    int(13312)
    ["descent"]=>
    int(4096)
    ["leftBearing"]=>
    int(1024)
    ["rightBearing"]=>
    int(101376)
  }
  ["logical"]=>
  object(Pango\Rectangle)#%d (8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(-19456)
    ["width"]=>
    int(102400)
    ["height"]=>
    int(24576)
    ["ascent"]=>
    int(19456)
    ["descent"]=>
    int(5120)
    ["leftBearing"]=>
    int(0)
    ["rightBearing"]=>
    int(102400)
  }
}
Pango\LayoutLine::getExtents() expects exactly 0 arguments, 1 given
