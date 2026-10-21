--TEST--
Pango\Attribute\ScaleAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ScaleAttribute;

$scale = new ScaleAttribute(5.2);
var_dump($scale->value);

$copy = clone $scale;
var_dump($copy->value);
?>
--EXPECT--
float(5.2)
float(5.2)
