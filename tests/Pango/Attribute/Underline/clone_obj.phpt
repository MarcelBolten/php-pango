--TEST--
Pango\Attribute\UnderlineAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\UnderlineAttribute;

$underline = new Underline(Pango\Underline::Double);
var_dump($underline->value);

$copy = clone $underline;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Underline::Double)
enum(Pango\Underline::Double)
