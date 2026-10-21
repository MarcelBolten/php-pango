--TEST--
Pango\Attribute\BackgroundAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\BackgroundAttribute;

$background = new BackgroundAttribute(new Pango\Color(1024, 2048, 4096));
var_dump($background->color->red);

$copy = clone $background;
var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(1024)
