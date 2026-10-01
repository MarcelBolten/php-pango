--TEST--
Pango\TabStops::getSize()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStops;

$tab = TabStops::fromString("10240 20480 40960");
var_dump($tab);
var_dump($tab->getSize());

try {
    $tab->getSize(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
int(3)
Pango\TabStops::getSize() expects exactly 0 arguments, 1 given
