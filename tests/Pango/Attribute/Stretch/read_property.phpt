--TEST--
Pango\Attribute\StretchAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StretchAttribute;

$stretch = new Stretch(Pango\Stretch::Expanded);

var_dump($stretch->value);
var_dump($stretch->startIndex);
var_dump($stretch->endIndex);
?>
--EXPECT--
enum(Pango\Stretch::Expanded)
int(0)
int(4294967295)
