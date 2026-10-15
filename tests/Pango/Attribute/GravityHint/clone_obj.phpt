--TEST--
Pango\Attribute\GravityHint clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityHint;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);
var_dump($gravityHint->value);

$copy = clone $gravityHint;
var_dump($copy->value);
?>
--EXPECT--
enum(Pango\GravityHint::Strong)
enum(Pango\GravityHint::Strong)
