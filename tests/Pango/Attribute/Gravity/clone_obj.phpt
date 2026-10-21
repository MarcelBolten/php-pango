--TEST--
Pango\Attribute\GravityAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityAttribute;

$gravity = new Gravity(Pango\Gravity::North);
var_dump($gravity->value);

$copy = clone $gravity;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\Gravity::North)
enum(Pango\Gravity::North)
