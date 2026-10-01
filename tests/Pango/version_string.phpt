--TEST--
Pango\version_string()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.php.inc';
?>
--FILE--
<?php
var_dump(Pango\version_string());
?>
--EXPECTF--
string(%d) "%d.%d.%d"
