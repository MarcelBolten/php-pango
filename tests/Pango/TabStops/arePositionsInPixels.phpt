--TEST--
Pango\TabStops::arePositionsInPixels()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

$tab = TabStops::fromString("10240");
var_dump($tab);
var_dump($tab->arePositionsInPixels());

$tab2 = TabStops::fromString("100px");
var_dump($tab2);
var_dump($tab2->arePositionsInPixels());

try {
    $tab2->arePositionsInPixels(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
bool(false)
object(Pango\TabStops)#%d (0) {
}
bool(true)
Pango\TabStops::arePositionsInPixels() expects exactly 0 arguments, 1 given
