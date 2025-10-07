--TEST--
Pango\Layout::getSize()
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

var_dump($layout->getSize());

$layout->setText("Hello, Παν語!");
var_dump($layout->getSize());

try {
    $layout->getSize('wrong');
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
Pango\Layout::getSize() expects exactly 0 arguments, 1 given
