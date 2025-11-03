--TEST--
Pango\Layout::getSize()
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
Pango\Layout::getSize() expects exactly 0 arguments, 1 given
