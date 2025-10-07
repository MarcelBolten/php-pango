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
object(Cairo\Context)#1 (0) {
}
object(Pango\Layout)#4 (0) {
}
array(2) {
  ["ink"]=>
  array(4) {
    ["x"]=>
    int(%d)
    ["y"]=>
    int(%d)
    ["width"]=>
    int(%d)
    ["height"]=>
    int(%d)
  }
  ["logical"]=>
  array(4) {
    ["x"]=>
    int(%d)
    ["y"]=>
    int(%d)
    ["width"]=>
    int(%d)
    ["height"]=>
    int(%d)
  }
}
array(2) {
  ["ink"]=>
  array(4) {
    ["x"]=>
    int(%d)
    ["y"]=>
    int(%d)
    ["width"]=>
    int(%d)
    ["height"]=>
    int(%d)
  }
  ["logical"]=>
  array(4) {
    ["x"]=>
    int(%d)
    ["y"]=>
    int(%d)
    ["width"]=>
    int(%d)
    ["height"]=>
    int(%d)
  }
}
Pango\Layout::getExtents() expects exactly 0 arguments, 1 given
