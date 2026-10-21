--TEST--
Pango\Attribute\StrikethroughAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughAttribute;

$strikethrough = new Strikethrough(true);

var_dump($strikethrough->value);
var_dump($strikethrough->startIndex);
var_dump($strikethrough->endIndex);
?>
--EXPECT--
bool(true)
int(0)
int(4294967295)
