--TEST--
Pango\LayoutIter::getLineYrange()
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

$layout->setWidth(100 * Pango\SCALE);
$layout->setText("Lorem ipsum dolor sit amet");

$layoutIter = $layout->getIter();
var_dump($layoutIter);
var_dump($layoutIter->getLineYrange());

try {
    $layoutIter->getLineYrange(1);
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
object(Pango\LayoutIter)#%d (0) {
}
array(2) {
  ["y0"]=>
  int(0)
  ["y1"]=>
  int(19456)
}
Pango\LayoutIter::getLineYrange() expects exactly 0 arguments, 1 given
