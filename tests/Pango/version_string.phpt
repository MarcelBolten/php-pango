--TEST--
Pango\version_string()
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\version_string());
?>
--EXPECTF--
string(%d) "%d.%d.%d"
