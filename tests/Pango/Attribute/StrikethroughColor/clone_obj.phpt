--TEST--
Pango\Attribute\StrikethroughColor clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughColor;

$strikethroughColor = new StrikethroughColor(new Pango\Color(1024, 2048, 4096));
var_dump($strikethroughColor->color->red);

$copy = clone $strikethroughColor;
var_dump($copy->color->red);
?>
--EXPECT--
int(1024)
int(1024)
