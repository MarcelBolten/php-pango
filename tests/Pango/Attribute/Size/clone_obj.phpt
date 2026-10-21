--TEST--
Pango\Attribute\SizeAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\SizeAttribute;

$size = new SizeAttribute(5);
var_dump($size->value);

$copy = clone $size;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
