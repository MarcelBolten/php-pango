--TEST--
Pango\TabStops::__toString()
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\TabStops;

$tabs = TabStops::fromString("decimal:10240:65");
var_dump($tabs);
var_dump($tabs->__toString());
echo $tabs, "\n";

$tabs = TabStops::fromString("");
var_dump($tabs);
var_dump($tabs->__toString());
echo $tabs, "\n";

try {
    $tabs->__toString(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECTF--
object(Pango\TabStops)#%d (0) {
}
string(16) "decimal:10240:65"
decimal:10240:65
object(Pango\TabStops)#%d (0) {
}
string(0) ""

Pango\TabStops::__toString() expects exactly 0 arguments, 1 given
