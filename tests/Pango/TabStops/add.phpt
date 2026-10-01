--TEST--
Pango\TabStops::add()
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
$tabs->add($tab);
var_dump($tabs->getTab(2)); // should be the new tab stop

try {
    $tabs->set(0, new TabStopPixel(TabAlign::Left, 200));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

$tabs2 = TabStops::fromString("left:100px");

try {
    $tabs2->add(new TabStop(TabAlign::Right, 200));
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->add();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->add($tab, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->add(array());
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
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(30720)
  ["decimalChar"]=>
  string(1) ","
}
Pango\TabStops::set(): Argument #2 ($tabStop) must be of type Pango\TabStop for this TabStops instance, but Pango\TabStopPixel was given
Pango\TabStops::add(): Argument #1 ($tabStop) must be of type Pango\TabStopPixel for this TabStops instance, but Pango\TabStop was given
Pango\TabStops::add() expects exactly 1 argument, 0 given
Pango\TabStops::add() expects exactly 1 argument, 2 given
Pango\TabStops::add(): Argument #1 ($tabStop) must be of type Pango\TabStop, array given