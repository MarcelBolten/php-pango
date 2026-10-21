--TEST--
Pango\Attribute\LineHeightAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LineHeightAttribute;

$LineHeight = new LineHeight(5.2);
var_dump($LineHeight->value);

$copy = clone $LineHeight;
var_dump($copy->value);
?>
--EXPECT--
float(5.2)
float(5.2)
