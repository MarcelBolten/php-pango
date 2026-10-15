--TEST--
Pango\FontSetSimple read property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\FontSetSimple;
use Pango\Language;

$fss = new FontSetSimple(new Language("en"));
var_dump($fss->size);
?>
--EXPECTF--
int(0)
