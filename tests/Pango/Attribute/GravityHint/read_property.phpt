--TEST--
Pango\Attribute\GravityHintAttribute read_property handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\GravityHintAttribute;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);

var_dump($gravityHint->value);
var_dump($gravityHint->startIndex);
var_dump($gravityHint->endIndex);
?>
--EXPECT--
enum(Pango\GravityHint::Strong)
int(0)
int(4294967295)
