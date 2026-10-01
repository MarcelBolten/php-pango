--TEST--
Pango\TabStops::remove()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

$tabs = TabStops::fromString("left:10240 right:20480 decimal:30720:46 center:40960");
var_dump($tabs);
var_dump($tabs->getSize());
var_dump($tabs->getTabs()[2]);
$tabs->remove(1);
var_dump($tabs->getSize());
var_dump($tabs->getTabs()[1]);

try {
    $tabs->remove(-1);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->remove(5);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->remove();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->remove(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    $tabs->remove(array());
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
int(4)
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(30720)
  ["decimalChar"]=>
  string(1) "."
}
int(3)
object(Pango\TabStop)#%d (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Decimal)
  ["position"]=>
  int(30720)
  ["decimalChar"]=>
  string(1) "."
}
Pango\TabStops::remove(): Argument #1 ($index) must be between 0 and size - 1 (2) but -1 was given
Pango\TabStops::remove(): Argument #1 ($index) must be between 0 and size - 1 (2) but 5 was given
Pango\TabStops::remove() expects exactly 1 argument, 0 given
Pango\TabStops::remove() expects exactly 1 argument, 2 given
Pango\TabStops::remove(): Argument #1 ($index) must be of type int, array given
