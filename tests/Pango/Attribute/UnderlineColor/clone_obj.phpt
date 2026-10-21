--TEST--
Pango\Attribute\UnderlineColorAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\UnderlineColorAttribute;

$underlineColor = new UnderlineColor(new Pango\Color(1024, 2048, 4096));
var_dump($underlineColor->color->red);

$copy = clone $underlineColor;
var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(1024)
