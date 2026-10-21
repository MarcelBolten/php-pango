--TEST--
Pango\Attribute\OverlineAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\OverlineAttribute;

$overline = new Overline(Pango\Overline::Single);

var_dump($overline->value);
var_dump($overline->startIndex);
var_dump($overline->endIndex);
?>
--EXPECT--
enum(Pango\Overline::Single)
int(0)
int(4294967295)
