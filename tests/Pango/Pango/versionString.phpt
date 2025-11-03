--TEST--
Pango\Pango::versionString()
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\Pango::versionString());
?>
--EXPECTF--
string(%d) "%d.%d.%d"
