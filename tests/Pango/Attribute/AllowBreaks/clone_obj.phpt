--TEST--
Pango\Attribute\AllowBreaksAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\AllowBreaksAttribute;

$allowBreaks = new AllowBreaksAttribute(true);
var_dump($allowBreaks->value);

$copy = clone $allowBreaks;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
