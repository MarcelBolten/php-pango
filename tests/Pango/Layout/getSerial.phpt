--TEST--
Pango\Layout::getSerial()
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

var_dump($layout->getSerial());

$layout->setText("Hello, Παν語!");
var_dump($layout->getSerial());

$layout->contextChanged();
var_dump($layout->getSerial());

try {
    $layout->getSerial('wrong');
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
int(1)
int(2)
int(3)
Pango\Layout::getSerial() expects exactly 0 arguments, 1 given
