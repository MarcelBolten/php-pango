--TEST--
Pango\Attribute\OverlineColorAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\OverlineColorAttribute;

$overlineColor = new OverlineColorAttribute(new Pango\Color(1024, 2048, 4096));
var_dump($overlineColor->color->red);

$copy = clone $overlineColor;
var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(1024)
