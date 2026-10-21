--TEST--
Pango\Attribute\UnderlineAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\UnderlineAttribute;

$underline = new UnderlineAttribute(Pango\Underline::Double);

var_dump($underline->value);
var_dump($underline->startIndex);
var_dump($underline->endIndex);
?>
--EXPECT--
enum(Pango\Underline::Double)
int(0)
int(4294967295)
