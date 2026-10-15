--TEST--
Pango\Attribute\InsertHyphens clone handler
--EXTENSIONS--
pango
--FILE--
<?php
use Pango\Attribute\InsertHyphens;

$insertHyphens = new InsertHyphens(true);
var_dump($insertHyphens->value);

$copy = clone $insertHyphens;
var_dump($copy->value);
?>
--EXPECT--
bool(true)
bool(true)
