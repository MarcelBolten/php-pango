--TEST--
Pango\Pango::SCALE
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Pango::SCALE);
?>
--EXPECT--
int(1024)
