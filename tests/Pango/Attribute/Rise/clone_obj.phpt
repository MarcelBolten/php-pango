--TEST--
Pango\Attribute\RiseAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\RiseAttribute;

$rise = new RiseAttribute(5);
var_dump($rise->value);

$copy = clone $rise;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
