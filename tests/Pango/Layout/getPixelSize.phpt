--TEST--
Pango\Layout::getPixelSize()
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
object(PangoCairo\FontMap)#%d (0) {
}
object(Pango\Context)#%d (0) {
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
Pango\Layout::getPixelSize() expects exactly 0 arguments, 1 given
