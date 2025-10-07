--TEST--
Pango\LayoutLine::getPixelExtents()
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
object(Cairo\Context)#%d (0) {
}
object(Pango\Layout)#%d (0) {
}
object(Pango\LayoutLine)#%d (0) {
}
array(2) {
  ["ink"]=>
  array(8) {
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
    ["lbearing"]=>
    int(0)
    ["rbearing"]=>
    int(0)
  }
  ["logical"]=>
  array(8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(-19)
    ["width"]=>
    int(0)
    ["height"]=>
    int(24)
    ["ascent"]=>
    int(19)
    ["descent"]=>
    int(5)
    ["lbearing"]=>
    int(0)
    ["rbearing"]=>
    int(0)
  }
}
object(Pango\LayoutLine)#%d (0) {
}
array(2) {
  ["ink"]=>
  array(8) {
    ["x"]=>
    int(1)
    ["y"]=>
    int(-13)
    ["width"]=>
    int(98)
    ["height"]=>
    int(17)
    ["ascent"]=>
    int(13)
    ["descent"]=>
    int(4)
    ["lbearing"]=>
    int(1)
    ["rbearing"]=>
    int(99)
  }
  ["logical"]=>
  array(8) {
    ["x"]=>
    int(0)
    ["y"]=>
    int(-19)
    ["width"]=>
    int(100)
    ["height"]=>
    int(24)
    ["ascent"]=>
    int(19)
    ["descent"]=>
    int(5)
    ["lbearing"]=>
    int(0)
    ["rbearing"]=>
    int(100)
  }
}
Pango\LayoutLine::getPixelExtents() expects exactly 0 arguments, 1 given
