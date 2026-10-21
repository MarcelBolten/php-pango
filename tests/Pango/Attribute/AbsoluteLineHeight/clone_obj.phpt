--TEST--
Pango\Attribute\AbsoluteLineHeightAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeightAttribute;

$absoluteLineHeight = new AbsoluteLineHeight(5);
var_dump($absoluteLineHeight->value);

$copy = clone $absoluteLineHeight;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
