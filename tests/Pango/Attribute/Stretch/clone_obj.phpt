--TEST--
Pango\Attribute\StretchAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StretchAttribute;

$stretch = new Stretch(Pango\Stretch::Expanded);
var_dump($stretch->value);

$copy = clone $stretch;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Stretch::Expanded)
enum(Pango\Stretch::Expanded)
