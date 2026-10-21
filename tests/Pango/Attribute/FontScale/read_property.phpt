--TEST--
Pango\Attribute\FontScaleAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\FontScaleAttribute;

$fontScale = new FontScaleAttribute(Pango\FontScale::SmallCaps);

var_dump($fontScale->value);
var_dump($fontScale->startIndex);
var_dump($fontScale->endIndex);
?>
--EXPECT--
enum(Pango\FontScale::SmallCaps)
int(0)
int(4294967295)
