--TEST--
Pango\Attribute\LineHeightAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\LineHeightAttribute;

$LineHeight = new LineHeightAttribute(5.2);

var_dump($LineHeight->value);
var_dump($LineHeight->startIndex);
var_dump($LineHeight->endIndex);
?>
--EXPECT--
float(5.2)
int(0)
int(4294967295)
