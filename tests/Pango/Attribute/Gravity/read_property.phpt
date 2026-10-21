--TEST--
Pango\Attribute\GravityAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityAttribute;

$gravity = new GravityAttribute(Pango\Gravity::North);

var_dump($gravity->value);
var_dump($gravity->startIndex);
var_dump($gravity->endIndex);
?>
--EXPECT--
enum(Pango\Gravity::North)
int(0)
int(4294967295)
