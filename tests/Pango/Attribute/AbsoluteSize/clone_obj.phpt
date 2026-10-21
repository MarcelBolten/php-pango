--TEST--
Pango\Attribute\AbsoluteSizeAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteSizeAttribute;

$absoluteSize = new AbsoluteSize(5);
var_dump($absoluteSize->value);

$copy = clone $absoluteSize;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
