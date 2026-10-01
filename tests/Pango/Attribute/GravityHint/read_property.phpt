--TEST--
Pango\Attribute\GravityHint read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../../skipif.php.inc';
?>
--FILE--
<?php
use Pango\Attribute\GravityHint;

$gravityHint = new GravityHint(Pango\GravityHint::Strong);

var_dump($gravityHint->value);
var_dump($gravityHint->startIndex);
var_dump($gravityHint->endIndex);
?>
--EXPECT--
enum(Pango\GravityHint::Strong)
int(0)
int(4294967295)
