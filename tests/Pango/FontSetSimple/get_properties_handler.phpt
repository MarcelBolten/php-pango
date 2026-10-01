--TEST--
Pango\FontSetSimple get properties handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\FontSetSimple;
use Pango\Language;

$fss = new FontSetSimple(new Language("en"));
var_dump($fss);
?>
--EXPECTF--
object(Pango\FontSetSimple)#%d (1) {
  ["size"]=>
  int(0)
}
