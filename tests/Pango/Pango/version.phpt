--TEST--
Pango\Pango::version()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Pango::version());
?>
--EXPECTF--
int(%d)
