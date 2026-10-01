--TEST--
Pango\TabStops::__construct()
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

$tabs_array = [
    new TabStop(TabAlign::Right, 20480),
    new TabStop(TabAlign::Left, 10240),
    new TabStop(TabAlign::Center, 40960),
    new TabStop(TabAlign::Decimal, 30720, ","),
];

$tabs = new TabStops($tabs_array);
var_dump($tabs);
var_dump($tabs->getTabs()[0]);
var_dump($tabs->getTabs()[3]);

var_dump(new TabStops([]));
var_dump(new TabStops([])->getTab(0));

try {
    new TabStops([1, 2, 3]);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops([new stdClass()]);
} catch (TypeError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops([new TabStop(TabAlign::Left, 10240), new TabStopPixel(TabAlign::Decimal, 100, ",")]);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops([new TabStopPixel(TabAlign::Decimal, 100, ","), new TabStop(TabAlign::Left, 10240)]);
} catch (ValueError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops(array(), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}

try {
    new TabStops(1);
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
  enum(Pango\TabAlign::Center)
  ["position"]=>
  int(40960)
  ["decimalChar"]=>
  NULL
}
object(Pango\TabStops)#11 (0) {
}
NULL
Pango\TabStops::__construct(): Argument #1 ($tabStops) must be an array of Pango\TabStop objects
Pango\TabStops::__construct(): Argument #1 ($tabStops) must be an array of Pango\TabStop objects
Pango\TabStops::__construct(): Argument #1 ($tabStops) must be of type Pango\TabStop for this TabStops instance, but Pango\TabStopPixel was given
Pango\TabStops::__construct(): Argument #1 ($tabStops) must be of type Pango\TabStopPixel for this TabStops instance, but Pango\TabStop was given
Pango\TabStops::__construct() expects exactly 1 argument, 0 given
Pango\TabStops::__construct() expects exactly 1 argument, 2 given
Pango\TabStops::__construct(): Argument #1 ($tabStops) must be of type array, int given