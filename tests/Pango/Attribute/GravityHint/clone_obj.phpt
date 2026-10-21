--TEST--
Pango\Attribute\GravityHintAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityHintAttribute;

$gravityHint = new GravityHintAttribute(Pango\GravityHint::Strong);
var_dump($gravityHint->value);

$copy = clone $gravityHint;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\GravityHint::Strong)
enum(Pango\GravityHint::Strong)
