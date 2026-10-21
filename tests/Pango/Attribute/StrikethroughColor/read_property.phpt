--TEST--
Pango\Attribute\StrikethroughColorAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughColorAttribute;

$strikethroughColor = new StrikethroughColorAttribute(new Pango\Color(1024, 2048, 4096));

var_dump($strikethroughColor->color->red);
var_dump($strikethroughColor->startIndex);
var_dump($strikethroughColor->endIndex);
?>
--EXPECT--
int(1024)
int(0)
int(4294967295)
