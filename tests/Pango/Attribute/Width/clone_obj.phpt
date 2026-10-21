--TEST--
Pango\Attribute\WidthAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\WidthAttribute;

$width = new WidthAttribute(Pango\Width::Expanded);
var_dump($width->value);

$copy = clone $width;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Width::Expanded)
enum(Pango\Width::Expanded)