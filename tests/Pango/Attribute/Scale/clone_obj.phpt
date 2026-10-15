--TEST--
Pango\Attribute\Scale clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Scale;

$scale = new Scale(5.2);
var_dump($scale->value);

$copy = clone $scale;
var_dump($copy->value);
?>
--EXPECT--
float(5.2)
float(5.2)
