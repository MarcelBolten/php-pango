--TEST--
Pango\version_check()
--EXTENSIONS--
pango
--FILE--
<?php
var_dump(Pango\version_check());
var_dump(Pango\version_check(1, 50, 0));
var_dump(Pango\version_check(1, 9999, 0));
?>
--EXPECTF--
string(0) ""
string(0) ""
string(38) "Pango version too old (micro mismatch)"
