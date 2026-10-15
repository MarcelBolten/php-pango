--TEST--
Pango\Attribute\Scale read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\Scale;

$scale = new Scale(5.2);

var_dump($scale->value);
var_dump($scale->startIndex);
var_dump($scale->endIndex);
?>
--EXPECT--
float(5.2)
int(0)
int(4294967295)
