--TEST--
Pango\Attribute\ShowAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ShowAttribute;

$show = new Show(Show::NONE);
var_dump($show->value);

$copy = clone $show;
var_dump($copy->value);
?>
--EXPECT--
int(0)
int(0)
