--TEST--
Pango\Attribute\OverlineAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\OverlineAttribute;

$overline = new OverlineAttribute(Pango\Overline::Single);
var_dump($overline->value);

$copy = clone $overline;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Overline::Single)
enum(Pango\Overline::Single)
