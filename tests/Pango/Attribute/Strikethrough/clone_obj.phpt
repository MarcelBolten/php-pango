--TEST--
Pango\Attribute\StrikethroughAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\StrikethroughAttribute;

$strikethrough = new Strikethrough(true);
var_dump($strikethrough->value);

$copy = clone $strikethrough;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
