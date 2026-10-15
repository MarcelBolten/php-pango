--TEST--
Pango\Attribute\Width clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Width;

$width = new Width(Pango\Width::Expanded);
var_dump($width->value);

$copy = clone $width;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Width::Expanded)
enum(Pango\Width::Expanded)