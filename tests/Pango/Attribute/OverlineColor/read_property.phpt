--TEST--
Pango\Attribute\OverlineColorAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\OverlineColorAttribute;

$overlineColor = new OverlineColorAttribute(new Pango\Color(1024, 2048, 4096));

var_dump($overlineColor->color->red);
var_dump($overlineColor->startIndex);
var_dump($overlineColor->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
