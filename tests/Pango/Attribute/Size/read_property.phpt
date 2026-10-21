--TEST--
Pango\Attribute\SizeAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SizeAttribute;

$size = new SizeAttribute(5);

var_dump($size->value);
var_dump($size->startIndex);
var_dump($size->endIndex);
?>
--EXPECT--
int(5)
int(0)
int(4294967295)
