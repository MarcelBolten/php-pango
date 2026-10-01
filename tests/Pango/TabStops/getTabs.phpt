--TEST--
Pango\TabStops::getTabs()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

$tabs = TabStops::fromString("decimal:10240:46 right:20480 left:30720 center:40960");
var_dump($tabs);
var_dump($tabs->getTabs());

$tabs2 = TabStops::fromString("decimal:100px:46");
var_dump($tabs2);
var_dump($tabs2->getTabs());

$tabs3 = TabStops::fromString("");
var_dump($tabs3);
var_dump($tabs3->getTabs());

try {
    $tabs->getTabs(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
array(4) {
  [0]=>
  object(Pango\TabStop)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Decimal)
    ["position"]=>
    int(10240)
    ["decimalChar"]=>
    string(1) "."
  }
  [1]=>
  object(Pango\TabStop)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Right)
    ["position"]=>
    int(20480)
    ["decimalChar"]=>
    NULL
  }
  [2]=>
  object(Pango\TabStop)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Left)
    ["position"]=>
    int(30720)
    ["decimalChar"]=>
    NULL
  }
  [3]=>
  object(Pango\TabStop)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Center)
    ["position"]=>
    int(40960)
    ["decimalChar"]=>
    NULL
  }
}
object(Pango\TabStops)#%d (0) {
}
array(1) {
  [0]=>
  object(Pango\TabStopPixel)#%d (3) {
    ["alignment"]=>
    enum(Pango\TabAlign::Decimal)
    ["position"]=>
    int(100)
    ["decimalChar"]=>
    string(1) "."
  }
}
object(Pango\TabStops)#%d (0) {
}
array(0) {
}
Pango\TabStops::getTabs() expects exactly 0 arguments, 1 given
