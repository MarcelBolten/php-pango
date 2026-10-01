--TEST--
Pango\Analysis new instance
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
include __DIR__ . '/../../skipif_cairo.php.inc';
?>
--FILE--
<?php
$analysis = new Pango\Analysis();
var_dump($analysis);
?>
--EXPECTF--
object(Pango\Analysis)#1 (0) {
}
