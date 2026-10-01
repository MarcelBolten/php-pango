--TEST--
Pango\TabStops::set()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;
use Pango\TabStop;
use Pango\TabStopPixel;
use Pango\TabAlign;

$tabs = TabStops::fromString("left:10240 right:20480");
var_dump($tabs);
var_dump($tabs->getTab(0));
$tab = new TabStop(TabAlign::Decimal, 30720, ",");
var_dump($tab);
$tabs->set(0, $tab);
var_dump($tabs->getTab(0)); // right:20480
var_dump($tabs->getTab(1)); // should be the new tab stop

try {
    $tabs->set(2, $tab);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->set(0, new TabStopPixel(TabAlign::Left, 200));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

$tabs2 = TabStops::fromString("left:100px");

try {
    $tabs2->set(0, new TabStop(TabAlign::Right, 100));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->set();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->set(0, $tab, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->set(array(), $tab);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->set(0, array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Left)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  NULL
}
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(30720)
  ["decimalChar"]=>
  string(1) ","
}
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Right)
  ["position"]=>
  int(20480)
  ["decimalChar"]=>
  NULL
}
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(30720)
  ["decimalChar"]=>
  string(1) ","
}
Pango\TabStops::set(): Argument #1 ($index) must be between 0 and size - 1 (1) but 2 was given
Pango\TabStops::set(): Argument #2 ($tabStop) must be of type Pango\TabStop for this TabStops instance, but Pango\TabStopPixel was given
Pango\TabStops::set(): Argument #2 ($tabStop) must be of type Pango\TabStopPixel for this TabStops instance, but Pango\TabStop was given
Pango\TabStops::set() expects exactly 2 arguments, 0 given
Pango\TabStops::set() expects exactly 2 arguments, 3 given
Pango\TabStops::set(): Argument #1 ($index) must be of type int, array given
Pango\TabStops::set(): Argument #2 ($tabStop) must be of type Pango\TabStop, array given
