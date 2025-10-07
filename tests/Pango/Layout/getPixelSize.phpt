--TEST--
Pango\Layout::getPixelSize()
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

// There are some uninitialized values in the pango library
// that cause memory issue reports by valgrind when running `run-test.php -m`
// TODO: try to add a suppression file for valgrind

var_dump($layout->getPixelSize());

$layout->setText("Hello, Παν語!");
var_dump($layout->getPixelSize());

try {
    $layout->getPixelSize('wrong');
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
  ["width"]=>
  int(%d)
  ["height"]=>
  int(%d)
}
array(2) {
  ["width"]=>
  int(%d)
  ["height"]=>
  int(%d)
}
Pango\Layout::getPixelSize() expects exactly 0 arguments, 1 given
