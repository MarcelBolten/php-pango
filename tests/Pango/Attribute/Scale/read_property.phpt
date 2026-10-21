--TEST--
Pango\Attribute\ScaleAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\ScaleAttribute;

$scale = new ScaleAttribute(5.2);

var_dump($scale->value);
var_dump($scale->startIndex);
var_dump($scale->endIndex);
?>
--EXPECT--
float(5.2)
int(0)
int(4294967295)
