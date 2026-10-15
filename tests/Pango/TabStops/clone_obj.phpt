--TEST--
Pango\TabStops clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\TabStops;

$tab = TabStops::fromString("10240 20480 40960");
var_dump($tab);
var_dump(clone $tab);
?>
--EXPECTF--
object(Pango\TabStops)#1 (0) {
}
object(Pango\TabStops)#2 (0) {
}
