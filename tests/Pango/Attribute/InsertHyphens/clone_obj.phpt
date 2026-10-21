--TEST--
Pango\Attribute\InsertHyphensAttribute clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\InsertHyphensAttribute;

$insertHyphens = new InsertHyphensAttribute(true);
var_dump($insertHyphens->value);

$copy = clone $insertHyphens;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
