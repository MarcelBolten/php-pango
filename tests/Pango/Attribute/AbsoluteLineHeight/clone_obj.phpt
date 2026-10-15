--TEST--
Pango\Attribute\AbsoluteLineHeight clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AbsoluteLineHeight;

$absoluteLineHeight = new AbsoluteLineHeight(5);
var_dump($absoluteLineHeight->value);

$copy = clone $absoluteLineHeight;
var_dump($copy->value);
?>
--EXPECT--
int(5)
int(5)
