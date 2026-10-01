--TEST--
Pango\TabStops::getTab()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

$tabs = TabStops::fromString("decimal:10240:46 right:20480 left:30720 center:40960");
var_dump($tabs);
var_dump($tabs->getTab(0));

try {
    $tabs->getTab(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->getTab(4);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

$tabs2 = TabStops::fromString("right:100px");
var_dump($tabs2);
var_dump($tabs2->getTab(0));

try {
    $tabs->getTab();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->getTab(0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->getTab(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  string(1) "."
}
Pango\TabStops::getTab(): Argument #1 ($index) must be between 0 and size - 1 (3) but -1 was given
Pango\TabStops::getTab(): Argument #1 ($index) must be between 0 and size - 1 (3) but 4 was given
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStopPixel)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Right)
  ["position"]=>
  int(100)
  ["decimalChar"]=>
  NULL
}
Pango\TabStops::getTab() expects exactly 1 argument, 0 given
Pango\TabStops::getTab() expects exactly 1 argument, 2 given
Pango\TabStops::getTab(): Argument #1 ($index) must be of type int, array given
