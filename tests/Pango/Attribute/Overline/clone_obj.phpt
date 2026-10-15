--TEST--
Pango\Attribute\Overline clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Overline;

$overline = new Overline(Pango\Overline::Single);
var_dump($overline->value);

$copy = clone $overline;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Overline::Single)
enum(Pango\Overline::Single)
