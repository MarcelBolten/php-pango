--TEST--
Pango\Pango::versionString()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\Pango::versionString());
?>
--EXPECTF--
string(%d) "%d.%d.%d"
