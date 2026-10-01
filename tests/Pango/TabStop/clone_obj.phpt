--TEST--
Pango\TabStop clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\TabStop;
use Pango\TabAlign;

$align = TabAlign::Right;
Var_dump($align);
$tab1 = new TabStop($align, 10240);
var_dump($tab1);
$tab2 = clone $tab1;
var_dump($tab2);
?>
--EXPECTF--
enum(Pango\TabAlign::Right)
object(Pango\TabStop)#2 (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Right)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  NULL
}
object(Pango\TabStop)#3 (3) {
  ["alignment"]=>
  enum(Pango\TabAlign::Right)
  ["position"]=>
  int(10240)
  ["decimalChar"]=>
  NULL
}
